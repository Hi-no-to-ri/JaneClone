#!/bin/bash

CMAKE=/usr/bin/cmake
if [ ! $(type -P ${CMAKE} 2>/dev/null) ]; then CMAKE=/usr/local/bin/cmake; fi
# if [ ! $(type -P ${CMAKE} 2>/dev/null) ]; then CMAKE=/mingw64/bin/cmake; fi
if [ ! $(type -P ${CMAKE} 2>/dev/null) ]; then CMAKE=$(which cmake); fi
# CMAKE=$(which cmake)
if [ ! -e build ]; then mkdir build; fi
cd build
$CMAKE --version
$CMAKE -G "Ninja" ..
ninja $@
