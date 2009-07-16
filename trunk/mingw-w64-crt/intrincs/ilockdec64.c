#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

LONG64 InterlockedDecrement64(LONG64 volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; subq $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

