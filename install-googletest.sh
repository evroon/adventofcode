#!/bin/bash

VERSION=1.8.0

cd /tmp || exit
wget "https://github.com/google/googletest/archive/release-$VERSION.tar.gz"
tar xzf "release-$VERSION.tar.gz"
cd "googletest-release-$VERSION" || exit

mkdir build && cd build || exit
cmake ..
make -j

sudo cp -r ../googletest/include /usr/local/include
sudo cp -r ./googlemock/gtest/libgtest*.a /usr/local/lib/
sudo cp -r ./googlemock/libgmock*.a /usr/local/lib/

