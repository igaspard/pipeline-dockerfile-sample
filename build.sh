#!/bin/bash

if [ -d build ]; then
    rm -rf build
fi

mkdir build
pushd build
cmake ..
make
popd