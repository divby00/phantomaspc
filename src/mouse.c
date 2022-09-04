#include "mouse.h"
#include "log.h"
#include "trans.h"

MOUSE *ph_init_mouse(void) {
    MOUSE *aux;

    ph_log(_("- Initiating mouse: "));
    aux = (struct MOUSE *) malloc(sizeof(struct MOUSE));
    if (aux == NULL)
        ph_log_memory_error((char *) "mouse.c", (char *) "ph_init_mouse", (char *) "aux", sizeof(struct MOUSE));
    aux->x = SCREEN_W << 1;
    aux->y = SCREEN_H << 1;
    aux->cursor = NULL;
    if (install_mouse() == -1) {
        ph_log(_("Error.\n"));
        aux->imouse = 0;
    } else {
        ph_log(_("Ok.\n"));
        aux->imouse = 1;
    }
    return aux;
}


void ph_destroy_mouse(MOUSE *m) {
    if (m->imouse) remove_mouse();
    free(m);
}


MOUSE *ph_get_mouse_data(MOUSE *m) {
    unsigned int pos = 0;

    if (!m->imouse) return 0;
    m->x = 0;
    m->y = 0;
    m->b1 = 0;
    m->b2 = 0;
    poll_mouse();
    pos = mouse_pos;
    m->x = pos >> 16;
    m->y = pos & 0x0000ffff;

    if (mouse_b & 1) {
        m->b1 = 1;
    }
    return m;
}


void ph_draw_mouse(MOUSE *m, BITMAP *dst) {
    if (!m->imouse) return;
    m = ph_get_mouse_data(m);
    draw_sprite(dst, m->cursor, m->x, m->y);
}
