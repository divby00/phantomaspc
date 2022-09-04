/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include <string.h>
#include "ball.h"
#include "phantom1.h"

BALL *ph_init_ball(void) {
    BALL *aux = (struct BALL *) malloc(sizeof(struct BALL));
    memset(aux, 0, sizeof(struct BALL));
    aux->x = 0;
    aux->y = 128;
    return aux;
}


void ph_destroy_ball(BALL *b) {
    free(b);
}


void ph_move_ball(BALL *b) {
    b->actframe++;
    if (b->actframe == 8) b->actframe = 0;
    b->og = (b->actframe / 2);
    b->xg = (b->x + X_DESP) / 2;
    b->yg = (b->y + Y_DESP) / 2;
}


void ph_draw_ball(BALL *b, GFX *gfx, DATA *data) {
    if (b->active == 2) {
        draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE33_0_0_BMP + (b->og)].dat, b->xg, b->yg);
        rectfill(gfx->virt[0], 0, 0, 62 / 2, 480 / 2, makecol(0, 0, 0));
        rectfill(gfx->virt[0], 577 / 2, 0, 640 / 2, 480 / 2, makecol(0, 0, 0));
        rectfill(gfx->virt[0], 62 / 2, 0, 577 / 2, 52 / 2, makecol(0, 0, 0));
    }
}
