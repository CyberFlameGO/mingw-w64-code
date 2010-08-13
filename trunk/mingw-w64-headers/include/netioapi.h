/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NETIOAPI
#define _INC_NETIOAPI

#include <winsock2.h>
#include <iprtrmib.h>
#include <ifdef.h>
#include <ws2tcpip.h>
#include <ws2ipdef.h>
#include <ntddndis.h>

#ifndef ANY_SIZE
#define ANY_SIZE 1
#endif

#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __IPHLPAPI_H__
#define NETIO_STATUS DWORD
#define NETIOAPI_API_ WINAPI
#else
#define NETIO_STATUS NTSTATUS
#define NETIOAPI_API_ NTAPI
#endif

#define NETIOAPI_API NETIO_STATUS NETIOAPI_API_
#define ConvertInterfaceLuidToName __MINGW_NAME_AW(ConvertInterfaceLuidToName)
#define ConvertInterfaceNameToLuid __MINGW_NAME_AW(ConvertInterfaceNameToLuid)

typedef enum _MIB_NOTIFICATION_TYPE {
  MibParameterNotification   = 0,
  MibAddInstance             = 1,
  MibDeleteInstance          = 2,
  MibInitialNotification     = 3
} MIB_NOTIFICATION_TYPE, *PMIB_NOTIFICATION_TYPE;

typedef struct _MIB_ANYCASTIPADDRESS_ROW {
  SOCKADDR_INET Address;
  NET_LUID      InterfaceLuid;
  NET_IFINDEX   InterfaceIndex;
  SCOPE_ID      ScopeId;
} MIB_ANYCASTIPADDRESS_ROW, *PMIB_ANYCASTIPADDRESS_ROW;

typedef struct _MIB_ANYCASTIPADDRESS_TABLE {
  ULONG                    NumEntries;
  MIB_ANYCASTIPADDRESS_ROW Table[ANY_SIZE];
} MIB_ANYCASTIPADDRESS_TABLE, *PMIB_ANYCASTIPADDRESS_TABLE;

typedef struct _IP_ADDRESS_PREFIX {
  SOCKADDR_INET Prefix;
  UINT8         PrefixLength;
} IP_ADDRESS_PREFIX, *PIP_ADDRESS_PREFIX;

typedef struct _MIB_IPFORWARD_ROW2 {
  NET_LUID          InterfaceLuid;
  NET_IFINDEX       InterfaceIndex;
  IP_ADDRESS_PREFIX DestinationPrefix;
  SOCKADDR_INET     NextHop;
  UCHAR             SitePrefixLength;
  ULONG             ValidLifetime;
  ULONG             PreferredLifetime;
  ULONG             Metric;
  NL_ROUTE_PROTOCOL Protocol;
  BOOLEAN           Loopback;
  BOOLEAN           AutoconfigureAddress;
  BOOLEAN           Publish;
  BOOLEAN           Immortal;
  ULONG             Age;
  NL_ROUTE_ORIGIN   Origin;
} MIB_IPFORWARD_ROW2, *PMIB_IPFORWARD_ROW2;

typedef struct _MIB_IPNET_ROW2 {
  SOCKADDR_INET     Address;
  NET_IFINDEX       InterfaceIndex;
  NET_LUID          InterfaceLuid;
  UCHAR             PhysicalAddress[IF_MAX_PHYS_ADDRESS_LENGTH];
  ULONG             PhysicalAddressLength;
  NL_NEIGHBOR_STATE State;
  __MINGW_EXTENSION union {
    __MINGW_EXTENSION struct {
      BOOLEAN IsRouter  :1;
      BOOLEAN IsUnreachable  :1;
    };
    UCHAR  Flags;
  };
  union {
    ULONG LastReachable;
    ULONG LastUnreachable;
  } ReachabilityTime;
} MIB_IPNET_ROW2, *PMIB_IPNET_ROW2;

typedef struct _MIB_IPNET_TABLE2 {
  ULONG          NumEntries;
  MIB_IPNET_ROW2 Table[ANY_SIZE];
} MIB_IPNET_TABLE2, *PMIB_IPNET_TABLE2;

