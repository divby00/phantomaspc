/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include <allegro.h>
#include <malloc.h>
#include <string.h>
#include "editor.h"
#include "log.h"
#include "trans.h"
#include "world.h"
#include "phantom1.h"

EDITOR *ph_init_editor(void) {
    ph_log(_("- Initiating editor: "));
    EDITOR *aux = (struct EDITOR *) malloc(sizeof(struct EDITOR));
    if (aux == NULL) {
        ph_log_memory_error((char *) "editor.c", (char *) "ph_init_editor", (char *) "aux", sizeof(struct EDITOR));
    }
    memset(aux, 0, sizeof(struct EDITOR));
    ph_log(_("Ok.\n"));
    aux->showgrid = 1;
    aux->xtiles = 30;
    aux->ytiles = 18;
    aux->xtile = 16;
    aux->ytile = 16;
    aux->xview = 20;
    aux->yview = 20;
    aux->xgrid = 16;
    aux->ygrid = 16;
    aux->xcursor = aux->xview;
    aux->ycursor = aux->yview;
    aux->guicolor = makecol(120, 120, 120);
    aux->focusedguicolor = makecol(200, 200, 200);
    aux->showrooms = 1;
    aux->disable_showrooms = 0;
    aux->selitem = 1;
    aux->selenemy = 0;
    aux->enemymode = 0;
    return aux;
}


void ph_destroy_editor(EDITOR *ed) {
    if (ed->showrooms) {
        unload_datafile(ed->roomdata);
    }
    free(ed);
}


