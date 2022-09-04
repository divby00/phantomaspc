
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "path.h"
#include "log.h"
#include "trans.h"

char *ph_init_path(void) {
    char *aux;

    aux = (char *) malloc(sizeof(char) * MAXPATHSIZE);
    if (aux == NULL)
        ph_log_memory_error((char *) "path.c", (char *) "ph_get_path", (char *) "aux", sizeof(char) * MAXPATHSIZE);
    return aux;
}


char *ph_get_file_name(CFG *cfg, char *name) {
    memset(cfg->buffer, 0, sizeof(char) * 512);
    strcpy(cfg->buffer, cfg->datadir);
    strcat(cfg->buffer, "/");
    strcat(cfg->buffer, name);
    return cfg->buffer;
}


char *ph_get_path(char *path, char *buffer) {
    FILE *f, *f1;
    memset(path, 0, sizeof(char) * MAXPATHSIZE);
    strcpy(path, buffer);
    f = fopen(path, "r");
    if (f == NULL) {
        /* Ok, no está en la ruta normal, mirar a ver si está en el directorio actual */
        /* En sistemas Unix cuya shell ponga el valor de la variable PWD */
        /* TODO Mirar a ver si hay alguna manera portable */
#ifndef WIN32
#ifndef DOS
#ifndef CUSTOM_PATH
        memset(path, 0, sizeof(char) * MAXPATHSIZE);
        strcpy(path, getenv("PWD"));
        path[strlen(path)] = '/';
        strcat(path, buffer);
        f = fopen(path, "r");
        if (f == NULL) {
            ph_log(_("- Error: According to function ph_get_path the file %s doesn't exist.\n"), path);
            return NULL;
        } else {
            fclose(f);
            return path;
        }
#endif
#endif
#endif

        memset(path, 0, sizeof(char) * MAXPATHSIZE);
#ifdef CUSTOM_PATH
		strcat(path, DFLT_DATADIR_CUSTOM);
		strcat(path, buffer);
#else
        strcpy(path, buffer);
#endif
        f1 = fopen(path, "rb");
        if (f1 == NULL) {
            ph_log(_("- Error: According to function ph_get_path the file %s doesn't exist.\n"), path);
            return NULL;
        }
        fclose(f1);
        return path;
    }
    fclose(f);
    return path;
}


void ph_destroy_path(char *path) {
    free(path);
}
