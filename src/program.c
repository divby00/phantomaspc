#include <string.h>
#include <malloc.h>
#include <allegro.h>
#include "config.h"
#include "program.h"
#include "trans.h"
#include "log.h"
#include "luaphant.h"
#include "path.h"
#include "fades.h"
#include "records.h"

PROGRAM *ph_init_program(int argc, char **argv) {
    int res = 0;
    (void) res;
    PROGRAM *aux;
    char *buf;
#ifdef WIN32
    int i=0;
#endif
#ifdef DOS
    int i=0;
#endif
#ifdef MAC
    int i=0;
#endif

#ifdef LINUX
    set_uformat(U_UTF8);
#else
    set_uformat(U_ASCII);
#endif

#if HAVE_INTL
    setlocale(LC_ALL,"");
    //bindtextdomain("phantomaspc",LOCALE_DIR);
#endif
    buf = (char *) malloc(sizeof(char) * 512);
    if (buf == NULL) {
        printf("%s", _("Error: There's no memory!\n"));
        exit(13);
    }
    memset(buf, 0, sizeof(char) * 512);
#ifdef WIN32
    buf=getcwd(buf,sizeof(char)*512);
    strcat(buf,"/");
    strcat(buf,LOCALE_DIR);
    while (*(buf+i)!='\0') {
        if (*(buf+i)==92) *(buf+i)=47;
        i++;
    }
#if HAVE_INTL
    bindtextdomain(PHANTOMAS_PACKAGE,buf);
#endif
#endif
#ifdef DOS
    buf=getcwd(buf,sizeof(char)*512);
    strcat(buf,"/");
    strcat(buf,LOCALE_DIR);
    while (*(buf+i)!='\0') {
        if (*(buf+i)==92) *(buf+i)=47;
        i++;
    }
#if HAVE_INTL
    bindtextdomain(PHANTOMAS_PACKAGE,buf);
#endif
#else
#if HAVE_INTL
#ifdef CUSTOM_PATH
	bindtextdomain(PHANTOMAS_PACKAGE, "/usr/share/locale");
    textdomain(PHANTOMAS_PACKAGE);
#else
	bindtextdomain(PHANTOMAS_PACKAGE, LOCALE_DIR);
    textdomain(PHANTOMAS_PACKAGE);
#endif
#endif
#endif
    free(buf);
    ph_log(_("- Initiating Phantomas PC...\n"));
    aux = (struct PROGRAM *) malloc(sizeof(struct PROGRAM));
    if (aux == NULL)
        ph_log_memory_error((char *) "program.c", (char *) "ph_init_program", (char *) "aux", sizeof(struct PROGRAM));
    memset(aux, 0, sizeof(struct PROGRAM));
    aux->ls = lp_init_lua();
    aux->path = ph_init_path();
    aux->tcfg = ph_init_temp_configuration();
    aux = ph_parse_commandline(aux, argc, argv);
    aux->cfg = ph_init_configuration(aux->launch_setup, aux->ls);

    if (aux->tcfg->nosound == 1) {
        aux->cfg->enable_sound = 0;
    }
    if (aux->tcfg->nosfx == 1) {
        aux->cfg->sfx = 0;
    }
    if (aux->tcfg->nomusic == 1) {
        aux->cfg->music = 0;
    }
    if (aux->tcfg->joystick == 1) {
        aux->cfg->controltype = 1;
    }

    ph_destroy_temp_configuration(aux->tcfg);
    allegro_init();
    install_timer();
    install_keyboard();
    aux->gfx = ph_init_gfx(aux->cfg);
#ifndef GP2X
    aux->m = ph_init_mouse();
#endif
    aux->snd = ph_init_sound(aux->cfg);
    aux->t = (TIMER *) ph_init_timer();
    aux->fnt = ph_init_texter();

#ifndef LINUX
    ph_get_file_name(aux->cfg, (char *) "cdata.bin");
#endif

    res = luaL_dofile(aux->ls, aux->cfg->buffer);
    aux->data = ph_init_data(aux->cfg, aux->path);
    ph_assign_data(aux->data, aux->cfg, aux->gfx, aux->snd, aux->fnt);
    ph_fade_out(16, aux->cfg);
    clear_to_color(screen, makecol(0, 0, 0));
    aux->w = ph_init_world();
    aux->ene = ph_init_enemies();
    aux->ar = ph_init_arrows();
    aux->bl = ph_init_block();
    aux->b = ph_init_ball();
    aux->hand = ph_init_hand();
    aux->v = ph_init_vehicles();
    aux->plat = ph_init_platforms();
    aux->sw = ph_init_switches();
    aux->energy = ph_init_energy();
    aux->pl = ph_init_player();
    aux->c = ph_init_control(aux->cfg);
    aux->menu = ph_init_menu();

    if (aux->cfg->controltype) aux->c = ph_init_joystick(aux->c);

    if (aux->launch_editor) {
        aux->ed = ph_init_editor();
        ph_load_editor_aux_data(aux->ed, aux->cfg);
        ph_run_editor(aux->ed, aux->gfx, aux->data, aux->w, aux->path);
    } else {
        aux->ed = NULL;
    }

    ph_set_menu_options(aux->fnt, aux->menu);
    aux->rec = ph_init_records();

    return aux;
}


