#!/usr/bin/env sh
rm -rf ./build
rm *.deb
mkdir -p ./build/DEBIAN
mkdir -p ./build/usr/share/icons
mkdir -p ./build/usr/share/applications
mkdir -p ./build/usr/share/phantomaspc/data
mkdir -p ./build/usr/share/locale/es/LC_MESSAGES
mkdir -p ./build/usr/bin/
cp ./platform/debian/control ./build/DEBIAN
cp phantomaspc ./build/usr/bin
cp ./phantomaspc.png ./build/usr/share/icons
cp ./phantomaspc.desktop ./build/usr/share/applications
cp ./data/phantom1.dat ./build/usr/share/phantomaspc/data
cp ./data/world.bin ./build/usr/share/phantomaspc/data
cp ./data/locale/es/LC_MESSAGES/phantomaspc.mo ./build/usr/share/locale/es/LC_MESSAGES
dpkg-deb --build build
mv build.deb phantomaspc_1.3-0_64.deb
rm -rf ./build
