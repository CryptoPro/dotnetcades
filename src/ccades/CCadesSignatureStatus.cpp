#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSignatureStatus.h"
#include "CPPCadesSignatureStatus.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesSignatureStatus_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesSignatureStatusObject> obj;
};

HRESULT CCadesSignatureStatus_create(CCadesSignatureStatus **result)
{
    try
    {
        CCadesSignatureStatus *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesSignatureStatusObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignatureStatus_destroy(CCadesSignatureStatus *m)
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

HRESULT CCadesSignatureStatus_is_valid(CCadesSignatureStatus *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        bool res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->IsValid(res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}