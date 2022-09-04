#ifndef __DATA_H
#define __DATA_H

#include <allegro.h>
#include "cfg.h"
#include "gfx.h"
#include "sfx.h"
#include "texter.h"

typedef struct DATA {
    DATAFILE *df;
    DATAFILE *dgfx;
    DATAFILE *dsnd;
} DATA;

DATA *ph_init_data(CFG *cfg, char *path);

void ph_destroy_data(DATA *data);

void ph_assign_data(DATA *data, CFG *cfg, GFX *gfx, SOUND *snd, PHFONT *fnt);

void ph_load_callback(DATAFILE *dat_obj);

#endif
