#include "trans.h"
#include "menu2.h"
#include "fades.h"
#include "phantom1.h"

void ph_do_menu1(PROGRAM *p) {
#ifdef HAVE_ALOGG_H
    char freq = 0;
    int voice = 0;
    TFPO funcpointer;
#endif

    char *cmsg[21] = {_("Original game made by Enric Cervera."), _("Original game distributed by Dinamic Software."),
                      _("Remake made by the following people:"), _("Program: Traperic."),
                      _("Graphics: Na_th_an and Traperic."), _("Music: Addax."), _("SFX: Traperic."),
                      _("Mac port: The Evangelist."), _("MS-Dos, Windows and GP2X ports: Traperic."), _("Thanks to:"),
                      _("Miguel Angel Jimenez (M.A. Software)"), _("Popolon (Brain Games)"), _("David Gonzalez"),
                      _("ParkyDR"), _("Special thanks to:"), _("Enric Cervera for beginning the legend."),
                      _("And to everybody who has get interest in this game."), _("Enjoy with Phantomas!")};

    BITMAP *cpink;
    BITMAP *cpieces[13];
    int ci = 0;
    int page = 0;
    int ani = 0;
    int ani2 = 0;
    BITMAP *bmp;
    int sppress = 0;
    int step = 0;
    int ca = 0;
    int csubx = 0;
    int cx = 0;
    if (p->cfg->enable_sound && p->cfg->sfx) {
        stop_sample(p->snd->sfx->radar);
        stop_sample(p->snd->sfx->hell);
        stop_sample(p->snd->sfx->bubbles);
    }
#ifdef HAVE_ALOGG_H
    funcpointer = ph_menu_target_incrementor;
    LOCK_FUNCTION(ph_menu_target_incrementor);
    install_param_int_ex(funcpointer, p->t, BPS_TO_TIMER(12 + (freq * 3)));
#endif
    bmp = create_bitmap(320, 240);
    clear(bmp);
    p->t->menu_target_cycle = p->t->acycle = 0;

    cpink = create_bitmap(320, 13);
    clear_to_color(cpink, makecol(255, 0, 255));

    /* Poner el primer texto en las piezas */
    ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
    ph_text(cpink, p->fnt, 320 / 2, 0, cmsg[0]);
    for (ci = 0; ci < 13; ci++) cpieces[ci] = create_bitmap(320, 1);
    for (ci = 0; ci < 13; ci++) clear(cpieces[ci]);
    for (ci = 0; ci < 13; ci++) {
        blit(cpink, cpieces[ci], 0, ci, 0, 0, 320, 1);
    }

    if (p->cfg->enable_sound && p->cfg->music) {
#ifdef HAVE_ALOGG_H
        voice = play_sample(p->snd->music->ogg3, p->cfg->musicvolume, 127, 1000, 0);
#endif
    }

    while (1) {
        poll_joystick();
        if (joy[0].button[7].b) {
            if (!step) {
#ifdef HAVE_ALOGG_H
                remove_param_int(funcpointer, p->t);
#endif
            }
            break;
            break;
        }
        if (joy[0].button[6].b) {
            sppress = 1;
        }
        if (joy[0].button[6].b && joy[0].button[7].b) {
            ph_destroy_program(p);
            exit(0);
        }
        if (joy[0].button[0].b && sppress) {
            ph_play_sample(p->snd->sfx->clock, 160, p->cfg);
            sppress = 0;
        }

        if (joy[0].stick[0].axis[0].d1 && page > 0 && ani2 > 5 && sppress) {
            ph_play_sample(p->snd->sfx->click, 160, p->cfg);
            ani2 = 0;
            page--;
        }
#ifndef GP2X
        if (joy[0].stick[0].axis[0].d2 && page < 4 && ani2 > 5 && sppress)
#else
            if (joy[0].stick[0].axis[0].d2 && page<2 && ani2>5 && sppress)
#endif
        {
            ph_play_sample(p->snd->sfx->click, 160, p->cfg);
            ani2 = 0;
            page++;
        }

        poll_keyboard();
        if ((key[KEY_LCONTROL] && key[KEY_Q]) || (key[KEY_RCONTROL] && key[KEY_Q]) || (key[KEY_ALT] && key[KEY_F4])) {
            ph_destroy_program(p);
            exit(0);
        }
        if (key[KEY_ENTER]) {
            if (!step) {
#ifdef HAVE_ALOGG_H
                remove_param_int(funcpointer, p->t);
#endif
            }
            break;
        }
        if (key[KEY_ESC] && sppress) {
            ph_play_sample(p->snd->sfx->clock, 160, p->cfg);
            sppress = 0;
        }
        if (key[KEY_SPACE]) {
            sppress = 1;
        }
        if (key[KEY_LEFT] && page > 0 && ani2 > 5 && sppress) {
            ph_play_sample(p->snd->sfx->click, 160, p->cfg);
            ani2 = 0;
            page--;
        }
        if (key[KEY_RIGHT] && page < 4 && ani2 > 5 && sppress) {
            ph_play_sample(p->snd->sfx->click, 160, p->cfg);
            ani2 = 0;
            page++;
        }
        /* Logica */
#ifdef HAVE_ALOGG_H
        while (p->t->menu_target_cycle > p->t->acycle)
#else
            while(p->t->target_cycle>p->t->acycle)
#endif
        {
            ani++;
            if (ani == 5) ani = 0;
            ani2++;

            /* Logica de animacion creditos */
            cx += 20;
            if (cx >= 320) {
                csubx = 1;
            }
            if (cx == 700) {
                csubx = 0;
                cx = 0;
                ca++;
                if (ca == 18) ca = 0;
                ph_set_text_properties(p->fnt, makecol(250, 250, 250), -1, TXT_TITLE, TXT_CENTER, 1);
                clear_to_color(cpink, makecol(255, 0, 255));
                ph_text(cpink, p->fnt, cpink->w >> 1, 0, cmsg[ca]);
                for (ci = 0; ci < 13; ci++) {
                    blit(cpink, cpieces[ci], 0, ci, 0, 0, 320, 1);
                }
            }
#ifdef HAVE_ALOGG_H
            if (voice_check(voice) == NULL) {
                step = 1;
                freq++;
                if (freq == 4) freq = 0;
                if (p->cfg->enable_sound && p->cfg->music)
                    voice = play_sample(p->snd->music->ogg3, p->cfg->musicvolume, 128, 1000 + (50 * freq), 0);
                remove_param_int(funcpointer, p->t);
                install_param_int_ex(funcpointer, p->t, BPS_TO_TIMER(12 + (freq * 3)));
            }
#endif
            p->t->acycle++;
        }

        draw_sprite(bmp, p->gfx->tr2x, 0, 0);

        if (!sppress) {
            draw_sprite(bmp, p->gfx->logo[ani], (160 - (p->gfx->logo[ani]->w >> 1)), 35);

            /* Dibujar los creditos */
            if (cx <= 320) set_trans_blender(0, 0, 0, ((255 * cx) / 320) >> 1);
            if (cx > 320) set_trans_blender(0, 0, 0, 255 - ((255 * cx) / 700));

            for (ci = 0; ci < 13; ci++) {
                if (ci % 2) {
                    if (csubx)
                        draw_trans_sprite(bmp, cpieces[ci], 0, 195 + ci);
                    else
                        draw_trans_sprite(bmp, cpieces[ci], -320 + cx, 195 + ci);
                } else {
                    if (csubx)
                        draw_trans_sprite(bmp, cpieces[ci], 0, 195 + ci);
                    else
                        draw_trans_sprite(bmp, cpieces[ci], 320 - cx, 195 + ci);
                }
            }

            if (ani % 2) ph_set_text_properties(p->fnt, makecol(250, 250, 0), -1, TXT_TITLE, TXT_CENTER, 1);
            else ph_set_text_properties(p->fnt, makecol(250, 0, 0), -1, TXT_TITLE, TXT_CENTER, 1);
#ifndef GP2X
            ph_text(bmp, p->fnt, 320 / 2, 120, _("PRESS ENTER TO PLAY!"));
#else
            ph_text(bmp,p->fnt,320/2,120,_("PRESS START TO PLAY!"));
#endif
            if (!(ani % 2)) ph_set_text_properties(p->fnt, makecol(250, 250, 0), -1, TXT_TITLE, TXT_CENTER, 1);
            else ph_set_text_properties(p->fnt, makecol(250, 0, 0), -1, TXT_TITLE, TXT_CENTER, 1);
#ifndef GP2X
            ph_text(bmp, p->fnt, 320 / 2, 135, _("PRESS SPACE TO SHOW THE HELP"));
#else
            ph_text(bmp,p->fnt,320/2,135,_("PRESS SELECT TO SHOW THE HELP"));
#endif
            ph_set_text_properties(p->fnt, makecol(75, 75, 75), -1, TXT_TITLE, TXT_CENTER, 1);
#ifndef GP2X
            ph_text(bmp, p->fnt, 320 / 2, 150, _("PRESS CONTROL+Q TO QUIT"));
#else
            ph_text(bmp,p->fnt,320/2,150,_("PRESS SELECT+START TO QUIT"));
#endif
        } else {
            ph_show_menu_page(p, page, bmp);
        }
        if (p->cfg->stretch) {
            stretch_blit(bmp, screen, 0, 0, 320, 240, 0, 0, p->cfg->stretchx, p->cfg->stretchy);
        } else {
            blit(bmp, screen, 0, 0, 0, 0, 320, 240);
        }
        rest(1);
    }

    if (p->cfg->enable_sound && p->cfg->music)
#ifdef HAVE_ALOGG_H
        voice_ramp_volume(voice, 1000, 0);
#endif
    rest(500);

    destroy_bitmap(bmp);
    destroy_bitmap(cpink);
    for (ci = 0; ci < 13; ci++) destroy_bitmap(cpieces[ci]);
}


