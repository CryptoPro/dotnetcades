#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSigners.h"
#include "CPPCadesCollections.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesSigners_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPSignersObject> obj;
};
struct CCadesSigner_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPSignerObject> obj;
};

HRESULT CCadesSigners_create(CCadesSigners **result)
{
    try
    {
        CCadesSigners *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPSignersObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigners_destroy(CCadesSigners *m)
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

HRESULT CCadesSigners_get_count(CCadesSigners *m, int *result)
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

HRESULT CCadesSigners_get_item(CCadesSigners *m, int value, CCadesSigner **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignerObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Item(value, pObj));
        CCadesSigner *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesSigner_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}