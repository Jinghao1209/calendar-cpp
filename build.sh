#!/bin/sh

set -xe

CC="g++"
PKGS=""
CFLAGS="-Wall -Wextra -std=c++17" # -pedantic
LIBS="-lm -Iinc"

if [ `uname` = "Darwin" ]; then
    CFLAGS+="" # add CFLAGS exp. -framework
fi

$CC $CFLAGS `pkg-config --cflags $PKGS` src/*.cpp $LIBS `pkg-config --libs $PKGS` -o main.out
