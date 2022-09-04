#ifndef __RECORDS_H
#define __RECORDS_H

#include "gfx.h"
#include "cfg.h"
#include "timer.h"
#include "records.h"
#include "texter.h"
#include "sfx.h"

#ifndef CUSTOM_PATH
#define RECORDFILE "records.dat"
#else
#define RECORDFILE "/usr/share/phantomaspc/records.dat"
#endif
#define MAXRECS 10

typedef struct RECORD {
    char name[10];
    signed short int points;
} RECORD;

typedef struct RECORDS {
    int points;
    char *aux;
    char *buf;
    RECORD *r[MAXRECS];
} RECORDS;

RECORDS *ph_init_records(void);

void ph_destroy_records(RECORDS *rec);

void ph_set_records_default(RECORDS *rec);

void ph_input_new_record(RECORDS *rec, char name[10], signed short int points);

char *ph_fix_name(RECORDS *rec, char *name);

void ph_save_record_table(RECORDS *rec);

void ph_load_record_table(RECORDS *rec);

void ph_draw_record_table(RECORDS *rec, GFX *gfx, CFG *cfg, TIMER *t, PHFONT *pfnt);

void ph_draw_input_table(RECORDS *rec, GFX *gfx, CFG *cfg, TIMER *t, PHFONT *pfnt, SFX *sfx);

#endif
