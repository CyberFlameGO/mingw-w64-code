/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __msdaipp_h__
#define __msdaipp_h__

#ifndef __ISynchronizeRow_FWD_DEFINED__
#define __ISynchronizeRow_FWD_DEFINED__
typedef struct ISynchronizeRow ISynchronizeRow;
#endif

#ifndef __MSDAIPP_DSO_FWD_DEFINED__
#define __MSDAIPP_DSO_FWD_DEFINED__
#ifdef __cplusplus
typedef class MSDAIPP_DSO MSDAIPP_DSO;
#else
typedef struct MSDAIPP_DSO MSDAIPP_DSO;
#endif
#endif

#ifndef __MSDAIPP_BINDER_FWD_DEFINED__
#define __MSDAIPP_BINDER_FWD_DEFINED__
#ifdef __cplusplus
typedef class MSDAIPP_BINDER MSDAIPP_BINDER;
#else
typedef struct MSDAIPP_BINDER MSDAIPP_BINDER;
#endif
#endif

#include "oledb.h"

#ifdef __cplusplus
extern "C"{
#endif

  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);

#define MSDAIPP_MAX_URL_LENGTH 4096

#define RESOURCE_PARSENAME L"RESOURCE_PARSENAME"
#define RESOURCE_PARSENAME_DBTYPE DBTYPE_WSTR
#define RESOURCE_PARSENAME_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_PARENTNAME L"RESOURCE_PARENTNAME"
#define RESOURCE_PARENTNAME_DBTYPE DBTYPE_WSTR
#define RESOURCE_PARENTNAME_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_ABSOLUTEPARSENAME L"RESOURCE_ABSOLUTEPARSENAME"
#define RESOURCE_ABSOLUTEPARSENAME_DBTYPE DBTYPE_WSTR
#define RESOURCE_ABSOLUTEPARSENAME_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_ISHIDDEN L"RESOURCE_ISHIDDEN"
#define RESOURCE_ISHIDDEN_DBTYPE DBTYPE_BOOL
#define RESOURCE_ISHIDDEN_MAXLENGTH sizeof(VARIANT_BOOL)

#define RESOURCE_ISREADONLY L"RESOURCE_ISREADONLY"
#define RESOURCE_ISREADONLY_DBTYPE DBTYPE_BOOL
#define RESOURCE_ISREADONLY_MAXLENGTH sizeof(VARIANT_BOOL)

#define RESOURCE_CONTENTTYPE L"RESOURCE_CONTENTTYPE"
#define RESOURCE_CONTENTTYPE_DBTYPE DBTYPE_WSTR
#define RESOURCE_CONTENTTYPE_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_CONTENTCLASS L"RESOURCE_CONTENTCLASS"
#define RESOURCE_CONTENTCLASS_DBTYPE DBTYPE_WSTR
#define RESOURCE_CONTENTCLASS_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_CONTENTLANGUAGE L"RESOURCE_CONTENTLANGUAGE"
#define RESOURCE_CONTENTLANGUAGE_DBTYPE DBTYPE_WSTR
#define RESOURCE_CONTENTLANGUAGE_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_CREATIONTIME L"RESOURCE_CREATIONTIME"
#define RESOURCE_CREATIONTIME_DBTYPE DBTYPE_FILETIME
#define RESOURCE_CREATIONTIME_MAXLENGTH sizeof(FILETIME)

#define RESOURCE_LASTACCESSTIME L"RESOURCE_LASTACCESSTIME"
#define RESOURCE_LASTACCESSTIME_DBTYPE DBTYPE_FILETIME
#define RESOURCE_LASTACCESSTIME_MAXLENGTH sizeof(FILETIME)

#define RESOURCE_LASTWRITETIME L"RESOURCE_LASTWRITETIME"
#define RESOURCE_LASTWRITETIME_DBTYPE DBTYPE_FILETIME
#define RESOURCE_LASTWRITETIME_MAXLENGTH sizeof(FILETIME)

#define RESOURCE_STREAMSIZE L"RESOURCE_STREAMSIZE"
#define RESOURCE_STREAMSIZE_DBTYPE DBTYPE_UI8
#define RESOURCE_STREAMSIZE_MAXLENGTH sizeof(DWORDLONG)

