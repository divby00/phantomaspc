/*
	Header file for config.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __CFG_H
#define __CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <lua5.4/lua.h>
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>

#ifdef __cplusplus
}
#endif

#define DFLT_XRES               320
#define DFLT_YRES               240
#define DFLT_SHOW_TIPS          1
#define DFLT_FULLSCREEN         0
#define DFLT_STRETCH            1
#define DFLT_STRETCHX           1280
#define DFLT_STRETCHY           960
#define DFLT_ENABLE_SOUND       1
#define DFLT_SFX                1
#define DFLT_MUSIC              1
#define DFLT_SFXVOLUME          255
#define DFLT_MUSICVOLUME        255

#ifndef GP2X
#define DFLT_CONTROLTYPE        0
#else
#define DFLT_CONTROLTYPE        1
#endif

#define DFLT_CONFIG_FILE_W32    "phantomaspc.cfg"
#define DFLT_CONFIG_FILE_UNIX   ".phantomaspc"
#define DFLT_DATADIR			"data/"
#define DFLT_DATADIR_MAC        "data/mac/"
#define DFLT_DATADIR_CUSTOM     "/usr/share/phantomaspc/"
#define DFLT_KEY_UP             84
#define DFLT_KEY_DOWN           85
#define DFLT_KEY_LEFT           82
#define DFLT_KEY_RIGHT          83
#define DFLT_SURROUND           1

typedef struct CFG {
    unsigned short int xres;
    unsigned short int yres;
    unsigned char fullscreen;
    unsigned char stretch;
    unsigned short int stretchx;
    unsigned short int stretchy;
    unsigned char show_tips;
    unsigned char enable_sound;
    unsigned char sfx;
    unsigned char music;
    unsigned char sfxvolume;
    unsigned char musicvolume;
    unsigned char surround;
    unsigned char controltype;
    unsigned char key_up;
    unsigned char key_down;
    unsigned char key_left;
    unsigned char key_right;
    char *datadir;
    char *buffer;
} CFG;

typedef struct TEMPCFG {
    unsigned char nosound;
    unsigned char nosfx;
    unsigned char nomusic;
    unsigned char joystick;
} TEMPCFG;

CFG *ph_init_configuration(unsigned char launch_setup, lua_State *ls);

TEMPCFG *ph_init_temp_configuration(void);

void ph_destroy_configuration(CFG *cfg);

void ph_destroy_temp_configuration(TEMPCFG *tcfg);

CFG *ph_set_config_defaults(CFG *cfg);

CFG *ph_get_config_from_cfg_from_path(CFG *cfg, lua_State *ls, char *buf);

char ph_save_config_file(CFG *cfg);

#endif
