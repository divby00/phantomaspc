#ifndef __HAND_H
#define __HAND_H

#include "player.h"
#include "ppcd.h"
#include "sfx.h"
#include "cfg.h"

typedef struct HAND {
    char active;
    char expactive;
    /* Contador de animacion de la mano*/
    char hframe;
    /* Contador de animacion de la explosion del rayo */
    char expframe;
    /* Coordenadas de la mano */
    signed int x, y;
    /* Coordenadas del rayo */
    signed int xr, yr;
} HAND;

HAND *ph_init_hand(void);

void ph_destroy_hand(HAND *hand);

void ph_move_hand(HAND *hand, PLAYER *pl);

void ph_draw_hand(HAND *hand, GFX *gfx, DATA *data, CFG *cfg, SOUND *snd);

void ph_exp_damage_player(HAND *hand, PLAYER *pl, GFX *gfx, SOUND *sfx, CFG *cfg, DATA *data);

#endif
