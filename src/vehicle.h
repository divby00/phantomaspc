#ifndef __VEHICLE_H
#define __VEHICLE_H

#include "world.h"
#include "data.h"
#include "gfx.h"
#include "player.h"
#include "sfx.h"
#include "config.h"

typedef struct VEHICLE {
    signed int x;
    signed int y;
    char active;
    char ractive;
    char actframe;
    char type;
} VEHICLE;

VEHICLE *ph_init_vehicles(void);

void ph_destroy_vehicles(VEHICLE *v);

void ph_draw_vehicles(VEHICLE *v, DATA *data, GFX *gfx, int actroom);

void ph_set_vehicles_data(VEHICLE *v, WORLD *w, PLAYER *pl);

void ph_move_vehicles(VEHICLE *v, PLAYER *pl, SOUND *snd, CFG *cfg);

#endif
