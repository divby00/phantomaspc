#!/usr/bin/env sh
rm -rf phantomaspc-1.3.0.zip
mkdir -p phantomaspc-1.3.0/data
mv phantomaspc.exe phantomaspc-1.3.0/
cp ./data/phantom1.dat phantomaspc-1.3.0/data
cp ./data/world.bin phantomaspc-1.3.0/data
cp ./platform/windows/deps/allegro/bin/dlls/alleg44.dll phantomaspc-1.3.0/
cp ./platform/windows/deps/allegro/bin/dlls/libvorbis-0.dll phantomaspc-1.3.0/
cp ./platform/windows/deps/allegro/bin/dlls/libvorbisfile-3.dll phantomaspc-1.3.0/
cp ./platform/windows/deps/allegro/bin/dlls/libvorbisenc-2.dll phantomaspc-1.3.0/
cp ./platform/windows/deps/allegro/bin/dlls/libogg-0.dll phantomaspc-1.3.0/
cp ./platform/windows/deps/lua/lua52.dll phantomaspc-1.3.0/
zip -r phantomaspc-1.3,0.zip phantomaspc-1.3.0/
rm -rf phantomaspc-1.3.0

