/*
	Header file for switch.h
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __SWITCH_H
#define __SWITCH_H

#include "cfg.h"
#include "sfx.h"
#include "gfx.h"
#include "player.h"
#include "world.h"

#define MAXSWITCHES 36
#define SWITCHES_TO_OPEN_SAFE 36

typedef struct SWITCH {
    signed short int x[MAXSWITCHES];
    signed short int y[MAXSWITCHES];
    unsigned char active[MAXSWITCHES];
    unsigned char pressed[100];
    unsigned char actswitch;
    unsigned char switchid[100];
    unsigned char actframe[MAXSWITCHES];
    unsigned char framespeed[MAXSWITCHES];
} SWITCH;

SWITCH *ph_init_switches(void);

void ph_destroy_switches(SWITCH *sw);

void ph_draw_switch(SWITCH *sw, GFX *gfx);

void ph_create_switch(SWITCH *sw, int x, int y, int actframe, int framespeed, char switchid);

void ph_push_switch(SWITCH *sw, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg, WORLD *w);

#endif
