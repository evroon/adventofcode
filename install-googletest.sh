#!/bin/bash

git clone https://github.com/google/googletest.git -b release-1.11.0
cd googletest || exit # Main directory of the cloned repository.
mkdir build           # Create a directory to hold the build output.
cd build || exit
cmake ..              # Generate native build scripts for GoogleTest.
make
sudo make install     # Install in /usr/local/ by default
