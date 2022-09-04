#ifndef __MENU_H
#define __MENU_H

#include "gfx.h"
#include "data.h"
#include "texter.h"
#include "mouse.h"
#include "config.h"

#define MAXELEMENTS     10

#define MAIN_MENU           0
#define PLAY_MENU           1
#define OPTIONS_MENU        2
#define EXIT_MENU           4
#define SCREEN_MENU         5
#define SOUND_MENU          6
#define CONTROL_MENU        8
#define GAME_MENU           9
#define CONTROLTYPE_MENU    10
#define FULLSCREEN_MENU     11
#define INGAME_MENU         12
#define RES_MENU            13
#define INOPTIONS_MENU      14
#define MUSIC_MENU          15
#define SFX_MENU            16
#define SURROUND_MENU       17
#define SCANLINES_MENU      18
#define MVOL_MENU           19
#define SVOL_MENU           20
#define STIPS_MENU          21
#define REDEFINE_MENU       22

typedef struct TMENU {
    char showmenu;
    char activemenu;
    char elements;
    char actelement;
    char *title;
    char *msg[MAXELEMENTS];
    char linknext[MAXELEMENTS];
    int x;
    int y;
    int longerstring;
} TMENU;

TMENU *ph_init_menu();

void ph_destroy_menu(TMENU *tmenu);

void ph_set_menu_defaults(TMENU *tmenu);

void ph_set_menu_options(PHFONT *font, TMENU *tmenu);

#endif
