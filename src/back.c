/*
	Phantomas PC
	Author: Traperic <traperic@gmail.com>
*/

#include "back.h"

void ph_set_background_image(WORLD *world, unsigned char index) {
    world->backdata = index;
}


void ph_draw_back_image(WORLD *world, GFX *gfx) {
    if (world->actroom == 67) {
        draw_sprite(gfx->virt[0], gfx->backspr[9], world->xg + (X_DESP / 2), Y_DESP / 2);
        draw_sprite(gfx->virt[0], gfx->backspr[9], world->xg + (X_DESP / 2) + 480, Y_DESP / 2);
    }
    if (world->actroom != 7 && world->actroom != 67) {
        draw_sprite(gfx->virt[0], gfx->backspr[world->backdata], X_DESP / 2, Y_DESP / 2);
    }
}


void ph_move_back_image(WORLD *world) {
    if (world->actroom == 67) {
        world->xg -= 4;
        if (world->xg < -480) {
            world->xg = 0;
        }
        if (world->xg >= 480) {
            world->xg = 0;
        }
    }
}
