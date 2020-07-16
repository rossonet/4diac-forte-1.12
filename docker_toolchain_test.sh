#!/bin/bash
docker run -ti --rm --device=$1 -v $(pwd):/code rossonet/ar4k-esp8266-toolchain:latest /code/recipes/ar4k_console_with_wifi.sh $1
