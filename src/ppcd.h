#ifndef __PPCD_H_
#define __PPCD_H_

#include <allegro.h>

#ifdef __cplusplus
extern "C"
{
#endif

int sn_collision(BITMAP *s1, int s1x1, int s1y1, BITMAP *s2, int s2x1, int s2y1);

#ifdef __cplusplus
}
#endif
#endif
