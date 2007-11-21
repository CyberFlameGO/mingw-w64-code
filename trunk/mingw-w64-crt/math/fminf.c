/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

float
fminf (float _x, float _y)
{
  return ((islessequal(_x, _y) || _isnan (_y)) ? _x : _y );
}