#define RESOURCE_ISCOLLECTION L"RESOURCE_ISCOLLECTION"
#define RESOURCE_ISCOLLECTION_DBTYPE DBTYPE_BOOL
#define RESOURCE_ISCOLLECTION_MAXLENGTH sizeof(VARIANT_BOOL)

#define RESOURCE_ISSTRUCTUREDDOCUMENT L"RESOURCE_ISSTRUCTUREDDOCUMENT"
#define RESOURCE_ISSTRUCTUREDDOCUMENT_DBTYPE DBTYPE_BOOL
#define RESOURCE_ISSTRUCTUREDDOCUMENT_MAXLENGTH sizeof(VARIANT_BOOL)

#define RESOURCE_DEFAULTDOCUMENT L"DEFAULT_DOCUMENT"
#define RESOURCE_DEFAULTDOCUMENT_DBTYPE DBTYPE_WSTR
#define RESOURCE_DEFAULTDOCUMENT_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_DISPLAYNAME L"RESOURCE_DISPLAYNAME"
#define RESOURCE_DISPLAYNAME_DBTYPE DBTYPE_WSTR
#define RESOURCE_DISPLAYNAME_MAXLENGTH MSDAIPP_MAX_URL_LENGTH

#define RESOURCE_ISROOT L"RESOURCE_ISROOT"
#define RESOURCE_ISROOT_DBTYPE DBTYPE_BOOL
#define RESOURCE_ISROOT_MAXLENGTH sizeof(VARIANT_BOOL)

  const GUID DBPROPSET_MSDAIPP_INIT = {0x8f1033e3,0xb2cd,0x11d1,{0x9c,0x74,0x0,0x0,0xf8,0x75,0xac,0x61}};
#define DBPROP_INIT_IGNORECACHEDDATA 2L
#define DBPROP_INIT_CACHEAGGRESSIVELY 3L
#define DBPROP_INIT_TREATASOFFLINE 4L
#define DBPROP_INIT_MARKFOROFFLINE 5L
#define DBPROP_INIT_PROTOCOLPROVIDER 6L

  enum MFO {
    MFO_DONTCHANGE = 0,MFO_MARK = 1,MFO_UNMARK = 2
  };

#define RESOURCE_ISMARKEDFOROFFLINE L"RESOURCE_ISMARKEDFOROFFLINE"
#define RESOURCE_ISMARKEDFOROFFLINE_DBTYPE DBTYPE_BOOL
#define RESOURCE_ISMARKEDFOROFFLINE_MAXLENGTH sizeof(VARIANT_BOOL)
#define DBGUID_RESOURCE_ISMARKEDFOROFFLINE {0x3c5d1c61,0x111e,0x11d2,{0x9c,0xda,0x0,0x0,0xf8,0x75,0xac,0x61}}

#ifdef DBINITCONSTANTS
  extern const DBID DBROWCOL_ISMARKEDFOROFFLINE = { DBGUID_RESOURCE_ISMARKEDFOROFFLINE,DBKIND_GUID,0};
#else
  extern const DBID DBROWCOL_ISMARKEDFOROFFLINE;
#endif

