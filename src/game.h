/*
	Header file for game.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __GAME_H
#define __GAME_H

#include "cfg.h"
#include "gfx.h"
#include "program.h"

void ph_start_game(PROGRAM *p);

void ph_change_room(PROGRAM *p, int room);

PROGRAM *ph_game_over(PROGRAM *p);

PROGRAM *ph_reset_data(PROGRAM *p);

char ph_special_cases(PROGRAM *p);

void ph_draw_dec(PROGRAM *p);

void ph_in_game_message(CONTROL *c, GFX *gfx, CFG *cfg, SOUND *sound, PLAYER *pl, PHFONT *fnt, char event);

void ph_game_end2(PROGRAM *p);

void ph_do_speccy(PROGRAM *p);

void ph_do_sp_speccy(int x, int y, BITMAP *pieces[], PROGRAM *p);

void ph_draw_text_box(GFX *gfx, CFG *cfg);

void ph_draw_marc(PROGRAM *p);

#endif
