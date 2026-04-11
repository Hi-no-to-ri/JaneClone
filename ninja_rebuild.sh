#!/bin/bash

rm -rf ./build

# Detect cmake path
CMAKE=/usr/bin/cmake
if [ ! $(type -P ${CMAKE} 2>/dev/null) ]; then CMAKE=/usr/local/bin/cmake; fi
if [ ! $(type -P ${CMAKE} 2>/dev/null) ]; then CMAKE=/mingw64/bin/cmake; fi
if [ ! $(type -P ${CMAKE} 2>/dev/null) ]; then CMAKE=$(which cmake); fi

# Detect build type (default: Release)
BUILD_TYPE=${BUILD_TYPE:-Release}

# Copy required MinGW runtime DLLs next to the executable
copy_mingw_dlls() {
    local dest="$1"
    [ -d "/mingw64/bin" ] || return 0
    local changed=1
    while [ "$changed" -eq 1 ]; do
        changed=0
        for pe in "$dest"/*.exe "$dest"/*.dll; do
            [ -f "$pe" ] || continue
            for dll in $(objdump -p "$pe" 2>/dev/null | grep "DLL Name:" | awk '{print $3}'); do
                if [ -f "/mingw64/bin/$dll" ] && [ ! -f "$dest/$dll" ]; then
                    cp "/mingw64/bin/$dll" "$dest/"
                    changed=1
                fi
            done
        done
    done
}

mkdir build
cd build
$CMAKE --version
$CMAKE -G "Ninja" -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ..
ninja $@ && copy_mingw_dlls src
