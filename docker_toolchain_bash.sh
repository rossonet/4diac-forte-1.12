#!/bin/bash
docker run -ti --rm -e DISPLAY=$DISPLAY -e QT_X11_NO_MITSHM=1 --device=$1 -v /tmp/.X11-unix:/tmp/.X11-unix --privileged -v $(pwd):/code rossonet/ar4k-esp8266-toolchain:latest bash
