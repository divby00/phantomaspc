#ifndef __ENEMY_H
#define __ENEMY_H

#include <allegro.h>
#include <string.h>
#include "gfx.h"
#include "data.h"
#include "log.h"
#include "enemy2.h"
#include "world.h"
#include "player.h"
#include "sfx.h"
#include "cfg.h"

/*! Tipos de movimiento enemigos, para saber donde estan encarados los enemigos en los ficheros
	con los graficos se utiliza un identificador en el nombre del fichero, asi, veras que en
	casi todos pone 0, eso es porque usan el EMOVE_NORMAL, etc...
EMOVE_NORMAL: Es el movimiento normal, es decir, con los bichos mirando al frente, no hay que
rotar los sprites ni nada.
EMOVE_RIGHT: Es el movimiento del pterodactilo por ejemplo, de los enemigos que miran hacia un
lado, su id en los ficheros graficos es el 1.
EMOVE_UP: Es el movimiento de los pollos que hay en la puerta, de los enemigos que miran hacia
arriba, su id en los ficheros graficos es el 2.
EMOVE_NONE: Para enemigos estaticos.
*/
enum enem_move_types {
    EMOVE_NORMAL = 0, EMOVE_RIGHT, EMOVE_UP, EMOVE_MULTI, EMOVE_NONE
};

typedef struct AUXENE {
    unsigned char type;
    signed short int x;
    signed short int y;
    signed short int xlimitl;
    signed short int xlimitr;
    signed short int ylimitu;
    signed short int ylimitd;
    unsigned char movtype;
    unsigned char aniframe;
    unsigned char anirate;
    unsigned char right;
    unsigned char up;
    signed char xspeed;
    signed char yspeed;
    unsigned char power;
} AUXENE;

/*!
Estructura con los datos de los enemigos
*/
typedef struct ENEMY {
    /* Se usan con los enemigos #11, los volcanes. */
    unsigned char act_counter[MAX_ENEMIES];
    unsigned char init_counter[MAX_ENEMIES];
    /*! Contador del enemigo actual */
    unsigned short int actenemy;
    /*! Contador del frame activo */
    char actframe[MAX_ENEMIES];
    /*! Tipo de enemigo, de aqui sacamos el tipo de grafico que tendra*/
    char type[MAX_ENEMIES];
    /*! Cierto si el enemigo esta activo */
    char active[MAX_ENEMIES];
    /*! Velocidad en las x del enemigo */
    char xspeed[MAX_ENEMIES];
    /*! Velocidad en las y del enemigo */
    char yspeed[MAX_ENEMIES];
    /*! Velocidad de los frames del enemigo (contra mas alto, mas lentamente se cambiara el frame) */
    char framespeed[MAX_ENEMIES];
    /*! Coordenada x1 tope del enemigo */
    signed short int x1limit[MAX_ENEMIES];
    /*! Coordenada x2 tope del enemigo */
    signed short int x2limit[MAX_ENEMIES];
    /*! Coordenada y1 tope del enemigo */
    signed short int y1limit[MAX_ENEMIES];
    /*! Coordenada y2 tope del enemigo */
    signed short int y2limit[MAX_ENEMIES];
    /*! Coordenada x del enemigo */
    signed short int x[MAX_ENEMIES];
    /*! Coordenada y del enemigo */
    signed short int y[MAX_ENEMIES];
    /*! Tipo de movimiento del enemigo, los tipos de movimiento son varios,
    mira la enumeracion <b>enem_move_types</b> para mas informacion.*/
    char mov_type[MAX_ENEMIES];
    /*! Activa si el bicho lleva trayectoria hacia la derecha (+x) */
    char right[MAX_ENEMIES];
    /*! Activa si lleva trayectoria hacia arriba (-y) el enemigo */
    char up[MAX_ENEMIES];
    /*! La cantidad de vida que quitara este enemigo a Phantomas, 0 = mortal */
    unsigned char power[MAX_ENEMIES];
    /*! Hacia que se colorizara al bicho, reservado para un futuro uso. */
    unsigned char ink;
    /*! Auxiliar para ayudar al poner los valores iniciales de los enemigos. */
    AUXENE *auxene;
} ENEMY;

ENEMY *ph_init_enemies(void);

void ph_destroy_enemies(ENEMY *ene);

void ph_move_enemies(ENEMY *enemy, SOUND *snd, CFG *cfg, PLAYER *pl);

void ph_draw_enemies(ENEMY *enemy, GFX *gfx);

void ph_create_enemy(ENEMY *enemy, GFX *gfx, DATA *data);

void ph_damage_player(ENEMY *ene, PLAYER *pl, GFX *gfx, SOUND *snd, CFG *cfg);

void ph_play_enemy_sfx(SOUND *snd, CFG *cfg, int x, int y, unsigned char ene_type, int enex, int eney,
                       int just_enter);

#endif
