/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <limits.h>
#include <errno.h>

long long
llround (double x)
{
  double res;

  if (x >= 0.0)
    {
	  res = ceil (x);
	  if (res - x > 0.5)
	    res -= 1.0;
     }
   else
     {
       res = ceil (-x);
       if (res + x > 0.5)
	     res -= 1.0;
       res = -res;
     }
   if (!isfinite (res) 
       || res > (double) LONG_LONG_MAX
       || res < (double) LONG_LONG_MIN)
     {
       errno = ERANGE;
       /* Undefined behaviour, so we could return anything. */
       /* return res > 0.0 ? LONG_LONG_MAX : LONG_LONG_MIN; */
     }
   return (long long) res;
}

