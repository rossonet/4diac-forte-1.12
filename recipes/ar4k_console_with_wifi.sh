#!/bin/bash

# by Andrea Ambrosini -Rossonet-

cd /tools/ESP8266_RTOS_SDK/examples/rossonet
make
python /tools/ESP8266_RTOS_SDK/components/esptool_py/esptool/esptool.py --chip esp8266 --port $1 --baud 115200 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size 2MB 0x0 /tools/ESP8266_RTOS_SDK/examples/rossonet/build/bootloader/bootloader.bin 0x10000 /tools/ESP8266_RTOS_SDK/examples/rossonet/build/console.bin 0x8000 /tools/ESP8266_RTOS_SDK/examples/rossonet/build/partitions_example.bin
