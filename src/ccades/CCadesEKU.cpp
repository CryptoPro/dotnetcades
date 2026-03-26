#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEKU.h"
#include "CPPCadesCPEKU.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesEKU_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPEKUObject> obj;
};

HRESULT CCadesEKU_create(CCadesEKU **result)
{
    try
    {
        CCadesEKU *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPEKUObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEKU_destroy(CCadesEKU *m)
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

HRESULT CCadesEKU_get_name(CCadesEKU *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_EKU val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Name(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEKU_put_name(CCadesEKU *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Name((CAPICOM_EKU)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEKU_get_oid(CCadesEKU *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }
        
        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_OID(sValue));
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

HRESULT CCadesEKU_put_oid(CCadesEKU *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_OID(pVal));
    }
    CCADESCATCH
    return S_OK;
}
