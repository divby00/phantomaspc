/*
	energy.c
	Author: Traperic <traperic@gmail.com>
*/

#include <string.h>
#include "trans.h"
#include "log.h"
#include "energy.h"
#include "gfx.h"
#include "player.h"
#include "ppcd.h"

ENERGY *ph_init_energy(void) {
    ENERGY *aux;

    ph_log(_("- Initiating energy: "));
    aux = (struct ENERGY *) malloc(sizeof(struct ENERGY));
    if (aux == NULL) {
        ph_log_memory_error((char *) "energy.c", (char *) "ph_init_energy", (char *) "aux", sizeof(struct ENERGY));
    }
    ph_log(_("Ok.\n"));
    memset(aux, 0, sizeof(struct ENERGY));
    return aux;
}


void ph_destroy_energy(ENERGY *energy) {
    free(energy);
}


void ph_create_energy(ENERGY *energy, int x, int y, char energyid) {
    energy->x[(int) energy->actenergy] = x;
    energy->y[(int) energy->actenergy] = y;

    if (!energy->got[(int) energyid]) {
        if (!energy->known[(int) energyid]) {
            energy->known2++;
            energy->known[(int) energyid] = 1;
        }
        energy->active[(int) energy->actenergy] = 1;
        energy->energyid[(int) energy->actenergy] = energyid;
    }

    energy->actenergy++;
    if (energy->actenergy >= MAXENERGY) energy->actenergy = 0;
}


void ph_draw_energy(ENERGY *energy, GFX *gfx) {
    int i;

    for (i = 0; i < MAXENERGY; i++) {
        if (energy->active[(int) i]) {
            draw_sprite(gfx->virt[0], gfx->lifespr[rand() % 4], (energy->x[(int) i] + X_DESP) / 2,
                        (energy->y[(int) i] + Y_DESP) / 2);
        }
    }
}


void ph_get_energy(ENERGY *energy, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg) {
    int i;
    BITMAP *aux = NULL;
    BITMAP *aux1 = NULL;

    if (pl->energy >= 238) return;

    clear(gfx->phhelper);
    aux1 = gfx->phhelper;

    if (pl->falling) {
        aux = gfx->phspr[5 + fixtoi(pl->aniframe)];
    }
    if (pl->jumping) {
        aux = gfx->phspr[4];
    }
    if (!pl->jumping && !pl->falling) {
        aux = gfx->phspr[fixtoi(pl->aniframe)];
    }

    if (!pl->right) {
        draw_sprite_h_flip(aux1, aux, 0, 0);
        aux = aux1;
    }

    for (i = 0; i < MAXENERGY; i++) {
        if (energy->active[i]) {
            if (sn_collision(aux, fixtoi(pl->x), fixtoi(pl->y), gfx->lifespr[0], energy->x[(int) i],
                             energy->y[(int) i])) {
                pl->energy += 20;
                pl->left_energy++;
                if (pl->energy > 238) {
                    pl->energy = 238;
                }
                energy->active[i] = 0;
                energy->got[(int) energy->energyid[i]] = 1;
                if (!pl->firsttimeenergy) pl->firsttimeenergy = 1;
                if (cfg->enable_sound && cfg->sfx) {
                    ph_play_sample(snd->sfx->eat, fixtoi(pl->x), cfg);
                }
                if (pl->energy == 238) break;
            }

        }
    }
}
