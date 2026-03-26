#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCertificateStatus.h"
#include "CPPCadesCPCertificateStatus.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificateStatus_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPCertificateStatusObject> obj;
};

HRESULT CCadesCertificateStatus_create(CCadesCertificateStatus **result)
{
    try
    {
        CCadesCertificateStatus *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPCertificateStatusObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificateStatus_destroy(CCadesCertificateStatus *m)
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

HRESULT CCadesCertificateStatus_get_result(CCadesCertificateStatus *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Result(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}
