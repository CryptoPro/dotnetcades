#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAttributes.h"
#include "CPPCadesCPAttributes.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesAttributes_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPAttributesObject> obj;
};
struct CCadesAttribute_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPAttributeObject> obj;
};

HRESULT CCadesAttributes_create(CCadesAttributes **result)
{
    try
    {
        CCadesAttributes *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPAttributesObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttributes_destroy(CCadesAttributes *m)
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

HRESULT CCadesAttributes_get_count(CCadesAttributes *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        long r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Count(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttributes_remove(CCadesAttributes *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Remove(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttributes_get_item(CCadesAttributes *m, int value, CCadesAttribute **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAttributeObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Item(value, pObj));
        CCadesAttribute *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesAttribute_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttributes_add(CCadesAttributes *m, CCadesAttribute *obj)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Add(obj->obj));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAttributes_clear(CCadesAttributes *m)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Clear());
    }
    CCADESCATCH
    return S_OK;
}
