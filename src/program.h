/*
	Header file for program.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __PROGRAM_H
#define __PROGRAM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <lua5.4/lua.h>

#ifdef __cplusplus
}
#endif

#include "config.h"

#include "luaphant.h"

#include "cfg.h"
#include "gfx.h"
#include "sfx.h"
#include "timer.h"
#include "data.h"
#include "player.h"
#include "enemy.h"
#include "platform.h"
#include "switch.h"
#include "energy.h"
#include "editor.h"
#include "world.h"
#include "control.h"
#include "texter.h"
#include "menu.h"
#include "mouse.h"
#include "arrows.h"
#include "blockp.h"
#include "hand.h"
#include "vehicle.h"
#include "ball.h"
#include "records.h"

/**
 * Desde esta estructura se puede acceder a cualquier dato no local del programa
 */
typedef struct PROGRAM {
    unsigned char launch_editor;
    unsigned char launch_setup;
    char *path;
    lua_State *ls;
    BALL *b;
    HAND *hand;
    BLOCK *bl;
    ARROWS *ar;
    PHFONT *fnt;
    CFG *cfg;
    TEMPCFG *tcfg;
    GFX *gfx;
    SOUND *snd;
    TIMER *t;
    DATA *data;
    ENEMY *ene;
    PLAYER *pl;
    EDITOR *ed;
    WORLD *w;
    CONTROL *c;
    PLATFORM *plat;
    SWITCH *sw;
    ENERGY *energy;
    TMENU *menu;
    MOUSE *m;
    VEHICLE *v;
    RECORDS *rec;
} PROGRAM;

/**
 * Se encarga de la inicializacion de la memoria para todas las estructuras,
 * tambien de hacer las llamadas a todas las funciones necesarias para iniciar
 * todo.
 * @param argc El nmero de argumentos de la linea de comandos.
 * @param argv Cadenas con los argumentos.
 * @return Un puntero PROGRAM con todos los datos listos para poderse usar.
 */
PROGRAM *ph_init_program(int argc, char **argv);

/**
 * Libera la memoria usada por el programa y finalmente sale.
 * @param p Un puntero PROGRAM con los datos que queremos liberar.
 */
void ph_destroy_program(PROGRAM *p);

/**
 * Examina la linea de comandos y actua en consecuencia.
 * @param p El programa.
 * @param argc Nmero de argumentos.
 * @param argv Cadenas con los argumentos.
 * @return PROGRAM til con los valores ajustados de acuerdo a lo que se pasara
 * por la linea de comandos.
 */
PROGRAM *ph_parse_commandline(PROGRAM *p, int argc, char **argv);

void ph_exit_message(void);

#endif
