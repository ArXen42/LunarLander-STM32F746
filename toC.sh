#!/bin/sh
# Rename all C++ files to C files (call before regenerate CubeMX project)

find LunarLander/Core/Src -name *.cpp | awk '{system("mv "$0 " " substr($0, 0, length($0) - 2))}'
