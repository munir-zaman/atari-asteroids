#!/bin/sh

SRC="src/main.cpp"
FLAGS="-lraylib -lGL -lm -lpthread -ldl -lrt -lX11"

g++ $SRC $FLAGS