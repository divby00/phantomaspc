/* bmpfnts.c
 * 
 *  Source for data encoded from fontdat.dat .
 *  Do not hand edit.
 */

#include <allegro.h>
#include <allegro/internal/aintern.h>



static DATAFILE_PROPERTY fterm_bmp_prop[] = {
    { "11-15-2008, 10:18", DAT_ID('D', 'A', 'T', 'E') },
    { "FTERM_BMP", DAT_ID('N', 'A', 'M', 'E') },
    { "/home/traperic/PhantomasPC/data/fonts/bitmap/fterm"
      ".bmp", DAT_ID('O', 'R', 'I', 'G') },
    { 0, DAT_END }
};

static unsigned char fterm_bmp_glyph32_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph32 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph32_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph32_lines + 0,
      fterm_bmp_glyph32_lines + 5,
      fterm_bmp_glyph32_lines + 10,
      fterm_bmp_glyph32_lines + 15,
      fterm_bmp_glyph32_lines + 20,
      fterm_bmp_glyph32_lines + 25,
      fterm_bmp_glyph32_lines + 30,
      fterm_bmp_glyph32_lines + 35,
      fterm_bmp_glyph32_lines + 40,
      fterm_bmp_glyph32_lines + 45,
      fterm_bmp_glyph32_lines + 50,
      fterm_bmp_glyph32_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph33_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph33 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph33_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph33_lines + 0,
      fterm_bmp_glyph33_lines + 5,
      fterm_bmp_glyph33_lines + 10,
      fterm_bmp_glyph33_lines + 15,
      fterm_bmp_glyph33_lines + 20,
      fterm_bmp_glyph33_lines + 25,
      fterm_bmp_glyph33_lines + 30,
      fterm_bmp_glyph33_lines + 35,
      fterm_bmp_glyph33_lines + 40,
      fterm_bmp_glyph33_lines + 45,
      fterm_bmp_glyph33_lines + 50,
      fterm_bmp_glyph33_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph34_lines[] = 
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph34 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph34_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph34_lines + 0,
      fterm_bmp_glyph34_lines + 5,
      fterm_bmp_glyph34_lines + 10,
      fterm_bmp_glyph34_lines + 15,
      fterm_bmp_glyph34_lines + 20,
      fterm_bmp_glyph34_lines + 25,
      fterm_bmp_glyph34_lines + 30,
      fterm_bmp_glyph34_lines + 35,
      fterm_bmp_glyph34_lines + 40,
      fterm_bmp_glyph34_lines + 45,
      fterm_bmp_glyph34_lines + 50,
      fterm_bmp_glyph34_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph35_lines[] = 
"\0\0\0\0\0"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\x3\x3\x3\x3\x3"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\x3\x3\x3\x3\x3"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph35 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph35_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph35_lines + 0,
      fterm_bmp_glyph35_lines + 5,
      fterm_bmp_glyph35_lines + 10,
      fterm_bmp_glyph35_lines + 15,
      fterm_bmp_glyph35_lines + 20,
      fterm_bmp_glyph35_lines + 25,
      fterm_bmp_glyph35_lines + 30,
      fterm_bmp_glyph35_lines + 35,
      fterm_bmp_glyph35_lines + 40,
      fterm_bmp_glyph35_lines + 45,
      fterm_bmp_glyph35_lines + 50,
      fterm_bmp_glyph35_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph36_lines[] = 
"\0\0\0\0\0"
"\0\x3\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph36 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph36_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph36_lines + 0,
      fterm_bmp_glyph36_lines + 5,
      fterm_bmp_glyph36_lines + 10,
      fterm_bmp_glyph36_lines + 15,
      fterm_bmp_glyph36_lines + 20,
      fterm_bmp_glyph36_lines + 25,
      fterm_bmp_glyph36_lines + 30,
      fterm_bmp_glyph36_lines + 35,
      fterm_bmp_glyph36_lines + 40,
      fterm_bmp_glyph36_lines + 45,
      fterm_bmp_glyph36_lines + 50,
      fterm_bmp_glyph36_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph37_lines[] = 
"\0\0\0\0\0"
"\x3\x3\0\x3\0"
"\x3\x3\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\x3\0\x3\x3\0"
"\x3\0\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph37 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph37_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph37_lines + 0,
      fterm_bmp_glyph37_lines + 5,
      fterm_bmp_glyph37_lines + 10,
      fterm_bmp_glyph37_lines + 15,
      fterm_bmp_glyph37_lines + 20,
      fterm_bmp_glyph37_lines + 25,
      fterm_bmp_glyph37_lines + 30,
      fterm_bmp_glyph37_lines + 35,
      fterm_bmp_glyph37_lines + 40,
      fterm_bmp_glyph37_lines + 45,
      fterm_bmp_glyph37_lines + 50,
      fterm_bmp_glyph37_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph38_lines[] = 
"\0\0\0\0\0"
"\0\x3\0\0\0"
"\x3\0\x3\0\0"
"\x3\0\x3\0\0"
"\x3\0\x3\0\0"
"\0\x3\0\0\0"
"\x3\0\x3\0\x3"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\x3"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph38 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph38_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph38_lines + 0,
      fterm_bmp_glyph38_lines + 5,
      fterm_bmp_glyph38_lines + 10,
      fterm_bmp_glyph38_lines + 15,
      fterm_bmp_glyph38_lines + 20,
      fterm_bmp_glyph38_lines + 25,
      fterm_bmp_glyph38_lines + 30,
      fterm_bmp_glyph38_lines + 35,
      fterm_bmp_glyph38_lines + 40,
      fterm_bmp_glyph38_lines + 45,
      fterm_bmp_glyph38_lines + 50,
      fterm_bmp_glyph38_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph39_lines[] = 
"\0\0\x3\x3\0"
"\0\0\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph39 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph39_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph39_lines + 0,
      fterm_bmp_glyph39_lines + 5,
      fterm_bmp_glyph39_lines + 10,
      fterm_bmp_glyph39_lines + 15,
      fterm_bmp_glyph39_lines + 20,
      fterm_bmp_glyph39_lines + 25,
      fterm_bmp_glyph39_lines + 30,
      fterm_bmp_glyph39_lines + 35,
      fterm_bmp_glyph39_lines + 40,
      fterm_bmp_glyph39_lines + 45,
      fterm_bmp_glyph39_lines + 50,
      fterm_bmp_glyph39_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph40_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph40 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph40_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph40_lines + 0,
      fterm_bmp_glyph40_lines + 5,
      fterm_bmp_glyph40_lines + 10,
      fterm_bmp_glyph40_lines + 15,
      fterm_bmp_glyph40_lines + 20,
      fterm_bmp_glyph40_lines + 25,
      fterm_bmp_glyph40_lines + 30,
      fterm_bmp_glyph40_lines + 35,
      fterm_bmp_glyph40_lines + 40,
      fterm_bmp_glyph40_lines + 45,
      fterm_bmp_glyph40_lines + 50,
      fterm_bmp_glyph40_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph41_lines[] = 
"\0\0\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph41 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph41_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph41_lines + 0,
      fterm_bmp_glyph41_lines + 5,
      fterm_bmp_glyph41_lines + 10,
      fterm_bmp_glyph41_lines + 15,
      fterm_bmp_glyph41_lines + 20,
      fterm_bmp_glyph41_lines + 25,
      fterm_bmp_glyph41_lines + 30,
      fterm_bmp_glyph41_lines + 35,
      fterm_bmp_glyph41_lines + 40,
      fterm_bmp_glyph41_lines + 45,
      fterm_bmp_glyph41_lines + 50,
      fterm_bmp_glyph41_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph42_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\x3\0\x3\0\x3"
"\0\x3\x3\x3\0"
"\0\x3\x3\x3\0"
"\x3\0\x3\0\x3"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph42 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph42_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph42_lines + 0,
      fterm_bmp_glyph42_lines + 5,
      fterm_bmp_glyph42_lines + 10,
      fterm_bmp_glyph42_lines + 15,
      fterm_bmp_glyph42_lines + 20,
      fterm_bmp_glyph42_lines + 25,
      fterm_bmp_glyph42_lines + 30,
      fterm_bmp_glyph42_lines + 35,
      fterm_bmp_glyph42_lines + 40,
      fterm_bmp_glyph42_lines + 45,
      fterm_bmp_glyph42_lines + 50,
      fterm_bmp_glyph42_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph43_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\x3\x3\x3\x3\x3"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph43 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph43_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph43_lines + 0,
      fterm_bmp_glyph43_lines + 5,
      fterm_bmp_glyph43_lines + 10,
      fterm_bmp_glyph43_lines + 15,
      fterm_bmp_glyph43_lines + 20,
      fterm_bmp_glyph43_lines + 25,
      fterm_bmp_glyph43_lines + 30,
      fterm_bmp_glyph43_lines + 35,
      fterm_bmp_glyph43_lines + 40,
      fterm_bmp_glyph43_lines + 45,
      fterm_bmp_glyph43_lines + 50,
      fterm_bmp_glyph43_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph44_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph44 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph44_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph44_lines + 0,
      fterm_bmp_glyph44_lines + 5,
      fterm_bmp_glyph44_lines + 10,
      fterm_bmp_glyph44_lines + 15,
      fterm_bmp_glyph44_lines + 20,
      fterm_bmp_glyph44_lines + 25,
      fterm_bmp_glyph44_lines + 30,
      fterm_bmp_glyph44_lines + 35,
      fterm_bmp_glyph44_lines + 40,
      fterm_bmp_glyph44_lines + 45,
      fterm_bmp_glyph44_lines + 50,
      fterm_bmp_glyph44_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph45_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph45 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph45_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph45_lines + 0,
      fterm_bmp_glyph45_lines + 5,
      fterm_bmp_glyph45_lines + 10,
      fterm_bmp_glyph45_lines + 15,
      fterm_bmp_glyph45_lines + 20,
      fterm_bmp_glyph45_lines + 25,
      fterm_bmp_glyph45_lines + 30,
      fterm_bmp_glyph45_lines + 35,
      fterm_bmp_glyph45_lines + 40,
      fterm_bmp_glyph45_lines + 45,
      fterm_bmp_glyph45_lines + 50,
      fterm_bmp_glyph45_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph46_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph46 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph46_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph46_lines + 0,
      fterm_bmp_glyph46_lines + 5,
      fterm_bmp_glyph46_lines + 10,
      fterm_bmp_glyph46_lines + 15,
      fterm_bmp_glyph46_lines + 20,
      fterm_bmp_glyph46_lines + 25,
      fterm_bmp_glyph46_lines + 30,
      fterm_bmp_glyph46_lines + 35,
      fterm_bmp_glyph46_lines + 40,
      fterm_bmp_glyph46_lines + 45,
      fterm_bmp_glyph46_lines + 50,
      fterm_bmp_glyph46_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph47_lines[] = 
"\0\0\0\0\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph47 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph47_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph47_lines + 0,
      fterm_bmp_glyph47_lines + 5,
      fterm_bmp_glyph47_lines + 10,
      fterm_bmp_glyph47_lines + 15,
      fterm_bmp_glyph47_lines + 20,
      fterm_bmp_glyph47_lines + 25,
      fterm_bmp_glyph47_lines + 30,
      fterm_bmp_glyph47_lines + 35,
      fterm_bmp_glyph47_lines + 40,
      fterm_bmp_glyph47_lines + 45,
      fterm_bmp_glyph47_lines + 50,
      fterm_bmp_glyph47_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph48_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph48 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph48_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph48_lines + 0,
      fterm_bmp_glyph48_lines + 5,
      fterm_bmp_glyph48_lines + 10,
      fterm_bmp_glyph48_lines + 15,
      fterm_bmp_glyph48_lines + 20,
      fterm_bmp_glyph48_lines + 25,
      fterm_bmp_glyph48_lines + 30,
      fterm_bmp_glyph48_lines + 35,
      fterm_bmp_glyph48_lines + 40,
      fterm_bmp_glyph48_lines + 45,
      fterm_bmp_glyph48_lines + 50,
      fterm_bmp_glyph48_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph49_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\x3\x3\0\0"
"\x3\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph49 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph49_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph49_lines + 0,
      fterm_bmp_glyph49_lines + 5,
      fterm_bmp_glyph49_lines + 10,
      fterm_bmp_glyph49_lines + 15,
      fterm_bmp_glyph49_lines + 20,
      fterm_bmp_glyph49_lines + 25,
      fterm_bmp_glyph49_lines + 30,
      fterm_bmp_glyph49_lines + 35,
      fterm_bmp_glyph49_lines + 40,
      fterm_bmp_glyph49_lines + 45,
      fterm_bmp_glyph49_lines + 50,
      fterm_bmp_glyph49_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph50_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph50 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph50_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph50_lines + 0,
      fterm_bmp_glyph50_lines + 5,
      fterm_bmp_glyph50_lines + 10,
      fterm_bmp_glyph50_lines + 15,
      fterm_bmp_glyph50_lines + 20,
      fterm_bmp_glyph50_lines + 25,
      fterm_bmp_glyph50_lines + 30,
      fterm_bmp_glyph50_lines + 35,
      fterm_bmp_glyph50_lines + 40,
      fterm_bmp_glyph50_lines + 45,
      fterm_bmp_glyph50_lines + 50,
      fterm_bmp_glyph50_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph51_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph51 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph51_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph51_lines + 0,
      fterm_bmp_glyph51_lines + 5,
      fterm_bmp_glyph51_lines + 10,
      fterm_bmp_glyph51_lines + 15,
      fterm_bmp_glyph51_lines + 20,
      fterm_bmp_glyph51_lines + 25,
      fterm_bmp_glyph51_lines + 30,
      fterm_bmp_glyph51_lines + 35,
      fterm_bmp_glyph51_lines + 40,
      fterm_bmp_glyph51_lines + 45,
      fterm_bmp_glyph51_lines + 50,
      fterm_bmp_glyph51_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph52_lines[] = 
"\0\0\0\0\0"
"\0\0\0\x3\0"
"\0\0\x3\x3\0"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph52 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph52_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph52_lines + 0,
      fterm_bmp_glyph52_lines + 5,
      fterm_bmp_glyph52_lines + 10,
      fterm_bmp_glyph52_lines + 15,
      fterm_bmp_glyph52_lines + 20,
      fterm_bmp_glyph52_lines + 25,
      fterm_bmp_glyph52_lines + 30,
      fterm_bmp_glyph52_lines + 35,
      fterm_bmp_glyph52_lines + 40,
      fterm_bmp_glyph52_lines + 45,
      fterm_bmp_glyph52_lines + 50,
      fterm_bmp_glyph52_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph53_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\0\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph53 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph53_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph53_lines + 0,
      fterm_bmp_glyph53_lines + 5,
      fterm_bmp_glyph53_lines + 10,
      fterm_bmp_glyph53_lines + 15,
      fterm_bmp_glyph53_lines + 20,
      fterm_bmp_glyph53_lines + 25,
      fterm_bmp_glyph53_lines + 30,
      fterm_bmp_glyph53_lines + 35,
      fterm_bmp_glyph53_lines + 40,
      fterm_bmp_glyph53_lines + 45,
      fterm_bmp_glyph53_lines + 50,
      fterm_bmp_glyph53_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph54_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\x3\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph54 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph54_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph54_lines + 0,
      fterm_bmp_glyph54_lines + 5,
      fterm_bmp_glyph54_lines + 10,
      fterm_bmp_glyph54_lines + 15,
      fterm_bmp_glyph54_lines + 20,
      fterm_bmp_glyph54_lines + 25,
      fterm_bmp_glyph54_lines + 30,
      fterm_bmp_glyph54_lines + 35,
      fterm_bmp_glyph54_lines + 40,
      fterm_bmp_glyph54_lines + 45,
      fterm_bmp_glyph54_lines + 50,
      fterm_bmp_glyph54_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph55_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph55 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph55_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph55_lines + 0,
      fterm_bmp_glyph55_lines + 5,
      fterm_bmp_glyph55_lines + 10,
      fterm_bmp_glyph55_lines + 15,
      fterm_bmp_glyph55_lines + 20,
      fterm_bmp_glyph55_lines + 25,
      fterm_bmp_glyph55_lines + 30,
      fterm_bmp_glyph55_lines + 35,
      fterm_bmp_glyph55_lines + 40,
      fterm_bmp_glyph55_lines + 45,
      fterm_bmp_glyph55_lines + 50,
      fterm_bmp_glyph55_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph56_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph56 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph56_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph56_lines + 0,
      fterm_bmp_glyph56_lines + 5,
      fterm_bmp_glyph56_lines + 10,
      fterm_bmp_glyph56_lines + 15,
      fterm_bmp_glyph56_lines + 20,
      fterm_bmp_glyph56_lines + 25,
      fterm_bmp_glyph56_lines + 30,
      fterm_bmp_glyph56_lines + 35,
      fterm_bmp_glyph56_lines + 40,
      fterm_bmp_glyph56_lines + 45,
      fterm_bmp_glyph56_lines + 50,
      fterm_bmp_glyph56_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph57_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\x3\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph57 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph57_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph57_lines + 0,
      fterm_bmp_glyph57_lines + 5,
      fterm_bmp_glyph57_lines + 10,
      fterm_bmp_glyph57_lines + 15,
      fterm_bmp_glyph57_lines + 20,
      fterm_bmp_glyph57_lines + 25,
      fterm_bmp_glyph57_lines + 30,
      fterm_bmp_glyph57_lines + 35,
      fterm_bmp_glyph57_lines + 40,
      fterm_bmp_glyph57_lines + 45,
      fterm_bmp_glyph57_lines + 50,
      fterm_bmp_glyph57_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph58_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph58 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph58_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph58_lines + 0,
      fterm_bmp_glyph58_lines + 5,
      fterm_bmp_glyph58_lines + 10,
      fterm_bmp_glyph58_lines + 15,
      fterm_bmp_glyph58_lines + 20,
      fterm_bmp_glyph58_lines + 25,
      fterm_bmp_glyph58_lines + 30,
      fterm_bmp_glyph58_lines + 35,
      fterm_bmp_glyph58_lines + 40,
      fterm_bmp_glyph58_lines + 45,
      fterm_bmp_glyph58_lines + 50,
      fterm_bmp_glyph58_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph59_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph59 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph59_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph59_lines + 0,
      fterm_bmp_glyph59_lines + 5,
      fterm_bmp_glyph59_lines + 10,
      fterm_bmp_glyph59_lines + 15,
      fterm_bmp_glyph59_lines + 20,
      fterm_bmp_glyph59_lines + 25,
      fterm_bmp_glyph59_lines + 30,
      fterm_bmp_glyph59_lines + 35,
      fterm_bmp_glyph59_lines + 40,
      fterm_bmp_glyph59_lines + 45,
      fterm_bmp_glyph59_lines + 50,
      fterm_bmp_glyph59_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph60_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph60 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph60_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph60_lines + 0,
      fterm_bmp_glyph60_lines + 5,
      fterm_bmp_glyph60_lines + 10,
      fterm_bmp_glyph60_lines + 15,
      fterm_bmp_glyph60_lines + 20,
      fterm_bmp_glyph60_lines + 25,
      fterm_bmp_glyph60_lines + 30,
      fterm_bmp_glyph60_lines + 35,
      fterm_bmp_glyph60_lines + 40,
      fterm_bmp_glyph60_lines + 45,
      fterm_bmp_glyph60_lines + 50,
      fterm_bmp_glyph60_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph61_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph61 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph61_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph61_lines + 0,
      fterm_bmp_glyph61_lines + 5,
      fterm_bmp_glyph61_lines + 10,
      fterm_bmp_glyph61_lines + 15,
      fterm_bmp_glyph61_lines + 20,
      fterm_bmp_glyph61_lines + 25,
      fterm_bmp_glyph61_lines + 30,
      fterm_bmp_glyph61_lines + 35,
      fterm_bmp_glyph61_lines + 40,
      fterm_bmp_glyph61_lines + 45,
      fterm_bmp_glyph61_lines + 50,
      fterm_bmp_glyph61_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph62_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph62 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph62_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph62_lines + 0,
      fterm_bmp_glyph62_lines + 5,
      fterm_bmp_glyph62_lines + 10,
      fterm_bmp_glyph62_lines + 15,
      fterm_bmp_glyph62_lines + 20,
      fterm_bmp_glyph62_lines + 25,
      fterm_bmp_glyph62_lines + 30,
      fterm_bmp_glyph62_lines + 35,
      fterm_bmp_glyph62_lines + 40,
      fterm_bmp_glyph62_lines + 45,
      fterm_bmp_glyph62_lines + 50,
      fterm_bmp_glyph62_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph63_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph63 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph63_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph63_lines + 0,
      fterm_bmp_glyph63_lines + 5,
      fterm_bmp_glyph63_lines + 10,
      fterm_bmp_glyph63_lines + 15,
      fterm_bmp_glyph63_lines + 20,
      fterm_bmp_glyph63_lines + 25,
      fterm_bmp_glyph63_lines + 30,
      fterm_bmp_glyph63_lines + 35,
      fterm_bmp_glyph63_lines + 40,
      fterm_bmp_glyph63_lines + 45,
      fterm_bmp_glyph63_lines + 50,
      fterm_bmp_glyph63_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph64_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\x3\x3\0"
