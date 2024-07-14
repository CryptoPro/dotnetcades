#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEnvelopedData.h"
#include "CPPCadesCPEnvelopedData.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesEnvelopedData_t
{
    boost::shared_ptr<CPPCadesCPEnvelopedDataObject> obj;
};
struct CCadesAlgorithm_t
{
    boost::shared_ptr<CPPCadesCPAlgorithmObject> obj;
};
struct CCadesRecipients_t
{
    boost::shared_ptr<CPPCadesCPRecipientsObject> obj;
};

HRESULT CCadesEnvelopedData_create(CCadesEnvelopedData **result)
{
    try
    {
        CCadesEnvelopedData *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPEnvelopedDataObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_destroy(CCadesEnvelopedData *m)
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

HRESULT CCadesEnvelopedData_get_algorithm(CCadesEnvelopedData *m, CCadesAlgorithm **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPAlgorithmObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Algorithm(pObj));
        CCadesAlgorithm *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesAlgorithm_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_put_content(CCadesEnvelopedData *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }
        CAtlStringA sValue(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Content(sValue.GetBuffer(), sValue.GetLength()));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_get_content(CCadesEnvelopedData *m, char **result)
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

HRESULT CCadesEnvelopedData_put_content_encoding(CCadesEnvelopedData *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_ContentEncoding((CADESCOM_CONTENT_ENCODING_TYPE)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_get_content_encoding(CCadesEnvelopedData *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }
        CADESCOM_CONTENT_ENCODING_TYPE val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ContentEncoding(&val));
        *result = (int)val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_get_recipients(CCadesEnvelopedData *m, CCadesRecipients **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPRecipientsObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Recipients(pObj));
        CCadesRecipients *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesRecipients_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_decrypt(CCadesEnvelopedData *m, char* value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob blob((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->Decrypt(blob));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_encrypt(CCadesEnvelopedData *m, int value, char** result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Encrypt((CAPICOM_ENCODING_TYPE)value, blob));
        char *buf = (char *)calloc(blob.cbData() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, blob.pbData(), blob.cbData());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_stream_encrypt(CCadesEnvelopedData *m, char *value, int isFinal, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->StreamEncrypt((const char *)sValue.GetBuffer(), sValue.GetLength(), isFinal, blob));
        char *buf = (char *)calloc(blob.cbData() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, blob.pbData(), blob.cbData());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEnvelopedData_stream_decrypt(CCadesEnvelopedData *m, char *value, int isFinal, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->StreamDecrypt((const char *)sValue.GetBuffer(), sValue.GetLength(), isFinal, blob));
        char *buf = (char *)calloc(blob.cbData() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, blob.pbData(), blob.cbData());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}
