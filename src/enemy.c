/*
	enemy.c
	Author: Traperic <traperic@gmail.com>
*/

#include "enemy.h"
#include "phantom1.h"
#include "trans.h"
#include "ppcd.h"
#include <math.h>

ENEMY *ph_init_enemies(void) {
    ENEMY *aux;
    AUXENE *auxene;

    ph_log(_("- Initiating enemies: "));
    aux = (struct ENEMY *) malloc(sizeof(struct ENEMY));
    if (aux == NULL) {
        ph_log_memory_error((char *) "enemy.c", (char *) "ph_init_enemies", (char *) "aux", sizeof(struct ENEMY));
    }
    memset(aux, 0, sizeof(struct ENEMY));
    auxene = (struct AUXENE *) malloc(sizeof(struct AUXENE));
    if (auxene == NULL) {
        ph_log_memory_error((char *) "enemy.c", (char *) "ph_init_enemies", (char *) "auxene", sizeof(struct AUXENE));
    }
    memset(auxene, 0, sizeof(struct AUXENE));
    ph_log(_("Ok.\n"));
    aux->auxene = auxene;
    return aux;
}


void ph_destroy_enemies(ENEMY *ene) {
    free(ene->auxene);
    free(ene);
}


void ph_create_enemy(ENEMY *enemy, GFX *gfx, DATA *data) {
    int a;
    char move_types[ENEMY_NUMBER];

    memset(move_types, EMOVE_NORMAL, sizeof(char) * ENEMY_NUMBER);
    move_types[3] = EMOVE_RIGHT;
    move_types[16] = EMOVE_RIGHT;
    move_types[19] = EMOVE_RIGHT;
    move_types[20] = EMOVE_RIGHT;
    move_types[28] = EMOVE_RIGHT;
    move_types[32] = EMOVE_RIGHT;
    move_types[11] = EMOVE_NONE;
    move_types[14] = EMOVE_NONE;
    move_types[15] = EMOVE_NONE;
    move_types[21] = EMOVE_NONE;
    move_types[23] = EMOVE_NONE;
    move_types[26] = EMOVE_NONE;
    move_types[16] = EMOVE_UP;
    enemy->power[(int) enemy->actenemy] = enemy->auxene->power;
    enemy->framespeed[(int) enemy->actenemy] = enemy->auxene->anirate;
    enemy->actframe[(int) enemy->actenemy] = enemy->auxene->aniframe;
    enemy->active[(int) enemy->actenemy] = 1;
    enemy->y1limit[(int) enemy->actenemy] = enemy->auxene->ylimitu;
    enemy->y2limit[(int) enemy->actenemy] = enemy->auxene->ylimitd;
    enemy->xspeed[(int) enemy->actenemy] = enemy->auxene->xspeed;
    enemy->yspeed[(int) enemy->actenemy] = enemy->auxene->yspeed;
    enemy->type[(int) enemy->actenemy] = enemy->auxene->type;
    enemy->up[(int) enemy->actenemy] = 0;
    enemy->right[(int) enemy->actenemy] = enemy->auxene->right;
    enemy->x1limit[(int) enemy->actenemy] = enemy->auxene->xlimitl;
    enemy->x2limit[(int) enemy->actenemy] = enemy->auxene->xlimitr;
    enemy->x[(int) enemy->actenemy] = enemy->auxene->x;
    enemy->y[(int) enemy->actenemy] = enemy->auxene->y;
    enemy->mov_type[(int) enemy->actenemy] = move_types[(int) enemy->type[(int) enemy->actenemy]];

    /* Casos especiales: Enemigo 11, volcanes */
    if (enemy->type[(int) enemy->actenemy] == 11) {
        enemy->active[(int) enemy->actenemy] = 0;
        enemy->init_counter[(int) enemy->actenemy] = enemy->act_counter[(int) enemy->actenemy] = (rand() % 30) + 10;
    }

    for (a = 0; a < 4; a++) {
        gfx->enespr[(int) enemy->actenemy][(int) a] = (BITMAP *) data->dgfx[PHANTGFX_DAT_ENE00_0_0_BMP +
                                                                            ((enemy->type[(int) enemy->actenemy] << 2) +
                                                                             a)].dat;
    }

    enemy->actenemy++;
    if (enemy->actenemy >= MAX_ENEMIES) enemy->actenemy = 0;
}


