#include "stdafx.h"
#include <stdlib.h>
#include "CCadesPublicKey.h"
#include "CPPCadesCPPublicKey.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesPublicKey_t
{
    boost::shared_ptr<CPPCadesCPPublicKeyObject> obj;
};
struct CCadesOID_t
{
    boost::shared_ptr<CPPCadesCPOIDObject> obj;
};
struct CCadesEncodedData_t
{
    boost::shared_ptr<CPPCadesCPEncodedDataObject> obj;
};

HRESULT CCadesPublicKey_create(CCadesPublicKey **result)
{
    try
    {
        CCadesPublicKey *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPPublicKeyObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPublicKey_destroy(CCadesPublicKey *m)
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

HRESULT CCadesPublicKey_get_algorithm(CCadesPublicKey *m, CCadesOID **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPOIDObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Algorithm(pObj));
        CCadesOID *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesOID_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPublicKey_get_encoded_key(CCadesPublicKey *m, CCadesEncodedData **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEncodedDataObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_EncodedKey(pObj));
        CCadesEncodedData *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesEncodedData_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPublicKey_get_encoded_parameters(CCadesPublicKey *m, CCadesEncodedData **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPEncodedDataObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_EncodedParameters(pObj));
        CCadesEncodedData *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesEncodedData_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesPublicKey_get_length(CCadesPublicKey *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Length(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}
