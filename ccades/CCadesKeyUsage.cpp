#include "stdafx.h"
#include <stdlib.h>
#include "CCadesKeyUsage.h"
#include "CPPCadesCPKeyUsage.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesKeyUsage_t
{
    boost::shared_ptr<CPPCadesCPKeyUsageObject> obj;
};

HRESULT CCadesKeyUsage_create(CCadesKeyUsage **result)
{
    try
    {
        CCadesKeyUsage *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPKeyUsageObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_destroy(CCadesKeyUsage *m)
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

HRESULT CCadesKeyUsage_get_is_present(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsPresent(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_critical(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsCritical(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_crl_sign_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsCRLSignEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_data_encipherment_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsDataEnciphermentEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_decipher_only_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsDecipherOnlyEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_digital_signature_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsDigitalSignatureEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_encipher_only_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsEncipherOnlyEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_key_agreement_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsKeyAgreementEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_key_cert_sign_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsKeyCertSignEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_key_encipherment_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsKeyEnciphermentEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesKeyUsage_get_is_non_repudation_enabled(CCadesKeyUsage *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsNonRepudiationEnabled(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}