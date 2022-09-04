/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include "config.h"
#include <allegro.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "control.h"
#include "control2.h"
#include "log.h"
#include "trans.h"
#include "cfg.h"
#include "texter.h"
#include "menu2.h"
#include "game.h"
#include "phantom1.h"
#include "sfx.h"

volatile int close_button_pressed = 0;

CONTROL *ph_init_control(CFG *cfg) {
    ph_log(_("- Initiating control: "));
    CONTROL *aux = (struct CONTROL *) malloc(sizeof(struct CONTROL));
    if (aux == NULL) {
        ph_log_memory_error((char *) "control.c", (char *) "ph_init_control", (char *) "aux", sizeof(struct CONTROL));
    }
    memset(aux, 0, sizeof(struct CONTROL));
    ph_log(_("Ok.\n"));

#ifndef DOS
#ifndef GP2X
    LOCK_FUNCTION(close_button_handler)
    set_close_button_callback(close_button_handler);
#endif
#endif

    if (!cfg->controltype) aux->type = CTRL_TYPE_KEYBOARD; else aux->type = CTRL_TYPE_JOYSTICK;

    aux->key[MOVE_UP] = cfg->key_up;
    aux->key[MOVE_DOWN] = cfg->key_down;
    aux->key[MOVE_LEFT] = cfg->key_left;
    aux->key[MOVE_RIGHT] = cfg->key_right;
    aux->key[MOVE_ACT1] = KEY_Y;
    aux->key[MOVE_ACT2] = KEY_U;
    aux->key[MOVE_ACT3] = KEY_I;
    aux->key[MOVE_ACT4] = KEY_O;

    return aux;
}


void ph_destroy_control(CONTROL *c) {
    free(c);
}


CONTROL *ph_read_control_in_ball(PROGRAM *p, CONTROL *c) {
    static char pressed = 0;

    if (p->pl->inball) {
#ifndef GP2X
        if (c->type == CTRL_TYPE_KEYBOARD) {
            poll_keyboard();
            if (key[(int) c->key[MOVE_LEFT]] && !key[(int) c->key[MOVE_RIGHT]] && pressed) {
#ifdef WIN32
                p->pl->ballspeed+=4;
#endif
#ifdef DOS
                p->pl->ballspeed+=16;
#endif
#ifdef MAC
                p->pl->ballspeed+=4;
#endif
#ifdef LINUX
                p->pl->ballspeed+=4;
#endif
                pressed = 0;
            }
            if (key[(int) c->key[MOVE_RIGHT]] && !key[(int) c->key[MOVE_LEFT]] && !pressed) {
#ifdef WIN32
                p->pl->ballspeed+=4;
#endif
#ifdef DOS
                p->pl->ballspeed+=16;
#endif
#ifdef MAC
                p->pl->ballspeed+=4;
#endif
#ifdef LINUX
                p->pl->ballspeed+=4;
#endif
                pressed = 1;
            }
        }
        if (c->type == CTRL_TYPE_JOYSTICK) {
            poll_joystick();
            if (joy[0].button[0].b && !joy[0].button[1].b && pressed) {
#ifdef WIN32
                p->pl->ballspeed+=4;
#endif
#ifdef DOS
                p->pl->ballspeed+=16;
#endif
#ifdef MAC
                p->pl->ballspeed+=4;
#endif
#ifdef LINUX
                p->pl->ballspeed+=4;
#endif
                pressed = 0;
            }
            if (joy[0].button[1].b && !joy[0].button[0].b && !pressed) {
#ifdef WIN32
                p->pl->ballspeed+=4;
#endif
#ifdef DOS
                p->pl->ballspeed+=16;
#endif
#ifdef MAC
                p->pl->ballspeed+=4;
#endif
#ifdef LINUX
                p->pl->ballspeed+=4;
#endif
                pressed = 1;
            }
        }
#else
        poll_joystick();
        if (joy[0].button[0].b && !pressed) {
            pressed=1;
            p->pl->ballspeed+=6;
        }
        if (!joy[0].button[0].b && pressed) {
            pressed=0;
            p->pl->ballspeed+=6;
        }
#endif
        p->pl->ballspeed--;
        p->pl->x = itofix(p->pl->ballspeed);
        p->pl->aniframe = (fixadd(p->pl->aniframe, itofix(1)));
        if (fixtoi(p->pl->aniframe) >= 4) p->pl->aniframe = itofix(0);
    }

    return c;
}