"\x3\0\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph64 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph64_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph64_lines + 0,
      fterm_bmp_glyph64_lines + 5,
      fterm_bmp_glyph64_lines + 10,
      fterm_bmp_glyph64_lines + 15,
      fterm_bmp_glyph64_lines + 20,
      fterm_bmp_glyph64_lines + 25,
      fterm_bmp_glyph64_lines + 30,
      fterm_bmp_glyph64_lines + 35,
      fterm_bmp_glyph64_lines + 40,
      fterm_bmp_glyph64_lines + 45,
      fterm_bmp_glyph64_lines + 50,
      fterm_bmp_glyph64_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph65_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph65 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph65_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph65_lines + 0,
      fterm_bmp_glyph65_lines + 5,
      fterm_bmp_glyph65_lines + 10,
      fterm_bmp_glyph65_lines + 15,
      fterm_bmp_glyph65_lines + 20,
      fterm_bmp_glyph65_lines + 25,
      fterm_bmp_glyph65_lines + 30,
      fterm_bmp_glyph65_lines + 35,
      fterm_bmp_glyph65_lines + 40,
      fterm_bmp_glyph65_lines + 45,
      fterm_bmp_glyph65_lines + 50,
      fterm_bmp_glyph65_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph66_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph66 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph66_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph66_lines + 0,
      fterm_bmp_glyph66_lines + 5,
      fterm_bmp_glyph66_lines + 10,
      fterm_bmp_glyph66_lines + 15,
      fterm_bmp_glyph66_lines + 20,
      fterm_bmp_glyph66_lines + 25,
      fterm_bmp_glyph66_lines + 30,
      fterm_bmp_glyph66_lines + 35,
      fterm_bmp_glyph66_lines + 40,
      fterm_bmp_glyph66_lines + 45,
      fterm_bmp_glyph66_lines + 50,
      fterm_bmp_glyph66_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph67_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph67 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph67_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph67_lines + 0,
      fterm_bmp_glyph67_lines + 5,
      fterm_bmp_glyph67_lines + 10,
      fterm_bmp_glyph67_lines + 15,
      fterm_bmp_glyph67_lines + 20,
      fterm_bmp_glyph67_lines + 25,
      fterm_bmp_glyph67_lines + 30,
      fterm_bmp_glyph67_lines + 35,
      fterm_bmp_glyph67_lines + 40,
      fterm_bmp_glyph67_lines + 45,
      fterm_bmp_glyph67_lines + 50,
      fterm_bmp_glyph67_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph68_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph68 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph68_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph68_lines + 0,
      fterm_bmp_glyph68_lines + 5,
      fterm_bmp_glyph68_lines + 10,
      fterm_bmp_glyph68_lines + 15,
      fterm_bmp_glyph68_lines + 20,
      fterm_bmp_glyph68_lines + 25,
      fterm_bmp_glyph68_lines + 30,
      fterm_bmp_glyph68_lines + 35,
      fterm_bmp_glyph68_lines + 40,
      fterm_bmp_glyph68_lines + 45,
      fterm_bmp_glyph68_lines + 50,
      fterm_bmp_glyph68_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph69_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph69 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph69_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph69_lines + 0,
      fterm_bmp_glyph69_lines + 5,
      fterm_bmp_glyph69_lines + 10,
      fterm_bmp_glyph69_lines + 15,
      fterm_bmp_glyph69_lines + 20,
      fterm_bmp_glyph69_lines + 25,
      fterm_bmp_glyph69_lines + 30,
      fterm_bmp_glyph69_lines + 35,
      fterm_bmp_glyph69_lines + 40,
      fterm_bmp_glyph69_lines + 45,
      fterm_bmp_glyph69_lines + 50,
      fterm_bmp_glyph69_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph70_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph70 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph70_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph70_lines + 0,
      fterm_bmp_glyph70_lines + 5,
      fterm_bmp_glyph70_lines + 10,
      fterm_bmp_glyph70_lines + 15,
      fterm_bmp_glyph70_lines + 20,
      fterm_bmp_glyph70_lines + 25,
      fterm_bmp_glyph70_lines + 30,
      fterm_bmp_glyph70_lines + 35,
      fterm_bmp_glyph70_lines + 40,
      fterm_bmp_glyph70_lines + 45,
      fterm_bmp_glyph70_lines + 50,
      fterm_bmp_glyph70_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph71_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph71 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph71_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph71_lines + 0,
      fterm_bmp_glyph71_lines + 5,
      fterm_bmp_glyph71_lines + 10,
      fterm_bmp_glyph71_lines + 15,
      fterm_bmp_glyph71_lines + 20,
      fterm_bmp_glyph71_lines + 25,
      fterm_bmp_glyph71_lines + 30,
      fterm_bmp_glyph71_lines + 35,
      fterm_bmp_glyph71_lines + 40,
      fterm_bmp_glyph71_lines + 45,
      fterm_bmp_glyph71_lines + 50,
      fterm_bmp_glyph71_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph72_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph72 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph72_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph72_lines + 0,
      fterm_bmp_glyph72_lines + 5,
      fterm_bmp_glyph72_lines + 10,
      fterm_bmp_glyph72_lines + 15,
      fterm_bmp_glyph72_lines + 20,
      fterm_bmp_glyph72_lines + 25,
      fterm_bmp_glyph72_lines + 30,
      fterm_bmp_glyph72_lines + 35,
      fterm_bmp_glyph72_lines + 40,
      fterm_bmp_glyph72_lines + 45,
      fterm_bmp_glyph72_lines + 50,
      fterm_bmp_glyph72_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph73_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph73 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph73_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph73_lines + 0,
      fterm_bmp_glyph73_lines + 5,
      fterm_bmp_glyph73_lines + 10,
      fterm_bmp_glyph73_lines + 15,
      fterm_bmp_glyph73_lines + 20,
      fterm_bmp_glyph73_lines + 25,
      fterm_bmp_glyph73_lines + 30,
      fterm_bmp_glyph73_lines + 35,
      fterm_bmp_glyph73_lines + 40,
      fterm_bmp_glyph73_lines + 45,
      fterm_bmp_glyph73_lines + 50,
      fterm_bmp_glyph73_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph74_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\x3\0\x3\0\0"
"\x3\0\x3\0\0"
"\0\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph74 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph74_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph74_lines + 0,
      fterm_bmp_glyph74_lines + 5,
      fterm_bmp_glyph74_lines + 10,
      fterm_bmp_glyph74_lines + 15,
      fterm_bmp_glyph74_lines + 20,
      fterm_bmp_glyph74_lines + 25,
      fterm_bmp_glyph74_lines + 30,
      fterm_bmp_glyph74_lines + 35,
      fterm_bmp_glyph74_lines + 40,
      fterm_bmp_glyph74_lines + 45,
      fterm_bmp_glyph74_lines + 50,
      fterm_bmp_glyph74_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph75_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\x3\0\0"
"\x3\0\x3\0\0"
"\x3\x3\0\0\0"
"\x3\0\x3\0\0"
"\x3\0\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph75 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph75_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph75_lines + 0,
      fterm_bmp_glyph75_lines + 5,
      fterm_bmp_glyph75_lines + 10,
      fterm_bmp_glyph75_lines + 15,
      fterm_bmp_glyph75_lines + 20,
      fterm_bmp_glyph75_lines + 25,
      fterm_bmp_glyph75_lines + 30,
      fterm_bmp_glyph75_lines + 35,
      fterm_bmp_glyph75_lines + 40,
      fterm_bmp_glyph75_lines + 45,
      fterm_bmp_glyph75_lines + 50,
      fterm_bmp_glyph75_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph76_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph76 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph76_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph76_lines + 0,
      fterm_bmp_glyph76_lines + 5,
      fterm_bmp_glyph76_lines + 10,
      fterm_bmp_glyph76_lines + 15,
      fterm_bmp_glyph76_lines + 20,
      fterm_bmp_glyph76_lines + 25,
      fterm_bmp_glyph76_lines + 30,
      fterm_bmp_glyph76_lines + 35,
      fterm_bmp_glyph76_lines + 40,
      fterm_bmp_glyph76_lines + 45,
      fterm_bmp_glyph76_lines + 50,
      fterm_bmp_glyph76_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph77_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph77 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph77_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph77_lines + 0,
      fterm_bmp_glyph77_lines + 5,
      fterm_bmp_glyph77_lines + 10,
      fterm_bmp_glyph77_lines + 15,
      fterm_bmp_glyph77_lines + 20,
      fterm_bmp_glyph77_lines + 25,
      fterm_bmp_glyph77_lines + 30,
      fterm_bmp_glyph77_lines + 35,
      fterm_bmp_glyph77_lines + 40,
      fterm_bmp_glyph77_lines + 45,
      fterm_bmp_glyph77_lines + 50,
      fterm_bmp_glyph77_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph78_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\0\x3\0"
"\x3\x3\0\x3\0"
"\x3\0\x3\x3\0"
"\x3\0\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph78 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph78_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph78_lines + 0,
      fterm_bmp_glyph78_lines + 5,
      fterm_bmp_glyph78_lines + 10,
      fterm_bmp_glyph78_lines + 15,
      fterm_bmp_glyph78_lines + 20,
      fterm_bmp_glyph78_lines + 25,
      fterm_bmp_glyph78_lines + 30,
      fterm_bmp_glyph78_lines + 35,
      fterm_bmp_glyph78_lines + 40,
      fterm_bmp_glyph78_lines + 45,
      fterm_bmp_glyph78_lines + 50,
      fterm_bmp_glyph78_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph79_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph79 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph79_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph79_lines + 0,
      fterm_bmp_glyph79_lines + 5,
      fterm_bmp_glyph79_lines + 10,
      fterm_bmp_glyph79_lines + 15,
      fterm_bmp_glyph79_lines + 20,
      fterm_bmp_glyph79_lines + 25,
      fterm_bmp_glyph79_lines + 30,
      fterm_bmp_glyph79_lines + 35,
      fterm_bmp_glyph79_lines + 40,
      fterm_bmp_glyph79_lines + 45,
      fterm_bmp_glyph79_lines + 50,
      fterm_bmp_glyph79_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph80_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph80 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph80_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph80_lines + 0,
      fterm_bmp_glyph80_lines + 5,
      fterm_bmp_glyph80_lines + 10,
      fterm_bmp_glyph80_lines + 15,
      fterm_bmp_glyph80_lines + 20,
      fterm_bmp_glyph80_lines + 25,
      fterm_bmp_glyph80_lines + 30,
      fterm_bmp_glyph80_lines + 35,
      fterm_bmp_glyph80_lines + 40,
      fterm_bmp_glyph80_lines + 45,
      fterm_bmp_glyph80_lines + 50,
      fterm_bmp_glyph80_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph81_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\x3\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph81 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph81_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph81_lines + 0,
      fterm_bmp_glyph81_lines + 5,
      fterm_bmp_glyph81_lines + 10,
      fterm_bmp_glyph81_lines + 15,
      fterm_bmp_glyph81_lines + 20,
      fterm_bmp_glyph81_lines + 25,
      fterm_bmp_glyph81_lines + 30,
      fterm_bmp_glyph81_lines + 35,
      fterm_bmp_glyph81_lines + 40,
      fterm_bmp_glyph81_lines + 45,
      fterm_bmp_glyph81_lines + 50,
      fterm_bmp_glyph81_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph82_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\x3\x3\0\0\0"
"\x3\0\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph82 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph82_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph82_lines + 0,
      fterm_bmp_glyph82_lines + 5,
      fterm_bmp_glyph82_lines + 10,
      fterm_bmp_glyph82_lines + 15,
      fterm_bmp_glyph82_lines + 20,
      fterm_bmp_glyph82_lines + 25,
      fterm_bmp_glyph82_lines + 30,
      fterm_bmp_glyph82_lines + 35,
      fterm_bmp_glyph82_lines + 40,
      fterm_bmp_glyph82_lines + 45,
      fterm_bmp_glyph82_lines + 50,
      fterm_bmp_glyph82_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph83_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\0\0"
"\0\x3\x3\0\0"
"\0\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph83 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph83_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph83_lines + 0,
      fterm_bmp_glyph83_lines + 5,
      fterm_bmp_glyph83_lines + 10,
      fterm_bmp_glyph83_lines + 15,
      fterm_bmp_glyph83_lines + 20,
      fterm_bmp_glyph83_lines + 25,
      fterm_bmp_glyph83_lines + 30,
      fterm_bmp_glyph83_lines + 35,
      fterm_bmp_glyph83_lines + 40,
      fterm_bmp_glyph83_lines + 45,
      fterm_bmp_glyph83_lines + 50,
      fterm_bmp_glyph83_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph84_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\x3\x3"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph84 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph84_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph84_lines + 0,
      fterm_bmp_glyph84_lines + 5,
      fterm_bmp_glyph84_lines + 10,
      fterm_bmp_glyph84_lines + 15,
      fterm_bmp_glyph84_lines + 20,
      fterm_bmp_glyph84_lines + 25,
      fterm_bmp_glyph84_lines + 30,
      fterm_bmp_glyph84_lines + 35,
      fterm_bmp_glyph84_lines + 40,
      fterm_bmp_glyph84_lines + 45,
      fterm_bmp_glyph84_lines + 50,
      fterm_bmp_glyph84_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph85_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph85 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph85_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph85_lines + 0,
      fterm_bmp_glyph85_lines + 5,
      fterm_bmp_glyph85_lines + 10,
      fterm_bmp_glyph85_lines + 15,
      fterm_bmp_glyph85_lines + 20,
      fterm_bmp_glyph85_lines + 25,
      fterm_bmp_glyph85_lines + 30,
      fterm_bmp_glyph85_lines + 35,
      fterm_bmp_glyph85_lines + 40,
      fterm_bmp_glyph85_lines + 45,
      fterm_bmp_glyph85_lines + 50,
      fterm_bmp_glyph85_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph86_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph86 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph86_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph86_lines + 0,
      fterm_bmp_glyph86_lines + 5,
      fterm_bmp_glyph86_lines + 10,
      fterm_bmp_glyph86_lines + 15,
      fterm_bmp_glyph86_lines + 20,
      fterm_bmp_glyph86_lines + 25,
      fterm_bmp_glyph86_lines + 30,
      fterm_bmp_glyph86_lines + 35,
      fterm_bmp_glyph86_lines + 40,
      fterm_bmp_glyph86_lines + 45,
      fterm_bmp_glyph86_lines + 50,
      fterm_bmp_glyph86_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph87_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph87 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph87_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph87_lines + 0,
      fterm_bmp_glyph87_lines + 5,
      fterm_bmp_glyph87_lines + 10,
      fterm_bmp_glyph87_lines + 15,
      fterm_bmp_glyph87_lines + 20,
      fterm_bmp_glyph87_lines + 25,
      fterm_bmp_glyph87_lines + 30,
      fterm_bmp_glyph87_lines + 35,
      fterm_bmp_glyph87_lines + 40,
      fterm_bmp_glyph87_lines + 45,
      fterm_bmp_glyph87_lines + 50,
      fterm_bmp_glyph87_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph88_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph88 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph88_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph88_lines + 0,
      fterm_bmp_glyph88_lines + 5,
      fterm_bmp_glyph88_lines + 10,
      fterm_bmp_glyph88_lines + 15,
      fterm_bmp_glyph88_lines + 20,
      fterm_bmp_glyph88_lines + 25,
      fterm_bmp_glyph88_lines + 30,
      fterm_bmp_glyph88_lines + 35,
      fterm_bmp_glyph88_lines + 40,
      fterm_bmp_glyph88_lines + 45,
      fterm_bmp_glyph88_lines + 50,
      fterm_bmp_glyph88_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph89_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\0\x3"
"\x3\0\0\0\x3"
"\x3\0\0\0\x3"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph89 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph89_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph89_lines + 0,
      fterm_bmp_glyph89_lines + 5,
      fterm_bmp_glyph89_lines + 10,
      fterm_bmp_glyph89_lines + 15,
      fterm_bmp_glyph89_lines + 20,
      fterm_bmp_glyph89_lines + 25,
      fterm_bmp_glyph89_lines + 30,
      fterm_bmp_glyph89_lines + 35,
      fterm_bmp_glyph89_lines + 40,
      fterm_bmp_glyph89_lines + 45,
      fterm_bmp_glyph89_lines + 50,
      fterm_bmp_glyph89_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph90_lines[] = 
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph90 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph90_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph90_lines + 0,
      fterm_bmp_glyph90_lines + 5,
      fterm_bmp_glyph90_lines + 10,
      fterm_bmp_glyph90_lines + 15,
      fterm_bmp_glyph90_lines + 20,
      fterm_bmp_glyph90_lines + 25,
      fterm_bmp_glyph90_lines + 30,
      fterm_bmp_glyph90_lines + 35,
      fterm_bmp_glyph90_lines + 40,
      fterm_bmp_glyph90_lines + 45,
      fterm_bmp_glyph90_lines + 50,
      fterm_bmp_glyph90_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph91_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph91 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph91_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph91_lines + 0,
      fterm_bmp_glyph91_lines + 5,
      fterm_bmp_glyph91_lines + 10,
      fterm_bmp_glyph91_lines + 15,
      fterm_bmp_glyph91_lines + 20,
      fterm_bmp_glyph91_lines + 25,
      fterm_bmp_glyph91_lines + 30,
      fterm_bmp_glyph91_lines + 35,
      fterm_bmp_glyph91_lines + 40,
      fterm_bmp_glyph91_lines + 45,
      fterm_bmp_glyph91_lines + 50,
      fterm_bmp_glyph91_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph92_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph92 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph92_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph92_lines + 0,
      fterm_bmp_glyph92_lines + 5,
      fterm_bmp_glyph92_lines + 10,
      fterm_bmp_glyph92_lines + 15,
      fterm_bmp_glyph92_lines + 20,
      fterm_bmp_glyph92_lines + 25,
      fterm_bmp_glyph92_lines + 30,
      fterm_bmp_glyph92_lines + 35,
      fterm_bmp_glyph92_lines + 40,
      fterm_bmp_glyph92_lines + 45,
      fterm_bmp_glyph92_lines + 50,
      fterm_bmp_glyph92_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph93_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph93 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph93_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph93_lines + 0,
      fterm_bmp_glyph93_lines + 5,
      fterm_bmp_glyph93_lines + 10,
      fterm_bmp_glyph93_lines + 15,
      fterm_bmp_glyph93_lines + 20,
      fterm_bmp_glyph93_lines + 25,
      fterm_bmp_glyph93_lines + 30,
      fterm_bmp_glyph93_lines + 35,
      fterm_bmp_glyph93_lines + 40,
      fterm_bmp_glyph93_lines + 45,
      fterm_bmp_glyph93_lines + 50,
      fterm_bmp_glyph93_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph94_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\x3\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph94 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph94_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph94_lines + 0,
      fterm_bmp_glyph94_lines + 5,
      fterm_bmp_glyph94_lines + 10,
      fterm_bmp_glyph94_lines + 15,
      fterm_bmp_glyph94_lines + 20,
      fterm_bmp_glyph94_lines + 25,
      fterm_bmp_glyph94_lines + 30,
      fterm_bmp_glyph94_lines + 35,
      fterm_bmp_glyph94_lines + 40,
      fterm_bmp_glyph94_lines + 45,
      fterm_bmp_glyph94_lines + 50,
      fterm_bmp_glyph94_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph95_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\x3\x3\x3\x3"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph95 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph95_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph95_lines + 0,
      fterm_bmp_glyph95_lines + 5,
      fterm_bmp_glyph95_lines + 10,
      fterm_bmp_glyph95_lines + 15,
      fterm_bmp_glyph95_lines + 20,
      fterm_bmp_glyph95_lines + 25,
      fterm_bmp_glyph95_lines + 30,
      fterm_bmp_glyph95_lines + 35,
      fterm_bmp_glyph95_lines + 40,
      fterm_bmp_glyph95_lines + 45,
      fterm_bmp_glyph95_lines + 50,
      fterm_bmp_glyph95_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph96_lines[] = 
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph96 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph96_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph96_lines + 0,
      fterm_bmp_glyph96_lines + 5,
      fterm_bmp_glyph96_lines + 10,
      fterm_bmp_glyph96_lines + 15,
      fterm_bmp_glyph96_lines + 20,
      fterm_bmp_glyph96_lines + 25,
      fterm_bmp_glyph96_lines + 30,
      fterm_bmp_glyph96_lines + 35,
      fterm_bmp_glyph96_lines + 40,
      fterm_bmp_glyph96_lines + 45,
      fterm_bmp_glyph96_lines + 50,
      fterm_bmp_glyph96_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph97_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\0\0\x3\0"
