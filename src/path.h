/*
	Header file for path.c
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __PATH_H
#define __PATH_H

#include "cfg.h"

#define MAXPATHSIZE 512

char *ph_init_path(void);

char *ph_get_path(char *path, char *buffer);

void ph_destroy_path(char *path);

char *ph_get_file_name(CFG *cfg, char *name);

#endif
