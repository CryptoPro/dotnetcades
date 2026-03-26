#include "stdafx.h"
#include <stdlib.h>
#include "CCadesExtendedKeyUsage.h"
#include "CPPCadesCPExtendedKeyUsage.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesExtendedKeyUsage_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPExtendedKeyUsageObject> obj;
};
struct CCadesEKUs_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPEKUsObject> obj;
};

HRESULT CCadesExtendedKeyUsage_create(CCadesExtendedKeyUsage **result)
{
    try
    {
        CCadesExtendedKeyUsage *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPExtendedKeyUsageObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesExtendedKeyUsage_destroy(CCadesExtendedKeyUsage *m)
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

HRESULT CCadesExtendedKeyUsage_get_ekus(CCadesExtendedKeyUsage *m, CCadesEKUs **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEKUsObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_EKUs(pObj));
        CCadesEKUs *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesEKUs_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesExtendedKeyUsage_get_is_present(CCadesExtendedKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsPresent(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesExtendedKeyUsage_get_is_critical(CCadesExtendedKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsCritical(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}
