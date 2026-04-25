# server_24b.py
from fastapi import FastAPI
from pydantic import BaseModel
import uvicorn
from llama_cpp import Llama
import os
from ..config import constants  # Import constants

# ===== CONFIGURATION - EDIT THESE VARIABLES =====
MODEL_PATH = constants.QWEN_MODEL_PATH  # Use constant from file
HOST = constants.DEFAULT_HOST
PORT = constants.DEFAULT_PORT
GPU_LAYERS = constants.DEFAULT_GPU_LAYERS
CONTEXT_SIZE = constants.DEFAULT_CONTEXT_SIZE
THREADS = constants.DEFAULT_THREADS
FLASH_ATTN = constants.DEFAULT_FLASH_ATTN
VERBOSE = True

# GPU SELECTION
SPLIT_MODE = "layer"
# ================================================

# Import GPU functions (could also move these to a separate module)
def get_gpu_info():
    """Get information about available GPUs and current settings"""
    import subprocess

    info = {
        "visible_devices": os.environ.get("CUDA_VISIBLE_DEVICES", "all"),
        "main_device": os.environ.get("GGML_CUDA_DEVICE", "0"),
        "split_mode": SPLIT_MODE,
        "available_gpus": [],
        "memory_info": []
    }

    try:
        result = subprocess.run(
            ['nvidia-smi', '--query-gpu=index,name,memory.total', '--format=csv,noheader'],
            capture_output=True,
            text=True,
            check=True
        )
        for line in result.stdout.strip().split('\n'):
            if line:
                parts = line.split(', ')
                if len(parts) >= 3:
                    info["available_gpus"].append({
                        "index": parts[0],
                        "name": parts[1],
                        "memory": parts[2]
                    })
    except:
        info["available_gpus"] = ["Unable to query GPU info"]

    return info


def print_gpu_config():
    """Print current GPU configuration"""
    print("\n" + "=" * 50)
    print("GPU CONFIGURATION")
    print("=" * 50)

    gpu_info = get_gpu_info()
    print(f"Visible GPUs: {gpu_info['visible_devices']}")
    print(f"Split Mode: {gpu_info['split_mode']}")

    if gpu_info['available_gpus'] and isinstance(gpu_info['available_gpus'][0], dict):
        print("\nAvailable GPUs:")
        for gpu in gpu_info['available_gpus']:
            marker = "→ " if gpu['index'] in str(gpu_info['visible_devices']).split(',') else "  "
            print(f"{marker}GPU {gpu['index']}: {gpu['name']} ({gpu['memory']})")

    print("=" * 50)


def set_gpus(gpu_indices):
    """Set which GPUs to use"""
    if isinstance(gpu_indices, list):
        gpu_str = ','.join(str(i) for i in gpu_indices)
    elif isinstance(gpu_indices, int):
        gpu_str = str(gpu_indices)
    else:
        gpu_str = gpu_indices

    os.environ["CUDA_VISIBLE_DEVICES"] = gpu_str
    print(f"✅ Set visible GPUs to: {gpu_str}")


def set_split_mode(mode="layer"):
    """Set how to split model across GPUs"""
    global SPLIT_MODE
    if mode in ["layer", "row"]:
        SPLIT_MODE = mode
        print(f"✅ Set split mode to: {mode}")
    else:
        print(f"❌ Invalid split mode: {mode}. Use 'layer' or 'row'")


def auto_select_gpus(min_memory_per_gpu_gb=8):
    """Automatically select GPUs with sufficient memory"""
    import subprocess

    try:
        result = subprocess.run(
            ['nvidia-smi', '--query-gpu=index,memory.free', '--format=csv,noheader,nounits'],
            capture_output=True,
            text=True,
            check=True
        )

        selected = []
        for line in result.stdout.strip().split('\n'):
            if line:
                idx, mem = line.split(', ')
                mem_gb = int(mem) / 1024
                if mem_gb >= min_memory_per_gpu_gb:
                    selected.append(idx)

        if selected:
            set_gpus(selected)
            print(f"Auto-selected GPUs with ≥{min_memory_per_gpu_gb}GB free: {', '.join(selected)}")
            return True
        else:
            print(f"No GPUs found with {min_memory_per_gpu_gb}GB free memory")
            return False
    except:
        print("Failed to auto-select GPUs, using default")
        return False


# Create FastAPI app
app = FastAPI(title="llama.cpp Python Server")

# Print GPU configuration
print_gpu_config()

# GPU selection (uncomment as needed)
# auto_select_gpus(min_memory_per_gpu_gb=8)
# set_gpus([0, 1])

# Load model
print("=" * 50)
print("Starting llama.cpp Python Server")
print("=" * 50)
print(f"Model: {MODEL_PATH}")
print(f"GPU Layers: {GPU_LAYERS}")
print(f"Context Size: {CONTEXT_SIZE}")
print(f"Threads: {THREADS}")
print(f"Flash Attention: {FLASH_ATTN}")
print(f"Split Mode: {SPLIT_MODE}")
print("-" * 50)

llm = Llama(
    model_path=MODEL_PATH,
    n_ctx=CONTEXT_SIZE,
    n_gpu_layers=GPU_LAYERS,
    n_threads=THREADS,
    flash_attn=FLASH_ATTN,
    verbose=VERBOSE,
    use_mmap=True,
)

print("Model loaded successfully!")
print("=" * 50)


# Request/Response models
class CompletionRequest(BaseModel):
    prompt: str
    max_tokens: int = 150
    temperature: float = 0.7
    top_p: float = 0.95
    top_k: int = 20


class ChatRequest(BaseModel):
    messages: list
    max_tokens: int = 150
    temperature: float = 0.7
    top_p: float = 0.95
    top_k: int = 20


# Completion endpoint
@app.post("/completion")
async def completion(request: CompletionRequest):
    response = llm(
        request.prompt,
        max_tokens=request.max_tokens,
        temperature=request.temperature,
        top_p=request.top_p,
        top_k=request.top_k,
        echo=False
    )
    return {"content": response["choices"][0]["text"].strip()}


# Chat endpoint
@app.post("/chat/completions")
async def chat_completions(request: ChatRequest):
    response = llm.create_chat_completion(
        messages=request.messages,
        max_tokens=request.max_tokens,
        temperature=request.temperature,
        top_p=request.top_p,
        top_k=request.top_k,
    )
    return {
        "choices": [{
            "message": {
                "content": response["choices"][0]["message"]["content"].strip()
            }
        }]
    }


# GPU info endpoint
@app.get("/gpu-info")
async def gpu_info():
    return get_gpu_info()


# Health endpoint
@app.get("/health")
async def health():
    return {"status": "ok"}


# Root endpoint
@app.get("/")
async def root():
    return {
        "status": "running",
        "model": MODEL_PATH.split("/")[-1],
        "endpoints": ["/completion", "/chat/completions", "/health", "/gpu-info"],
        "gpu_config": {
            "visible_devices": os.environ.get("CUDA_VISIBLE_DEVICES", "all"),
            "split_mode": SPLIT_MODE
        }
    }


if __name__ == "__main__":
    print(f"Server starting on http://{HOST}:{PORT}")
    print(f"GPU Info available at http://{HOST}:{PORT}/gpu-info")
    print("Press Ctrl+C to stop")
    uvicorn.run(app, host=HOST, port=PORT)