/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#if !defined(_CERTSRV_H_)
#define _CERTSRV_H_

#include <certadm.h>
#include <certbcli.h>
#include <certcli.h>
#include <certenc.h>
#include <certexit.h>
#include <certif.h>
#include <certpol.h>
#include <certmod.h>
#include <certview.h>

#define wszSERVICE_NAME TEXT("CertSvc")
#define wszREGKEYNOSYSTEMCERTSVCPATH TEXT("CurrentControlSet\\Services\\") wszSERVICE_NAME
#define wszREGKEYCERTSVCPATH TEXT("SYSTEM\\") wszREGKEYNOSYSTEMCERTSVCPATH
#define wszREGKEYBASE wszREGKEYCERTSVCPATH
#define wszREGKEYCONFIGPATH wszREGKEYCERTSVCPATH TEXT("\\") wszREGKEYCONFIG
#define wszREGKEYCONFIGPATH_BS wszREGKEYCONFIGPATH TEXT("\\")
#define wszREGKEYCONFIGCANAME wszREGKEYCONFIGPATH_BS
#define wszREGKEYCONFIGRESTORE wszREGKEYCONFIGPATH_BS wszREGKEYRESTOREINPROGRESS
#define wszREGKEYCONFIG TEXT("Configuration")
#define wszREGACTIVE TEXT("Active")
#define wszREGDIRECTORY TEXT("ConfigurationDirectory")
#define wszREGDBDIRECTORY TEXT("DBDirectory")
#define wszREGDBLOGDIRECTORY TEXT("DBLogDirectory")
#define wszREGDBSYSDIRECTORY TEXT("DBSystemDirectory")
#define wszREGDBTEMPDIRECTORY TEXT("DBTempDirectory")
#define wszREGDBSESSIONCOUNT TEXT("DBSessionCount")
#define wszREGDBFLAGS TEXT("DBFlags")
#define wszREGDBLASTFULLBACKUP TEXT("DBLastFullBackup")
#define wszREGDBLASTINCREMENTALBACKUP TEXT("DBLastIncrementalBackup")
#define wszREGDBLASTRECOVERY TEXT("DBLastRecovery")
#define wszREGWEBCLIENTCAMACHINE TEXT("WebClientCAMachine")
#define wszREGVERSION TEXT("Version")
#define wszREGWEBCLIENTCANAME TEXT("WebClientCAName")
#define wszREGWEBCLIENTCATYPE TEXT("WebClientCAType")
#define wszREGLDAPFLAGS TEXT("LDAPFlags")
#define wszREGCERTSRVDEBUG TEXT("Debug")

#define DBSESSIONCOUNTDEFAULT 20

#define DBFLAGS_READONLY 0x00000001
#define DBFLAGS_CREATEIFNEEDED 0x00000002
#define DBFLAGS_CIRCULARLOGGING 0x00000004
#define DBFLAGS_LAZYFLUSH 0x00000008
#define DBFLAGS_MAXCACHESIZEX100 0x00000010
#define DBFLAGS_CHECKPOINTDEPTH60MB 0x00000020
#define DBFLAGS_LOGBUFFERSLARGE 0x00000040
#define DBFLAGS_LOGBUFFERSHUGE 0x00000080
#define DBFLAGS_LOGFILESIZE16MB 0x00000100
#define DBFLAGS_MULTITHREADTRANSACTIONS 0x00000200
#define DBFLAGS_DISABLESNAPSHOTBACKUP 0x00000400

#define DBFLAGS_DEFAULT (DBFLAGS_LAZYFLUSH | DBFLAGS_MAXCACHESIZEX100 | DBFLAGS_CHECKPOINTDEPTH60MB | DBFLAGS_LOGBUFFERSHUGE)

#define LDAPF_SSLENABLE 0x00000001
#define LDAPF_SIGNDISABLE 0x00000002

#define MAXINCOMINGMESSAGESIZEDEFAULT (64 *1024)
#define MAXINCOMINGALLOCSIZEDEFAULT (64 *1024)

#define CSVER_MAJOR_WIN2K 1
#define CSVER_MINOR_WIN2K 1

#define CSVER_MAJOR_WHISTLER 2
#define CSVER_MINOR_WHISTLER_BETA2 1
#define CSVER_MINOR_WHISTLER_BETA3 2

#define CSVER_MAJOR CSVER_MAJOR_WHISTLER
#define CSVER_MINOR CSVER_MINOR_WHISTLER_BETA3

#define CSVER_EXTRACT_MAJOR(version) ((version)>>16)
#define CSVER_EXTRACT_MINOR(version) ((version)&0xffff)
#define CSVER_BUILD_VERSION(major,minor) (((major)<<16)|(minor))

#define wszREGKEYRESTOREINPROGRESS TEXT("RestoreInProgress")
#define wszREGKEYDBPARAMETERS TEXT("DBParameters")

#define wszREGCADESCRIPTION TEXT("CADescription")
#define wszREGCACERTHASH TEXT("CACertHash")
#define wszREGCASERIALNUMBER TEXT("CACertSerialNumber")
#define wszREGCAXCHGCERTHASH TEXT("CAXchgCertHash")
#define wszREGKRACERTHASH TEXT("KRACertHash")
#define wszREGKRACERTCOUNT TEXT("KRACertCount")
#define wszREGKRAFLAGS TEXT("KRAFlags")
#define wszREGCATYPE TEXT("CAType")
#define wszREGCERTENROLLCOMPATIBLE TEXT("CertEnrollCompatible")
#define wszREGENFORCEX500NAMELENGTHS TEXT("EnforceX500NameLengths")
#define wszREGCOMMONNAME TEXT("CommonName")
#define wszREGCLOCKSKEWMINUTES TEXT("ClockSkewMinutes")

#define wszREGCRLNEXTPUBLISH TEXT("CRLNextPublish")
#define wszREGCRLPERIODSTRING TEXT("CRLPeriod")
#define wszREGCRLPERIODCOUNT TEXT("CRLPeriodUnits")
#define wszREGCRLOVERLAPPERIODSTRING TEXT("CRLOverlapPeriod")
#define wszREGCRLOVERLAPPERIODCOUNT TEXT("CRLOverlapUnits")

#define wszREGCRLDELTANEXTPUBLISH TEXT("CRLDeltaNextPublish")
#define wszREGCRLDELTAPERIODSTRING TEXT("CRLDeltaPeriod")
#define wszREGCRLDELTAPERIODCOUNT TEXT("CRLDeltaPeriodUnits")
#define wszREGCRLDELTAOVERLAPPERIODSTRING TEXT("CRLDeltaOverlapPeriod")
#define wszREGCRLDELTAOVERLAPPERIODCOUNT TEXT("CRLDeltaOverlapUnits")

