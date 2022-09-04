/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include "config.h"
#include <allegro.h>
#include <string.h>
#include "data.h"
#include "trans.h"
#include "log.h"
#include "path.h"
#include "phantom1.h"
#include "loadpc.h"
#include "bmpfnts.h"

DATA *ph_init_data(CFG *cfg, char *path) {
    const char dfile[] = "phantom1.dat";
    ph_log(_("- Initiating data: "));

    DATA *aux = (struct DATA *) malloc(sizeof(struct DATA));
    if (aux == NULL) {
        ph_log_memory_error((char *) "data.c", (char *) "ph_init_data", (char *) "aux", sizeof(struct DATA));
    }
    memset(aux, 0, sizeof(struct DATA));

    char *buf = (char *) malloc(sizeof(char) * 512);
    if (buf == NULL) {
        ph_log_memory_error((char *) "data.c", (char *) "ph_init_data", (char *) "buf", sizeof(char) * 512);
    }

    ph_log(_("Ok.\n"));

    memset(buf, 0, sizeof(char) * 512);
    strcpy(buf, cfg->datadir);
    buf[strlen(buf)] = '/';
    strcat(buf, dfile);
    ph_log(_("- Loading data file %s: "), ph_get_path(path, buf));
    /* Load parent data file */

    aux->df = load_datafile_callback(ph_get_path(path, buf), ph_load_callback);

    if (aux->df == NULL) {
        ph_log(_("Fatal error: Can't load the file: %s."), ph_get_path(path, buf));
        exit(13);
    } else {
        ph_log(_("Ok.\n"));
    }

    /* Load children data files */
    DATAFILE *tmp1 = (DATAFILE *) find_datafile_object(aux->df, "PHANTGFX_DAT");
    DATAFILE *tmp2 = (DATAFILE *) find_datafile_object(aux->df, "PHANTSND_DAT");
    aux->dgfx = (DATAFILE *) tmp1->dat;
    aux->dsnd = (DATAFILE *) tmp2->dat;
    free(buf);
    return aux;
}


void ph_destroy_data(DATA *data) {
    unload_datafile(data->df);
    free(data);
}


void ph_assign_data(DATA *data, CFG *cfg, GFX *gfx, SOUND *snd, PHFONT *fnt) {
#ifdef HAVE_ALOGG_H
    DATAFILE *dogg3;
#ifndef GP2X
    DATAFILE *dogg2;
#endif
#endif

    char *buf = (char *) malloc(sizeof(char) * 512);
    memset(buf, 0, sizeof(char) * 512);

    for (int i = PHANTGFX_DAT_BACK000_BMP; i < PHANTGFX_DAT_DEC00_0_BMP; i++) {
        gfx->backspr[i - PHANTGFX_DAT_BACK000_BMP] = (BITMAP *) data->dgfx[i].dat;
    }

    for (int i = PHANTGFX_DAT_DEC00_0_BMP; i < PHANTGFX_DAT_ENE00_0_0_BMP - 1; i++) {
        gfx->decspr[i - PHANTGFX_DAT_DEC00_0_BMP] = (BITMAP *) data->dgfx[i].dat;
    }

    for (int i = PHANTGFX_DAT_PHA00_0_1_BMP; i < PHANTGFX_DAT_PLA00_0_BMP; i++) {
        gfx->phspr[i - PHANTGFX_DAT_PHA00_0_1_BMP] = (BITMAP *) data->dgfx[i].dat;
    }

    for (int i = PHANTGFX_DAT_PLA00_0_BMP; i < PHANTGFX_DAT_X0_BMP - 1; i++) {
        gfx->plaspr[i - PHANTGFX_DAT_PLA00_0_BMP] = (BITMAP *) data->dgfx[i].dat;
    }
    gfx->logo[0] = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISLOGO00_BMP].dat;
    gfx->logo[1] = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISLOGO01_BMP].dat;
    gfx->logo[2] = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISLOGO02_BMP].dat;
    gfx->logo[3] = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISLOGO03_BMP].dat;
    gfx->logo[4] = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISLOGO04_BMP].dat;
    gfx->gameover = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISCGAMEOVER_BMP].dat;
    gfx->marc1 = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISCMARC1_BMP].dat;
    gfx->marc2 = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISCMARC2_BMP].dat;
    gfx->marc3 = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISCMARC3_BMP].dat;
    gfx->tr2x = (BITMAP *) data->dgfx[PHANTGFX_DAT_MISCTR2X_BMP].dat;

    for (int i = PHANTGFX_DAT_LIFE00_0_BMP; i <= PHANTGFX_DAT_LIFE00_3_BMP; i++) {
        gfx->lifespr[i - PHANTGFX_DAT_LIFE00_0_BMP] = (BITMAP *) data->dgfx[i].dat;
    }

    for (int i = PHANTGFX_DAT_SW00_0_BMP; i <= PHANTGFX_DAT_SW01_3_BMP; i++) {
        gfx->swspr[i - PHANTGFX_DAT_SW00_0_BMP] = (BITMAP *) data->dgfx[i].dat;
    }

