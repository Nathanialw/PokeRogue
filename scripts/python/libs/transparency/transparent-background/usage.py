import cv2
import numpy as np

from PIL import Image
from transparent_background import Remover

# Load model
remover = Remover() # default setting
#remover = Remover(mode='fast', jit=True, device='cuda:0') # custom setting
#remover = Remover(mode='base-nightly') # nightly release checkpoint

# Usage for image
img = Image.open('ABOLETH-5.png').convert('RGB') # read image


out = remover.process(img, threshold=0.5) # use threhold parameter for hard prediction.

out.save('output.png') # save result


