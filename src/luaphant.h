/*
	Header file for luaphant.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __LUAPHANT_H
#define __LUAPHANT_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <lua5.4/lua.h>
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif

lua_State *lp_init_lua(void);

void lp_destroy_lua(lua_State *ls);

int lp_check_file(lua_State *ls);

lua_State *lp_register_luaphant_functions(lua_State *ls);

int lp_translation_helper(lua_State *ls);

int lp_exist_file(lua_State *ls);

int lp_ppc(lua_State *ls);

int lp_exit(lua_State *ls);

int lp_create_enemy(lua_State *ls);

int lp_create_energy(lua_State *ls);

int lp_create_platform(lua_State *ls);

int lp_create_switch(lua_State *ls);

int lp_set_background_image(lua_State *ls);

int lp_packfile_password(lua_State *ls);

#ifdef __cplusplus
}
#endif
#endif
