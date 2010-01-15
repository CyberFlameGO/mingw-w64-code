/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
   Contributed by Danny Smith
   2005-01-04
*/

#include <math.h>
#include <complex.h>

/* csinh (x + I * y) = sinh (x) * cos (y)
    + I * (cosh (x) * sin (y)) */ 


long double complex csinhl (long double complex Z)
{
  long double complex Res;
  __real__ Res = sinhl (__real__ Z) * cosl (__imag__ Z);
  __imag__ Res = coshl (__real__ Z) * sinl (__imag__ Z);
  return Res;
}
