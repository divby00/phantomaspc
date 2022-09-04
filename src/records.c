#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "records.h"
#include "trans.h"
#include "control.h"

RECORDS *ph_init_records(void) {
    RECORDS *aux;
    int i;

    aux = (struct RECORDS *) malloc(sizeof(struct RECORDS));
    if (aux == NULL)
        ph_log_memory_error((char *) "records.c", (char *) "ph_init_records", (char *) "aux", sizeof(struct RECORDS));
    memset(aux, 0, sizeof(struct RECORDS));

    aux->aux = (char *) malloc(sizeof(char) * 10);
    memset(aux->aux, 0, sizeof(char) * 10);

    aux->buf = (char *) malloc(sizeof(char) * 10);
    memset(aux->buf, 0, sizeof(char) * 10);

    for (i = 0; i < MAXRECS; i++) {
        aux->r[i] = (struct RECORD *) malloc(sizeof(struct RECORD));
        if (aux->r[i] == NULL)
            ph_log_memory_error((char *) "records.c", (char *) "ph_init_records", (char *) "aux->r",
                                sizeof(struct RECORD));
        memset(aux->r[i], 0, sizeof(struct RECORD));
    }
    ph_load_record_table(aux);
    return aux;
}


void ph_destroy_records(RECORDS *rec) {
    int i;

    for (i = 0; i < MAXRECS; i++)
        free(rec->r[i]);
    free(rec->aux);
    free(rec);
}


void ph_set_records_default(RECORDS *rec) {
    int i;

    for (i = 0; i < MAXRECS; i++) {
        strcpy(rec->r[i]->name, ph_fix_name(rec, (char *) "PHANTOMAS"));
        rec->r[i]->points = (100 - (i * 5)) * 10;
    }
}


void ph_input_new_record(RECORDS *rec, char name[10], signed short int points) {
    int i = 0;
    int pos = 0;

    /* Si es menor que todas las puntuaciones volver */
    if (points < rec->r[MAXRECS - 1]->points) return;

    /* Buscar posicion del record */
    for (i = 0; i < MAXRECS; i++) {
        if (points >= rec->r[i]->points) {
            break;
        }
        pos++;
    }

    /* Mover records */
    for (i = MAXRECS - 2; i >= pos; i--) {
        strcpy(rec->r[i + 1]->name, rec->r[i]->name);
        rec->r[i + 1]->points = rec->r[i]->points;
    }
    strcpy(rec->r[pos]->name, name);
    rec->r[pos]->points = points;
}


char *ph_fix_name(RECORDS *rec, char *name) {
    unsigned int i = 0;

    memset(rec->aux, 0, sizeof(char) * 10);

    do {
        rec->aux[i] = name[i];
        i++;
        if (i == 9) break;
    } while (i < strlen(name));

    while (i < 9) {
        rec->aux[i] = ' ';
        i++;
    }
    rec->aux[9] = '\0';
    return rec->aux;
}


void ph_save_record_table(RECORDS *rec) {
    FILE *f;
    int i;

    f = fopen(RECORDFILE, "wb");
    if (f != NULL) {
        for (i = 0; i < MAXRECS; i++) {
            fwrite(rec->r[i]->name, sizeof(char) * 10, 1, f);
            fwrite(&rec->r[i]->points, sizeof(signed short int), 1, f);
        }
        fclose(f);
    } else {
        ph_log(_("Error: Can't write the records file: %s.\n"), RECORDFILE);
    }
}


void ph_load_record_table(RECORDS *rec) {
    FILE *f;
    int i;

    f = fopen(RECORDFILE, "rt");
    if (f == NULL) {
        ph_set_records_default(rec);
    } else {
        for (i = 0; i < MAXRECS; i++) {
            int read_status_1 = fread(rec->r[i]->name, sizeof(char) * 10, 1, f);
            int read_status_2 = fread(&rec->r[i]->points, sizeof(signed short int), 1, f);
            (void)read_status_1;
            (void)read_status_2;
        }
        fclose(f);
    }
}


