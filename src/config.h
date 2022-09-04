/*
	Description: Usa esto para controlar la compilacion del juego.
	Author: Traperic <traperic@gmail.com>
*/

#ifndef __CONFIG_H
#define __CONFIG_H
	#define HAVE_ALOGG_H 1
	#define PHANTOMAS_PACKAGE   "phantomaspc"
	#define LOCALE_DIR          "data/locale"

	#ifndef GP2X
		#define HAVE_INTL       1
	#else
		#define HAVE_INTL       0
		#define GMSG(message)       allegro_message(message);
	#endif
#endif
