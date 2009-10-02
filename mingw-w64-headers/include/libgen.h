/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _LIBGEN_H_
#define _LIBGEN_H_

#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

 char * __cdecl __MINGW_NOTHROW char *basename (char *);
 char * __cdecl __MINGW_NOTHROW char *dirname (char *);

#ifdef __cplusplus
}
#endif

#endif