#define wszREGCRLPUBLICATIONURLS TEXT("CRLPublicationURLs")
#define wszREGCACERTPUBLICATIONURLS TEXT("CACertPublicationURLs")

#define wszREGCAXCHGVALIDITYPERIODSTRING TEXT("CAXchgValidityPeriod")
#define wszREGCAXCHGVALIDITYPERIODCOUNT TEXT("CAXchgValidityPeriodUnits")
#define wszREGCAXCHGOVERLAPPERIODSTRING TEXT("CAXchgOverlapPeriod")
#define wszREGCAXCHGOVERLAPPERIODCOUNT TEXT("CAXchgOverlapPeriodUnits")

#define wszREGCRLPATH_OLD TEXT("CRLPath")
#define wszREGCRLEDITFLAGS TEXT("CRLEditFlags")
#define wszREGCRLFLAGS TEXT("CRLFlags")
#define wszREGCRLATTEMPTREPUBLISH TEXT("CRLAttemptRepublish")
#define wszREGENABLED TEXT("Enabled")
#define wszREGFORCETELETEX TEXT("ForceTeletex")
#define wszREGLOGLEVEL TEXT("LogLevel")
#define wszREGHIGHSERIAL TEXT("HighSerial")
#define wszREGPOLICYFLAGS TEXT("PolicyFlags")
#define wszREGNAMESEPARATOR TEXT("SubjectNameSeparator")
#define wszREGSUBJECTTEMPLATE TEXT("SubjectTemplate")
#define wszREGCAUSEDS TEXT("UseDS")
#define wszREGVALIDITYPERIODSTRING TEXT("ValidityPeriod")
#define wszREGVALIDITYPERIODCOUNT TEXT("ValidityPeriodUnits")
#define wszREGPARENTCAMACHINE TEXT("ParentCAMachine")
#define wszREGPARENTCANAME TEXT("ParentCAName")
#define wszREGREQUESTFILENAME TEXT("RequestFileName")
#define wszREGREQUESTID TEXT("RequestId")
#define wszREGREQUESTKEYCONTAINER TEXT("RequestKeyContainer")
#define wszREGREQUESTKEYINDEX TEXT("RequestKeyIndex")
#define wszREGCASERVERNAME TEXT("CAServerName")
#define wszREGCACERTFILENAME TEXT("CACertFileName")
#define wszREGCASECURITY TEXT("Security")
#define wszREGAUDITFILTER TEXT("AuditFilter")
#define wszREGOFFICERRIGHTS TEXT("OfficerRights")
#define wszREGMAXINCOMINGMESSAGESIZE TEXT("MaxIncomingMessageSize")
#define wszREGMAXINCOMINGALLOCSIZE TEXT("MaxIncomingAllocSize")
#define wszREGROLESEPARATIONENABLED TEXT("RoleSeparationEnabled")
#define wszREGALTERNATEPUBLISHDOMAINS TEXT("AlternatePublishDomains")

#define wszREGSETUPSTATUS TEXT("SetupStatus")
#define wszREGINTERFACEFLAGS TEXT("InterfaceFlags")
#define wszREGDSCONFIGDN TEXT("DSConfigDN")
#define wszREGDSDOMAINDN TEXT("DSDomainDN")
#define wszREGVIEWAGEMINUTES TEXT("ViewAgeMinutes")
#define wszREGVIEWIDLEMINUTES TEXT("ViewIdleMinutes")

#define wszCRTFILENAMEEXT TEXT(".crt")
#define wszPFXFILENAMEEXT TEXT(".p12")
#define wszDATFILENAMEEXT TEXT(".dat")
#define wszLOGFILENAMEEXT TEXT(".log")
#define wszDBFILENAMEEXT TEXT(".edb")
#define szDBBASENAMEPARM "edb"
#define wszDBBASENAMEPARM TEXT(szDBBASENAMEPARM)
#define wszLOGPATH TEXT("CertLog")
#define wszDBBACKUPSUBDIR TEXT("DataBase")
#define wszDBBACKUPCERTBACKDAT TEXT("certbkxp.dat")

#ifndef __ENUM_CATYPES__
#define __ENUM_CATYPES__

typedef enum {
  ENUM_ENTERPRISE_ROOTCA = 0,ENUM_ENTERPRISE_SUBCA = 1,ENUM_STANDALONE_ROOTCA = 3,ENUM_STANDALONE_SUBCA = 4,ENUM_UNKNOWN_CA = 5,
} ENUM_CATYPES;

typedef struct _CAINFO {
  DWORD cbSize;
  ENUM_CATYPES CAType;
  DWORD cCASignatureCerts;
  DWORD cCAExchangeCerts;
  DWORD cExitModules;
  LONG lPropIdMax;
  LONG lRoleSeparationEnabled;
  DWORD cKRACertUsedCount;
  DWORD cKRACertCount;
  DWORD fAdvancedServer;
} CAINFO;
#endif

#define CCLOCKSKEWMINUTESDEFAULT 10
#define CVIEWAGEMINUTESDEFAULT 16
#define CVIEWIDLEMINUTESDEFAULT (CVIEWAGEMINUTESDEFAULT / 2)
#define dwVALIDITYPERIODCOUNTDEFAULT_ROOT 5
#define dwVALIDITYPERIODCOUNTDEFAULT_ENTERPRISE 2
#define dwVALIDITYPERIODCOUNTDEFAULT_STANDALONE 1
#define dwVALIDITYPERIODENUMDEFAULT ENUM_PERIOD_YEARS
#define wszVALIDITYPERIODSTRINGDEFAULT wszPERIODYEARS
#define dwCAXCHGVALIDITYPERIODCOUNTDEFAULT 1
#define dwCAXCHGVALIDITYPERIODENUMDEFAULT ENUM_PERIOD_WEEKS
#define wszCAXCHGVALIDITYPERIODSTRINGDEFAULT wszPERIODWEEKS
#define dwCAXCHGOVERLAPPERIODCOUNTDEFAULT 1
#define dwCAXCHGOVERLAPPERIODENUMDEFAULT ENUM_PERIOD_DAYS
#define wszCAXCHGOVERLAPPERIODSTRINGDEFAULT wszPERIODDAYS
#define dwCRLPERIODCOUNTDEFAULT 1
#define wszCRLPERIODSTRINGDEFAULT wszPERIODWEEKS
#define dwCRLOVERLAPPERIODCOUNTDEFAULT 0
#define wszCRLOVERLAPPERIODSTRINGDEFAULT wszPERIODHOURS
#define dwCRLDELTAPERIODCOUNTDEFAULT 1
#define wszCRLDELTAPERIODSTRINGDEFAULT wszPERIODDAYS
#define dwCRLDELTAOVERLAPPERIODCOUNTDEFAULT 0
#define wszCRLDELTAOVERLAPPERIODSTRINGDEFAULT wszPERIODMINUTES