void ph_run_editor(EDITOR *ed, GFX *gfx, DATA *data, WORLD *w, char *path) {
    poll_keyboard();
    while (!key[KEY_ESC]) {
        poll_keyboard();
        rest(40);
        if (key[KEY_1]) ed->focus = 0;
        if (key[KEY_2]) ed->focus = 1;
        if (key[KEY_3]) ed->focus = 2;
        if (key[KEY_4]) ed->focus = 3;

        if (key[KEY_TAB]) {
            if (key[KEY_LSHIFT] || key[KEY_RSHIFT]) {
                ed->focus--;
                if (ed->focus < 0) ed->focus = 3;
            } else {
                ed->focus++;
                if (ed->focus == 4) ed->focus = 0;
            }
        }

        switch (ed->focus) {
            case 0:
                if (ed->platmode) {
                    if (key[KEY_O]) ed->imagemode = 0;
                    if (key[KEY_RIGHT]) ed->x2capt += ed->xtile;
                    if (key[KEY_LEFT]) ed->x2capt -= ed->xtile;
                    if (key[KEY_UP]) ed->y2capt -= ed->ytile;
                    if (key[KEY_DOWN]) ed->y2capt += ed->ytile;
                    if (key[KEY_ENTER]) {
                        ph_grab_image(ed, gfx);
                    }
                }

                if (ed->imagemode) {
                    if (key[KEY_O]) ed->imagemode = 0;
                    if (key[KEY_RIGHT]) ed->x2capt += ed->xtile;
                    if (key[KEY_LEFT]) ed->x2capt -= ed->xtile;
                    if (key[KEY_UP]) ed->y2capt -= ed->ytile;
                    if (key[KEY_DOWN]) ed->y2capt += ed->ytile;
                    if (key[KEY_ENTER]) {
                        ph_grab_image(ed, gfx);
                    }
                }

                if (ed->enemymode) {
                    if (key[KEY_O]) ed->imagemode = 0;
                    if (key[KEY_RIGHT]) ed->x2capt += ed->xtile;
                    if (key[KEY_LEFT]) ed->x2capt -= ed->xtile;
                    if (key[KEY_UP]) ed->y2capt -= ed->ytile;
                    if (key[KEY_DOWN]) ed->y2capt += ed->ytile;
                    if (key[KEY_ENTER]) {
                        ph_set_enemy(ed);
                    }
                    if (key[KEY_PLUS_PAD] && ed->selenemy < (35 * 4)) ed->selenemy += 4;
                    if (key[KEY_MINUS_PAD] && ed->selenemy > 0) ed->selenemy -= 4;
                }

                if (!ed->imagemode && !ed->enemymode) {
                    if (key[KEY_P]) {
                        ed->platmode = 1;
                        ed->x1capt = ed->xcursor;
                        ed->y1capt = ed->ycursor;
                        ed->x2capt = ed->xcursor + ed->xtile;
                        ed->y2capt = ed->ycursor + ed->ytile;
                    }
                    if (key[KEY_I]) {
                        ed->imagemode = 1;
                        ed->x1capt = ed->xcursor;
                        ed->y1capt = ed->ycursor;
                        ed->x2capt = ed->xcursor + ed->xtile;
                        ed->y2capt = ed->ycursor + ed->ytile;
                    }
                    if (key[KEY_RIGHT] && ed->xmap < ed->xtiles - 1) ed->xcursor += ed->xtile;
                    if (key[KEY_LEFT] && ed->xmap > 0) ed->xcursor -= ed->xtile;
                    if (key[KEY_UP] && ed->ymap > 0) ed->ycursor -= ed->ytile;
                    if (key[KEY_DOWN] && ed->ymap < ed->ytiles - 1) ed->ycursor += ed->ytile;
                    if (key[KEY_PLUS_PAD] && ed->selitem < MAXSPRDEC - 1) ed->selitem++;
                    if (key[KEY_MINUS_PAD] && ed->selitem > 0) ed->selitem--;
                    if (key[KEY_G]) ed->showgrid ^= 1;
                    if (key[KEY_PGUP] && ed->actroom > 0) ed->actroom--;
                    if (key[KEY_PGDN] && ed->actroom < MAXWORLDROOMS) ed->actroom++;
                    if (key[KEY_B] && !ed->disable_showrooms) ed->showrooms ^= 1;
                    if (key[KEY_S]) ph_save_world_data(w, path);
                    if (key[KEY_L]) w = ph_load_world_data(w, path);
                    if (key[KEY_K]) ph_do_brick_block(ed, w);
                    if (key[KEY_F]) ph_set_enemy(ed);
                    if (key[KEY_E]) {
                        ed->enemymode = 1;
                        ed->x1capt = ed->xcursor;
                        ed->y1capt = ed->ycursor;
                        ed->x2capt = ed->xcursor + ed->xtile;
                        ed->y2capt = ed->ycursor + ed->ytile;
                    }

                    if (key[KEY_ENTER]) {
                        w->decdata[((ed->xtiles * ed->ymap) + ed->xmap) +
                                   (ed->actroom * ed->xtiles * ed->ytiles)] = ed->selitem;
                    }
                    if (key[KEY_C]) {
                        w->crossdata[((ed->xtiles * ed->ymap) + ed->xmap) +
                                     (ed->actroom * ed->xtiles * ed->ytiles)] = 1;
                    }
                    if (key[KEY_V]) {
                        w->crossdata[((ed->xtiles * ed->ymap) + ed->xmap) +
                                     (ed->actroom * ed->xtiles * ed->ytiles)] = 0;
                    }
                    if (key[KEY_SPACE]) {
                        w->decdata[((ed->xtiles * ((ed->ycursor >> 4) - 1)) + ((ed->xcursor >> 4) - 1)) +
                                   (ed->actroom * ed->xtiles * ed->ytiles)] = 0;
                    }
                    if (key[KEY_N]) {
                        memset(w->decdata, 0, sizeof(char) * XMAXTILE * YMAXTILE * MAXWORLDROOMS);
                    }
                }
                break;
        }

        ph_set_map_coords(ed, ed->xcursor, ed->ycursor);
        clear_to_color(gfx->virt[0], makecol(40, 30, 100));
        ph_draw_editor_gui(ed, gfx);
        ph_draw_background_grid(ed, gfx);
        ph_draw_background_image(ed, gfx);
        ph_draw_world_data(w, ed, gfx);
        ph_draw_cursor(ed, gfx, data);
        ph_show_grid(ed);
        acquire_screen();
        blit(gfx->virt[0], screen, 0, 0, 0, 0, gfx->virt[0]->w, gfx->virt[0]->h);
        release_screen();
    }
}


