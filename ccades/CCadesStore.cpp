#include "stdafx.h"
#include <stdlib.h>
#include "CCadesStore.h"
#include "CPPCadesCPStore.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
};
struct CCadesCRL_t
{
    boost::shared_ptr<CPPCadesCPCRLObject> obj;
};
struct CCadesStore_t
{
    boost::shared_ptr<CPPCadesCPStoreObject> obj;
};

HRESULT CCadesStore_create(CCadesStore **result)
{
    try
    {
        CCadesStore *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPStoreObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_destroy(CCadesStore *m)
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

HRESULT CCadesStore_open(CCadesStore *m, int value, char* name, int mode)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringW wName(name);
        CAPICOM_STORE_OPEN_MODE mod = (CAPICOM_STORE_OPEN_MODE)mode;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Open((CADESCOM_STORE_LOCATION)value, wName, mod));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_close(CCadesStore *m)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Close());
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_add(CCadesStore *m, CCadesCertificate *obj)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj(obj->obj);
        ATL_HR_ERRORCHECK_RETURN(m->obj->Add(pObj));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_add_crl(CCadesStore *m, CCadesCRL *obj)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->AddCRL(obj->obj));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_get_certificates(CCadesStore *m, CCadesCertificates **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Certificates(pObj));

        CCadesCertificates *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesCertificates_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_get_location(CCadesStore *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CADESCOM_STORE_LOCATION val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Location(&val));
        *result = (int)val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesStore_get_name(CCadesStore *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Name(sValue));
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
