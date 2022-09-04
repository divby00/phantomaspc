/*
	main.c
	Author: Traperic <traperic@gmail.com>
*/

#include "config.h"

#ifdef GP2X
#include <sys/mman.h>
#endif

#include "program.h"
#include "game.h"
#include "trans.h"
#include "intro.h"
#include "menu2.h"

#ifdef GP2X

#include <allegro/platform/aintlnx.h>

#define MESGDSTCTRL     0x0000
#define MESG_BSTBPP     0x60
#define MESG_DSTBPP_16  (1<<5)
#define MESG_DSTENB     (1<<6)
#define MESGDSTADDR     0x0004
#define MESGSRCCTRL     0x000c
#define MESG_INVIDEO    (1<<8)
#define MESGPATCTRL     0x0020
#define MESGSIZE        0x002c
#define MESG_HEIGHT     16
#define MESGCTRL        0x0030
#define MESG_XDIR_POS   (1<<8)
#define MESG_YDIR_POS   (1<<9)
#define MESG_FFCLR      (1<<10)
#define MESGSTATUS      0x0034
#define MESG_BUSY       (1<<0)

#define mmsp2_blit_putl(addr,value) (*(unsigned long volatile *)(mmsp2_blit_base+(addr)) = (value))
#define mmsp2_blit_getl(addr)       (*(unsigned long volatile *)(mmsp2_blit_base+(addr)))
#endif

#ifdef GP2X
int mmuhack(void);
void mmuunhack(void);
#endif

int main(int argc, char **argv) {
#ifdef GP2X
    unsigned long gp2x_dev;
    static volatile unsigned long *gp2x_memregl;
    volatile unsigned short *gp2x_memregs;
    static struct MAPPED_MEMORY mmsp2_blit;
    int mmsp2_blit_base;

    gp2x_dev = open("/dev/mem", O_RDWR);
    gp2x_memregl = (unsigned long  *)mmap(0, 0x10000, PROT_READ|PROT_WRITE, MAP_SHARED, gp2x_dev, 0xc0000000);
    gp2x_memregs = (unsigned short *)gp2x_memregl;
    gp2x_memregs[0x90a >> 1] = 0xffff;
    gp2x_memregs[0x904 >> 1] |= 1<<10;
    mmsp2_blit.base  = 0xe0020000;
    mmsp2_blit.size  = 0x100;
    mmsp2_blit.perms = PROT_READ|PROT_WRITE;
    mmsp2_blit.data  = mmap(0, 0x100, PROT_READ|PROT_WRITE, MAP_SHARED, gp2x_dev, 0xe0020000);
    if (mmsp2_blit.data == MAP_FAILED) return 13;
    mmsp2_blit_base = (int *)mmsp2_blit.data;
    mmsp2_blit_putl (MESGDSTCTRL, MESG_DSTBPP_16 | MESG_DSTENB);
    mmsp2_blit_putl (MESGDSTADDR, 0x3101000);
    mmsp2_blit_putl (MESGSRCCTRL, MESG_INVIDEO);
    mmsp2_blit_putl (MESGPATCTRL, 0);
    mmsp2_blit_putl (MESGSIZE, (1 << MESG_HEIGHT) | 8);
    mmsp2_blit_putl (MESGCTRL, (MESG_XDIR_POS) | (MESG_YDIR_POS) | 0xaa | MESG_FFCLR);
    mmsp2_blit_putl (MESGSTATUS, 1);
    while (mmsp2_blit_getl(MESGSTATUS) & MESG_BUSY);
    munmap((void *)&mmsp2_blit_base, 0x100);
#endif
    PROGRAM *p = ph_init_program(argc, argv);
    ph_do_intro(p);
    ph_do_menu1(p);
    ph_start_game(p);
    return 0;
}


END_OF_MAIN()

void ph_exit_message(void) {
    char msg[512];
    sprintf(msg, "%s", _("\n\nPhantomas PC 1.3 by Traperic Software.\n"));
    fprintf(stdout, "%s", msg);
	sprintf(msg, "%s", _("I hope you enjoy this game!\n\n"));
    fprintf(stdout, "%s", msg);
}
