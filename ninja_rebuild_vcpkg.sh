#!/bin/bash

rm -rf ./build

CMAKE=$(which cmake)
VCPKG_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

if [ ! -e build ]; then mkdir build; fi
cd build
$CMAKE --version
$CMAKE -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=$VCPKG_TOOLCHAIN_FILE .. -DBUILD_SHARED_LIBS=OFF
ninja $@
