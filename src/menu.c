#include <string.h>
#include "menu.h"
#include "mouse.h"
#include "log.h"
#include "trans.h"

TMENU *ph_init_menu() {
    int i = 0;
    ph_log(_("- Initiating menu: "));
    TMENU *aux = (struct TMENU *) malloc(sizeof(struct TMENU));
    if (aux == NULL) {
        ph_log(_("Error.\n"));
        ph_log_memory_error((char *) "menu.c", (char *) "ph_init_menu", (char *) "aux", sizeof(struct TMENU));
    } else {
        ph_log(_("Ok.\n"));
    }

    memset(aux, 0, sizeof(struct TMENU));

    for (i = 0; i < MAXELEMENTS; i++) {
        aux->msg[i] = (char *) malloc(sizeof(char) * 512);
        if (aux->msg[i] == NULL) {
            ph_log_memory_error((char *) "menu.c", (char *) "ph_init_menu", (char *) "msg", sizeof(char) * 512);
        }
        memset(aux->msg[i], 0, sizeof(char) * 512);
        strcpy(aux->msg[i], "m");
    }

    aux->title = (char *) malloc(sizeof(char) * 1024);
    if (aux->title == NULL) {
        ph_log_memory_error((char *) "menu.c", (char *) "ph_init_menu", (char *) "title", sizeof(char) * 1024);
    }
    memset(aux->title, 0, sizeof(char) * 1024);

    ph_set_menu_defaults(aux);
    return aux;
}


void ph_destroy_menu(TMENU *tmenu) {
    int i;

    for (i = 0; i < MAXELEMENTS; i++) free(tmenu->msg[i]);
    free(tmenu->title);
    free(tmenu);
}


void ph_set_menu_defaults(TMENU *tmenu) {
    tmenu->showmenu = 1;
    tmenu->activemenu = MAIN_MENU;
}


