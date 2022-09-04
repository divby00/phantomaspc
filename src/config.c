/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "log.h"
#include "cfg.h"
#include "trans.h"

CFG *ph_init_configuration(unsigned char launch_setup, lua_State *ls) {
    FILE *f1;

    ph_log(_("- Initiating configuration: "));

    CFG *aux = (struct CFG *) malloc(sizeof(struct CFG));
    if (aux == NULL) {
        ph_log_memory_error((char *) "config.c", (char *) "ph_init_configuration", (char *) "aux", sizeof(struct CFG));
    }
    memset(aux, 0, sizeof(struct CFG));

    char *buffer = (char *) malloc(sizeof(char) * 512);
    if (buffer == NULL) {
        ph_log_memory_error((char *) "config.c", (char *) "ph_init_configuration", (char *) "buffer",
                            sizeof(char) * 512);
    }
    memset(buffer, 0, sizeof(char) * 512);
    aux->datadir = buffer;

    char *buf = (char *) malloc(sizeof(char) * 512);
    if (buf == NULL) {
        ph_log_memory_error((char *) "config.c", (char *) "ph_init_configuration", (char *) "buf", sizeof(char) * 512);
    }
    memset(buf, 0, sizeof(char) * 512);

    char *b = (char *) malloc(sizeof(char) * 512);
    if (b == NULL) {
        ph_log_memory_error((char *) "config.c", (char *) "ph_init_configuration", (char *) "b", sizeof(char) * 512);
    }
    memset(b, 0, sizeof(char) * 512);
    aux->buffer = b;

#ifdef LINUX
    strcpy(buf,getenv("HOME"));
    buf[strlen(buf)]='/';
    strcat(buf,DFLT_CONFIG_FILE_UNIX);
    f1=fopen(buf,"rb");
    if (f1!=NULL && !launch_setup) {
        aux=ph_get_config_from_cfg_from_path(aux,ls,buf);
        fclose(f1);
        free(buf);
        return aux;
    }
    else {
        ph_set_config_defaults(aux);
        ph_save_config_file(aux);
    }
#else
    buf = getcwd(buf, sizeof(char) * 512);
    buf[strlen(buf)] = '/';
    strcat(buf, DFLT_CONFIG_FILE_W32);
    f1 = fopen(buf, "rb");
    if (f1 != NULL && !launch_setup) {
        aux = ph_get_config_from_cfg_from_path(aux, ls, buf);
        ph_save_config_file(aux);
        fclose(f1);
        free(buf);
        return aux;
    } else {
        ph_set_config_defaults(aux);
        ph_save_config_file(aux);
    }
#endif
    free(buf);
    return aux;
}


void ph_destroy_configuration(CFG *cfg) {
    free(cfg->buffer);
    free(cfg->datadir);
    free(cfg);
}


CFG *ph_set_config_defaults(CFG *cfg) {
    cfg->surround = DFLT_SURROUND;

#ifdef MAC
	strcpy(cfg->datadir, DFLT_DATADIR_MAC);
#else
    strcpy(cfg->datadir, DFLT_DATADIR);
#endif

    cfg->xres = DFLT_XRES;
    cfg->yres = DFLT_YRES;
    cfg->fullscreen = DFLT_FULLSCREEN;
    cfg->stretch = DFLT_STRETCH;
    cfg->stretchx = DFLT_STRETCHX;
    cfg->stretchy = DFLT_STRETCHY;
    cfg->show_tips = DFLT_SHOW_TIPS;
    cfg->enable_sound = DFLT_ENABLE_SOUND;
    cfg->sfx = DFLT_SFX;
    cfg->music = DFLT_MUSIC;
    cfg->sfxvolume = DFLT_SFXVOLUME;
    cfg->musicvolume = DFLT_MUSICVOLUME;
    cfg->surround = DFLT_SURROUND;
    cfg->controltype = DFLT_CONTROLTYPE;
    cfg->key_up = DFLT_KEY_UP;
    cfg->key_down = DFLT_KEY_DOWN;
    cfg->key_left = DFLT_KEY_LEFT;
    cfg->key_right = DFLT_KEY_RIGHT;

#ifdef GP2X
    cfg->xres=320;
    cfg->yres=240;
    cfg->fullscreen=1;
    cfg->stretch=0;
    cfg->stretchx=320;
    cfg->stretchy=240;
    cfg->controltype=1;
    // 		cfg->scanlines=0;
#endif
    return cfg;
}


