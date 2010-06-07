#!/bin/sh

BIN="bin/cmakeqt"
if [ -f $BIN ]; then
    exec $BIN "$@"
else
    echo "CMakeQt not build, read INSTALL first"
fi
