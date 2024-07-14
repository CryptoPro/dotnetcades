#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAlgorithm.h"
#include "CPPCadesCPAlgorithm.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesAlgorithm_t
{
    boost::shared_ptr<CPPCadesCPAlgorithmObject> obj;
};

HRESULT CCadesAlgorithm_create(CCadesAlgorithm **result)
{
    try
    {
        CCadesAlgorithm *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPAlgorithmObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAlgorithm_destroy(CCadesAlgorithm *m)
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

HRESULT CCadesAlgorithm_get_name(CCadesAlgorithm *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CADESCOM_ENCRYPTION_ALGORITHM val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Name(&val));
        DWORD r = (DWORD)val;
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAlgorithm_put_name(CCadesAlgorithm *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Name((CADESCOM_ENCRYPTION_ALGORITHM)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAlgorithm_get_key_length(CCadesAlgorithm *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAPICOM_ENCRYPTION_KEY_LENGTH val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_KeyLength(&val));
        DWORD r = (DWORD)val;
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAlgorithm_put_key_length(CCadesAlgorithm *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_KeyLength((CAPICOM_ENCRYPTION_KEY_LENGTH)value));
    }
    CCADESCATCH
    return S_OK;
}