CFG *ph_get_config_from_cfg_from_path(CFG *cfg, lua_State *ls, char *buf) {
    FILE *f = fopen(buf, "rb");
    fseek(f, 0, SEEK_END);
    unsigned long int size = ftell(f);
    fclose(f);
    if (!size) {
        ph_log(_("Warning: there's a problem with the configuration file. Assuming defaults.\n"));
        cfg = ph_set_config_defaults(cfg);
        return cfg;
    }

    int res = luaL_dofile(ls, buf);
    if (res != 0) {
        ph_log(_("Warning: there's a problem with the configuration file. Assuming defaults.\n"));
        cfg = ph_set_config_defaults(cfg);
    } else {
        lua_getglobal(ls, "datadir");
        lua_getglobal(ls, "keyright");
        lua_getglobal(ls, "keyleft");
        lua_getglobal(ls, "keydown");
        lua_getglobal(ls, "keyup");
        lua_getglobal(ls, "controltype");
        lua_getglobal(ls, "surround");
        lua_getglobal(ls, "musicvol");
        lua_getglobal(ls, "sfxvol");
        lua_getglobal(ls, "music");
        lua_getglobal(ls, "sfx");
        lua_getglobal(ls, "enable_sound");
        lua_getglobal(ls, "show_tips");
        lua_getglobal(ls, "stretchy");
        lua_getglobal(ls, "stretchx");
        lua_getglobal(ls, "stretch");
        lua_getglobal(ls, "fullscreen");
        lua_getglobal(ls, "yres");
        lua_getglobal(ls, "xres");

        cfg->xres = (unsigned short int) lua_tonumber(ls, -1);
        cfg->yres = (unsigned short int) lua_tonumber(ls, -2);
        cfg->fullscreen = (unsigned char) lua_tonumber(ls, -3);
        cfg->stretch = (unsigned char) lua_tonumber(ls, -4);
        cfg->stretchx = (unsigned short int) lua_tonumber(ls, -5);
        cfg->stretchy = (unsigned short int) lua_tonumber(ls, -6);
        cfg->show_tips = (unsigned short int) lua_tonumber(ls, -7);
        cfg->enable_sound = (unsigned char) lua_tonumber(ls, -8);
        cfg->sfx = (unsigned char) lua_tonumber(ls, -9);
        cfg->music = (unsigned char) lua_tonumber(ls, -10);
        cfg->sfxvolume = (unsigned char) lua_tonumber(ls, -11);
        cfg->musicvolume = (unsigned char) lua_tonumber(ls, -12);
        cfg->surround = (int) lua_tonumber(ls, -13);
        cfg->controltype = (unsigned char) lua_tonumber(ls, -14);
        cfg->key_up = (int) lua_tonumber(ls, -15);
        cfg->key_down = (int) lua_tonumber(ls, -16);
        cfg->key_left = (int) lua_tonumber(ls, -17);
        cfg->key_right = (int) lua_tonumber(ls, -18);
        strcpy(cfg->datadir, lua_tostring(ls, -19));
        ph_log(_("Ok.\n"));
    }
    return cfg;
}


