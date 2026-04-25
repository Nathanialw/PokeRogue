#!/bin/bash


cd /mnt/media/ai/text/llama.cpp_built/bin
#quite bad
#./llama-server -m "/mnt/media/ai/text/llama.cpp_built/models/bartowski_Llama-3.1-SuperNova-Lite-GGUF_Llama-3.1-SuperNova-Lite-Q4_K_M.gguf" --host 127.0.0.1 --port 8000 --n-gpu-layers 999 --ctx-size 4096 --threads 8
#./llama-server -m "/mnt/media/ai/text/llama.cpp_built/models/ValueFX9507_Tifa-Deepsex-14b-CoT-GGUF-Q4_Tifa-Deepsex-14b-CoT-Q4_K_M.gguf" --host 127.0.0.1 --port 8000 --n-gpu-layers 999 --ctx-size 4096 --threads 8
#./llama-server -m "/mnt/media/ai/text/llama.cpp_built/models/bartowski_DeepSeek-R1-Distill-Qwen-14B-GGUF_DeepSeek-R1-Distill-Qwen-14B-Q4_K_M.gguf" --host 127.0.0.1 --port 8000 --n-gpu-layers 999 --ctx-size 4096 --threads 8
#./llama-server -m "/mnt/media/ai/text/llama.cpp_built/models/DavidAU_L3-DARKEST-PLANET-16.5B-GGUF_L3-DARKEST-PLANET-16.5B-D_AU-Q4_k_m.gguf" --host 127.0.0.1 --port 8000 --n-gpu-layers 999 --ctx-size 4096 --threads 8

#pretty good
#./llama-server -m "/mnt/media/ai/text/llama.cpp_built/models/OLMo-2-1124-13B-Instruct-Q6_K.gguf" --host 127.0.0.1 --port 8000 --ctx-size 2048 --threads 20 -ngl 999  --no-kv-offload
#./llama-server -m "/mnt/media/ai/text/llama.cpp_built/models/ConicCat_Qwen3.5-27B-Writer-Q6_K.gguf" --host 127.0.0.1 --port 8000 --ctx-size 2048 --threads 20 -ngl 33 --no-kv-offload --flash-attn on --cache-type-k q8_0 --cache-type-v q8_0 --temp 0.6 --top-p 0.95 --top-k 20 --ubatch-size 256 --batch-size 1024 --parallel 1 --cont-batching --no-warmup


#split between gpus
#  ./llama-server \
#  -m "/path/to/model.gguf" \
#  --host 127.0.0.1 \
#  --port 8000 \
#  -ngl 999 \
#  --split-mode layer  # Split layers across available GPUs


MODEL_PATH="/mnt/media/ai/text/llama.cpp_built/models/mistralai_Mistral-Small-4-119B-2603-Q6_K-00001-of-00003.gguf"

# For split models, just point to the first file
# llama.cpp will automatically find the other parts

./llama-server -m "$MODEL_PATH" --host 127.0.0.1 --port 8000 --ctx-size 1024 --threads 20 -ngl 4 --no-kv-offload --flash-attn on

#free -h && sudo sysctl -w vm.drop_caches=3 && sudo sync && echo 3 | sudo tee /proc/sys/vm/drop_caches && free -h
