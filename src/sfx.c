
#include <allegro.h>
#include <malloc.h>
#include <string.h>
#include "config.h"

#include "cfg.h"
#include "log.h"
#include "sfx.h"
#include "trans.h"

SOUND *ph_init_sound(CFG *cfg) {
    SOUND *aux;

    if (!cfg->enable_sound) {
        ph_log(_("- Sound disabled.\n"));
        aux = (struct SOUND *) malloc(sizeof(struct SOUND));
        if (aux == NULL)
            ph_log_memory_error((char *) "sfx.c", (char *) "ph_init_sound", (char *) "aux", sizeof(struct SOUND));
        memset(aux, 0, sizeof(struct SOUND));
        aux->sfx = ph_init_sfx();
        aux->music = ph_init_music();
        return aux;
    } else {
        ph_log(_("- Initiating sound system: "));
        aux = (struct SOUND *) malloc(sizeof(struct SOUND));
        if (aux == NULL)
            ph_log_memory_error((char *) "sfx.c", (char *) "ph_init_sound", (char *) "aux", sizeof(struct SOUND));
        memset(aux, 0, sizeof(struct SOUND));
        if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL) != 0) {
            ph_log(_("Error initiating sound system.\n"));
            cfg->sfx = 0;
            cfg->music = 0;
            cfg->enable_sound = 0;
        } else {
            ph_log(_("Ok.\n"));
        }

        ph_log(_("- Initiating sound effects: "));
        aux->sfx = ph_init_sfx();

        if (aux->sfx != NULL) {
            if (cfg->sfx) {
                ph_log(_("Ok.\n"));
            } else {
                ph_log(_("Sound effects disabled.\n"));
            }
        }

        ph_log(_("- Initiating music: "));
        aux->music = ph_init_music();
        if (aux->music != NULL) {
            if (cfg->music) {
                ph_log(_("Ok.\n"));
            } else {
                ph_log(_("Music disabled.\n"));
            }
        }
    }
    aux->main_theme = 0;
#ifdef HAVE_ALOGG_H
    aux->music->voice = 0;
#endif
    return aux;
}


void ph_destroy_sound(CFG *cfg, SOUND *sound) {
#ifdef HAVE_ALOGG_H
    if (cfg->music && cfg->enable_sound) {
#ifndef GP2X
        destroy_sample(sound->music->ogg2);
#endif
        destroy_sample(sound->music->ogg3);
    }
    alogg_exit();
#endif

    if (cfg->enable_sound) {
        free(sound->sfx);
        free(sound->music);
        free(sound);
    }
}


SFX *ph_init_sfx(void) {
    SFX *aux;

    aux = (struct SFX *) malloc(sizeof(struct SFX));
    if (aux == NULL) ph_log_memory_error((char *) "sfx.c", (char *) "ph_init_sfx", (char *) "aux", sizeof(struct SFX));
    return aux;
}


MUSIC *ph_init_music(void) {
    MUSIC *aux;

    aux = (struct MUSIC *) malloc(sizeof(struct MUSIC));
    if (aux == NULL)
        ph_log_memory_error((char *) "sfx.c", (char *) "ph_init_music", (char *) "aux", sizeof(struct MUSIC));
#ifdef HAVE_ALOGG_H
    alogg_init();
#endif
    return aux;
}


void ph_play_sample(SAMPLE *sample, signed short int x, CFG *cfg) {
    int pan = 127;

    if (sample == NULL) return;
    if (cfg->enable_sound && cfg->sfx) {
        if (cfg->surround) pan = (255 * (x >> 1)) / 224; else pan = 127;
        play_sample(sample, cfg->sfxvolume, pan, 1000, 0);
    }
}


void ph_play_sample_falling(SAMPLE *sample, signed short int x, signed short int y, CFG *cfg) {
    int pan;

    if (sample == NULL) return;
    if (cfg->enable_sound && cfg->sfx) {
        pan = (255 * (x >> 1)) / 224;
        //pan=(255*x)/cfg->xres;
        play_sample(sample, cfg->sfxvolume, pan, 2000 - ((y * 1000) / 256), 0);
    }
}


void ph_play_ambient_sfx(int room, SOUND *sound, CFG *cfg) {
    SAMPLE *aux = NULL;
    stop_sample(sound->sfx->radar);
    stop_sample(sound->sfx->hell);
    stop_sample(sound->sfx->bubbles);
    stop_sample(sound->sfx->space);

    switch (room) {
        // Sonido radar.
        case 0:
            aux = sound->sfx->radar;
            break;
        case 2:
            aux = sound->sfx->hell;
            break;
        case 50:
            aux = sound->sfx->bubbles;
            break;
        case 65:
            aux = sound->sfx->hell;
            break;
        default:
            aux = NULL;
            break;
    }

    if (aux != NULL) {
        int v = play_sample(aux, cfg->sfxvolume, 127, 1000, 1);
        (void)v;
    }
}
