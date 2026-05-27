#!/bin/bash


cd python

cd process_images

image_types=("item" "spell" "skill" "creature" "object" "trainer")
#image_types=("creature")


echo $type

#process images for use
for type in "${image_types[@]}"
do
  echo ${type}
  raw_source_file="../../../assets_raw/sprites/${type}"
  staged_file="../../../assets_processed/${type}s/staged"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency"
  deployable_file="../../../assets_processed/${type}s/deployable"

  python copy_first_images.py ${raw_source_file}         ${staged_file}
  python transparent_bulk.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py  ${with_transparency_file}  ${deployable_file}
  python compress_img.py      ${deployable_file}

  python compress_map_sprite.py ${deployable_file} 16
  python compress_map_sprite.py ${deployable_file} 20
  python compress_map_sprite.py ${deployable_file} 24
  python compress_map_sprite.py ${deployable_file} 32
  python compress_map_sprite.py ${deployable_file} 64
done


cd ..
cd ..