#define CERTLOG_MINIMAL (DWORD) 0
#define CERTLOG_TERSE (DWORD) 1
#define CERTLOG_ERROR (DWORD) 2
#define CERTLOG_WARNING (DWORD) 3
#define CERTLOG_VERBOSE (DWORD) 4
#define CERTLOG_EXHAUSTIVE (DWORD) 5

#define SETUP_SERVER_FLAG 0x00000001
#define SETUP_CLIENT_FLAG 0x00000002
#define SETUP_SUSPEND_FLAG 0x00000004
#define SETUP_REQUEST_FLAG 0x00000008
#define SETUP_ONLINE_FLAG 0x00000010
#define SETUP_DENIED_FLAG 0x00000020
#define SETUP_CREATEDB_FLAG 0x00000040
#define SETUP_ATTEMPT_VROOT_CREATE 0x00000080
#define SETUP_FORCECRL_FLAG 0x00000100
#define SETUP_UPDATE_CAOBJECT_SVRTYPE 0x00000200
#define SETUP_SERVER_UPGRADED_FLAG 0x00000400
#define SETUP_W2K_SECURITY_NOT_UPGRADED_FLAG 0x00000800
#define SETUP_SECURITY_CHANGED 0x00001000

#define SETUP_DCOM_SECURITY_UPDATED_FLAG 0x00002000

#define CRLF_DELTA_USE_OLDEST_UNEXPIRED_BASE 0x00000001
#define CRLF_DELETE_EXPIRED_CRLS 0x00000002
#define CRLF_CRLNUMBER_CRITICAL 0x00000004
#define CRLF_REVCHECK_IGNORE_OFFLINE 0x00000008
#define CRLF_IGNORE_INVALID_POLICIES 0x00000010
#define CRLF_REBUILD_MODIFIED_SUBJECT_ONLY 0x00000020
#define CRLF_SAVE_FAILED_CERTS 0x00000040
#define CRLF_IGNORE_UNKNOWN_CMC_ATTRIBUTES 0x00000080
#define CRLF_IGNORE_CROSS_CERT_TRUST_ERROR 0x00000100
#define CRLF_PUBLISH_EXPIRED_CERT_CRLS 0x00000200
#define CRLF_ENFORCE_ENROLLMENT_AGENT 0x00000400
#define CRLF_DISABLE_RDN_REORDER 0x00000800
#define CRLF_DISABLE_ROOT_CROSS_CERTS 0x00001000
#define CRLF_LOG_FULL_RESPONSE 0x00002000
#define CRLF_USE_XCHG_CERT_TEMPLATE 0x00004000
#define CRLF_USE_CROSS_CERT_TEMPLATE 0x00008000
#define CRLF_ALLOW_REQUEST_ATTRIBUTE_SUBJECT 0x00010000
#define CRLF_REVCHECK_IGNORE_NOREVCHECK 0x00020000
#define CRLF_PRESERVE_EXPIRED_CA_CERTS 0x00040000
#define CRLF_PRESERVE_REVOKED_CA_CERTS 0x00080000

#define KRAF_ENABLEFOREIGN 0x00000001
#define KRAF_SAVEBADREQUESTKEY 0x00000002
#define KRAF_ENABLEARCHIVEALL 0x00000004

#define IF_LOCKICERTREQUEST 0x00000001
#define IF_NOREMOTEICERTREQUEST 0x00000002
#define IF_NOLOCALICERTREQUEST 0x00000004
#define IF_NORPCICERTREQUEST 0x00000008
#define IF_NOREMOTEICERTADMIN 0x00000010
#define IF_NOLOCALICERTADMIN 0x00000020
#define IF_NOREMOTEICERTADMINBACKUP 0x00000040
#define IF_NOLOCALICERTADMINBACKUP 0x00000080
#define IF_NOSNAPSHOTBACKUP 0x00000100
#define IF_ENFORCEENCRYPTICERTREQUEST 0x00000200
#define IF_ENFORCEENCRYPTICERTADMIN 0x00000400
#define IF_ENABLEEXITKEYRETRIEVAL 0x00000800
#define IF_ENABLEADMINASAUDITOR 0x00001000
#define IF_DEFAULT (IF_NOREMOTEICERTADMINBACKUP)

#define CSURL_SERVERPUBLISH 0x00000001
#define CSURL_ADDTOCERTCDP 0x00000002
#define CSURL_ADDTOFRESHESTCRL 0x00000004
#define CSURL_ADDTOCRLCDP 0x00000008
#define CSURL_PUBLISHRETRY 0x00000010
#define CSURL_ADDTOCERTOCSP 0x00000020
#define CSURL_SERVERPUBLISHDELTA 0x00000040

