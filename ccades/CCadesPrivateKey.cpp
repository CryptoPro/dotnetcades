#include "stdafx.h"
#include <stdlib.h>
#include "CCadesPrivateKey.h"
#include "CPPCadesCPPrivateKey.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesPrivateKey_t
{
    boost::shared_ptr<CPPCadesCPPrivateKeyObject> obj;
};

HRESULT CCadesPrivateKey_create(CCadesPrivateKey **result)
{
    try
    {
        CCadesPrivateKey *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPPrivateKeyObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_destroy(CCadesPrivateKey *m)
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

HRESULT CCadesPrivateKey_change_pin(CCadesPrivateKey *m)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->ChangePin());
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_get_container_name(CCadesPrivateKey *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ContainerName(sValue));
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

HRESULT CCadesPrivateKey_get_unique_container_name(CCadesPrivateKey *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_UniqueContainerName(sValue));
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

HRESULT CCadesPrivateKey_get_provider_name(CCadesPrivateKey *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ProviderName(sValue));
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

HRESULT CCadesPrivateKey_get_provider_type(CCadesPrivateKey *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_PROV_TYPE val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ProviderType(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_get_key_spec(CCadesPrivateKey *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_KEY_SPEC val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_KeySpec(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_get_is_default_pin(CCadesPrivateKey *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsDefaultPin(res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_set_cache_pin(CCadesPrivateKey *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->set_CachePin(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_set_key_pin(CCadesPrivateKey *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA newVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->set_KeyPin(newVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPrivateKey_get_carrier_flags(CCadesPrivateKey *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_CarrierFlags(r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}