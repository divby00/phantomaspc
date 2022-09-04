/*
	Header file for menu2.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __MENU2_H
#define __MENU2_H

#include "program.h"

void ph_menu_target_incrementor(void *t);

typedef void(*TFPO)(void *);

void ph_do_menu1(PROGRAM *p);

void ph_show_menu_page(PROGRAM *p, char page, BITMAP *bmp);

#endif