#define wszREGKEYCSP TEXT("CSP")
#define wszREGKEYENCRYPTIONCSP TEXT("EncryptionCSP")
#define wszREGKEYEXITMODULES TEXT("ExitModules")
#define wszREGKEYPOLICYMODULES TEXT("PolicyModules")
#define wszSECUREDATTRIBUTES TEXT("SignedAttributes")
#define wszzDEFAULTSIGNEDATTRIBUTES TEXT("RequesterName\0")
#define wszREGBACKUPLOGDIRECTORY TEXT("BackupLogDirectory")
#define wszREGCHECKPOINTFILE TEXT("CheckPointFile")
#define wszREGHIGHLOGNUMBER TEXT("HighLogNumber")
#define wszREGLOWLOGNUMBER TEXT("LowLogNumber")
#define wszREGLOGPATH TEXT("LogPath")
#define wszREGRESTOREMAPCOUNT TEXT("RestoreMapCount")
#define wszREGRESTOREMAP TEXT("RestoreMap")
#define wszREGDATABASERECOVERED TEXT("DatabaseRecovered")
#define wszREGRESTORESTATUS TEXT("RestoreStatus")
#define wszREGB2ICERTMANAGEMODULE TEXT("ICertManageModule")
#define wszREGSP4DEFAULTCONFIGURATION TEXT("DefaultConfiguration")
#define wszREGSP4KEYSETNAME TEXT("KeySetName")
#define wszREGSP4SUBJECTNAMESEPARATOR TEXT("SubjectNameSeparator")
#define wszREGSP4NAMES TEXT("Names")
#define wszREGSP4QUERIES TEXT("Queries")
#define wszREGNETSCAPECERTTYPE TEXT("NetscapeCertType")
#define wszNETSCAPEREVOCATIONTYPE TEXT("Netscape")
#define wszREGPROVIDERTYPE TEXT("ProviderType")
#define wszREGPROVIDER TEXT("Provider")
#define wszHASHALGORITHM TEXT("HashAlgorithm")
#define wszENCRYPTIONALGORITHM TEXT("EncryptionAlgorithm")
#define wszMACHINEKEYSET TEXT("MachineKeyset")
#define wszREGKEYSIZE TEXT("KeySize")
#define szNAMESEPARATORDEFAULT "\n"
#define wszNAMESEPARATORDEFAULT TEXT(szNAMESEPARATORDEFAULT)
#define wszPERIODYEARS TEXT("Years")
#define wszPERIODMONTHS TEXT("Months")
#define wszPERIODWEEKS TEXT("Weeks")
#define wszPERIODDAYS TEXT("Days")
#define wszPERIODHOURS TEXT("Hours")
#define wszPERIODMINUTES TEXT("Minutes")
#define wszPERIODSECONDS TEXT("Seconds")
#define wszREGISSUERCERTURLFLAGS TEXT("IssuerCertURLFlags")
#define wszREGEDITFLAGS TEXT("EditFlags")
#define wszREGUPNMAP TEXT("UPNMap")
#define wszREGSUBJECTALTNAME TEXT("SubjectAltName")
#define wszREGSUBJECTALTNAME2 TEXT("SubjectAltName2")
#define wszREGREQUESTDISPOSITION TEXT("RequestDisposition")
#define wszREGCAPATHLENGTH TEXT("CAPathLength")
#define wszREGREVOCATIONTYPE TEXT("RevocationType")
#define wszREGLDAPREVOCATIONCRLURL_OLD TEXT("LDAPRevocationCRLURL")
#define wszREGREVOCATIONCRLURL_OLD TEXT("RevocationCRLURL")
#define wszREGFTPREVOCATIONCRLURL_OLD TEXT("FTPRevocationCRLURL")
#define wszREGFILEREVOCATIONCRLURL_OLD TEXT("FileRevocationCRLURL")
#define wszREGREVOCATIONURL TEXT("RevocationURL")
#define wszREGLDAPISSUERCERTURL_OLD TEXT("LDAPIssuerCertURL")
#define wszREGISSUERCERTURL_OLD TEXT("IssuerCertURL")
#define wszREGFTPISSUERCERTURL_OLD TEXT("FTPIssuerCertURL")
#define wszREGFILEISSUERCERTURL_OLD TEXT("FileIssuerCertURL")
#define wszREGENABLEREQUESTEXTENSIONLIST TEXT("EnableRequestExtensionList")
#define wszREGENABLEENROLLEEREQUESTEXTENSIONLIST TEXT("EnableEnrolleeRequestExtensionList")
#define wszREGDISABLEEXTENSIONLIST TEXT("DisableExtensionList")
#define wszREGDEFAULTSMIME TEXT("DefaultSMIME")

#define CAPATHLENGTH_INFINITE 0xffffffff

#define REQDISP_PENDING 0x00000000
#define REQDISP_ISSUE 0x00000001
#define REQDISP_DENY 0x00000002
#define REQDISP_USEREQUESTATTRIBUTE 0x00000003
#define REQDISP_MASK 0x000000ff
#define REQDISP_PENDINGFIRST 0x00000100
#define REQDISP_DEFAULT_STANDALONE (REQDISP_PENDINGFIRST | REQDISP_ISSUE)
#define REQDISP_DEFAULT_ENTERPRISE (REQDISP_ISSUE)

#define REVEXT_CDPLDAPURL_OLD 0x00000001
#define REVEXT_CDPHTTPURL_OLD 0x00000002
#define REVEXT_CDPFTPURL_OLD 0x00000004
#define REVEXT_CDPFILEURL_OLD 0x00000008
#define REVEXT_CDPURLMASK_OLD 0x000000ff
#define REVEXT_CDPENABLE 0x00000100
#define REVEXT_ASPENABLE 0x00000200

#define REVEXT_DEFAULT_NODS (REVEXT_CDPENABLE)
#define REVEXT_DEFAULT_DS (REVEXT_CDPENABLE)

#define ISSCERT_LDAPURL_OLD 0x00000001
#define ISSCERT_HTTPURL_OLD 0x00000002
#define ISSCERT_FTPURL_OLD 0x00000004
#define ISSCERT_FILEURL_OLD 0x00000008
#define ISSCERT_URLMASK_OLD 0x000000ff
#define ISSCERT_ENABLE 0x00000100

#define ISSCERT_DEFAULT_NODS (ISSCERT_ENABLE)
#define ISSCERT_DEFAULT_DS (ISSCERT_ENABLE)

#define EDITF_ENABLEREQUESTEXTENSIONS 0x00000001
#define EDITF_REQUESTEXTENSIONLIST 0x00000002
#define EDITF_DISABLEEXTENSIONLIST 0x00000004
#define EDITF_ADDOLDKEYUSAGE 0x00000008
#define EDITF_ADDOLDCERTTYPE 0x00000010
#define EDITF_ATTRIBUTEENDDATE 0x00000020
#define EDITF_BASICCONSTRAINTSCRITICAL 0x00000040
#define EDITF_BASICCONSTRAINTSCA 0x00000080
#define EDITF_ENABLEAKIKEYID 0x00000100
#define EDITF_ATTRIBUTECA 0x00000200
#define EDITF_IGNOREREQUESTERGROUP 0x00000400
#define EDITF_ENABLEAKIISSUERNAME 0x00000800
#define EDITF_ENABLEAKIISSUERSERIAL 0x00001000
#define EDITF_ENABLEAKICRITICAL 0x00002000
#define EDITF_SERVERUPGRADED 0x00004000
#define EDITF_ATTRIBUTEEKU 0x00008000
#define EDITF_ENABLEDEFAULTSMIME 0x00010000
#define EDITF_EMAILOPTIONAL 0x00020000
#define EDITF_ATTRIBUTESUBJECTALTNAME2 0x00040000
#define EDITF_ENABLELDAPREFERRALS 0x00080000
#define EDITF_ENABLECHASECLIENTDC 0x00100000
#define EDITF_AUDITCERTTEMPLATELOAD 0x00200000
#define EDITF_DISABLEOLDOSCNUPN 0x00400000
#define EDITF_DISABLELDAPPACKAGELIST 0x00800000
#define EDITF_ENABLEUPNMAP 0x01000000

