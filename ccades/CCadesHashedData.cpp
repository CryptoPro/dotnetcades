#include "stdafx.h"
#include <stdlib.h>
#include "CCadesHashedData.h"
#include "CPPCadesCPHashedData.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesHashedData_t
{
    boost::shared_ptr<CPPCadesCPHashedDataObject> obj;
};

HRESULT CCadesHashedData_create(CCadesHashedData **result)
{
    try
    {
        CCadesHashedData *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPHashedDataObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_destroy(CCadesHashedData *m)
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

HRESULT CCadesHashedData_put_algorithm(CCadesHashedData *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Algorithm((CAPICOM_HASH_ALGORITHM)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_get_algorithm(CCadesHashedData *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_HASH_ALGORITHM val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Algorithm(&val));
        *result = (int)val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_get_value(CCadesHashedData *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Value(sValue));
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

HRESULT CCadesHashedData_put_data_encoding(CCadesHashedData *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_DataEncoding((CADESCOM_CONTENT_ENCODING_TYPE)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_get_data_encoding(CCadesHashedData *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CADESCOM_CONTENT_ENCODING_TYPE val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_DataEncoding(&val));
        *result = (int)val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_get_key(CCadesHashedData *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Key(sValue));
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

HRESULT CCadesHashedData_put_key(CCadesHashedData *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Key(sValue));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_hash(CCadesHashedData *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Hash(sValue.GetBuffer(), sValue.GetLength()));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesHashedData_set_hash_value(CCadesHashedData *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_HashValue(sValue));
    }
    CCADESCATCH
    return S_OK;
}