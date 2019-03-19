#!/bin/bash

if [ $# -eq 0 ]
then
    echo "Entrez le nom du fichier en argument"
else
    progmem -v -o output.bin  $1

    cd tp/Write
    make clean
    sleep 1
    make install
    cd ../..

    serieViaUSB -e -f output.bin
fi