"\0\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph97 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph97_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph97_lines + 0,
      fterm_bmp_glyph97_lines + 5,
      fterm_bmp_glyph97_lines + 10,
      fterm_bmp_glyph97_lines + 15,
      fterm_bmp_glyph97_lines + 20,
      fterm_bmp_glyph97_lines + 25,
      fterm_bmp_glyph97_lines + 30,
      fterm_bmp_glyph97_lines + 35,
      fterm_bmp_glyph97_lines + 40,
      fterm_bmp_glyph97_lines + 45,
      fterm_bmp_glyph97_lines + 50,
      fterm_bmp_glyph97_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph98_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph98 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph98_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph98_lines + 0,
      fterm_bmp_glyph98_lines + 5,
      fterm_bmp_glyph98_lines + 10,
      fterm_bmp_glyph98_lines + 15,
      fterm_bmp_glyph98_lines + 20,
      fterm_bmp_glyph98_lines + 25,
      fterm_bmp_glyph98_lines + 30,
      fterm_bmp_glyph98_lines + 35,
      fterm_bmp_glyph98_lines + 40,
      fterm_bmp_glyph98_lines + 45,
      fterm_bmp_glyph98_lines + 50,
      fterm_bmp_glyph98_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph99_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\x3\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph99 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph99_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph99_lines + 0,
      fterm_bmp_glyph99_lines + 5,
      fterm_bmp_glyph99_lines + 10,
      fterm_bmp_glyph99_lines + 15,
      fterm_bmp_glyph99_lines + 20,
      fterm_bmp_glyph99_lines + 25,
      fterm_bmp_glyph99_lines + 30,
      fterm_bmp_glyph99_lines + 35,
      fterm_bmp_glyph99_lines + 40,
      fterm_bmp_glyph99_lines + 45,
      fterm_bmp_glyph99_lines + 50,
      fterm_bmp_glyph99_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph100_lines[] = 
"\0\0\0\0\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
"\0\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph100 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph100_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph100_lines + 0,
      fterm_bmp_glyph100_lines + 5,
      fterm_bmp_glyph100_lines + 10,
      fterm_bmp_glyph100_lines + 15,
      fterm_bmp_glyph100_lines + 20,
      fterm_bmp_glyph100_lines + 25,
      fterm_bmp_glyph100_lines + 30,
      fterm_bmp_glyph100_lines + 35,
      fterm_bmp_glyph100_lines + 40,
      fterm_bmp_glyph100_lines + 45,
      fterm_bmp_glyph100_lines + 50,
      fterm_bmp_glyph100_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph101_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\0\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph101 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph101_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph101_lines + 0,
      fterm_bmp_glyph101_lines + 5,
      fterm_bmp_glyph101_lines + 10,
      fterm_bmp_glyph101_lines + 15,
      fterm_bmp_glyph101_lines + 20,
      fterm_bmp_glyph101_lines + 25,
      fterm_bmp_glyph101_lines + 30,
      fterm_bmp_glyph101_lines + 35,
      fterm_bmp_glyph101_lines + 40,
      fterm_bmp_glyph101_lines + 45,
      fterm_bmp_glyph101_lines + 50,
      fterm_bmp_glyph101_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph102_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\x3\x3\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph102 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph102_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph102_lines + 0,
      fterm_bmp_glyph102_lines + 5,
      fterm_bmp_glyph102_lines + 10,
      fterm_bmp_glyph102_lines + 15,
      fterm_bmp_glyph102_lines + 20,
      fterm_bmp_glyph102_lines + 25,
      fterm_bmp_glyph102_lines + 30,
      fterm_bmp_glyph102_lines + 35,
      fterm_bmp_glyph102_lines + 40,
      fterm_bmp_glyph102_lines + 45,
      fterm_bmp_glyph102_lines + 50,
      fterm_bmp_glyph102_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph103_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\x3\x3\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph103 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph103_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph103_lines + 0,
      fterm_bmp_glyph103_lines + 5,
      fterm_bmp_glyph103_lines + 10,
      fterm_bmp_glyph103_lines + 15,
      fterm_bmp_glyph103_lines + 20,
      fterm_bmp_glyph103_lines + 25,
      fterm_bmp_glyph103_lines + 30,
      fterm_bmp_glyph103_lines + 35,
      fterm_bmp_glyph103_lines + 40,
      fterm_bmp_glyph103_lines + 45,
      fterm_bmp_glyph103_lines + 50,
      fterm_bmp_glyph103_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph104_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph104 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph104_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph104_lines + 0,
      fterm_bmp_glyph104_lines + 5,
      fterm_bmp_glyph104_lines + 10,
      fterm_bmp_glyph104_lines + 15,
      fterm_bmp_glyph104_lines + 20,
      fterm_bmp_glyph104_lines + 25,
      fterm_bmp_glyph104_lines + 30,
      fterm_bmp_glyph104_lines + 35,
      fterm_bmp_glyph104_lines + 40,
      fterm_bmp_glyph104_lines + 45,
      fterm_bmp_glyph104_lines + 50,
      fterm_bmp_glyph104_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph105_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph105 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph105_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph105_lines + 0,
      fterm_bmp_glyph105_lines + 5,
      fterm_bmp_glyph105_lines + 10,
      fterm_bmp_glyph105_lines + 15,
      fterm_bmp_glyph105_lines + 20,
      fterm_bmp_glyph105_lines + 25,
      fterm_bmp_glyph105_lines + 30,
      fterm_bmp_glyph105_lines + 35,
      fterm_bmp_glyph105_lines + 40,
      fterm_bmp_glyph105_lines + 45,
      fterm_bmp_glyph105_lines + 50,
      fterm_bmp_glyph105_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph106_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\x3\0\x3\0\0"
"\0\x3\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph106 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph106_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph106_lines + 0,
      fterm_bmp_glyph106_lines + 5,
      fterm_bmp_glyph106_lines + 10,
      fterm_bmp_glyph106_lines + 15,
      fterm_bmp_glyph106_lines + 20,
      fterm_bmp_glyph106_lines + 25,
      fterm_bmp_glyph106_lines + 30,
      fterm_bmp_glyph106_lines + 35,
      fterm_bmp_glyph106_lines + 40,
      fterm_bmp_glyph106_lines + 45,
      fterm_bmp_glyph106_lines + 50,
      fterm_bmp_glyph106_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph107_lines[] = 
"\0\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\x3\0\0"
"\x3\x3\0\0\0"
"\x3\x3\0\0\0"
"\x3\0\x3\0\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph107 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph107_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph107_lines + 0,
      fterm_bmp_glyph107_lines + 5,
      fterm_bmp_glyph107_lines + 10,
      fterm_bmp_glyph107_lines + 15,
      fterm_bmp_glyph107_lines + 20,
      fterm_bmp_glyph107_lines + 25,
      fterm_bmp_glyph107_lines + 30,
      fterm_bmp_glyph107_lines + 35,
      fterm_bmp_glyph107_lines + 40,
      fterm_bmp_glyph107_lines + 45,
      fterm_bmp_glyph107_lines + 50,
      fterm_bmp_glyph107_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph108_lines[] = 
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph108 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph108_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph108_lines + 0,
      fterm_bmp_glyph108_lines + 5,
      fterm_bmp_glyph108_lines + 10,
      fterm_bmp_glyph108_lines + 15,
      fterm_bmp_glyph108_lines + 20,
      fterm_bmp_glyph108_lines + 25,
      fterm_bmp_glyph108_lines + 30,
      fterm_bmp_glyph108_lines + 35,
      fterm_bmp_glyph108_lines + 40,
      fterm_bmp_glyph108_lines + 45,
      fterm_bmp_glyph108_lines + 50,
      fterm_bmp_glyph108_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph109_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph109 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph109_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph109_lines + 0,
      fterm_bmp_glyph109_lines + 5,
      fterm_bmp_glyph109_lines + 10,
      fterm_bmp_glyph109_lines + 15,
      fterm_bmp_glyph109_lines + 20,
      fterm_bmp_glyph109_lines + 25,
      fterm_bmp_glyph109_lines + 30,
      fterm_bmp_glyph109_lines + 35,
      fterm_bmp_glyph109_lines + 40,
      fterm_bmp_glyph109_lines + 45,
      fterm_bmp_glyph109_lines + 50,
      fterm_bmp_glyph109_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph110_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\x3\0\0"
"\x3\x3\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph110 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph110_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph110_lines + 0,
      fterm_bmp_glyph110_lines + 5,
      fterm_bmp_glyph110_lines + 10,
      fterm_bmp_glyph110_lines + 15,
      fterm_bmp_glyph110_lines + 20,
      fterm_bmp_glyph110_lines + 25,
      fterm_bmp_glyph110_lines + 30,
      fterm_bmp_glyph110_lines + 35,
      fterm_bmp_glyph110_lines + 40,
      fterm_bmp_glyph110_lines + 45,
      fterm_bmp_glyph110_lines + 50,
      fterm_bmp_glyph110_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph111_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph111 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph111_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph111_lines + 0,
      fterm_bmp_glyph111_lines + 5,
      fterm_bmp_glyph111_lines + 10,
      fterm_bmp_glyph111_lines + 15,
      fterm_bmp_glyph111_lines + 20,
      fterm_bmp_glyph111_lines + 25,
      fterm_bmp_glyph111_lines + 30,
      fterm_bmp_glyph111_lines + 35,
      fterm_bmp_glyph111_lines + 40,
      fterm_bmp_glyph111_lines + 45,
      fterm_bmp_glyph111_lines + 50,
      fterm_bmp_glyph111_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph112_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\0\0"
"\x3\0\0\0\0"
"\x3\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph112 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph112_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph112_lines + 0,
      fterm_bmp_glyph112_lines + 5,
      fterm_bmp_glyph112_lines + 10,
      fterm_bmp_glyph112_lines + 15,
      fterm_bmp_glyph112_lines + 20,
      fterm_bmp_glyph112_lines + 25,
      fterm_bmp_glyph112_lines + 30,
      fterm_bmp_glyph112_lines + 35,
      fterm_bmp_glyph112_lines + 40,
      fterm_bmp_glyph112_lines + 45,
      fterm_bmp_glyph112_lines + 50,
      fterm_bmp_glyph112_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph113_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\0\x3\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph113 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph113_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph113_lines + 0,
      fterm_bmp_glyph113_lines + 5,
      fterm_bmp_glyph113_lines + 10,
      fterm_bmp_glyph113_lines + 15,
      fterm_bmp_glyph113_lines + 20,
      fterm_bmp_glyph113_lines + 25,
      fterm_bmp_glyph113_lines + 30,
      fterm_bmp_glyph113_lines + 35,
      fterm_bmp_glyph113_lines + 40,
      fterm_bmp_glyph113_lines + 45,
      fterm_bmp_glyph113_lines + 50,
      fterm_bmp_glyph113_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph114_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\x3\x3\0"
"\0\x3\0\x3\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph114 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph114_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph114_lines + 0,
      fterm_bmp_glyph114_lines + 5,
      fterm_bmp_glyph114_lines + 10,
      fterm_bmp_glyph114_lines + 15,
      fterm_bmp_glyph114_lines + 20,
      fterm_bmp_glyph114_lines + 25,
      fterm_bmp_glyph114_lines + 30,
      fterm_bmp_glyph114_lines + 35,
      fterm_bmp_glyph114_lines + 40,
      fterm_bmp_glyph114_lines + 45,
      fterm_bmp_glyph114_lines + 50,
      fterm_bmp_glyph114_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph115_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph115 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph115_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph115_lines + 0,
      fterm_bmp_glyph115_lines + 5,
      fterm_bmp_glyph115_lines + 10,
      fterm_bmp_glyph115_lines + 15,
      fterm_bmp_glyph115_lines + 20,
      fterm_bmp_glyph115_lines + 25,
      fterm_bmp_glyph115_lines + 30,
      fterm_bmp_glyph115_lines + 35,
      fterm_bmp_glyph115_lines + 40,
      fterm_bmp_glyph115_lines + 45,
      fterm_bmp_glyph115_lines + 50,
      fterm_bmp_glyph115_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph116_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\x3\x3\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph116 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph116_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph116_lines + 0,
      fterm_bmp_glyph116_lines + 5,
      fterm_bmp_glyph116_lines + 10,
      fterm_bmp_glyph116_lines + 15,
      fterm_bmp_glyph116_lines + 20,
      fterm_bmp_glyph116_lines + 25,
      fterm_bmp_glyph116_lines + 30,
      fterm_bmp_glyph116_lines + 35,
      fterm_bmp_glyph116_lines + 40,
      fterm_bmp_glyph116_lines + 45,
      fterm_bmp_glyph116_lines + 50,
      fterm_bmp_glyph116_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph117_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph117 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph117_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph117_lines + 0,
      fterm_bmp_glyph117_lines + 5,
      fterm_bmp_glyph117_lines + 10,
      fterm_bmp_glyph117_lines + 15,
      fterm_bmp_glyph117_lines + 20,
      fterm_bmp_glyph117_lines + 25,
      fterm_bmp_glyph117_lines + 30,
      fterm_bmp_glyph117_lines + 35,
      fterm_bmp_glyph117_lines + 40,
      fterm_bmp_glyph117_lines + 45,
      fterm_bmp_glyph117_lines + 50,
      fterm_bmp_glyph117_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph118_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\0\x3\0"
"\0\x3\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph118 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph118_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph118_lines + 0,
      fterm_bmp_glyph118_lines + 5,
      fterm_bmp_glyph118_lines + 10,
      fterm_bmp_glyph118_lines + 15,
      fterm_bmp_glyph118_lines + 20,
      fterm_bmp_glyph118_lines + 25,
      fterm_bmp_glyph118_lines + 30,
      fterm_bmp_glyph118_lines + 35,
      fterm_bmp_glyph118_lines + 40,
      fterm_bmp_glyph118_lines + 45,
      fterm_bmp_glyph118_lines + 50,
      fterm_bmp_glyph118_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph119_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\x3\x3\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph119 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph119_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph119_lines + 0,
      fterm_bmp_glyph119_lines + 5,
      fterm_bmp_glyph119_lines + 10,
      fterm_bmp_glyph119_lines + 15,
      fterm_bmp_glyph119_lines + 20,
      fterm_bmp_glyph119_lines + 25,
      fterm_bmp_glyph119_lines + 30,
      fterm_bmp_glyph119_lines + 35,
      fterm_bmp_glyph119_lines + 40,
      fterm_bmp_glyph119_lines + 45,
      fterm_bmp_glyph119_lines + 50,
      fterm_bmp_glyph119_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph120_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\0\0"
"\0\x3\x3\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph120 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph120_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph120_lines + 0,
      fterm_bmp_glyph120_lines + 5,
      fterm_bmp_glyph120_lines + 10,
      fterm_bmp_glyph120_lines + 15,
      fterm_bmp_glyph120_lines + 20,
      fterm_bmp_glyph120_lines + 25,
      fterm_bmp_glyph120_lines + 30,
      fterm_bmp_glyph120_lines + 35,
      fterm_bmp_glyph120_lines + 40,
      fterm_bmp_glyph120_lines + 45,
      fterm_bmp_glyph120_lines + 50,
      fterm_bmp_glyph120_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph121_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\x3\0\0\x3\0"
"\0\x3\x3\x3\0"
"\0\0\0\x3\0"
"\x3\x3\x3\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph121 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph121_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph121_lines + 0,
      fterm_bmp_glyph121_lines + 5,
      fterm_bmp_glyph121_lines + 10,
      fterm_bmp_glyph121_lines + 15,
      fterm_bmp_glyph121_lines + 20,
      fterm_bmp_glyph121_lines + 25,
      fterm_bmp_glyph121_lines + 30,
      fterm_bmp_glyph121_lines + 35,
      fterm_bmp_glyph121_lines + 40,
      fterm_bmp_glyph121_lines + 45,
      fterm_bmp_glyph121_lines + 50,
      fterm_bmp_glyph121_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph122_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\x3\x3\x3\x3\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph122 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph122_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph122_lines + 0,
      fterm_bmp_glyph122_lines + 5,
      fterm_bmp_glyph122_lines + 10,
      fterm_bmp_glyph122_lines + 15,
      fterm_bmp_glyph122_lines + 20,
      fterm_bmp_glyph122_lines + 25,
      fterm_bmp_glyph122_lines + 30,
      fterm_bmp_glyph122_lines + 35,
      fterm_bmp_glyph122_lines + 40,
      fterm_bmp_glyph122_lines + 45,
      fterm_bmp_glyph122_lines + 50,
      fterm_bmp_glyph122_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph123_lines[] = 
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\x3\0\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph123 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph123_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph123_lines + 0,
      fterm_bmp_glyph123_lines + 5,
      fterm_bmp_glyph123_lines + 10,
      fterm_bmp_glyph123_lines + 15,
      fterm_bmp_glyph123_lines + 20,
      fterm_bmp_glyph123_lines + 25,
      fterm_bmp_glyph123_lines + 30,
      fterm_bmp_glyph123_lines + 35,
      fterm_bmp_glyph123_lines + 40,
      fterm_bmp_glyph123_lines + 45,
      fterm_bmp_glyph123_lines + 50,
      fterm_bmp_glyph123_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph124_lines[] = 
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph124 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph124_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph124_lines + 0,
      fterm_bmp_glyph124_lines + 5,
      fterm_bmp_glyph124_lines + 10,
      fterm_bmp_glyph124_lines + 15,
      fterm_bmp_glyph124_lines + 20,
      fterm_bmp_glyph124_lines + 25,
      fterm_bmp_glyph124_lines + 30,
      fterm_bmp_glyph124_lines + 35,
      fterm_bmp_glyph124_lines + 40,
      fterm_bmp_glyph124_lines + 45,
      fterm_bmp_glyph124_lines + 50,
      fterm_bmp_glyph124_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph125_lines[] = 
"\0\0\0\0\0"
"\0\x3\0\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\0\x3\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\0\x3\0\0"
"\0\x3\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph125 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph125_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph125_lines + 0,
      fterm_bmp_glyph125_lines + 5,
      fterm_bmp_glyph125_lines + 10,
      fterm_bmp_glyph125_lines + 15,
      fterm_bmp_glyph125_lines + 20,
      fterm_bmp_glyph125_lines + 25,
      fterm_bmp_glyph125_lines + 30,
      fterm_bmp_glyph125_lines + 35,
      fterm_bmp_glyph125_lines + 40,
      fterm_bmp_glyph125_lines + 45,
      fterm_bmp_glyph125_lines + 50,
      fterm_bmp_glyph125_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph126_lines[] = 
