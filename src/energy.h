/*
	Header file for energy.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __ENERGY_H
#define __ENERGY_H

#include "gfx.h"
#include "data.h"
#include "player.h"
#include "sfx.h"
#include "cfg.h"

#define MAXENERGY   10

typedef struct ENERGY {
    signed short int x[MAXENERGY];
    signed short int y[MAXENERGY];
    char active[MAXENERGY];
    char energyid[MAXENERGY];
    char got[62];
    char known[62];
    char known2;
    char actenergy;
} ENERGY;

ENERGY *ph_init_energy(void);

void ph_destroy_energy(ENERGY *energy);

void ph_create_energy(ENERGY *energy, int x, int y, char energyid);

void ph_draw_energy(ENERGY *energy, GFX *gfx);

void ph_get_energy(ENERGY *energy, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg);

#endif
