#!/bin/sh
gcc `pkg-config --cflags gtk+-3.0` -o runFile runFile.c `pkg-config --libs gtk+-3.0`
echo "Running program\n"
./runFile