void ph_draw_record_table(RECORDS *rec, GFX *gfx, CFG *cfg, TIMER *t, PHFONT *pfnt) {
    int salir = 0;
    int i;
    int show = 50;

    while (1) {
        if (cfg->controltype == CTRL_TYPE_KEYBOARD) {
            poll_keyboard();
            if (key[KEY_ENTER] && !show) salir = 1;
            if (key[KEY_D]) {
                ph_set_records_default(rec);
                ph_save_record_table(rec);
            }
        } else {
            poll_joystick();
            if (joy[0].button[3].b && !show) salir = 1;
            if (joy[0].button[1].b) {
                ph_set_records_default(rec);
                ph_save_record_table(rec);
            }
        }
        while (t->target_cycle > t->acycle) {
            if (show) show--;
            t->acycle++;
        }

        draw_sprite(gfx->virt[0], gfx->tr2x, 0, 0);
        textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 320 >> 1, 30, makecol(200, 200, 200), -1, "%s",
                             _("The best players"));
#ifndef GP2X
        if (!show)
            textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 320 >> 1, 204, makecol(100, 100, 100), -1, "%s",
                                 _("Press Enter to continue..."));
#else
        if (!show) textprintf_centre_ex(gfx->virt[0],pfnt->ufnt,320>>1,204,makecol(100,100,100),-1,"%s",_("Press A to continue..."));
#endif
        for (i = 0; i < MAXRECS; i++) {
            textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 133, (15 * i) + 50,
                                 makecol(00, 200 - (i * 15), 200 - (i * 15)), -1, "%s", rec->r[i]->name);
            textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 200, (15 * i) + 50,
                                 makecol(200 - (i * 15), 200 - (i * 15), 200 - (i * 15)), -1, "%d", rec->r[i]->points);
        }
        ph_draw(gfx, cfg);
        if (salir) break;
    }
}


