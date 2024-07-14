#include "stdafx.h"
#include <stdlib.h>
#include "CCadesRawSignature.h"
#include "CPPCadesRawSignature.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesRawSignature_t
{
    boost::shared_ptr<CPPCadesRawSignatureObject> obj;
};
struct CCadesHashedData_t
{
    boost::shared_ptr<CPPCadesCPHashedDataObject> obj;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
};

HRESULT CCadesRawSignature_create(CCadesRawSignature **result)
{
    try
    {
        CCadesRawSignature *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesRawSignatureObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesRawSignature_destroy(CCadesRawSignature *m)
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

HRESULT CCadesRawSignature_sign_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->SignHash(hashed->obj, signer->obj, sValue));
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

HRESULT CCadesRawSignature_verify_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->VerifyHash(hashed->obj, sValue, signer->obj));
    }
    CCADESCATCH
    return S_OK;
}