void ph_set_menu_options(PHFONT *font, TMENU *tmenu) {
    int i;

    for (i = 0; i < 10; i++) {
        memset(tmenu->msg[i], 0, sizeof(char) * 512);
    }

    memset(tmenu->title, 0, sizeof(char) * 1024);

    switch (tmenu->activemenu) {
        case MAIN_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = PLAY_MENU;
            tmenu->linknext[1] = OPTIONS_MENU;
            tmenu->linknext[2] = EXIT_MENU;
            strcpy(tmenu->msg[0], _("Play"));
            strcpy(tmenu->msg[1], _("Game options"));
            strcpy(tmenu->msg[2], _("Exit"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case OPTIONS_MENU:
            tmenu->elements = 5;
            tmenu->linknext[0] = SCREEN_MENU;
            tmenu->linknext[1] = SOUND_MENU;
            tmenu->linknext[2] = CONTROL_MENU;
            tmenu->linknext[3] = GAME_MENU;
            tmenu->linknext[4] = MAIN_MENU;
            strcpy(tmenu->title, _("Game options"));
            strcpy(tmenu->msg[0], _("Screen options"));
            strcpy(tmenu->msg[1], _("Sound options"));
            strcpy(tmenu->msg[2], _("Control options"));
            strcpy(tmenu->msg[3], _("Game options"));
            strcpy(tmenu->msg[4], _("Return to main menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case INOPTIONS_MENU:
            tmenu->elements = 5;
            tmenu->linknext[0] = SCREEN_MENU;
            tmenu->linknext[1] = SOUND_MENU;
            tmenu->linknext[2] = CONTROL_MENU;
            tmenu->linknext[3] = GAME_MENU;
            tmenu->linknext[4] = INGAME_MENU;
            strcpy(tmenu->title, _("Game options"));
            strcpy(tmenu->msg[0], _("Screen options"));
            strcpy(tmenu->msg[1], _("Sound options"));
            strcpy(tmenu->msg[2], _("Control options"));
            strcpy(tmenu->msg[3], _("Game options"));
            strcpy(tmenu->msg[4], _("Return to main menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case SCREEN_MENU:
            tmenu->elements = 4;
            tmenu->linknext[0] = FULLSCREEN_MENU;
            tmenu->linknext[1] = RES_MENU;
            tmenu->linknext[2] = SCANLINES_MENU;
            tmenu->linknext[3] = OPTIONS_MENU;
            strcpy(tmenu->title, _("Screen options"));
            strcpy(tmenu->msg[0], _("Fullscreen"));
            strcpy(tmenu->msg[1], _("Resolution"));
            strcpy(tmenu->msg[2], _("Scanlines"));
            strcpy(tmenu->msg[3], _("Return to options menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case SOUND_MENU:
            tmenu->elements = 6;
            strcpy(tmenu->title, _("Sound options"));
            tmenu->linknext[0] = MUSIC_MENU;
            tmenu->linknext[1] = SFX_MENU;
            tmenu->linknext[2] = MVOL_MENU;
            tmenu->linknext[3] = SVOL_MENU;
            tmenu->linknext[4] = SURROUND_MENU;
            tmenu->linknext[5] = OPTIONS_MENU;
            strcpy(tmenu->msg[0], _("Music"));
            strcpy(tmenu->msg[1], _("Sound effects"));
            strcpy(tmenu->msg[2], _("Music volume"));
            strcpy(tmenu->msg[3], _("Sound effect volume"));
            strcpy(tmenu->msg[4], _("Surround"));
            strcpy(tmenu->msg[5], _("Return to options menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case CONTROL_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = CONTROLTYPE_MENU;
            tmenu->linknext[1] = REDEFINE_MENU;
            tmenu->linknext[2] = OPTIONS_MENU;
            strcpy(tmenu->title, _("Control options"));
            strcpy(tmenu->msg[0], _("Control type"));
            strcpy(tmenu->msg[1], _("Redefine keys"));
            strcpy(tmenu->msg[2], _("Return to options menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case CONTROLTYPE_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = CONTROL_MENU;
            tmenu->linknext[1] = CONTROL_MENU;
            tmenu->linknext[2] = CONTROL_MENU;
            strcpy(tmenu->title, _("Control type"));
            strcpy(tmenu->msg[0], _("Keyboard"));
            strcpy(tmenu->msg[1], _("Joystick"));
            strcpy(tmenu->msg[2], _("Return to control menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case FULLSCREEN_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = SCREEN_MENU;
            tmenu->linknext[1] = SCREEN_MENU;
            tmenu->linknext[2] = SCREEN_MENU;
            strcpy(tmenu->title, _("Fullscreen options"));
            strcpy(tmenu->msg[0], _("Fullscreen"));
            strcpy(tmenu->msg[1], _("Windowed"));
            strcpy(tmenu->msg[2], _("Return to screen menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case GAME_MENU:
            tmenu->elements = 2;
            tmenu->linknext[0] = STIPS_MENU;
            tmenu->linknext[1] = OPTIONS_MENU;
            strcpy(tmenu->title, _("Game options"));
            strcpy(tmenu->msg[0], _("Show tips"));
            strcpy(tmenu->msg[1], _("Return to options menu"));
            tmenu->x = 320;
            tmenu->y = 220;
            break;
        case RES_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = SCREEN_MENU;
            tmenu->linknext[1] = SCREEN_MENU;
            tmenu->linknext[2] = SCREEN_MENU;
            strcpy(tmenu->title, _("Resolution"));
            strcpy(tmenu->msg[0], _("320 x 240"));
            strcpy(tmenu->msg[1], _("640 x 480"));
            strcpy(tmenu->msg[2], _("Return to screen menu"));
            break;
        case MUSIC_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = SOUND_MENU;
            tmenu->linknext[1] = SOUND_MENU;
            tmenu->linknext[2] = SOUND_MENU;
            strcpy(tmenu->title, _("Music options"));
            strcpy(tmenu->msg[0], _("Music on"));
            strcpy(tmenu->msg[1], _("Music off"));
            strcpy(tmenu->msg[2], _("Return to sound menu"));
            break;
        case SFX_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = SOUND_MENU;
            tmenu->linknext[1] = SOUND_MENU;
            tmenu->linknext[2] = SOUND_MENU;
            strcpy(tmenu->title, _("Sound options"));
            strcpy(tmenu->msg[0], _("Sound effects on"));
            strcpy(tmenu->msg[1], _("Sound effects off"));
            strcpy(tmenu->msg[2], _("Return to sound menu"));
            break;
        case SURROUND_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = SOUND_MENU;
            tmenu->linknext[1] = SOUND_MENU;
            tmenu->linknext[2] = SOUND_MENU;
            strcpy(tmenu->title, _("Surround"));
            strcpy(tmenu->msg[0], _("Surround effect on"));
            strcpy(tmenu->msg[1], _("Surround effect off"));
            strcpy(tmenu->msg[2], _("Return to sound menu"));
            break;
        case SCANLINES_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = SCREEN_MENU;
            tmenu->linknext[1] = SCREEN_MENU;
            tmenu->linknext[2] = SCREEN_MENU;
            strcpy(tmenu->title, _("Scanlines"));
            strcpy(tmenu->msg[0], _("Scanlines on"));
            strcpy(tmenu->msg[1], _("Scanlines off"));
            strcpy(tmenu->msg[2], _("Return to screen menu"));
            break;
        case STIPS_MENU:
            tmenu->elements = 3;
            tmenu->linknext[0] = GAME_MENU;
            tmenu->linknext[1] = GAME_MENU;
            tmenu->linknext[2] = GAME_MENU;
            strcpy(tmenu->title, _("Tips"));
            strcpy(tmenu->msg[0], _("Show tips"));
            strcpy(tmenu->msg[1], _("Don't show the tips"));
            strcpy(tmenu->msg[2], _("Return to game menu"));
            break;
    }

    tmenu->longerstring = 0;

    for (i = 0; i < tmenu->elements; i++) {
        if (ph_text_len(font, tmenu->msg[i]) > ph_text_len(font, tmenu->msg[tmenu->longerstring])) {
            tmenu->longerstring = i;
        }
    }

    tmenu->longerstring = ph_text_len(font, tmenu->msg[tmenu->longerstring]);
}
