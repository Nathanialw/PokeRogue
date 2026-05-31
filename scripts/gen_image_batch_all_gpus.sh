#!/bin/bash

#generate all from server
#python -m python.gen_images.svrgen_generate_all


python -m python.gen_images.batch_generate --type item
#python -m python.gen_images.batch_generate --type spell
#python -m python.gen_images.batch_generate --type object
#python -m python.gen_images.batch_generate --type skill
#python -m python.gen_images.batch_generate --type trainer

# --start-from SUCCUBUS
#generate all from local
#python gen_sprites_gguf.py

## List all available objects
#python batch_generate.py --list
#
## Generate all objects
#python batch_generate.py
#
## Generate only creatures
#python batch_generate.py --type creature
#
## Generate only spells
#python batch_generate.py --type spell
#
## Generate only skills
#python batch_generate.py --type skill
#
## Generate only items
#python batch_generate.py --type item
#
## Generate all objects with custom variants per object
#python batch_generate.py --variants 8
#
## Start from a specific spell
#python batch_generate.py --start-from "spell/Fireball"
#
## Generate with monitoring
#python batch_generate.py --monitor
#
## Generate creatures with 4 variants each
#python batch_generate.py --type creature --variants 4
#
## Generate all objects with custom server and delay
#python batch_generate.py --server http://192.168.1.100:5000 --delay 5