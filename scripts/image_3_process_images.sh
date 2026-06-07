#!/bin/bash

# copy all images to staging folder
rm -r ../assets_processed
python -m python.export.populate_db_images


cd python
cd process_images


image_types=("creature" "spell" "skill" "item" "object" "trainer")
for type in "${image_types[@]}"
do
  echo ${type}
  staged_file="../../../assets_processed/${type}s/staged"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency"
  deployable_file="../../../assets_processed/${type}s/deployable"

  python transparent_bulk.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py  ${with_transparency_file}  ${deployable_file}
  python compress_img.py      ${deployable_file} 16 16
  python compress_img.py      ${deployable_file} 64 64

  python compress_map_sprite.py ${deployable_file} 16
  python compress_map_sprite.py ${deployable_file} 20
  python compress_map_sprite.py ${deployable_file} 24
  python compress_map_sprite.py ${deployable_file} 32
  python compress_map_sprite.py ${deployable_file} 64
done


# Tiles use all of the texture scripts except transparency
type="tile"
echo ${type}

raw_source_file="../../../assets_raw/sprites/${type}"
staged_file="../../../assets_processed/${type}s/staged"
deployable_file="../../../assets_processed/${type}s/deployable"

python rescale_reformat.py  ${staged_file}  ${deployable_file}
python compress_img.py      ${deployable_file}
python compress_img.py      ${deployable_file} 16 16
python compress_img.py      ${deployable_file} 64 64

python compress_map_sprite.py ${deployable_file} 16
python compress_map_sprite.py ${deployable_file} 20
python compress_map_sprite.py ${deployable_file} 24
python compress_map_sprite.py ${deployable_file} 32
python compress_map_sprite.py ${deployable_file} 64


cd ..
cd ..

