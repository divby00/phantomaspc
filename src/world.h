#ifndef __WORLD_H
#define __WORLD_H

#include "gfx.h"
#include "data.h"
#include "player.h"

#define XMAXTILE 30
#define YMAXTILE 18
#define MAXWORLDROOMS 69

typedef struct WORLD {
    unsigned char room[XMAXTILE][YMAXTILE];
    unsigned char cross[XMAXTILE][YMAXTILE];
    unsigned char backdata;
    unsigned char *decdata;
    unsigned char *crossdata;
    unsigned char *enemydata;
    unsigned char *miscdata;
    unsigned char initroom;
    unsigned char actroom;
    signed short int wtriggers;
    signed short int xinit;
    signed short int yinit;
    char visited_rooms[MAXWORLDROOMS];
    signed int xg;
    signed int odd;
} WORLD;

WORLD *ph_init_world(void);

void ph_destroy_world(WORLD *w);

WORLD *ph_load_world_data(WORLD *w, char *path);

WORLD *ph_load_world_data_alt(WORLD *w, DATA *data);

void ph_save_world_data(WORLD *w, char *path);

void ph_get_room_data(WORLD *w, int room, PLAYER *pl);

#endif