CONTROL *ph_read_control(PROGRAM *p, CONTROL *c, TMENU *menu, PHFONT *font) {
    if (menu->showmenu) return c;
    c->up = 0;
    c->down = 0;
    c->left = 0;
    c->right = 0;
    for (char i = 0; i < MAXACTIONKEYS; i++) c->action[(int) i] = 0;
    if (!p->pl->inball) {
        switch (c->type) {
            case CTRL_TYPE_KEYBOARD:
                if (!p->pl->inchopper || !p->pl->inrocket) {
                    poll_keyboard();
                    if (key[(int) c->key[MOVE_UP]]) c->up = 1;
                    if (key[(int) c->key[MOVE_DOWN]]) c->down = 1;
                    if (key[(int) c->key[MOVE_LEFT]]) c->left = 1;
                    if (key[(int) c->key[MOVE_RIGHT]]) c->right = 1;
                    if (key[(int) c->key[MOVE_ACT1]]) c->action[0] = 1;
                    if (key[(int) c->key[MOVE_ACT2]]) c->action[1] = 1;
                    if (key[(int) c->key[MOVE_ACT3]]) c->action[2] = 1;
                    if (key[(int) c->key[MOVE_ACT4]]) c->action[3] = 1;
                }
                break;

            case CTRL_TYPE_JOYSTICK:

                if (!p->pl->inchopper || !p->pl->inrocket || !p->pl->inball) {
                    poll_joystick();
                    if (joy[0].stick[0].axis[0].d1) c->left = 1;
                    if (joy[0].stick[0].axis[0].d2) c->right = 1;

#ifdef GP2X
                    if (joy[0].button[5].b) c->left=1;
                    if (joy[0].button[4].b) c->right=1;
#endif

                    if (joy[0].button[0].b) c->up = 1;
                    if (joy[0].button[1].b) c->down = 1;
                }
                break;

            default:

                break;
        }
    }

    ph_read_common_keys(p, c, menu, font);

    return c;
}


CONTROL *ph_init_joystick(CONTROL *c) {
    ph_log(_("- Initiating joystick: "));
    unsigned char res = install_joystick(JOY_TYPE_AUTODETECT);
    if (res || !num_joysticks) {
        ph_log(_("Error.\n"));
        c->type = CTRL_TYPE_KEYBOARD;
        return c;
    } else {
        ph_log(_("Ok.\n"));
    }
    c->type = CTRL_TYPE_JOYSTICK;
    return c;
}


#ifndef DOS
#ifndef GP2X

void close_button_handler(void) {
    close_button_pressed = 1;
}


END_OF_FUNCTION(close_button_handler)
#endif
#endif