void ph_show_grid(EDITOR *ed) {
    int i;

    if (ed->showgrid) {
        for (i = 0; i < ed->xtiles; i++) {
        }
    }
}


void ph_draw_editor_gui(EDITOR *ed, GFX *gfx) {
    int color = ed->guicolor;
    int i, a;
    int b = 0;
    char *imagemodemsg[] = {_("Off"), _("On")};

    /* Dibujar zona principal */
    textprintf_ex(gfx->virt[0], font, ed->xview, ed->yview - 12, makecol(200, 200, 200), -1, "%s",
                  _("Phantomas PC Editor. Press F1 for help."));

    if (ed->focus == 0) color = ed->focusedguicolor; else color = ed->guicolor;

    rect(gfx->virt[0], ed->xview - 1, ed->yview - 1, ed->xview + (ed->xtile * ed->xtiles),
         ed->yview + (ed->ytile * ed->ytiles), makecol(0, 0, 0));
    rect(gfx->virt[0], ed->xview - 2, ed->yview - 2, ed->xview + (ed->xtile * ed->xtiles) + 1,
         ed->yview + (ed->ytile * ed->ytiles) + 1, color);
    rect(gfx->virt[0], ed->xview - 3, ed->yview - 3, ed->xview + (ed->xtile * ed->xtiles) + 2,
         ed->yview + (ed->ytile * ed->ytiles) + 2, color);
    rect(gfx->virt[0], ed->xview - 4, ed->yview - 4, ed->xview + (ed->xtile * ed->xtiles) + 3,
         ed->yview + (ed->ytile * ed->ytiles) + 3, makecol(0, 0, 0));
    textprintf_ex(gfx->virt[0], font, ed->xview, ed->yview + (ed->ytile * ed->ytiles) + 5, makecol(200, 200, 200), -1,
                  _("Room:%d  X:%d  Y:%d  Item:%d  Image mode: %s"), ed->actroom, ed->xmap, ed->ymap, ed->selitem,
                  imagemodemsg[ed->imagemode]);

    /* Dibujar selector de tiles */
    if (ed->focus == 1) color = ed->focusedguicolor; else color = ed->guicolor;

    rectfill(gfx->virt[0], ed->xview - 1, (ed->yview - 1) + (ed->ytiles * ed->ytile) + 18,
             ed->xview + (ed->xtile * ed->xtiles), (ed->yview - 1) + (ed->ytiles * ed->ytile) + 128,
             makecol(20, 20, 20));
    rectfill(gfx->virt[0], ed->xview - 1, (ed->yview - 1) + (ed->ytiles * ed->ytile) + 18,
             ed->xview + (ed->xtile * ed->xtiles), (ed->yview - 1) + (ed->ytiles * ed->ytile) + 18 + 36,
             makecol(40, 40, 40));
    rect(gfx->virt[0], ed->xview - 1, (ed->yview - 1) + (ed->ytiles * ed->ytile) + 18,
         ed->xview + (ed->xtile * ed->xtiles), (ed->yview - 1) + (ed->ytiles * ed->ytile) + 128, makecol(0, 0, 0));
    rect(gfx->virt[0], ed->xview - 2, (ed->yview - 2) + (ed->ytiles * ed->ytile) + 18,
         ed->xview + (ed->xtile * ed->xtiles + 1), (ed->yview - 1) + (ed->ytiles * ed->ytile) + 129, color);
    rect(gfx->virt[0], ed->xview - 3, (ed->yview - 3) + (ed->ytiles * ed->ytile) + 18,
         ed->xview + (ed->xtile * ed->xtiles + 2), (ed->yview - 1) + (ed->ytiles * ed->ytile) + 130, color);
    rect(gfx->virt[0], ed->xview - 4, (ed->yview - 4) + (ed->ytiles * ed->ytile) + 18,
         ed->xview + (ed->xtile * ed->xtiles + 3), (ed->yview - 1) + (ed->ytiles * ed->ytile) + 131, makecol(0, 0, 0));

    for (a = ed->selitem; a < ed->selitem + 15; a++) {
        stretch_sprite(gfx->virt[0], gfx->decspr[ed->selitem + b], (b * 32) + ed->xview,
                       (ed->yview) + (ed->ytiles * ed->ytile) + 20, 32, 32);
        stretch_sprite(gfx->virt[0], gfx->decspr[ed->selitem + b], (b * 32) + ed->xview,
                       (ed->yview) + (ed->ytiles * ed->ytile) + 20 + 36, 32, 32);
        stretch_sprite(gfx->virt[0], gfx->decspr[ed->selitem + b], (b * 32) + ed->xview,
                       (ed->yview) + (ed->ytiles * ed->ytile) + 20 + 36 + 36, 32, 32);
        b++;
    }

    /* Dibujar mapa del mundo */
    if (ed->focus == 2) color = ed->focusedguicolor; else color = ed->guicolor;

    rect(gfx->virt[0], ed->xview - 1 + 505, ed->yview - 1, ed->xview + 605, ed->yview + 100, makecol(0, 0, 0));
    rect(gfx->virt[0], ed->xview - 1 + 504, ed->yview - 2, ed->xview + 606, ed->yview + 101, color);
    rect(gfx->virt[0], ed->xview - 1 + 503, ed->yview - 3, ed->xview + 607, ed->yview + 102, color);
    rect(gfx->virt[0], ed->xview - 1 + 502, ed->yview - 4, ed->xview + 608, ed->yview + 103, makecol(0, 0, 0));

    for (a = ed->yview; a < ed->yview + 100; a += 10) {
        for (i = (ed->xview + 505); i < (ed->xview + 605); i += 10) {
            rect(gfx->virt[0], i + 1, a + 1, i + 8, a + 8, makecol(100, 100, 100));
        }
    }

    textprintf_ex(gfx->virt[0], font, 10, 465, makecol(120, 120, 120), -1, "%d",
                  ((ed->xtiles * ed->ymap) + ed->xmap) + (ed->actroom * ed->xtiles * ed->ytiles));
}


