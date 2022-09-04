#ifndef __GFX_H
#define __GFX_H

#include <allegro.h>
#include "cfg.h"
#include "enemy2.h"

#define X_DESP  80
#define Y_DESP  68
#define MAXVIRTSCREENS 1
#define MAXSPRDEC 179
#define MAXSPRPH 117
#define MAXSPRBACK 10
#define MAXSPRPLAT 20
#define MAXSPRPLIFE 4
#define MAXSPRSW 8

typedef struct GFX {
    BITMAP *virt[MAXVIRTSCREENS];
    BITMAP *backspr[MAXSPRBACK];
    BITMAP *enespr[MAX_ENEMIES][4];
    BITMAP *decspr[MAXSPRDEC];
    BITMAP *phspr[MAXSPRPH];
    BITMAP *plaspr[MAXSPRPLAT];
    BITMAP *lifespr[MAXSPRPLIFE];
    BITMAP *swspr[MAXSPRSW];
    BITMAP *logo[5];
    BITMAP *gameover;
    BITMAP *tr2x;
    BITMAP *phhelper;
    BITMAP *marc1;
    BITMAP *marc2;
    BITMAP *marc3;
} GFX;

GFX *ph_init_gfx(CFG *cfg);

void ph_destroy_gfx(GFX *gfx);

void ph_draw(GFX *gfx, CFG *cfg);

#endif