void ph_draw_input_table(RECORDS *rec, GFX *gfx, CFG *cfg, TIMER *t, PHFONT *pfnt, SFX *sfx) {
    const char *glyph[31] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                             "S", "T", "U", "V", "W", "X", "Y", "Z", "-", ".", "DEL", "END"};

    int cursorx = 35;
    int cursory = 100;
    int i, a = 0;
    int pos = 0;
    char *selchar;
    int canim = 0;
    int enter_active = 10;
    int del_active = 10;
    char salir = 0;
    char temp = 0;

    selchar = (char *) malloc(sizeof(char) * 4);
    memset(selchar, 0, sizeof(char) * 4);
    memset(rec->buf, 0, sizeof(char) * 10);
    t->target_cycle = t->acycle = 0;

    while (1) {
        while (t->target_cycle > t->acycle) {
            if (cfg->controltype == CTRL_TYPE_KEYBOARD) {
                clear_keybuf();

                poll_keyboard();
                if (key[KEY_RIGHT] && cursorx < 240 && !temp) {
                    temp = 2;
                    cursorx += 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                if (key[KEY_LEFT] && cursorx > 50 && !temp) {
                    temp = 2;
                    cursorx -= 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                if (key[KEY_UP] && cursory > 100 && !temp) {
                    temp = 2;
                    cursory -= 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                if (key[KEY_DOWN] && cursory < 150 && !temp) {
                    temp = 2;
                    cursory += 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                memset(selchar, 0, sizeof(char) * 4);
                strcpy(selchar, glyph[((cursorx - 35) / 25) + (((cursory - 100) / 25) * 10)]);

                if (key[KEY_BACKSPACE] && pos == 1 && !del_active) {
                    rec->buf[0] = '\0';
                    pos = 0;
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }

                if (key[KEY_BACKSPACE] && pos > 1 && !del_active) {
                    rec->buf[pos - 1] = '\0';
                    pos--;
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }

                if (key[KEY_ENTER] && cursorx == 260 && cursory == 150) {
                    ph_play_sample(sfx->clock, cursorx, cfg);
                    ph_input_new_record(rec, ph_fix_name(rec, rec->buf), rec->points);
                    enter_active = 10;
                    salir = 1;
                }

                if (cursorx == 235 && cursory == 150) {
                } else if (key[KEY_ENTER] && pos < 9 && !enter_active) {
                    rec->buf[pos] = *selchar;
                    pos++;
                    enter_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }

                if (key[KEY_ENTER] && cursorx == 235 && cursory == 150 && pos == 1 && !del_active) {
                    ph_play_sample(sfx->clock, cursorx, cfg);
                    rec->buf[0] = '\0';
                    pos = 0;
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }

                if (key[KEY_ENTER] && cursorx == 235 && cursory == 150 && pos > 1 && !del_active) {
                    rec->buf[pos - 1] = '\0';
                    pos--;
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }
            } else {
                poll_joystick();
                if (joy[0].stick[0].axis[0].d2 && cursorx < 240) {
                    cursorx += 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                if (joy[0].stick[0].axis[0].d1 && cursorx > 50) {
                    cursorx -= 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                if (joy[0].stick[0].axis[1].d1 && cursory > 100) {
                    cursory -= 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                if (joy[0].stick[0].axis[1].d2 && cursory < 150) {
                    cursory += 25;
                    ph_play_sample(sfx->click, cursorx, cfg);
                    enter_active = 0;
                    del_active = 0;
                }
                memset(selchar, 0, sizeof(char) * 4);
                strcpy(selchar, glyph[((cursorx - 35) / 25) + (((cursory - 100) / 25) * 10)]);

                if (joy[0].button[1].b && pos == 1 && !del_active) {
                    rec->buf[0] = '\0';
                    pos = 0;
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }

                if (joy[0].button[1].b && pos > 1 && !del_active) {
                    rec->buf[pos - 1] = '\0';
                    pos--;
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                }

                if (joy[0].button[0].b && cursorx == 260 && cursory == 150) {
                    ph_play_sample(sfx->clock, cursorx, cfg);
                    ph_input_new_record(rec, ph_fix_name(rec, rec->buf), rec->points);
                    enter_active = 10;
                    salir = 1;
                }

                if (joy[0].button[0].b && cursorx == 235 && cursory == 150) {
                    ph_play_sample(sfx->clock, cursorx, cfg);
                    if (pos >= 1) {
                        rec->buf[pos - 1] = '\0';
                        pos--;
                    } else {
                        rec->buf[0] = '\0';
                        pos = 0;
                    }
                    del_active = 10;
                    ph_play_sample(sfx->clock, cursorx, cfg);
                } else {
                    if (joy[0].button[0].b && pos < 9 && !enter_active) {
                        rec->buf[pos] = *selchar;
                        pos++;
                        enter_active = 10;
                        ph_play_sample(sfx->clock, cursorx, cfg);
                    }
                }
            }

            if (temp) temp--;
            if (enter_active) enter_active--;
            if (del_active) del_active--;
            canim ^= 1;
            t->acycle++;
        }

        draw_sprite(gfx->virt[0], gfx->tr2x, 0, 0);
        if (canim)
            rect(gfx->virt[0], cursorx, cursory, cursorx + 20, cursory + 20, makecol(0, 200, 200));
        else
            rect(gfx->virt[0], cursorx + 1, cursory + 1, cursorx + 19, cursory + 19, makecol(0, 100, 100));
        set_trans_blender(60, 60, 60, 60);

        drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
        if (canim)
            rectfill(gfx->virt[0], cursorx + 1, cursory + 1, cursorx + 19, cursory + 19, makecol(0, 200, 200));
        else
            rectfill(gfx->virt[0], cursorx + 2, cursory + 2, cursorx + 18, cursory + 18, makecol(0, 200, 200));
        drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);

        for (a = 0; a < 3; a++) {
            for (i = 0; i < 10; i++) {
                textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, (i * 25) + 71 - 25, (a * 25) + 105, makecol(0, 0, 0), -1,
                                     "%s", glyph[i + (a * 10)]);
            }
            for (i = 0; i < 10; i++) {
                textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, (i * 25) + 70 - 25, (a * 25) + 105,
                                     makecol(200, 200, 200), -1, "%s", glyph[i + (a * 10)]);
            }
        }

        textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, (320 >> 1), 78, makecol(0, 200, 200), -1, "%s", rec->buf);
        textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 320 >> 1, 40, makecol(200, 200, 200), -1, "%s",
                             _("You have got a high score!!"));
        textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 320 >> 1, 55, makecol(200, 200, 200), -1, "%s",
                             _("Input your name"));
        textprintf_centre_ex(gfx->virt[0], pfnt->ufnt, 320 >> 1, 204, makecol(100, 100, 100), -1, "%s",
                             _("Select END when finished"));

        //stretch_blit(gfx->virt[0],screen,0,0,320,240,0,0,cfg->stretchx,cfg->stretchy);
        ph_draw(gfx, cfg);
        if (salir) break;
    }
    free(selchar);
}
