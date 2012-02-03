#define INITGUID
#include <basetyps.h>
#define DEFINE_SHLGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

DEFINE_SHLGUID(CLSID_ShellDesktop,0x00021400L,0,0);
DEFINE_SHLGUID(CLSID_ShellLink,0x00021401L,0,0);
DEFINE_SHLGUID(FMTID_Intshcut,0x000214A0L,0,0);
DEFINE_SHLGUID(FMTID_InternetSite,0x000214A1L,0,0);
DEFINE_SHLGUID(CGID_Explorer,0x000214D0L,0,0);
DEFINE_SHLGUID(CGID_ShellDocView,0x000214D1L,0,0);
DEFINE_SHLGUID(CGID_ShellServiceObject,0x000214D2L,0,0);
DEFINE_SHLGUID(IID_INewShortcutHookA,0x000214E1L,0,0);
DEFINE_SHLGUID(IID_IShellBrowser,0x000214E2L,0,0);
DEFINE_SHLGUID(IID_IShellView,0x000214E3L,0,0);
DEFINE_SHLGUID(IID_IContextMenu,0x000214E4L,0,0);
DEFINE_SHLGUID(IID_IQueryInfo,0x00021500L,0,0);
DEFINE_SHLGUID(IID_IShellIcon,0x000214E5L,0,0);
DEFINE_SHLGUID(IID_IShellFolder,0x000214E6L,0,0);
DEFINE_SHLGUID(IID_IShellExtInit,0x000214E8L,0,0);
DEFINE_SHLGUID(IID_IShellPropSheetExt,0x000214E9L,0,0);
DEFINE_SHLGUID(IID_IPersistFolder,0x000214EAL,0,0);
DEFINE_SHLGUID(IID_IExtractIconA,0x000214EBL,0,0);
DEFINE_SHLGUID(IID_IShellLinkA,0x000214EEL,0,0);
DEFINE_SHLGUID(IID_IShellCopyHookA,0x000214EFL,0,0);
DEFINE_SHLGUID(IID_IFileViewerA,0x000214F0L,0,0);
DEFINE_SHLGUID(IID_ICommDlgBrowser,0x000214F1L,0,0);
DEFINE_SHLGUID(IID_IEnumIDList,0x000214F2L,0,0);
DEFINE_SHLGUID(IID_IFileViewerSite,0x000214F3L,0,0);
DEFINE_SHLGUID(IID_IContextMenu2,0x000214F4L,0,0);
DEFINE_GUID(IID_IContextMenu3,0xBCFCE0A0,0xEC17,0x11D0,0x8D,0x10,0x0,0xA0,0xC9,0xF,0x27,0x19);
DEFINE_SHLGUID(IID_IShellExecuteHookA,0x000214F5L,0,0);
DEFINE_SHLGUID(IID_IPropSheetPage,0x000214F6L,0,0);
DEFINE_SHLGUID(IID_INewShortcutHookW,0x000214F7L,0,0);
DEFINE_SHLGUID(IID_IFileViewerW,0x000214F8L,0,0);
DEFINE_SHLGUID(IID_IShellLinkW,0x000214F9L,0,0);
DEFINE_SHLGUID(IID_IExtractIconW,0x000214FAL,0,0);
DEFINE_SHLGUID(IID_IShellExecuteHookW,0x000214FBL,0,0);
DEFINE_SHLGUID(IID_IShellCopyHookW,0x000214FCL,0,0);
DEFINE_GUID(IID_IShellView2,0x88E39E80L,0x3578,0x11CF,0xAE,0x69,0x08,0x00,0x2B,0x2E,0x12,0x62);
DEFINE_GUID(IID_IShellFolder2,0x93F2F68C,0x1D1B,0x11D3,0xA3,0x0E,0x00,0xC0,0x4F,0x79,0xAB,0xD1);
DEFINE_GUID(IID_IPersistFolder2,0x1AC3D9F0,0x175C,0x11D1,0x95,0xBE,0x00,0x60,0x97,0x97,0xEA,0x4F);
DEFINE_GUID(IID_IPersistFolder3,0xCEF04FDF,0xFE72,0x11D2,0x87,0xA5,0x00,0xC0,0x4F,0x68,0x37,0xCF);
DEFINE_GUID(IID_IFileSystemBindData,0x1E18D10,0x4D8B,0x11D2,0x85,0x5D,0x00,0x60,0x08,0x05,0x93,0x67);
DEFINE_GUID(LIBID_SHDocVw,0xEAB22AC0,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(IID_IShellExplorer,0xEAB22AC1,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(DIID_DShellExplorerEvents,0xEAB22AC2,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(CLSID_ShellExplorer,0xEAB22AC3,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(IID_ISHItemOC,0xEAB22AC4,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(DIID_DSHItemOCEvents,0xEAB22AC5,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(CLSID_SHItemOC,0xEAB22AC6,0x30C1,0x11CF,0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B);
DEFINE_GUID(IID_DHyperLink,0x0002DF07,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);
DEFINE_GUID(IID_DIExplorer,0x0002DF05,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);
DEFINE_GUID(DIID_DExplorerEvents,0x0002DF06,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);
DEFINE_GUID(CLSID_InternetExplorer,0x0002DF01,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);
DEFINE_GUID(CLSID_StdHyperLink,0x0002DF09,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);
DEFINE_GUID(CLSID_FileTypes,0xB091E540,0x83E3,0x11CF,0xA7,0x13,0x00,0x20,0xAF,0xD7,0x97,0x62);
DEFINE_GUID(CLSID_DragDropHelper,0x4657278AL,0x411B,0x11D2,0x83,0x9A,0x0,0xC0,0x4F,0xD9,0x18,0xD0);
DEFINE_GUID(IID_IDropTargetHelper,0x4657278BL,0x411B,0x11D2,0x83,0x9A,0x0,0xC0,0x4F,0xD9,0x18,0xD0);
DEFINE_GUID(IID_IDragSourceHelper,0xDE5BF786L,0x477A,0x11D2,0x83,0x9D,0x0,0xC0,0x4F,0xD9,0x18,0xD0);
DEFINE_GUID(IID_IColumnProvider,0xE8025004,0x1C42,0x11D2,0xBE,0x2C,0x0,0xA0,0xC9,0xA8,0x3D,0xA1);
DEFINE_GUID(IID_IShellIconOverlayIdentifier,0x0C6C4200L,0xC589,0x11D0,0x99,0x9A,0x00,0xC0,0x4F,0xD6,0x55,0xE1);
DEFINE_GUID(CLSID_AutoComplete,0x00bb2763,0x6a77,0x11d0,0xa5,0x35,0x00,0xc0,0x4f,0xd7,0xd0,0x62);
DEFINE_GUID(IID_IAutoComplete,0x00bb2762,0x6a77,0x11d0,0xa5,0x35,0x00,0xc0,0x4f,0xd7,0xd0,0x62);
DEFINE_GUID(IID_IAutoComplete2,0xeac04bc0,0x3791,0x11d2,0xbb,0x95,0x00,0x60,0x97,0x7b,0x46,0x4c);
DEFINE_GUID(CLSID_ACLMulti,0x00bb2765,0x6a77,0x11d0,0xa5,0x35,0x00,0xc0,0x4f,0xd7,0xd0,0x62);
DEFINE_GUID(IID_IObjMgr,0x00bb2761,0x6a77,0x11d0,0xa5,0x35,0x00,0xc0,0x4f,0xd7,0xd0,0x62);
DEFINE_GUID(CLSID_ACListISF,0x03c036f1,0xa186,0x11D0,0x82,0x4a,0x00,0xaa,0x00,0x5b,0x43,0x83);
DEFINE_GUID(IID_IACList,0x77a130b0,0x94fd,0x11D0,0xa5,0x44,0x00,0xc0,0x4f,0xd7,0xd0,0x62);
DEFINE_GUID(CLSID_RecycleBin,0x645FF040,0x5081,0x101B,0x9F,0x08,0x00,0xAA,0x00,0x2F,0x95,0x4E);
DEFINE_GUID(CLSID_ControlPanel,0x21EC2020,0x3AEA,0x1069,0xA2,0xDD,0x08,0x00,0x2B,0x30,0x30,0x9D);
DEFINE_GUID(CLSID_MyComputer,0x20D04FE0,0x3AEA,0x1069,0xA2,0xD8,0x08,0x00,0x2B,0x30,0x30,0x9D);
DEFINE_GUID(CLSID_Internet,0x871C5380,0x42A0,0x1069,0xA2,0xEA,0x08,0x00,0x2B,0x30,0x30,0x9D);
DEFINE_GUID(CLSID_NetworkPlaces,0x208D2C60,0x3AEA,0x1069,0xA2,0xD7,0x08,0x00,0x2B,0x30,0x30,0x9D);
DEFINE_GUID(CLSID_MyDocuments,0x450d8fba,0xad25,0x11d0,0x98,0xa8,0x08,0x00,0x36,0x1b,0x11,0x03);
DEFINE_GUID(CLSID_FolderShortcut,0x0AFACED1,0xE828,0x11D1,0x91,0x87,0xB5,0x32,0xF1,0xE9,0x57,0x5D);
DEFINE_GUID(CLSID_ShellFSFolder,0xF3364BA0,0x65B9,0x11CE,0xA9,0xBA,0x00,0xAA,0x00,0x4A,0xE8,0x37);
DEFINE_GUID(IID_IShellLinkDataList,0x45E2B4AE,0xB1C3, 0x11D0,0xB9,0x2F,0x00,0xA0,0xC9,0x03,0x12,0xE1);
DEFINE_GUID(IID_IFolderView,0xCDE725B0L,0xCCC9,0x4519,0x91,0x7E,0x32,0x5D,0x72,0xFA,0xB4,0xCE);
DEFINE_GUID(CLSID_TaskbarList,0x56FDF344L,0xFD6D,0x11D0,0x95,0x8A,0x00,0x60,0x97,0xC9,0xA0,0x90);
DEFINE_GUID(CLSID_ApplicationAssociationRegistrationUI, 0x1968106d, 0xf3b5, 0x44cf, 0x89,0x0e, 0x11,0x6f,0xcb,0x9e,0xce,0xf1);
DEFINE_GUID(IID_IApplicationAssociationRegistrationUI, 0x1f76a169,0xf994,0x40ac, 0x8f,0xc8,0x09,0x59,0xe8,0x87,0x47,0x10);
DEFINE_GUID(IID_ITaskList3,0xEA1AFB91L,0x9E28,0x4B86,0x90,0xE9,0x9E,0x9F,0x8A,0x5E,0xEF,0xAF);
