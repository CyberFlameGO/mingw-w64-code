#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

PVOID InterlockedExchangePointer(PVOID volatile *Target,PVOID Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

