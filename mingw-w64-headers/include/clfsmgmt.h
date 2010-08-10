/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CLFSMGMT
#define _INC_CLFSMGMT
#if (_WIN32_WINNT >= 0x0600)
#ifdef __cplusplus
extern "C" {
#endif

typedef enum _CLFS_MGMT_POLICY_TYPE {
  ClfsMgmtPolicyMaximumSize             = 0x0,
  ClfsMgmtPolicyMinimumSize             = 0x1,
  ClfsMgmtPolicyNewContainerSize        = 0x2,
  ClfsMgmtPolicyGrowthRate              = 0x3,
  ClfsMgmtPolicyLogTail                 = 0x4,
  ClfsMgmtPolicyAutoShrink              = 0x5,
  ClfsMgmtPolicyAutoGrow                = 0x6,
  ClfsMgmtPolicyNewContainerPrefix      = 0x7,
  ClfsMgmtPolicyNewContainerSuffix      = 0x8,
  ClfsMgmtPolicyNewContainerExtension 
} CLFS_MGMT_POLICY_TYPE, *PCLFS_MGMT_POLICY_TYPE;

typedef enum _CLFS_MGMT_NOTIFICATION_TYPE {
  ClfsMgmtAdvanceTailNotification = 0,
  ClfsMgmtLogFullHandlerNotification,
  ClfsMgmtLogUnpinnedNotification,
  ClfsMgmtLogWriteNotification
} CLFS_MGMT_NOTIFICATION_TYPE;

typedef struct _CLFS_MGMT_NOTIFICATION {
  CLFS_MGMT_NOTIFICATION_TYPE Notification;
  CLFS_LSN                    Lsn;
  USHORT                      LogIsPinned;
} CLFS_MGMT_NOTIFICATION, *PCLFS_MGMT_NOTIFICATION;

typedef struct _CLFS_MGMT_POLICY {
  ULONG Version;
  ULONG LengthInBytes;
  ULONG PolicyFlags;
  CLFS_MGMT_POLICY_TYPE PolicyType;
  __MINGW_EXTENSION union {
    __MINGW_EXTENSION struct {
      ULONG Containers;
    } MaximumSize;
    __MINGW_EXTENSION struct {
      ULONG Containers;
    } MinimumSize;
    __MINGW_EXTENSION struct {
      ULONG SizeInBytes;
    } NewContainerSize;
    __MINGW_EXTENSION struct {
      ULONG AbsoluteGrowthInContainers;
      ULONG RelativeGrowthPercentage;
    } GrowthRate;
    __MINGW_EXTENSION struct {
      ULONG MinimumAvailablePercentage;
      ULONG MinimumAvailableContainers;
    } LogTail;
    __MINGW_EXTENSION struct {
      ULONG Percentage;
    } AutoShrink;
    __MINGW_EXTENSION struct {
      ULONG Enabled;
    } AutoGrow;
    __MINGW_EXTENSION struct {
      USHORT PrefixLengthInBytes;
      WCHAR PrefixString[1];
    } NewContainerPrefix;
    __MINGW_EXTENSION struct {
      ULONGLONG NextContainerSuffix;
    } NewContainerSuffix;
    __MINGW_EXTENSION struct {
      USHORT ExtensionLengthInBytes;
      WCHAR ExtensionString[1];
    } NewContainerExtension;
  } PolicyParameters;
} CLFS_MGMT_POLICY,  *PCLFS_MGMT_POLICY;

/* Conflict with CLFS_MGMT_POLICY_TYPE
typedef struct _ClfsMgmtPolicyAutoGrow {
  ULONG Enabled;
} ClfsMgmtPolicyAutoGrow;

typedef struct _ClfsMgmtPolicyAutoShrink {
  ULONG Percentage;
} ClfsMgmtPolicyAutoShrink;

typedef struct _ClfsMgmtPolicyGrowthRate {
  ULONG AbsoluteGrowthInContainers;
  ULONG RelativeGrowthPercentage;
} ClfsMgmtPolicyGrowthRate;

typedef struct _ClfsMgmtPolicyLogTail {
  ULONG MinimumAvailablePercentage;
  ULONG MinimumAvailableContainers;
} ClfsMgmtPolicyLogTail;

typedef struct _ClfsMgmtPolicyMinimumSize {
  ULONG Containers;
} ClfsMgmtPolicyMinimumSize;

typedef struct _ClfsMgmtPolicyMaximumSize {
  ULONG Containers;
} ClfsMgmtPolicyMaximumSize;

typedef struct _ClfsMgmtPolicyNewContainerExtension {
  ULONG ExtensionLengthInBytes;
  WCHAR ExtensionString[1];
} ClfsMgmtPolicyNewContainerExtension, *PClfsMgmtPolicyNewContainerExtension;

typedef struct _ClfsMgmtPolicyNewContainerPrefix {
  USHORT PrefixLengthInBytes;
  WCHAR  PrefixString[1];
} ClfsMgmtPolicyNewContainerPrefix;

typedef struct _ClfsMgmtPolicyNewContainerSize {
  ULONG SizeInBytes;
} ClfsMgmtPolicyNewContainerSize;

typedef struct _ClfsMgmtPolicyNewContainerSuffix {
  ULONGLONG NextContainerSuffix;
} ClfsMgmtPolicyNewContainerSuffix, *PClfsMgmtPolicyNewContainerSuffix;
*/
#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_CLFSMGMT*/
