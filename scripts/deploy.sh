#!/bin/bash

ELF="build-pico/src/PicoGame/PicoRogue.elf"
UF2="build-pico/src/PicoGame/PicoRogue.uf2"
PICO_MOUNT="/media/nathanial/RPI-RP2"

echo "=== PicoRogue Deploy ==="

echo "Memory usage:"
arm-none-eabi-size -A "$ELF" | grep -E '^(\.text|\.rodata|\.data|\.bss|Total)'
echo ""

RAM_USED=$(arm-none-eabi-size -A "$ELF" | awk '
/^\.(data|bss)/ { sum += $2 }
END { print sum }')

FLASH_USED=$(arm-none-eabi-size -A "$ELF" | awk '
/^\.(text|rodata|data)/ { sum += $2 }
END { print sum }')

FLASH_TOTAL=4096
RAM_TOTAL=200

echo "Flash usage: $((FLASH_USED / 1024)) KB / $FLASH_TOTAL KB ($((FLASH_USED * 100 / (FLASH_TOTAL * 1024)))%)"
echo "RAM usage:   $((RAM_USED / 1024)) KB / $RAM_TOTAL KB ($((RAM_USED * 100 / (RAM_TOTAL * 1024)))%) usable RAM is 200KB/264KB"
echo ""

echo "Copying to Pico..."
cp "$UF2" "$PICO_MOUNT/"
sync
echo "✅ Done! Pico will reset."