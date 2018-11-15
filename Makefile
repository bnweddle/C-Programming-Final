#!/bin/sh
gcc `pkg-config --cflags gtk+-3.0` -o Class Class.c `pkg-config --libs gtk+-3.0`
echo "Running program\n"
./Class
