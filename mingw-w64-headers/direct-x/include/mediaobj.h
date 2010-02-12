/*** Autogenerated by WIDL 1.1.38 from mediaobj.idl - Do not edit ***/

#include <rpc.h>
#include <rpcndr.h>

#ifndef __WIDL_MEDIAOBJ_H
#define __WIDL_MEDIAOBJ_H

#ifdef __cplusplus
extern "C" {
#endif

/* Headers for imported files */

#include <unknwn.h>
#include <objidl.h>

/* Forward declarations */

#ifndef __IEnumDMO_FWD_DEFINED__
#define __IEnumDMO_FWD_DEFINED__
typedef interface IEnumDMO IEnumDMO;
#endif


#if !defined(COM_NO_WINDOWS_H) && !defined(__WINESRC__)
#include <windows.h>
#include <ole2.h>
#endif
#ifndef __IDMOQualityControl_FWD_DEFINED__
#define __IDMOQualityControl_FWD_DEFINED__
typedef interface IDMOQualityControl IDMOQualityControl;
#endif

#ifndef __IDMOVideoOutputOptimizations_FWD_DEFINED__
#define __IDMOVideoOutputOptimizations_FWD_DEFINED__
typedef interface IDMOVideoOutputOptimizations IDMOVideoOutputOptimizations;
#endif

#ifndef __IMediaBuffer_FWD_DEFINED__
#define __IMediaBuffer_FWD_DEFINED__
typedef interface IMediaBuffer IMediaBuffer;
#endif

#ifndef __IMediaObject_FWD_DEFINED__
#define __IMediaObject_FWD_DEFINED__
typedef interface IMediaObject IMediaObject;
#endif

#ifndef __IMediaObjectInPlace_FWD_DEFINED__
#define __IMediaObjectInPlace_FWD_DEFINED__
typedef interface IMediaObjectInPlace IMediaObjectInPlace;
#endif

typedef struct _DMOMediaType {
    GUID majortype;
    GUID subtype;
    BOOL bFixedSizeSamples;
    BOOL bTemporalCompression;
    ULONG lSampleSize;
    GUID formattype;
    IUnknown *pUnk;
    ULONG cbFormat;
    BYTE *pbFormat;
} DMO_MEDIA_TYPE;
/*****************************************************************************
 * IEnumDMO interface
 */
#ifndef __IEnumDMO_INTERFACE_DEFINED__
#define __IEnumDMO_INTERFACE_DEFINED__

DEFINE_GUID(IID_IEnumDMO, 0x2c3cd98a, 0x2bfa, 0x4a53, 0x9c,0x27, 0x52,0x49,0xba,0x64,0xba,0x0f);
#if defined(__cplusplus) && !defined(CINTERFACE)
interface IEnumDMO : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Next(
        DWORD cItemsToFetch,
        CLSID *pCLSID,
        WCHAR **Names,
        DWORD *pcItemsFetched) = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        DWORD cItemsToSkip) = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        IEnumDMO **ppEnum) = 0;

};
#else
typedef struct IEnumDMOVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IEnumDMO* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IEnumDMO* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IEnumDMO* This);

    /*** IEnumDMO methods ***/
    HRESULT (STDMETHODCALLTYPE *Next)(
        IEnumDMO* This,
        DWORD cItemsToFetch,
        CLSID *pCLSID,
        WCHAR **Names,
        DWORD *pcItemsFetched);

    HRESULT (STDMETHODCALLTYPE *Skip)(
        IEnumDMO* This,
        DWORD cItemsToSkip);

    HRESULT (STDMETHODCALLTYPE *Reset)(
        IEnumDMO* This);

    HRESULT (STDMETHODCALLTYPE *Clone)(
        IEnumDMO* This,
        IEnumDMO **ppEnum);

    END_INTERFACE
} IEnumDMOVtbl;
interface IEnumDMO {
    CONST_VTBL IEnumDMOVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IEnumDMO_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumDMO_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumDMO_Release(This) (This)->lpVtbl->Release(This)
/*** IEnumDMO methods ***/
#define IEnumDMO_Next(This,cItemsToFetch,pCLSID,Names,pcItemsFetched) (This)->lpVtbl->Next(This,cItemsToFetch,pCLSID,Names,pcItemsFetched)
#define IEnumDMO_Skip(This,cItemsToSkip) (This)->lpVtbl->Skip(This,cItemsToSkip)
#define IEnumDMO_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumDMO_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#endif

#endif

HRESULT STDMETHODCALLTYPE IEnumDMO_Skip_Proxy(
    IEnumDMO* This,
    DWORD cItemsToSkip);
void __RPC_STUB IEnumDMO_Skip_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEnumDMO_Reset_Proxy(
    IEnumDMO* This);
void __RPC_STUB IEnumDMO_Reset_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEnumDMO_Clone_Proxy(
    IEnumDMO* This,
    IEnumDMO **ppEnum);
void __RPC_STUB IEnumDMO_Clone_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IEnumDMO_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __WIDL_MEDIAOBJ_H */