char ph_save_config_file(CFG *cfg) {
    char *buf = (char *) malloc(sizeof(char) * 512);
    memset(buf, 0, sizeof(char) * 512);

#ifdef LINUX
    strcpy(buf,getenv("HOME"));
    buf[strlen(buf)]='/';
    strcat(buf,DFLT_CONFIG_FILE_UNIX);
	FILE *f=fopen(buf,"wt");
#else
    buf = getcwd(buf, sizeof(char) * 512);
    buf[strlen(buf)] = '/';
    strcat(buf, DFLT_CONFIG_FILE_W32);
    FILE *f = fopen(buf, "wt");
#endif
    if (f == NULL) {
        ph_log(_("Warning: Can't write the configuration file %s.\n"), buf);
        return 0;
    } else {
        fprintf(f, "%s", _("-- Configuration file for Phantomas PC\n"));
        fprintf(f, "%s", _("-- Lines starting with -- are comments.\n\n"));
        fprintf(f, "%s", _("-- Horizontal resolution, recommended 320.\n"));
        fprintf(f, "xres = %d\n", cfg->xres);
        fprintf(f, "%s", _("-- Vertical resolution, recommended 240.\n"));
        fprintf(f, "yres = %d\n", cfg->yres);
        fprintf(f, "%s", _("-- Full screen? 0 -> no, 1 -> yes.\n"));
        fprintf(f, "fullscreen = %d\n", cfg->fullscreen);
        fprintf(f, "%s", _("-- Stretch screen? 0 -> no, 1 -> yes.\n"));
        fprintf(f, "stretch = %d\n", cfg->stretch);
        fprintf(f, "%s", _("-- Stretch screen to this width.\n"));
        fprintf(f, "stretchx = %d\n", cfg->stretchx);
        fprintf(f, "%s", _("-- Stretch screen to this height.\n"));
        fprintf(f, "stretchy = %d\n", cfg->stretchy);
        fprintf(f, "%s", _("-- Show tips in the game? 0 -> no, 1 -> yes.\n"));
        fprintf(f, "show_tips = %d\n", cfg->show_tips);
        fprintf(f, "%s", _("-- Enable sounds and music? 0 -> no, 1 -> yes.\n"));
        fprintf(f, "enable_sound = %d\n", cfg->enable_sound);
        fprintf(f, "%s", _("-- Enable sound effects? 0 -> no, 1 -> yes.\n"));
        fprintf(f, "sfx = %d\n", cfg->sfx);
        fprintf(f, "%s", _("-- Enable music? 0 -> no, 1 -> yes.\n"));
        fprintf(f, "music = %d\n", cfg->music);
        fprintf(f, "%s", _("-- Sound effects volume 0 (min.) - 255 (max.)\n"));
        fprintf(f, "sfxvol = %d\n", cfg->sfxvolume);
        fprintf(f, "%s", _("-- Music volume 0 (min.) - 255 (max.)\n"));
        fprintf(f, "musicvol = %d\n", cfg->musicvolume);
        fprintf(f, "%s", _("-- Surround sound.\n"));
        fprintf(f, "surround = %d\n", cfg->surround);
        fprintf(f, "%s", _("-- Control type, 0 keyboard, 1 joystick.\n"));
        fprintf(f, "controltype = %d\n", cfg->controltype);
        fprintf(f, "%s", _("-- Scan code of key for UP.\n"));
        fprintf(f, "keyup = %d\n", cfg->key_up);
        fprintf(f, "%s", _("-- Scan code of key for DOWN.\n"));
        fprintf(f, "keydown = %d\n", cfg->key_down);
        fprintf(f, "%s", _("-- Scan code of key for LEFT.\n"));
        fprintf(f, "keyleft = %d\n", cfg->key_left);
        fprintf(f, "%s", _("-- Scan code of key for RIGHT.\n"));
        fprintf(f, "keyright = %d\n", cfg->key_right);
        fprintf(f, "%s", _("-- Directory with the game data.\n"));
        fprintf(f, "datadir = \"%s\"\n", cfg->datadir);
        fclose(f);
    }
    free(buf);
    return 1;
}


TEMPCFG *ph_init_temp_configuration(void) {
    ph_log(_("- Initiating temporal configuration: "));
    TEMPCFG *aux = (struct TEMPCFG *) malloc(sizeof(struct TEMPCFG));
    if (aux == NULL) {
        ph_log_memory_error((char *) "config.c", (char *) "ph_init_temp_configuration", (char *) "aux",
                            sizeof(struct TEMPCFG));
        exit(13);
    } else {
        ph_log(_("Ok.\n"));
    }
    memset(aux, 0, sizeof(struct TEMPCFG));
    return aux;
}


void ph_destroy_temp_configuration(TEMPCFG *tcfg) {
    free(tcfg);
}
