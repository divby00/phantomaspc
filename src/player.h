/*
	Header file for player.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __PLAYER_H
#define __PLAYER_H

#include <allegro.h>

typedef struct PLAYER {
    char hide;
    char destroyed;
    fixed x;
    fixed y;
    fixed aniframe;
    char firsttimehit;
    char firsttimeenergy;
    char firsttimeswitch;
    signed char right;
    signed char speed;
    signed char falling;
    signed char jumping;
    signed char onplatform;
    signed short int energy;
    unsigned char pressed_switches;
    unsigned char visited_rooms;
    unsigned char opendoor;
    unsigned char explotedoor;
    unsigned char safe;
    unsigned char treasure;
    unsigned char points;
    unsigned char gametype;
    unsigned char showtips;
    unsigned char astro;
    unsigned char abu;
    unsigned char cheats;
    unsigned char damaging;
    unsigned char finished;
    unsigned char left_energy;
    char heared;
    char sp_heared;
    char spa_heared;
    char just_enter;
    signed int ballspeed;
    char rocket;
    char special_switch_on;
    char inrocket;
    char inchopper;
    char inball;
    char end;
    char restart;
    int endframe;
} PLAYER;

PLAYER *ph_init_player(void);

void ph_destroy_player(PLAYER *pl);

#endif
