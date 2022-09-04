#ifndef __SFX_H
#define __SFX_H

#include "config.h"

#include <allegro.h>
#include "cfg.h"
#include "gfx.h"
#include "texter.h"

#ifdef HAVE_ALOGG_H

#include "alogg.h"

#endif

typedef struct SFX {
    int ambient;
    SAMPLE *e1;
    SAMPLE *e2;
    SAMPLE *e3;
    SAMPLE *e4;
    SAMPLE *e5;
    SAMPLE *e6;
    SAMPLE *e7;
    SAMPLE *e8;
    SAMPLE *e9;
    SAMPLE *e10;
    SAMPLE *e11;
    SAMPLE *e12;
    SAMPLE *e13;
    SAMPLE *e14;
    SAMPLE *e15;
    SAMPLE *e16;
    SAMPLE *e17;
    SAMPLE *e18;
    SAMPLE *e19;
    SAMPLE *e20;
    SAMPLE *e22;
    SAMPLE *e24;
    SAMPLE *e30;
    SAMPLE *e32;
    SAMPLE *e35;
    SAMPLE *e41;

    SAMPLE *ball;
    SAMPLE *hell;
    SAMPLE *radar;
    SAMPLE *smoke1;
    SAMPLE *smoke2;
    SAMPLE *smoke3;
    SAMPLE *explo;
    SAMPLE *shoot;
    SAMPLE *rocket1;
    SAMPLE *rocket2;
    SAMPLE *space;
    SAMPLE *menubegin;
    SAMPLE *menuend;
    SAMPLE *ts;
    SAMPLE *gameover;
    SAMPLE *hjump;
    SAMPLE *ljump;
    SAMPLE *push;
    SAMPLE *eat;
    SAMPLE *hit;
    SAMPLE *click;
    SAMPLE *clock;
    SAMPLE *bubbles;
    SAMPLE *walk;
    SAMPLE *treasure;
    SAMPLE *speccy;
} SFX;

typedef struct MUSIC {
#ifdef HAVE_ALOGG_H
#ifndef GP2X
    SAMPLE *ogg2;
#endif
    SAMPLE *ogg3;
#ifndef GP2X
    DATAFILE *dogg2;
#endif
    DATAFILE *dogg3;
    int voice;
#endif

#if HAVE_LOGG_H
#ifndef GP2X
    SAMPLE *ogg2;
#endif
    SAMPLE *ogg3;
#ifndef GP2X
    DATAFILE *dogg2;
#endif
    DATAFILE *dogg3;
    int voice;
#endif

} MUSIC;

typedef struct SOUND {
    SFX *sfx;
    MUSIC *music;
    unsigned char main_theme;
} SOUND;

SOUND *ph_init_sound(CFG *cfg);

void ph_destroy_sound(CFG *cfg, SOUND *sound);

SFX *ph_init_sfx();

MUSIC *ph_init_music();

void ph_play_sample(SAMPLE *sample, signed short int x, CFG *cfg);

void ph_play_sample_falling(SAMPLE *sample, signed short int x, signed short int y, CFG *cfg);

void ph_play_ambient_sfx(int room, SOUND *sound, CFG *cfg);

#endif
