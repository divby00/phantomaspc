/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include "config.h"
#include "game.h"
#include "gfx.h"
#include "player.h"
#include "control.h"
#include "control2.h"
#include "world.h"
#include "luaphant.h"
#include "platform.h"
#include "switch.h"
#include "trans.h"
#include "energy.h"
#include "path.h"
#include "back.h"
#include "texter.h"
#include "phantom1.h"
#include "arrows.h"
#include "blockp.h"
#include "fades.h"

void ph_start_game(PROGRAM *p) {
    int res = 0;
    (void) res;
    HAND *hand;
    BLOCK *bl;
    ARROWS *ar;
    TMENU *menu;
    PHFONT *pfont;
    DATA *data;
    ENEMY *ene;
    GFX *gfx;
    CONTROL *c;
    PLAYER *pl;
    CFG *cfg;
    WORLD *w;
    VEHICLE *v;
    PLATFORM *plat;
    SWITCH *sw;
    ENERGY *energy;
    SOUND *sound;
    int i;
    unsigned char show_sfx_vol = 0;
    unsigned char show_mus_vol = 0;
    char done = 0;
    int xj = 0;
    int wi;
    int playerx;
    int playery;
    int platx;
    int platy;
    char event[10];
    char allow_jump = 0;
    char ilife = 0;
    char debug = 0;
    char r = 0;
    unsigned char bc1 = 0;
    unsigned char bc2 = 0;
    unsigned char bc3 = 0;
    static char back7 = 0;
#ifdef CUSTOM_PATH
    char buf[512];
#endif

    event[0] = 0;
    event[1] = 0;
    event[2] = 0;
    event[3] = 0;
    event[4] = 0;
    event[5] = 0;
    event[6] = 0;
    event[7] = 0;
    ar = p->ar;
    v = p->v;
    w = p->w;
    gfx = p->gfx;
    c = p->c;
    ene = p->ene;
    hand = p->hand;
    data = p->data;
    pl = p->pl;
    plat = p->plat;
    cfg = p->cfg;
    bl = p->bl;
    sw = p->sw;
    pfont = p->fnt;
    energy = p->energy;
    sound = p->snd;
    menu = p->menu;
    pl->x = itofix(64);
    pl->right = 1;
    pl->aniframe = 1;
    pl->y = itofix(104);
    pl->speed = 4;
    pl->jumping = 0;
    pl->energy = 238;
    pl->cheats = 0;
    pl->pressed_switches = 0;
    pl->treasure = 0;
    pl->safe = 0;
    pl->heared = 0;
    pl->sp_heared = 0;
    pl->spa_heared = 0;
    w->actroom = 0;
    pl->opendoor = 0;
    p->b->active = 0;
    pl->hide = 0;
    xj = 0;
    pl->finished = 0;
#ifdef GP2X
    p->c->type=CTRL_TYPE_JOYSTICK;
#endif

    set_display_switch_mode(SWITCH_NONE);
    w = ph_load_world_data_alt(w, p->data);

#ifdef CUSTOM_PATH
    memset(buf, 0, 512);                                                                                                                memset(buf,0,512);
    strcpy(buf,"data/world.bin");
    ph_get_path(p->path,buf);
    res=luaL_dofile(p->ls,p->path);
#else
    ph_get_file_name(cfg, (char *) "world.bin");
    res = luaL_dofile(p->ls, cfg->buffer);
	fprintf(stderr,"Lua failed: %s\n",lua_tostring(p->ls, -1));
#endif

    ph_get_room_data(w, w->actroom, pl);
    ph_change_room(p, w->actroom);
    clear_to_color(gfx->virt[0], makecol(0, 0, 0));
    ph_set_text_properties(pfont, makecol(255, 255, 255), -1, TXT_TITLE, TXT_LEFT, 1);
    menu->showmenu = 0;
    p->t->acycle = p->t->target_cycle = p->t->script_target_cycle = 0;

    ph_log(_("- Entering main loop...\n"));

    p->t->acycle = p->t->target_cycle = 0;
    rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, makecol(255, 255, 255));
    ph_fade_image(16, (BITMAP *) data->dgfx[PHANTGFX_DAT_MISCINIT_BMP].dat);
    p->t->acycle = p->t->target_cycle = 0;

    while (1) {
        c = ph_read_control(p, c, menu, pfont);

#ifndef GP2X
        if (cfg->sfx) {
            if (key[KEY_PLUS_PAD] && cfg->sfxvolume < 255) {
                cfg->sfxvolume++;
                show_sfx_vol = 200;
            }
            if (key[KEY_MINUS_PAD] && cfg->sfxvolume > 0) {
                cfg->sfxvolume--;
                show_sfx_vol = 200;
            }
        }
        if (cfg->music) {
            if (key[KEY_PGUP] && cfg->musicvolume < 255) {
                cfg->musicvolume++;
                show_mus_vol = 200;
            }
            if (key[KEY_PGDN] && cfg->musicvolume > 0) {
                cfg->musicvolume--;
                show_mus_vol = 200;
            }
        }
#else
                                                                                                                                if (cfg->sfx) {
			poll_joystick();
			if (joy[0].button[9].b && cfg->sfxvolume<255) {
				cfg->sfxvolume++;
				show_sfx_vol=70;
			}
			if (joy[0].button[8].b && cfg->sfxvolume>0) {
				cfg->sfxvolume--;
				show_sfx_vol=70;
			}
			cfg->musicvolume=cfg->sfxvolume;
		}
#endif
#ifdef GP2X
        poll_joystick();
if (joy[0].button[4].b) {
if (w->actroom<=66) w->actroom++;
ph_change_room(p,w->actroom);
ph_get_room_data(w,w->actroom,pl);
rest(50);
}
if (joy[0].button[5].b) {
if (w->actroom) w->actroom--;
ph_change_room(p,w->actroom);
ph_get_room_data(w,w->actroom,pl);
rest(50);
}
#endif

        if (key[KEY_A] && key[KEY_B] && key[KEY_U]) {
            pl->abu = 1;
        }

        if (key[KEY_E] && key[KEY_N] && key[KEY_T] && key[KEY_H] && pl->cheats) {
            allow_jump = 1;
        }

        if (key[KEY_1] && key[KEY_0] && key[KEY_8] && pl->cheats) {
            ilife = 1;
        }

        if (key[KEY_E] && key[KEY_P] && key[KEY_O] && key[KEY_K]) {
            pl->cheats = 1;
        }

        while (p->t->target_cycle > p->t->acycle) {
            c = ph_read_control_in_ball(p, c);
            pl->damaging = 0;
            pl->onplatform = 0;
            pl->falling = 0;
            /* Menudo follon de codigo para controlar el movimiento correcto de las plataformas de subida y bajada */
            for (i = 0; i < MAXPLATFORMS; i++) {
                if (plat->active[i]) {
                    wi = (int) gfx->plaspr[4 * plat->type[(int) i]]->w * 2;
                    playerx = fixtoi(pl->x);
                    playery = fixtoi(pl->y);
                    platx = fixtoi(plat->x[(int) i]);
                    platy = fixtoi(plat->y[(int) i]);

                    if ((plat->up[(int) i] == 2) && !(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                        (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                        (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4])) {
                        if ((((playerx + 30) >= platx) && (playerx <= (platx + (wi - 2))) && xj >= 9) &&
                            ((playery + 32) == platy || (playery + 33) == platy || (playery + 34) == platy ||
                             (playery + 35) == platy || (playery + 36) == platy || (playery + 37) == platy ||
                             (playery + 38) == platy || (playery + 39) == platy || (playery + 40) == platy ||
                             (playery + 41) == platy || (playery + 42) == platy || (playery + 43) == platy ||
                             (playery + 46) == platy || (playery + 47) == platy || (playery + 44) == platy ||
                             (playery + 45) == platy || (playery + 46) == platy)) {
                            pl->y = fixsub(plat->y[i], itofix(32));
                            pl->onplatform = i + 1;
                            pl->jumping = 0;
                            pl->falling = 0;
                        }
                    }
                    if ((plat->up[(int) i] != 2) && !(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                        (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                        (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4])) {
                        if ((((playerx + 30) >= platx) && (playerx <= (platx + wi) - 2) && xj >= 9) &&
                            ((playery + 32) == platy || (playery + 33) == platy || (playery + 34) == platy ||
                             (playery + 35) == platy || (playery + 36) == platy || (playery + 37) == platy ||
                             (playery + 38) == platy || (playery + 39) == platy || (playery + 40) == platy ||
                             (playery + 41) == platy || (playery + 42) == platy || (playery + 43) == platy ||
                             (playery + 46) == platy || (playery + 47) == platy || (playery + 44) == platy ||
                             (playery + 45) == platy || (playery + 46) == platy)) {
                            pl->y = fixsub(plat->y[i], itofix(32));
                            pl->onplatform = i + 1;
                            pl->jumping = 0;
                            pl->falling = 0;
                        }
                    }
                }
            }

            done = 0;

            /* Si estamos en el limite de abajo entrar en una hab. nueva */
            if (pl->y >= itofix(256) && !done) {
                w->actroom += 8;
                pl->y = itofix((0));
                ph_clean_arrows(ar);
                ph_change_room(p, w->actroom);
                ph_get_room_data(w, w->actroom, pl);
                done = 1;
            }

            /* Si estamos en el limite de arriba entrar en una hab. nueva */
            if (pl->y <= itofix(0) && !done && pl->jumping) {
                w->actroom -= 8;
                pl->y = itofix(256);
                ph_clean_arrows(ar);
                ph_change_room(p, w->actroom);
                ph_get_room_data(w, w->actroom, pl);
                done = 1;
            }

            /* Si no hay suelo y no estamos saltando caer */
            if (!pl->inchopper && !pl->inrocket) {
                if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                    (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                    (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4]) && !pl->jumping &&
                    !pl->onplatform) {
                    pl->falling = 1;
                    pl->y = fixadd(pl->y, itofix(4));
                    if (cfg->enable_sound && cfg->sfx)
                        ph_play_sample_falling(sound->sfx->walk, fixtoi(pl->x), fixtoi(pl->y), cfg);

                }
                if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                    (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                    (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4]) && !pl->jumping &&
                    !pl->onplatform) {
                    pl->falling = 1;
                    pl->y = fixadd(pl->y, itofix(4));
                    pl->aniframe = fixadd(pl->aniframe, itofix(1));
                    if (fixtoi(pl->aniframe) == 4) pl->aniframe = 0;
                }
            }
            if (v->active != 2 || v->active != 3 || v->active != 5 || v->active != 6) {
                /* Salto alto */
                if (c->up && !pl->falling && !pl->jumping && !bl->active && !pl->inchopper && !pl->inrocket) {
                    pl->jumping = 1;
                    xj = 0;
                    if (cfg->enable_sound && cfg->sfx)
                        ph_play_sample(sound->sfx->hjump, fixtoi(pl->x), cfg);
                }

                /* Salto bajo */
                if (c->down && !pl->falling && !pl->jumping && !bl->active && !pl->inchopper && !pl->inrocket) {
                    pl->jumping = 2;
                    xj = 0;
                    if (cfg->enable_sound && cfg->sfx)
                        ph_play_sample(sound->sfx->ljump, fixtoi(pl->x), cfg);
                }
            } else {
                pl->jumping = 0;
            }
            /* Control del salto */
            if (pl->jumping) {
                if (xj < 18) {
                    if (xj < 9) {
                        /* Aumentar si no chocamos contra algo que haya arriba,
						si no volver al modo normal. */
                        if (fixtoi(pl->x) == 448) {
                            pl->y = fixsub(pl->y, itofix(4));
                        } else {
                            if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) - 1) >> 4]) &&
                                (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) - 1) >> 4]) &&
                                (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) - 1) >> 4])) {
                                pl->y = fixsub(pl->y, itofix(4));

                                if (pl->jumping == 1) {
                                    if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) - 1) >> 4]) &&
                                        (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) - 1) >> 4]) &&
                                        (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) - 1) >> 4])) {
                                        pl->y = fixsub(pl->y, itofix(4));
                                    }
                                }
                            }
                        }
                    } else {
                        if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4])) {
                            pl->y = fixadd(pl->y, itofix(4));

                            if (pl->jumping == 1) {
                                if (!(w->cross[(fixtoi(pl->x)) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                                    (!w->cross[(fixtoi(pl->x) + 15) >> 4][(fixtoi(pl->y) + 32) >> 4]) &&
                                    (!w->cross[(fixtoi(pl->x) + 31) >> 4][(fixtoi(pl->y) + 32) >> 4]))
                                    pl->y = fixadd(pl->y, itofix(4));
                            }
                        } else {
                            pl->jumping = 0;
                        }
                    }

                    if (pl->right) {
                        if (fixtoi(pl->x) == 448) {
                            pl->x = fixadd(pl->x, itofix(4));
                            if (pl->jumping == 2) pl->x = fixadd(pl->x, itofix(4));
                            w->actroom++;
                            ph_clean_arrows(ar);
                            ph_change_room(p, w->actroom);
                            ph_get_room_data(w, w->actroom, pl);
                            pl->x = itofix(0);
                        }
                        if (!(w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 1) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 15) >> 4])) {
                            pl->x = fixadd(pl->x, itofix(4));
                            if (pl->jumping == 2) {
                                if (!(w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                                    (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 1) >> 4]) &&
                                    (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 15) >> 4]))
                                    pl->x = fixadd(pl->x, itofix(4));
                            }

                            if (fixtoi(pl->x) >= 448) {
                                w->actroom++;
                                ph_clean_arrows(ar);
                                ph_change_room(p, w->actroom);
                                ph_get_room_data(w, w->actroom, pl);
                                pl->x = itofix(0);
                            }
                        }
                    } else {
                        if (!(w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 1) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 15) >> 4])) {
                            pl->x = fixsub(pl->x, itofix(4));

                            if (pl->jumping == 2) {
                                if (!(w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                                    (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 1) >> 4]) &&
                                    (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 15) >> 4]))
                                    pl->x = fixsub(pl->x, itofix(4));
                            }
                        }
                        if (fixtoi(pl->x) <= 0) {
                            w->actroom--;
                            ph_clean_arrows(ar);
                            ph_change_room(p, w->actroom);
                            ph_get_room_data(w, w->actroom, pl);
                            pl->x = itofix(448);
                        }
                    }
                    xj++;
                } else {
                    pl->jumping = 0;
                }
            }

            /* Si se permite el salto controlado */
            if (allow_jump) {
                if ((c->left && pl->jumping) || (c->left && pl->falling)) pl->right = 0;
                if ((c->right && pl->jumping) || (c->right && pl->falling)) pl->right = 1;
            }

            /* Si pulsamos izquierda */
            if (c->left && !pl->falling && !pl->jumping && !pl->inrocket && !pl->inchopper) {
                if (cfg->enable_sound && cfg->sfx) {
                    ph_play_sample(sound->sfx->walk, fixtoi(pl->x), cfg);
                }
                if (pl->right) {
                    pl->right = 0;
                    pl->aniframe = 1;
                } else {

                    if (fixtoi(pl->x) == 0) {
                        w->actroom--;
                        ph_clean_arrows(ar);
                        ph_change_room(p, w->actroom);
                        ph_get_room_data(w, w->actroom, pl);
                        pl->x = itofix(448);
                    } else {
                        /* Si no nos chocamos avanzar */
                        if (!(w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 1) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) - 1) >> 4][(fixtoi(pl->y) + 15) >> 4])) {
                            pl->x = fixsub(pl->x, itofix(pl->speed));
                        }
                    }

                    pl->aniframe = fixadd(pl->aniframe, itofix(1));
                    if (fixtoi(pl->aniframe) == 4) pl->aniframe = itofix(0);
                }
            }

            /* Si pulsamos derecha */
            if (c->right && !pl->falling && !pl->jumping && !pl->inrocket && !pl->inchopper) {
                if (cfg->enable_sound && cfg->sfx) {
                    ph_play_sample(sound->sfx->walk, fixtoi(pl->x), cfg);
                }
                if (!pl->right) {
                    pl->right = 1;
                    pl->aniframe = 1;
                } else {
                    /* Cambiar de pantalla */
                    if (fixtoi(pl->x) >= 448) {
                        w->actroom++;
                        ph_clean_arrows(ar);
                        ph_change_room(p, w->actroom);
                        ph_get_room_data(w, w->actroom, pl);
                        pl->x = itofix(0);
                    } else {
                        /* Si no nos chocamos avanzar */
                        if (!(w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 31) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 1) >> 4]) &&
                            (!w->cross[(fixtoi(pl->x) + 32) >> 4][(fixtoi(pl->y) + 15) >> 4])) {
                            pl->x = fixadd(pl->x, ftofix(4));
                        }
                    }

                    /* Cambiar animacion */
                    pl->aniframe = fixadd(pl->aniframe, ftofix(1));
                    if (fixtoi(pl->aniframe) == 4) pl->aniframe = itofix(0);
                }
            }

            ph_set_vehicles_data(p->v, p->w, pl);
            ph_move_ball(p->b);
            ph_move_back_image(p->w);
            ph_move_vehicles(p->v, p->pl, p->snd, p->cfg);
            ph_move_enemies(ene, p->snd, p->cfg, p->pl);

            if (w->actroom == 64 && fixtoi(pl->x) == 96 && p->b->active != 3) {
                p->b->active = 1;
            }

            if (w->actroom == 64 && fixtoi(pl->x) >= 248 && p->b->active == 1 && event[7] == 2 && event[6] == 2) {
                ph_do_speccy(p);
                p->b->active = 2;
                p->pl->inball = 1;
                p->pl->ballspeed = 248;
                p->t->acycle = p->t->target_cycle = 0;
                w->actroom = 67;
                ph_change_room(p, w->actroom);
                ph_get_room_data(w, w->actroom, pl);
            }

            if (w->actroom == 56 && pl->explotedoor == 1) {
                pl->explotedoor = 2;
                ph_get_room_data(w, w->actroom, pl);
            }

            if (w->actroom == 7) {
                pl->opendoor = 1;
                back7++;
                if (back7 == 8) back7 = 0;
                switch (back7) {
                    case 0:
                        bc1 = 0;
                        bc2 = 0;
                        bc3 = 0;
                        break;
                    case 1:
                        bc1 = 0;
                        bc2 = 0;
                        bc3 = 192;
                        break;
                    case 2:
                        bc1 = 192;
                        bc2 = 0;
                        bc3 = 0;
                        break;
                    case 3:
                        bc1 = 0;
                        bc2 = 192;
                        bc3 = 0;
                        break;
                    case 4:
                        bc1 = 192;
                        bc2 = 0;
                        bc3 = 192;
                        break;
                    case 5:
                        bc1 = 0;
                        bc2 = 192;
                        bc3 = 192;
                        break;
                    case 6:
                        bc1 = 192;
                        bc2 = 192;
                        bc3 = 0;
                        break;
                    case 7:
                        bc1 = 192;
                        bc2 = 192;
                        bc3 = 192;
                        break;
                }
            }

            if (w->actroom == 56 && !pl->treasure) {
                if (fixtoi(pl->x) >= 32 && fixtoi(pl->x) <= 60 && fixtoi(pl->y) <= 64 && fixtoi(pl->y) > 32) {
                    pl->treasure = 1;
                    ph_get_room_data(w, w->actroom, pl);
                    ph_play_sample(sound->sfx->treasure, 0, cfg);
                }
            }
            if (w->actroom == 56 && pl->treasure) {
                ph_move_hand(hand, pl);
                ph_exp_damage_player(hand, pl, gfx, sound, cfg, data);
            }
            if (w->actroom == 60) {
                ph_throw_arrows(ar, pl);
                ph_arrows_damage_player(ar, pl, gfx, sound, cfg, data);
                ph_move_arrows(ar);
            }
            if (w->actroom == 61) {
                ph_throw_block(bl, pl);
                ph_move_block(bl, pl);
            }
            if (w->actroom == 67) {
                ph_move_ball(p->b);
            }
            ph_move_platforms(plat, pl, w);
            ph_get_energy(energy, pl, gfx, sound, cfg);
            if (!ilife) ph_damage_player(ene, pl, gfx, sound, cfg);
            ph_push_switch(sw, pl, gfx, sound, cfg, w);
            if (ph_special_cases(p)) xj = 0;
            p->t->acycle++;

            /* Mirar eventos */
            if (p->t->acycle == 16 && !event[0]) event[0] = 1;
            if (pl->firsttimehit == 1) {
                event[1] = 1;
                pl->firsttimehit = 2;
            }
            if (pl->firsttimeenergy == 1) {
                event[2] = 1;
                pl->firsttimeenergy = 2;
            }
            if (pl->firsttimeswitch == 1) {
                event[3] = 1;
                pl->firsttimeswitch = 2;
            }
            if (pl->pressed_switches == SWITCHES_TO_OPEN_SAFE && !event[4]) {
                event[4] = 1;
                /* Sonido de alarma desactivada */
            }
            if (pl->pressed_switches >= SWITCHES_TO_OPEN_SAFE && !event[5] && w->actroom == 16 && fixtoi(pl->x) == 32 &&
                fixtoi(pl->y) == 64) {
                event[5] = 1;
                pl->safe = 1;
                ph_play_sample(sound->sfx->treasure, 0, cfg);
            }
            if (!event[6] && w->actroom == 64 && fixtoi(pl->x) >= 96 && fixtoi(pl->x) <= 120 && fixtoi(pl->y) <= 176) {
                //				if (!event[6] && w->actroom==64 && fixtoi(pl->x)>=96)
                event[6] = 1;
            }
            if (!event[7] && w->actroom == 64 && fixtoi(pl->x) >= 244 && event[6]) {
                event[7] = 1;
                pl->x = itofix(248);
                pl->y = itofix(224);
                ph_play_sample(sound->sfx->ball, 320 >> 1, cfg);
            }
            rest(1);
        }

        if (w->actroom == 67 && p->pl->inball && fixtoi(p->pl->x) <= 110) {
            p->pl->energy = 0;
        }

        if (w->actroom == 67 && p->pl->inball && fixtoi(p->pl->x) >= 440) {
            w->actroom = 65;
            pl->x = itofix(0);
            pl->inball = 0;
            p->b->active = 3;
            ph_change_room(p, p->w->actroom);
            ph_get_room_data(p->w, p->w->actroom, pl);
        }

        /* Limpiar buffer */
        clear(gfx->virt[0]);
        //		draw_sprite(p->gfx->virt[0],(BITMAP *)p->data->dgfx[PHANTGFX_DAT_MISCTR2X_BMP].dat,0,0);

        /* Dibujar fondo especial */
        if (w->actroom == 7) {
            rectfill(gfx->virt[0], 0 + X_DESP / 2, 0 + Y_DESP / 2, (479 + X_DESP) / 2, (287 + Y_DESP) / 2,
                     makecol(bc1, bc2, bc3));
        }

        ph_draw_dec(p);
        if (w->actroom == 2 || w->actroom == 5 || w->actroom == 65 || w->actroom == 66)
            ph_draw_vehicles(p->v, data, gfx, w->actroom);
        if (w->actroom == 5 && p->v->type == 1) {
            p->v->type = 2;
            p->v->x = 176;
            p->v->y = 112;
        }
        if (w->actroom == 2 && p->v->type == 2) {
            p->v->x = 192;
            p->v->y = 112;
            p->v->type = 1;
        }

        ph_draw_platforms(plat, gfx);
        ph_draw_enemies(ene, gfx);

        if (p->v->ractive == 3 && w->actroom == 5) {
            w->actroom = 66;
            ph_change_room(p, p->w->actroom);
            ph_get_room_data(p->w, p->w->actroom, pl);
        }
        if (p->v->ractive == 5 && w->actroom == 66) {
            w->actroom = 5;
            ph_change_room(p, p->w->actroom);
            ph_get_room_data(p->w, p->w->actroom, pl);
        }
        if (p->v->active == 3 && w->actroom == 2) {
            w->actroom = 65;
            ph_change_room(p, p->w->actroom);
            ph_get_room_data(p->w, p->w->actroom, pl);
        }
        if (p->v->active == 6 && w->actroom == 65) {
            w->actroom = 2;
            ph_change_room(p, p->w->actroom);
            ph_get_room_data(p->w, p->w->actroom, pl);
        }

        if (w->actroom == 31 && pl->safe && pl->treasure) {
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC58_0_BMP].dat, (272 + X_DESP) / 2,
                        (192 + Y_DESP) / 2);
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC57_0_BMP].dat, (200 + X_DESP) / 2,
                        (192 + Y_DESP) / 2);
            /*			pl->x=itofix(32);
						pl->y=itofix(224);*/
        }

        if (w->actroom == 31 && pl->safe && pl->treasure && pl->x == itofix(32) && pl->y == itofix(224)) {
            pl->end = 1;
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC58_0_BMP].dat, (272 + X_DESP) / 2,
                        (192 + Y_DESP) / 2);
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC57_0_BMP].dat, (200 + X_DESP) / 2,
                        (192 + Y_DESP) / 2);
            pl->x = itofix(32);
            pl->y = itofix(224);
        }

        if (w->actroom == 16 && !pl->safe)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC22_0_BMP].dat, (0 + X_DESP) / 2,
                        (64 + Y_DESP) / 2);
        if (w->actroom == 56 && !pl->treasure)
            draw_sprite(gfx->virt[0], (BITMAP *) data->dgfx[PHANTGFX_DAT_DEC79_0_BMP].dat, (32 + X_DESP) / 2,
                        (64 + Y_DESP) / 2);
        if (w->actroom == 56 && pl->treasure) ph_draw_hand(hand, gfx, data, cfg, sound);
        if (w->actroom == 60) ph_draw_arrows(ar, data, gfx);
        if (w->actroom == 61) ph_draw_block(bl, gfx, data);
        if (w->actroom == 67) ph_draw_ball(p->b, gfx, data);

        ph_draw_energy(energy, gfx);
        ph_draw_switch(sw, gfx);

        /* Game over */

        if (pl->energy <= 0) {
            for (i = 0; i < 10; i++) {
                event[i] = 0;
            }
            pl->energy = 0;
            pl->finished = 0;
            pl->destroyed = 1;
            p = ph_game_over(p);
            p->pl->y = itofix(104);
            p->t->acycle = p->t->target_cycle = 0;
        }

        if (p->pl->restart) {
            ph_start_game(p);
            p->pl->y = itofix(80 + 16);
            p->t->acycle = p->t->target_cycle = 0;
        }
        /* Dibujar el sprite de Phantomas si no esta destruido */
        if (!pl->hide) {
            if (!pl->destroyed || !pl->restart) {
                if (w->actroom == 7) {
                    r = rand() % 7;
                    if (pl->right) {
                        if (pl->falling)
                            draw_sprite(gfx->virt[0], gfx->phspr[(50 + fixtoi(pl->aniframe)) + (9 * r)],
                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                        if (pl->jumping)
                            draw_sprite(gfx->virt[0], gfx->phspr[49 + (9 * r)], (fixtoi(pl->x) + X_DESP) / 2,
                                        (fixtoi(pl->y) + Y_DESP) / 2);
                        if (!pl->falling && !pl->jumping)
                            draw_sprite(gfx->virt[0], gfx->phspr[(45 + fixtoi(pl->aniframe)) + (9 * r)],
                                        ((fixtoi(pl->x) + X_DESP) / 2), (fixtoi(pl->y) + Y_DESP) / 2);
                    } else {
                        if (pl->falling)
                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[(50 + fixtoi(pl->aniframe)) + (9 * r)],
                                               (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                        if (pl->jumping)
                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[49 + (9 * r)], (fixtoi(pl->x) + X_DESP) / 2,
                                               (fixtoi(pl->y) + Y_DESP) / 2);
                        if (!pl->falling && !pl->jumping)
                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[(45 + fixtoi(pl->aniframe)) + (9 * r)],
                                               (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                    }
                } else {
                    if (!pl->inchopper && !pl->inrocket) {
                        if (pl->right) {
                            if (!pl->astro) {
                                if (!pl->abu) {
                                    if (!pl->damaging) {
                                        if (pl->falling)
                                            draw_sprite(gfx->virt[0], gfx->phspr[5 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[4], (fixtoi(pl->x) + X_DESP) / 2,
                                                        (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[0 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                    } else {
                                        if (pl->falling)
                                            draw_sprite(gfx->virt[0], gfx->phspr[32 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[31], (fixtoi(pl->x) + X_DESP) / 2,
                                                        (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[27 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                    }
                                } else {
                                    if (!pl->damaging) {
                                        // No salto
                                        if (pl->falling)
                                            draw_sprite(gfx->virt[0], gfx->phspr[23 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[22], (fixtoi(pl->x) + X_DESP) / 2,
                                                        (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[18 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                    } else {
                                        if (pl->falling)
                                            draw_sprite(gfx->virt[0], gfx->phspr[41 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[40], (fixtoi(pl->x) + X_DESP) / 2,
                                                        (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite(gfx->virt[0], gfx->phspr[36 + fixtoi(pl->aniframe)],
                                                        (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                    }
                                }
                            } else {
                                if (pl->falling)
                                    draw_sprite(gfx->virt[0], gfx->phspr[14 + fixtoi(pl->aniframe)],
                                                (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                if (pl->jumping)
                                    draw_sprite(gfx->virt[0], gfx->phspr[13], (fixtoi(pl->x) + X_DESP) / 2,
                                                (fixtoi(pl->y) + Y_DESP) / 2);
                                if (!pl->falling && !pl->jumping)
                                    draw_sprite(gfx->virt[0], gfx->phspr[9 + fixtoi(pl->aniframe)],
                                                (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                            }
                        } else {
                            if (!pl->astro) {
                                if (!pl->abu) {
                                    if (!pl->damaging) {
                                        if (pl->falling)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[5 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[4],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[0 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                    } else {
                                        if (pl->falling)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[32 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[31],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[27 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                    }
                                } else {
                                    if (!pl->damaging) {
                                        if (pl->falling)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[23 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[22],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[18 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                    } else {
                                        if (pl->falling)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[41 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[40],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                        if (!pl->falling && !pl->jumping)
                                            draw_sprite_h_flip(gfx->virt[0], gfx->phspr[36 + fixtoi(pl->aniframe)],
                                                               (fixtoi(pl->x) + X_DESP) / 2,
                                                               (fixtoi(pl->y) + Y_DESP) / 2);
                                    }
                                }
                            } else {
                                if (pl->falling)
                                    draw_sprite_h_flip(gfx->virt[0], gfx->phspr[14 + fixtoi(pl->aniframe)],
                                                       (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                                if (pl->jumping)
                                    draw_sprite_h_flip(gfx->virt[0], gfx->phspr[13], (fixtoi(pl->x) + X_DESP) / 2,
                                                       (fixtoi(pl->y) + Y_DESP) / 2);
                                if (!pl->falling && !pl->jumping)
                                    draw_sprite_h_flip(gfx->virt[0], gfx->phspr[9 + fixtoi(pl->aniframe)],
                                                       (fixtoi(pl->x) + X_DESP) / 2, (fixtoi(pl->y) + Y_DESP) / 2);
                            }
                        }
                    }
                }
            }
        }
        if (pl->end) ph_game_end2(p);
        if (!pl->just_enter) pl->just_enter = 1;

        ph_draw_marc(p);

        /* Mostrar informacion del volumen si es pertinente */

#ifndef GP2X
        if (show_sfx_vol) {
            rect(gfx->virt[0], (SCREEN_W >> 1) - 64, ((SCREEN_H - 30) >> 1) - 6, ((SCREEN_W >> 1) + 65),
                 ((SCREEN_H - 30) >> 1) + 8, makecol(0, 0, 127));
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            set_trans_blender(130, 130, 130, 130);
            rectfill(gfx->virt[0], (SCREEN_W >> 1) - 63, ((SCREEN_H - 30) >> 1) - 5, ((SCREEN_W >> 1) + 64),
                     ((SCREEN_H - 30) >> 1) + 7, makecol(0, 0, 127));
            drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
            if (cfg->sfxvolume)
                rectfill(gfx->virt[0], (SCREEN_W >> 1) - 63, ((SCREEN_H - 30) >> 1) - 5,
                         ((SCREEN_W >> 1) - 63) + (cfg->sfxvolume >> 1), ((SCREEN_H - 30) >> 1) + 7,
                         makecol(0, 0, 255));
            ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
            ph_printf(gfx->virt[0], p->fnt, SCREEN_W >> 1, ((SCREEN_H - 60) >> 1) - 4, (char *) _("SFX volume"));
            show_sfx_vol--;
        }
        if (show_mus_vol) {
            rect(gfx->virt[0], (SCREEN_W >> 1) - 64, ((SCREEN_H - 30) >> 1) - 6, ((SCREEN_W >> 1) + 65),
                 ((SCREEN_H - 30) >> 1) + 8, makecol(0, 0, 127));
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            set_trans_blender(130, 130, 130, 130);
            rectfill(gfx->virt[0], (SCREEN_W >> 1) - 63, ((SCREEN_H - 30) >> 1) - 5, ((SCREEN_W >> 1) + 64),
                     ((SCREEN_H - 30) >> 1) + 7, makecol(0, 0, 127));
            drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
            if (cfg->musicvolume)
                rectfill(gfx->virt[0], (SCREEN_W >> 1) - 63, ((SCREEN_H - 30) >> 1) - 5,
                         ((SCREEN_W >> 1) - 63) + (cfg->musicvolume >> 1), ((SCREEN_H - 30) >> 1) + 7,
                         makecol(0, 0, 255));
            ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
            ph_printf(gfx->virt[0], p->fnt, SCREEN_W >> 1, ((SCREEN_H - 60) >> 1) - 4, (char *) _("Music volume"));
            show_mus_vol--;
        }
#else
                                                                                                                                if (show_sfx_vol) {
			rect(gfx->virt[0],(SCREEN_W>>1)-64,((SCREEN_H-30)>>1)-6,((SCREEN_W>>1)+65),((SCREEN_H-30)>>1)+8,makecol(0,0,127));
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			set_trans_blender(130,130,130,130);
			rectfill(gfx->virt[0],(SCREEN_W>>1)-63,((SCREEN_H-30)>>1)-5,((SCREEN_W>>1)+64),((SCREEN_H-30)>>1)+7,makecol(0,0,127));
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
			if (cfg->sfxvolume) rectfill(gfx->virt[0],(SCREEN_W>>1)-63,((SCREEN_H-30)>>1)-5,((SCREEN_W>>1)-63)+(cfg->sfxvolume>>1),((SCREEN_H-30)>>1)+7,makecol(0,0,255));
			ph_set_text_properties(p->fnt,makecol(250,250,250),-1,TXT_TITLE,TXT_CENTER, 1);
			ph_printf(gfx->virt[0],p->fnt,SCREEN_W>>1,((SCREEN_H-60)>>1)-4,(char *)_("Volume"));
			show_sfx_vol--;
		}
#endif

        /*Mostrar informacion de las teclas de control pulsadas */

        if (c->key_press) {
            switch (c->key_event) {
                case 1:
                    break;
                case 2:
                    if (c->type == CTRL_TYPE_KEYBOARD) {
                        ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
                        ph_printf(gfx->virt[0], p->fnt, 160, ((240 - 30) >> 1) - 4,
                                  (char *) _("Control device set to keyboard."));
                    }
                    if (c->type == CTRL_TYPE_JOYSTICK) {
                        ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
                        ph_printf(gfx->virt[0], p->fnt, 160, ((240 - 30) >> 1) - 4,
                                  (char *) _("Control device set to joystick."));
                    }
                    break;
                case 3:
                    ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
                    if (cfg->surround)
                        ph_printf(gfx->virt[0], p->fnt, 160, ((240 - 30) >> 1) - 4, (char *) _("Surround: On."));
                    else ph_printf(gfx->virt[0], p->fnt, 160, ((240 - 30) >> 1) - 4, (char *) _("Surround: Off."));
                    break;
                case 4:
                    ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
                    if (cfg->show_tips)
                        ph_printf(gfx->virt[0], p->fnt, 160, ((240 - 30) >> 1) - 4, (char *) _("Show tips: On."));
                    else ph_printf(gfx->virt[0], p->fnt, 160, ((240 - 30) >> 1) - 4, (char *) _("Show tips: Off."));
                    break;
            }
        }

        /* Si showtips llamar a las funciones de ensenar los mensajes */
        if (p->cfg->show_tips) {
            if (event[0] == 1) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 0);
                event[0] = 2;
                ph_draw(gfx, cfg);
                p->t->acycle = 0;
                p->t->target_cycle = 0;
            }

            if (event[1]) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 1);
                event[1] = 0;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }

            if (event[2]) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 2);
                event[2] = 0;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }

            if (event[3]) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 3);
                event[3] = 0;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }

            if (event[4] == 1) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 4);
                event[4] = 2;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }

            if (event[5] == 1) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 5);
                event[5] = 2;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }

            if (event[6] == 1) {
                event[6] = 2;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }

            if (event[7] == 1) {
                ph_in_game_message(c, gfx, cfg, sound, pl, pfont, 6);
                event[7] = 2;
                p->t->acycle = 0;
                p->t->target_cycle = 0;
                ph_draw(gfx, cfg);
            }
        }
        /* Mostrar algo de informacion de depuracion */
        if (debug) {
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            rectfill(gfx->virt[0], 0, 0, 400, 40, makecol(50, 50, 50));
            drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
            ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_LEFT, 1);
            ph_printf(gfx->virt[0], p->fnt, 10, 10, (char *) "x:%d y:%d xm:%d ym:%d energy known:%d vehicle state:%d",
                      fixtoi(pl->x), fixtoi(pl->y), fixtoi(pl->x) >> 4, fixtoi(pl->y) >> 4, energy->known2,
                      p->v->active);
            ph_printf(gfx->virt[0], p->fnt, 10, 20,
                      (char *) "room:%d life:%d switches:%d  time:%d   energia restante:%d", w->actroom, pl->energy,
                      pl->pressed_switches, p->t->script_target_cycle, p->pl->left_energy);
            ph_printf(gfx->virt[0], p->fnt, 10, 30, (char *) "event:%d %d", event[6], event[7]);
        }
        /* El gran blit :) */
        ph_draw(gfx, cfg);
    }
}


void ph_change_room(PROGRAM *p, int room) {
    PLATFORM *plat;
    ENERGY *energy;
    SWITCH *sw;
    WORLD *w;
    GFX *gfx;
    DATA *data;
    ENEMY *ene;
    lua_State *ls;
    int i;

    w = (WORLD *) p->w;
    ene = (ENEMY *) p->ene;
    data = (DATA *) p->data;
    gfx = (GFX *) p->gfx;
    ls = (lua_State *) p->ls;
    sw = (SWITCH *) p->sw;
    energy = (ENERGY *) p->energy;
    plat = (PLATFORM *) p->plat;
    ene->actenemy = 0;
    energy->actenergy = 0;
    sw->actswitch = 0;
    plat->actplatform = 0;
    for (i = 0; i < MAX_ENEMIES; i++) ene->type[i] = 0;
    for (i = 0; i < MAX_ENEMIES; i++) ene->active[i] = 0;
    for (i = 0; i < MAXENERGY; i++) energy->active[i] = 0;
    for (i = 0; i < MAXSWITCHES; i++) sw->active[i] = 0;
    for (i = 0; i < MAXPLATFORMS; i++) plat->active[i] = 0;
    w->visited_rooms[room] = 1;
    lua_getglobal(ls, "set_world_data");
    lua_pushnumber(ls, 80);
    lua_pushnumber(ls, 76);
    lua_pushnumber(ls, room);
    lua_pushlightuserdata(ls, w);
    lua_pushlightuserdata(ls, ene);
    lua_pushlightuserdata(ls, data);
    lua_pushlightuserdata(ls, gfx);
    lua_pushlightuserdata(ls, energy);
    lua_pushlightuserdata(ls, sw);
    lua_pushlightuserdata(ls, plat);
    lua_pcall(ls, 10, 0, 0);
    if (p->cfg->enable_sound && p->cfg->sfx) ph_play_ambient_sfx(p->w->actroom, p->snd, p->cfg);

    if ((room == 29 && !p->snd->main_theme) || (room == 21 && !p->snd->main_theme)) {
        p->snd->main_theme = 1;
#ifdef HAVE_ALOGG_H
#ifndef GP2X
        if (p->cfg->enable_sound && p->cfg->music)
            p->snd->music->voice = play_sample(p->snd->music->ogg2, p->cfg->musicvolume, 127, 1000, 1);
#endif
#endif
    }
}


PROGRAM *ph_game_over(PROGRAM *p) {
    int i, a, cont = 0;
    int totalvrooms = 0;
    signed int score = 0;
    char draw_input = 0;
    BITMAP *pieces[256];
    BITMAP *aux = NULL;
    BITMAP *aux1 = NULL;
#ifdef CUSTOM_PATH
    char buf[512];
#endif

    if (p->cfg->enable_sound && p->cfg->sfx) {
        stop_sample(p->snd->sfx->radar);
        stop_sample(p->snd->sfx->hell);
        stop_sample(p->snd->sfx->bubbles);
    }

    /* Fuera musica */
#ifdef HAVE_ALOGG_H
    if (p->cfg->enable_sound && p->cfg->music) {
#ifndef GP2X
        stop_sample(p->snd->music->ogg2);
#endif
    }
#endif
    for (i = 0; i < 256; i++) {
        pieces[i] = create_bitmap(1, 1);
        clear(pieces[i]);
    }
    i = 0;
    clear(p->gfx->phhelper);
    aux1 = p->gfx->phhelper;

    if (!p->pl->abu) {
        if (p->pl->falling) {
            aux = p->gfx->phspr[5 + fixtoi(p->pl->aniframe)];
        }
        if (p->pl->jumping) {
            aux = p->gfx->phspr[4];
        }
        if (!p->pl->jumping && !p->pl->falling) {
            aux = p->gfx->phspr[fixtoi(p->pl->aniframe)];
        }
        if (!p->pl->right) {
            draw_sprite_h_flip(aux1, aux, 0, 0);
            aux = aux1;
        }
    } else {
        if (p->pl->falling) {
            aux = p->gfx->phspr[23 + fixtoi(p->pl->aniframe)];
        }
        if (p->pl->jumping) {
            aux = p->gfx->phspr[22];
        }
        if (!p->pl->jumping && !p->pl->falling) {
            aux = p->gfx->phspr[18 + fixtoi(p->pl->aniframe)];
        }
        if (!p->pl->right) {
            draw_sprite_h_flip(aux1, aux, 0, 0);
            aux = aux1;
        }
    }

    /* Ya esta el grafico de Phantomas en aux */
    /* Ahora se descompone en trocitos de 2 por 2 */

    cont = 0;
    for (a = 0; a < 16; a++) {
        for (i = 0; i < 16; i++) {
            blit(aux, pieces[cont], i, a, 0, 0, 1, 1);
            cont++;
        }
    }
    i = 0;
    (void) cont;

    /* Phantomas esta troceado */
    /* Ruidito de game over y do_speccy especial para la animacion de Phantomas */

    ph_play_sample(p->snd->sfx->gameover, 160, p->cfg);
    ph_do_sp_speccy(fixtoi(p->pl->x), fixtoi(p->pl->y), pieces, p);
    p->t->acycle = p->t->target_cycle = 0;
    p->t->acycle = p->t->target_cycle = 0;
    clear_keybuf();

    for (i = 0; i < MAXWORLDROOMS; i++) {
        if (p->w->visited_rooms[i]) {
            totalvrooms++;
        }
    }

    // CALCULAR PUNTUACION
#ifdef CUSTOM_PATH
                                                                                                                            memset(buf,0,512);
	strcpy(buf,"data/network.bin");
	ph_get_path(p->path,buf);
	int res = luaL_dofile(p->ls,p->path);
	(void) res;
#else
    ph_get_file_name(p->cfg, (char *) "network.bin");
    int res = luaL_dofile(p->ls, p->cfg->buffer);
    (void) res;
#endif

    lua_getglobal(p->ls, "calc_score");
    lua_pushnumber(p->ls, totalvrooms);
    lua_pushnumber(p->ls, p->pl->pressed_switches);
    lua_pushnumber(p->ls, p->pl->treasure);
    lua_pushnumber(p->ls, p->pl->safe);
    lua_pushnumber(p->ls, p->pl->finished);
    lua_pushnumber(p->ls, p->pl->energy);
    lua_pushnumber(p->ls, (p->energy->known2 - p->pl->left_energy));
    lua_pushnumber(p->ls, p->t->script_target_cycle);
    lua_pcall(p->ls, 8, 1, 0);
    score = (int) lua_tonumber(p->ls, -1);
    i = 0;
    ph_fade_out(16, p->cfg);
    draw_sprite(p->gfx->virt[0], p->gfx->tr2x, 0, 0);
    draw_sprite(p->gfx->virt[0], p->gfx->gameover, (320 >> 1) - (p->gfx->gameover->w >> 1), 60);
    p->fnt->color = makecol(255, 255, 255);
    p->fnt->align = TXT_CENTER;
    ph_printf(p->gfx->virt[0], p->fnt, 160, 115, _("You have completed %d percent of the adventure."),
              (score * 100) / 1986);
    ph_printf(p->gfx->virt[0], p->fnt, 160, 130, _("Your score: %d points."), score);
    p->fnt->color = makecol(255, 255, 0);
#ifndef GP2X
    ph_text(p->gfx->virt[0], p->fnt, 160, 145, _("Press any key to continue..."));
#else
    ph_text(p->gfx->virt[0],p->fnt,160,145,_("Press X to continue..."));
#endif
    p->fnt->align = TXT_LEFT;

    if (p->cfg->stretch) {
        stretch_blit(p->gfx->virt[0], screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
    } else {
        blit(p->gfx->virt[0], screen, 0, 0, 0, 0, 320, 240);
    }

    p->snd->main_theme = 0;

    do {
        poll_joystick();
        if (joy[0].button[1].b) {
            joy[0].button[1].b = 0;
            break;
        }
        poll_keyboard();
    } while (!keypressed());

    clear_keybuf();

    p->rec->points = score;

    for (i = 0; i < MAXRECS; i++) {
        if (score >= p->rec->r[i]->points) {
            draw_input = 1;
        }
    }

    if (draw_input) {
        ph_draw_input_table(p->rec, p->gfx, p->cfg, p->t, p->fnt, p->snd->sfx);
    }
    ph_draw_record_table(p->rec, p->gfx, p->cfg, p->t, p->fnt);

    memset(p->pl, 0, sizeof(struct PLAYER));
    memset(p->v, 0, sizeof(struct VEHICLE));

    for (i = 0; i < 62; i++) {
        p->energy->known[i] = 0;
    }

    p->pl->special_switch_on = 0;
    p->pl->left_energy = 0;
    p->energy->known2 = 0;
    p->pl->x = itofix(64);
    p->pl->y = itofix(16);
    p->b->x = 0;
    p->b->y = 128;
    p->pl->right = 1;
    p->pl->aniframe = 1;
    p->pl->speed = 4;
    p->pl->jumping = 0;
    p->pl->energy = 238;
    p->pl->end = 0;
    p->pl->treasure = 0;
    p->pl->safe = 0;
    p->pl->rocket = 0;
    p->pl->inchopper = 0;
    p->pl->inrocket = 0;
    p->pl->pressed_switches = 0;
    p->pl->finished = 0;
    p->w->actroom = 0;
    p->pl->restart = 0;
    p->w = ph_load_world_data_alt(p->w, p->data);
    p->b->active = 0;
    p->pl->inball = 0;
    p->pl->left_energy = 0;
    p->pl->ballspeed = 248;
    p->snd->main_theme = 0;

    for (i = 0; i < 100; i++) {
        p->energy->got[i] = 0;
        p->sw->pressed[i] = 0;
        p->sw->switchid[i] = 0;
    }

    memset(p->v, 0, sizeof(struct VEHICLE));
    memset(p->w->visited_rooms, 0, sizeof(char) * MAXWORLDROOMS);
    memset(p->ar, 0, sizeof(struct ARROWS));
    memset(p->bl, 0, sizeof(struct BLOCK));
    memset(p->b, 0, sizeof(struct BALL));
    p->bl->x = 176;
    p->bl->y = 32;
    p->sw->actswitch = 0;
    ph_get_room_data(p->w, p->w->actroom, p->pl);
    ph_change_room(p, p->w->actroom);
    clear_to_color(p->gfx->virt[0], makecol(0, 0, 0));
    p->b->y = 128;
    p->pl->aniframe = 1;
    p->pl->y = itofix(184);

    p->t->script_target_cycle = 0;
    p->t->acycle = p->t->target_cycle = 0;
    for (i = 0; i < 256; i++) destroy_bitmap(pieces[i]);
    return p;
}


void ph_fade_out(int speed, CFG *cfg) {
    BITMAP *bmp_orig = NULL;
    BITMAP *bmp_buff = NULL;

    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
#ifndef GP2X
    if ((bmp_orig = create_bitmap(320, 240))) {
        if ((bmp_buff = create_bitmap(320, 240))) {
            int a;
            stretch_blit(screen, bmp_orig, 0, 0, SCREEN_W, SCREEN_H, 0, 0, 320, 240);
            if (speed <= 0) speed = 16;
            for (a = 255 - speed; a > 0; a -= speed) {
                clear(bmp_buff);
                set_trans_blender(0, 0, 0, a);
                draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
                vsync();
                if (cfg->stretch) {
                    stretch_blit(bmp_buff, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
                } else {
                    blit(bmp_buff, screen, 0, 0, 0, 0, 320, 240);
                }
            }
        }
    }
#else
                                                                                                                            if ((bmp_orig = create_bitmap(320, 240))) {
		if ((bmp_buff = create_bitmap(320, 240))) {
			int a;
			stretch_blit(screen, bmp_orig, 0,0, SCREEN_W, SCREEN_H, 0,0, 320, 240);
			if (speed <= 0) speed = 16;
			for (a = 255-speed; a > 0; a-=speed) {
				clear(bmp_buff);
				set_trans_blender(0,0,0,a);
				draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
				vsync();
				stretch_blit(bmp_buff,screen,0,0,320,240,0,0,SCREEN_W, SCREEN_H);
			}
		}
	}
#endif

    set_trans_blender(255, 255, 255, 255);
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
    rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, makecol(0, 0, 0));
    destroy_bitmap(bmp_buff);
    destroy_bitmap(bmp_orig);
}


void ph_fade_in(BITMAP *bmp_orig, int speed) {
    BITMAP *bmp_buff;

    if ((bmp_buff = create_bitmap(320, 240))) {
        int a;
        if (speed <= 0) speed = 16;

        for (a = 0; a < 256; a += speed) {
            clear(bmp_buff);
            set_trans_blender(0, 0, 0, a);
            draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
            vsync();
            stretch_blit(bmp_buff, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
        }
        destroy_bitmap(bmp_buff);
    }

    stretch_blit(bmp_orig, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
}


void ph_fade_image(int speed, BITMAP *dst) {
    BITMAP *bmp_orig = NULL;
    BITMAP *bmp_buff = NULL;
    int a = 255, b = 0;

    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);

    if ((bmp_orig = create_bitmap(320, 240))) {
        if ((bmp_buff = create_bitmap(320, 240))) {
            stretch_blit(screen, bmp_orig, 0, 0, SCREEN_W, SCREEN_H, 0, 0, 320, 240);
            a = 255;
            b = 0;

            for (a = 255 - speed; a > 0; a -= speed) {
                clear_to_color(bmp_buff, makecol(0, 0, 0));
                set_trans_blender(0, 0, 0, a);
                draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
                b = 255 - a;
                set_trans_blender(0, 0, 0, b);
                draw_trans_sprite(bmp_buff, dst, 0, 0);
                vsync();
                stretch_blit(bmp_buff, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
    }

    set_trans_blender(255, 255, 255, 255);
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
    destroy_bitmap(bmp_buff);
    destroy_bitmap(bmp_orig);
}


void ph_draw_text_box(GFX *gfx, CFG *cfg) {
    unsigned short int i;

    set_trans_blender(0, 0, 0, 30);
    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
    for (i = 0; i < 90; i += 2) {
        rectfill(gfx->virt[0], (0 + X_DESP) / 2, (150 - i + Y_DESP) / 2, (479 + X_DESP) / 2, (150 + i + Y_DESP) / 2,
                 makecol(0, 0, 50));
        hline(gfx->virt[0], (0 + X_DESP) / 2, ((Y_DESP + 150 - i) + 1) / 2, (479 + X_DESP) / 2, makecol(200, 200, 255));
        hline(gfx->virt[0], (0 + X_DESP) / 2, ((Y_DESP + 150 - i)) / 2, (479 + X_DESP) / 2, makecol(200, 200, 255));
        hline(gfx->virt[0], (0 + X_DESP) / 2, ((Y_DESP + 150 + i)) / 2, (479 + X_DESP) / 2, makecol(200, 200, 255));
        hline(gfx->virt[0], (0 + X_DESP) / 2, ((Y_DESP + 150 + i) + 1) / 2, (479 + X_DESP) / 2, makecol(200, 200, 255));
        rest(5);
        ph_draw(gfx, cfg);
    }
    set_trans_blender(255, 255, 255, 255);
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
}


void ph_in_game_message(CONTROL *c, GFX *gfx, CFG *cfg, SOUND *sound, PLAYER *pl, PHFONT *fnt, char event) {
    ph_play_sample(sound->sfx->menubegin, 160, cfg);
    ph_draw_text_box(gfx, cfg);
    ph_set_text_properties(fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_LEFT, 1);

    switch (event) {
        case 0:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("You are in Goldter's mansion."));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2,
                    _("Your mission is to steal the safe box"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (129 + Y_DESP) / 2, _("and the treasure chest."));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (153 + Y_DESP) / 2, _("Good luck."));
            break;
        case 1:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("When enemies hit Phantomas,"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2, _("the energy bar gets darker."));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (129 + Y_DESP) / 2, _("When it gets totally dark,"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (153 + Y_DESP) / 2, _("Phantomas will be destroyed!"));
            break;
        case 2:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("Energy capsules allow Phantomas"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2, _("to get some extra energy."));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (129 + Y_DESP) / 2, _("There are only a few."));
            break;
        case 3:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("These switches open the safe box."));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2, _("You have to push all of them or"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (129 + Y_DESP) / 2, _("you won't be able to open it."));
            break;
        case 4:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("You have pressed every switch!"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2, _("You can get the safe now!"));
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (129 + Y_DESP) / 2, _("It should be in Goldter's office."));
            break;
        case 5:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("Great! You got the safe!!"));
            if (!pl->treasure) {
                ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2,
                        _("You should go for the treasure now!"));
                ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (129 + Y_DESP) / 2, _("Surely it is in the gauntlet."));
            } else {
                ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2, _("Let's run to the exit!"));
            }
            break;
        case 6:
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (81 + Y_DESP) / 2, _("It's a trap!!!"));
#ifndef GP2X
            ph_text(gfx->virt[0], fnt, (8 + X_DESP) / 2, (105 + Y_DESP) / 2, _("Press left and right to run!!"));
#else
            ph_text(gfx->virt[0],fnt,(8+X_DESP)/2,(105+Y_DESP)/2,_("Press and release B button to run!!"));
#endif
            pl->y = itofix(224);
            break;
    }

    ph_set_text_properties(fnt, makecol(250, 250, 0), -1, TXT_TITLE, TXT_CENTER, 1);

    if (c->type == CTRL_TYPE_KEYBOARD) {
        ph_text(gfx->virt[0], fnt, (240 + X_DESP) / 2, (201 + Y_DESP) / 2, _("Press Enter to continue..."));
    } else {
        ph_text(gfx->virt[0], fnt, (240 + X_DESP) / 2, (201 + Y_DESP) / 2, _("Press A to continue..."));
    }

    ph_draw(gfx, cfg);

#ifndef GP2X
    if (c->type == CTRL_TYPE_KEYBOARD) {
        poll_keyboard();
        clear_keybuf();
        do {
            poll_keyboard();
        } while (!key[KEY_ENTER]);
        ph_play_sample(sound->sfx->menuend, 160, cfg);
        clear_keybuf();
    } else {
        do {
            poll_joystick();
        } while (!joy[0].button[1].b);
        joy[0].button[1].b = 0;
        ph_play_sample(sound->sfx->menuend, 160, cfg);
        return;
    }
#else
                                                                                                                            if (c->type==CTRL_TYPE_KEYBOARD) {
		poll_keyboard();
		clear_keybuf();
		do {
			poll_keyboard();
		}
		while(!key[KEY_ENTER]);
		ph_play_sample(sound->sfx->menuend,160,cfg);
		clear_keybuf();
	}
	else {
		do {
			poll_joystick();
		}
		while (!joy[0].button[3].b);
		joy[0].button[3].b=0;
		ph_play_sample(sound->sfx->menuend,160,cfg);
		return;
	}
#endif
}


char ph_special_cases(PROGRAM *p) {
    char res = 0;

    switch (p->w->actroom) {
        case 2:
            break;
    }
    return res;
}


void ph_draw_dec(PROGRAM *p) {

    int i, a, b, pan;
    static int x = 0;

    /* Se pone la imagen del fondo */
    if (p->w->actroom != 7) ph_draw_back_image(p->w, p->gfx);

    /* Primera pasada, se ponen las sombras */
    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
    set_trans_blender(60, 60, 60, 60);

    for (a = 0; a < YMAXTILE; a++) {
        for (i = 0; i < XMAXTILE; i++) {
            /* Las sombras se dibujan con transparencia */
            if (p->w->room[i][a] >= (PHANTGFX_DAT_DEC90_0_BMP - MAXSPRBACK) &&
                p->w->room[i][a] <= (PHANTGFX_DAT_DEC98_0_BMP - MAXSPRBACK)) {
                draw_trans_sprite(p->gfx->virt[0], p->gfx->decspr[(int) p->w->room[i][a]], ((i << 4) + X_DESP) / 2,
                                  ((a << 4) + Y_DESP) / 2);
            }
        }
    }
    set_trans_blender(255, 255, 255, 255);
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);

    /* Segunda pasada, se pone el resto de objetos */
    if (p->w->actroom != 67) {
        for (a = 0; a < YMAXTILE; a++) {
            for (i = 0; i < XMAXTILE; i++) {
                if ((p->w->room[i][a] < PHANTGFX_DAT_DEC90_0_BMP - MAXSPRBACK) ||
                    (p->w->room[i][a] > PHANTGFX_DAT_DEC96_0_BMP - MAXSPRBACK)) {
                    draw_sprite(p->gfx->virt[0], p->gfx->decspr[(int) p->w->room[i][a]], ((i << 4) + X_DESP) / 2,
                                ((a << 4) + Y_DESP) / 2);
                }
            }
        }
    } else {
        /* Esto mueve el suelo donde la bola */
        for (i = 0; i < 960; i += 32) {
            draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_DEC64_0_BMP].dat, (i + x + X_DESP) / 2,
                        (256 + Y_DESP) / 2);
        }
        x -= 8;
        if (x <= -480) x = 0;
    }
    /*
	if ((p->w->actroom==5 && p->pl->inrocket) || (p->w->actroom==66 && p->pl->inrocket))
	{
	draw_sprite(p->gfx->virt[0],p->gfx->decspr[PHANTGFX_DAT_DEC42_0_BMP-6],176,114);
	}
	*/

    if (p->w->actroom == 5 && !p->pl->inrocket && p->v->ractive < 5) {
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[PHANTGFX_DAT_DEC06_0_BMP - MAXSPRBACK], (176 + 16 + X_DESP) / 2,
                    (114 + 32 + Y_DESP) / 2);
    }

    if (p->w->actroom == 5 && p->v->ractive >= 2) {
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[PHANTGFX_DAT_DEC04_0_BMP - MAXSPRBACK], (176 + 32 + X_DESP) / 2,
                    (112 + Y_DESP) / 2);
    }

    if (p->w->actroom == 7) {
        b = rand() % 7;
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO110_0_BMP - MAXSPRBACK) + b], (32 + X_DESP) / 2,
                    (48 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO113_0_BMP - MAXSPRBACK) + b], (336 + X_DESP) / 2,
                    (16 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO111_0_BMP - MAXSPRBACK) + rand() % 7],
                    (368 + X_DESP) / 2, (48 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO112_0_BMP - MAXSPRBACK) + b], (X_DESP) / 2,
                    (192 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO112_0_BMP - MAXSPRBACK) + b], (48 + X_DESP) / 2,
                    (192 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO112_0_BMP - MAXSPRBACK) + b], (X_DESP) / 2,
                    (224 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO112_0_BMP - MAXSPRBACK) + b], (48 + X_DESP) / 2,
                    (224 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[(PHANTGFX_DAT_DECO112_0_BMP - MAXSPRBACK) + b], (92 + X_DESP) / 2,
                    (208 + Y_DESP) / 2);
    }
    if (p->w->actroom == 57 && !p->pl->opendoor) {
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[PHANTGFX_DAT_DEC81_0_BMP - MAXSPRBACK], 0 + X_DESP / 2,
                    (96 + Y_DESP) / 2);
    }
    if (p->w->actroom == 57 && p->pl->explotedoor == 2 && fixtoi(p->pl->x) >= 32) {
        if (p->cfg->enable_sound && p->cfg->sfx) {
            if (p->cfg->surround) pan = (255 * (0 >> 1)) / 224; else pan = 127;
            if (!p->pl->heared) {
                play_sample(p->snd->sfx->ts, p->cfg->sfxvolume, pan, 1000, 0);
                p->pl->heared = 1;
            }
        }
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[PHANTGFX_DAT_DEC81_0_BMP - MAXSPRBACK], 0 + X_DESP / 2,
                    (96 + Y_DESP) / 2);
    }
    if (p->w->actroom == 66) {
        if (p->cfg->enable_sound && p->cfg->sfx) {
            if (p->cfg->surround) pan = (255 * (0 >> 1)) / 224; else pan = 127;
            if (!p->pl->spa_heared) {
                play_sample(p->snd->sfx->space, p->cfg->sfxvolume, pan, 1000, 1);
                p->pl->spa_heared = 1;
            }
        }
    }
    if (p->w->actroom != 66 && p->pl->spa_heared) {
        p->pl->spa_heared = 0;
        if (p->cfg->enable_sound && p->cfg->sfx) {
            stop_sample(p->snd->sfx->space);
        }
    }
    if (p->w->actroom == 7) {
        if (p->cfg->enable_sound && p->cfg->sfx) {
            if (p->cfg->surround) pan = (255 * (0 >> 1)) / 224; else pan = 127;
            if (!p->pl->sp_heared) {
                play_sample(p->snd->sfx->speccy, p->cfg->sfxvolume, pan, 1000, 1);
                p->pl->sp_heared = 1;
            }
        }
    }
    if (p->w->actroom != 7 && p->pl->sp_heared) {
        p->pl->sp_heared = 0;
        if (p->cfg->enable_sound && p->cfg->sfx) {
            stop_sample(p->snd->sfx->speccy);
        }
    }
    if (p->w->actroom == 56 && p->pl->treasure && !p->pl->explotedoor) {
        draw_sprite(p->gfx->virt[0], p->gfx->decspr[PHANTGFX_DAT_DEC81_0_BMP - MAXSPRBACK], (448 + X_DESP) / 2,
                    (96 + Y_DESP) / 2);
    }

}


