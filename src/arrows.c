/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include <string.h>
#include "arrows.h"
#include "phantom1.h"
#include "ppcd.h"
#include "trans.h"
#include "log.h"

ARROWS *ph_init_arrows(void) {
    ARROWS *aux;

    ph_log(_("- Initiating arrows: "));
    aux = (struct ARROWS *) malloc(sizeof(struct ARROWS));
    if (aux == NULL) {
        ph_log_memory_error((char *) "arrows.c", (char *) "ph_init_arrows", (char *) "aux", sizeof(struct ARROWS));
    }
    ph_log(_("Ok.\n"));
    memset(aux, 0, sizeof(struct ARROWS));
    return aux;
}


void ph_destroy_arrows(ARROWS *ar) {
    free(ar);
}


void ph_move_arrows(ARROWS *ar) {
    for (int i = 0; i < MAXARROWS; i++) {
        if (ar->active[i] && ar->x[i] < 432) {
            ar->x[i] += 20;
        }
        if (ar->x[i] >= 432 && ar->active[i]) {
            if (ar->y[i] == 72) ar->arrow1 = 0;
            if (ar->y[i] == 128) ar->arrow2 = 0;
            if (ar->y[i] == 192) ar->arrow3 = 0;
            ar->active[i] = 0;
        }
    }
}


void ph_draw_arrows(ARROWS *ar, DATA *data, GFX *gfx) {
    for (int i = 0; i < MAXARROWS; i++) {
        if (ar->active[i]) {
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE30_0_5_BMP].dat, (ar->x[i] + X_DESP) / 2,
                        (ar->y[i] + Y_DESP) / 2);
        }
    }
}


void ph_throw_arrows(ARROWS *ar, PLAYER *pl) {
    int y = fixtoi(pl->y);

    if (y >= 68 && y <= 76 && !ar->active[ar->actarrow] && !ar->arrow1) {
        ar->arrow1 = 1;
        ar->active[ar->actarrow] = 1;
        ar->x[ar->actarrow] = 16;
        ar->y[ar->actarrow] = 72;
        ar->actarrow++;
    }

    if (y >= 116 && y <= 124 && !ar->active[ar->actarrow] && !ar->arrow2) {
        ar->arrow2 = 1;
        ar->active[ar->actarrow] = 1;
        ar->x[ar->actarrow] = 16;
        ar->y[ar->actarrow] = 128;
        ar->actarrow++;
    }

    if (y >= 188 && y <= 196 && !ar->active[ar->actarrow] && !ar->arrow3) {
        ar->arrow3 = 1;
        ar->active[ar->actarrow] = 1;
        ar->x[ar->actarrow] = 16;
        ar->y[ar->actarrow] = 192;
        ar->actarrow++;
    }

    if (ar->actarrow == MAXARROWS) ar->actarrow = 0;
}


void ph_clean_arrows(ARROWS *ar) {
    memset(ar, 0, sizeof(struct ARROWS));
}


void ph_arrows_damage_player(ARROWS *ar, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg, DATA *data) {
    char i;
    BITMAP *aux = NULL;
    BITMAP *aux1 = NULL;

    clear(gfx->phhelper);
    aux1 = gfx->phhelper;

    if (pl->falling) {
        aux = gfx->phspr[5 + fixtoi(pl->aniframe)];
        if (!pl->right) blit(aux, aux, 0, 0, 0, 0, aux->w, aux->h);
    }

    if (pl->jumping) {
        aux = gfx->phspr[4];
        if (!pl->right) blit(aux, aux, 0, 0, 0, 0, aux->w, aux->h);
    }

    if (!pl->jumping && !pl->falling) {
        aux = gfx->phspr[fixtoi(pl->aniframe)];
    }

    if (!pl->right) {
        draw_sprite_h_flip(aux1, aux, 0, 0);
        aux = aux1;
    }

    for (i = 0; i < MAXARROWS; i++) {
        if (ar->active[(int) i]) {
            if (sn_collision(aux, fixtoi(pl->x), fixtoi(pl->y), (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE30_0_5_BMP].dat,
                             ar->x[(int) i], ar->y[(int) i])) {
                draw_sprite(screen, (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE30_0_5_BMP].dat, ar->x[(int) i],
                            ar->y[(int) i]);
                pl->energy = 0;
                pl->damaging = 1;
                if (cfg->enable_sound && cfg->sfx) ph_play_sample(snd->sfx->hit, fixtoi(pl->x), cfg);
            }
        }
    }
}