typedef struct _MIB_IPFORWARD_TABLE2 {
  ULONG              NumEntries;
  MIB_IPFORWARD_ROW2 Table[ANY_SIZE];
} MIB_IPFORWARD_TABLE2, *PMIB_IPFORWARD_TABLE2;

#ifndef ScopeLevelCount
#define ScopeLevelCount 16
#endif

typedef struct _MIB_IPINTERFACE_ROW {
  ADDRESS_FAMILY                 Family;
  NET_LUID                       InterfaceLuid;
  NET_IFINDEX                    InterfaceIndex;
  ULONG                          MaxReassemblySize;
  ULONG64                        InterfaceIdentifier;
  ULONG                          MinRouterAdvertisementInterval;
  ULONG                          MaxRouterAdvertisementInterval;
  BOOLEAN                        AdvertisingEnabled;
  BOOLEAN                        ForwardingEnabled;
  BOOLEAN                        WeakHostSend;
  BOOLEAN                        WeakHostReceive;
  BOOLEAN                        UseAutomaticMetric;
  BOOLEAN                        UseNeighborUnreachabilityDetection;
  BOOLEAN                        ManagedAddressConfigurationSupported;
  BOOLEAN                        OtherStatefulConfigurationSupported;
  BOOLEAN                        AdvertiseDefaultRoute;
  NL_ROUTER_DISCOVERY_BEHAVIOR   RouterDiscoveryBehavior;
  ULONG                          DadTransmits;
  ULONG                          BaseReachableTime;
  ULONG                          RetransmitTime;
  ULONG                          PathMtuDiscoveryTimeout;
  NL_LINK_LOCAL_ADDRESS_BEHAVIOR LinkLocalAddressBehavior;
  ULONG                          LinkLocalAddressTimeout;
  ULONG                          ZoneIndices[ScopeLevelCount];
  ULONG                          SitePrefixLength;
  ULONG                          Metric;
  ULONG                          NlMtu;
  BOOLEAN                        Connected;
  BOOLEAN                        SupportsWakeUpPatterns;
  BOOLEAN                        SupportsNeighborDiscovery;
  BOOLEAN                        SupportsRouterDiscovery;
  ULONG                          ReachableTime;
  NL_INTERFACE_OFFLOAD_ROD       TransmitOffload;
  NL_INTERFACE_OFFLOAD_ROD       ReceiveOffload;
  BOOLEAN                        DisableDefaultRoutes;
} MIB_IPINTERFACE_ROW, *PMIB_IPINTERFACE_ROW;

typedef struct _MIB_IPINTERFACE_TABLE {
  ULONG               NumEntries;
  MIB_IPINTERFACE_ROW Table[ANY_SIZE];
} MIB_IPINTERFACE_TABLE, *PMIB_IPINTERFACE_TABLE;

typedef struct _MIB_UNICASTIPADDRESS_ROW {
  SOCKADDR_INET    Address;
  NET_LUID         InterfaceLuid;
  NET_IFINDEX      InterfaceIndex;
  NL_PREFIX_ORIGIN PrefixOrigin;
  NL_SUFFIX_ORIGIN SuffixOrigin;
  ULONG            ValidLifetime;
  ULONG            PreferredLifetime;
  UINT8            OnLinkPrefixLength;
  BOOLEAN          SkipAsSource;
  NL_DAD_STATE     DadState;
  SCOPE_ID         ScopeId;
  LARGE_INTEGER    CreationTimeStamp;
} MIB_UNICASTIPADDRESS_ROW, *PMIB_UNICASTIPADDRESS_ROW;

typedef struct _MIB_UNICASTIPADDRESS_TABLE {
  ULONG                    NumEntries;
  MIB_UNICASTIPADDRESS_ROW Table[ANY_SIZE];
} MIB_UNICASTIPADDRESS_TABLE, *PMIB_UNICASTIPADDRESS_TABLE;