"\0\0\0\0\0"
"\0\x3\0\x3\0"
"\x3\0\x3\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph126 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph126_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph126_lines + 0,
      fterm_bmp_glyph126_lines + 5,
      fterm_bmp_glyph126_lines + 10,
      fterm_bmp_glyph126_lines + 15,
      fterm_bmp_glyph126_lines + 20,
      fterm_bmp_glyph126_lines + 25,
      fterm_bmp_glyph126_lines + 30,
      fterm_bmp_glyph126_lines + 35,
      fterm_bmp_glyph126_lines + 40,
      fterm_bmp_glyph126_lines + 45,
      fterm_bmp_glyph126_lines + 50,
      fterm_bmp_glyph126_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph127_lines[] = 
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\0\0\0\a"
"\a\0\0\0\a"
"\a\0\0\0\a"
"\a\0\0\0\a"
"\a\a\a\a\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph127 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph127_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph127_lines + 0,
      fterm_bmp_glyph127_lines + 5,
      fterm_bmp_glyph127_lines + 10,
      fterm_bmp_glyph127_lines + 15,
      fterm_bmp_glyph127_lines + 20,
      fterm_bmp_glyph127_lines + 25,
      fterm_bmp_glyph127_lines + 30,
      fterm_bmp_glyph127_lines + 35,
      fterm_bmp_glyph127_lines + 40,
      fterm_bmp_glyph127_lines + 45,
      fterm_bmp_glyph127_lines + 50,
      fterm_bmp_glyph127_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph128_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph128 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph128_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph128_lines + 0,
      fterm_bmp_glyph128_lines + 5,
      fterm_bmp_glyph128_lines + 10,
      fterm_bmp_glyph128_lines + 15,
      fterm_bmp_glyph128_lines + 20,
      fterm_bmp_glyph128_lines + 25,
      fterm_bmp_glyph128_lines + 30,
      fterm_bmp_glyph128_lines + 35,
      fterm_bmp_glyph128_lines + 40,
      fterm_bmp_glyph128_lines + 45,
      fterm_bmp_glyph128_lines + 50,
      fterm_bmp_glyph128_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph129_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph129 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph129_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph129_lines + 0,
      fterm_bmp_glyph129_lines + 5,
      fterm_bmp_glyph129_lines + 10,
      fterm_bmp_glyph129_lines + 15,
      fterm_bmp_glyph129_lines + 20,
      fterm_bmp_glyph129_lines + 25,
      fterm_bmp_glyph129_lines + 30,
      fterm_bmp_glyph129_lines + 35,
      fterm_bmp_glyph129_lines + 40,
      fterm_bmp_glyph129_lines + 45,
      fterm_bmp_glyph129_lines + 50,
      fterm_bmp_glyph129_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph130_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph130 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph130_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph130_lines + 0,
      fterm_bmp_glyph130_lines + 5,
      fterm_bmp_glyph130_lines + 10,
      fterm_bmp_glyph130_lines + 15,
      fterm_bmp_glyph130_lines + 20,
      fterm_bmp_glyph130_lines + 25,
      fterm_bmp_glyph130_lines + 30,
      fterm_bmp_glyph130_lines + 35,
      fterm_bmp_glyph130_lines + 40,
      fterm_bmp_glyph130_lines + 45,
      fterm_bmp_glyph130_lines + 50,
      fterm_bmp_glyph130_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph131_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\a\0"
"\0\a\a\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph131 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph131_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph131_lines + 0,
      fterm_bmp_glyph131_lines + 5,
      fterm_bmp_glyph131_lines + 10,
      fterm_bmp_glyph131_lines + 15,
      fterm_bmp_glyph131_lines + 20,
      fterm_bmp_glyph131_lines + 25,
      fterm_bmp_glyph131_lines + 30,
      fterm_bmp_glyph131_lines + 35,
      fterm_bmp_glyph131_lines + 40,
      fterm_bmp_glyph131_lines + 45,
      fterm_bmp_glyph131_lines + 50,
      fterm_bmp_glyph131_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph132_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\a\0"
"\0\a\a\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph132 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph132_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph132_lines + 0,
      fterm_bmp_glyph132_lines + 5,
      fterm_bmp_glyph132_lines + 10,
      fterm_bmp_glyph132_lines + 15,
      fterm_bmp_glyph132_lines + 20,
      fterm_bmp_glyph132_lines + 25,
      fterm_bmp_glyph132_lines + 30,
      fterm_bmp_glyph132_lines + 35,
      fterm_bmp_glyph132_lines + 40,
      fterm_bmp_glyph132_lines + 45,
      fterm_bmp_glyph132_lines + 50,
      fterm_bmp_glyph132_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph133_lines[] = 
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\a\0\a\0"
"\0\0\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph133 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph133_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph133_lines + 0,
      fterm_bmp_glyph133_lines + 5,
      fterm_bmp_glyph133_lines + 10,
      fterm_bmp_glyph133_lines + 15,
      fterm_bmp_glyph133_lines + 20,
      fterm_bmp_glyph133_lines + 25,
      fterm_bmp_glyph133_lines + 30,
      fterm_bmp_glyph133_lines + 35,
      fterm_bmp_glyph133_lines + 40,
      fterm_bmp_glyph133_lines + 45,
      fterm_bmp_glyph133_lines + 50,
      fterm_bmp_glyph133_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph134_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph134 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph134_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph134_lines + 0,
      fterm_bmp_glyph134_lines + 5,
      fterm_bmp_glyph134_lines + 10,
      fterm_bmp_glyph134_lines + 15,
      fterm_bmp_glyph134_lines + 20,
      fterm_bmp_glyph134_lines + 25,
      fterm_bmp_glyph134_lines + 30,
      fterm_bmp_glyph134_lines + 35,
      fterm_bmp_glyph134_lines + 40,
      fterm_bmp_glyph134_lines + 45,
      fterm_bmp_glyph134_lines + 50,
      fterm_bmp_glyph134_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph135_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\0\a\0\0"
"\a\a\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph135 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph135_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph135_lines + 0,
      fterm_bmp_glyph135_lines + 5,
      fterm_bmp_glyph135_lines + 10,
      fterm_bmp_glyph135_lines + 15,
      fterm_bmp_glyph135_lines + 20,
      fterm_bmp_glyph135_lines + 25,
      fterm_bmp_glyph135_lines + 30,
      fterm_bmp_glyph135_lines + 35,
      fterm_bmp_glyph135_lines + 40,
      fterm_bmp_glyph135_lines + 45,
      fterm_bmp_glyph135_lines + 50,
      fterm_bmp_glyph135_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph136_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\a"
"\0\0\a\a\0"
"\0\a\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph136 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph136_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph136_lines + 0,
      fterm_bmp_glyph136_lines + 5,
      fterm_bmp_glyph136_lines + 10,
      fterm_bmp_glyph136_lines + 15,
      fterm_bmp_glyph136_lines + 20,
      fterm_bmp_glyph136_lines + 25,
      fterm_bmp_glyph136_lines + 30,
      fterm_bmp_glyph136_lines + 35,
      fterm_bmp_glyph136_lines + 40,
      fterm_bmp_glyph136_lines + 45,
      fterm_bmp_glyph136_lines + 50,
      fterm_bmp_glyph136_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph137_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph137 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph137_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph137_lines + 0,
      fterm_bmp_glyph137_lines + 5,
      fterm_bmp_glyph137_lines + 10,
      fterm_bmp_glyph137_lines + 15,
      fterm_bmp_glyph137_lines + 20,
      fterm_bmp_glyph137_lines + 25,
      fterm_bmp_glyph137_lines + 30,
      fterm_bmp_glyph137_lines + 35,
      fterm_bmp_glyph137_lines + 40,
      fterm_bmp_glyph137_lines + 45,
      fterm_bmp_glyph137_lines + 50,
      fterm_bmp_glyph137_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph138_lines[] = 
"\0\a\0\0\a"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph138 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph138_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph138_lines + 0,
      fterm_bmp_glyph138_lines + 5,
      fterm_bmp_glyph138_lines + 10,
      fterm_bmp_glyph138_lines + 15,
      fterm_bmp_glyph138_lines + 20,
      fterm_bmp_glyph138_lines + 25,
      fterm_bmp_glyph138_lines + 30,
      fterm_bmp_glyph138_lines + 35,
      fterm_bmp_glyph138_lines + 40,
      fterm_bmp_glyph138_lines + 45,
      fterm_bmp_glyph138_lines + 50,
      fterm_bmp_glyph138_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph139_lines[] = 
"\0\0\0\0\0"
"\0\a\0\0\a"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph139 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph139_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph139_lines + 0,
      fterm_bmp_glyph139_lines + 5,
      fterm_bmp_glyph139_lines + 10,
      fterm_bmp_glyph139_lines + 15,
      fterm_bmp_glyph139_lines + 20,
      fterm_bmp_glyph139_lines + 25,
      fterm_bmp_glyph139_lines + 30,
      fterm_bmp_glyph139_lines + 35,
      fterm_bmp_glyph139_lines + 40,
      fterm_bmp_glyph139_lines + 45,
      fterm_bmp_glyph139_lines + 50,
      fterm_bmp_glyph139_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph140_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph140 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph140_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph140_lines + 0,
      fterm_bmp_glyph140_lines + 5,
      fterm_bmp_glyph140_lines + 10,
      fterm_bmp_glyph140_lines + 15,
      fterm_bmp_glyph140_lines + 20,
      fterm_bmp_glyph140_lines + 25,
      fterm_bmp_glyph140_lines + 30,
      fterm_bmp_glyph140_lines + 35,
      fterm_bmp_glyph140_lines + 40,
      fterm_bmp_glyph140_lines + 45,
      fterm_bmp_glyph140_lines + 50,
      fterm_bmp_glyph140_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph141_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph141 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph141_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph141_lines + 0,
      fterm_bmp_glyph141_lines + 5,
      fterm_bmp_glyph141_lines + 10,
      fterm_bmp_glyph141_lines + 15,
      fterm_bmp_glyph141_lines + 20,
      fterm_bmp_glyph141_lines + 25,
      fterm_bmp_glyph141_lines + 30,
      fterm_bmp_glyph141_lines + 35,
      fterm_bmp_glyph141_lines + 40,
      fterm_bmp_glyph141_lines + 45,
      fterm_bmp_glyph141_lines + 50,
      fterm_bmp_glyph141_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph142_lines[] = 
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph142 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph142_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph142_lines + 0,
      fterm_bmp_glyph142_lines + 5,
      fterm_bmp_glyph142_lines + 10,
      fterm_bmp_glyph142_lines + 15,
      fterm_bmp_glyph142_lines + 20,
      fterm_bmp_glyph142_lines + 25,
      fterm_bmp_glyph142_lines + 30,
      fterm_bmp_glyph142_lines + 35,
      fterm_bmp_glyph142_lines + 40,
      fterm_bmp_glyph142_lines + 45,
      fterm_bmp_glyph142_lines + 50,
      fterm_bmp_glyph142_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph143_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph143 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph143_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph143_lines + 0,
      fterm_bmp_glyph143_lines + 5,
      fterm_bmp_glyph143_lines + 10,
      fterm_bmp_glyph143_lines + 15,
      fterm_bmp_glyph143_lines + 20,
      fterm_bmp_glyph143_lines + 25,
      fterm_bmp_glyph143_lines + 30,
      fterm_bmp_glyph143_lines + 35,
      fterm_bmp_glyph143_lines + 40,
      fterm_bmp_glyph143_lines + 45,
      fterm_bmp_glyph143_lines + 50,
      fterm_bmp_glyph143_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph144_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph144 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph144_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph144_lines + 0,
      fterm_bmp_glyph144_lines + 5,
      fterm_bmp_glyph144_lines + 10,
      fterm_bmp_glyph144_lines + 15,
      fterm_bmp_glyph144_lines + 20,
      fterm_bmp_glyph144_lines + 25,
      fterm_bmp_glyph144_lines + 30,
      fterm_bmp_glyph144_lines + 35,
      fterm_bmp_glyph144_lines + 40,
      fterm_bmp_glyph144_lines + 45,
      fterm_bmp_glyph144_lines + 50,
      fterm_bmp_glyph144_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph145_lines[] = 
"\0\a\a\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph145 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph145_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph145_lines + 0,
      fterm_bmp_glyph145_lines + 5,
      fterm_bmp_glyph145_lines + 10,
      fterm_bmp_glyph145_lines + 15,
      fterm_bmp_glyph145_lines + 20,
      fterm_bmp_glyph145_lines + 25,
      fterm_bmp_glyph145_lines + 30,
      fterm_bmp_glyph145_lines + 35,
      fterm_bmp_glyph145_lines + 40,
      fterm_bmp_glyph145_lines + 45,
      fterm_bmp_glyph145_lines + 50,
      fterm_bmp_glyph145_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph146_lines[] = 
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph146 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph146_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph146_lines + 0,
      fterm_bmp_glyph146_lines + 5,
      fterm_bmp_glyph146_lines + 10,
      fterm_bmp_glyph146_lines + 15,
      fterm_bmp_glyph146_lines + 20,
      fterm_bmp_glyph146_lines + 25,
      fterm_bmp_glyph146_lines + 30,
      fterm_bmp_glyph146_lines + 35,
      fterm_bmp_glyph146_lines + 40,
      fterm_bmp_glyph146_lines + 45,
      fterm_bmp_glyph146_lines + 50,
      fterm_bmp_glyph146_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph147_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph147 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph147_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph147_lines + 0,
      fterm_bmp_glyph147_lines + 5,
      fterm_bmp_glyph147_lines + 10,
      fterm_bmp_glyph147_lines + 15,
      fterm_bmp_glyph147_lines + 20,
      fterm_bmp_glyph147_lines + 25,
      fterm_bmp_glyph147_lines + 30,
      fterm_bmp_glyph147_lines + 35,
      fterm_bmp_glyph147_lines + 40,
      fterm_bmp_glyph147_lines + 45,
      fterm_bmp_glyph147_lines + 50,
      fterm_bmp_glyph147_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph148_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph148 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph148_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph148_lines + 0,
      fterm_bmp_glyph148_lines + 5,
      fterm_bmp_glyph148_lines + 10,
      fterm_bmp_glyph148_lines + 15,
      fterm_bmp_glyph148_lines + 20,
      fterm_bmp_glyph148_lines + 25,
      fterm_bmp_glyph148_lines + 30,
      fterm_bmp_glyph148_lines + 35,
      fterm_bmp_glyph148_lines + 40,
      fterm_bmp_glyph148_lines + 45,
      fterm_bmp_glyph148_lines + 50,
      fterm_bmp_glyph148_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph149_lines[] = 
"\0\0\0\0\0"
"\a\0\a\a\0"
"\a\0\a\a\0"
"\a\0\0\a\0"
"\a\0\a\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph149 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph149_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph149_lines + 0,
      fterm_bmp_glyph149_lines + 5,
      fterm_bmp_glyph149_lines + 10,
      fterm_bmp_glyph149_lines + 15,
      fterm_bmp_glyph149_lines + 20,
      fterm_bmp_glyph149_lines + 25,
      fterm_bmp_glyph149_lines + 30,
      fterm_bmp_glyph149_lines + 35,
      fterm_bmp_glyph149_lines + 40,
      fterm_bmp_glyph149_lines + 45,
      fterm_bmp_glyph149_lines + 50,
      fterm_bmp_glyph149_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph150_lines[] = 
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\a\a\a\0"
"\0\a\0\a\0"
"\0\a\a\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\a\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph150 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph150_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph150_lines + 0,
      fterm_bmp_glyph150_lines + 5,
      fterm_bmp_glyph150_lines + 10,
      fterm_bmp_glyph150_lines + 15,
      fterm_bmp_glyph150_lines + 20,
      fterm_bmp_glyph150_lines + 25,
      fterm_bmp_glyph150_lines + 30,
      fterm_bmp_glyph150_lines + 35,
      fterm_bmp_glyph150_lines + 40,
      fterm_bmp_glyph150_lines + 45,
      fterm_bmp_glyph150_lines + 50,
      fterm_bmp_glyph150_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph151_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\0\a\a\0\0"
"\0\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph151 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph151_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph151_lines + 0,
      fterm_bmp_glyph151_lines + 5,
      fterm_bmp_glyph151_lines + 10,
      fterm_bmp_glyph151_lines + 15,
      fterm_bmp_glyph151_lines + 20,
      fterm_bmp_glyph151_lines + 25,
      fterm_bmp_glyph151_lines + 30,
      fterm_bmp_glyph151_lines + 35,
      fterm_bmp_glyph151_lines + 40,
      fterm_bmp_glyph151_lines + 45,
      fterm_bmp_glyph151_lines + 50,
      fterm_bmp_glyph151_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph152_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\a\0\0\0"
"\0\0\a\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph152 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph152_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph152_lines + 0,
      fterm_bmp_glyph152_lines + 5,
      fterm_bmp_glyph152_lines + 10,
      fterm_bmp_glyph152_lines + 15,
      fterm_bmp_glyph152_lines + 20,
      fterm_bmp_glyph152_lines + 25,
      fterm_bmp_glyph152_lines + 30,
      fterm_bmp_glyph152_lines + 35,
      fterm_bmp_glyph152_lines + 40,
      fterm_bmp_glyph152_lines + 45,
      fterm_bmp_glyph152_lines + 50,
      fterm_bmp_glyph152_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph153_lines[] = 
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph153 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph153_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph153_lines + 0,
      fterm_bmp_glyph153_lines + 5,
      fterm_bmp_glyph153_lines + 10,
      fterm_bmp_glyph153_lines + 15,
      fterm_bmp_glyph153_lines + 20,
      fterm_bmp_glyph153_lines + 25,
      fterm_bmp_glyph153_lines + 30,
      fterm_bmp_glyph153_lines + 35,
      fterm_bmp_glyph153_lines + 40,
      fterm_bmp_glyph153_lines + 45,
      fterm_bmp_glyph153_lines + 50,
      fterm_bmp_glyph153_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph154_lines[] = 
"\a\0\0\a\0"
"\0\0\0\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph154 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph154_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph154_lines + 0,
      fterm_bmp_glyph154_lines + 5,
      fterm_bmp_glyph154_lines + 10,
      fterm_bmp_glyph154_lines + 15,
      fterm_bmp_glyph154_lines + 20,
      fterm_bmp_glyph154_lines + 25,
      fterm_bmp_glyph154_lines + 30,
      fterm_bmp_glyph154_lines + 35,
      fterm_bmp_glyph154_lines + 40,
      fterm_bmp_glyph154_lines + 45,
      fterm_bmp_glyph154_lines + 50,
      fterm_bmp_glyph154_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph155_lines[] = 
"\0\a\0\a\0"
"\0\0\a\0\0"
"\a\a\a\a\a"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph155 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph155_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph155_lines + 0,
      fterm_bmp_glyph155_lines + 5,
      fterm_bmp_glyph155_lines + 10,
      fterm_bmp_glyph155_lines + 15,
      fterm_bmp_glyph155_lines + 20,
      fterm_bmp_glyph155_lines + 25,
      fterm_bmp_glyph155_lines + 30,
      fterm_bmp_glyph155_lines + 35,
      fterm_bmp_glyph155_lines + 40,
      fterm_bmp_glyph155_lines + 45,
      fterm_bmp_glyph155_lines + 50,
      fterm_bmp_glyph155_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph156_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\a\a\0"
"\0\a\0\a\0"
"\a\a\a\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph156 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph156_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph156_lines + 0,
      fterm_bmp_glyph156_lines + 5,
      fterm_bmp_glyph156_lines + 10,
      fterm_bmp_glyph156_lines + 15,
      fterm_bmp_glyph156_lines + 20,
      fterm_bmp_glyph156_lines + 25,
      fterm_bmp_glyph156_lines + 30,
      fterm_bmp_glyph156_lines + 35,
      fterm_bmp_glyph156_lines + 40,
      fterm_bmp_glyph156_lines + 45,
      fterm_bmp_glyph156_lines + 50,
      fterm_bmp_glyph156_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph157_lines[] = 
