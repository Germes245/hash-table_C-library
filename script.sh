#!/bin/bash
mkdir -p temp
cd temp
cmake ..
make
cd ..
mkdir -p ./object_files
pwd
mv `find ./temp -name "*.o"` ./object_files
#rm -r temp