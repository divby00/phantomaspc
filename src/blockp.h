/*
	Header file for block.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __BLOCK_H
#define __BLOCK_H

#include <allegro.h>
#include "gfx.h"
#include "player.h"
#include "data.h"

typedef struct BLOCK {
    signed int x;
    signed int y;
    BITMAP *bmp;
    char active;
} BLOCK;

BLOCK *ph_init_block(void);

void ph_destroy_block(BLOCK *bl);

void ph_throw_block(BLOCK *bl, PLAYER *pl);

void ph_draw_block(BLOCK *bl, GFX *gfx, DATA *data);

void ph_move_block(BLOCK *bl, PLAYER *pl);

#endif