typedef struct _MIB_IF_ROW2 {
  NET_LUID                   InterfaceLuid;
  NET_IFINDEX                InterfaceIndex;
  GUID                       InterfaceGuid;
  WCHAR                      Alias[IF_MAX_STRING_SIZE + 1];
  WCHAR                      Description[IF_MAX_STRING_SIZE + 1];
  ULONG                      PhysicalAddressLength;
   UCHAR                     PhysicalAddress[IF_MAX_PHYS_ADDRESS_LENGTH];
   UCHAR                     PermanentPhysicalAddress[IF_MAX_PHYS_ADDRESS_LENGTH];
  ULONG                      Mtu;
  IFTYPE                     Type;
  TUNNEL_TYPE                TunnelType;
  NDIS_MEDIUM                MediaType;
  NDIS_PHYSICAL_MEDIUM       PhysicalMediumType;
  NET_IF_ACCESS_TYPE         AccessType;
  NET_IF_DIRECTION_TYPE      DirectionType;
  struct {
    BOOLEAN HardwareInterface  :1;
    BOOLEAN FilterInterface  :1;
    BOOLEAN ConnectorPresent   :1;
    BOOLEAN NotAuthenticated  :1;
    BOOLEAN NotMediaConnected  :1;
    BOOLEAN Paused  :1;
    BOOLEAN LowPower  :1;
    BOOLEAN EndPointInterface  :1;
  } InterfaceAndOperStatusFlags;
  IF_OPER_STATUS             OperStatus;
  NET_IF_ADMIN_STATUS        AdminStatus;
  NET_IF_MEDIA_CONNECT_STATE MediaConnectState;
  NET_IF_NETWORK_GUID        NetworkGuid;
  NET_IF_CONNECTION_TYPE     ConnectionType;
  ULONG64                    TransmitLinkSpeed;
  ULONG64                    ReceiveLinkSpeed;
  ULONG64                    InOctets;
  ULONG64                    InUcastPkts;
  ULONG64                    InNUcastPkts;
  ULONG64                    InDiscards;
  ULONG64                    InErrors;
  ULONG64                    InUnknownProtos;
  ULONG64                    InUcastOctets;
  ULONG64                    InMulticastOctets;
  ULONG64                    InBroadcastOctets;
  ULONG64                    OutOctets;
  ULONG64                    OutUcastPkts;
  ULONG64                    OutNUcastPkts;
  ULONG64                    OutDiscards;
  ULONG64                    OutErrors;
  ULONG64                    OutUcastOctets;
  ULONG64                    OutMulticastOctets;
  ULONG64                    OutBroadcastOctets;
  ULONG64                    OutQLen;
} MIB_IF_ROW2, *PMIB_IF_ROW2;

typedef struct _MIB_IF_TABLE2 {
  ULONG       NumEntries;
  MIB_IF_ROW2 Table[ANY_SIZE];
} MIB_IF_TABLE2, *PMIB_IF_TABLE2;

typedef struct _MIB_IFSTACK_ROW {
  NET_IFINDEX HigherLayerInterfaceIndex;
  NET_IFINDEX LowerLayerInterfaceIndex;
} MIB_IFSTACK_ROW, *PMIB_IFSTACK_ROW;

typedef struct _MIB_IFSTACK_TABLE {
  ULONG           NumEntries;
  MIB_IFSTACK_ROW Table[ANY_SIZE];
} MIB_IFSTACK_TABLE, *PMIB_IFSTACK_TABLE;

typedef struct _MIB_INVERTEDIFSTACK_ROW {
  NET_IFINDEX LowerLayerInterfaceIndex;
  NET_IFINDEX HigherLayerInterfaceIndex;
} MIB_INVERTEDIFSTACK_ROW, *PMIB_INVERTEDIFSTACK_ROW;

typedef struct _MIB_INVERTEDIFSTACK_TABLE {
  ULONG                   NumEntries;
  MIB_INVERTEDIFSTACK_ROW Table[ANY_SIZE];
} MIB_INVERTEDIFSTACK_TABLE, *PMIB_INVERTEDIFSTACK_TABLE;

