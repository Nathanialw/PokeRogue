#!/bin/bash

# copy all images to staging folder
rm -r ../assets_processed/
python -m python.export.populate_db_images


cd python
cd process_images

image_types=("creature" "trainer")
for type in "${image_types[@]}"
do
  echo ${type}
  staged_file="../../../assets_processed/${type}s/staged/front"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency/front"
  deployable_file="../../../assets_processed/${type}s/deployable/front"

  python transparent_bulk.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py  ${with_transparency_file}  ${deployable_file}
  python compress_img.py      ${deployable_file} 64 64

  python compress_map_sprite.py ${deployable_file} 64
done

image_types=("creature" "trainer")
for type in "${image_types[@]}"
do
  echo ${type}
  staged_file="../../../assets_processed/${type}s/staged/back"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency/back"
  deployable_file="../../../assets_processed/${type}s/deployable/back"

  python transparent_bulk.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py  ${with_transparency_file}  ${deployable_file}
  python compress_img.py      ${deployable_file} 64 64

  python compress_map_sprite.py ${deployable_file} 64
done

image_types=("item" "object" "environment_object")
for type in "${image_types[@]}"
do
  echo ${type}
  staged_file="../../../assets_processed/${type}s/staged"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency"
  deployable_file="../../../assets_processed/${type}s/deployable"

  python transparent_bulk.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py  ${with_transparency_file}  ${deployable_file}
  python compress_img.py      ${deployable_file} 64 64

  python compress_map_sprite.py ${deployable_file} 64
done

image_types=("spell" "skill")
for type in "${image_types[@]}"
do
  echo ${type}
  staged_file="../../../assets_processed/${type}s/staged"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency"
  deployable_file="../../../assets_processed/${type}s/deployable"

  python transfer_to_transparency.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py          ${with_transparency_file}  ${deployable_file}
  python compress_img.py              ${deployable_file} 64 64

  python compress_map_sprite.py ${deployable_file} 80
done

image_types=("creature_buff" "creature_debuff" "trainer_buff")
for type in "${image_types[@]}"
do
  echo ${type}
  staged_file="../../../assets_processed/${type}s/staged"
  with_transparency_file="../../../assets_processed/${type}s/with_transparency"
  deployable_file="../../../assets_processed/${type}s/deployable"

  python transfer_to_transparency.py  ${staged_file}             ${with_transparency_file}
  python rescale_reformat.py          ${with_transparency_file}  ${deployable_file}
  python compress_img.py              ${deployable_file} 64 64

  python compress_map_sprite.py ${deployable_file} 48
done

# Tiles use all of the texture scripts except transparency
type="tile"
echo ${type}
raw_source_file="../../../assets_raw/sprites/${type}"
staged_file="../../../assets_processed/${type}s/staged"
deployable_file="../../../assets_processed/${type}s/deployable"

python rescale_reformat.py  ${staged_file}  ${deployable_file}
python compress_img.py      ${deployable_file}
python compress_img.py      ${deployable_file} 64 64

python compress_map_sprite.py ${deployable_file} 64


cd ..
cd ..

