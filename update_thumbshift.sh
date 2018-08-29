#!/bin/sh

make ergodox_ez:thumbshift
echo "start teensy"
teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_thumbshift.hex