void ph_draw_cursor(EDITOR *ed, GFX *gfx, DATA *data) {
    if (!ed->imagemode && !ed->enemymode) {
        draw_sprite(gfx->virt[0], gfx->decspr[ed->selitem], ed->xcursor, ed->ycursor);
        rect(gfx->virt[0], ed->xcursor + 1, ed->ycursor + 1, ed->xcursor + ed->xtile - 2, ed->ycursor + ed->ytile - 2,
             makecol(0, 0, 0));
        rect(gfx->virt[0], ed->xcursor + 2, ed->ycursor + 2, ed->xcursor + ed->xtile - 3, ed->ycursor + ed->ytile - 3,
             makecol(220, 0, 220));
        rect(gfx->virt[0], ed->xcursor + 3, ed->ycursor + 3, ed->xcursor + ed->xtile - 4, ed->ycursor + ed->ytile - 4,
             makecol(0, 0, 0));
    } else {
        rect(gfx->virt[0], ed->x1capt, ed->y1capt, ed->x2capt, ed->y2capt, makecol(255, 0, 255));
        rect(gfx->virt[0], ed->x1capt - 1, ed->y1capt - 1, ed->x2capt + 1, ed->y2capt + 1, makecol(0, 0, 0));
    }

    if (ed->enemymode) {
        BITMAP *img = (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE01_0_0_BMP + ed->selenemy].dat;
        draw_sprite(gfx->virt[0], img, 500, 120);
    }
}


void ph_set_map_coords(EDITOR *ed, int x, int y) {
    ed->xmap = (x - ed->xview) / ed->xtile;
    ed->ymap = (y - ed->yview) / ed->ytile;
}


void ph_load_editor_aux_data(EDITOR *ed, CFG *cfg) {
    char *buffer;

    ph_log(_("- Loading editor auxiliar data file %sphanted.dat: "), cfg->datadir);
    buffer = (char *) malloc(sizeof(char) * 512);
    if (buffer == NULL)
        ph_log_memory_error((char *) "editor.c", (char *) "ph_load_editor_aux_data", (char *) "buffer",
                            sizeof(char) * 512);

    strcpy(buffer, cfg->datadir);
    strcat(buffer, "phanted.dat");
    ed->roomdata = load_datafile(buffer);
    if (ed->roomdata == NULL) {
        ph_log(_("Warning: Can't find file. Disabling the use of phanted.dat.\n"));
        ed->showrooms = 0;
        ed->disable_showrooms = 1;
    } else {
        ph_log(_("Ok.\n"));
        ed->showrooms = 1;
        ed->disable_showrooms = 0;
    }
    free(buffer);
}


