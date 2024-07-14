#include "stdafx.h"
#include <stdlib.h>
#include "CCadesOID.h"
#include "CPPCadesCPOID.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesOID_t
{
    boost::shared_ptr<CPPCadesCPOIDObject> obj;
};

HRESULT CCadesOID_create(CCadesOID **result)
{
    try
    {
        CCadesOID *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPOIDObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesOID_destroy(CCadesOID *m)
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

HRESULT CCadesOID_get_value(CCadesOID *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CAtlStringA> sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Value(sValue));
        char *buf = (char *)calloc(sValue->GetLength() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, sValue->GetBuffer(), sValue->GetLength());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesOID_set_value(CCadesOID *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Value(sValue));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesOID_get_friendly_name(CCadesOID *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_FriendlyName(sValue));
        char *buf = (char *)calloc(sValue.GetLength(), sizeof(char));
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

HRESULT CCadesOID_set_friendly_name(CCadesOID *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_FriendlyName(sValue));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesOID_get_name(CCadesOID *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_OID val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Name(&val));
        *result = (int)val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesOID_set_name(CCadesOID *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Name((CAPICOM_OID)value));
    }
    CCADESCATCH
    return S_OK;
}