void ph_move_enemies(ENEMY *enemy, SOUND *snd, CFG *cfg, PLAYER *pl) {
    int i;
    //int aux;
    int a;

    for (i = 0; i < MAX_ENEMIES; i++) {
        if (enemy->type[(int) i] == 11) {
            if (enemy->act_counter[(int) i] && !enemy->active[(int) i]) {
                enemy->act_counter[(int) i]--;
            }
            if (!enemy->act_counter[(int) i] && !enemy->active[(int) i]) {
                enemy->active[(int) i] = 1;
                a = rand() % 2;
                if (a)
                    ph_play_sample(snd->sfx->smoke1, enemy->x[(int) i], cfg);
                else
                    ph_play_sample(snd->sfx->smoke2, enemy->x[(int) i], cfg);
            }
            if (!enemy->act_counter[(int) i] && enemy->active[(int) i]) {
                enemy->act_counter[(int) i] = enemy->init_counter[(int) i];
            }
            if (enemy->act_counter[(int) i] && enemy->active[(int) i]) {
                enemy->act_counter[(int) i]--;
            }
            if (!enemy->act_counter[(int) i] && enemy->active[(int) i]) {
                enemy->act_counter[(int) i] = enemy->init_counter[(int) i];
                enemy->active[(int) i] = 0;
            }
        }
        if (enemy->active[(int) i]) {
            //aux=enemy->actenemy;
            enemy->actframe[(int) i]++;
            if (enemy->actframe[(int) i] == enemy->framespeed[(int) i] << 2) enemy->actframe[(int) i] = 0;

            if (enemy->mov_type[i] != EMOVE_NONE) {
                if (enemy->x[i] <= enemy->x1limit[i] && !enemy->right[i]) {
                    enemy->right[i] = 1;
                    ph_play_enemy_sfx(snd, cfg, fixtoi(pl->x), fixtoi(pl->y), enemy->type[(int) i],
                                      enemy->x[(int) i], enemy->y[(int) i], pl->just_enter);
                }

                if (enemy->x[i] >= enemy->x2limit[i] && enemy->right[i]) {
                    enemy->right[i] = 0;
                    ph_play_enemy_sfx(snd, cfg, fixtoi(pl->x), fixtoi(pl->y), enemy->type[(int) i],
                                      enemy->x[(int) i], enemy->y[(int) i], pl->just_enter);
                }

                if (enemy->x[i] >= enemy->x1limit[i] && !enemy->right[i]) {
                    enemy->x[i] -= enemy->xspeed[i];
                }

                if (enemy->x[i] <= enemy->x2limit[i] && enemy->right[i]) {
                    enemy->x[i] += enemy->xspeed[i];
                }

                if (enemy->y[i] <= enemy->y1limit[i] && enemy->up[i]) {
                    enemy->up[i] = 0;
                    ph_play_enemy_sfx(snd, cfg, fixtoi(pl->x), fixtoi(pl->y), enemy->type[(int) i],
                                      enemy->x[(int) i], enemy->y[(int) i], pl->just_enter);
                }

                if (enemy->y[i] < enemy->y2limit[i] && !enemy->up[i]) {
                    enemy->y[i] += enemy->yspeed[i];
                }

                if (enemy->y[i] >= enemy->y2limit[i] && !enemy->up[i]) {
                    enemy->up[i] = 1;
                    ph_play_enemy_sfx(snd, cfg, fixtoi(pl->x), fixtoi(pl->y), enemy->type[(int) i],
                                      enemy->x[(int) i], enemy->y[(int) i], pl->just_enter);
                }
                if (enemy->y[i] > enemy->y1limit[i] && enemy->up[i]) {
                    enemy->y[i] -= enemy->yspeed[i];
                }

            }
        }
    }
}


void ph_draw_enemies(ENEMY *enemy, GFX *gfx) {
    int i;

    for (i = 0; i < MAX_ENEMIES; i++) {
        if (enemy->active[(int) i]) {
            if (enemy->mov_type[(int) i] == EMOVE_RIGHT && !enemy->right[(int) i]) {
                draw_sprite_h_flip(gfx->virt[0],
                                   gfx->enespr[(int) i][enemy->actframe[(int) i] / enemy->framespeed[(int) i]],
                                   (enemy->x[(int) i] + X_DESP) / 2, (enemy->y[(int) i] + Y_DESP) / 2);
            } else if (enemy->mov_type[(int) i] == EMOVE_UP && !enemy->up[(int) i]) {
                draw_sprite_h_flip(gfx->virt[0],
                                   gfx->enespr[(int) i][enemy->actframe[(int) i] / enemy->framespeed[(int) i]],
                                   (enemy->x[(int) i] + X_DESP) / 2, (enemy->y[(int) i] + Y_DESP) / 2);
            } else {
                draw_sprite(gfx->virt[0], gfx->enespr[(int) i][enemy->actframe[(int) i] / enemy->framespeed[(int) i]],
                            (enemy->x[(int) i] + X_DESP) / 2, (enemy->y[(int) i] + Y_DESP) / 2);
            }
        }

    }
}


