#include <string.h>
#include "switch.h"
#include "trans.h"
#include "log.h"
#include "gfx.h"
#include "ppcd.h"

SWITCH *ph_init_switches(void) {
    SWITCH *aux;

    ph_log(_("- Initiating switches: "));
    aux = (struct SWITCH *) malloc(sizeof(struct SWITCH));
    if (aux == NULL)
        ph_log_memory_error((char *) "switch.c", (char *) "ph_init_switches", (char *) "aux", sizeof(struct SWITCH));
    ph_log(_("Ok.\n"));
    memset(aux, 0, sizeof(struct SWITCH));
    return aux;
}


void ph_destroy_switches(SWITCH *sw) {
    free(sw);
}


void ph_create_switch(SWITCH *sw, int x, int y, int actframe, int framespeed, char switchid) {
    if (switchid >= MAXSWITCHES) switchid = 0;
    sw->x[(int) switchid] = x;
    sw->y[(int) switchid] = y;
    sw->active[(int) switchid] = 1;

    if (!sw->pressed[(int) switchid]) {
        sw->switchid[(int) switchid] = switchid;
    }

    sw->actframe[(int) switchid] = actframe;
    sw->framespeed[(int) switchid] = framespeed;
}


void ph_draw_switch(SWITCH *sw, GFX *gfx) {
    int i;

    for (i = 0; i < MAXSWITCHES; i++) {
        if (sw->active[(int) i]) {
            if (!sw->pressed[(int) i])
                draw_sprite(gfx->virt[0], gfx->swspr[0], (sw->x[(int) i] + X_DESP) / 2, (sw->y[(int) i] + Y_DESP) / 2);
            else
                draw_sprite(gfx->virt[0], gfx->swspr[4], (sw->x[(int) i] + X_DESP) / 2, (sw->y[(int) i] + Y_DESP) / 2);
        }
    }
}


void ph_push_switch(SWITCH *sw, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg, WORLD *w) {
    int i;
    BITMAP *aux = NULL;

    if (pl->falling) {
        aux = gfx->phspr[5 + fixtoi(pl->aniframe)];
    }

    if (pl->jumping) {
        aux = gfx->phspr[4];
    }

    if (!pl->jumping && !pl->falling) {
        aux = gfx->phspr[fixtoi(pl->aniframe)];
    }

    for (i = 0; i < MAXSWITCHES; i++) {
        if (sw->active[(int) i]) {
            if (sn_collision(aux, fixtoi(pl->x), fixtoi(pl->y), gfx->swspr[0], sw->x[(int) i], sw->y[(int) i])) {
                if (!sw->pressed[(int) sw->switchid[i]]) {
                    if (cfg->enable_sound && cfg->sfx)
                        ph_play_sample(snd->sfx->push, fixtoi(pl->x), cfg);
                    pl->pressed_switches++;
                    sw->pressed[(int) sw->switchid[i]] = 1;
                    if (!pl->firsttimeswitch) pl->firsttimeswitch = 1;
                    if (w->actroom == 66) pl->special_switch_on = 1;
                }
            }
        }
    }
}