typedef struct _MIB_IPPATH_ROW {
  SOCKADDR_INET Source;
  SOCKADDR_INET Destination;
  NET_LUID      InterfaceLuid;
  NET_IFINDEX   InterfaceIndex;
  SOCKADDR_INET CurrentNextHop;
  ULONG         PathMtu;
  ULONG         RttMean;
  ULONG         RttDeviation;
  __MINGW_EXTENSION union {
    ULONG LastReachable;
    ULONG LastUnreachable;
  };
  BOOLEAN       IsReachable;
  ULONG64       LinkTransmitSpeed;
  ULONG64       LinkReceiveSpeed;
} MIB_IPPATH_ROW, *PMIB_IPPATH_ROW;

typedef struct _MIB_IPPATH_TABLE {
  ULONG          NumEntries;
  MIB_IPPATH_ROW Table[ANY_SIZE];
} MIB_IPPATH_TABLE, *PMIB_IPPATH_TABLE;

typedef struct _MIB_MULTICASTIPADDRESS_ROW {
  SOCKADDR_INET Address;
  NET_IFINDEX   InterfaceIndex;
  NET_LUID      InterfaceLuid;
  SCOPE_ID      ScopeId;
} MIB_MULTICASTIPADDRESS_ROW, *PMIB_MULTICASTIPADDRESS_ROW;

typedef struct _MIB_MULTICASTIPADDRESS_TABLE {
  ULONG                      NumEntries;
  MIB_MULTICASTIPADDRESS_ROW Table[ANY_SIZE];
} MIB_MULTICASTIPADDRESS_TABLE, *PMIB_MULTICASTIPADDRESS_TABLE;

NETIOAPI_API CancelMibChangeNotify2(
  HANDLE NotificationHandle
);

NETIO_STATUS WINAPI ConvertInterfaceAliasToLuid(
  const WCHAR *InterfaceAlias,
  PNET_LUID InterfaceLuid
);

NETIO_STATUS WINAPI ConvertInterfaceLuidToNameA(
  const NET_LUID *InterfaceLuid,
  PSTR InterfaceName,
  SIZE_T Length
);

NETIO_STATUS WINAPI ConvertInterfaceLuidToNameW(
  const NET_LUID *InterfaceLuid,
  PWSTR InterfaceName,
  SIZE_T Length
);

NETIO_STATUS WINAPI ConvertInterfaceNameToLuidA(
  const CHAR *InterfaceName,
  PNET_LUID InterfaceLuid
);

NETIO_STATUS WINAPI ConvertInterfaceNameToLuidW(
  const WCHAR *InterfaceName,
  PNET_LUID InterfaceLuid
);

PCHAR WINAPI if_indextoname(
  NET_IFINDEX InterfaceIndex,
  PCHAR InterfaceName
);

NET_IFINDEX WINAPI if_nametoindex(
  PCSTR InterfaceName
);

NETIO_STATUS WINAPI ConvertInterfaceGuidToLuid(
  const GUID *InterfaceGuid,
  PNET_LUID InterfaceLuid
);

NETIO_STATUS WINAPI ConvertInterfaceIndexToLuid(
  NET_IFINDEX InterfaceIndex,
  PNET_LUID InterfaceLuid
);

NETIO_STATUS WINAPI ConvertInterfaceLuidToAlias(
  const NET_LUID *InterfaceLuid,
  PWSTR InterfaceAlias,
  SIZE_T Length
);

NETIO_STATUS WINAPI ConvertInterfaceLuidToGuid(
  const NET_LUID *InterfaceLuid,
  GUID *InterfaceGuid
);

NETIO_STATUS WINAPI ConvertInterfaceLuidToIndex(
  const NET_LUID *InterfaceLuid,
  PNET_IFINDEX InterfaceIndex
);

NETIO_STATUS WINAPI ConvertIpv4MaskToLength(
  ULONG Mask,
  PUINT8 MaskLength
);

NETIO_STATUS WINAPI ConvertLengthToIpv4Mask(
  ULONG MaskLength,
  PULONG Mask
);

