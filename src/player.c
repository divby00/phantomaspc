
#include <string.h>
#include "player.h"
#include "log.h"
#include "trans.h"

PLAYER *ph_init_player(void) {
    PLAYER *aux;

    ph_log(_("- Initiating player: "));
    aux = (struct PLAYER *) malloc(sizeof(struct PLAYER));
    if (aux == NULL) {
        ph_log_memory_error((char *) "player.c", (char *) "ph_init_player", (char *) "aux", sizeof(struct PLAYER));
    }
    memset(aux, 0, sizeof(struct PLAYER));
    ph_log(_("Ok.\n"));
    aux->energy = 238;
    aux->left_energy = 0;
    aux->abu = 0;
    aux->heared = 0;
    aux->firsttimeenergy = 0;
    return aux;
}


void ph_destroy_player(PLAYER *pl) {
    free(pl);
}
