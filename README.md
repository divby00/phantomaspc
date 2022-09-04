# Phantomas PC

Phantomas remake. A platform game where you need to guide a thief around a mansion hunting some treasures and avoiding the enemies. Check [here](http://www.worldofspectrum.org/infoseekid.cgi?id=0003686) for more information.

## License

Phantomas PC is a gift. You can use, redistribute and modify it in any way and you don't need to pay anything for it.

This software is distributed without any warranty, use it on your own risk.

This software includes the Alogg library from Vincent Penquerc'h. This library is distributed under the terms of the LGPL.

## Building from source

### Ubuntu

On Ubuntu based distros, the process is quite straightforward:

    sudo apt install build-essential liballegro4-dev libvorbis-dev liblua5.4-dev lua5.4 qmake6

Make sure lua5.4 is in the path

    cd into the projects root folder
    
    chmod +x builddata.sh && ./builddata.sh 
    
    qmake6 phantomas1.pro
    
    make

### Other systems

On any other operating system or Linux distros, things could be different. Use the information in this section to help yourself to build the project on these systems.

#### Dependencies

Needed dependencies:

* allegro 4.0.0 or higher, 4.2 and 4.4 work as well. Get it [here](http://alleg.sf.net).

* lua 5.1.3 or higher. Get it [here](http://www.lua.org).

Optional dependencies:

* libogg y libvorbis. (Ogg music support). Get them [here](http://www.xyph.org).

* [libintl](http://gnuwin32.sourceforge.net/packages/libintl.htm) and [libiconv](http://gnuwin32.sourceforge.net/packages/libiconv.htm) (Translations support).

In order to build the game you need to follow these steps:

* Build the data file with Allegro's dat utility, you can use the script `builddata.sh`.

* Build the project, use `qmake` to generate a `Makefile` for it. Maybe you need to tweak in the Makefile some of the paths to the libraries (-L parameter) or includes (-I parameter). You can disable the use of some libraries by changing the value of the directives in the `config.h` file.