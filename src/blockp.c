/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include <string.h>
#include "blockp.h"
#include "phantom1.h"

BLOCK *ph_init_block(void) {
    BLOCK *aux = (struct BLOCK *) malloc(sizeof(struct BLOCK));
    memset(aux, 0, sizeof(struct BLOCK));
    aux->bmp = create_bitmap(128, 64);
    clear_to_color(aux->bmp, makecol(255, 120, 255));
    aux->y = 32;
    aux->x = 176;
    return aux;
}


void ph_destroy_block(BLOCK *bl) {
    destroy_bitmap(bl->bmp);
    free(bl);
}


void ph_move_block(BLOCK *bl, PLAYER *pl) {
    if (!bl->active) return;
    if (bl->y < 128) {
        bl->y += 8;
    } else {
        pl->energy -= 2;
    }
}


void ph_draw_block(BLOCK *bl, GFX *gfx, DATA *data) {
    draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DECO108_0_BMP].dat, (bl->x + X_DESP) / 2,
                (bl->y + Y_DESP) / 2);
}


void ph_throw_block(BLOCK *bl, PLAYER *pl) {
    int x, y;

    x = fixtoi(pl->x);
    y = fixtoi(pl->y);

    if (x == 224 && y == 192 && !bl->active && !pl->treasure) {
        bl->active = 1;
    }
}