void ph_damage_player(ENEMY *ene, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg) {
    char i;
    BITMAP *aux = NULL;
    BITMAP *aux1 = NULL;

    clear(gfx->phhelper);
    aux1 = gfx->phhelper;

    if (pl->falling) {
        aux = gfx->phspr[5 + fixtoi(pl->aniframe)];
        if (!pl->right) blit(aux, aux, 0, 0, 0, 0, aux->w, aux->h);
    }
    if (pl->jumping) {
        aux = gfx->phspr[4];
        if (!pl->right) blit(aux, aux, 0, 0, 0, 0, aux->w, aux->h);
    }
    if (!pl->jumping && !pl->falling) {
        aux = gfx->phspr[fixtoi(pl->aniframe)];
    }
    if (!pl->right) {
        draw_sprite_h_flip(aux1, aux, 0, 0);
        aux = aux1;
    }

    for (i = 0; i < MAX_ENEMIES; i++) {
        if (ene->active[(int) i]) {
            if (sn_collision(aux, fixtoi(pl->x), fixtoi(pl->y),
                             gfx->enespr[(int) i][ene->actframe[(int) i] / ene->framespeed[(int) i]], ene->x[(int) i],
                             ene->y[(int) i])) {
                pl->energy -= 2;
                pl->damaging = 1;
                if (cfg->enable_sound && cfg->sfx) ph_play_sample(snd->sfx->hit, fixtoi(pl->x), cfg);
                if (!pl->firsttimehit) pl->firsttimehit = 1;
            }
        }
    }
}


void ph_play_enemy_sfx(SOUND *snd, CFG *cfg, int x, int y, unsigned char ene_type, int enex, int eney,
                       int just_enter) {
    float vol, pan;

    if (!just_enter) return;
    if (!cfg->enable_sound && !cfg->sfx) return;

    if (cfg->surround) {
        enex /= 2;
        eney /= 2;
        x /= 2;
        y /= 2;
        vol = sqrt(pow(abs(x - enex), 2) + pow(abs(y - eney), 2));
        vol = (unsigned char) vol ^ 255;
        vol -= 50;
        vol /= 5;
        vol *= 3;
        vol = (vol * cfg->sfxvolume) / 255;
        pan = ((255 * enex) / 224);
    } else {
        vol = cfg->sfxvolume;
        vol = (vol * 50) / 100;
        pan = 127;
    }

    switch (ene_type) {
        case 1:
            play_sample(snd->sfx->e1, vol, pan, 1000, 0);
            break;
        case 2:
            play_sample(snd->sfx->e2, vol, pan, 1000, 0);
            break;
        case 4:
            play_sample(snd->sfx->e4, vol, pan, 1000, 0);
            break;
        case 5:
            play_sample(snd->sfx->e5, vol, pan, 1000, 0);
            break;
        case 6:
            play_sample(snd->sfx->e6, vol, pan, 1000, 0);
            break;
        case 7:
            play_sample(snd->sfx->e7, vol, pan, 1000, 0);
            break;
        case 8:
            play_sample(snd->sfx->e8, vol, pan, 1000, 0);
            break;
        case 9:
            play_sample(snd->sfx->e9, vol, pan, 1000, 0);
            break;
        case 10:
            play_sample(snd->sfx->e10, vol, pan, 1000, 0);
            break;
        case 12:
            play_sample(snd->sfx->e12, vol, pan, 1000, 0);
            break;
        case 13:
            play_sample(snd->sfx->e13, vol, pan, 1000, 0);
            break;
        case 16:
            play_sample(snd->sfx->e16, vol, pan, 1000, 0);
            break;
        case 19:
            play_sample(snd->sfx->e19, vol, pan, 1000, 0);
            break;
        case 20:
            play_sample(snd->sfx->e20, vol, pan, 1000, 0);
            break;
        case 22:
            play_sample(snd->sfx->e22, vol, pan, 1000, 0);
            break;
        case 24:
            play_sample(snd->sfx->e24, vol, pan, 1000, 0);
            break;
        case 25:
            play_sample(snd->sfx->e24, vol, pan, 1000, 0);
            break;
        case 32:
            play_sample(snd->sfx->e32, vol, pan, 1000, 0);
            break;
        case 35:
            play_sample(snd->sfx->e35, vol, pan, 1000, 0);
            break;
        case 36:
            play_sample(snd->sfx->e35, vol, pan, 1000, 0);
            break;
        case 37:
            play_sample(snd->sfx->e35, vol, pan, 1000, 0);
            break;
        case 39:
            play_sample(snd->sfx->e1, vol, pan, 1000, 0);
            break;
        case 40:
            play_sample(snd->sfx->e1, vol, pan, 1000, 0);
            break;
        case 41:
            play_sample(snd->sfx->e1, vol, pan, 1000, 0);
            break;
    }
}
