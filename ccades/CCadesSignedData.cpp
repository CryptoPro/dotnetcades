#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSignedData.h"
#include "CPPCadesCPSignedData.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesSignedData_t
{
    boost::shared_ptr<CPPCadesSignedDataObject> obj;
};
struct CCadesSigners_t
{
    boost::shared_ptr<CPPCadesCPSignersObject> obj;
};
struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
};
struct CCadesSigner_t
{
    boost::shared_ptr<CPPCadesCPSignerObject> obj;
};
struct CCadesHashedData_t
{
    boost::shared_ptr<CPPCadesCPHashedDataObject> obj;
};

HRESULT CCadesSignedData_create(CCadesSignedData **result)
{
    try
    {
        CCadesSignedData *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesSignedDataObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_destroy(CCadesSignedData *m)
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

HRESULT CCadesSignedData_get_certificates(CCadesSignedData *m, CCadesCertificates **result)
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

HRESULT CCadesSignedData_put_content(CCadesSignedData *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pbData(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_Content(pbData.GetBuffer(), pbData.GetLength()));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_get_content(CCadesSignedData *m, char **result)
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

HRESULT CCadesSignedData_put_content_encoding(CCadesSignedData *m, int value)
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

HRESULT CCadesSignedData_get_content_encoding(CCadesSignedData *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CADESCOM_CONTENT_ENCODING_TYPE val;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_ContentEncoding(&val));
        *result = val;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_get_signers(CCadesSignedData *m, CCadesSigners **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignersObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Signers(pObj));
        CCadesSigners *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesSigners_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_put_display_data(CCadesSignedData *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_DisplayData(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_get_display_data(CCadesSignedData *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_DisplayData(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_cosign(CCadesSignedData *m, CCadesSigner *signer, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->CoSign(signer->obj, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_sign(CCadesSignedData *m, CCadesSigner *signer, int isDetached, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Sign(signer->obj, isDetached, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_verify(CCadesSignedData *m, char *value, int isDetached, int Flag)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob SignedMessage((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->Verify(SignedMessage, isDetached, (CAPICOM_SIGNED_DATA_VERIFY_FLAG)Flag));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_cosign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->CoSignCades(signer->obj, (CADESCOM_CADES_TYPE)CadesType, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_enhance_cades(CCadesSignedData *m, int CadesType, char *TSAAddress, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA arg_TSAAddress(TSAAddress);
        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->EnhanceCades((CADESCOM_CADES_TYPE)CadesType, arg_TSAAddress, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_sign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, int isDetached, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->SignCades(signer->obj, (CADESCOM_CADES_TYPE)CadesType, isDetached, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_verify_cades(CCadesSignedData *m, char *value, int CadesType, int isDetached)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob SignedMessage((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->VerifyCades(SignedMessage, (CADESCOM_CADES_TYPE)CadesType, isDetached));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSignedData_cosign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->CoSignHash(signer->obj, hashed->obj, (CADESCOM_CADES_TYPE)CadesType, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_sign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->SignHash(signer->obj, hashed->obj, (CADESCOM_CADES_TYPE)CadesType, (CAPICOM_ENCODING_TYPE)EncodingType, &blob));
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

HRESULT CCadesSignedData_verify_hash(CCadesSignedData *m, CCadesHashedData *hashed, char *value, int CadesType)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sValue(value);
        CryptoPro::CBlob SignedMessage((const unsigned char *)sValue.GetBuffer(), sValue.GetLength());
        ATL_HR_ERRORCHECK_RETURN(m->obj->VerifyHash(hashed->obj, SignedMessage, (CADESCOM_CADES_TYPE)CadesType));
    }
    CCADESCATCH
    return S_OK;
}
