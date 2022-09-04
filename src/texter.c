
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

#include "texter.h"
#include "log.h"
#include "trans.h"
#include "bmpfnts.h"


PHFONT *ph_init_texter(void) {
    PHFONT *aux;

    ph_log(_("- Initiating fonts: "));
    aux = (struct PHFONT *) malloc(sizeof(struct PHFONT));
    if (aux == NULL) {
        ph_log_memory_error((char *) "texter.c", (char *) "ph_init_texter", (char *) "aux", sizeof(struct PHFONT));
    } else {
        ph_log(_("Ok.\n"));
    }

    aux->fnt = aux->ufnt = font;
    memset(aux, 0, sizeof(struct PHFONT));

    return aux;
}


void ph_destroy_texter(PHFONT *pfont) {
    free(pfont);
}


void ph_set_text_properties(PHFONT *pf, int color, int back, char fonttype, char align, char aa) {
    pf->color = color;
    pf->back = back;
    pf->fonttype = fonttype;
    pf->align = align;
    pf->aa = aa;
}


void ph_text(BITMAP *bmp, PHFONT *pf, signed short int x, signed short int y, char *buffer) {
    FONT *f;
    if (pf->fonttype == TXT_TITLE) f = pf->fnt; else f = pf->ufnt;
    f = pf->ufnt;
    if (!pf->align && !pf->aa) textout_ex(bmp, f, buffer, x, y, pf->color, pf->back);
    switch (pf->align) {
        case TXT_LEFT:
            textout_ex(bmp, (FONT *) databmpfnts[0].dat, buffer, x, y, pf->color, pf->back);
            break;
        case TXT_CENTER:
            textout_centre_ex(bmp, (FONT *) databmpfnts[0].dat, buffer, x, y, pf->color, pf->back);
            // 				textout_centre_ex(bmp,f,buffer,x,y,pf->color,pf->back);
            break;
        case TXT_RIGHT:
            textout_right_ex(bmp, (FONT *) databmpfnts[0].dat, buffer, x, y, pf->color, pf->back);
            // 				textout_right_ex(bmp,f,buffer,x,y,pf->color,pf->back);
            break;
    }
}


int ph_text_len(PHFONT *pfont, char *buffer) {
    int len = 0;

    if (pfont->fonttype == TXT_TITLE)
        len = text_length(pfont->ufnt, buffer);
    else
        len = text_length(pfont->ufnt, buffer);
    return len;
}


void ph_printf(BITMAP *bmp, PHFONT *pf, signed short int x, signed short int y, char *buf, ...) {
    va_list args;
    char *buffer;
    FONT *f;

    va_start(args, buf);
    buffer = (char *) malloc(512);
    memset(buffer, 0, sizeof(char) * 512);
#ifndef DOS
    vsnprintf(buffer, 512, buf, args);
#endif
    if (pf->fonttype == TXT_TITLE) f = pf->fnt; else f = pf->ufnt;
    f = pf->fnt;
    (void)f;
    if (!pf->align && !pf->aa) textprintf_ex(bmp, (FONT *) databmpfnts[0].dat, x, y, pf->color, pf->back, "%s", buffer);
    switch (pf->align) {
        case TXT_LEFT:
            textprintf_ex(bmp, (FONT *) databmpfnts[0].dat, x, y, pf->color, -1, "%s", buffer);
            break;
        case TXT_CENTER:
            textprintf_centre_ex(bmp, (FONT *) databmpfnts[0].dat, x, y, pf->color, -1, "%s", buffer);
            break;
        case TXT_RIGHT:
            textprintf_right_ex(bmp, (FONT *) databmpfnts[0].dat, x, y, pf->color, -1, "%s", buffer);
            break;
    }

    va_end(args);
    free(buffer);
}


void ph_shprintf(BITMAP *bmp, PHFONT *pf, signed short int x, signed short int y, char *buf, ...) {
    va_list args;
    char *buffer;
    FONT *f;

    va_start(args, buf);
    buffer = (char *) malloc(512);
    memset(buffer, 0, sizeof(char) * 512);
#ifndef DOS
    vsnprintf(buffer, 512, buf, args);
#endif
    if (pf->fonttype == TXT_TITLE) f = pf->fnt; else f = pf->ufnt;
    f = pf->ufnt;

    if (!pf->align && !pf->aa) textprintf_ex(bmp, f, x, y, pf->color, pf->back, "%s", buffer);
    switch (pf->align) {
        case TXT_LEFT:
            textprintf_ex(bmp, f, x, y, pf->color, pf->back, "%s", buffer);
            break;
        case TXT_CENTER:
            textprintf_centre_ex(bmp, f, x, y, pf->color, pf->back, "%s", buffer);
            break;
        case TXT_RIGHT:
            textprintf_right_ex(bmp, f, x, y, pf->color, pf->back, "%s", buffer);
            break;
    }
    va_end(args);
    free(buffer);
}
