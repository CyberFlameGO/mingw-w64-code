#ifdef CRTDLL
#undef CRTDLL
#define _DLL

#include <oscalls.h>
#include <internal.h>
#include <stdlib.h>
#include <windows.h>
#define _DECL_DLLMAIN
#include <process.h>
#include <crtdbg.h>

#ifndef _CRTIMP
#ifdef CRTDLL
#define _CRTIMP __declspec(dllexport)
#else
#ifdef _DLL
#define _CRTIMP __declspec(dllimport)
#else
#define _CRTIMP
#endif
#endif
#endif
#include <sect_attribs.h>
#include <locale.h>

extern void __cdecl _initterm(_PVFV *,_PVFV *);
extern void __main ();
extern void _pei386_runtime_relocator (void);
extern _CRTALLOC(".CRT$XIA") _PIFV __xi_a[];
extern _CRTALLOC(".CRT$XIZ") _PIFV __xi_z[];
extern _CRTALLOC(".CRT$XCA") _PVFV __xc_a[];
extern _CRTALLOC(".CRT$XCZ") _PVFV __xc_z[];

extern const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback;

static int __proc_attached = 0;

extern _PVFV *__onexitbegin;
extern _PVFV *__onexitend;

extern int mingw_app_type;

extern BOOL WINAPI DllMain (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved);

extern BOOL WINAPI DllEntryPoint (HANDLE, DWORD, LPVOID);

static int pre_c_init (void);

_CRTALLOC(".CRT$XIAA") _PIFV pcinit = pre_c_init;

static int
pre_c_init (void)
{
  _PVFV *onexitbegin;

  onexitbegin = (_PVFV *) malloc (32 * sizeof (_PVFV));
  __onexitend = __onexitbegin = (_PVFV *) _encode_pointer (onexitbegin);

  if (onexitbegin == NULL)
    return 1;
  *onexitbegin = (_PVFV) NULL;
  return 0;
}

BOOL WINAPI _CRT_INIT (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  if (dwReason == DLL_PROCESS_DETACH)
    {
      if (__proc_attached > 0)
	__proc_attached--;
      else
	return FALSE;
    }
  if (dwReason == DLL_PROCESS_ATTACH)
    {
      void *lock_free = NULL;
      void *fiberid = ((PNT_TIB)NtCurrentTeb ())->StackBase;
      int nested = FALSE;
      
      while ((lock_free = InterlockedCompareExchangePointer ((volatile PVOID *) &__native_startup_lock,
							     fiberid, 0)) != 0)
	{
	  if (lock_free == fiberid)
	    {
	      nested = TRUE;
	      break;
	    }
	  Sleep(1000);
	}
      if (__native_startup_state != __uninitialized)
	{
	  _amsg_exit(31);
	}
      else
	{
	  __native_startup_state = __initializing;
	  
	  _initterm ((_PVFV *) (void *) __xi_a, (_PVFV *) (void *) __xi_z);
	  _initterm (__xc_a,__xc_z);
	  __native_startup_state = __initialized;
	}
      if (! nested)
	{
	  InterlockedExchangePointer ((volatile PVOID *) &__native_startup_lock, 0);
	}
      if (__dyn_tls_init_callback != NULL &&
	  _IsNonwritableInCurrentImage ((PBYTE) &__dyn_tls_init_callback))
	{
	  __dyn_tls_init_callback (hDllHandle, DLL_THREAD_ATTACH, lpreserved);
	}
      _CrtSetCheckCount (TRUE);
      __proc_attached++;
    }
  else if (dwReason == DLL_PROCESS_DETACH)
    {
      void *lock_free = NULL;
      while ((lock_free = InterlockedCompareExchangePointer ((volatile PVOID *) &__native_startup_lock,(PVOID) 1, 0)) != 0)
	{
	  Sleep(1000);
	}
      if(__native_startup_state!=__initialized)
	{
	  _amsg_exit (31);
	}
      else
	{
	  _PVFV * onexitbegin = (_PVFV *) _decode_pointer (__onexitbegin);
	  if (onexitbegin)
	    {
	      _PVFV *onexitend = (_PVFV *) _decode_pointer (__onexitend);
	      while (--onexitend >= onexitbegin)
		if (*onexitend != NULL)
		  (**onexitend) ();
	      free (onexitbegin);
	      __onexitbegin = __onexitend = (_PVFV *) NULL;
	    }
	  __native_startup_state = __uninitialized;
	  InterlockedExchangePointer ((volatile PVOID *) &__native_startup_lock, 0);
	}
    }
  return TRUE;
}

static BOOL __DllMainCRTStartup (HANDLE, DWORD, LPVOID);

BOOL WINAPI
DllMainCRTStartup(HANDLE hDllHandle,DWORD dwReason,LPVOID lpreserved)
{
  mingw_app_type = 0;
  if (dwReason == DLL_PROCESS_ATTACH)
    {
      __security_init_cookie ();
    }
  return __DllMainCRTStartup (hDllHandle, dwReason, lpreserved);
}

__declspec(noinline) BOOL
__DllMainCRTStartup (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  BOOL retcode = TRUE;

  __native_dllmain_reason = dwReason;
  if (dwReason == DLL_PROCESS_DETACH && __proc_attached == 0)
    {
	retcode = FALSE;
	goto i__leave;
    }
  if (dwReason == DLL_PROCESS_ATTACH || dwReason == DLL_THREAD_ATTACH)
    {
        retcode = DllEntryPoint (hDllHandle, dwReason, lpreserved);
	if (retcode)
	  retcode = _CRT_INIT (hDllHandle, dwReason, lpreserved);
	if (! retcode)
	  goto i__leave;
    }
  _pei386_runtime_relocator ();
  if (retcode && dwReason == DLL_PROCESS_ATTACH)
    __main ();
  retcode = DllMain(hDllHandle,dwReason,lpreserved);
  if ((dwReason == DLL_PROCESS_ATTACH) && ! retcode)
    {
	DllMain (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	_CRT_INIT (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	DllEntryPoint (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
    }
  if (dwReason == DLL_PROCESS_DETACH || dwReason == DLL_THREAD_DETACH)
    {
	if (_CRT_INIT (hDllHandle, dwReason, lpreserved) == FALSE)
	  {
	    retcode = FALSE;
	  }
	if (retcode)
	  {
	    retcode = DllEntryPoint (hDllHandle, dwReason, lpreserved);
	  }
    }
i__leave:
  __native_dllmain_reason = UINT_MAX;
  return retcode ;
}
#endif