void ph_menu_target_incrementor(void *t) {
    TIMER *aux;

    aux = (TIMER *) t;
    aux->menu_target_cycle++;
}


END_OF_FUNCTION(ph_menu_target_incrementor)

void ph_show_menu_page(PROGRAM *p, char page, BITMAP *bmp) {
    ph_set_text_properties(p->fnt, makecol(255, 255, 0), -1, TXT_TITLE, TXT_CENTER, 1);

    switch (page) {
        case 0:
            ph_shprintf(bmp, p->fnt, 320 / 2, 65, _("Instructions %d/3"), page + 1);
            break;
        case 1:
            ph_shprintf(bmp, p->fnt, 320 / 2, 65, _("Instructions %d/3"), page + 1);
            break;
        case 2:
            ph_shprintf(bmp, p->fnt, 320 / 2, 65, _("Instructions %d/3"), page + 1);
            break;
        case 3:
            ph_shprintf(bmp, p->fnt, 320 / 2, 65, _("Keyboard shortcuts 1/2"));
            break;
        case 4:
            ph_shprintf(bmp, p->fnt, 320 / 2, 65, _("Keyboard shortcuts 2/2"));
            break;
    }
    ph_set_text_properties(p->fnt, makecol(255, 255, 255), -1, TXT_TITLE, TXT_CENTER, 1);

    switch (page) {
        case 0:
            draw_sprite(bmp, p->gfx->swspr[0], 310 / 2, 110);
            draw_sprite(bmp, p->gfx->decspr[22], 310 / 2, 140);
            draw_sprite(bmp, p->gfx->decspr[80], 310 / 2, 170);
            ph_shprintf(bmp, p->fnt, 320 / 2, 95, _("First of all, you have to press all the switches!."));
            ph_shprintf(bmp, p->fnt, 320 / 2, 125, _("When done, go for the safe."));
            ph_shprintf(bmp, p->fnt, 320 / 2, 157, _("After that, take the treasure!"));
            ph_shprintf(bmp, p->fnt, 320 / 2, 189, _("And then run to the exit!!!... sounds easy, doesn't it?"));

            break;
        case 1:
            draw_sprite(bmp, (BITMAP *) p->data->dgfx[PHANTGFX_DAT_ENE13_0_0_BMP].dat, 310 / 2, 250 / 2);
            ph_text(bmp, p->fnt, 320 / 2, 95, _("Unfortunately, there are some 'things' that won't"));
            ph_printf(bmp, p->fnt, 320 / 2, 110, _("let your journey to be a pleasant trip."));
            ph_printf(bmp, p->fnt, 320 / 2, 140, _("Like this for example, say hello to Peposo beard."));
            ph_printf(bmp, p->fnt, 320 / 2, 155, _("Don't trust him with that angelical face!"));
            ph_printf(bmp, p->fnt, 320 / 2, 170, _("He and the others will drain your energy!"));
            break;
        case 2:
            draw_sprite(bmp, p->gfx->lifespr[0], 310 / 2, 112);
            ph_text(bmp, p->fnt, 320 / 2, 95, _("You can use the energy capsules to recover some energy."));
            ph_text(bmp, p->fnt, 320 / 2, 125, _("And use your high and long jump to avoid enemies."));
            ph_text(bmp, p->fnt, 320 / 2, 140, _("This is all you have to know to play."));
            break;
        case 3:
            ph_text(bmp, p->fnt, 320 / 2, 95, _("Alt+Enter -> Fullscreen / Windowed mode."));
            ph_text(bmp, p->fnt, 320 / 2, 110, _("ESC -> Return to the main menu."));
            ph_text(bmp, p->fnt, 320 / 2, 125, _("+ / - -> Sfx volume up and down."));
            ph_text(bmp, p->fnt, 320 / 2, 140, _("Pg.up / pg.dwn -> Music volume up and down."));
            ph_text(bmp, p->fnt, 320 / 2, 155, _("F8 -> Redefine keys."));
            ph_text(bmp, p->fnt, 320 / 2, 170, _("F9 -> Change control type."));
            ph_text(bmp, p->fnt, 320 / 2, 185, _("F10 -> Surround effect."));
            break;
        case 4:
            ph_text(bmp, p->fnt, 320 / 2, 95, _("F12 -> Take snapshot."));
            ph_text(bmp, p->fnt, 320 / 2, 110, _("Control+Q -> Finish the game."));
            break;
    }
}
