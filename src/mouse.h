#ifndef __MOUSE_H
#define __MOUSE_H

#include <allegro.h>

typedef struct MOUSE {
    char imouse;                                  /* Definida a 1 si el raton se ha podido instalar */
    BITMAP *cursor;
    int x;
    int y;
    char b1;
    char b2;
} MOUSE;

MOUSE *ph_init_mouse(void);

void ph_destroy_mouse(MOUSE *m);

MOUSE *ph_get_mouse_data(MOUSE *m);

void ph_draw_mouse(MOUSE *m, BITMAP *dst);

#endif
