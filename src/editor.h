#ifndef __EDITOR_H
#define __EDITOR_H

#include "cfg.h"
#include "gfx.h"
#include "data.h"
#include "world.h"

#define EDITOR_SHOTS "image"

typedef struct EDITOR {
    /*! La posicion x1 del cursor de captura */
    signed short int x1capt;
    /*! La posicion x2 del cursor de captura */
    signed short int x2capt;
    /*! La posicion y1 del cursor de captura */
    signed short int y1capt;
    /*! La posicion y2 del cursor de captura */
    signed short int y2capt;
    /*! La posicion x del cursor en la pantalla */
    signed short int xcursor;
    /*! La posicion y del cursor en la pantalla */
    signed short int ycursor;
    /*! La posicion x del cursor en el mapa */
    signed short int xmap;
    /*! La posicion y del cursor en el mapa */
    signed short int ymap;
    /*! La habitacion actual en la que estamos */
    unsigned char actroom;
    /*! Si esta activo mostramos la rejilla */
    unsigned char showgrid;
    /*! La anchura de la rejilla */
    unsigned char xgrid;
    /*! La altura de la rejilla */
    unsigned char ygrid;
    /*! La coordenada x de la pantalla donde se empieza a dibujar el nivel */
    signed short int xview;
    /*! La coordenada y de la pantalla donde se empieza a dibujar el nivel */
    signed short int yview;
    /*! La anchura de las 'tiles'*/
    unsigned char xtile;
    /*! La altura de las 'tiles'*/
    unsigned char ytile;
    /*! El numero maximo de 'tiles' por habitacion a lo ancho */
    unsigned char xtiles;
    /*! El numero maximo de 'tiles' por habitacion a lo alto */
    unsigned char ytiles;
    /*! En donde esta el foco en el editor */
    signed char focus;

    unsigned char imagemode;
    unsigned char enemymode;
    unsigned char platmode;
    signed short int selitem;
    int selenemy;
    unsigned char showrooms;
    unsigned char disable_showrooms;
    DATAFILE *roomdata;
    int focusedguicolor;
    int guicolor;
} EDITOR;

EDITOR *ph_init_editor(void);

void ph_destroy_editor(EDITOR *ed);

void ph_run_editor(EDITOR *ed, GFX *gfx, DATA *data, WORLD *w, char *path);

void ph_show_grid(EDITOR *ed);

void ph_draw_editor_gui(EDITOR *ed, GFX *gfx);

void ph_set_map_coords(EDITOR *ed, int x, int y);

void ph_draw_cursor(EDITOR *ed, GFX *gfx, DATA *data);

void ph_load_editor_aux_data(EDITOR *ed, CFG *cfg);

void ph_draw_background_grid(EDITOR *ed, GFX *gfx);

void ph_draw_background_image(EDITOR *ed, GFX *gfx);

void ph_draw_world_data(WORLD *w, EDITOR *ed, GFX *gfx);

void ph_grab_image(EDITOR *ed, GFX *gfx);

void ph_do_brick_block(EDITOR *ed, WORLD *w);

void ph_set_enemy(EDITOR *ed);

#endif