"\0\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\a\0"
"\a\0\a\0\0"
"\a\a\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph157 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph157_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph157_lines + 0,
      fterm_bmp_glyph157_lines + 5,
      fterm_bmp_glyph157_lines + 10,
      fterm_bmp_glyph157_lines + 15,
      fterm_bmp_glyph157_lines + 20,
      fterm_bmp_glyph157_lines + 25,
      fterm_bmp_glyph157_lines + 30,
      fterm_bmp_glyph157_lines + 35,
      fterm_bmp_glyph157_lines + 40,
      fterm_bmp_glyph157_lines + 45,
      fterm_bmp_glyph157_lines + 50,
      fterm_bmp_glyph157_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph158_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph158 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph158_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph158_lines + 0,
      fterm_bmp_glyph158_lines + 5,
      fterm_bmp_glyph158_lines + 10,
      fterm_bmp_glyph158_lines + 15,
      fterm_bmp_glyph158_lines + 20,
      fterm_bmp_glyph158_lines + 25,
      fterm_bmp_glyph158_lines + 30,
      fterm_bmp_glyph158_lines + 35,
      fterm_bmp_glyph158_lines + 40,
      fterm_bmp_glyph158_lines + 45,
      fterm_bmp_glyph158_lines + 50,
      fterm_bmp_glyph158_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph159_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph159 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph159_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph159_lines + 0,
      fterm_bmp_glyph159_lines + 5,
      fterm_bmp_glyph159_lines + 10,
      fterm_bmp_glyph159_lines + 15,
      fterm_bmp_glyph159_lines + 20,
      fterm_bmp_glyph159_lines + 25,
      fterm_bmp_glyph159_lines + 30,
      fterm_bmp_glyph159_lines + 35,
      fterm_bmp_glyph159_lines + 40,
      fterm_bmp_glyph159_lines + 45,
      fterm_bmp_glyph159_lines + 50,
      fterm_bmp_glyph159_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph160_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\a\0"
"\0\a\a\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph160 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph160_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph160_lines + 0,
      fterm_bmp_glyph160_lines + 5,
      fterm_bmp_glyph160_lines + 10,
      fterm_bmp_glyph160_lines + 15,
      fterm_bmp_glyph160_lines + 20,
      fterm_bmp_glyph160_lines + 25,
      fterm_bmp_glyph160_lines + 30,
      fterm_bmp_glyph160_lines + 35,
      fterm_bmp_glyph160_lines + 40,
      fterm_bmp_glyph160_lines + 45,
      fterm_bmp_glyph160_lines + 50,
      fterm_bmp_glyph160_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph161_lines[] = 
"\0\0\0\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0\0\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph161 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph161_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph161_lines + 0,
      fterm_bmp_glyph161_lines + 5,
      fterm_bmp_glyph161_lines + 10,
      fterm_bmp_glyph161_lines + 15,
      fterm_bmp_glyph161_lines + 20,
      fterm_bmp_glyph161_lines + 25,
      fterm_bmp_glyph161_lines + 30,
      fterm_bmp_glyph161_lines + 35,
      fterm_bmp_glyph161_lines + 40,
      fterm_bmp_glyph161_lines + 45,
      fterm_bmp_glyph161_lines + 50,
      fterm_bmp_glyph161_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph162_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph162 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph162_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph162_lines + 0,
      fterm_bmp_glyph162_lines + 5,
      fterm_bmp_glyph162_lines + 10,
      fterm_bmp_glyph162_lines + 15,
      fterm_bmp_glyph162_lines + 20,
      fterm_bmp_glyph162_lines + 25,
      fterm_bmp_glyph162_lines + 30,
      fterm_bmp_glyph162_lines + 35,
      fterm_bmp_glyph162_lines + 40,
      fterm_bmp_glyph162_lines + 45,
      fterm_bmp_glyph162_lines + 50,
      fterm_bmp_glyph162_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph163_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph163 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph163_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph163_lines + 0,
      fterm_bmp_glyph163_lines + 5,
      fterm_bmp_glyph163_lines + 10,
      fterm_bmp_glyph163_lines + 15,
      fterm_bmp_glyph163_lines + 20,
      fterm_bmp_glyph163_lines + 25,
      fterm_bmp_glyph163_lines + 30,
      fterm_bmp_glyph163_lines + 35,
      fterm_bmp_glyph163_lines + 40,
      fterm_bmp_glyph163_lines + 45,
      fterm_bmp_glyph163_lines + 50,
      fterm_bmp_glyph163_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph164_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\a\0\0"
"\0\0\a\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph164 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph164_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph164_lines + 0,
      fterm_bmp_glyph164_lines + 5,
      fterm_bmp_glyph164_lines + 10,
      fterm_bmp_glyph164_lines + 15,
      fterm_bmp_glyph164_lines + 20,
      fterm_bmp_glyph164_lines + 25,
      fterm_bmp_glyph164_lines + 30,
      fterm_bmp_glyph164_lines + 35,
      fterm_bmp_glyph164_lines + 40,
      fterm_bmp_glyph164_lines + 45,
      fterm_bmp_glyph164_lines + 50,
      fterm_bmp_glyph164_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph165_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\a\0"
"\0\a\a\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\a\0\0"
"\0\0\a\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph165 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph165_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph165_lines + 0,
      fterm_bmp_glyph165_lines + 5,
      fterm_bmp_glyph165_lines + 10,
      fterm_bmp_glyph165_lines + 15,
      fterm_bmp_glyph165_lines + 20,
      fterm_bmp_glyph165_lines + 25,
      fterm_bmp_glyph165_lines + 30,
      fterm_bmp_glyph165_lines + 35,
      fterm_bmp_glyph165_lines + 40,
      fterm_bmp_glyph165_lines + 45,
      fterm_bmp_glyph165_lines + 50,
      fterm_bmp_glyph165_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph166_lines[] = 
"\0\a\0\a\0"
"\0\0\a\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph166 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph166_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph166_lines + 0,
      fterm_bmp_glyph166_lines + 5,
      fterm_bmp_glyph166_lines + 10,
      fterm_bmp_glyph166_lines + 15,
      fterm_bmp_glyph166_lines + 20,
      fterm_bmp_glyph166_lines + 25,
      fterm_bmp_glyph166_lines + 30,
      fterm_bmp_glyph166_lines + 35,
      fterm_bmp_glyph166_lines + 40,
      fterm_bmp_glyph166_lines + 45,
      fterm_bmp_glyph166_lines + 50,
      fterm_bmp_glyph166_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph167_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph167 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph167_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph167_lines + 0,
      fterm_bmp_glyph167_lines + 5,
      fterm_bmp_glyph167_lines + 10,
      fterm_bmp_glyph167_lines + 15,
      fterm_bmp_glyph167_lines + 20,
      fterm_bmp_glyph167_lines + 25,
      fterm_bmp_glyph167_lines + 30,
      fterm_bmp_glyph167_lines + 35,
      fterm_bmp_glyph167_lines + 40,
      fterm_bmp_glyph167_lines + 45,
      fterm_bmp_glyph167_lines + 50,
      fterm_bmp_glyph167_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph168_lines[] = 
"\0\0\0\0\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph168 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph168_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph168_lines + 0,
      fterm_bmp_glyph168_lines + 5,
      fterm_bmp_glyph168_lines + 10,
      fterm_bmp_glyph168_lines + 15,
      fterm_bmp_glyph168_lines + 20,
      fterm_bmp_glyph168_lines + 25,
      fterm_bmp_glyph168_lines + 30,
      fterm_bmp_glyph168_lines + 35,
      fterm_bmp_glyph168_lines + 40,
      fterm_bmp_glyph168_lines + 45,
      fterm_bmp_glyph168_lines + 50,
      fterm_bmp_glyph168_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph169_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph169 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph169_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph169_lines + 0,
      fterm_bmp_glyph169_lines + 5,
      fterm_bmp_glyph169_lines + 10,
      fterm_bmp_glyph169_lines + 15,
      fterm_bmp_glyph169_lines + 20,
      fterm_bmp_glyph169_lines + 25,
      fterm_bmp_glyph169_lines + 30,
      fterm_bmp_glyph169_lines + 35,
      fterm_bmp_glyph169_lines + 40,
      fterm_bmp_glyph169_lines + 45,
      fterm_bmp_glyph169_lines + 50,
      fterm_bmp_glyph169_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph170_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph170 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph170_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph170_lines + 0,
      fterm_bmp_glyph170_lines + 5,
      fterm_bmp_glyph170_lines + 10,
      fterm_bmp_glyph170_lines + 15,
      fterm_bmp_glyph170_lines + 20,
      fterm_bmp_glyph170_lines + 25,
      fterm_bmp_glyph170_lines + 30,
      fterm_bmp_glyph170_lines + 35,
      fterm_bmp_glyph170_lines + 40,
      fterm_bmp_glyph170_lines + 45,
      fterm_bmp_glyph170_lines + 50,
      fterm_bmp_glyph170_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph171_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph171 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph171_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph171_lines + 0,
      fterm_bmp_glyph171_lines + 5,
      fterm_bmp_glyph171_lines + 10,
      fterm_bmp_glyph171_lines + 15,
      fterm_bmp_glyph171_lines + 20,
      fterm_bmp_glyph171_lines + 25,
      fterm_bmp_glyph171_lines + 30,
      fterm_bmp_glyph171_lines + 35,
      fterm_bmp_glyph171_lines + 40,
      fterm_bmp_glyph171_lines + 45,
      fterm_bmp_glyph171_lines + 50,
      fterm_bmp_glyph171_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph172_lines[] = 
"\a\0\a\0\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph172 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph172_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph172_lines + 0,
      fterm_bmp_glyph172_lines + 5,
      fterm_bmp_glyph172_lines + 10,
      fterm_bmp_glyph172_lines + 15,
      fterm_bmp_glyph172_lines + 20,
      fterm_bmp_glyph172_lines + 25,
      fterm_bmp_glyph172_lines + 30,
      fterm_bmp_glyph172_lines + 35,
      fterm_bmp_glyph172_lines + 40,
      fterm_bmp_glyph172_lines + 45,
      fterm_bmp_glyph172_lines + 50,
      fterm_bmp_glyph172_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph173_lines[] = 
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
"\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph173 = {
    1, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph173_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph173_lines + 0,
      fterm_bmp_glyph173_lines + 1,
      fterm_bmp_glyph173_lines + 2,
      fterm_bmp_glyph173_lines + 3,
      fterm_bmp_glyph173_lines + 4,
      fterm_bmp_glyph173_lines + 5,
      fterm_bmp_glyph173_lines + 6,
      fterm_bmp_glyph173_lines + 7,
      fterm_bmp_glyph173_lines + 8,
      fterm_bmp_glyph173_lines + 9,
      fterm_bmp_glyph173_lines + 10,
      fterm_bmp_glyph173_lines + 11,
      0 }
};

static unsigned char fterm_bmp_glyph174_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\0\a\0\0"
"\a\0\a\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph174 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph174_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph174_lines + 0,
      fterm_bmp_glyph174_lines + 5,
      fterm_bmp_glyph174_lines + 10,
      fterm_bmp_glyph174_lines + 15,
      fterm_bmp_glyph174_lines + 20,
      fterm_bmp_glyph174_lines + 25,
      fterm_bmp_glyph174_lines + 30,
      fterm_bmp_glyph174_lines + 35,
      fterm_bmp_glyph174_lines + 40,
      fterm_bmp_glyph174_lines + 45,
      fterm_bmp_glyph174_lines + 50,
      fterm_bmp_glyph174_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph175_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\0\a\0\0"
"\a\0\a\0\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\0\a\0\0"
"\a\0\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph175 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph175_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph175_lines + 0,
      fterm_bmp_glyph175_lines + 5,
      fterm_bmp_glyph175_lines + 10,
      fterm_bmp_glyph175_lines + 15,
      fterm_bmp_glyph175_lines + 20,
      fterm_bmp_glyph175_lines + 25,
      fterm_bmp_glyph175_lines + 30,
      fterm_bmp_glyph175_lines + 35,
      fterm_bmp_glyph175_lines + 40,
      fterm_bmp_glyph175_lines + 45,
      fterm_bmp_glyph175_lines + 50,
      fterm_bmp_glyph175_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph176_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\0\a\0\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\0\a\0\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph176 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph176_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph176_lines + 0,
      fterm_bmp_glyph176_lines + 5,
      fterm_bmp_glyph176_lines + 10,
      fterm_bmp_glyph176_lines + 15,
      fterm_bmp_glyph176_lines + 20,
      fterm_bmp_glyph176_lines + 25,
      fterm_bmp_glyph176_lines + 30,
      fterm_bmp_glyph176_lines + 35,
      fterm_bmp_glyph176_lines + 40,
      fterm_bmp_glyph176_lines + 45,
      fterm_bmp_glyph176_lines + 50,
      fterm_bmp_glyph176_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph177_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\a\0\a\0\a"
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\a\0\a\0\a"
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\a\0\a\0\a"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph177 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph177_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph177_lines + 0,
      fterm_bmp_glyph177_lines + 5,
      fterm_bmp_glyph177_lines + 10,
      fterm_bmp_glyph177_lines + 15,
      fterm_bmp_glyph177_lines + 20,
      fterm_bmp_glyph177_lines + 25,
      fterm_bmp_glyph177_lines + 30,
      fterm_bmp_glyph177_lines + 35,
      fterm_bmp_glyph177_lines + 40,
      fterm_bmp_glyph177_lines + 45,
      fterm_bmp_glyph177_lines + 50,
      fterm_bmp_glyph177_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph178_lines[] = 
"\0\a\0\a\0"
"\a\0\a\0\a"
"\0\a\0\a\0"
"\a\0\a\0\a"
"\0\a\0\a\0"
"\a\0\a\0\a"
"\0\a\0\a\0"
"\a\0\a\0\a"
"\0\a\0\a\0"
"\a\0\a\0\a"
"\0\a\0\a\0"
"\a\0\a\0\a"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph178 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph178_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph178_lines + 0,
      fterm_bmp_glyph178_lines + 5,
      fterm_bmp_glyph178_lines + 10,
      fterm_bmp_glyph178_lines + 15,
      fterm_bmp_glyph178_lines + 20,
      fterm_bmp_glyph178_lines + 25,
      fterm_bmp_glyph178_lines + 30,
      fterm_bmp_glyph178_lines + 35,
      fterm_bmp_glyph178_lines + 40,
      fterm_bmp_glyph178_lines + 45,
      fterm_bmp_glyph178_lines + 50,
      fterm_bmp_glyph178_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph179_lines[] = 
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph179 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph179_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph179_lines + 0,
      fterm_bmp_glyph179_lines + 5,
      fterm_bmp_glyph179_lines + 10,
      fterm_bmp_glyph179_lines + 15,
      fterm_bmp_glyph179_lines + 20,
      fterm_bmp_glyph179_lines + 25,
      fterm_bmp_glyph179_lines + 30,
      fterm_bmp_glyph179_lines + 35,
      fterm_bmp_glyph179_lines + 40,
      fterm_bmp_glyph179_lines + 45,
      fterm_bmp_glyph179_lines + 50,
      fterm_bmp_glyph179_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph180_lines[] = 
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\a\a\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph180 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph180_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph180_lines + 0,
      fterm_bmp_glyph180_lines + 5,
      fterm_bmp_glyph180_lines + 10,
      fterm_bmp_glyph180_lines + 15,
      fterm_bmp_glyph180_lines + 20,
      fterm_bmp_glyph180_lines + 25,
      fterm_bmp_glyph180_lines + 30,
      fterm_bmp_glyph180_lines + 35,
      fterm_bmp_glyph180_lines + 40,
      fterm_bmp_glyph180_lines + 45,
      fterm_bmp_glyph180_lines + 50,
      fterm_bmp_glyph180_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph181_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph181 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph181_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph181_lines + 0,
      fterm_bmp_glyph181_lines + 5,
      fterm_bmp_glyph181_lines + 10,
      fterm_bmp_glyph181_lines + 15,
      fterm_bmp_glyph181_lines + 20,
      fterm_bmp_glyph181_lines + 25,
      fterm_bmp_glyph181_lines + 30,
      fterm_bmp_glyph181_lines + 35,
      fterm_bmp_glyph181_lines + 40,
      fterm_bmp_glyph181_lines + 45,
      fterm_bmp_glyph181_lines + 50,
      fterm_bmp_glyph181_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph182_lines[] = 
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph182 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph182_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph182_lines + 0,
      fterm_bmp_glyph182_lines + 5,
      fterm_bmp_glyph182_lines + 10,
      fterm_bmp_glyph182_lines + 15,
      fterm_bmp_glyph182_lines + 20,
      fterm_bmp_glyph182_lines + 25,
      fterm_bmp_glyph182_lines + 30,
      fterm_bmp_glyph182_lines + 35,
      fterm_bmp_glyph182_lines + 40,
      fterm_bmp_glyph182_lines + 45,
      fterm_bmp_glyph182_lines + 50,
      fterm_bmp_glyph182_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph183_lines[] = 
"\a\0\a\0\0"
"\0\a\0\0\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph183 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph183_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph183_lines + 0,
      fterm_bmp_glyph183_lines + 5,
      fterm_bmp_glyph183_lines + 10,
      fterm_bmp_glyph183_lines + 15,
      fterm_bmp_glyph183_lines + 20,
      fterm_bmp_glyph183_lines + 25,
      fterm_bmp_glyph183_lines + 30,
      fterm_bmp_glyph183_lines + 35,
      fterm_bmp_glyph183_lines + 40,
      fterm_bmp_glyph183_lines + 45,
      fterm_bmp_glyph183_lines + 50,
      fterm_bmp_glyph183_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph184_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\0\a\a\0\0"
"\0\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\a\0\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph184 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph184_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph184_lines + 0,
      fterm_bmp_glyph184_lines + 5,
      fterm_bmp_glyph184_lines + 10,
      fterm_bmp_glyph184_lines + 15,
      fterm_bmp_glyph184_lines + 20,
      fterm_bmp_glyph184_lines + 25,
      fterm_bmp_glyph184_lines + 30,
      fterm_bmp_glyph184_lines + 35,
      fterm_bmp_glyph184_lines + 40,
      fterm_bmp_glyph184_lines + 45,
      fterm_bmp_glyph184_lines + 50,
      fterm_bmp_glyph184_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph185_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\a\0\a\0"
"\0\0\0\a\0"
"\a\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph185 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph185_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph185_lines + 0,
      fterm_bmp_glyph185_lines + 5,
      fterm_bmp_glyph185_lines + 10,
      fterm_bmp_glyph185_lines + 15,
      fterm_bmp_glyph185_lines + 20,
      fterm_bmp_glyph185_lines + 25,
      fterm_bmp_glyph185_lines + 30,
      fterm_bmp_glyph185_lines + 35,
      fterm_bmp_glyph185_lines + 40,
      fterm_bmp_glyph185_lines + 45,
      fterm_bmp_glyph185_lines + 50,
      fterm_bmp_glyph185_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph186_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph186 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph186_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph186_lines + 0,
      fterm_bmp_glyph186_lines + 5,
      fterm_bmp_glyph186_lines + 10,
      fterm_bmp_glyph186_lines + 15,
      fterm_bmp_glyph186_lines + 20,
      fterm_bmp_glyph186_lines + 25,
      fterm_bmp_glyph186_lines + 30,
      fterm_bmp_glyph186_lines + 35,
      fterm_bmp_glyph186_lines + 40,
      fterm_bmp_glyph186_lines + 45,
      fterm_bmp_glyph186_lines + 50,
      fterm_bmp_glyph186_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph187_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\a\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph187 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph187_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph187_lines + 0,
      fterm_bmp_glyph187_lines + 5,
      fterm_bmp_glyph187_lines + 10,
      fterm_bmp_glyph187_lines + 15,
      fterm_bmp_glyph187_lines + 20,
      fterm_bmp_glyph187_lines + 25,
      fterm_bmp_glyph187_lines + 30,
      fterm_bmp_glyph187_lines + 35,
      fterm_bmp_glyph187_lines + 40,
      fterm_bmp_glyph187_lines + 45,
      fterm_bmp_glyph187_lines + 50,
      fterm_bmp_glyph187_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph188_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\a\0\a\0"
"\0\0\0\a\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph188 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph188_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph188_lines + 0,
      fterm_bmp_glyph188_lines + 5,
      fterm_bmp_glyph188_lines + 10,
      fterm_bmp_glyph188_lines + 15,
      fterm_bmp_glyph188_lines + 20,
      fterm_bmp_glyph188_lines + 25,
      fterm_bmp_glyph188_lines + 30,
      fterm_bmp_glyph188_lines + 35,
      fterm_bmp_glyph188_lines + 40,
      fterm_bmp_glyph188_lines + 45,
      fterm_bmp_glyph188_lines + 50,
      fterm_bmp_glyph188_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph189_lines[] = 
