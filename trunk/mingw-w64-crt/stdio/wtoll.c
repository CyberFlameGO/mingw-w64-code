/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#define __CRT__NO_INLINE
#include <stdlib.h>

long long wtoll(const wchar_t * _w)
 	{ return _wtoi64 (_w); }
