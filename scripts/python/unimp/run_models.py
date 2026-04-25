import subprocess
# from llama_cpp import Llama

# exe = "/mnt/01E555CE2EC7267F/llamacpp/bin/llama-server"
#
# # Define your variables
# model_root = "/mnt/01E555CE2EC7267F/llamacpp/models/"
# model = "bartowski_Llama-3.1-SuperNova-Lite-GGUF_Llama-3.1-SuperNova-Lite-"
# code_model = "bartowski/DeepSeek-Coder-V2-Lite-Instruct-GGUF"
# quant = "Q6_K_L"
# ext = '.gguf'

# Path to the llama-server executable
root = "~/llamacpp/llama.cpp/build/"
exe = "bin/llama-server"



# Global variables
port = 8080
ctx_size = 32768
#   512
#   1024
#   2048
#   4096
#   8192
#   16384
#   32768
#   65536
#   131072
gpu_layers = 999
#   -1 for all layers

class Quant:
    """Stores all supported quantization levels as class attributes."""
    Q2_K = "Q2_K"
    Q3_K_S = "Q3_K_S"
    Q3_K_M = "Q3_K_M"
    Q3_K_L = "Q3_K_L"
    Q4_K_S = "Q4_K_S"
    Q4_K_M = "Q4_K_M"
    Q5_K_S = "Q5_K_S"
    Q5_K_M = "Q5_K_M"
    Q6_K_L = "Q6_K_L"
    Q6_K = "Q6_K"
    Q8_K = "Q8_K"


class Model:
    def __init__(self, name):
        self.name = name

        # Dynamically add quantization attributes to the instance
        for quant_name, quant_value in Quant.__dict__.items():
            if not quant_name.startswith("__"):
                setattr(self, quant_name, self._create_quant_method(quant_value))

    def _create_quant_method(self, quant):
        """Creates a method to run the model with the specified quantization."""

        def run_quant():
            return self.run(quant)

        return run_quant

    def run(self, quant):
        """Runs the model with the specified quantization."""
        print(f"{root}{exe}")

        command = [
            f"{root}{exe}",
            "-m", f"{root}models/{self.name}{quant}.gguf",  # Construct model file path
            "--port", str(port),
            "--n-gpu-layers", str(gpu_layers),
            "--ctx-size", str(ctx_size)
        ]
        return command


class Models:
    SuperNova_Lite = Model("bartowski_Llama-3.1-SuperNova-Lite-GGUF_Llama-3.1-SuperNova-Lite-")


# Create an instance of Models
llm = Models()

# Run the command
try:
    # Run the SuperNova_Lite model with Q6_K quantization using the desired syntax
    cmd = llm.SuperNova_Lite.Q4_K_M()
    subprocess.run(cmd, check=True)
except subprocess.CalledProcessError as e:
    print(f"Error occurred: {e}")
except FileNotFoundError:
    print(f"Error: The executable '{exe}' was not found. Please check the path.")
except Exception as e:
    print(f"An unexpected error occurred: {e}")