#define EDITF_DEFAULT_STANDALONE (EDITF_REQUESTEXTENSIONLIST | EDITF_DISABLEEXTENSIONLIST | EDITF_ADDOLDKEYUSAGE | EDITF_ATTRIBUTEENDDATE | EDITF_BASICCONSTRAINTSCRITICAL | EDITF_BASICCONSTRAINTSCA | EDITF_ENABLEAKIKEYID | EDITF_ATTRIBUTECA | EDITF_ATTRIBUTEEKU)
#define EDITF_DEFAULT_ENTERPRISE (EDITF_REQUESTEXTENSIONLIST | EDITF_DISABLEEXTENSIONLIST | EDITF_ADDOLDKEYUSAGE | EDITF_BASICCONSTRAINTSCRITICAL | EDITF_ENABLEAKIKEYID | EDITF_ENABLEDEFAULTSMIME | EDITF_ENABLECHASECLIENTDC)

#define wszREGLDAPREVOCATIONDN_OLD TEXT("LDAPRevocationDN")
#define wszREGLDAPREVOCATIONDNTEMPLATE_OLD TEXT("LDAPRevocationDNTemplate")
#define wszCRLPUBLISHRETRYCOUNT TEXT("CRLPublishRetryCount")
#define wszREGCERTPUBLISHFLAGS TEXT("PublishCertFlags")

#define EXITPUB_FILE 0x00000001
#define EXITPUB_ACTIVEDIRECTORY 0x00000002
#define EXITPUB_REMOVEOLDCERTS 0x00000010

#define EXITPUB_DEFAULT_ENTERPRISE EXITPUB_ACTIVEDIRECTORY

#define EXITPUB_DEFAULT_STANDALONE EXITPUB_FILE