"\0\a\a\0\0"
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph189 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph189_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph189_lines + 0,
      fterm_bmp_glyph189_lines + 5,
      fterm_bmp_glyph189_lines + 10,
      fterm_bmp_glyph189_lines + 15,
      fterm_bmp_glyph189_lines + 20,
      fterm_bmp_glyph189_lines + 25,
      fterm_bmp_glyph189_lines + 30,
      fterm_bmp_glyph189_lines + 35,
      fterm_bmp_glyph189_lines + 40,
      fterm_bmp_glyph189_lines + 45,
      fterm_bmp_glyph189_lines + 50,
      fterm_bmp_glyph189_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph190_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\a\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\a\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph190 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph190_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph190_lines + 0,
      fterm_bmp_glyph190_lines + 5,
      fterm_bmp_glyph190_lines + 10,
      fterm_bmp_glyph190_lines + 15,
      fterm_bmp_glyph190_lines + 20,
      fterm_bmp_glyph190_lines + 25,
      fterm_bmp_glyph190_lines + 30,
      fterm_bmp_glyph190_lines + 35,
      fterm_bmp_glyph190_lines + 40,
      fterm_bmp_glyph190_lines + 45,
      fterm_bmp_glyph190_lines + 50,
      fterm_bmp_glyph190_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph191_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0.\0\0\0"
"\0.\0\0\0"
"\0\0\0\0\0"
"\0.\0\0\0"
"\0.\0\0\0"
".\0\0\0\0"
".\0\0.\0"
".\0\0.\0"
"\0..\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph191 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph191_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph191_lines + 0,
      fterm_bmp_glyph191_lines + 5,
      fterm_bmp_glyph191_lines + 10,
      fterm_bmp_glyph191_lines + 15,
      fterm_bmp_glyph191_lines + 20,
      fterm_bmp_glyph191_lines + 25,
      fterm_bmp_glyph191_lines + 30,
      fterm_bmp_glyph191_lines + 35,
      fterm_bmp_glyph191_lines + 40,
      fterm_bmp_glyph191_lines + 45,
      fterm_bmp_glyph191_lines + 50,
      fterm_bmp_glyph191_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph192_lines[] = 
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\a\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph192 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph192_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph192_lines + 0,
      fterm_bmp_glyph192_lines + 5,
      fterm_bmp_glyph192_lines + 10,
      fterm_bmp_glyph192_lines + 15,
      fterm_bmp_glyph192_lines + 20,
      fterm_bmp_glyph192_lines + 25,
      fterm_bmp_glyph192_lines + 30,
      fterm_bmp_glyph192_lines + 35,
      fterm_bmp_glyph192_lines + 40,
      fterm_bmp_glyph192_lines + 45,
      fterm_bmp_glyph192_lines + 50,
      fterm_bmp_glyph192_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph193_lines[] = 
"\0\0..\0"
"\0.\0\0\0"
"\0..\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"....\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph193 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph193_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph193_lines + 0,
      fterm_bmp_glyph193_lines + 5,
      fterm_bmp_glyph193_lines + 10,
      fterm_bmp_glyph193_lines + 15,
      fterm_bmp_glyph193_lines + 20,
      fterm_bmp_glyph193_lines + 25,
      fterm_bmp_glyph193_lines + 30,
      fterm_bmp_glyph193_lines + 35,
      fterm_bmp_glyph193_lines + 40,
      fterm_bmp_glyph193_lines + 45,
      fterm_bmp_glyph193_lines + 50,
      fterm_bmp_glyph193_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph194_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\a\a\a\a"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph194 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph194_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph194_lines + 0,
      fterm_bmp_glyph194_lines + 5,
      fterm_bmp_glyph194_lines + 10,
      fterm_bmp_glyph194_lines + 15,
      fterm_bmp_glyph194_lines + 20,
      fterm_bmp_glyph194_lines + 25,
      fterm_bmp_glyph194_lines + 30,
      fterm_bmp_glyph194_lines + 35,
      fterm_bmp_glyph194_lines + 40,
      fterm_bmp_glyph194_lines + 45,
      fterm_bmp_glyph194_lines + 50,
      fterm_bmp_glyph194_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph195_lines[] = 
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\a\a"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph195 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph195_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph195_lines + 0,
      fterm_bmp_glyph195_lines + 5,
      fterm_bmp_glyph195_lines + 10,
      fterm_bmp_glyph195_lines + 15,
      fterm_bmp_glyph195_lines + 20,
      fterm_bmp_glyph195_lines + 25,
      fterm_bmp_glyph195_lines + 30,
      fterm_bmp_glyph195_lines + 35,
      fterm_bmp_glyph195_lines + 40,
      fterm_bmp_glyph195_lines + 45,
      fterm_bmp_glyph195_lines + 50,
      fterm_bmp_glyph195_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph196_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\a\a\a\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph196 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph196_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph196_lines + 0,
      fterm_bmp_glyph196_lines + 5,
      fterm_bmp_glyph196_lines + 10,
      fterm_bmp_glyph196_lines + 15,
      fterm_bmp_glyph196_lines + 20,
      fterm_bmp_glyph196_lines + 25,
      fterm_bmp_glyph196_lines + 30,
      fterm_bmp_glyph196_lines + 35,
      fterm_bmp_glyph196_lines + 40,
      fterm_bmp_glyph196_lines + 45,
      fterm_bmp_glyph196_lines + 50,
      fterm_bmp_glyph196_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph197_lines[] = 
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\a\a\a\a\a"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph197 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph197_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph197_lines + 0,
      fterm_bmp_glyph197_lines + 5,
      fterm_bmp_glyph197_lines + 10,
      fterm_bmp_glyph197_lines + 15,
      fterm_bmp_glyph197_lines + 20,
      fterm_bmp_glyph197_lines + 25,
      fterm_bmp_glyph197_lines + 30,
      fterm_bmp_glyph197_lines + 35,
      fterm_bmp_glyph197_lines + 40,
      fterm_bmp_glyph197_lines + 45,
      fterm_bmp_glyph197_lines + 50,
      fterm_bmp_glyph197_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph198_lines[] = 
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph198 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph198_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph198_lines + 0,
      fterm_bmp_glyph198_lines + 5,
      fterm_bmp_glyph198_lines + 10,
      fterm_bmp_glyph198_lines + 15,
      fterm_bmp_glyph198_lines + 20,
      fterm_bmp_glyph198_lines + 25,
      fterm_bmp_glyph198_lines + 30,
      fterm_bmp_glyph198_lines + 35,
      fterm_bmp_glyph198_lines + 40,
      fterm_bmp_glyph198_lines + 45,
      fterm_bmp_glyph198_lines + 50,
      fterm_bmp_glyph198_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph199_lines[] = 
"\0\0\0\0\0"
"\0\xb6\xb6\0\0"
"\xb6\0\0\xb6\0"
"\xb6\0\0\xb6\0"
"\xb6\0\0\0\0"
"\xb6\0\0\0\0"
"\xb6\0\0\0\0"
"\xb6\0\0\0\0"
"\xb6\0\0\xb6\0"
"\0\xb6\xb6\0\0"
"\0\0\xb6\0\0"
"\0\xb6\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph199 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph199_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph199_lines + 0,
      fterm_bmp_glyph199_lines + 5,
      fterm_bmp_glyph199_lines + 10,
      fterm_bmp_glyph199_lines + 15,
      fterm_bmp_glyph199_lines + 20,
      fterm_bmp_glyph199_lines + 25,
      fterm_bmp_glyph199_lines + 30,
      fterm_bmp_glyph199_lines + 35,
      fterm_bmp_glyph199_lines + 40,
      fterm_bmp_glyph199_lines + 45,
      fterm_bmp_glyph199_lines + 50,
      fterm_bmp_glyph199_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph200_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\a"
"\0\a\0\0\0"
"\0\a\a\a\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph200 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph200_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph200_lines + 0,
      fterm_bmp_glyph200_lines + 5,
      fterm_bmp_glyph200_lines + 10,
      fterm_bmp_glyph200_lines + 15,
      fterm_bmp_glyph200_lines + 20,
      fterm_bmp_glyph200_lines + 25,
      fterm_bmp_glyph200_lines + 30,
      fterm_bmp_glyph200_lines + 35,
      fterm_bmp_glyph200_lines + 40,
      fterm_bmp_glyph200_lines + 45,
      fterm_bmp_glyph200_lines + 50,
      fterm_bmp_glyph200_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph201_lines[] = 
"\0\0..\0"
"\0.\0\0\0"
"....\0"
".\0\0\0\0"
".\0\0\0\0"
"....\0"
".\0\0\0\0"
".\0\0\0\0"
".\0\0\0\0"
"....\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph201 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph201_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph201_lines + 0,
      fterm_bmp_glyph201_lines + 5,
      fterm_bmp_glyph201_lines + 10,
      fterm_bmp_glyph201_lines + 15,
      fterm_bmp_glyph201_lines + 20,
      fterm_bmp_glyph201_lines + 25,
      fterm_bmp_glyph201_lines + 30,
      fterm_bmp_glyph201_lines + 35,
      fterm_bmp_glyph201_lines + 40,
      fterm_bmp_glyph201_lines + 45,
      fterm_bmp_glyph201_lines + 50,
      fterm_bmp_glyph201_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph202_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\a\0\a\a"
"\0\0\0\0\0"
"\a\a\a\a\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph202 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph202_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph202_lines + 0,
      fterm_bmp_glyph202_lines + 5,
      fterm_bmp_glyph202_lines + 10,
      fterm_bmp_glyph202_lines + 15,
      fterm_bmp_glyph202_lines + 20,
      fterm_bmp_glyph202_lines + 25,
      fterm_bmp_glyph202_lines + 30,
      fterm_bmp_glyph202_lines + 35,
      fterm_bmp_glyph202_lines + 40,
      fterm_bmp_glyph202_lines + 45,
      fterm_bmp_glyph202_lines + 50,
      fterm_bmp_glyph202_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph203_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\a\a\a\a"
"\0\0\0\0\0"
"\a\a\0\a\a"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph203 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph203_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph203_lines + 0,
      fterm_bmp_glyph203_lines + 5,
      fterm_bmp_glyph203_lines + 10,
      fterm_bmp_glyph203_lines + 15,
      fterm_bmp_glyph203_lines + 20,
      fterm_bmp_glyph203_lines + 25,
      fterm_bmp_glyph203_lines + 30,
      fterm_bmp_glyph203_lines + 35,
      fterm_bmp_glyph203_lines + 40,
      fterm_bmp_glyph203_lines + 45,
      fterm_bmp_glyph203_lines + 50,
      fterm_bmp_glyph203_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph204_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\a"
"\0\a\0\0\0"
"\0\a\0\a\a"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph204 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph204_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph204_lines + 0,
      fterm_bmp_glyph204_lines + 5,
      fterm_bmp_glyph204_lines + 10,
      fterm_bmp_glyph204_lines + 15,
      fterm_bmp_glyph204_lines + 20,
      fterm_bmp_glyph204_lines + 25,
      fterm_bmp_glyph204_lines + 30,
      fterm_bmp_glyph204_lines + 35,
      fterm_bmp_glyph204_lines + 40,
      fterm_bmp_glyph204_lines + 45,
      fterm_bmp_glyph204_lines + 50,
      fterm_bmp_glyph204_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph205_lines[] = 
"\0\0..\0"
"\0.\0\0\0"
"\0...\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0...\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph205 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph205_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph205_lines + 0,
      fterm_bmp_glyph205_lines + 5,
      fterm_bmp_glyph205_lines + 10,
      fterm_bmp_glyph205_lines + 15,
      fterm_bmp_glyph205_lines + 20,
      fterm_bmp_glyph205_lines + 25,
      fterm_bmp_glyph205_lines + 30,
      fterm_bmp_glyph205_lines + 35,
      fterm_bmp_glyph205_lines + 40,
      fterm_bmp_glyph205_lines + 45,
      fterm_bmp_glyph205_lines + 50,
      fterm_bmp_glyph205_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph206_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\a\a\0\a\a"
"\0\0\0\0\0"
"\a\a\0\a\a"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\a\0\a\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph206 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph206_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph206_lines + 0,
      fterm_bmp_glyph206_lines + 5,
      fterm_bmp_glyph206_lines + 10,
      fterm_bmp_glyph206_lines + 15,
      fterm_bmp_glyph206_lines + 20,
      fterm_bmp_glyph206_lines + 25,
      fterm_bmp_glyph206_lines + 30,
      fterm_bmp_glyph206_lines + 35,
      fterm_bmp_glyph206_lines + 40,
      fterm_bmp_glyph206_lines + 45,
      fterm_bmp_glyph206_lines + 50,
      fterm_bmp_glyph206_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph207_lines[] = 
"\0\0\0\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph207 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph207_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph207_lines + 0,
      fterm_bmp_glyph207_lines + 5,
      fterm_bmp_glyph207_lines + 10,
      fterm_bmp_glyph207_lines + 15,
      fterm_bmp_glyph207_lines + 20,
      fterm_bmp_glyph207_lines + 25,
      fterm_bmp_glyph207_lines + 30,
      fterm_bmp_glyph207_lines + 35,
      fterm_bmp_glyph207_lines + 40,
      fterm_bmp_glyph207_lines + 45,
      fterm_bmp_glyph207_lines + 50,
      fterm_bmp_glyph207_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph208_lines[] = 
"\0\0\0\0\0"
"\0\0\0\a\0"
"\0\a\a\a\a"
"\0\0\0\a\0"
"\0\a\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph208 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph208_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph208_lines + 0,
      fterm_bmp_glyph208_lines + 5,
      fterm_bmp_glyph208_lines + 10,
      fterm_bmp_glyph208_lines + 15,
      fterm_bmp_glyph208_lines + 20,
      fterm_bmp_glyph208_lines + 25,
      fterm_bmp_glyph208_lines + 30,
      fterm_bmp_glyph208_lines + 35,
      fterm_bmp_glyph208_lines + 40,
      fterm_bmp_glyph208_lines + 45,
      fterm_bmp_glyph208_lines + 50,
      fterm_bmp_glyph208_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph209_lines[] = 
"....\0"
"\0\0\0\0\0"
".\0\0.\0"
"..\0.\0"
"..\0.\0"
".\0..\0"
".\0..\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph209 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph209_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph209_lines + 0,
      fterm_bmp_glyph209_lines + 5,
      fterm_bmp_glyph209_lines + 10,
      fterm_bmp_glyph209_lines + 15,
      fterm_bmp_glyph209_lines + 20,
      fterm_bmp_glyph209_lines + 25,
      fterm_bmp_glyph209_lines + 30,
      fterm_bmp_glyph209_lines + 35,
      fterm_bmp_glyph209_lines + 40,
      fterm_bmp_glyph209_lines + 45,
      fterm_bmp_glyph209_lines + 50,
      fterm_bmp_glyph209_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph210_lines[] = 
"\a\0\a\0\0"
"\0\a\0\0\0"
"\a\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph210 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph210_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph210_lines + 0,
      fterm_bmp_glyph210_lines + 5,
      fterm_bmp_glyph210_lines + 10,
      fterm_bmp_glyph210_lines + 15,
      fterm_bmp_glyph210_lines + 20,
      fterm_bmp_glyph210_lines + 25,
      fterm_bmp_glyph210_lines + 30,
      fterm_bmp_glyph210_lines + 35,
      fterm_bmp_glyph210_lines + 40,
      fterm_bmp_glyph210_lines + 45,
      fterm_bmp_glyph210_lines + 50,
      fterm_bmp_glyph210_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph211_lines[] = 
"\0\0..\0"
"\0.\0\0\0"
"\0..\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0..\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph211 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph211_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph211_lines + 0,
      fterm_bmp_glyph211_lines + 5,
      fterm_bmp_glyph211_lines + 10,
      fterm_bmp_glyph211_lines + 15,
      fterm_bmp_glyph211_lines + 20,
      fterm_bmp_glyph211_lines + 25,
      fterm_bmp_glyph211_lines + 30,
      fterm_bmp_glyph211_lines + 35,
      fterm_bmp_glyph211_lines + 40,
      fterm_bmp_glyph211_lines + 45,
      fterm_bmp_glyph211_lines + 50,
      fterm_bmp_glyph211_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph212_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\a"
"\0\0\a\a\a"
"\0\0\a\0\a"
"\0\a\a\a\0"
"\a\0\a\0\0"
"\a\0\a\0\0"
"\a\0\a\0\0"
"\a\0\a\0\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph212 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph212_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph212_lines + 0,
      fterm_bmp_glyph212_lines + 5,
      fterm_bmp_glyph212_lines + 10,
      fterm_bmp_glyph212_lines + 15,
      fterm_bmp_glyph212_lines + 20,
      fterm_bmp_glyph212_lines + 25,
      fterm_bmp_glyph212_lines + 30,
      fterm_bmp_glyph212_lines + 35,
      fterm_bmp_glyph212_lines + 40,
      fterm_bmp_glyph212_lines + 45,
      fterm_bmp_glyph212_lines + 50,
      fterm_bmp_glyph212_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph213_lines[] = 
"\a\0\0\a\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\a\0\a\0"
"\a\a\0\a\0"
"\a\0\a\a\0"
"\a\0\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph213 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph213_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph213_lines + 0,
      fterm_bmp_glyph213_lines + 5,
      fterm_bmp_glyph213_lines + 10,
      fterm_bmp_glyph213_lines + 15,
      fterm_bmp_glyph213_lines + 20,
      fterm_bmp_glyph213_lines + 25,
      fterm_bmp_glyph213_lines + 30,
      fterm_bmp_glyph213_lines + 35,
      fterm_bmp_glyph213_lines + 40,
      fterm_bmp_glyph213_lines + 45,
      fterm_bmp_glyph213_lines + 50,
      fterm_bmp_glyph213_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph214_lines[] = 
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph214 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph214_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph214_lines + 0,
      fterm_bmp_glyph214_lines + 5,
      fterm_bmp_glyph214_lines + 10,
      fterm_bmp_glyph214_lines + 15,
      fterm_bmp_glyph214_lines + 20,
      fterm_bmp_glyph214_lines + 25,
      fterm_bmp_glyph214_lines + 30,
      fterm_bmp_glyph214_lines + 35,
      fterm_bmp_glyph214_lines + 40,
      fterm_bmp_glyph214_lines + 45,
      fterm_bmp_glyph214_lines + 50,
      fterm_bmp_glyph214_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph215_lines[] = 
"\0\0\a\0\0"
"\0\a\0\a\0"
"\0\a\a\a\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph215 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph215_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph215_lines + 0,
      fterm_bmp_glyph215_lines + 5,
      fterm_bmp_glyph215_lines + 10,
      fterm_bmp_glyph215_lines + 15,
      fterm_bmp_glyph215_lines + 20,
      fterm_bmp_glyph215_lines + 25,
      fterm_bmp_glyph215_lines + 30,
      fterm_bmp_glyph215_lines + 35,
      fterm_bmp_glyph215_lines + 40,
      fterm_bmp_glyph215_lines + 45,
      fterm_bmp_glyph215_lines + 50,
      fterm_bmp_glyph215_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph216_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\a\0"
"\a\0\0\0\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph216 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph216_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph216_lines + 0,
      fterm_bmp_glyph216_lines + 5,
      fterm_bmp_glyph216_lines + 10,
      fterm_bmp_glyph216_lines + 15,
      fterm_bmp_glyph216_lines + 20,
      fterm_bmp_glyph216_lines + 25,
      fterm_bmp_glyph216_lines + 30,
      fterm_bmp_glyph216_lines + 35,
      fterm_bmp_glyph216_lines + 40,
      fterm_bmp_glyph216_lines + 45,
      fterm_bmp_glyph216_lines + 50,
      fterm_bmp_glyph216_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph217_lines[] = 
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\a\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph217 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph217_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph217_lines + 0,
      fterm_bmp_glyph217_lines + 5,
      fterm_bmp_glyph217_lines + 10,
      fterm_bmp_glyph217_lines + 15,
      fterm_bmp_glyph217_lines + 20,
      fterm_bmp_glyph217_lines + 25,
      fterm_bmp_glyph217_lines + 30,
      fterm_bmp_glyph217_lines + 35,
      fterm_bmp_glyph217_lines + 40,
      fterm_bmp_glyph217_lines + 45,
      fterm_bmp_glyph217_lines + 50,
      fterm_bmp_glyph217_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph218_lines[] = 
