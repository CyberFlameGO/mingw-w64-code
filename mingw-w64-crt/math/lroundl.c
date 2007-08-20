/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <limits.h>
#include <errno.h>

long
lroundl (long double x)
{
  /* Add +/- 0.5, then round towards zero.  */
  long double tmp = truncl (x + (x >= 0.0L ?  0.5L : -0.5L));
  if (!isfinite (tmp) 
      || tmp > (long double)LONG_MAX
      || tmp < (long double)LONG_MIN)
    { 
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0L ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}
