#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ppcd.h"
#include "luaphant.h"
#include "trans.h"
#include "log.h"
#include "gfx.h"
#include "enemy.h"
#include "data.h"
#include "energy.h"
#include "switch.h"
#include "back.h"
#include "platform.h"


lua_State *lp_init_lua(void) {
    ph_log(_("- Initiating Lua: "));
    lua_State *ls = luaL_newstate();
    if (ls == NULL) {
        ph_log(_("Fatal error: Can't init Lua.\n"));
        exit(13);
    } else {
        ph_log(_("Ok.\n"));
    }
    ls = lp_register_luaphant_functions(ls);
    luaL_openlibs(ls);
    return ls;
}


void lp_destroy_lua(lua_State *ls) {
    lua_close(ls);
}


lua_State *lp_register_luaphant_functions(lua_State *ls) {
    lua_register(ls, "packfile_password", lp_packfile_password);
    lua_register(ls, "translate", lp_translation_helper);
    lua_register(ls, "exist_file", lp_exist_file);
    lua_register(ls, "check_file", lp_check_file);
    lua_register(ls, "ppc", lp_ppc);
    lua_register(ls, "exit", lp_exit);
    lua_register(ls, "create_enemy", lp_create_enemy);
    lua_register(ls, "create_energy", lp_create_energy);
    lua_register(ls, "create_platform", lp_create_platform);
    lua_register(ls, "create_switch", lp_create_switch);
    lua_register(ls, "set_background_image", lp_set_background_image);
    return ls;
}


int lp_translation_helper(lua_State *ls) {
    char *aux = (char *) malloc(sizeof(char) * 512);
    if (aux == NULL) {
        ph_log_memory_error((char *) "lfunc.c", (char *) "lm_translation_helper", (char *) "aux", sizeof(char) * 512);
    }
    memset(aux, 0, sizeof(char) * 512);
    strcpy(aux, _(lua_tostring(ls, 1)));
    lua_pushstring(ls, aux);
    free(aux);
    return 1;
}


int lp_exist_file(lua_State *ls) {
    int aux;
    FILE *f = fopen(lua_tostring(ls, 1), "rb");
    if (f == NULL) {
        aux = 0;
    } else {
        aux = 1;
    }
    lua_pushnumber(ls, aux);
    return 1;
}


int lp_packfile_password(lua_State *ls) {
    char *buf = (char *) malloc(sizeof(char) * 512);
    memset(buf, 0, sizeof(char) * 512);
    strcpy(buf, lua_tostring(ls, 1));
    free(buf);
    return 0;
}