"\0\0..\0"
"\0.\0\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0..\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph218 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph218_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph218_lines + 0,
      fterm_bmp_glyph218_lines + 5,
      fterm_bmp_glyph218_lines + 10,
      fterm_bmp_glyph218_lines + 15,
      fterm_bmp_glyph218_lines + 20,
      fterm_bmp_glyph218_lines + 25,
      fterm_bmp_glyph218_lines + 30,
      fterm_bmp_glyph218_lines + 35,
      fterm_bmp_glyph218_lines + 40,
      fterm_bmp_glyph218_lines + 45,
      fterm_bmp_glyph218_lines + 50,
      fterm_bmp_glyph218_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph219_lines[] = 
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph219 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph219_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph219_lines + 0,
      fterm_bmp_glyph219_lines + 5,
      fterm_bmp_glyph219_lines + 10,
      fterm_bmp_glyph219_lines + 15,
      fterm_bmp_glyph219_lines + 20,
      fterm_bmp_glyph219_lines + 25,
      fterm_bmp_glyph219_lines + 30,
      fterm_bmp_glyph219_lines + 35,
      fterm_bmp_glyph219_lines + 40,
      fterm_bmp_glyph219_lines + 45,
      fterm_bmp_glyph219_lines + 50,
      fterm_bmp_glyph219_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph220_lines[] = 
".\0\0.\0"
"\0\0\0\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0..\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph220 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph220_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph220_lines + 0,
      fterm_bmp_glyph220_lines + 5,
      fterm_bmp_glyph220_lines + 10,
      fterm_bmp_glyph220_lines + 15,
      fterm_bmp_glyph220_lines + 20,
      fterm_bmp_glyph220_lines + 25,
      fterm_bmp_glyph220_lines + 30,
      fterm_bmp_glyph220_lines + 35,
      fterm_bmp_glyph220_lines + 40,
      fterm_bmp_glyph220_lines + 45,
      fterm_bmp_glyph220_lines + 50,
      fterm_bmp_glyph220_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph221_lines[] = 
"\0\0\0\0\0"
"\a\a\a\a\a"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\a\0\0"
"\0\0\0\a\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph221 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph221_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph221_lines + 0,
      fterm_bmp_glyph221_lines + 5,
      fterm_bmp_glyph221_lines + 10,
      fterm_bmp_glyph221_lines + 15,
      fterm_bmp_glyph221_lines + 20,
      fterm_bmp_glyph221_lines + 25,
      fterm_bmp_glyph221_lines + 30,
      fterm_bmp_glyph221_lines + 35,
      fterm_bmp_glyph221_lines + 40,
      fterm_bmp_glyph221_lines + 45,
      fterm_bmp_glyph221_lines + 50,
      fterm_bmp_glyph221_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph222_lines[] = 
"\0\a\a\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph222 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph222_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph222_lines + 0,
      fterm_bmp_glyph222_lines + 5,
      fterm_bmp_glyph222_lines + 10,
      fterm_bmp_glyph222_lines + 15,
      fterm_bmp_glyph222_lines + 20,
      fterm_bmp_glyph222_lines + 25,
      fterm_bmp_glyph222_lines + 30,
      fterm_bmp_glyph222_lines + 35,
      fterm_bmp_glyph222_lines + 40,
      fterm_bmp_glyph222_lines + 45,
      fterm_bmp_glyph222_lines + 50,
      fterm_bmp_glyph222_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph223_lines[] = 
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\a\a\a\a\a"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph223 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph223_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph223_lines + 0,
      fterm_bmp_glyph223_lines + 5,
      fterm_bmp_glyph223_lines + 10,
      fterm_bmp_glyph223_lines + 15,
      fterm_bmp_glyph223_lines + 20,
      fterm_bmp_glyph223_lines + 25,
      fterm_bmp_glyph223_lines + 30,
      fterm_bmp_glyph223_lines + 35,
      fterm_bmp_glyph223_lines + 40,
      fterm_bmp_glyph223_lines + 45,
      fterm_bmp_glyph223_lines + 50,
      fterm_bmp_glyph223_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph224_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph224 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph224_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph224_lines + 0,
      fterm_bmp_glyph224_lines + 5,
      fterm_bmp_glyph224_lines + 10,
      fterm_bmp_glyph224_lines + 15,
      fterm_bmp_glyph224_lines + 20,
      fterm_bmp_glyph224_lines + 25,
      fterm_bmp_glyph224_lines + 30,
      fterm_bmp_glyph224_lines + 35,
      fterm_bmp_glyph224_lines + 40,
      fterm_bmp_glyph224_lines + 45,
      fterm_bmp_glyph224_lines + 50,
      fterm_bmp_glyph224_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph225_lines[] = 
"\0\0\0\0\0"
"\0\0..\0"
"\0.\0\0\0"
"\0\0\0\0\0"
"\0..\0\0"
".\0\0.\0"
"\0\0\0.\0"
"\0...\0"
".\0\0.\0"
"\0...\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph225 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph225_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph225_lines + 0,
      fterm_bmp_glyph225_lines + 5,
      fterm_bmp_glyph225_lines + 10,
      fterm_bmp_glyph225_lines + 15,
      fterm_bmp_glyph225_lines + 20,
      fterm_bmp_glyph225_lines + 25,
      fterm_bmp_glyph225_lines + 30,
      fterm_bmp_glyph225_lines + 35,
      fterm_bmp_glyph225_lines + 40,
      fterm_bmp_glyph225_lines + 45,
      fterm_bmp_glyph225_lines + 50,
      fterm_bmp_glyph225_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph226_lines[] = 
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph226 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph226_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph226_lines + 0,
      fterm_bmp_glyph226_lines + 5,
      fterm_bmp_glyph226_lines + 10,
      fterm_bmp_glyph226_lines + 15,
      fterm_bmp_glyph226_lines + 20,
      fterm_bmp_glyph226_lines + 25,
      fterm_bmp_glyph226_lines + 30,
      fterm_bmp_glyph226_lines + 35,
      fterm_bmp_glyph226_lines + 40,
      fterm_bmp_glyph226_lines + 45,
      fterm_bmp_glyph226_lines + 50,
      fterm_bmp_glyph226_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph227_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\a\0\0\a\0"
"\a\a\0\a\0"
"\a\a\0\a\0"
"\a\0\a\a\0"
"\a\0\a\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph227 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph227_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph227_lines + 0,
      fterm_bmp_glyph227_lines + 5,
      fterm_bmp_glyph227_lines + 10,
      fterm_bmp_glyph227_lines + 15,
      fterm_bmp_glyph227_lines + 20,
      fterm_bmp_glyph227_lines + 25,
      fterm_bmp_glyph227_lines + 30,
      fterm_bmp_glyph227_lines + 35,
      fterm_bmp_glyph227_lines + 40,
      fterm_bmp_glyph227_lines + 45,
      fterm_bmp_glyph227_lines + 50,
      fterm_bmp_glyph227_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph228_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\a\0\a\0\0"
"\a\a\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph228 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph228_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph228_lines + 0,
      fterm_bmp_glyph228_lines + 5,
      fterm_bmp_glyph228_lines + 10,
      fterm_bmp_glyph228_lines + 15,
      fterm_bmp_glyph228_lines + 20,
      fterm_bmp_glyph228_lines + 25,
      fterm_bmp_glyph228_lines + 30,
      fterm_bmp_glyph228_lines + 35,
      fterm_bmp_glyph228_lines + 40,
      fterm_bmp_glyph228_lines + 45,
      fterm_bmp_glyph228_lines + 50,
      fterm_bmp_glyph228_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph229_lines[] = 
"\0\0\0\0\0"
"\a\0\a\0\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\a\0\a\0\0"
"\a\a\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph229 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph229_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph229_lines + 0,
      fterm_bmp_glyph229_lines + 5,
      fterm_bmp_glyph229_lines + 10,
      fterm_bmp_glyph229_lines + 15,
      fterm_bmp_glyph229_lines + 20,
      fterm_bmp_glyph229_lines + 25,
      fterm_bmp_glyph229_lines + 30,
      fterm_bmp_glyph229_lines + 35,
      fterm_bmp_glyph229_lines + 40,
      fterm_bmp_glyph229_lines + 45,
      fterm_bmp_glyph229_lines + 50,
      fterm_bmp_glyph229_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph230_lines[] = 
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\0\a\a\0\0"
"\0\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph230 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph230_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph230_lines + 0,
      fterm_bmp_glyph230_lines + 5,
      fterm_bmp_glyph230_lines + 10,
      fterm_bmp_glyph230_lines + 15,
      fterm_bmp_glyph230_lines + 20,
      fterm_bmp_glyph230_lines + 25,
      fterm_bmp_glyph230_lines + 30,
      fterm_bmp_glyph230_lines + 35,
      fterm_bmp_glyph230_lines + 40,
      fterm_bmp_glyph230_lines + 45,
      fterm_bmp_glyph230_lines + 50,
      fterm_bmp_glyph230_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph231_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\xb6\xb6\xb6\0"
"\xb6\0\0\0\0"
"\xb6\0\0\0\0"
"\xb6\0\0\0\0"
"\xb6\0\0\0\0"
"\0\xb6\xb6\xb6\0"
"\0\0\xb6\0\0"
"\xb6\xb6\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph231 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph231_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph231_lines + 0,
      fterm_bmp_glyph231_lines + 5,
      fterm_bmp_glyph231_lines + 10,
      fterm_bmp_glyph231_lines + 15,
      fterm_bmp_glyph231_lines + 20,
      fterm_bmp_glyph231_lines + 25,
      fterm_bmp_glyph231_lines + 30,
      fterm_bmp_glyph231_lines + 35,
      fterm_bmp_glyph231_lines + 40,
      fterm_bmp_glyph231_lines + 45,
      fterm_bmp_glyph231_lines + 50,
      fterm_bmp_glyph231_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph232_lines[] = 
"\0\0\a\a\0"
"\0\a\0\0\0"
"\a\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\a\a\0\0"
"\a\a\0\0\0"
"\a\0\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph232 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph232_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph232_lines + 0,
      fterm_bmp_glyph232_lines + 5,
      fterm_bmp_glyph232_lines + 10,
      fterm_bmp_glyph232_lines + 15,
      fterm_bmp_glyph232_lines + 20,
      fterm_bmp_glyph232_lines + 25,
      fterm_bmp_glyph232_lines + 30,
      fterm_bmp_glyph232_lines + 35,
      fterm_bmp_glyph232_lines + 40,
      fterm_bmp_glyph232_lines + 45,
      fterm_bmp_glyph232_lines + 50,
      fterm_bmp_glyph232_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph233_lines[] = 
"\0\0\0\0\0"
"\0\0..\0"
"\0.\0\0\0"
"\0\0\0\0\0"
"\0..\0\0"
".\0\0.\0"
".\0\0.\0"
"....\0"
".\0\0\0\0"
"\0...\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph233 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph233_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph233_lines + 0,
      fterm_bmp_glyph233_lines + 5,
      fterm_bmp_glyph233_lines + 10,
      fterm_bmp_glyph233_lines + 15,
      fterm_bmp_glyph233_lines + 20,
      fterm_bmp_glyph233_lines + 25,
      fterm_bmp_glyph233_lines + 30,
      fterm_bmp_glyph233_lines + 35,
      fterm_bmp_glyph233_lines + 40,
      fterm_bmp_glyph233_lines + 45,
      fterm_bmp_glyph233_lines + 50,
      fterm_bmp_glyph233_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph234_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\a\0\a\a\0"
"\0\a\0\a\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph234 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph234_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph234_lines + 0,
      fterm_bmp_glyph234_lines + 5,
      fterm_bmp_glyph234_lines + 10,
      fterm_bmp_glyph234_lines + 15,
      fterm_bmp_glyph234_lines + 20,
      fterm_bmp_glyph234_lines + 25,
      fterm_bmp_glyph234_lines + 30,
      fterm_bmp_glyph234_lines + 35,
      fterm_bmp_glyph234_lines + 40,
      fterm_bmp_glyph234_lines + 45,
      fterm_bmp_glyph234_lines + 50,
      fterm_bmp_glyph234_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph235_lines[] = 
"\0\a\0\0\a"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph235 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph235_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph235_lines + 0,
      fterm_bmp_glyph235_lines + 5,
      fterm_bmp_glyph235_lines + 10,
      fterm_bmp_glyph235_lines + 15,
      fterm_bmp_glyph235_lines + 20,
      fterm_bmp_glyph235_lines + 25,
      fterm_bmp_glyph235_lines + 30,
      fterm_bmp_glyph235_lines + 35,
      fterm_bmp_glyph235_lines + 40,
      fterm_bmp_glyph235_lines + 45,
      fterm_bmp_glyph235_lines + 50,
      fterm_bmp_glyph235_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph236_lines[] = 
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\a\0"
"\a\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph236 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph236_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph236_lines + 0,
      fterm_bmp_glyph236_lines + 5,
      fterm_bmp_glyph236_lines + 10,
      fterm_bmp_glyph236_lines + 15,
      fterm_bmp_glyph236_lines + 20,
      fterm_bmp_glyph236_lines + 25,
      fterm_bmp_glyph236_lines + 30,
      fterm_bmp_glyph236_lines + 35,
      fterm_bmp_glyph236_lines + 40,
      fterm_bmp_glyph236_lines + 45,
      fterm_bmp_glyph236_lines + 50,
      fterm_bmp_glyph236_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph237_lines[] = 
"\0\0\0\0\0"
"\0\0..\0"
"\0.\0\0\0"
"\0\0\0\0\0"
"\0..\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0\0.\0\0"
"\0...\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph237 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph237_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph237_lines + 0,
      fterm_bmp_glyph237_lines + 5,
      fterm_bmp_glyph237_lines + 10,
      fterm_bmp_glyph237_lines + 15,
      fterm_bmp_glyph237_lines + 20,
      fterm_bmp_glyph237_lines + 25,
      fterm_bmp_glyph237_lines + 30,
      fterm_bmp_glyph237_lines + 35,
      fterm_bmp_glyph237_lines + 40,
      fterm_bmp_glyph237_lines + 45,
      fterm_bmp_glyph237_lines + 50,
      fterm_bmp_glyph237_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph238_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\a\a\a\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
"\0\0\a\0\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph238 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph238_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph238_lines + 0,
      fterm_bmp_glyph238_lines + 5,
      fterm_bmp_glyph238_lines + 10,
      fterm_bmp_glyph238_lines + 15,
      fterm_bmp_glyph238_lines + 20,
      fterm_bmp_glyph238_lines + 25,
      fterm_bmp_glyph238_lines + 30,
      fterm_bmp_glyph238_lines + 35,
      fterm_bmp_glyph238_lines + 40,
      fterm_bmp_glyph238_lines + 45,
      fterm_bmp_glyph238_lines + 50,
      fterm_bmp_glyph238_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph239_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\a\a\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph239 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph239_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph239_lines + 0,
      fterm_bmp_glyph239_lines + 5,
      fterm_bmp_glyph239_lines + 10,
      fterm_bmp_glyph239_lines + 15,
      fterm_bmp_glyph239_lines + 20,
      fterm_bmp_glyph239_lines + 25,
      fterm_bmp_glyph239_lines + 30,
      fterm_bmp_glyph239_lines + 35,
      fterm_bmp_glyph239_lines + 40,
      fterm_bmp_glyph239_lines + 45,
      fterm_bmp_glyph239_lines + 50,
      fterm_bmp_glyph239_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph240_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph240 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph240_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph240_lines + 0,
      fterm_bmp_glyph240_lines + 5,
      fterm_bmp_glyph240_lines + 10,
      fterm_bmp_glyph240_lines + 15,
      fterm_bmp_glyph240_lines + 20,
      fterm_bmp_glyph240_lines + 25,
      fterm_bmp_glyph240_lines + 30,
      fterm_bmp_glyph240_lines + 35,
      fterm_bmp_glyph240_lines + 40,
      fterm_bmp_glyph240_lines + 45,
      fterm_bmp_glyph240_lines + 50,
      fterm_bmp_glyph240_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph241_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"....\0"
"\0\0\0\0\0"
".\0.\0\0"
"..\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph241 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph241_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph241_lines + 0,
      fterm_bmp_glyph241_lines + 5,
      fterm_bmp_glyph241_lines + 10,
      fterm_bmp_glyph241_lines + 15,
      fterm_bmp_glyph241_lines + 20,
      fterm_bmp_glyph241_lines + 25,
      fterm_bmp_glyph241_lines + 30,
      fterm_bmp_glyph241_lines + 35,
      fterm_bmp_glyph241_lines + 40,
      fterm_bmp_glyph241_lines + 45,
      fterm_bmp_glyph241_lines + 50,
      fterm_bmp_glyph241_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph242_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\a\0\0\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph242 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph242_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph242_lines + 0,
      fterm_bmp_glyph242_lines + 5,
      fterm_bmp_glyph242_lines + 10,
      fterm_bmp_glyph242_lines + 15,
      fterm_bmp_glyph242_lines + 20,
      fterm_bmp_glyph242_lines + 25,
      fterm_bmp_glyph242_lines + 30,
      fterm_bmp_glyph242_lines + 35,
      fterm_bmp_glyph242_lines + 40,
      fterm_bmp_glyph242_lines + 45,
      fterm_bmp_glyph242_lines + 50,
      fterm_bmp_glyph242_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph243_lines[] = 
"\0\0\0\0\0"
"\0\0..\0"
"\0.\0\0\0"
"\0\0\0\0\0"
"\0..\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0..\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph243 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph243_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph243_lines + 0,
      fterm_bmp_glyph243_lines + 5,
      fterm_bmp_glyph243_lines + 10,
      fterm_bmp_glyph243_lines + 15,
      fterm_bmp_glyph243_lines + 20,
      fterm_bmp_glyph243_lines + 25,
      fterm_bmp_glyph243_lines + 30,
      fterm_bmp_glyph243_lines + 35,
      fterm_bmp_glyph243_lines + 40,
      fterm_bmp_glyph243_lines + 45,
      fterm_bmp_glyph243_lines + 50,
      fterm_bmp_glyph243_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph244_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph244 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph244_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph244_lines + 0,
      fterm_bmp_glyph244_lines + 5,
      fterm_bmp_glyph244_lines + 10,
      fterm_bmp_glyph244_lines + 15,
      fterm_bmp_glyph244_lines + 20,
      fterm_bmp_glyph244_lines + 25,
      fterm_bmp_glyph244_lines + 30,
      fterm_bmp_glyph244_lines + 35,
      fterm_bmp_glyph244_lines + 40,
      fterm_bmp_glyph244_lines + 45,
      fterm_bmp_glyph244_lines + 50,
      fterm_bmp_glyph244_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph245_lines[] = 
"\0\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\0\0"
"\0\a\a\0\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph245 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph245_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph245_lines + 0,
      fterm_bmp_glyph245_lines + 5,
      fterm_bmp_glyph245_lines + 10,
      fterm_bmp_glyph245_lines + 15,
      fterm_bmp_glyph245_lines + 20,
      fterm_bmp_glyph245_lines + 25,
      fterm_bmp_glyph245_lines + 30,
      fterm_bmp_glyph245_lines + 35,
      fterm_bmp_glyph245_lines + 40,
      fterm_bmp_glyph245_lines + 45,
      fterm_bmp_glyph245_lines + 50,
      fterm_bmp_glyph245_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph246_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\a\a\a\a\a"
"\0\0\0\0\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph246 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph246_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph246_lines + 0,
      fterm_bmp_glyph246_lines + 5,
      fterm_bmp_glyph246_lines + 10,
      fterm_bmp_glyph246_lines + 15,
      fterm_bmp_glyph246_lines + 20,
      fterm_bmp_glyph246_lines + 25,
      fterm_bmp_glyph246_lines + 30,
      fterm_bmp_glyph246_lines + 35,
      fterm_bmp_glyph246_lines + 40,
      fterm_bmp_glyph246_lines + 45,
      fterm_bmp_glyph246_lines + 50,
      fterm_bmp_glyph246_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph247_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\0\0\0"
