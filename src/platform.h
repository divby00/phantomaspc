/*
	Header file for platform.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __PLATFORM_H
#define __PLATFORM_H

#include "player.h"

#include "world.h"
/*! Max. platforms per screen */
#define MAXPLATFORMS 10

typedef struct PLATFORM {
    unsigned char type[MAXPLATFORMS];
    fixed x[MAXPLATFORMS];
    fixed y[MAXPLATFORMS];
    signed short int xmap[MAXPLATFORMS];
    signed short int ymap[MAXPLATFORMS];
    signed short int xlimitl[MAXPLATFORMS];
    signed short int xlimitr[MAXPLATFORMS];
    signed short int ylimitu[MAXPLATFORMS];
    signed short int ylimitd[MAXPLATFORMS];
    fixed xspeed[MAXPLATFORMS];
    fixed yspeed[MAXPLATFORMS];
    unsigned char frame[MAXPLATFORMS];
    unsigned char active[MAXPLATFORMS];
    unsigned char right[MAXPLATFORMS];
    unsigned char up[MAXPLATFORMS];
    unsigned char actplatform;
} PLATFORM;

void ph_move_platforms(PLATFORM *plat, PLAYER *pl, WORLD *w);

PLATFORM *ph_init_platforms(void);

void ph_destroy_platforms(PLATFORM *plat);

void ph_draw_platforms(PLATFORM *plat, GFX *gfx);

void ph_create_platform(PLATFORM *plat, char type, int x, int y, int xspeed, int yspeed, int xlimitl, int ylimitu,
                        int xlimitr, int ylimitd, char up, char right);

#endif
