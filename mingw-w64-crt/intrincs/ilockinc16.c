#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

SHORT InterlockedIncrement16(SHORT volatile *Addend)
{
  SHORT ret, value = 1;
  __asm__ ("lock\n\t"
	       "xaddw %0,(%1)"
	       : "=r" (ret)
	       : "r" (Addend), "0" (value)
	       : "memory");
  return ret + 1;
}
