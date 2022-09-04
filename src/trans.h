#ifndef __TRANS_H
#define __TRANS_H

#include "config.h"
#include <allegro.h>

#if HAVE_INTL
#include <libintl.h>
#include <locale.h>
#endif

#ifdef LINUX
#if HAVE_INTL
#define t_(String) (char *)uconvert(gettext(String),get_uformat(),NULL,U_UTF8,0)
#define _(String) uconvert(gettext(String),get_uformat(),NULL,U_UTF8,0)
#else
#define t_(String) (char *)uconvert(String,get_uformat(),NULL,U_UTF8,0)
#define _(String) (char *)uconvert(String,get_uformat(),NULL,U_UTF8,0)
#endif
#else
#if HAVE_INTL
#define t_(String) uconvert(gettext(String),get_uformat(),NULL,U_UTF8,0)
#define _(String) uconvert(gettext(String),get_uformat(),NULL,U_ASCII,0)
#else
#define t_(String) uconvert(String,get_uformat(),NULL,U_UTF8,0)
#define _(String) uconvert(String,get_uformat(),NULL,U_UTF8,0)
#endif
#endif

#define N_(String) (String)
#endif
