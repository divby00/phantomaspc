/*
	Header file for control.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __CONTROL_H
#define __CONTROL_H

#include "cfg.h"
#include "menu.h"

#define CTRL_TYPE_KEYBOARD 0
#define CTRL_TYPE_JOYSTICK 1
#define MAXACTIONKEYS 4
#define MAXMOVES    8
#define MOVE_UP     0
#define MOVE_DOWN   1
#define MOVE_LEFT   2
#define MOVE_RIGHT  3
#define MOVE_ACT1   4
#define MOVE_ACT2   5
#define MOVE_ACT3   6
#define MOVE_ACT4   7

typedef struct CONTROL {
    unsigned char key_event;
    unsigned char key_press;
    unsigned char type;

    /* Estas variables seran 1 cuando se haya pulsado la tecla para ese
     * movimiento, 0 si no. */
    signed char up;
    signed char down;
    signed char left;
    signed char right;
    signed char action[MAXACTIONKEYS];

    /* Aqui se almacena el scancode de cada tecla */
    char key[MAXMOVES];
} CONTROL;

typedef int ( *snap_cback )(const char *, int, void *);

#ifndef DOS
#ifndef GP2X

void close_button_handler(void);

#endif
#endif

void ph_destroy_control(CONTROL *c);

CONTROL *ph_init_joystick(CONTROL *c);

CONTROL *ph_init_control(CFG *cfg);

int ph_snapshot_callback(const char *filename, int attrib, void *param);

void ph_take_snapshot(void);

char ph_ascii_to_scancode(char ascii);

#endif
