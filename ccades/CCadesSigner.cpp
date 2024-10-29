#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSigner.h"
#include "CPPCadesCPSigner.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesSigner_t
{
    boost::shared_ptr<CPPCadesCPSignerObject> obj;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
};
struct CCadesAttributes_t
{
    boost::shared_ptr<CPPCadesCPAttributesObject> obj;
};
struct CCadesBlobs_t
{
    boost::shared_ptr<CPPCadesCPBlobsObject> obj;
};
struct CCadesSignatureStatus_t
{
    boost::shared_ptr<CPPCadesSignatureStatusObject> obj;
};

HRESULT CCadesSigner_create(CCadesSigner **result)
{
    try
    {
        CCadesSigner *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPSignerObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_destroy(CCadesSigner *m)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }
        m->obj.reset();
        free(m);
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_authenticated_attributes2(CCadesSigner *m, CCadesAttributes **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributesObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_AuthenticatedAttributes(pObj));
        CCadesAttributes *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesAttributes_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_unauthenticated_attributes(CCadesSigner *m, CCadesAttributes **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributesObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_UnauthenticatedAttributes(pObj));
        CCadesAttributes *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesAttributes_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_certificate(CCadesSigner *m, CCadesCertificate **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Certificate(pObj));
        CCadesCertificate *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesCertificate_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_put_certificate(CCadesSigner *m, CCadesCertificate *obj)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Certificate(obj->obj));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_put_options(CCadesSigner *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Options((CAPICOM_CERTIFICATE_INCLUDE_OPTION)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_options(CCadesSigner *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_CERTIFICATE_INCLUDE_OPTION val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Options(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_crls(CCadesSigner *m, CCadesBlobs **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBlobsObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_CRLs(pObj));
        CCadesBlobs *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesBlobs_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_ocsp_responses(CCadesSigner *m, CCadesBlobs **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBlobsObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_OCSPResponses(pObj));
        CCadesBlobs *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesBlobs_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_put_tsa_address(CCadesSigner *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA newVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_TSAAddress(newVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_tsa_address(CCadesSigner *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_TSAAddress(sValue));
        char *buf = (char *)calloc(sValue.GetLength() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_signature_timestamp_time(CCadesSigner *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CDateTime d;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_SignatureTimeStampTime(d));
        CAtlString sValue = d.tostring().c_str();
        char *buf = (char *)calloc(sValue.GetLength() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_signing_time(CCadesSigner *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CDateTime d;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_SigningTime(d));
        CAtlString sValue = d.tostring().c_str();
        char *buf = (char *)calloc(sValue.GetLength() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_put_key_pin(CCadesSigner *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA newVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_KeyPin(newVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_signature_status(CCadesSigner *m, CCadesSignatureStatus **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesSignatureStatusObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_SignatureStatus(pObj));
        CCadesSignatureStatus *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesSignatureStatus_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_put_check_certificate(CCadesSigner *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_CheckCertificate(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigner_get_check_certificate(CCadesSigner *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_CheckCertificate(res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}
