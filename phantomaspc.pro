QMAKE_PROJECT_NAME = phantomaspc
QMAKE_CFLAGS += -DLINUX -DCUSTOM_PATH -Wno-unused-parameter -Wno-aggressive-loop-optimizations -Wno-cast-function-type


HEADERS +=  src/alogg.h\
            src/aloggcfg.h\
            src/aloggint.h\
            src/arrows.h\
            src/back.h\
            src/ball.h\
            src/blockp.h\
            src/bmpfnts.h\
            src/cfg.h\
            src/config.h\
            src/control.h\
            src/control2.h\
            src/data.h\
            src/editor.h\
            src/enemy.h\
            src/enemy2.h\
            src/energy.h\
            src/fades.h\
            src/game.h\
            src/gfx.h\
            src/hand.h\
            src/intro.h\
            src/loadpc.h\
            src/log.h\
            src/luaphant.h\
            src/menu.h\
            src/menu2.h\
            src/mouse.h\
            src/path.h\
            src/phantom1.h\
            src/platform.h\
            src/player.h\
            src/ppcd.h\
            src/program.h\
            src/records.h\
            src/sfx.h\
            src/switch.h\
            src/texter.h\
            src/timer.h\
            src/trans.h\
            src/vehicle.h\
            src/world.h
SOURCES +=  src/alogg.c\
            src/arrows.c\
            src/back.c\
            src/ball.c\
            src/blockp.c\
            src/bmpfnts.c\
            src/config.c\
            src/control.c\
            src/data.c\
            src/editor.c\
            src/enemy.c\
            src/energy.c\
            src/game.c\
            src/gfx.c\
            src/hand.c\
            src/intro.c\
            src/loadpc.c\
            src/log.c\
            src/luaphant.c\
            src/main.c\
            src/menu.c\
            src/menu2.c\
            src/mouse.c\
            src/path.c\
            src/platform.c\
            src/player.c\
            src/ppcd.c\
            src/program.c\
            src/records.c\
            src/sfx.c\
            src/switch.c\
            src/texter.c\
            src/timer.c\
            src/vehicle.c\
            src/world.c
win32 {
    HEADERS += src/w_res.h
}

INCLUDEPATH = '/usr/include/lua5.4'
QMAKE_LIBDIR = '/usr/lib/x86_64-linux-gnu'
LIBS += -llua5.4 -lalleg -lvorbisfile -lvorbisenc -lvorbis -logg -lm
QT -= gui core

DISTFILES += \
    README.md \
    builddata.sh \
    builddeb.sh \
    buildtrans.sh \
    buildwin.sh