#define wszCLASS_CERTADMIN TEXT("CertificateAuthority.Admin")
#define wszCLASS_CERTCONFIG TEXT("CertificateAuthority.Config")
#define wszCLASS_CERTGETCONFIG TEXT("CertificateAuthority.GetConfig")
#define wszCLASS_CERTENCODE TEXT("CertificateAuthority.Encode")
#define wszCLASS_CERTREQUEST TEXT("CertificateAuthority.Request")
#define wszCLASS_CERTSERVEREXIT TEXT("CertificateAuthority.ServerExit")
#define wszCLASS_CERTSERVERPOLICY TEXT("CertificateAuthority.ServerPolicy")
#define wszCLASS_CERTVIEW TEXT("CertificateAuthority.View")
#define wszMICROSOFTCERTMODULE_PREFIX TEXT("CertificateAuthority_MicrosoftDefault")
#define wszCERTMANAGE_SUFFIX TEXT("Manage")
#define wszCERTEXITMODULE_POSTFIX TEXT(".Exit")
#define wszCERTMANAGEEXIT_POSTFIX wszCERTEXITMODULE_POSTFIX wszCERTMANAGE_SUFFIX
#define wszCERTPOLICYMODULE_POSTFIX TEXT(".Policy")
#define wszCERTMANAGEPOLICY_POSTFIX wszCERTPOLICYMODULE_POSTFIX wszCERTMANAGE_SUFFIX
#define wszCLASS_CERTMANAGEEXITMODULE wszMICROSOFTCERTMODULE_PREFIX wszCERTMANAGEEXIT_POSTFIX
#define wszCLASS_CERTMANAGEPOLICYMODULE wszMICROSOFTCERTMODULE_PREFIX wszCERTMANAGEPOLICY_POSTFIX
#define wszCLASS_CERTEXIT wszMICROSOFTCERTMODULE_PREFIX wszCERTEXITMODULE_POSTFIX
#define wszCLASS_CERTPOLICY wszMICROSOFTCERTMODULE_PREFIX wszCERTPOLICYMODULE_POSTFIX
#define wszCAPOLICYFILE L"CAPolicy.inf"
#define wszINFSECTION_CDP L"CRLDistributionPoint"
#define wszINFSECTION_AIA L"AuthorityInformationAccess"
#define wszINFSECTION_EKU L"EnhancedKeyUsageExtension"
#define wszINFSECTION_CCDP L"CrossCertificateDistributionPointsExtension"
#define wszINFSECTION_CERTSERVER L"certsrv_server"
#define wszINFKEY_RENEWALKEYLENGTH L"RenewalKeyLength"
#define wszINFKEY_RENEWALVALIDITYPERIODSTRING L"RenewalValidityPeriod"
#define wszINFKEY_RENEWALVALIDITYPERIODCOUNT L"RenewalValidityPeriodUnits"
#define wszINFKEY_UTF8 L"UTF8"
#define wszINFKEY_CRLPERIODSTRING wszREGCRLPERIODSTRING
#define wszINFKEY_CRLPERIODCOUNT wszREGCRLPERIODCOUNT
#define wszINFKEY_CRLDELTAPERIODSTRING wszREGCRLDELTAPERIODSTRING
#define wszINFKEY_CRLDELTAPERIODCOUNT wszREGCRLDELTAPERIODCOUNT
#define wszINFKEY_LOADDEFAULTTEMPLATES L"LoadDefaultTemplates"
#define wszINFKEY_ENABLEKEYCOUNTING L"EnableKeyCounting"
#define wszINFKEY_FORCEUTF8 L"FORCEUTF8"
#define wszINFKEY_CRITICAL L"Critical"
#define wszINFKEY_EMPTY L"Empty"
#define wszINFKEY_CCDPSYNCDELTATIME L"SyncDeltaTime"
#define wszINFSECTION_CAPOLICY L"CAPolicy"
#define wszINFSECTION_POLICYSTATEMENT L"PolicyStatementExtension"
#define wszINFSECTION_APPLICATIONPOLICYSTATEMENT L"ApplicationPolicyStatementExtension"
#define wszINFKEY_POLICIES L"Policies"
#define wszINFKEY_OID L"OID"
#define wszINFKEY_NOTICE L"Notice"
#define wszINFSECTION_REQUESTATTRIBUTES L"RequestAttributes"
#define wszINFSECTION_NAMECONSTRAINTS L"NameConstraintsExtension"
#define wszINFKEY_INCLUDE L"Include"
#define wszINFKEY_EXCLUDE L"Exclude"
#define wszINFKEY_UPN L"UPN"
#define wszINFKEY_EMAIL L"EMail"
#define wszINFKEY_DNS L"DNS"
#define wszINFKEY_DIRECTORYNAME L"DirectoryName"
#define wszINFKEY_URL L"URL"
#define wszINFKEY_IPADDRESS L"IPAddress"
#define wszINFKEY_REGISTEREDID L"RegisteredId"
#define wszINFKEY_OTHERNAME L"OtherName"
#define wszINFSECTION_POLICYMAPPINGS L"PolicyMappingsExtension"
#define wszINFSECTION_APPLICATIONPOLICYMAPPINGS L"ApplicationPolicyMappingsExtension"
#define wszINFSECTION_POLICYCONSTRAINTS L"PolicyConstraintsExtension"
#define wszINFSECTION_APPLICATIONPOLICYCONSTRAINTS L"ApplicationPolicyConstraintsExtension"
#define wszINFKEY_REQUIREEXPLICITPOLICY L"RequireExplicitPolicy"
#define wszINFKEY_INHIBITPOLICYMAPPING L"InhibitPolicyMapping"
#define wszINFSECTION_BASICCONSTRAINTS L"BasicConstraintsExtension"
#define wszINFKEY_PATHLENGTH L"PathLength"
#define wszREGEXITSMTPKEY L"SMTP"
#define wszREGEXITSMTPTEMPLATES L"Templates"
#define wszREGEXITSMTPEVENTFILTER L"EventFilter"
#define wszREGEXITSMTPSERVER L"SMTPServer"
#define wszREGEXITSMTPAUTHENTICATE L"SMTPAuthenticate"
#define wszREGEXITDENIEDKEY L"Denied"
#define wszREGEXITISSUEDKEY L"Issued"
#define wszREGEXITPENDINGKEY L"Pending"
#define wszREGEXITREVOKEDKEY L"Revoked"
#define wszREGEXITCRLISSUEDKEY L"CRLIssued"
#define wszREGEXITSHUTDOWNKEY L"Shutdown"
#define wszREGEXITSTARTUPKEY L"Startup"
#define wszREGEXITSMTPFROM L"From"
#define wszREGEXITSMTPTO L"To"
#define wszREGEXITSMTPCC L"Cc"
#define wszREGEXITTITLEFORMAT L"TitleFormat"
#define wszREGEXITTITLEARG L"TitleArg"
#define wszREGEXITBODYFORMAT L"BodyFormat"
#define wszREGEXITBODYARG L"BodyArg"
#define wszREGEXITPROPNOTFOUND L"???"
#define wszPROPDISTINGUISHEDNAME TEXT("DistinguishedName")
#define wszPROPRAWNAME TEXT("RawName")
#define wszPROPCOUNTRY TEXT("Country")
#define wszPROPORGANIZATION TEXT("Organization")
#define wszPROPORGUNIT TEXT("OrgUnit")
#define wszPROPCOMMONNAME TEXT("CommonName")
#define wszPROPLOCALITY TEXT("Locality")
#define wszPROPSTATE TEXT("State")
#define wszPROPTITLE TEXT("Title")
#define wszPROPGIVENNAME TEXT("GivenName")
#define wszPROPINITIALS TEXT("Initials")
#define wszPROPSURNAME TEXT("SurName")
#define wszPROPDOMAINCOMPONENT TEXT("DomainComponent")
#define wszPROPEMAIL TEXT("EMail")
#define wszPROPSTREETADDRESS TEXT("StreetAddress")
#define wszPROPUNSTRUCTUREDNAME TEXT("UnstructuredName")
#define wszPROPUNSTRUCTUREDADDRESS TEXT("UnstructuredAddress")
#define wszPROPDEVICESERIALNUMBER TEXT("DeviceSerialNumber")
#define wszPROPSUBJECTDOT TEXT("Subject.")
#define wszPROPSUBJECTDISTINGUISHEDNAME wszPROPSUBJECTDOT wszPROPDISTINGUISHEDNAME
#define wszPROPSUBJECTRAWNAME wszPROPSUBJECTDOT wszPROPRAWNAME
#define wszPROPSUBJECTCOUNTRY wszPROPSUBJECTDOT wszPROPCOUNTRY
#define wszPROPSUBJECTORGANIZATION wszPROPSUBJECTDOT wszPROPORGANIZATION
#define wszPROPSUBJECTORGUNIT wszPROPSUBJECTDOT wszPROPORGUNIT
#define wszPROPSUBJECTCOMMONNAME wszPROPSUBJECTDOT wszPROPCOMMONNAME
#define wszPROPSUBJECTLOCALITY wszPROPSUBJECTDOT wszPROPLOCALITY
#define wszPROPSUBJECTSTATE wszPROPSUBJECTDOT wszPROPSTATE
#define wszPROPSUBJECTTITLE wszPROPSUBJECTDOT wszPROPTITLE
#define wszPROPSUBJECTGIVENNAME wszPROPSUBJECTDOT wszPROPGIVENNAME
#define wszPROPSUBJECTINITIALS wszPROPSUBJECTDOT wszPROPINITIALS
#define wszPROPSUBJECTSURNAME wszPROPSUBJECTDOT wszPROPSURNAME
#define wszPROPSUBJECTDOMAINCOMPONENT wszPROPSUBJECTDOT wszPROPDOMAINCOMPONENT
#define wszPROPSUBJECTEMAIL wszPROPSUBJECTDOT wszPROPEMAIL
#define wszPROPSUBJECTSTREETADDRESS wszPROPSUBJECTDOT wszPROPSTREETADDRESS
#define wszPROPSUBJECTUNSTRUCTUREDNAME wszPROPSUBJECTDOT wszPROPUNSTRUCTUREDNAME
#define wszPROPSUBJECTUNSTRUCTUREDADDRESS wszPROPSUBJECTDOT wszPROPUNSTRUCTUREDADDRESS
#define wszPROPSUBJECTDEVICESERIALNUMBER wszPROPSUBJECTDOT wszPROPDEVICESERIALNUMBER
#define wszPROPREQUESTDOT TEXT("Request.")
#define wszPROPREQUESTREQUESTID TEXT("RequestID")
#define wszPROPREQUESTRAWREQUEST TEXT("RawRequest")
#define wszPROPREQUESTRAWARCHIVEDKEY TEXT("RawArchivedKey")
#define wszPROPREQUESTARCHIVEDKEY TEXT("ArchivedKey")
#define wszPROPREQUESTKEYRECOVERYHASHES TEXT("KeyRecoveryHashes")
#define wszPROPREQUESTRAWOLDCERTIFICATE TEXT("RawOldCertificate")
#define wszPROPREQUESTATTRIBUTES TEXT("RequestAttributes")
#define wszPROPREQUESTTYPE TEXT("RequestType")
#define wszPROPREQUESTFLAGS TEXT("RequestFlags")
#define wszPROPREQUESTSTATUSCODE TEXT("StatusCode")
#define wszPROPREQUESTDISPOSITION TEXT("Disposition")
#define wszPROPREQUESTDISPOSITIONMESSAGE TEXT("DispositionMessage")
#define wszPROPREQUESTSUBMITTEDWHEN TEXT("SubmittedWhen")
#define wszPROPREQUESTRESOLVEDWHEN TEXT("ResolvedWhen")
#define wszPROPREQUESTREVOKEDWHEN TEXT("RevokedWhen")
#define wszPROPREQUESTREVOKEDEFFECTIVEWHEN TEXT("RevokedEffectiveWhen")
#define wszPROPREQUESTREVOKEDREASON TEXT("RevokedReason")
#define wszPROPREQUESTERNAME TEXT("RequesterName")
#define wszPROPCALLERNAME TEXT("CallerName")
#define wszPROPSIGNERPOLICIES TEXT("SignerPolicies")
#define wszPROPSIGNERAPPLICATIONPOLICIES TEXT("SignerApplicationPolicies")
#define wszPROPOFFICER TEXT("Officer")
#define wszPROPCHALLENGE TEXT("Challenge")
#define wszPROPEXPECTEDCHALLENGE TEXT("ExpectedChallenge")
#define wszPROPDISPOSITION TEXT("Disposition")
#define wszPROPDISPOSITIONDENY TEXT("Deny")
#define wszPROPDISPOSITIONPENDING TEXT("Pending")
#define wszPROPVALIDITYPERIODSTRING TEXT("ValidityPeriod")
#define wszPROPVALIDITYPERIODCOUNT TEXT("ValidityPeriodUnits")
#define wszPROPCERTTYPE TEXT("CertType")
#define wszPROPCERTTEMPLATE TEXT("CertificateTemplate")
#define wszPROPCERTUSAGE TEXT("CertificateUsage")
#define wszPROPREQUESTOSVERSION TEXT("RequestOSVersion")
#define wszPROPREQUESTCSPPROVIDER TEXT("RequestCSPProvider")
#define wszPROPEXITCERTFILE TEXT("CertFile")
#define wszPROPCLIENTBROWSERMACHINE TEXT("cbm")
#define wszPROPCERTCLIENTMACHINE TEXT("ccm")
#define wszPROPCLIENTDCDNS L"cdc"
#define wszPROPREQUESTMACHINEDNS L"rmd"
#define wszPROPSUBJECTALTNAME2 TEXT("san")
#define wszPROPDNS TEXT("dns")
#define wszPROPDN TEXT("dn")
#define wszPROPURL TEXT("url")
#define wszPROPIPADDRESS TEXT("ipaddress")
#define wszPROPGUID TEXT("guid")
#define wszPROPOID TEXT("oid")
#define wszPROPUPN TEXT("upn")
#define wszPROPUPN TEXT("upn")
#define szPROPASNTAG "{asn}"
#define wszPROPUTF8TAG TEXT("{utf8}")
#define wszPROPOCTETTAG TEXT("{octet}")
#define wszPROPASNTAG TEXT(szPROPASNTAG)
#define wszPROPCATYPE TEXT("CAType")
#define wszPROPSANITIZEDCANAME TEXT("SanitizedCAName")
#define wszPROPSANITIZEDSHORTNAME TEXT("SanitizedShortName")
#define wszPROPMACHINEDNSNAME TEXT("MachineDNSName")
#define wszPROPMODULEREGLOC TEXT("ModuleRegistryLocation")
#define wszPROPUSEDS TEXT("fUseDS")
#define wszPROPDELTACRLSDISABLED TEXT("fDeltaCRLsDisabled")
#define wszPROPSERVERUPGRADED TEXT("fServerUpgraded")
#define wszPROPCONFIGDN TEXT("ConfigDN")
#define wszPROPDOMAINDN TEXT("DomainDN")
#define wszPROPLOGLEVEL TEXT("LogLevel")
#define wszPROPSESSIONCOUNT TEXT("SessionCount")
#define wszPROPTEMPLATECHANGESEQUENCENUMBER TEXT("TemplateChangeSequenceNumber")
#define wszLOCALIZEDTIMEPERIODUNITS TEXT("LocalizedTimePeriodUnits")
#define wszPROPREQUESTERCAACCESS TEXT("RequesterCAAccess")
#define wszPROPUSERDN TEXT("UserDN")
#define wszPROPKEYARCHIVED TEXT("KeyArchived")
#define wszPROPCERTCOUNT TEXT("CertCount")
#define wszPROPRAWCACERTIFICATE TEXT("RawCACertificate")
#define wszPROPCERTSTATE TEXT("CertState")
#define wszPROPCERTSUFFIX TEXT("CertSuffix")
#define wszPROPRAWCRL TEXT("RawCRL")
#define wszPROPRAWDELTACRL TEXT("RawDeltaCRL")
#define wszPROPCRLINDEX TEXT("CRLIndex")
#define wszPROPCRLSTATE TEXT("CRLState")
#define wszPROPCRLSUFFIX TEXT("CRLSuffix")
#define wszPROPEVENTLOGTERSE TEXT("EventLogTerse")
#define wszPROPEVENTLOGERROR TEXT("EventLogError")
#define wszPROPEVENTLOGWARNING TEXT("EventLogWarning")
#define wszPROPEVENTLOGVERBOSE TEXT("EventLogVerbose")
#define wszPROPEVENTLOGEXHAUSTIVE TEXT("EventLogExhaustive")
#define wszPROPDCNAME TEXT("DCName")
#define wszPROPSEAUDITID TEXT("SEAuditId")
#define wszPROPSEAUDITFILTER TEXT("SEAuditFilter")
#define wszPROPCERTIFICATEREQUESTID TEXT("RequestID")
#define wszPROPRAWCERTIFICATE TEXT("RawCertificate")
#define wszPROPCERTIFICATEHASH TEXT("CertificateHash")
#define wszPROPCERTIFICATETEMPLATE TEXT("CertificateTemplate")
#define wszPROPCERTIFICATEENROLLMENTFLAGS TEXT("EnrollmentFlags")
#define wszPROPCERTIFICATEGENERALFLAGS TEXT("GeneralFlags")
#define wszPROPCERTIFICATESERIALNUMBER TEXT("SerialNumber")
#define wszPROPCERTIFICATENOTBEFOREDATE TEXT("NotBefore")
#define wszPROPCERTIFICATENOTAFTERDATE TEXT("NotAfter")
#define wszPROPCERTIFICATESUBJECTKEYIDENTIFIER TEXT("SubjectKeyIdentifier")
#define wszPROPCERTIFICATERAWPUBLICKEY TEXT("RawPublicKey")
#define wszPROPCERTIFICATEPUBLICKEYLENGTH TEXT("PublicKeyLength")
#define wszPROPCERTIFICATEPUBLICKEYALGORITHM TEXT("PublicKeyAlgorithm")
#define wszPROPCERTIFICATERAWPUBLICKEYALGORITHMPARAMETERS TEXT("RawPublicKeyAlgorithmParameters")
#define wszPROPCERTIFICATEUPN TEXT("UPN")
#define wszPROPCERTIFICATETYPE TEXT("CertificateType")
#define wszPROPCERTIFICATERAWSMIMECAPABILITIES TEXT("RawSMIMECapabilities")
#define wszPROPNAMETYPE TEXT("NameType")

