#include <string.h>
#include "gfx.h"
#include "data.h"
#include "hand.h"
#include "phantom1.h"

#define TIMEXP 2

HAND *ph_init_hand(void) {
    HAND *aux = (struct HAND *) malloc(sizeof(struct HAND));
    memset(aux, 0, sizeof(struct HAND));
    aux->x = 80;
    aux->y = 192;
    aux->active = 1;
    return aux;
}


void ph_destroy_hand(HAND *hand) {
    free(hand);
}


void ph_move_hand(HAND *hand, PLAYER *pl) {
    if (hand->active) {
        if (!hand->hframe) {
            hand->xr = fixtoi(pl->x);
            hand->yr = fixtoi(pl->y);
            hand->xr += 16;
            hand->yr += 16;
        }
        hand->hframe++;
        if (hand->hframe == 32) hand->hframe = 0;
        if (hand->hframe == 16) hand->expactive = 0;
    }
    if (hand->expactive) {
        if (hand->xr >= 416 && hand->yr >= 64 && hand->yr <= 176) {
            pl->explotedoor = 1;
        }
    }
}


void ph_draw_hand(HAND *hand, GFX *gfx, DATA *data, CFG *cfg, SOUND *snd) {
    if (hand->active) {
        if (hand->hframe >= 0 && hand->hframe < 2)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE34_0_0_BMP].dat, (hand->x + X_DESP) / 2,
                        (hand->y + Y_DESP) / 2);
        if (hand->hframe >= 2 && hand->hframe < 4)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE34_1_0_BMP].dat, (hand->x + X_DESP) / 2,
                        (hand->y + Y_DESP) / 2);
        if (hand->hframe >= 4 && hand->hframe < 10)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE34_2_0_BMP].dat, (hand->x + X_DESP) / 2,
                        (hand->y + Y_DESP) / 2);
        if (hand->hframe >= 10 && hand->hframe < 12)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE34_3_0_BMP].dat, (hand->x + X_DESP) / 2,
                        (hand->y + Y_DESP) / 2);
        if (hand->hframe >= 12 && hand->hframe < 14)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE34_0_0_BMP].dat, (hand->x + X_DESP) / 2,
                        (hand->y + Y_DESP) / 2);

        if (hand->hframe >= 6 && hand->hframe <= 9) {
            line(gfx->virt[0], (hand->x + 32 + X_DESP) / 2, (hand->y + 8 + Y_DESP) / 2, (hand->xr + X_DESP) / 2,
                 (hand->yr + Y_DESP) / 2, makecol(200, 0, 0));
            hand->expactive = 1;
        }
        if (hand->hframe == 9) ph_play_sample(snd->sfx->explo, 160, cfg);
    }

    if (hand->expactive) {
        draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE43_0_0_BMP + hand->expframe].dat,
                    (hand->xr - 16 + X_DESP) / 2, (hand->yr - 16 + Y_DESP) / 2);
        hand->expframe++;
        if (hand->expframe == 4) {
            hand->expframe = 0;
            hand->expactive = 0;
        }
    }
}


void ph_exp_damage_player(HAND *hand, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg, DATA *data) {
    BITMAP *aux = NULL;
    BITMAP *aux1 = NULL;

    if (!hand->expactive) return;
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

    if (sn_collision(aux, fixtoi(pl->x), fixtoi(pl->y),
                     (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE43_0_0_BMP + hand->expframe].dat, hand->xr, hand->yr)) {
        pl->energy -= 10;
        pl->damaging = 1;
        if (cfg->enable_sound && cfg->sfx) ph_play_sample(snd->sfx->hit, fixtoi(pl->x), cfg);
    }
}
