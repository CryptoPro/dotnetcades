#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCertificate.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
};
struct CCadesBasicConstraints_t
{
    boost::shared_ptr<CPPCadesCPBasicConstraintsObject> obj;
};
struct CCadesCertificateStatus_t
{
    boost::shared_ptr<CPPCadesCPCertificateStatusObject> obj;
};
struct CCadesExtendedKeyUsage_t
{
    boost::shared_ptr<CPPCadesCPExtendedKeyUsageObject> obj;
};
struct CCadesKeyUsage_t
{
    boost::shared_ptr<CPPCadesCPKeyUsageObject> obj;
};
struct CCadesPrivateKey_t
{
    boost::shared_ptr<CPPCadesCPPrivateKeyObject> obj;
};
struct CCadesPublicKey_t
{
    boost::shared_ptr<CPPCadesCPPublicKeyObject> obj;
};

HRESULT CCadesCertificate_create(CCadesCertificate **result)
{
    try
    {
        CCadesCertificate *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPCertificateObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_destroy(CCadesCertificate *m)
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

HRESULT CCadesCertificate_get_info(CCadesCertificate *m, int value, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->GetInfo((CAPICOM_CERT_INFO_TYPE)value, sValue));
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

HRESULT CCadesCertificate_has_private_key(CCadesCertificate *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->HasPrivateKey(&r));
        *result = (int)r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_is_valid(CCadesCertificate *m, CCadesCertificateStatus **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateStatusObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->IsValid(pObj));

        CCadesCertificateStatus *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesCertificateStatus_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_extended_key_usage(CCadesCertificate *m, CCadesExtendedKeyUsage **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPExtendedKeyUsageObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->ExtendedKeyUsage(pObj));

        CCadesExtendedKeyUsage *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesExtendedKeyUsage_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_key_usage(CCadesCertificate *m, CCadesKeyUsage **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPKeyUsageObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->KeyUsage(pObj));

        CCadesKeyUsage *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesKeyUsage_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_export(CCadesCertificate *m, int value, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Export((CAPICOM_ENCODING_TYPE)value, blob));
        char *buf = (char *)calloc(blob.cbData() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, blob.pbData(), blob.cbData());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_import(CCadesCertificate *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->Import(blob));
    }
    CCADESCATCH
    return S_OK;

}

HRESULT CCadesCertificate_get_thumbprint(CCadesCertificate *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Thumbprint(sValue));
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

HRESULT CCadesCertificate_get_serial_number(CCadesCertificate *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_SerialNumber(sValue));
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

HRESULT CCadesCertificate_get_subject_name(CCadesCertificate *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_SubjectName(sValue));
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

HRESULT CCadesCertificate_get_issuer_name(CCadesCertificate *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IssuerName(sValue));
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

HRESULT CCadesCertificate_get_version(CCadesCertificate *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Version(&r));
        *result = (int)r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_get_valid_to_date(CCadesCertificate *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CDateTime d;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ValidToDate(d));
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

HRESULT CCadesCertificate_get_valid_from_date(CCadesCertificate *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CDateTime d;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ValidFromDate(d));
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

HRESULT CCadesCertificate_basic_constraints(CCadesCertificate *m, CCadesBasicConstraints **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPBasicConstraintsObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->BasicConstraints(pObj));

        CCadesBasicConstraints *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesBasicConstraints_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_public_key(CCadesCertificate *m, CCadesPublicKey **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPPublicKeyObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->PublicKey(pObj));

        CCadesPublicKey *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesPublicKey_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_private_key(CCadesCertificate *m, CCadesPrivateKey **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPPrivateKeyObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->PrivateKey(pObj));

        CCadesPrivateKey *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesPrivateKey_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificate_find_private_key(CCadesCertificate *m)
{
    try
    {
        ATL_HR_ERRORCHECK_RETURN(m->obj->FindPrivateKey(CAtlString()));
    }
    CCADESCATCH
    return S_OK;
}
