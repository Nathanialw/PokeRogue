# server.py
from fastapi import FastAPI
from llama_cpp import Llama
from pydantic import BaseModel
import uvicorn
import threading
import time

app = FastAPI()

# Load model directly from your path
model_path = "/mnt/media/ai/text/llama.cpp_built/models/bartowski_Llama-3.1-SuperNova-Lite-GGUF_Llama-3.1-SuperNova-Lite-Q4_K_M.gguf"

print("Loading model...")
llm = Llama(
    model_path=model_path,
    n_ctx=4096,
    n_gpu_layers=999,
    n_threads=8,
    verbose=False
)
print("Model loaded!")

class PromptRequest(BaseModel):
    prompt: str

@app.post("/generate")
async def generate(request: PromptRequest):
    response = llm(
        request.prompt,
        max_tokens=512,
        temperature=0.7,
        stop=None
    )
    return {"response": response["choices"][0]["text"].strip()}

def run_server():
    """Function to run the server in a separate thread"""
    uvicorn.run(app, host="127.0.0.1", port=8000, log_level="info")

if __name__ == "__main__":
    # This runs when server.py is executed directly
    uvicorn.run(app, host="127.0.0.1", port=8000)