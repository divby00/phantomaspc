/*
	Header file for back.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __BALL_H
#define __BALL_H

#include "gfx.h"
#include "data.h"

typedef struct BALL {
    signed int og;
    signed int xg;
    signed int yg;
    signed int x;
    signed int y;
    char active;
    char actframe;
} BALL;

BALL *ph_init_ball(void);

void ph_destroy_ball(BALL *b);

void ph_move_ball(BALL *b);

void ph_draw_ball(BALL *b, GFX *gfx, DATA *data);

#endif