#define RESOURCE_PARSENAME_ALTNAME L"DAV:name"
#define RESOURCE_PARENTNAME_ALTNAME L"DAV:parentname"
#define RESOURCE_ABSOLUTEPARSENAME_ALTNAME L"DAV:href"
#define RESOURCE_ISHIDDEN_ALTNAME L"DAV:ishidden"
#define RESOURCE_ISREADONLY_ALTNAME L"DAV:isreadonly"
#define RESOURCE_CONTENTTYPE_ALTNAME L"DAV:getcontenttype"
#define RESOURCE_CONTENTCLASS_ALTNAME L"DAV:contentclass"
#define RESOURCE_CONTENTLANGUAGE_ALTNAME L"DAV:getcontentlanguage"
#define RESOURCE_CREATIONTIME_ALTNAME L"DAV:creationdate"
#define RESOURCE_LASTACCESSTIME_ALTNAME L"DAV:lastaccessed"
#define RESOURCE_LASTWRITETIME_ALTNAME L"DAV:getlastmodified"
#define RESOURCE_STREAMSIZE_ALTNAME L"DAV:getcontentlength"
#define RESOURCE_ISCOLLECTION_ALTNAME L"DAV:iscollection"
#define RESOURCE_ISSTRUCTUREDDOCUMENT_ALTNAME L"DAV:isstructureddocument"
#define RESOURCE_DEFAULTDOCUMENT_ALTNAME L"DAV:defaultdocument"
#define RESOURCE_DISPLAYNAME_ALTNAME L"DAV:displayname"
#define RESOURCE_ISROOT_ALTNAME L"DAV:isroot"
#define RESOURCE_ISMARKEDFOROFFLINE_ALTNAME L"MSDAIPP:ismarkedforoffline"

  const GUID GUID_IPPCOMMAND = { 0xd395c253,0x6511,0x11d1,{ 0x9c,0x9,0x0,0x0,0xf8,0x75,0xac,0x61 } };

  const GUID GUID_DAV_PROVIDER = {0x9FECD570,0xB9D4,0x11d1,0x9C,0x78,0x00,0x00,0xF8,0x75,0xAC,0x61};
  const GUID GUID_WEC_PROVIDER = {0x9FECD571,0xB9D4,0x11d1,0x9C,0x78,0x00,0x00,0xF8,0x75,0xAC,0x61};
  const GUID GUID_HTTP_PROVIDER = {0x9FECD572,0xB9D4,0x11d1,0x9C,0x78,0x00,0x00,0xF8,0x75,0xAC,0x61};

  extern RPC_IF_HANDLE __MIDL_itf_msdaipp_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_msdaipp_0000_v0_0_s_ifspec;

#ifndef __ISynchronizeRow_INTERFACE_DEFINED__
#define __ISynchronizeRow_INTERFACE_DEFINED__

  typedef DWORD MSDAIPP_SYNC_FLAGS;

  enum MSDAIPP_SYNCFLAGSENUM {
    MSDAIPP_SYNC_NONE = 0,MSDAIPP_SYNC_ABANDON_SERVER = 0x1,MSDAIPP_SYNC_ABANDON_LOCAL = 0x2,MSDAIPP_SYNC_MERGE = 0x4
  };

  EXTERN_C const IID IID_ISynchronizeRow;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISynchronizeRow : public IUnknown {
  public:
    virtual HRESULT WINAPI Synchronize(MSDAIPP_SYNC_FLAGS dwFlags) = 0;
  };
#else
  typedef struct ISynchronizeRowVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISynchronizeRow *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISynchronizeRow *This);
      ULONG (WINAPI *Release)(ISynchronizeRow *This);
      HRESULT (WINAPI *Synchronize)(ISynchronizeRow *This,MSDAIPP_SYNC_FLAGS dwFlags);
    END_INTERFACE
  } ISynchronizeRowVtbl;
  struct ISynchronizeRow {
    CONST_VTBL struct ISynchronizeRowVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISynchronizeRow_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISynchronizeRow_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISynchronizeRow_Release(This) (This)->lpVtbl->Release(This)
#define ISynchronizeRow_Synchronize(This,dwFlags) (This)->lpVtbl->Synchronize(This,dwFlags)
#endif
#endif
  HRESULT WINAPI ISynchronizeRow_Synchronize_Proxy(ISynchronizeRow *This,MSDAIPP_SYNC_FLAGS dwFlags);
  void __RPC_STUB ISynchronizeRow_Synchronize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __MSDAIPPLib_LIBRARY_DEFINED__
#define __MSDAIPPLib_LIBRARY_DEFINED__
  EXTERN_C const IID LIBID_MSDAIPPLib;
  EXTERN_C const CLSID CLSID_MSDAIPP_DSO;
#ifdef __cplusplus
  class MSDAIPP_DSO;
#endif
  EXTERN_C const CLSID CLSID_MSDAIPP_BINDER;
#ifdef __cplusplus
  class MSDAIPP_BINDER;
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