#ifdef HAVE_ALOGG_H
#ifndef GP2X
    dogg2 = find_datafile_object(data->df, "SONG2_OGG");
#endif
    dogg3 = find_datafile_object(data->df, "SONG3_OGG");
#ifndef GP2X
    ASSERT(dogg2 != NULL);
#endif
    ASSERT(dogg3 != NULL);
    if (cfg->music && cfg->enable_sound) {
#ifndef GP2X
        snd->music->ogg2 = alogg_create_sample(dogg2);
#endif
        snd->music->ogg3 = alogg_create_sample(dogg3);
    }
#endif
    if (cfg->enable_sound && cfg->sfx) {
        snd->sfx->e1 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E1_WAV].dat;
        snd->sfx->e2 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E2_WAV].dat;
        snd->sfx->e4 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E4_WAV].dat;
        snd->sfx->e5 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E5_WAV].dat;
        snd->sfx->e6 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E6_WAV].dat;
        snd->sfx->e7 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E7_WAV].dat;
        snd->sfx->e8 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E8_WAV].dat;
        snd->sfx->e9 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E9_WAV].dat;
        snd->sfx->e10 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E10_WAV].dat;
        snd->sfx->e12 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E12_WAV].dat;
        snd->sfx->e13 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E13_WAV].dat;
        snd->sfx->e16 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E16_WAV].dat;
        snd->sfx->e19 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E19_WAV].dat;
        snd->sfx->e20 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E20_WAV].dat;
        snd->sfx->e22 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E22_WAV].dat;
        snd->sfx->e24 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E24_WAV].dat;
        snd->sfx->e30 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E30_WAV].dat;
        snd->sfx->e32 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E32_WAV].dat;
        snd->sfx->e35 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E35_WAV].dat;
        snd->sfx->e41 = (SAMPLE *) data->dsnd[PHANTSND_DAT_E41_WAV].dat;
        snd->sfx->ball = (SAMPLE *) data->dsnd[PHANTSND_DAT_BALL_WAV].dat;
        snd->sfx->hell = (SAMPLE *) data->dsnd[PHANTSND_DAT_HELLACOPTER_WAV].dat;
        snd->sfx->radar = (SAMPLE *) data->dsnd[PHANTSND_DAT_RADAR_WAV].dat;
        snd->sfx->bubbles = (SAMPLE *) data->dsnd[PHANTSND_DAT_BUBBLES_WAV].dat;
        snd->sfx->smoke1 = (SAMPLE *) data->dsnd[PHANTSND_DAT_SMOKE1_WAV].dat;
        snd->sfx->smoke2 = (SAMPLE *) data->dsnd[PHANTSND_DAT_SMOKE2_WAV].dat;
        snd->sfx->smoke3 = (SAMPLE *) data->dsnd[PHANTSND_DAT_SMOKE3_WAV].dat;
        snd->sfx->explo = (SAMPLE *) data->dsnd[PHANTSND_DAT_EXPLOSION1_WAV].dat;
        snd->sfx->menubegin = (SAMPLE *) data->dsnd[PHANTSND_DAT_MENUBEGIN_WAV].dat;
        snd->sfx->menuend = (SAMPLE *) data->dsnd[PHANTSND_DAT_MENUCONT_WAV].dat;
        snd->sfx->gameover = (SAMPLE *) data->dsnd[PHANTSND_DAT_GAMEOVER2_WAV].dat;
        snd->sfx->ts = (SAMPLE *) data->dsnd[PHANTSND_DAT_TS_WAV].dat;
        snd->sfx->click = (SAMPLE *) data->dsnd[PHANTSND_DAT_CLICK_WAV].dat;
        snd->sfx->clock = (SAMPLE *) data->dsnd[PHANTSND_DAT_CLOCK_WAV].dat;
        snd->sfx->push = (SAMPLE *) data->dsnd[PHANTSND_DAT_PUSH_WAV].dat;
        snd->sfx->hjump = (SAMPLE *) data->dsnd[PHANTSND_DAT_BOING1_WAV].dat;
        snd->sfx->ljump = (SAMPLE *) data->dsnd[PHANTSND_DAT_BOING2_WAV].dat;
        snd->sfx->hit = (SAMPLE *) data->dsnd[PHANTSND_DAT_HIT_WAV].dat;
        snd->sfx->eat = (SAMPLE *) data->dsnd[PHANTSND_DAT_ENERGY1_WAV].dat;
        snd->sfx->walk = (SAMPLE *) data->dsnd[PHANTSND_DAT_WALK_WAV].dat;
        snd->sfx->treasure = (SAMPLE *) data->dsnd[PHANTSND_DAT_TREASURE_WAV].dat;
        snd->sfx->speccy = (SAMPLE *) data->dsnd[PHANTSND_DAT_SPECCY_WAV].dat;
        snd->sfx->shoot = (SAMPLE *) data->dsnd[PHANTSND_DAT_SHOOT_WAV].dat;
        snd->sfx->space = (SAMPLE *) data->dsnd[PHANTSND_DAT_SPACE_WAV].dat;
        snd->sfx->rocket1 = (SAMPLE *) data->dsnd[PHANTSND_DAT_ROCKET_WAV].dat;
        snd->sfx->rocket2 = (SAMPLE *) data->dsnd[PHANTSND_DAT_ROCKET2_WAV].dat;
    } else {
        snd->sfx->rocket1 = NULL;
        snd->sfx->rocket2 = NULL;
        snd->sfx->space = NULL;
        snd->sfx->shoot = NULL;
        snd->sfx->ball = NULL;
        snd->sfx->hell = NULL;
        snd->sfx->radar = NULL;
        snd->sfx->bubbles = NULL;
        snd->sfx->smoke1 = NULL;
        snd->sfx->smoke2 = NULL;
        snd->sfx->smoke3 = NULL;
        snd->sfx->explo = NULL;
        snd->sfx->menubegin = NULL;
        snd->sfx->menuend = NULL;
        snd->sfx->gameover = NULL;
        snd->sfx->ts = NULL;
        snd->sfx->click = NULL;
        snd->sfx->clock = NULL;
        snd->sfx->push = NULL;
        snd->sfx->hjump = NULL;
        snd->sfx->ljump = NULL;
        snd->sfx->hit = NULL;
        snd->sfx->eat = NULL;
        snd->sfx->walk = NULL;
        snd->sfx->e1 = NULL;
        snd->sfx->e2 = NULL;
        snd->sfx->e4 = NULL;
        snd->sfx->e5 = NULL;
        snd->sfx->e6 = NULL;
        snd->sfx->e7 = NULL;
        snd->sfx->e8 = NULL;
        snd->sfx->e9 = NULL;
        snd->sfx->e10 = NULL;
        snd->sfx->e12 = NULL;
        snd->sfx->e13 = NULL;
        snd->sfx->e16 = NULL;
        snd->sfx->e19 = NULL;
        snd->sfx->e20 = NULL;
        snd->sfx->e22 = NULL;
        snd->sfx->e24 = NULL;
        snd->sfx->e30 = NULL;
        snd->sfx->e32 = NULL;
        snd->sfx->e35 = NULL;
        snd->sfx->e41 = NULL;
        snd->sfx->treasure = NULL;
        snd->sfx->speccy = NULL;
    }

    fnt->ufnt = (FONT *) databmpfnts[0].dat;
    fnt->fnt = (FONT *) databmpfnts[0].dat;

    free(buf);

}


