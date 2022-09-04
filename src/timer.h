#ifndef __TIMER_H
#define __TIMER_H

typedef struct TIMER {
    volatile int frame_counter;
    volatile int last_fps;
    volatile int target_cycle;
    volatile int acycle;
    volatile int menu_target_cycle;
    volatile int script_target_cycle;
} TIMER;

typedef void ( *TFP )(void *);

/**
 * Esta funcion sirve para aumentar la variable target_cycle para conseguir una
 * buena velocidad en cada ordenador.
 * @param t Puntero a TIMER.
 */
void ph_target_incrementor(void *t);

void lp_script_target_incrementor(void *t);

/**
 * Proporciona ayuda para contar las imagenes por segundo del juego.
 * @param t Puntero a un TIMER.
 */
void ph_count_frames(void *t);

/**
 *
 * @param t
 */
void ph_install_timer(TIMER *t);

void *ph_init_timer(void);

void ph_destroy_timer(TIMER *t);

#endif
