/*
	gfx.c
	Author: Traperic <traperic@gmail.com>
*/

/*
TODO: Que funcione lo de escalar la pantalla.
*/

#include <string.h>
#include "gfx.h"
#include "log.h"
#include "trans.h"

GFX *ph_init_gfx(CFG *cfg) {
    struct virtdim {
        int x[MAXVIRTSCREENS];
        int y[MAXVIRTSCREENS];
    };

    int driver;
    const char *drivermsg[] = {_("windowed"), _("at fullscreen")};
    GFX *aux;
    int i;
    struct virtdim virtdim = {{320},
                              {240}};

    aux = (struct GFX *) malloc(sizeof(struct GFX));
    if (aux == NULL) {
        ph_log_memory_error((char *) "gfx.c", (char *) "ph_init_gfx", (char *) "aux", sizeof(struct GFX));
    }
    memset(aux, 0, sizeof(struct GFX));

#ifdef GP2X
    cfg->fullscreen=1;
    cfg->stretch=0;
    cfg->xres=320;
    cfg->yres=240;
    cfg->stretchx=320;
    cfg->stretchy=240;
#endif

#ifdef DOS
    cfg->fullscreen=1;
    cfg->stretch=0;
    cfg->xres=320;
    cfg->yres=240;
    cfg->stretchx=320;
    cfg->stretchy=240;
#endif

#ifndef GP2X
    if (!cfg->stretch)
        ph_log(_("- Initiating graphic mode (%d x %d @ 16 bpp, running %s): "), cfg->xres, cfg->yres,
               drivermsg[cfg->fullscreen]);
    else
        ph_log(_("- Initiating graphic mode (%d x %d @ 16 bpp, running %s): "), cfg->stretchx, cfg->stretchy,
               drivermsg[cfg->fullscreen]);
#else

#ifdef GP2X
    cfg->fullscreen=1;
#else
    cfg->fullscreen=0;
#endif
    ph_log(_("- Initiating graphic mode (%d x %d @ 16 bpp, running %s): "),cfg->stretchx, cfg->stretchy, drivermsg[cfg->fullscreen]);
#endif

    set_color_depth(16);

    if (cfg->fullscreen) {
        driver = GFX_AUTODETECT;
    } else {
        driver = GFX_AUTODETECT_WINDOWED;
    }

    if (!cfg->stretch) {
        if (set_gfx_mode(driver, cfg->xres, cfg->yres, 0, 0)) {
            ph_log(_("Error: Can't set the graphic mode.\n"));
            if (driver == GFX_AUTODETECT) {
                ph_log(_("- Trying windowed mode: "));
                if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, cfg->xres, cfg->yres, 0, 0)) {
                    ph_log(_("Fatal error.\n"));
                    exit(13);
                } else {
                    set_window_title(_("Phantomas PC 1.3"));
                }
            }
            if (driver == GFX_AUTODETECT_WINDOWED) {
                ph_log(_("- Trying fullscreen mode: "));
                if (set_gfx_mode(GFX_AUTODETECT, cfg->xres, cfg->yres, 0, 0)) {
                    ph_log(_("Fatal error.\n"));
                    exit(13);
                }
            }
        }
    } else {
        if (set_gfx_mode(driver, cfg->stretchx, cfg->stretchy, 0, 0)) {
            ph_log(_("Error: Can't set the graphic mode.\n"));
            if (driver == GFX_AUTODETECT) {
                ph_log(_("- Trying windowed mode: "));
                if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, cfg->stretchx, cfg->stretchy, 0, 0)) {
                    ph_log(_("Fatal error.\n"));
                    exit(13);
                } else {
                    set_window_title(_("Phantomas PC 1.3"));
                }
            }
            if (driver == GFX_AUTODETECT_WINDOWED) {
                ph_log(_("- Trying fullscreen mode: "));
                if (set_gfx_mode(GFX_AUTODETECT, cfg->stretchx, cfg->stretchy, 0, 0)) {
                    ph_log(_("Fatal error.\n"));
                    exit(13);
                } else {
                    set_window_title(_("Phantomas PC 1.3"));
                }
            }
        } else {
            set_window_title(_("Phantomas PC 1.3"));
        }
    }

    if (driver == GFX_AUTODETECT_WINDOWED) set_window_title(_("Phantomas PC 1.3"));

    ph_log(_("Ok.\n"));
    ph_log(_("- Initiating the virtual screens (%d x %d): "), cfg->xres, cfg->yres);

    for (i = 0; i < MAXVIRTSCREENS; i++) {
        aux->virt[i] = create_bitmap(virtdim.x[i], virtdim.y[i]);
        if (aux->virt[i] == NULL) {
            ph_log(_("Fatal error: Can't create the virtual screens.\n"));
            exit(13);
        }
        clear_to_color(aux->virt[i], makecol(0, 0, 0));
    }
    ph_log(_("Ok.\n"));

    ph_log(_("- Initiating phantomas helper: "));
    aux->phhelper = create_bitmap(16, 16);
    if (aux->phhelper == NULL) {
        ph_log(_("Error: Can't create the phantomas helper sprite.\n"));
    }
    ph_log(_("Ok.\n"));
    clear_to_color(aux->phhelper, makecol(0, 0, 0));

    return aux;
}


void ph_destroy_gfx(GFX *gfx) {
    destroy_bitmap(gfx->phhelper);
    for (int i = 0; i < MAXVIRTSCREENS; i++) {
        destroy_bitmap(gfx->virt[i]);
    }
    free(gfx);
}


void ph_draw(GFX *gfx, CFG *cfg) {
    acquire_screen();
    if (cfg->stretch) {
        stretch_blit(gfx->virt[0], screen, 0, 0, 320, 240, 0, 0, cfg->stretchx, cfg->stretchy);
    } else
        blit(gfx->virt[0], screen, 0, 0, 0, 0, 320, 240);

    release_screen();
}
