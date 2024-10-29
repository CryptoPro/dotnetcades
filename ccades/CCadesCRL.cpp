#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCRL.h"
#include "CPPCadesCPCRL.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCRL_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPCRLObject> obj;
};

HRESULT CCadesCRL_create(CCadesCRL **result)
{
    try
    {
        CCadesCRL *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPCRLObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCRL_destroy(CCadesCRL *m)
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

HRESULT CCadesCRL_import(CCadesCRL *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob arg_value((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->Import(arg_value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCRL_export(CCadesCRL *m, int value, char **result)
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

HRESULT CCadesCRL_get_issuer_name(CCadesCRL *m, char **result)
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

HRESULT CCadesCRL_get_this_update(CCadesCRL *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CDateTime d;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ThisUpdate(d));
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

HRESULT CCadesCRL_get_next_update(CCadesCRL *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CDateTime d;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_NextUpdate(d));
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

HRESULT CCadesCRL_get_thumbprint(CCadesCRL *m, char **result)
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

HRESULT CCadesCRL_get_auth_key_id(CCadesCRL *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_AuthKeyID(sValue));
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
