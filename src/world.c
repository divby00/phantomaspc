
#include <string.h>
#include "world.h"
#include "trans.h"
#include "log.h"
#include "cfg.h"
#include "path.h"

WORLD *ph_init_world(void) {
    WORLD *aux;
    unsigned char *buf;
    unsigned char *buf1;

    ph_log(_("- Initiating world data: "));

    aux = (struct WORLD *) malloc(sizeof(struct WORLD));
    if (aux == NULL) {
        ph_log_memory_error((char *) "world.c", (char *) "ph_init_world", (char *) "aux", sizeof(struct WORLD));
    }
    memset(aux, 0, sizeof(struct WORLD));

    buf = (unsigned char *) malloc(sizeof(unsigned short int) * MAXWORLDROOMS * XMAXTILE * YMAXTILE);
    if (buf == NULL) {
        ph_log_memory_error((char *) "world.c", (char *) "ph_init_world", (char *) "buf",
                            sizeof(unsigned short int) * MAXWORLDROOMS * YMAXTILE * XMAXTILE);
    }
    memset(buf, 0, sizeof(unsigned short int) * MAXWORLDROOMS * XMAXTILE * YMAXTILE);

    buf1 = (unsigned char *) malloc(sizeof(unsigned short int) * MAXWORLDROOMS * XMAXTILE * YMAXTILE);
    if (buf1 == NULL) {
        ph_log_memory_error((char *) "world.c", (char *) "ph_init_world", (char *) "buf1",
                            sizeof(unsigned short int) * MAXWORLDROOMS * YMAXTILE * XMAXTILE);
    }
    memset(buf1, 0, sizeof(unsigned short int) * MAXWORLDROOMS * XMAXTILE * YMAXTILE);

    aux->decdata = buf;
    aux->crossdata = buf1;

    memset(aux->visited_rooms, 0, sizeof(unsigned char) * MAXWORLDROOMS);

    aux->odd = 0;
    aux->xg = 0;
    ph_log(_("Ok.\n"));
    return aux;
}


void ph_destroy_world(WORLD *w) {
    free(w->crossdata);
    free(w->decdata);
    free(w);
}


void ph_save_world_data(WORLD *w, char *path) {
    PACKFILE *f;
    f = pack_fopen(ph_get_path(path, (char *) "data/phantwld.dat"), "w");
    pack_fwrite(w->decdata, sizeof(short int) * XMAXTILE * YMAXTILE * MAXWORLDROOMS, f);
    pack_fwrite(w->crossdata, sizeof(short int) * XMAXTILE * YMAXTILE * MAXWORLDROOMS, f);
    pack_fclose(f);
}


WORLD *ph_load_world_data(WORLD *w, char *path) {
    PACKFILE *f;
    f = pack_fopen(ph_get_path(path, (char *) "data/phantwld.dat"), "r");
    if (f != NULL) {
        pack_fread(w->decdata, sizeof(short int) * XMAXTILE * YMAXTILE * MAXWORLDROOMS, f);
        pack_fread(w->crossdata, sizeof(short int) * XMAXTILE * YMAXTILE * MAXWORLDROOMS, f);
        pack_fclose(f);
        return w;
    }
    return w;
}


WORLD *ph_load_world_data_alt(WORLD *w, DATA *data) {
    DATAFILE *aux;
    char *buf;
    unsigned long int size = 0L;
    aux = (DATAFILE *) find_datafile_object(data->df, "PHANTWLD_DAT");
    ASSERT(aux == NULL)
    size = aux->size;
    buf = (char *) malloc((sizeof(char) * size) + 1);
    ASSERT(buf != NULL)
    memset(buf, 0, (sizeof(char) * size) + 1);
    memcpy(buf, aux->dat, size);
    memset(w->decdata, 0, sizeof(short int) * (XMAXTILE * YMAXTILE * MAXWORLDROOMS));
    memset(w->crossdata, 0, sizeof(short int) * (XMAXTILE * YMAXTILE * MAXWORLDROOMS));
    w->decdata = (unsigned char *) memcpy(w->decdata, buf, sizeof(short int) * (XMAXTILE * YMAXTILE * MAXWORLDROOMS));
    ASSERT(w->decdata != NULL)
    w->crossdata = (unsigned char *) memcpy(w->crossdata,
                                            buf + sizeof(short int) * (XMAXTILE * YMAXTILE * MAXWORLDROOMS),
                                            sizeof(short int) * (XMAXTILE * YMAXTILE * MAXWORLDROOMS));
    ASSERT(w->crossdata != NULL)
    free(buf);
    return w;
}


void ph_get_room_data(WORLD *w, int room, PLAYER *pl) {
    for (int y = 0; y < YMAXTILE; y++) {
        for (int x = 0; x < XMAXTILE; x++) {
            w->room[x][y] = w->decdata[((XMAXTILE * y) + x) + (room * XMAXTILE * YMAXTILE)];
            w->cross[x][y] = w->crossdata[((XMAXTILE * y) + x) + (room * XMAXTILE * YMAXTILE)];
        }
    }
    if (w->actroom == 57) {
        if (!pl->opendoor) {
            w->cross[1][7] = 1;
            w->cross[1][9] = 1;
            w->cross[1][11] = 1;
            w->cross[1][8] = 1;
            w->cross[1][10] = 1;
        } else {
            w->cross[1][7] = 0;
            w->cross[1][9] = 0;
            w->cross[1][11] = 0;
            w->cross[1][8] = 0;
            w->cross[1][10] = 0;
        }
        if (pl->explotedoor == 2 && fixtoi(pl->x) >= 32) {
            w->cross[1][7] = 1;
            w->cross[1][9] = 1;
            w->cross[1][11] = 1;
            w->cross[1][8] = 1;
            w->cross[1][10] = 1;
        }
    }

    if (w->actroom == 56) {
        if (!pl->treasure || pl->explotedoor) {
            w->cross[29][7] = 0;
            w->cross[29][8] = 0;
            w->cross[29][9] = 0;
            w->cross[29][10] = 0;
            w->cross[29][11] = 0;
        } else {
            w->cross[28][7] = 1;
            w->cross[28][8] = 1;
            w->cross[28][9] = 1;
            w->cross[28][10] = 1;
            w->cross[28][11] = 1;
        }
    }

    if (w->actroom == 5) {
        if (pl->inrocket || pl->rocket) {
            for (int y = 9; y < 13; y++) {
                for (int x = 12; x < 18; x++) {
                    w->cross[x][y] = 0;
                }
            }
        }
    }

    pl->just_enter = 0;
}
