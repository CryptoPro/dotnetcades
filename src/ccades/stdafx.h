#pragma once

#define CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS
#define CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS
#define CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS
#define CERT_PARA_HAS_EXTRA_FIELDS
#define IGNORE_LEGACY_FORMAT_MESSAGE_MSG

#include "boost/shared_ptr.hpp"
#include <iostream>
#include <cstdint>

#include "CSP_WinDef.h"
#include "CSP_WinError.h"
#include <atlcrypt2.h>
#include "ocspcli_e.h"
#include "tspcli_e.h"
#include "cppcades.h"

#ifndef NS_SHARED_PTR
#define NS_SHARED_PTR boost
#endif

#ifdef MAKELANGID
#undef MAKELANGID
#endif // MAKELANGID

#define MAKELANGID(a, b) 0x409 // English U.S.

#define CCADESCATCH                                \
    catch (CAtlException & ex) { return ex.m_hr; } \
    catch (...) { return E_UNEXPECTED; }

#ifdef __cplusplus
extern "C"
{
#endif

char *CSGetErrorMessage(HRESULT err);
HRESULT FreeString(char *ptr);

#ifdef __cplusplus
}
#endif