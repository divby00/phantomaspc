#ifndef __FADES_H
#define __FADES_H

#include "config.h"

void ph_fade_out(int speed, CFG *cfg);

void ph_fade_in(BITMAP *, int speed);

void ph_fade_image(int speed, BITMAP *dst);

#endif