#define EXTENSION_CRITICAL_FLAG 0x00000001
#define EXTENSION_DISABLE_FLAG 0x00000002
#define EXTENSION_POLICY_MASK 0x0000ffff

#define EXTENSION_ORIGIN_REQUEST 0x00010000
#define EXTENSION_ORIGIN_POLICY 0x00020000
#define EXTENSION_ORIGIN_ADMIN 0x00030000
#define EXTENSION_ORIGIN_SERVER 0x00040000
#define EXTENSION_ORIGIN_RENEWALCERT 0x00050000
#define EXTENSION_ORIGIN_IMPORTEDCERT 0x00060000
#define EXTENSION_ORIGIN_PKCS7 0x00070000
#define EXTENSION_ORIGIN_CMC 0x00080000
#define EXTENSION_ORIGIN_CACERT 0x00090000
#define EXTENSION_ORIGIN_MASK 0x000f0000

#define wszPROPEXTREQUESTID TEXT("ExtensionRequestId")
#define wszPROPEXTNAME TEXT("ExtensionName")
#define wszPROPEXTFLAGS TEXT("ExtensionFlags")
#define wszPROPEXTRAWVALUE TEXT("ExtensionRawValue")
#define wszPROPATTRIBREQUESTID TEXT("AttributeRequestId")
#define wszPROPATTRIBNAME TEXT("AttributeName")
#define wszPROPATTRIBVALUE TEXT("AttributeValue")
#define wszPROPCRLROWID TEXT("CRLRowId")
#define wszPROPCRLNUMBER TEXT("CRLNumber")
#define wszPROPCRLMINBASE TEXT("CRLMinBase")
#define wszPROPCRLNAMEID TEXT("CRLNameId")
#define wszPROPCRLCOUNT TEXT("CRLCount")
#define wszPROPCRLTHISUPDATE TEXT("CRLThisUpdate")
#define wszPROPCRLNEXTUPDATE TEXT("CRLNextUpdate")
#define wszPROPCRLTHISPUBLISH TEXT("CRLThisPublish")
#define wszPROPCRLNEXTPUBLISH TEXT("CRLNextPublish")
#define wszPROPCRLEFFECTIVE TEXT("CRLEffective")
#define wszPROPCRLPROPAGATIONCOMPLETE TEXT("CRLPropagationComplete")
#define wszPROPCRLLASTPUBLISHED TEXT("CRLLastPublished")
#define wszPROPCRLPUBLISHATTEMPTS TEXT("CRLPublishAttempts")
#define wszPROPCRLPUBLISHFLAGS TEXT("CRLPublishFlags")
#define wszPROPCRLPUBLISHSTATUSCODE TEXT("CRLPublishStatusCode")
#define wszPROPCRLPUBLISHERROR TEXT("CRLPublishError")
#define wszPROPCRLRAWCRL TEXT("CRLRawCRL")

