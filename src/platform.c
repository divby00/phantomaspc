
#include <string.h>
#include "gfx.h"
#include "platform.h"
#include "player.h"
#include "log.h"
#include "trans.h"

PLATFORM *ph_init_platforms(void) {
    PLATFORM *aux;

    ph_log(_("- Initiating platforms: "));
    aux = (struct PLATFORM *) malloc(sizeof(struct PLATFORM));
    if (aux == NULL)
        ph_log_memory_error((char *) "platform.c", (char *) "ph_init_platforms", (char *) "aux",
                            sizeof(struct PLATFORM));
    memset(aux, 0, sizeof(struct PLATFORM));
    ph_log(_("Ok.\n"));
    return aux;
}


void ph_destroy_platforms(PLATFORM *plat) {
    free(plat);
}


/*void ph_create_platform(PLATFORM *plat, char type, short int x, short int y,
	char xspeed, char yspeed, short int xlimitl, short int ylimitu, short int xlimitr,
	short int ylimitd, char up, char right)*/
void ph_create_platform(PLATFORM *plat, char type, int x, int y, int xspeed, int yspeed,
                        int xlimitl, int ylimitu, int xlimitr, int ylimitd, char up, char right) {
    plat->type[plat->actplatform] = type;
    plat->x[plat->actplatform] = itofix(x);
    plat->y[plat->actplatform] = itofix(y);
    plat->xspeed[plat->actplatform] = itofix(xspeed);
    plat->yspeed[plat->actplatform] = itofix(yspeed);
    plat->xlimitl[plat->actplatform] = xlimitl;
    plat->ylimitu[plat->actplatform] = ylimitu;
    plat->xlimitr[plat->actplatform] = xlimitr;
    plat->ylimitd[plat->actplatform] = ylimitd;
    plat->up[plat->actplatform] = up;
    plat->right[plat->actplatform] = right;
    plat->active[plat->actplatform] = 1;
    plat->frame[plat->actplatform] = 0;
    plat->actplatform++;
    if (plat->actplatform >= MAXPLATFORMS) plat->actplatform = 0;
}


void ph_move_platforms(PLATFORM *plat, PLAYER *pl, WORLD *w) {
    unsigned char i;

    for (i = 0; i < MAXPLATFORMS; i++) {
        if (plat->active[(int) i] && !plat->up[(int) i]) {

            if (pl->onplatform && (i == pl->onplatform - 1)) {
                if (plat->right[(int) i]) {
                    if (!(w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                        (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 1) >> 4])
                        && (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 15) >> 4])) {
                        pl->x = fixadd(pl->x, plat->xspeed[(int) i]);
                    }
                } else {
                    if (!(w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                        (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 1) >> 4])
                        && (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 15) >> 4])) {
                        pl->x = fixsub(pl->x, plat->xspeed[(int) i]);
                    }
                }
            }
            if (plat->right[(int) i]) {
                plat->x[(int) i] = fixadd(plat->x[(int) i], plat->xspeed[(int) i]);
            } else {
                plat->x[(int) i] = fixsub(plat->x[(int) i], plat->xspeed[(int) i]);
            }
            if (fixtoi(plat->x[(int) i]) >= plat->xlimitr[(int) i]) {
                plat->right[(int) i] = 0;
            }
            if (fixtoi(plat->x[(int) i]) <= plat->xlimitl[(int) i]) {
                plat->right[(int) i] = 1;
            }
        }

        if (plat->active[(int) i] && plat->up[(int) i]) {

            if (pl->onplatform && (i == pl->onplatform - 1)) {

                if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) - 1) >> 4]) &&
                    (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) - 1) >> 4])
                    && (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) - 1) >> 4])) {
                    if (plat->up[(int) i] == 1) {
                        pl->y = fixsub(pl->y, plat->yspeed[(int) i]);
                    }
                } else {
                    plat->up[(int) i] = 2;
                }

                if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                    (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4])
                    && (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4])) {
                    if (plat->up[(int) i] == 2)
                        pl->y = fixadd(pl->y, plat->yspeed[(int) i]);
                }
            }
            if (plat->up[(int) i] == 1) {
                plat->y[(int) i] = fixsub(plat->y[(int) i], plat->yspeed[(int) i]);
            }
            if (plat->up[(int) i] == 2) {
                plat->y[(int) i] = fixadd(plat->y[(int) i], plat->yspeed[(int) i]);
            }
            if (fixtoi(plat->y[(int) i]) >= plat->ylimitd[(int) i]) {
                plat->up[(int) i] = 1;
            }
            if (fixtoi(plat->y[(int) i]) <= plat->ylimitu[(int) i]) {
                plat->up[(int) i] = 2;
            }
        }
    }
}


void ph_draw_platforms(PLATFORM *plat, GFX *gfx) {
    unsigned char i;

    for (i = 0; i < MAXPLATFORMS; i++) {
        if (plat->active[(int) i]) {
            draw_sprite(gfx->virt[0], gfx->plaspr[4 * plat->type[(int) i] + (plat->frame[(int) i] / 2)],
                        (fixtoi(plat->x[(int) i]) + X_DESP) / 2, (fixtoi(plat->y[(int) i]) + Y_DESP) / 2);
            plat->frame[(int) i]++;
            if (plat->frame[(int) i] == 8) plat->frame[(int) i] = 0;
        }
    }
}