void ph_destroy_program(PROGRAM *p) {
    ph_log(_("- Saving the configuration: "));

    if (ph_save_config_file(p->cfg)) {
        ph_log(_("Ok.\n"));
    } else {
        ph_log(_("Error.\n"));
    }
    ph_log(_("- Saving the record table...\n"));
    ph_save_record_table(p->rec);
    ph_log(_("- Destroying Lua...\n"));
    lp_destroy_lua(p->ls);
    if (p->launch_editor) {
        ph_destroy_editor(p->ed);
        ph_log(_("- Destroying editor...\n"));
    }
    ph_log(_("- Destroying world...\n"));
    ph_destroy_world(p->w);
    ph_log(_("- Destroying platforms...\n"));
    ph_destroy_platforms(p->plat);
    ph_log(_("- Destroying switches...\n"));
    ph_destroy_switches(p->sw);
    ph_log(_("- Destroying energy...\n"));
    ph_destroy_energy(p->energy);
    ph_log(_("- Destroying enemies...\n"));
    ph_destroy_enemies(p->ene);
    ph_log(_("- Destroying arrows...\n"));
    ph_destroy_arrows(p->ar);
    ph_log(_("- Destroying block...\n"));
    ph_destroy_block(p->bl);
    ph_log(_("- Destroying ball...\n"));
    ph_destroy_ball(p->b);
    ph_log(_("- Destroying hand...\n"));
    ph_destroy_hand(p->hand);
    ph_log(_("- Destroying vehicles...\n"));
    ph_destroy_vehicles(p->v);
    ph_log(_("- Destroying player...\n"));
    ph_destroy_player(p->pl);
    ph_log(_("- Destroying control...\n"));
    ph_destroy_control(p->c);
#ifndef GP2X
    ph_log(_("- Destroying mouse...\n"));
    ph_destroy_mouse(p->m);
#endif
    ph_log(_("- Destroying timers...\n"));
    ph_destroy_timer(p->t);
    ph_log(_("- Destroying graphics...\n"));
    ph_destroy_gfx(p->gfx);
    ph_log(_("- Destroying sound...\n"));
    ph_destroy_sound(p->cfg, p->snd);
    ph_log(_("- Destroying data...\n"));
    ph_destroy_data(p->data);
    ph_log(_("- Destroying menu...\n"));
    ph_destroy_menu(p->menu);
    ph_log(_("- Destroying fonts...\n"));
    ph_destroy_texter(p->fnt);
    ph_log(_("- Destroying records...\n"));
    ph_destroy_records(p->rec);
    ph_log(_("- Destroying configuration...\n"));
    ph_destroy_configuration(p->cfg);
    ph_destroy_path(p->path);
    ph_log(_("- Destroying program...\n"));
    free(p);
    ph_log(_("- Exiting...\n"));
    allegro_exit();
    ph_exit_message();
}


PROGRAM *ph_parse_commandline(PROGRAM *p, int argc, char **argv) {
    int i;
    char *buffer;
    char valid_arg = 0;

    if (argc == 1) return p;

    ph_log(_("- Parsing the command line: "));

    buffer = (char *) malloc(sizeof(char) * 512);
    if (buffer == NULL)
        ph_log_memory_error((char *) "program.c", (char *) "ph_parse_commandline", (char *) "buffer",
                            sizeof(char) * 512);

    for (i = 0; i < argc; i++) {
        memset(buffer, 0, sizeof(char) * 512);
        strcpy(buffer, argv[i]);
        if (!strcmp(buffer, "editor")) {
            p->launch_editor = 1;
            valid_arg = 1;
        }
        if (!strcmp(buffer, "nosound")) {
            p->tcfg->nosound = 1;
            valid_arg = 1;
        }
        if (!strcmp(buffer, "nosfx")) {
            p->tcfg->nosfx = 1;
            valid_arg = 1;
        }
        if (!strcmp(buffer, "joystick")) {
            p->tcfg->joystick = 1;
            valid_arg = 1;
        }
        if (!strcmp(buffer, "nomusic")) {
            p->tcfg->nomusic = 1;
            valid_arg = 1;
        }
    }

    if (!valid_arg) {
        ph_log(_("The arguments you passed seem to be invalid. Try these:\n"));
        ph_log(_("    setup - run the setup script.\n"));
        ph_log(_("    editor - run the level editor.\n"));
        ph_log(_("    nosound - disable the sound.\n"));
        ph_log(_("    nosfx - disable the sound effects.\n"));
        ph_log(_("    nomusic - disable the music.\n"));
        ph_log(_("    joystick - use a joystick if it is available.\n\n"));
    } else {
        ph_log(_("Ok.\n"));
    }

    free(buffer);
    return p;
}
