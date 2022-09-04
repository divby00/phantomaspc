/*
	Header file for arrows.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __ARROWS_H
#define __ARROWS_H

#include "gfx.h"
#include "data.h"
#include "player.h"
#include "world.h"
#include "sfx.h"
#include "cfg.h"

#define MAXARROWS 10

typedef struct ARROWS {
    signed int x[MAXARROWS];
    signed int y[MAXARROWS];
    unsigned char active[MAXARROWS];
    unsigned char actarrow;
    unsigned char arrow1;
    unsigned char arrow2;
    unsigned char arrow3;
} ARROWS;

ARROWS *ph_init_arrows(void);

void ph_destroy_arrows(ARROWS *ar);

void ph_move_arrows(ARROWS *ar);

void ph_draw_arrows(ARROWS *ar, DATA *data, GFX *gfx);

void ph_throw_arrows(ARROWS *ar, PLAYER *pl);

void ph_clean_arrows(ARROWS *ar);

void ph_arrows_damage_player(ARROWS *ar, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg, DATA *data);

#endif
