#!/bin/bash


cd fonts
python ttf_to_font.py fonts/myfont.ttf --size 20 --char-width 20 --char-height 20 --chars-file chars.txt --tight
python ttf_to_font.py fonts/myfont.ttf --size 24 --char-width 24 --char-height 24 --chars-file chars.txt --tight
python ttf_to_font.py fonts/myfont.ttf --size 32 --char-width 32 --char-height 32 --chars-file chars.txt --tight
