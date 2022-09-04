/*
	Header file for texter.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __TEXTER_H
#define __TEXTER_H

#include <allegro.h>
#include <stdarg.h>
#include "config.h"

#define TXT_LEFT        0
#define TXT_CENTER      1
#define TXT_RIGHT       2
#define TXT_TITLE       3

typedef struct PHFONT {
    FONT *fnt;
    FONT *ufnt;
    signed int color;
    signed int back;
    unsigned char fonttype;
    unsigned char align;
    unsigned char aa;
} PHFONT;

PHFONT *ph_init_texter(void);

void ph_destroy_texter(PHFONT *pfont);

void ph_set_text_properties(PHFONT *pf, int color, int back, char fonttype, char align, char aa);

void ph_text(BITMAP *bmp, PHFONT *pf, signed short int x, signed short int y, char *buffer);

void ph_printf(BITMAP *bmp, PHFONT *pf, signed short int x, signed short int y, char *buf, ...);

void ph_shprintf(BITMAP *bmp, PHFONT *pf, signed short int x, signed short int y, char *buf, ...);

int ph_text_len(PHFONT *pfont, char *buffer);

#endif
