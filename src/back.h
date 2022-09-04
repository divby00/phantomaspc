/*
	Header file for back.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __BACK_H
#define __BACK_H

#include "world.h"
#include "gfx.h"

void ph_set_background_image(WORLD *world, unsigned char index);

void ph_draw_back_image(WORLD *world, GFX *gfx);

void ph_move_back_image(WORLD *world);

#endif
