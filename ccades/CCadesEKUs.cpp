#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEKUs.h"
#include "CPPCadesCollections.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesEKUs_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPEKUsObject> obj;
};
struct CCadesEKU_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPEKUObject> obj;
};

HRESULT CCadesEKUs_create(CCadesEKUs **result)
{
    try
    {
        CCadesEKUs *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPEKUsObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEKUs_destroy(CCadesEKUs *m)
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

HRESULT CCadesEKUs_get_count(CCadesEKUs *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Count(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEKUs_get_item(CCadesEKUs *m, int value, CCadesEKU **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEKUObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Item(value, pObj));
        CCadesEKU *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesEKU_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}