void ph_draw_background_grid(EDITOR *ed, GFX *gfx) {
    int i;
    int a;
    char gridcolor = 10;

    for (a = 0; a < ed->ytiles; a++) {
        for (i = 0; i < ed->xtiles; i++) {
            if (!(i % 2)) {
                gridcolor = 20;
                if (!(a % 2)) gridcolor = 40; else gridcolor = 20;
                if ((a % 2)) gridcolor = 20; else gridcolor = 40;
            } else {
                gridcolor = 40;
                if (!(a % 2)) gridcolor = 20; else gridcolor = 40;
                if ((a % 2)) gridcolor = 40; else gridcolor = 20;
            }

            rectfill(gfx->virt[0], (i * ed->xgrid) + ed->xview, (a * ed->ygrid) + ed->yview,
                     (i * ed->xgrid) + ed->xgrid + ed->xview - 1, (a * ed->ygrid) + ed->ygrid + ed->yview - 1,
                     makecol(gridcolor, gridcolor, gridcolor));
        }
    }
}


void ph_draw_background_image(EDITOR *ed, GFX *gfx) {
    if (!ed->disable_showrooms && ed->showrooms) {
        stretch_blit((BITMAP *) ed->roomdata[ed->actroom].dat, gfx->virt[0], 0, 0, 240, 144, ed->xview, ed->yview, 480,
                     288);
    }
}


void ph_draw_world_data(WORLD *w, EDITOR *ed, GFX *gfx) {
    int x, y;

    for (y = 0; y < ed->ytiles; y++) {
        for (x = 0; x < ed->xtiles; x++) {
            if (w->decdata[((ed->xtiles * y) + x) + (ed->actroom * ed->xtiles * ed->ytiles)]) {
                draw_sprite(gfx->virt[0], gfx->decspr[(short int) w->decdata[(short int) ((ed->xtiles * y) + x) +
                                                                             (ed->actroom * ed->xtiles * ed->ytiles)]],
                            (x * ed->xtile) + ed->xview, (y * ed->ytile) + ed->yview);
            }
            if (w->crossdata[((ed->xtiles * y) + x) + (ed->actroom * ed->xtiles * ed->ytiles)]) {
                rect(gfx->virt[0], (x * ed->xtile) + ed->xview + 5, (y * ed->ytile) + ed->yview + 5,
                     (x * ed->xtile) + ed->xview + 11, (y * ed->ytile) + ed->yview + 11, makecol(0, 0, 0));
                rect(gfx->virt[0], (x * ed->xtile) + ed->xview + 6, (y * ed->ytile) + ed->yview + 6,
                     (x * ed->xtile) + ed->xview + 10, (y * ed->ytile) + ed->yview + 10, makecol(220, 220, 220));
                rect(gfx->virt[0], (x * ed->xtile) + ed->xview + 7, (y * ed->ytile) + ed->yview + 7,
                     (x * ed->xtile) + ed->xview + 9, (y * ed->ytile) + ed->yview + 9, makecol(0, 0, 0));
            }
        }
    }
}


