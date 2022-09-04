#include <string.h>
#include "vehicle.h"
#include "phantom1.h"

VEHICLE *ph_init_vehicles(void) {
    VEHICLE *aux;

    aux = (struct VEHICLE *) malloc(sizeof(struct VEHICLE));
    memset(aux, 0, sizeof(struct VEHICLE));
    return aux;
}


void ph_destroy_vehicles(VEHICLE *v) {
    free(v);
}


void ph_set_vehicles_data(VEHICLE *v, WORLD *w, PLAYER *pl) {
    int x, y;
    /*
    Tipo de los vehiculos
    1: helicoptero
    2: cohete
    3: ovni
    */
    x = fixtoi(pl->x);
    y = fixtoi(pl->y);
    switch (w->actroom) {
        case 2:
            if (!v->active) {
                v->type = 1;
                v->x = 192;
                v->y = 112;
                v->active = 1;
            }
            if (v->active == 1 && x == 216 && y == 144) {
                v->active = 2;
                pl->inchopper = 1;
            }
            break;
        case 5:
            if (!v->ractive) {
                v->type = 2;
                v->x = 176;
                v->y = 112;
                v->ractive = 1;
            }
            if (v->ractive == 1 && x == 208 && y == 128) {
                v->ractive = 7;
                v->actframe = 0;
                pl->inrocket = 1;
                pl->rocket = 1;
                pl->y = itofix(1);
            }
            break;
        case 65:
            if (v->active == 4 && x == 412 && y == 224) {
                v->active = 5;
                pl->inchopper = 1;
            }
            break;
        case 66:
            if (v->ractive == 3 && x == 208 && y == 152 && pl->special_switch_on) {
                v->ractive = 4;
                pl->inrocket = 1;
            }
            break;

    }
}


void ph_move_vehicles(VEHICLE *v, PLAYER *pl, SOUND *snd, CFG *cfg) {
    switch (v->type) {
        case 1:
            v->actframe++;
            if (v->actframe == 5) v->actframe = 0;
            if (v->active == 2) {
                if (v->y > -64) v->y -= 4;
                if (v->y == -64) {
                    /* Cambia la habitacion colega */
                    v->active = 3;
                }
            }
            if (v->active == 3) {
                v->x = 384;
                if (v->y < 192) v->y += 4;
                if (v->y == 192) {
                    v->active = 4;
                    pl->x = itofix(408);
                    pl->y = itofix(224);
                    pl->jumping = 0;
                    pl->right = 0;
                    pl->inchopper = 0;
                }
            }
            if (v->active == 5) {
                if (v->y > -64) v->y -= 4;
                if (v->y == -64) {
                    /* Cambia la habitacion colega */
                    v->active = 6;
                }
            }
            if (v->active == 6) {
                v->x = 192;
                if (v->y < 112) v->y += 4;
                if (v->y == 112) {
                    v->active = 0;
                    pl->x = itofix(220);
                    pl->y = itofix(144);
                    pl->jumping = 0;
                    pl->right = 1;
                    pl->inchopper = 0;
                }
            }
            if (v->active == 7) {
                pl->inchopper = 0;
            }
            break;

        case 2:
            v->actframe++;
            if (v->actframe >= 4) {
                if (v->ractive == 7) v->ractive = 2;
                v->actframe = 0;
            }
            if (v->ractive == 2) {
                if (v->y > -104) {
                    v->y -= 4;
                    ph_play_sample(snd->sfx->rocket1, v->x, cfg);
                }

                if (v->y == -104) {
                    v->ractive = 3;
                }
            }
            if (v->ractive == 3) {
                if (v->y < 112) {
                    v->y += 4;
                    ph_play_sample(snd->sfx->rocket1, v->x, cfg);
                }
                if (v->y == 112 && !pl->astro) {
                    pl->x = itofix(208);
                    pl->y = itofix(176);
                    pl->jumping = 0;
                    pl->right = 1;
                    pl->inrocket = 0;
                    pl->astro = 1;
                    ph_play_sample(snd->sfx->rocket2, v->x, cfg);
                }
            }
            if (v->ractive == 4) {
                if (v->y > -104) {
                    v->y -= 4;
                    ph_play_sample(snd->sfx->rocket1, v->x, cfg);
                }
                if (v->y == -104) {
                    v->ractive = 5;
                }
            }
            if (v->ractive == 5) {
                if (v->y < 112) {
                    v->y += 4;
                    ph_play_sample(snd->sfx->rocket1, v->x, cfg);
                }
                if (v->y == 112) {
                    ph_play_sample(snd->sfx->rocket2, v->x, cfg);
                    v->ractive = 6;
                    pl->x = itofix(208);
                    pl->y = itofix(176);
                    pl->jumping = 0;
                    pl->right = 1;
                    pl->inrocket = 0;
                    pl->astro = 0;
                }
            }

            break;
    }
}


void ph_draw_vehicles(VEHICLE *v, DATA *data, GFX *gfx, int actroom) {
    switch (v->type) {
        case 1:
            if (actroom == 2 || actroom == 65)
                draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC97_0_BMP + v->actframe].dat,
                            (v->x + X_DESP) / 2, (v->y + Y_DESP) / 2);
            rectfill(gfx->virt[0], 0, 0, 320, 28, makecol(0, 0, 0));
            break;
        case 2:
            if (actroom == 5 || actroom == 66) {
                if (v->ractive >= 2)
                    draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DECO122_0_BMP + v->actframe].dat,
                                (v->x + X_DESP) / 2, (v->y + Y_DESP) / 2);
                rectfill(gfx->virt[0], 0, 0, 320, 28, makecol(0, 0, 0));
            }
            break;
    }
}