NETIOAPI_API CreateAnycastIpAddressEntry(
  const MIB_ANYCASTIPADDRESS_ROW *Row
);

NETIOAPI_API CreateIpForwardEntry2(
  const MIB_IPFORWARD_ROW2 *Row
);

NETIOAPI_API GetIpNetTable2(
  ADDRESS_FAMILY Family,
  PMIB_IPNET_TABLE2 *Table
);

NETIOAPI_API GetIpNetEntry2(
  PMIB_IPNET_ROW2 Row
);

NETIOAPI_API CreateIpNetEntry2(
  const MIB_IPNET_ROW2 *Row
);

NETIOAPI_API CreateSortedAddressPairs(
  const PSOCKADDR_IN6 SourceAddressList,
  ULONG SourceAddressCount,
  const PSOCKADDR_IN6 DestinationAddressList,
  ULONG DestinationAddressCount,
  ULONG AddressSortOptions,
  PSOCKADDR_IN6_PAIR *SortedAddressPairList,
  ULONG *SortedAddressPairCount
);

NETIOAPI_API CreateIpNetEntry2(
  const MIB_IPNET_ROW2 *Row
);

NETIOAPI_API CreateUnicastIpAddressEntry(
  const MIB_UNICASTIPADDRESS_ROW *Row
);

NETIOAPI_API DeleteIpForwardEntry2(
  const MIB_IPFORWARD_ROW2 *Row
);

NETIOAPI_API GetIpForwardTable2(
  ADDRESS_FAMILY  Family,
  PMIB_IPFORWARD_TABLE2 *Table
);

VOID NETIOAPI_API_ FreeMibTable(
  PVOID Memory
);

NETIOAPI_API DeleteIpNetEntry2(
  const MIB_IPNET_ROW2 *Row
);

NETIOAPI_API GetIpNetTable2(
  ADDRESS_FAMILY  Family,
  PMIB_IPNET_TABLE2 *Table
);

NETIOAPI_API DeleteUnicastIpAddressEntry(
  const MIB_UNICASTIPADDRESS_ROW *Row
);

NETIOAPI_API GetUnicastIpAddressEntry(
  PMIB_UNICASTIPADDRESS_ROW Row
);

NETIOAPI_API DeleteAnycastIpAddressEntry(
  const MIB_ANYCASTIPADDRESS_ROW *Row
);

NETIOAPI_API FlushIpNetTable2(
  ADDRESS_FAMILY  Family,
  NET_IFINDEX InterfaceIndex
);

NETIOAPI_API FlushIpPathTable(
  ADDRESS_FAMILY  Family
);

NETIOAPI_API GetAnycastIpAddressEntry(
  PMIB_ANYCASTIPADDRESS_ROW Row
);

NETIOAPI_API GetAnycastIpAddressTable(
  ADDRESS_FAMILY  Family,
  PMIB_ANYCASTIPADDRESS_TABLE *Table
);

NETIOAPI_API GetBestRoute2(
  NET_LUID *InterfaceLuid,
  NET_IFINDEX InterfaceIndex,
  const SOCKADDR_INET *SourceAddress,
  const SOCKADDR_INET *DestinationAddress,
  ULONG AddressSortOptions,
  PMIB_IPFORWARD_ROW2 BestRoute,
  SOCKADDR_INET *BestSourceAddress
);

NETIOAPI_API GetIfEntry2(
  PMIB_IF_ROW2 Row
);

NETIOAPI_API GetIfTable2(
  PMIB_IF_TABLE2 *Table
);

NETIOAPI_API  GetIfStackTable(
  PMIB_IFSTACK_TABLE *Table
);

/* TODO: Fixme.
  MIB_IF_TABLE_LEVEL is unknown type
  NETIOAPI_API GetIfTable2Ex(MIB_IF_TABLE_LEVEL Level,PMIB_IF_TABLE2 *Table);
*/

NETIOAPI_API  GetInvertedIfStackTable(
  PMIB_INVERTEDIFSTACK_TABLE *Table
);

