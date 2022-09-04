
#include <allegro.h>
#include <malloc.h>
#include <string.h>
#include "timer.h"
#include "trans.h"
#include "log.h"

void *ph_init_timer(void) {
    TIMER *aux;

    ph_log(_("- Initiating timer: "));
    aux = (struct TIMER *) malloc(sizeof(struct TIMER));
    if (aux == NULL) {
        ph_log_memory_error((char *) "init.c", (char *) "ph_init_timer", (char *) "aux", sizeof(struct TIMER));
    }
    memset(aux, 0, sizeof(struct TIMER));
    ph_log(_("Ok.\n"));
    ph_install_timer(aux);
    return aux;
}


void ph_destroy_timer(TIMER *t) {
    TFP funcpoin1;
    TFP funcpoin2;
    TFP funcpoin3;

    funcpoin1 = &ph_count_frames;
    funcpoin2 = &ph_target_incrementor;
    funcpoin3 = &lp_script_target_incrementor;
    remove_param_int(funcpoin1, t);
    remove_param_int(funcpoin2, t);
    remove_param_int(funcpoin3, t);
    free(t);
}


void ph_target_incrementor(void *t) {
    TIMER *aux;

    aux = (TIMER *) t;
    aux->target_cycle++;
}


END_OF_FUNCTION(ph_target_incrementor)

void lp_script_target_incrementor(void *t) {
    TIMER *aux;

    aux = (TIMER *) t;
    aux->script_target_cycle++;
}


END_OF_FUNCTION(lp_script_target_incrementor)

void ph_count_frames(void *t) {
    TIMER *aux;

    aux = (TIMER *) t;
    aux->last_fps = aux->frame_counter;
    aux->frame_counter = 0;
}


END_OF_FUNCTION(ph_count_frames)

void ph_install_timer(TIMER *t) {
    TFP funcpoin1;
    TFP funcpoin2;
    TFP funcpoin3;

    funcpoin1 = &ph_count_frames;
    funcpoin2 = &ph_target_incrementor;
    funcpoin3 = &lp_script_target_incrementor;
    LOCK_VARIABLE(t->target_cycle);
    LOCK_VARIABLE(t->menu_target_cycle);
    LOCK_VARIABLE(t->script_target_cycle);
    LOCK_VARIABLE(t->acycle);
    LOCK_VARIABLE(t->frame_counter);
    LOCK_VARIABLE(t->last_fps);
    LOCK_FUNCTION(ph_count_frames);
    LOCK_FUNCTION(ph_target_incrementor);
    LOCK_FUNCTION(lp_script_target_incrementor);
    t->acycle = 0;
    t->frame_counter = 0;
    t->last_fps = 0;
    t->target_cycle = 0;
    ph_log(_("- Initiating timer (ph_count_frames): "));
    (install_param_int_ex(funcpoin1, t, BPS_TO_TIMER(1))) ? ph_log(_("Error.\n")) : ph_log(_("Ok.\n"));
    ph_log(_("- Initiating timer (ph_target_incrementor): "));
    (install_param_int_ex(funcpoin2, t, BPS_TO_TIMER(18))) ? ph_log(_("Error.\n")) : ph_log(_("Ok.\n"));
    ph_log(_("- Initiating timer (lp_script_target_incrementor): "));
    (install_param_int_ex(funcpoin3, t, BPS_TO_TIMER(12))) ? ph_log(_("Error.\n")) : ph_log(_("Ok.\n"));
}