int lp_check_file(lua_State *ls) {
    unsigned long int size = 0L;
    unsigned long int size2 = 0L;

    char *aux = (char *) malloc(sizeof(char) * 512);
    if (aux == NULL) {
        ph_log_memory_error((char *) "luaphant.c", (char *) "lp_check_file", (char *) "aux", sizeof(char) * 512);
    }
    memset(aux, 0, sizeof(char) * 512);
    strcpy(aux, lua_tostring(ls, 1));
    FILE *f = fopen(aux, "rb");
    if (f == NULL) {
        ph_log(_("Fatal error: Can't find the file %s."), aux);
        exit(-1);
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    size2 = (unsigned long int) lua_tonumber(ls, 2);

    if (size != size2) {
        ph_log(_("Fatal error: Size doesn't match."));
        exit(-1);
    }

    fclose(f);
    free(aux);
    return 0;
}


int lp_ppc(lua_State *ls) {
    int res;
    int x1, y1, x2, y2;
    BITMAP *aux1 = (BITMAP *) lua_touserdata(ls, 1);
    x1 = (int) lua_tonumber(ls, 2);
    y1 = (int) lua_tonumber(ls, 3);
    BITMAP *aux2 = (BITMAP *) lua_touserdata(ls, 4);
    x2 = (int) lua_tonumber(ls, 5);
    y2 = (int) lua_tonumber(ls, 6);
    res = sn_collision(aux1, x1, y1, aux2, x2, y2);
    lua_pushnumber(ls, res);
    return 1;
}


int lp_exit(lua_State *ls) {
    (void)ls;
    exit(0);
}


int lp_create_enemy(lua_State *ls) {
    int v[15];
    ENEMY *ene = (ENEMY *) lua_touserdata(ls, 1);
    GFX *gfx = (GFX *) lua_touserdata(ls, 2);
    DATA *data = (DATA *) lua_touserdata(ls, 3);
    v[0] = (int) lua_tonumber(ls, 4);
    v[1] = (int) lua_tonumber(ls, 5);
    v[2] = (int) lua_tonumber(ls, 6);
    v[3] = (int) lua_tonumber(ls, 7);
    v[4] = (int) lua_tonumber(ls, 8);
    v[5] = (int) lua_tonumber(ls, 9);
    v[6] = (int) lua_tonumber(ls, 10);
    v[7] = (int) lua_tonumber(ls, 11);
    v[8] = (int) lua_tonumber(ls, 12);
    v[9] = (int) lua_tonumber(ls, 13);
    v[10] = (int) lua_tonumber(ls, 14);
    v[11] = (int) lua_tonumber(ls, 15);
    v[12] = (int) lua_tonumber(ls, 16);
    v[13] = (int) lua_tonumber(ls, 17);
    v[14] = (int) lua_tonumber(ls, 18);

    ene->auxene->type = v[0];
    ene->auxene->x = v[1];
    ene->auxene->y = v[2];
    ene->auxene->xlimitl = v[3];
    ene->auxene->xlimitr = v[4];
    ene->auxene->ylimitu = v[5];
    ene->auxene->ylimitd = v[6];
    ene->auxene->movtype = v[7];
    ene->auxene->aniframe = v[8];
    ene->auxene->anirate = v[9];
    ene->auxene->right = v[10];
    ene->auxene->up = v[11];
    ene->auxene->xspeed = v[12];
    ene->auxene->yspeed = v[13];
    ene->auxene->power = v[14];

    ph_create_enemy(ene, gfx, data);
    return 0;
}


int lp_create_energy(lua_State *ls) {
    int v[5];
    ENERGY *energy = (ENERGY *) lua_touserdata(ls, 1);
    v[0] = (int) lua_tonumber(ls, 2);
    v[1] = (int) lua_tonumber(ls, 3);
    v[2] = (int) lua_tonumber(ls, 4);
    v[3] = (int) lua_tonumber(ls, 5);
    v[4] = (int) lua_tonumber(ls, 6);
    ph_create_energy(energy, v[0], v[1], v[2]);
    return 0;
}


int lp_create_switch(lua_State *ls) {
    int v[5];
    SWITCH *sw = (SWITCH *) lua_touserdata(ls, 1);
    v[0] = (int) lua_tonumber(ls, 2);
    v[1] = (int) lua_tonumber(ls, 3);
    v[2] = (int) lua_tonumber(ls, 4);
    v[3] = (int) lua_tonumber(ls, 5);
    v[4] = (int) lua_tonumber(ls, 6);
    ph_create_switch(sw, v[0], v[1], v[2], v[3], v[4]);
    return 0;
}


int lp_create_platform(lua_State *ls) {
    int f[11];
    PLATFORM *plat = (PLATFORM *) lua_touserdata(ls, 1);
    f[0] = (int) lua_tonumber(ls, 2);
    f[1] = (int) lua_tonumber(ls, 3);
    f[2] = (int) lua_tonumber(ls, 4);
    f[3] = (int) lua_tonumber(ls, 5);
    f[4] = (int) lua_tonumber(ls, 6);
    f[5] = (int) lua_tonumber(ls, 7);
    f[6] = (int) lua_tonumber(ls, 8);
    f[7] = (int) lua_tonumber(ls, 9);
    f[8] = (int) lua_tonumber(ls, 10);
    f[9] = (int) lua_tonumber(ls, 11);
    f[10] = (int) lua_tonumber(ls, 12);
    ph_create_platform(plat, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9], f[10]);
    return 0;
}


int lp_set_background_image(lua_State *ls) {
    WORLD *w = (WORLD *) lua_touserdata(ls, 1);
    unsigned char i = (unsigned char) lua_tonumber(ls, 2);
    ph_set_background_image(w, i);
    return 0;
}
