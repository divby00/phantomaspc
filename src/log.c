/*
	log.c
	Description: This is based in a piece of code by Robert 'Bob' Ohannessian
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "log.h"
#include "trans.h"

void ph_log(char *format, ...) {
    FILE *file;
    va_list args;
    static char init = 1;
    static char disable_log = 0;
    unsigned long int size = 0L;
    time_t ti;
    char msg[1024];

    if (init) {
        file = fopen(LOGFILE, "at+");
        if (file == NULL) {
            disable_log = 1;
        } else {
            fseek(file, 0L, SEEK_END);
            size = ftell(file);
            fseek(file, 0L, SEEK_SET);
            if (size >= 10000) {
                fclose(file);
                delete_file(LOGFILE);
            }
        }
    }

    if (!disable_log) {
        va_start(args, format);
        file = fopen(LOGFILE, "at+");

        if (init) {
            ti = time((time_t *) NULL);

            sprintf(msg, "%s", _("\n\n- - - Begin the log - - -\n"));
            fprintf(file, "%s", msg);
            fprintf(file, _("Date and time: %s\n"), ctime(&ti));
            init = 0;
        }
        vfprintf(file, format, args);
        fflush(file);
        fclose(file);
        va_end(args);
    }
}


void ph_log_memory_error(char *module, char *function, char *pointer, unsigned long int size) {
    char *aux;

    aux = (char *) malloc(sizeof(char) * 256);

    if (aux == NULL) {
        ph_log(_("- Fatal error: memory allocation error, module: log.c, function: ph_log_memory_error, pointer: aux, %ld bytes.\n"),
               sizeof(char) * 256);
        exit(-1);
    }
    memset(aux, 0, sizeof(char) * 256);

    sprintf(aux, _("- Fatal error: memory allocation error, module: %s, function: %s, pointer: %s, %ld bytes.\n"),
            module, function, pointer, size);
    ph_log(aux);
    free(aux);
    exit(-13);
}