void ph_grab_image(EDITOR *ed, GFX *gfx) {
    static int snapshot = 0;
    char *buf;
    BITMAP *bmp;
    int x = 0;
    int y = 0;
    int ancho;
    int alto;
    int i = 0;
    int a = 0;

    buf = (char *) malloc(sizeof(char) * 512);
    if (buf == NULL)
        ph_log_memory_error((char *) "editor.c", (char *) "ph_grab_image", (char *) "buf", sizeof(char) * 512);
    sprintf(buf, (char *) "data/gfx/editor/exgfx/dec%d.bmp", snapshot);

    ancho = ed->x2capt - ed->x1capt;
    alto = ed->y2capt - ed->y1capt;

    bmp = create_bitmap(ancho, alto);
    clear_to_color(bmp, makecol(0, 0, 0));

    i = 0;
    a = 0;
    ph_draw_background_image(ed, gfx);

    for (y = ed->y1capt; y < ed->y2capt + 1; y++) {
        for (x = ed->x1capt; x < ed->x2capt + 1; x++) {

            if ((!getpixel((BITMAP *) gfx->virt[0], x, y)) || ((getpixel((BITMAP *) gfx->virt[0], x, y)) == 51200)) {
                putpixel(bmp, i, a, makecol(255, 0, 255));
            } else {
                putpixel(bmp, i, a, makecol(255, 255, 255));
            }
            i++;
        }
        i = 0;
        a++;
    }

    ed->imagemode = 0;
    save_bmp(buf, bmp, NULL);
    snapshot++;
    destroy_bitmap(bmp);
    free(buf);
}


void ph_do_brick_block(EDITOR *ed, WORLD *w) {
    int i, a, b;

    for (i = 0; i < 29; i += 2) {
        w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + i] = PHANTGFX_DAT_DEC43_0_BMP;
        w->crossdata[(ed->actroom * ed->xtiles * ed->ytiles) + i] = 1;
    }
    for (i = 0; i < 28; i += 2) {
        w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + i + 31] = PHANTGFX_DAT_DEC43_0_BMP;
        w->crossdata[(ed->actroom * ed->xtiles * ed->ytiles) + i + 31] = 1;
    }
    w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + 30] = PHANTGFX_DAT_DEC45_0_BMP;
    w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + 59] = PHANTGFX_DAT_DEC44_0_BMP;
    w->crossdata[(ed->actroom * ed->xtiles * ed->ytiles) + 30] = 1;
    w->crossdata[(ed->actroom * ed->xtiles * ed->ytiles) + 59] = 1;

    for (i = 0; i < 15; i++) {
        a = (rand() % 59);
        b = rand() % 2;
        if (a == 30) a = 31;
        if (!(a % 2) && a < 30) {
            w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + a] = PHANTGFX_DAT_DEC46_0_BMP + (b * 3);
        }
        if ((a % 2) && a >= 30) {
            w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + a] = PHANTGFX_DAT_DEC46_0_BMP + (b * 3);
        }
    }

    for (i = 480; i < 509; i += 2) {
        w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + i] = PHANTGFX_DAT_DEC43_0_BMP;
    }
    for (i = 480; i < 508; i += 2) {
        w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + i + 31] = PHANTGFX_DAT_DEC43_0_BMP;
    }
    w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + 510] = PHANTGFX_DAT_DEC45_0_BMP;
    w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + 539] = PHANTGFX_DAT_DEC44_0_BMP;

    for (i = 0; i < 15; i++) {
        a = (rand() % 59) + 480;
        b = rand() % 2;
        if (!(a % 2) && a < 510) {
            w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + a] = PHANTGFX_DAT_DEC46_0_BMP + (b * 3);
        }
        if ((a % 2) && a >= 510) {
            w->decdata[(ed->actroom * ed->xtiles * ed->ytiles) + a] = PHANTGFX_DAT_DEC46_0_BMP + (b * 3);
        }
    }
}


void ph_set_enemy(EDITOR *ed) {
    FILE *f;
    char buf[512];
    char up = 0;
    char right = 0;

    if (ed->x1capt == ed->x2capt) up = 1;
    if (ed->y1capt == ed->y2capt) right = 1;
    f = fopen("enemies.txt", "at+");
    memset(buf, 0, sizeof(char) * 512);
    fprintf(f, "if room==%d then\n", ed->actroom);
    fprintf(f, "\tcreate_enemy(ene,gfx,data,%d,%d,%d,%d,%d,%d,%d,0,0,1,%d,%d,4,0,1);\n", (ed->selenemy >> 2) + 1,
            ed->x1capt + -20, ed->y1capt + -20, ed->x1capt + -20, ed->x2capt + -20, ed->y1capt + -20, ed->y2capt + -20,
            right, up);
    fprintf(f, "end\n");
    fclose(f);
    ed->enemymode = 0;
}
