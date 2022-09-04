/*
	Header file for control.h
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __CONTROL2_H
#define __CONTROL2_H

#include "program.h"

CONTROL *ph_read_control(PROGRAM *p, CONTROL *c, TMENU *menu, PHFONT *font);

void *ph_read_common_keys(PROGRAM *p, CONTROL *c, TMENU *menu, PHFONT *font);

void ph_redefine_keys(PROGRAM *p);

void ph_return_game_menu(PROGRAM *p);

CONTROL *ph_read_control_in_ball(PROGRAM *p, CONTROL *c);

#endif