void ph_game_end2(PROGRAM *p) {
    BITMAP *bmp;
    int a = 0;
    int b = 0;
    int i = 0;
    int len1 = 0;
    int len2 = 0;
    int big;
    int res = 0;
    int totalvrooms = 0;
    signed int score = 0;
    char draw_input = 0;
#ifdef CUSTOM_PATH
    char buf[512];
#endif

    bmp = create_bitmap(p->cfg->xres, p->cfg->yres);
    clear(bmp);
    ph_set_text_properties(p->fnt, makecol(0, 0, 0), -1, TXT_TITLE, TXT_CENTER, 1);
    p->pl->finished = 1;
    ph_change_room(p, p->w->actroom);
    ph_get_room_data(p->w, p->w->actroom, p->pl);
    ph_draw_marc(p);
    blit(p->gfx->virt[0], bmp, 0, 0, 0, 0, p->cfg->xres, p->cfg->yres);

    len1 = text_length(p->fnt->ufnt, _("Good try Phantomas."));
    len2 = text_length(p->fnt->ufnt, _("Maybe next time..."));

    big = len1;
    if (len1 > len2) big = len1;
    if (len2 > len1) big = len2;

    while (1) {
        if (!a) ph_play_sample(p->snd->sfx->menubegin, 160, p->cfg);
        if (a < big >> 1) a++;
        rectfill(bmp, 160 - a - 2, 86, 160 + a + 2, 120, makecol(20, 20, 20));
        rectfill(bmp, 160 - a, 88, 160 + a, 118, makecol(200, 200, 200));
        if (a >= big >> 1) {
            ph_set_text_properties(p->fnt, makecol(0, 0, 0), -1, TXT_TITLE, TXT_CENTER, 1);
            ph_printf(bmp, p->fnt, 320 / 2, 180 / 2, _("Good try Phantomas."));
            ph_printf(bmp, p->fnt, 320 / 2, 210 / 2, _("Maybe next time..."));
            poll_keyboard();
            if (key[KEY_ENTER]) break;
            poll_joystick();
            if (joy[0].button[3].b) break;
        }
        if (!p->cfg->stretch)
            blit(bmp, screen, 0, 0, 0, 0, p->cfg->xres, p->cfg->yres);
        else
            stretch_blit(bmp, screen, 0, 0, p->cfg->xres, p->cfg->yres, 0, 0, p->cfg->stretchx, p->cfg->stretchy);
        rest(20);
    }

    len1 = text_length(p->fnt->ufnt, _("...Shit!"));
    a = 0;

    ph_set_text_properties(p->fnt, makecol(0, 0, 0), -1, TXT_TITLE, TXT_CENTER, 1);

    while (1) {
        if (!a) ph_play_sample(p->snd->sfx->menubegin, 160, p->cfg);
        if (a < len1 >> 1) a++;
        rectfill(bmp, 64 - a - 2, 115, 64 + a + 2, 134, makecol(20, 20, 20));
        rectfill(bmp, 64 - a, 117, 64 + a, 132, makecol(200, 200, 200));
        if (a >= len1 >> 1) {
            ph_set_text_properties(p->fnt, makecol(0, 0, 0), -1, TXT_TITLE, TXT_CENTER, 1);
            ph_printf(bmp, p->fnt, 64, 119, _("...Shit!"));
            poll_keyboard();
            if (key[KEY_ENTER]) break;
            poll_joystick();
            if (joy[0].button[3].b) break;
        }
        rest(20);
        if (!p->cfg->stretch)
            blit(bmp, screen, 0, 0, 0, 0, p->cfg->xres, p->cfg->yres);
        else
            stretch_blit(bmp, screen, 0, 0, p->cfg->xres, p->cfg->yres, 0, 0, p->cfg->stretchx, p->cfg->stretchy);
    }

    a = 0;

    while (1) {
        if (!a) ph_play_sample(p->snd->sfx->gameover, 160, p->cfg);
        if (a < 9) {
            for (b = 0; b < 240; b += 8) {
                for (i = 0; i < 320; i += 8) {
                    rectfill(bmp, i - (a >> 1), b - (a >> 1), i + (a >> 1), b + (a >> 1), makecol(0, 0, 0));
                }
            }
            a++;
        }
        rest(50);
        if (!p->cfg->stretch)
            blit(bmp, screen, 0, 0, 0, 0, p->cfg->xres, p->cfg->yres);
        else
            stretch_blit(bmp, screen, 0, 0, p->cfg->xres, p->cfg->yres, 0, 0, p->cfg->stretchx, p->cfg->stretchy);
        if (a >= 9) break;
    }

    rest(200);
    a = 0;
    b = 0;

    while (1) {
        clear(bmp);
        ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
        if (a < 100) {
            ph_printf(bmp, p->fnt, 160, 70, _("Phantomas PC, a remake of Phantomas."));
            ph_printf(bmp, p->fnt, 160, 90, _("2005-2011 Traperic Software."));
        }
        if (a >= 100 && a < 200) {
            ph_printf(bmp, p->fnt, 160, 80, _("This is the end... at the moment..."));
        }
        if (a >= 200 && a < 300) {
            ph_printf(bmp, p->fnt, 160, 80, _("Hope you enjoy this game!"));
        }
        if (a >= 300) {
            b = 1;
            a = 0;
        }

        a++;
        rest(50);
        if (b) {
            ph_set_text_properties(p->fnt, makecol(100, 100, 100), -1, TXT_TITLE, TXT_CENTER, 1);
#ifndef GP2X
            ph_printf(bmp, p->fnt, 160, 220, _("Press Enter to continue..."));
#else
            ph_printf(bmp,p->fnt,160,220,_("Press A to continue..."));
#endif
            poll_keyboard();
            if (key[KEY_ENTER]) break;
            poll_joystick();
            if (joy[0].button[3].b) break;
        }
        if (!p->cfg->stretch)
            blit(bmp, screen, 0, 0, 0, 0, p->cfg->xres, p->cfg->yres);
        else
            stretch_blit(bmp, screen, 0, 0, p->cfg->xres, p->cfg->yres, 0, 0, p->cfg->stretchx, p->cfg->stretchy);
    }
    clear(bmp);

    res = 0;
    i = 0;
    a = 0;
    totalvrooms = 0;
    draw_input = 0;
    /* Fuera musica */
#ifdef HAVE_ALOGG_H
    if (p->cfg->enable_sound && p->cfg->music) {
#ifndef GP2X
        stop_sample(p->snd->music->ogg2);
#endif
    }
#endif

    p->t->acycle = p->t->target_cycle = 0;
    clear_keybuf();

    for (i = 0; i < MAXWORLDROOMS; i++) {
        if (p->w->visited_rooms[i]) {
            totalvrooms++;
        }
    }

    // CALCULAR PUNTUACION
#ifdef CUSTOM_PATH
    memset(buf,0,512);
	strcpy(buf,"data/network.bin");
	ph_get_path(p->path,buf);
	res = luaL_dofile(p->ls,p->path);
    (void)res;
#else
    ph_get_file_name(p->cfg, (char *) "network.bin");
    res = luaL_dofile(p->ls, p->cfg->buffer);
    (void) res;
#endif
    lua_getglobal(p->ls, "calc_score");
    lua_pushnumber(p->ls, totalvrooms);
    lua_pushnumber(p->ls, p->pl->pressed_switches);
    lua_pushnumber(p->ls, p->pl->treasure);
    lua_pushnumber(p->ls, p->pl->safe);
    lua_pushnumber(p->ls, p->pl->finished);
    lua_pushnumber(p->ls, p->pl->energy);
    lua_pushnumber(p->ls, (p->energy->known2 - p->pl->left_energy));
    lua_pushnumber(p->ls, p->t->script_target_cycle);
    lua_pcall(p->ls, 8, 1, 0);
    score = (int) lua_tonumber(p->ls, -1);
    i = 0;
    p->fnt->color = makecol(255, 255, 255);
    p->fnt->align = TXT_CENTER;
    ph_printf(bmp, p->fnt, 160, 70, _("You have completed %d percent of the adventure."), (score * 100) / 1986);
    ph_printf(bmp, p->fnt, 160, 90, _("Your score: %d points."), score);
    p->fnt->color = makecol(255, 255, 0);
#ifndef GP2X
    ph_text(bmp, p->fnt, 160, 130, _("Press any key to continue..."));
#else
    ph_text(bmp,p->fnt,160,130,_("Press X to continue..."));
#endif
    p->fnt->align = TXT_LEFT;

    if (p->cfg->stretch) {
        stretch_blit(bmp, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
    } else {
        blit(bmp, screen, 0, 0, 0, 0, 320, 240);
    }

    p->snd->main_theme = 0;

    do {
        poll_joystick();
        if (joy[0].button[1].b) {
            joy[0].button[1].b = 0;
            break;
        }
        poll_keyboard();
    } while (!keypressed());

    clear_keybuf();

    p->rec->points = score;

    for (i = 0; i < MAXRECS; i++) {
        if (score >= p->rec->r[i]->points) {
            draw_input = 1;
        }
    }

    if (draw_input) {
        ph_draw_input_table(p->rec, p->gfx, p->cfg, p->t, p->fnt, p->snd->sfx);
    }
    ph_draw_record_table(p->rec, p->gfx, p->cfg, p->t, p->fnt);

    memset(p->pl, 0, sizeof(struct PLAYER));
    memset(p->v, 0, sizeof(struct VEHICLE));

    for (i = 0; i < 62; i++) {
        p->energy->known[i] = 0;
    }

    p->pl->special_switch_on = 0;
    p->pl->left_energy = 0;
    p->energy->known2 = 0;
    p->pl->x = itofix(64);
    p->pl->y = itofix(16);
    p->b->x = 0;
    p->b->y = 128;
    p->pl->right = 1;
    p->pl->aniframe = 1;
    p->pl->speed = 4;
    p->pl->jumping = 0;
    p->pl->energy = 238;
    p->pl->end = 0;
    p->pl->treasure = 0;
    p->pl->safe = 0;
    p->pl->rocket = 0;
    p->pl->inchopper = 0;
    p->pl->inrocket = 0;
    p->pl->pressed_switches = 0;
    p->pl->finished = 0;
    p->w->actroom = 0;
    p->pl->restart = 0;
    p->w = ph_load_world_data_alt(p->w, p->data);
    p->b->active = 0;
    p->pl->inball = 0;
    p->pl->left_energy = 0;
    p->pl->ballspeed = 248;
    p->snd->main_theme = 0;

    for (i = 0; i < 100; i++) {
        p->energy->got[i] = 0;
        p->sw->pressed[i] = 0;
        p->sw->switchid[i] = 0;
    }

    memset(p->v, 0, sizeof(struct VEHICLE));
    memset(p->w->visited_rooms, 0, sizeof(char) * MAXWORLDROOMS);
    memset(p->ar, 0, sizeof(struct ARROWS));
    memset(p->bl, 0, sizeof(struct BLOCK));
    memset(p->b, 0, sizeof(struct BALL));
    p->bl->x = 176;
    p->bl->y = 32;
    p->sw->actswitch = 0;
    ph_get_room_data(p->w, p->w->actroom, p->pl);
    ph_change_room(p, p->w->actroom);
    clear_to_color(bmp, makecol(0, 0, 0));
    p->b->y = 128;
    p->pl->aniframe = 1;
    p->pl->y = itofix(104);
    p->t->script_target_cycle = 0;
    p->t->acycle = p->t->target_cycle = 0;
    destroy_bitmap(bmp);
}


void ph_do_speccy(PROGRAM *p) {
    char a = 0;
    char anim = 0;
    int spcol[8];
    char i = 0;
    BITMAP *virt;

    virt = create_bitmap(320, 240);
    clear(virt);
    spcol[0] = makecol(0, 0, 0);
    spcol[1] = makecol(192, 0, 0);
    spcol[2] = makecol(0, 192, 0);
    spcol[3] = makecol(0, 0, 192);
    spcol[4] = makecol(192, 192, 0);
    spcol[5] = makecol(192, 0, 192);
    spcol[6] = makecol(0, 192, 192);
    spcol[7] = makecol(192, 192, 192);

    for (i = 0; i < 4; i++) {
        anim = 0;
        while (anim < 7) {
            set_trans_blender(255, 255, 255, 255);
            drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
            ph_draw_marc(p);
            draw_sprite(virt, p->gfx->virt[0], 0, 0);
            set_trans_blender(60, 60, 60, 60);
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            rectfill(virt, 80 / 2, 68 / 2, (480 + 79) / 2, (288 + 75 - 8) / 2, spcol[(int) a]);
            a++;
            if (a == 8) a = 0;
            acquire_screen();
            stretch_blit(virt, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
            release_screen();
            anim++;
            rest(5);
        }
    }
    set_trans_blender(255, 255, 255, 255);
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
    destroy_bitmap(virt);
}


PROGRAM *ph_reset_data(PROGRAM *p) {
    int i = 0;
    int totalvrooms = 0;

    p->t->acycle = p->t->target_cycle = 0;
    p->t->acycle = p->t->target_cycle = 0;

    for (i = 0; i < MAXWORLDROOMS; i++) {
        if (p->w->visited_rooms[i]) {
            totalvrooms++;
        }
    }
    p->fnt->align = TXT_LEFT;

#ifdef HAVE_ALOGG_H
#ifndef GP2X
    if (p->cfg->enable_sound && p->cfg->music)
        stop_sample(p->snd->music->ogg2);
    /*		#else
			if (p->cfg->enable_sound && p->cfg->music)
				stop_sample(p->snd->music->ogg1);*/
#endif
#endif

    clear_keybuf();
    memset(p->pl, 0, sizeof(struct PLAYER));
    memset(p->v, 0, sizeof(struct VEHICLE));

    for (i = 0; i < 62; i++) {
        p->energy->known[i] = 0;
    }

    p->pl->left_energy = 0;
    p->energy->known2 = 0;
    p->pl->x = itofix(64);
    p->pl->y = itofix(16);
    p->b->x = 0;
    p->b->y = 128;
    p->pl->right = 1;
    p->pl->aniframe = 1;
    p->pl->speed = 4;
    p->pl->jumping = 0;
    p->pl->energy = 238;
    p->pl->end = 0;
    p->pl->treasure = 0;
    p->pl->safe = 0;
    p->pl->rocket = 0;
    p->pl->inchopper = 0;
    p->pl->inrocket = 0;
    p->pl->pressed_switches = 0;
    p->pl->finished = 0;
    p->w->actroom = 0;
    p->w = ph_load_world_data_alt(p->w, p->data);
    p->b->active = 0;
    p->pl->inball = 0;
    p->pl->left_energy = 0;
    p->pl->ballspeed = 248;
    p->pl->special_switch_on = 0;
    p->snd->main_theme = 0;

    for (i = 0; i < 100; i++) {
        p->energy->got[i] = 0;
        p->sw->pressed[i] = 0;
        p->sw->switchid[i] = 0;
    }

    memset(p->v, 0, sizeof(struct VEHICLE));
    memset(p->w->visited_rooms, 0, sizeof(char) * MAXWORLDROOMS);
    memset(p->ar, 0, sizeof(struct ARROWS));
    memset(p->bl, 0, sizeof(struct BLOCK));
    memset(p->b, 0, sizeof(struct BALL));
    p->bl->x = 176;
    p->bl->y = 32;
    p->sw->actswitch = 0;
    ph_get_room_data(p->w, p->w->actroom, p->pl);
    ph_change_room(p, p->w->actroom);
    p->b->y = 128;
    p->t->script_target_cycle = 0;
    p->t->acycle = p->t->target_cycle = 0;

    return p;
}


void ph_draw_marc(PROGRAM *p) {
    /* Dibujar el marcador de vida, la caja fuerte y el tesoro */
    if (p->w->actroom != 7) {
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0A_BMP].dat, (X_DESP - 18) / 2,
                    (Y_DESP - 18) / 2);
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0B_BMP].dat, (X_DESP - 18) / 2,
                    (Y_DESP + 290) / 2);
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0C_BMP].dat, (X_DESP - 18) / 2,
                    (Y_DESP - 2) / 2);
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0D_BMP].dat, (482 + X_DESP) / 2,
                    (Y_DESP - 2) / 2);

        if (p->pl->safe)
            draw_sprite(p->gfx->virt[0], p->gfx->marc2, (X_DESP + 6) / 2, (314 + Y_DESP) / 2);
        if (p->pl->treasure)
            draw_sprite(p->gfx->virt[0], p->gfx->marc1, (X_DESP - 18) / 2, (314 + Y_DESP) / 2);
        if (p->pl->pressed_switches == SWITCHES_TO_OPEN_SAFE)
            draw_sprite(p->gfx->virt[0], p->gfx->marc3, (X_DESP + 30) / 2, (314 + Y_DESP) / 2);

        textprintf_ex(p->gfx->virt[0], p->fnt->ufnt, ((X_DESP + 55) / 2), ((316 + Y_DESP) / 2), makecol(200, 200, 200),
                      -1, "%d", p->pl->pressed_switches);
        textprintf_ex(p->gfx->virt[0], p->fnt->ufnt, ((X_DESP + 56) / 2), ((316 + Y_DESP) / 2), makecol(200, 200, 200),
                      -1, "%d", p->pl->pressed_switches);

        if (p->pl->energy < 238) {
            set_trans_blender(127, 127, 127, 127);
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            rectfill(p->gfx->virt[0], (494 + X_DESP) / 2, (318 + Y_DESP) / 2,
                     ((494 + X_DESP) / 2) - ((238 - p->pl->energy) / 2), (333 + Y_DESP) / 2, makecol(24, 24, 24));
            set_trans_blender(255, 255, 255, 255);
            drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
        }
    } else {
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0E_BMP].dat, (X_DESP - 16) / 2,
                    (Y_DESP - 16) / 2);
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0F_BMP].dat, (X_DESP - 16) / 2,
                    (288 + Y_DESP) / 2);
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0G_BMP].dat, (X_DESP - 16) / 2,
                    Y_DESP / 2);
        draw_sprite(p->gfx->virt[0], (BITMAP *) p->data->dgfx[PHANTGFX_DAT_MISCMARC0H_BMP].dat, (480 + X_DESP) / 2,
                    Y_DESP / 2);
    }
}


