#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSignedXML.h"
#include "CPPCadesSignedXML.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesSignedXML_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesSignedXMLObject> obj;
};
struct CCadesSigners_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPSignersObject> obj;
};
struct CCadesSigner_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPSignerObject> obj;
};

HRESULT CCadesSignedXML_create(CCadesSignedXML **result)
{
    try
    {
        CCadesSignedXML *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesSignedXMLObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedXML_destroy(CCadesSignedXML *m)
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

HRESULT CCadesSignedXML_get_signers(CCadesSignedXML *m, CCadesSigners **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignersObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Signers(pObj));
        CCadesSigners *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesSigners_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedXML_put_content(CCadesSignedXML *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Content(sValue));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedXML_get_content(CCadesSignedXML *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Content(sValue));
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

HRESULT CCadesSignedXML_put_signature_type(CCadesSignedXML *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_SignatureType((CADESCOM_XML_SIGNATURE_TYPE)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedXML_put_signature_method(CCadesSignedXML *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_SignatureMethod(pVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedXML_put_digest_method(CCadesSignedXML *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pVal(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_DigestMethod(pVal));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedXML_sign(CCadesSignedXML *m, CCadesSigner *signer, char *xpath, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob pXPath(xpath);
        CStringBlob sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Sign(signer->obj, pXPath, sValue));
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

HRESULT CCadesSignedXML_verify(CCadesSignedXML *m, char *value, char *xpath)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CStringBlob SignedMessage(value);
        CStringBlob pXPath(xpath);
        ATL_HR_ERRORCHECK_RETURN(m->obj->Verify(SignedMessage, pXPath));
    }
    CCADESCATCH
    return S_OK;
}
