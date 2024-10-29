#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAttribute.h"
#include "CPPCadesCPAttribute.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesAttribute_t
{
    boost::shared_ptr<CPPCadesCPAttributeObject> obj;
};
struct CCadesOID_t
{
    boost::shared_ptr<CPPCadesCPOIDObject> obj;
};

HRESULT CCadesAttribute_create(CCadesAttribute **result)
{
    try
    {
        CCadesAttribute *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPAttributeObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_destroy(CCadesAttribute *m)
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

HRESULT CCadesAttribute_get_oid(CCadesAttribute *m, CCadesOID **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPOIDObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_OID(pObj));
        CCadesOID *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesOID_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_put_oid(CCadesAttribute *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString newVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_OID(newVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_get_value(CCadesAttribute *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Value(blob));
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

HRESULT CCadesAttribute_put_value(CCadesAttribute *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob pVal((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Value(pVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_put_name(CCadesAttribute *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Name((CADESCOM_ATTRIBUTE)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_get_name(CCadesAttribute *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CADESCOM_ATTRIBUTE val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Name(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_put_value_encoding(CCadesAttribute *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_ValueEncoding((CAPICOM_ENCODING_TYPE)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttribute_get_value_encoding(CCadesAttribute *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_ENCODING_TYPE val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ValueEncoding(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}
