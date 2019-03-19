#!/bin/bash

progmem -v -o output.bin  $1

cd tp/Write
make clean
sleep 1
make install
cd ../..

serieViaUSB -e -f output.bin