void *ph_read_common_keys(PROGRAM *p, CONTROL *c, TMENU *menu, PHFONT *font) {
    int driver;
    int olddriver;

#ifdef GP2X
    poll_joystick();
    if (joy[0].button[6].b && joy[0].button[7].b) {
        // Say bye!
        ph_destroy_program(p);
        exit(0);
    }
#endif
    poll_keyboard();

    if (key[KEY_F9] && !c->key_press) {
        if (c->type == CTRL_TYPE_KEYBOARD) {
            ph_init_joystick(c);
            c->key_press = 250;
        }
        c->key_event = 2;
    }
    if (key[KEY_F9] && !c->key_press) {
        if (c->type == CTRL_TYPE_JOYSTICK) {
            c->type = CTRL_TYPE_KEYBOARD;
            c->key_press = 250;
        }
        c->key_event = 2;
    }

    if (key[KEY_F8]) {
        ph_play_sample(p->snd->sfx->menubegin, 320 >> 1, p->cfg);
        ph_draw_text_box(p->gfx, p->cfg);
        ph_redefine_keys(p);
        ph_play_sample(p->snd->sfx->menuend, 320 >> 1, p->cfg);

    }

    if (key[KEY_F10] && !c->key_press) {
        p->cfg->surround ^= 1;
        c->key_press = 250;
        c->key_event = 3;
    }

    if (c->key_press) c->key_press--;

    if ((key[KEY_LCONTROL] && key[KEY_Q]) || (key[KEY_RCONTROL] && key[KEY_Q]) || (key[KEY_ALT] && key[KEY_F4])) {
        ph_destroy_program(p);
        exit(0);
    }
    if (close_button_pressed) {
        ph_destroy_program(p);
        exit(0);
    }

    if (key[KEY_ALT] && key[KEY_ENTER]) {
        p->cfg->fullscreen ^= 1;
        if (p->cfg->fullscreen) {
            olddriver = driver = GFX_AUTODETECT;
        } else {
            olddriver = driver = GFX_AUTODETECT_WINDOWED;
        }
        ph_log(_("- Changing the graphic mode: "));

        if (!p->cfg->stretch) {
            if (!set_gfx_mode(driver, p->cfg->xres, p->cfg->yres, 0, 0)) {
                ph_log(_("Ok.\n"));
            } else {
                ph_log(_("Error. Returning to previous graphic mode: "));
                if (set_gfx_mode(olddriver, p->cfg->xres, p->cfg->yres, 0, 0)) {
                    ph_log(_("Error, aborting program...\n"));
                } else {
                    ph_log(_("Ok.\n"));
                }
            }
        } else {
            if (set_gfx_mode(driver, p->cfg->stretchx, p->cfg->stretchy, 0, 0)) {
                set_gfx_mode(olddriver, p->cfg->stretchx, p->cfg->stretchy, 0, 0);
            }
        }

        if (olddriver == GFX_AUTODETECT_WINDOWED) set_window_title(_("Phantomas PC 1.3"));

    }

    if (menu->showmenu) {
        poll_keyboard();
        if (key[KEY_UP]) {
            ph_play_sample(p->snd->sfx->click, 320 >> 1, p->cfg);
            menu->actelement--;
            if (menu->actelement < 0) menu->actelement = menu->elements - 1;
            rest(50);
        }

        if (key[KEY_DOWN]) {
            ph_play_sample(p->snd->sfx->click, 320 >> 1, p->cfg);
            menu->actelement++;
            if (menu->actelement >= menu->elements) menu->actelement = 0;
            rest(50);
        }

        if (key[KEY_ENTER]) {
            ph_play_sample(p->snd->sfx->clock, 320 >> 1, p->cfg);
            menu->activemenu = menu->linknext[(int) menu->actelement];
            menu->actelement = 0;
            ph_set_menu_options(font, menu);
            rest(200);
        }

        poll_joystick();
        if (joy[0].stick[0].axis[1].d1) {
            ph_play_sample(p->snd->sfx->click, 320 >> 1, p->cfg);
            menu->actelement--;
            if (menu->actelement < 0) menu->actelement = menu->elements - 1;
            rest(50);
        }

        if (joy[0].stick[0].axis[1].d2) {
            ph_play_sample(p->snd->sfx->click, 320 >> 1, p->cfg);
            menu->actelement++;
            if (menu->actelement >= menu->elements) menu->actelement = 0;
            rest(50);
        }

        if (joy[0].button[0].b || joy[0].button[1].b) {
            ph_play_sample(p->snd->sfx->clock, 320 >> 1, p->cfg);
            menu->activemenu = menu->linknext[(int) menu->actelement];
            menu->actelement = 0;
            ph_set_menu_options(font, menu);
            rest(200);
        }
    } else {
        poll_keyboard();
        if (key[KEY_ESC] && p->t->acycle > 0) {
            ph_play_sample(p->snd->sfx->menubegin, 320 >> 1, p->cfg);

            if (p->cfg->enable_sound && p->cfg->sfx) {
                stop_sample(p->snd->sfx->radar);
                stop_sample(p->snd->sfx->hell);
                stop_sample(p->snd->sfx->bubbles);
            }

            if (p->cfg->enable_sound && p->cfg->sfx) {
                stop_sample(p->snd->sfx->radar);
                stop_sample(p->snd->sfx->hell);
                stop_sample(p->snd->sfx->bubbles);
            }
            ph_return_game_menu(p);
            ph_play_sample(p->snd->sfx->menuend, 320 >> 1, p->cfg);
        }
#ifdef GP2X
        poll_joystick();
        if (joy[0].button[4].b && joy[0].button[5].b && p->t->acycle>0) {
            ph_play_sample(p->snd->sfx->menubegin,320>>1,p->cfg);
            ph_return_game_menu(p);
            ph_play_sample(p->snd->sfx->menuend,320>>1,p->cfg);
        }
#endif

        if (key[KEY_F12]) ph_take_snapshot();
    }
    return NULL;
}


void ph_take_snapshot(void) {
    PALETTE pal;
    snap_cback cb = &ph_snapshot_callback;
    int shots = for_each_file_ex("snapshot*.bmp", 0, 0, cb, NULL);
    char *name = (char *) malloc(sizeof(char) * 512);
    memset(name, 0, sizeof(char) * 512);
    sprintf(name, "snapshot%d.bmp", shots);
    get_palette(pal);
    BITMAP *bmp = screen;
    save_bitmap(name, bmp, pal);
}


int ph_snapshot_callback(const char *filename, int attrib, void *param) {
    return 0;
}


