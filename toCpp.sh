#!/bin/sh
# Rename all CubeMX generated C files to C++ files

find LunarLander/Core/Src -name *.c | awk '{system("mv "$0 " "$0 "pp")}'
