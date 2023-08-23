#!/bin/sh

SRC="src/main.cpp"
FLAGS="-lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
OUT="asteroids.out"

g++ -o $OUT $SRC $FLAGS