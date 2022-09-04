/*
	intro.c
	Author: Traperic <traperic@gmail.com>
*/

#include "intro.h"
#include "trans.h"
#include "phantom1.h"
#include "fades.h"

/*!
 * Esta funcion se encarga de animar la pequena introduccion del juego.
 * @param p puntero con los datos del programa.
 */
void ph_do_intro(PROGRAM *p) {
    BITMAP *bmp = create_bitmap(320, 240);
    clear_to_color(bmp, makecol(0, 0, 0));
    clear_to_color(screen, makecol(0, 0, 0));
    clear_to_color(p->gfx->virt[0], makecol(0, 0, 0));
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR2_BMP].dat, (240 + 60) / 2, (40 + 50) / 2);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR1_BMP].dat, (110 + 60) / 2, (50 + 50) / 2);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR4_BMP].dat, (147 + 60) / 2, (198 + 50) / 2);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR3_BMP].dat, (130 + 60) / 2, (240 + 50) / 2);
    ph_fade_in(bmp, 8);
    clear(bmp);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR2_BMP].dat, (240 + 60) / 2, (40 + 50) / 2);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR1_BMP].dat, (110 + 60) / 2, (50 + 50) / 2);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR4_BMP].dat, (147 + 60) / 2, (198 + 50) / 2);
    draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCTR3_BMP].dat, (130 + 60) / 2, (240 + 50) / 2);
    acquire_screen();
    stretch_blit(bmp, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
    release_screen();
    ph_play_sample((SAMPLE *) p->snd->sfx->ts, 160, p->cfg);
    rest(1500);
    ph_fade_out(8, p->cfg);
    destroy_bitmap(bmp);
}