void ph_load_callback(DATAFILE *dat_obj) {
    static unsigned long int a = 0L;
    static char firsttime = 1;
    static BITMAP *v, *load, *virt;
    static float p;
    int i = 0;
#ifndef GP2X
    unsigned int target = 611;
#else
    unsigned int target=610;
#endif

    if (firsttime) {
        fixup_datafile(datapc);
        load = (BITMAP *) datapc[B].dat;
        v = create_bitmap(load->w, load->h);
        virt = create_bitmap(320, 240);
        clear(virt);
        clear(v);
        p = 184;
        p /= 100;
    }
    a++;
    firsttime = 0;
    draw_sprite(v, load, 0, 0);
    i = (a * 184 / (target)) * (int) p;
    draw_sprite(virt, v, (320 >> 1) - (load->w >> 1), (240 / 3) - (load->h >> 1));
    rectfill(virt, 228 / 2, 190 / 2, (228 + i) / 2, 204 / 2, makecol(10 + (i >> 1), 10 + (i >> 1), 10 + (i >> 1)));
    rectfill(virt, 228 / 2, 192 / 2, (228 + i) / 2, 202 / 2, makecol(30 + (i >> 1), 30 + (i >> 1), 30 + (i >> 1)));
    rectfill(virt, 228 / 2, 194 / 2, (228 + i) / 2, 200 / 2, makecol(50 + (i >> 1), 50 + (i >> 1), 50 + (i >> 1)));
#ifndef GP2X
    textprintf_right_ex(virt, (FONT *) databmpfnts[0].dat, 638 / 2, 360 / 2, makecol(10 + (i), 10 + (i), 10 + (i)), -1,
                        "%s", _("Phantomas PC 1.3"));
#else
    textprintf_right_ex(virt,(FONT *)databmpfnts[0].dat,638/2,360/2,makecol(10+(i),10+(i),10+(i)),-1,"%s",_("Phantomas 2X"));
#endif
    textprintf_right_ex(virt, (FONT *) databmpfnts[0].dat, 638 / 2, 384 / 2, makecol(10 + (i), 10 + (i), 10 + (i)), -1,
                        "%s", _("Original game by Dinamic Software."));
    textprintf_right_ex(virt, (FONT *) databmpfnts[0].dat, 638 / 2, 408 / 2, makecol(10 + (i), 10 + (i), 10 + (i)), -1,
                        "%s", _("All trademarks are copyright of their respective authors."));
    textprintf_right_ex(virt, (FONT *) databmpfnts[0].dat, 638 / 2, 432 / 2, makecol(10 + (i), 10 + (i), 10 + (i)), -1,
                        "%s", _("2005-2010 Traperic Software."));
    stretch_blit(virt, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);

    if (a == target) {
        destroy_bitmap(v);
        destroy_bitmap(virt);
    }
}