void ph_redefine_keys(PROGRAM *p) {
    const char *action[] = {_("High jump"), _("Long jump"), _("Left"), _("Right")};
    char act = 0;
    char redkey[4];

    BITMAP *bmp = create_bitmap(p->gfx->virt[0]->w, p->gfx->virt[0]->h);
    clear_to_color(bmp, makecol(0, 0, 0));
    ph_set_text_properties(p->fnt, makecol(255, 255, 0), -1, TXT_TITLE, TXT_CENTER, 1);
    ph_shprintf(p->gfx->virt[0], p->fnt, 160, 100, _("Redefine keys"));
    clear_keybuf();
    blit(p->gfx->virt[0], bmp, 0, 0, 0, 0, bmp->w, bmp->h);

    while (act < 4) {
        draw_sprite(p->gfx->virt[0], bmp, 0, 0);
        ph_set_text_properties(p->fnt, makecol(255, 255, 255), -1, TXT_TITLE, TXT_CENTER, 1);
        ph_shprintf(p->gfx->virt[0], p->fnt, 160, 115, _("Press a key for %s"), action[(int) act]);

        ph_draw(p->gfx, p->cfg);

        clear_keybuf();
        poll_keyboard();
        while (!keypressed()) {
        }
        redkey[(int) act] = readkey() >> 8;
        clear_keybuf();

        ph_shprintf(p->gfx->virt[0], p->fnt, 160, 130, (char *) "%s", scancode_to_name(redkey[(int) act]));
        ph_draw(p->gfx, p->cfg);
        rest(100);
        act++;
    }

    for (int i = 0; i < 4; i++) {
        p->c->key[(int) i] = redkey[(int) i];
    }

    destroy_bitmap(bmp);
    p->cfg->key_up = p->c->key[0];
    p->cfg->key_down = p->c->key[1];
    p->cfg->key_left = p->c->key[2];
    p->cfg->key_right = p->c->key[3];
    p->cfg->controltype = 0;
    p->c->type = CTRL_TYPE_KEYBOARD;
    p->t->acycle = p->t->target_cycle = 0;
}


void ph_return_game_menu(PROGRAM *p) {
    char *res[2] = {_("Yes"), _("No")};
    ph_draw_text_box(p->gfx, p->cfg);
    ph_set_text_properties(p->fnt, makecol(255, 255, 0), -1, TXT_TITLE, TXT_CENTER, 1);
    ph_shprintf(p->gfx->virt[0], p->fnt, (240 + X_DESP) / 2, (120 + Y_DESP) / 2, _("Return to the game menu"));
    ph_set_text_properties(p->fnt, makecol(255, 255, 255), -1, TXT_TITLE, TXT_CENTER, 1);
#ifndef GP2X
    ph_shprintf(p->gfx->virt[0], p->fnt, (240 + X_DESP) / 2, (150 + Y_DESP) / 2,
                _("Are you sure you want to restart the game? %s/%s"), res[0], res[1]);
#else
    ph_shprintf(p->gfx->virt[0],p->fnt,(240+X_DESP)/2,(150+Y_DESP)/2,_("Are you sure you want to restart the game?"));
    ph_shprintf(p->gfx->virt[0],p->fnt,(240+X_DESP)/2,(174+Y_DESP)/2,_("A - Yes, Y - No"));
#endif
    ph_draw(p->gfx, p->cfg);
    char ok = ph_ascii_to_scancode(*res[0]);
    char cancel = ph_ascii_to_scancode(*res[1]);

    while (1) {
#ifndef GP2X
        if (p->cfg->controltype == CTRL_TYPE_KEYBOARD) {
            poll_keyboard();
            if (key[(int) cancel]) {
                break;
            }
            if (key[(int) ok]) {
                if (p->cfg->enable_sound && p->cfg->sfx) {
                    stop_sample(p->snd->sfx->radar);
                    stop_sample(p->snd->sfx->hell);
                    stop_sample(p->snd->sfx->bubbles);
                }
#ifdef HAVE_ALOGG_H
                if (p->cfg->enable_sound && p->cfg->music) {
                    stop_sample(p->snd->music->ogg2);
                }
#endif
                p->t->target_cycle = p->t->acycle = 0;
                p->menu->activemenu = 0;
                p->menu->elements = 4;
                p->menu->actelement = 0;
                p->menu->showmenu = 1;
                ph_set_menu_defaults(p->menu);
                ph_set_menu_options(p->fnt, p->menu);
                ph_reset_data(p);
                ph_do_menu1(p);
                ph_start_game(p);
                break;
            }
        }
#else
        poll_joystick();
        if (joy[0].button[2].b) {
            break;
        }
        if (joy[0].button[3].b) {
            /* Fuera musica *//*
			#ifdef HAVE_ALOGG_H
			if (p->cfg->enable_sound && p->cfg->music)
			{
			stop_sample(p->snd->music->ogg2);
			}
			#endif*/
            p->t->target_cycle=p->t->acycle=0;
            p->menu->activemenu=0;
            p->menu->elements=4;
            p->menu->actelement=0;
            p->menu->showmenu=1;
            ph_set_menu_defaults(p->menu);
            ph_set_menu_options(p->fnt,p->menu);
            ph_reset_data(p);
            ph_do_menu1(p);
            ph_start_game(p);
            break;
        }
#endif
    }

    clear_keybuf();
    p->t->acycle = p->t->target_cycle = 0;
}


char ph_ascii_to_scancode(char ascii) {
    unsigned char res;
    ascii = tolower(ascii);
    res = ascii - 96;
    return res;
}
