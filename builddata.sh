#!/usr/bin/env bash

# Remove old global data file headers
rm src/phantom1.h

# Fonts
dat data/phantfont.dat -a -c2 -t FONT data/fonts/*.bmp
dat2c -o src/bmpfnts.c -h src/bmpfnts.h -n databmpfnts phantfont.dat

# Sprites
dat data/phantgfx.dat -a -c2 -t BMP data/gfx/*.bmp

# Sounds
dat data/phantsnd.dat -a -c2 -t SAMP data/sfx/*.wav

# Global data file
dat data/phantom1.dat -a -c2 -t FILE data/phantgfx.dat
dat data/phantom1.dat -a -c2 -t FILE data/phantsnd.dat
dat data/phantom1.dat -a -c2 -t WLD data/phantwld.dat
dat data/phantom1.dat -a -c2 -t OGGV data/sfx/*.ogg

# Export new global data file headers
dat data/phantom1.dat -h src/phantom1.h

# Compile lua scripts
luac5.4 -s -o data/world.bin data/scripts/world.lua

# Remove temporary datafiles
rm data/phantfont.dat
rm data/phantgfx.dat
rm data/phantsnd.dat