"\0\0\a\0\0"
"\0\a\a\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph247 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph247_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph247_lines + 0,
      fterm_bmp_glyph247_lines + 5,
      fterm_bmp_glyph247_lines + 10,
      fterm_bmp_glyph247_lines + 15,
      fterm_bmp_glyph247_lines + 20,
      fterm_bmp_glyph247_lines + 25,
      fterm_bmp_glyph247_lines + 30,
      fterm_bmp_glyph247_lines + 35,
      fterm_bmp_glyph247_lines + 40,
      fterm_bmp_glyph247_lines + 45,
      fterm_bmp_glyph247_lines + 50,
      fterm_bmp_glyph247_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph248_lines[] = 
"\0\a\a\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph248 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph248_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph248_lines + 0,
      fterm_bmp_glyph248_lines + 5,
      fterm_bmp_glyph248_lines + 10,
      fterm_bmp_glyph248_lines + 15,
      fterm_bmp_glyph248_lines + 20,
      fterm_bmp_glyph248_lines + 25,
      fterm_bmp_glyph248_lines + 30,
      fterm_bmp_glyph248_lines + 35,
      fterm_bmp_glyph248_lines + 40,
      fterm_bmp_glyph248_lines + 45,
      fterm_bmp_glyph248_lines + 50,
      fterm_bmp_glyph248_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph249_lines[] = 
"\0\a\0\a\0"
"\0\a\0\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph249 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph249_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph249_lines + 0,
      fterm_bmp_glyph249_lines + 5,
      fterm_bmp_glyph249_lines + 10,
      fterm_bmp_glyph249_lines + 15,
      fterm_bmp_glyph249_lines + 20,
      fterm_bmp_glyph249_lines + 25,
      fterm_bmp_glyph249_lines + 30,
      fterm_bmp_glyph249_lines + 35,
      fterm_bmp_glyph249_lines + 40,
      fterm_bmp_glyph249_lines + 45,
      fterm_bmp_glyph249_lines + 50,
      fterm_bmp_glyph249_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph250_lines[] = 
"\0\0\0\0\0"
"\0\0..\0"
"\0.\0\0\0"
"\0\0\0\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0...\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph250 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph250_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph250_lines + 0,
      fterm_bmp_glyph250_lines + 5,
      fterm_bmp_glyph250_lines + 10,
      fterm_bmp_glyph250_lines + 15,
      fterm_bmp_glyph250_lines + 20,
      fterm_bmp_glyph250_lines + 25,
      fterm_bmp_glyph250_lines + 30,
      fterm_bmp_glyph250_lines + 35,
      fterm_bmp_glyph250_lines + 40,
      fterm_bmp_glyph250_lines + 45,
      fterm_bmp_glyph250_lines + 50,
      fterm_bmp_glyph250_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph251_lines[] = 
"\0\0\0\0\0"
"\0\a\0\0\a"
"\a\0\0\a\0"
"\0\0\0\0\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\a\0\0\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph251 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph251_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph251_lines + 0,
      fterm_bmp_glyph251_lines + 5,
      fterm_bmp_glyph251_lines + 10,
      fterm_bmp_glyph251_lines + 15,
      fterm_bmp_glyph251_lines + 20,
      fterm_bmp_glyph251_lines + 25,
      fterm_bmp_glyph251_lines + 30,
      fterm_bmp_glyph251_lines + 35,
      fterm_bmp_glyph251_lines + 40,
      fterm_bmp_glyph251_lines + 45,
      fterm_bmp_glyph251_lines + 50,
      fterm_bmp_glyph251_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph252_lines[] = 
"\0\0\0\0\0"
"\0.\0.\0"
"\0.\0.\0"
"\0\0\0\0\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
".\0\0.\0"
"\0...\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph252 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph252_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph252_lines + 0,
      fterm_bmp_glyph252_lines + 5,
      fterm_bmp_glyph252_lines + 10,
      fterm_bmp_glyph252_lines + 15,
      fterm_bmp_glyph252_lines + 20,
      fterm_bmp_glyph252_lines + 25,
      fterm_bmp_glyph252_lines + 30,
      fterm_bmp_glyph252_lines + 35,
      fterm_bmp_glyph252_lines + 40,
      fterm_bmp_glyph252_lines + 45,
      fterm_bmp_glyph252_lines + 50,
      fterm_bmp_glyph252_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph253_lines[] = 
"\0\0\0\0\0"
"\0\a\0\a\0"
"\0\0\a\0\0"
"\0\0\0\0\0"
"\a\0\a\a\0"
"\0\a\0\a\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\a\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph253 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph253_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph253_lines + 0,
      fterm_bmp_glyph253_lines + 5,
      fterm_bmp_glyph253_lines + 10,
      fterm_bmp_glyph253_lines + 15,
      fterm_bmp_glyph253_lines + 20,
      fterm_bmp_glyph253_lines + 25,
      fterm_bmp_glyph253_lines + 30,
      fterm_bmp_glyph253_lines + 35,
      fterm_bmp_glyph253_lines + 40,
      fterm_bmp_glyph253_lines + 45,
      fterm_bmp_glyph253_lines + 50,
      fterm_bmp_glyph253_lines + 55,
      0 }
};

static unsigned char fterm_bmp_glyph254_lines[] = 
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\a\a\a\0"
"\0\a\a\a\0"
"\0\a\a\a\0"
"\0\a\a\a\0"
"\0\a\a\a\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
"\0\0\0\0\0"
;

static struct { int w, h; int clip; int cl, cr, ct, cb;
                GFX_VTABLE *vtable; void *write_bank; void *read_bank;
                void *dat; unsigned long id; void *extra;
                int x_ofs; int y_ofs; int seg; unsigned char *line[13]; } fterm_bmp_glyph254 = {
    5, 12, /* width, height */
    0, 0, 0, 0, 0, /* clip */
    (GFX_VTABLE *)8, /* bpp */
    0, 0, /* write_bank, read_bank */
    fterm_bmp_glyph254_lines, /* data */
    0, 0, 0, 0, 0,
    { /* line[] array */
      fterm_bmp_glyph254_lines + 0,
      fterm_bmp_glyph254_lines + 5,
      fterm_bmp_glyph254_lines + 10,
      fterm_bmp_glyph254_lines + 15,
      fterm_bmp_glyph254_lines + 20,
      fterm_bmp_glyph254_lines + 25,
      fterm_bmp_glyph254_lines + 30,
      fterm_bmp_glyph254_lines + 35,
      fterm_bmp_glyph254_lines + 40,
      fterm_bmp_glyph254_lines + 45,
      fterm_bmp_glyph254_lines + 50,
      fterm_bmp_glyph254_lines + 55,
      0 }
};

static BITMAP* fterm_bmp_range0_glyphs[] = {
    (BITMAP *)&fterm_bmp_glyph32,
    (BITMAP *)&fterm_bmp_glyph33,
    (BITMAP *)&fterm_bmp_glyph34,
    (BITMAP *)&fterm_bmp_glyph35,
    (BITMAP *)&fterm_bmp_glyph36,
    (BITMAP *)&fterm_bmp_glyph37,
    (BITMAP *)&fterm_bmp_glyph38,
    (BITMAP *)&fterm_bmp_glyph39,
    (BITMAP *)&fterm_bmp_glyph40,
    (BITMAP *)&fterm_bmp_glyph41,
    (BITMAP *)&fterm_bmp_glyph42,
    (BITMAP *)&fterm_bmp_glyph43,
    (BITMAP *)&fterm_bmp_glyph44,
    (BITMAP *)&fterm_bmp_glyph45,
    (BITMAP *)&fterm_bmp_glyph46,
    (BITMAP *)&fterm_bmp_glyph47,
    (BITMAP *)&fterm_bmp_glyph48,
    (BITMAP *)&fterm_bmp_glyph49,
    (BITMAP *)&fterm_bmp_glyph50,
    (BITMAP *)&fterm_bmp_glyph51,
    (BITMAP *)&fterm_bmp_glyph52,
    (BITMAP *)&fterm_bmp_glyph53,
    (BITMAP *)&fterm_bmp_glyph54,
    (BITMAP *)&fterm_bmp_glyph55,
    (BITMAP *)&fterm_bmp_glyph56,
    (BITMAP *)&fterm_bmp_glyph57,
    (BITMAP *)&fterm_bmp_glyph58,
    (BITMAP *)&fterm_bmp_glyph59,
    (BITMAP *)&fterm_bmp_glyph60,
    (BITMAP *)&fterm_bmp_glyph61,
    (BITMAP *)&fterm_bmp_glyph62,
    (BITMAP *)&fterm_bmp_glyph63,
    (BITMAP *)&fterm_bmp_glyph64,
    (BITMAP *)&fterm_bmp_glyph65,
    (BITMAP *)&fterm_bmp_glyph66,
    (BITMAP *)&fterm_bmp_glyph67,
    (BITMAP *)&fterm_bmp_glyph68,
    (BITMAP *)&fterm_bmp_glyph69,
    (BITMAP *)&fterm_bmp_glyph70,
    (BITMAP *)&fterm_bmp_glyph71,
    (BITMAP *)&fterm_bmp_glyph72,
    (BITMAP *)&fterm_bmp_glyph73,
    (BITMAP *)&fterm_bmp_glyph74,
    (BITMAP *)&fterm_bmp_glyph75,
    (BITMAP *)&fterm_bmp_glyph76,
    (BITMAP *)&fterm_bmp_glyph77,
    (BITMAP *)&fterm_bmp_glyph78,
    (BITMAP *)&fterm_bmp_glyph79,
    (BITMAP *)&fterm_bmp_glyph80,
    (BITMAP *)&fterm_bmp_glyph81,
    (BITMAP *)&fterm_bmp_glyph82,
    (BITMAP *)&fterm_bmp_glyph83,
    (BITMAP *)&fterm_bmp_glyph84,
    (BITMAP *)&fterm_bmp_glyph85,
    (BITMAP *)&fterm_bmp_glyph86,
    (BITMAP *)&fterm_bmp_glyph87,
    (BITMAP *)&fterm_bmp_glyph88,
    (BITMAP *)&fterm_bmp_glyph89,
    (BITMAP *)&fterm_bmp_glyph90,
    (BITMAP *)&fterm_bmp_glyph91,
    (BITMAP *)&fterm_bmp_glyph92,
    (BITMAP *)&fterm_bmp_glyph93,
    (BITMAP *)&fterm_bmp_glyph94,
    (BITMAP *)&fterm_bmp_glyph95,
    (BITMAP *)&fterm_bmp_glyph96,
    (BITMAP *)&fterm_bmp_glyph97,
    (BITMAP *)&fterm_bmp_glyph98,
    (BITMAP *)&fterm_bmp_glyph99,
    (BITMAP *)&fterm_bmp_glyph100,
    (BITMAP *)&fterm_bmp_glyph101,
    (BITMAP *)&fterm_bmp_glyph102,
    (BITMAP *)&fterm_bmp_glyph103,
    (BITMAP *)&fterm_bmp_glyph104,
    (BITMAP *)&fterm_bmp_glyph105,
    (BITMAP *)&fterm_bmp_glyph106,
    (BITMAP *)&fterm_bmp_glyph107,
    (BITMAP *)&fterm_bmp_glyph108,
    (BITMAP *)&fterm_bmp_glyph109,
    (BITMAP *)&fterm_bmp_glyph110,
    (BITMAP *)&fterm_bmp_glyph111,
    (BITMAP *)&fterm_bmp_glyph112,
    (BITMAP *)&fterm_bmp_glyph113,
    (BITMAP *)&fterm_bmp_glyph114,
    (BITMAP *)&fterm_bmp_glyph115,
    (BITMAP *)&fterm_bmp_glyph116,
    (BITMAP *)&fterm_bmp_glyph117,
    (BITMAP *)&fterm_bmp_glyph118,
    (BITMAP *)&fterm_bmp_glyph119,
    (BITMAP *)&fterm_bmp_glyph120,
    (BITMAP *)&fterm_bmp_glyph121,
    (BITMAP *)&fterm_bmp_glyph122,
    (BITMAP *)&fterm_bmp_glyph123,
    (BITMAP *)&fterm_bmp_glyph124,
    (BITMAP *)&fterm_bmp_glyph125,
    (BITMAP *)&fterm_bmp_glyph126,
    (BITMAP *)&fterm_bmp_glyph127,
    (BITMAP *)&fterm_bmp_glyph128,
    (BITMAP *)&fterm_bmp_glyph129,
    (BITMAP *)&fterm_bmp_glyph130,
    (BITMAP *)&fterm_bmp_glyph131,
    (BITMAP *)&fterm_bmp_glyph132,
    (BITMAP *)&fterm_bmp_glyph133,
    (BITMAP *)&fterm_bmp_glyph134,
    (BITMAP *)&fterm_bmp_glyph135,
    (BITMAP *)&fterm_bmp_glyph136,
    (BITMAP *)&fterm_bmp_glyph137,
    (BITMAP *)&fterm_bmp_glyph138,
    (BITMAP *)&fterm_bmp_glyph139,
    (BITMAP *)&fterm_bmp_glyph140,
    (BITMAP *)&fterm_bmp_glyph141,
    (BITMAP *)&fterm_bmp_glyph142,
    (BITMAP *)&fterm_bmp_glyph143,
    (BITMAP *)&fterm_bmp_glyph144,
    (BITMAP *)&fterm_bmp_glyph145,
    (BITMAP *)&fterm_bmp_glyph146,
    (BITMAP *)&fterm_bmp_glyph147,
    (BITMAP *)&fterm_bmp_glyph148,
    (BITMAP *)&fterm_bmp_glyph149,
    (BITMAP *)&fterm_bmp_glyph150,
    (BITMAP *)&fterm_bmp_glyph151,
    (BITMAP *)&fterm_bmp_glyph152,
    (BITMAP *)&fterm_bmp_glyph153,
    (BITMAP *)&fterm_bmp_glyph154,
    (BITMAP *)&fterm_bmp_glyph155,
    (BITMAP *)&fterm_bmp_glyph156,
    (BITMAP *)&fterm_bmp_glyph157,
    (BITMAP *)&fterm_bmp_glyph158,
    (BITMAP *)&fterm_bmp_glyph159,
    (BITMAP *)&fterm_bmp_glyph160,
    (BITMAP *)&fterm_bmp_glyph161,
    (BITMAP *)&fterm_bmp_glyph162,
    (BITMAP *)&fterm_bmp_glyph163,
    (BITMAP *)&fterm_bmp_glyph164,
    (BITMAP *)&fterm_bmp_glyph165,
    (BITMAP *)&fterm_bmp_glyph166,
    (BITMAP *)&fterm_bmp_glyph167,
    (BITMAP *)&fterm_bmp_glyph168,
    (BITMAP *)&fterm_bmp_glyph169,
    (BITMAP *)&fterm_bmp_glyph170,
    (BITMAP *)&fterm_bmp_glyph171,
    (BITMAP *)&fterm_bmp_glyph172,
    (BITMAP *)&fterm_bmp_glyph173,
    (BITMAP *)&fterm_bmp_glyph174,
    (BITMAP *)&fterm_bmp_glyph175,
    (BITMAP *)&fterm_bmp_glyph176,
    (BITMAP *)&fterm_bmp_glyph177,
    (BITMAP *)&fterm_bmp_glyph178,
    (BITMAP *)&fterm_bmp_glyph179,
    (BITMAP *)&fterm_bmp_glyph180,
    (BITMAP *)&fterm_bmp_glyph181,
    (BITMAP *)&fterm_bmp_glyph182,
    (BITMAP *)&fterm_bmp_glyph183,
    (BITMAP *)&fterm_bmp_glyph184,
    (BITMAP *)&fterm_bmp_glyph185,
    (BITMAP *)&fterm_bmp_glyph186,
    (BITMAP *)&fterm_bmp_glyph187,
    (BITMAP *)&fterm_bmp_glyph188,
    (BITMAP *)&fterm_bmp_glyph189,
    (BITMAP *)&fterm_bmp_glyph190,
    (BITMAP *)&fterm_bmp_glyph191,
    (BITMAP *)&fterm_bmp_glyph192,
    (BITMAP *)&fterm_bmp_glyph193,
    (BITMAP *)&fterm_bmp_glyph194,
    (BITMAP *)&fterm_bmp_glyph195,
    (BITMAP *)&fterm_bmp_glyph196,
    (BITMAP *)&fterm_bmp_glyph197,
    (BITMAP *)&fterm_bmp_glyph198,
    (BITMAP *)&fterm_bmp_glyph199,
    (BITMAP *)&fterm_bmp_glyph200,
    (BITMAP *)&fterm_bmp_glyph201,
    (BITMAP *)&fterm_bmp_glyph202,
    (BITMAP *)&fterm_bmp_glyph203,
    (BITMAP *)&fterm_bmp_glyph204,
    (BITMAP *)&fterm_bmp_glyph205,
    (BITMAP *)&fterm_bmp_glyph206,
    (BITMAP *)&fterm_bmp_glyph207,
    (BITMAP *)&fterm_bmp_glyph208,
    (BITMAP *)&fterm_bmp_glyph209,
    (BITMAP *)&fterm_bmp_glyph210,
    (BITMAP *)&fterm_bmp_glyph211,
    (BITMAP *)&fterm_bmp_glyph212,
    (BITMAP *)&fterm_bmp_glyph213,
    (BITMAP *)&fterm_bmp_glyph214,
    (BITMAP *)&fterm_bmp_glyph215,
    (BITMAP *)&fterm_bmp_glyph216,
    (BITMAP *)&fterm_bmp_glyph217,
    (BITMAP *)&fterm_bmp_glyph218,
    (BITMAP *)&fterm_bmp_glyph219,
    (BITMAP *)&fterm_bmp_glyph220,
    (BITMAP *)&fterm_bmp_glyph221,
    (BITMAP *)&fterm_bmp_glyph222,
    (BITMAP *)&fterm_bmp_glyph223,
    (BITMAP *)&fterm_bmp_glyph224,
    (BITMAP *)&fterm_bmp_glyph225,
    (BITMAP *)&fterm_bmp_glyph226,
    (BITMAP *)&fterm_bmp_glyph227,
    (BITMAP *)&fterm_bmp_glyph228,
    (BITMAP *)&fterm_bmp_glyph229,
    (BITMAP *)&fterm_bmp_glyph230,
    (BITMAP *)&fterm_bmp_glyph231,
    (BITMAP *)&fterm_bmp_glyph232,
    (BITMAP *)&fterm_bmp_glyph233,
    (BITMAP *)&fterm_bmp_glyph234,
    (BITMAP *)&fterm_bmp_glyph235,
    (BITMAP *)&fterm_bmp_glyph236,
    (BITMAP *)&fterm_bmp_glyph237,
    (BITMAP *)&fterm_bmp_glyph238,
    (BITMAP *)&fterm_bmp_glyph239,
    (BITMAP *)&fterm_bmp_glyph240,
    (BITMAP *)&fterm_bmp_glyph241,
    (BITMAP *)&fterm_bmp_glyph242,
    (BITMAP *)&fterm_bmp_glyph243,
    (BITMAP *)&fterm_bmp_glyph244,
    (BITMAP *)&fterm_bmp_glyph245,
    (BITMAP *)&fterm_bmp_glyph246,
    (BITMAP *)&fterm_bmp_glyph247,
    (BITMAP *)&fterm_bmp_glyph248,
    (BITMAP *)&fterm_bmp_glyph249,
    (BITMAP *)&fterm_bmp_glyph250,
    (BITMAP *)&fterm_bmp_glyph251,
    (BITMAP *)&fterm_bmp_glyph252,
    (BITMAP *)&fterm_bmp_glyph253,
    (BITMAP *)&fterm_bmp_glyph254,
    0
};

static FONT_COLOR_DATA fterm_bmp_range0 = {
    32, 255, /* begin, end */
    fterm_bmp_range0_glyphs,
    0
};

static FONT fterm_bmp = {
    &fterm_bmp_range0,
    12, /* height */
    (FONT_VTABLE *)1 /* color flag */
};



DATAFILE databmpfnts[] = {
    { &fterm_bmp, DAT_ID('F', 'O', 'N', 'T'), 14237, fterm_bmp_prop },
    { 0, DAT_END, 0, 0 }
};



#ifdef ALLEGRO_USE_CONSTRUCTOR
CONSTRUCTOR_FUNCTION(static void _construct_me(void));
static void _construct_me(void)
{
    _construct_datafile(databmpfnts);
}
#endif



/* end of bmpfnts.c */



