#include <windows.h>
#include <malloc.h>
#include <errno.h>

HMODULE __mingw_get_msvcrt_handle(void);
int __cdecl _vcprintf (const char * __restrict__ f,va_list argp);
static int __cdecl _int_vcprintf_s (const char *, va_list);
static int __cdecl _stub (const char *, va_list);

int __cdecl (*__MINGW_IMP_SYMBOL(_vcprintf_s))(const char *, va_list) = 
 _stub;

static int __cdecl
_stub (const char *s, va_list argp)
{
  int __cdecl (*f)(const char *, va_list) = __MINGW_IMP_SYMBOL(_vcprintf_s);

  if (f == _stub)
    {
	f = (int __cdecl (*)(const char *, va_list))
	    GetProcAddress (__mingw_get_msvcrt_handle (), "_vcprintf_s");
	if (!f)
	  f = _int_vcprintf_s;
	__MINGW_IMP_SYMBOL(_vcprintf_s) = f;
    }
  return (*f)(s, argp);
}

static int __cdecl
_int_vcprintf_s (const char *s, va_list argp)
{
  return _vcprintf (s, argp);
}