void ph_do_sp_speccy(int x, int y, BITMAP *pieces[], PROGRAM *p) {
    char a = 0;
    char anim = 0;
    int spcol[8];
    int i, b = 0;
    signed int j = 256;
    char inc;
    signed short int xp[16][16];
    signed short int yp[16][16];
    signed short int xmov[16][16];
    signed short int ymov[16][16];
    static int c = 0;

    BITMAP *virt = create_bitmap(320, 240);
    clear(virt);
    spcol[0] = makecol(0, 0, 0);
    spcol[1] = makecol(192, 0, 0);
    spcol[2] = makecol(0, 192, 0);
    spcol[3] = makecol(0, 0, 192);
    spcol[4] = makecol(192, 192, 0);
    spcol[5] = makecol(192, 0, 192);
    spcol[6] = makecol(0, 192, 192);
    spcol[7] = makecol(192, 192, 192);

    for (b = 0; b < 16; b++) {
        for (i = 0; i < 16; i++) {
            xp[i][b] = (x + (i * 2) + X_DESP) / 2;
            yp[i][b] = (y + (b * 2) + Y_DESP) / 2;
            xmov[i][b] = (rand() % 3) + 1;
            ymov[i][b] = (rand() % 3) + 1;
            if (rand() % 2) xmov[i][b] *= -1;
            if (rand() % 2) ymov[i][b] *= -1;
        }
    }

    for (inc = 0; inc < 3; inc++) {
        anim = 0;
        while (anim < 7) {
            set_trans_blender(255, 255, 255, 255);
            drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
            ph_draw_marc(p);
            draw_sprite(virt, p->gfx->virt[0], 0, 0);
            if (c) j = 256 - ((256 * c) / 21);
            set_trans_blender(j, j, j, j);

            for (b = 0; b < 16; b++) {
                for (i = 0; i < 16; i++) {

                    draw_trans_sprite(virt, pieces[i + (16 * b)], (xp[i][b]), (yp[i][b]));
                    xp[i][b] += xmov[i][b];
                    yp[i][b] += ymov[i][b];
                }
            }

            set_trans_blender(60, 60, 60, 60);
            drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
            rectfill(virt, 80 / 2, 68 / 2, (480 + 79) / 2, (288 + 75 - 8) / 2, spcol[(int) a]);
            a++;
            if (a == 8) a = 0;
            acquire_screen();
            stretch_blit(virt, screen, 0, 0, 320, 240, 0, 0, SCREEN_W, SCREEN_H);
            release_screen();
            anim++;
            c++;
            vsync();
            rest(25);
        }
    }
    c = 0;
    set_trans_blender(255, 255, 255, 255);
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
    destroy_bitmap(virt);
}
