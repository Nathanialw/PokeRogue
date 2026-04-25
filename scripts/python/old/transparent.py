

# import cv2
# import numpy as np
#
# from PIL import Image
# from transparent_background import Remover
#
#
# gpu = 'cuda:0'
# # Load model
# remover = Remover() # default setting
#
# try:
# 	remover = Remover(mode='base-nightly', jit=False, device='cuda:0')  # custom setting
# except:
# 	remover = Remover(mode='base-nightly', jit=True, device='cpu')  # custom setting
#
# #
# # try:
# # 	remover = Remover(mode='base-nightly', jit=False, device=gpu) # custom
# # except:
# # 	# remover = Remover(mode='base-nightly', jit=True, device='cpu') # custom
# # 	remover = Remover(mode='base', jit=True, device='cpu') # custom
# # 	#remover = Remover(mode='base-nightly') # nightly release checkpoint
#
# img_name = "ABOLETH-5"
# img = Image.open(f"{img_name}.png").convert('RGB') # read image
# out = remover.process(img) # use threhold parameter for hard prediction.
# out.save(f"{img_name}_t22.png") # save result
#
#
from PIL import Image
from transparent_background import Remover

# Load model
#remover = Remover(mode='fast', jit=True, device='cuda:0') # custom setting
#remover = Remover(mode='base-nightly') # nightly release checkpoint
# out = remover.process(img, type='[255, 0, 255]') # change background with color code [255, 0, 255]

remover = Remover(resize='dynamic', device='cuda:1') # use dynamic resizing instead of static resizing


# Usage for image
img = Image.open('img.png').convert('RGB') # read image

out = remover.process(img, threshold=0.01) # use threhold parameter for hard prediction.
#make multiple from range 0.001 to 0.1, pick the best one

out.save('trans_output.png') # save result


