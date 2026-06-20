#!/bin/bash

python -m python.data.populate_entities
python -m python.export.export_all
python -m python.cartridge.make_dummy_constants