#define CPF_BASE 0x00000001
#define CPF_DELTA 0x00000002
#define CPF_COMPLETE 0x00000004
#define CPF_SHADOW 0x00000008
#define CPF_CASTORE_ERROR 0x00000010
#define CPF_BADURL_ERROR 0x00000020
#define CPF_MANUAL 0x00000040
#define CPF_SIGNATURE_ERROR 0x00000080
#define CPF_LDAP_ERROR 0x00000100
#define CPF_FILE_ERROR 0x00000200
#define CPF_FTP_ERROR 0x00000400
#define CPF_HTTP_ERROR 0x00000800

#define PROPTYPE_LONG 0x00000001
#define PROPTYPE_DATE 0x00000002
#define PROPTYPE_BINARY 0x00000003
#define PROPTYPE_STRING 0x00000004
#define PROPTYPE_MASK 0x000000ff
#define PROPCALLER_SERVER 0x00000100
#define PROPCALLER_POLICY 0x00000200
#define PROPCALLER_EXIT 0x00000300
#define PROPCALLER_ADMIN 0x00000400
#define PROPCALLER_REQUEST 0x00000500
#define PROPCALLER_MASK 0x00000f00
#define PROPFLAGS_INDEXED 0x00010000

#define CR_FLG_FORCETELETEX 0x00000001
#define CR_FLG_RENEWAL 0x00000002
#define CR_FLG_FORCEUTF8 0x00000004
#define CR_FLG_CAXCHGCERT 0x00000008
#define CR_FLG_ENROLLONBEHALFOF 0x00000010
#define CR_FLG_SUBJECTUNMODIFIED 0x00000020
#define CR_FLG_VALIDENCRYPTEDKEYHASH 0x00000040
#define CR_FLG_CACROSSCERT 0x00000080
#define CR_FLG_ENFORCEUTF8 0x00000100
#define CR_FLG_PUBLISHERROR 0x80000000

#define DB_DISP_ACTIVE 8
#define DB_DISP_PENDING 9
#define DB_DISP_QUEUE_MAX 9
#define DB_DISP_FOREIGN 12
#define DB_DISP_CA_CERT 15
#define DB_DISP_CA_CERT_CHAIN 16
#define DB_DISP_KRA_CERT 17
#define DB_DISP_LOG_MIN 20
#define DB_DISP_ISSUED 20
#define DB_DISP_REVOKED 21
#define DB_DISP_LOG_FAILED_MIN 30
#define DB_DISP_ERROR 30
#define DB_DISP_DENIED 31

#define VR_PENDING 0
#define VR_INSTANT_OK 1
#define VR_INSTANT_BAD 2

#define wszCERT_TYPE L"RequestType"
#define wszCERT_TYPE_CLIENT L"Client"
#define wszCERT_TYPE_SERVER L"Server"
#define wszCERT_TYPE_CODESIGN L"CodeSign"
#define wszCERT_TYPE_CUSTOMER L"SetCustomer"
#define wszCERT_TYPE_MERCHANT L"SetMerchant"
#define wszCERT_TYPE_PAYMENT L"SetPayment"
#define wszCERT_VERSION L"Version"
#define wszCERT_VERSION_1 L"1"
#define wszCERT_VERSION_2 L"2"
#define wszCERT_VERSION_3 L"3"

#endif
