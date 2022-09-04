#ifndef __LOG_H
#define __LOG_H

#include "log.h"
#include "config.h"

/**
 * El nombre del fichero de registro por defecto. Para cambiarlo escribe otro
 * nombre diferente aqui.
 */
#ifdef GP2X
#define LOGFILE "phantomaspc.txt"
#else
#ifdef LINUX
#define LOGFILE ".phantomaspc.log"
#else
#define LOGFILE "phantomaspc.log"
#endif
#endif

/**
 * Para registrar un mensaje en el fichero de registro.
 * Escribe mensajes en un fichero de texto, esto es util para ver las cosas que
 * el programa va haciendo, detectar fallos, etc... La forma de uso es
 * ph_log("Hay %d * fallos.",fallos); por ejemplo, normalmente el texto es
 * traducible con lo que habria que introducirlo entre _() para que gettext
 * lo reconozca, es decir, (siguiendo con el ejemplo anterior):
 * ph_log(_("Hay %d fallos."),fallos);
 * @param format: Lo que queremos registrar. En formato como printf.
 */
void ph_log(char *format, ...);

/**
 * Funcion para registrar un mensaje de error de memoria.
 * Estos errores son MUY peligrosos, y aunque la funcion no sale deberias salir
 * al sistema operativo rapidamente despues de detectar uno de estos errores.
 * @param module: Una cadena con el nombre del fichero (o modulo) donde se ha
 * producido el error, ej: main.c
 * @param function: Una cadena con el nombre de la funcion donde se ha producido
 * el error.
 * @param pointer: Una cadena con el nombre del puntero donde se ha producido el
 * error.
 * @param size: El tamano de memoria que se intentaba reservar.
 */
void ph_log_memory_error(char *module, char *function, char *pointer,
                         unsigned long int size);

#endif