NETIOAPI_API GetIpForwardEntry2(
  PMIB_IPFORWARD_ROW2 Row
);

NETIOAPI_API GetIpInterfaceEntry(
  PMIB_IPINTERFACE_ROW Row
);

NETIOAPI_API  GetIpInterfaceTable(
  ADDRESS_FAMILY  Family,
  PMIB_IPINTERFACE_TABLE *Table
);

NETIOAPI_API GetIpNetEntry2(
  PMIB_IPNET_ROW2 Row
);

NETIOAPI_API GetIpPathEntry(
  PMIB_IPPATH_ROW Row
);

NETIOAPI_API GetIpPathTable(
  ADDRESS_FAMILY  Family,
  PMIB_IPPATH_TABLE *Table
);

NETIOAPI_API GetMulticastIpAddressEntry(
  PMIB_MULTICASTIPADDRESS_ROW Row
);

NETIOAPI_API GetMulticastIpAddressTable(
  ADDRESS_FAMILY  Family,
  PMIB_MULTICASTIPADDRESS_TABLE *Table
);

NETIOAPI_API GetTeredoPort(
  USHORT *Port
);

typedef void (WINAPI *PTEREDO_PORT_CHANGE_CALLBACK)(void* callerContext, USHORT Port, MIB_NOTIFICATION_TYPE type);

NETIOAPI_API NotifyTeredoPortChange(
  PTEREDO_PORT_CHANGE_CALLBACK Callback,
  PVOID CallerContext,
  BOOLEAN InitialNotification,
  HANDLE *NotificationHandle
);

typedef void (WINAPI *PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK)(void* callerContext, MIB_UNICASTIPADDRESS_TABLE *AddressTable);

NETIOAPI_API NotifyStableUnicastIpAddressTable(
  ADDRESS_FAMILY  Family,
  PMIB_UNICASTIPADDRESS_TABLE *Table,
  PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK CallerCallback,
  PVOID CallerContext,
  HANDLE *NotificationHandle
);

typedef void (WINAPI *PUNICAST_IPADDRESS_CHANGE_CALLBACK)(void* callerContext, PMIB_UNICASTIPADDRESS_ROW row, MIB_NOTIFICATION_TYPE type);

NETIOAPI_API NotifyUnicastIpAddressChange(
  ADDRESS_FAMILY Family,
  PUNICAST_IPADDRESS_CHANGE_CALLBACK Callback,
  PVOID CallerContext,
  BOOLEAN InitialNotification,
  HANDLE *NotificationHandle
);

NETIOAPI_API GetUnicastIpAddressTable(
  ADDRESS_FAMILY  Family,
  PMIB_UNICASTIPADDRESS_TABLE *Table
);

typedef LPVOID PIPINTERFACE_CHANGE_CALLBACK;

NETIOAPI_API NotifyIpInterfaceChange(
  ADDRESS_FAMILY Family,
  PIPINTERFACE_CHANGE_CALLBACK Callback,
  PVOID CallerContext,
  BOOLEAN InitialNotification,
  HANDLE *NotificationHandle
);

typedef LPVOID PIPFORWARD_CHANGE_CALLBACK;

NETIOAPI_API NotifyRouteChange2(
  ADDRESS_FAMILY Family,
  PIPFORWARD_CHANGE_CALLBACK Callback,
  PVOID CallerContext,
  BOOLEAN InitialNotification,
  HANDLE *NotificationHandle
);

NETIOAPI_API ResolveIpNetEntry2(
  PMIB_IPNET_ROW2 Row,
  const SOCKADDR_INET *SourceAddress
);

NETIOAPI_API SetIpForwardEntry2(
  const MIB_IPFORWARD_ROW2 *Route
);

NETIOAPI_API SetIpInterfaceEntry(
  PMIB_IPINTERFACE_ROW Row
);

NETIOAPI_API SetIpNetEntry2(
  PMIB_IPNET_ROW2 Row
);

NETIOAPI_API SetUnicastIpAddressEntry(
  const MIB_UNICASTIPADDRESS_ROW *Row
);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /*_INC_NETIOAPI*/
