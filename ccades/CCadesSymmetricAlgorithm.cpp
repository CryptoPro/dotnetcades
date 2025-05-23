#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSymmetricAlgorithm.h"
#include "CPPCadesSymmetricAlgorithm.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesSymmetricAlgorithm_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesSymmetricAlgorithmObject> obj;
};
struct CCadesCertificate_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPCertificateObject> obj;
};

HRESULT CCadesSymmetricAlgorithm_create(CCadesSymmetricAlgorithm **result)
{
    try
    {
        CCadesSymmetricAlgorithm *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesSymmetricAlgorithmObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_destroy(CCadesSymmetricAlgorithm *m)
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

HRESULT CCadesSymmetricAlgorithm_put_divers_data(CCadesSymmetricAlgorithm *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pbData(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_DiversData(pbData.GetBuffer(), pbData.GetLength()));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_get_divers_data(CCadesSymmetricAlgorithm *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_DiversData(blob));
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

HRESULT CCadesSymmetricAlgorithm_put_iv(CCadesSymmetricAlgorithm *m, char *value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pbData(value);
        ATL_HR_ERRORCHECK_RETURN(m->obj->put_IV(pbData.GetBuffer(), pbData.GetLength()));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_get_iv(CCadesSymmetricAlgorithm *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IV(blob));
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

HRESULT CCadesSymmetricAlgorithm_import_key(CCadesSymmetricAlgorithm *m, char *value, CCadesCertificate *cert, char *password)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pbData(value);
        CAtlStringA pbPin(password);
        ATL_HR_ERRORCHECK_RETURN(m->obj->ImportKey(pbData.GetBuffer(), pbData.GetLength(), cert->obj, pbPin.GetBuffer(), pbPin.GetLength()));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_export_key(CCadesSymmetricAlgorithm *m, CCadesCertificate *cert, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->ExportKey(cert->obj, blob));
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

HRESULT CCadesSymmetricAlgorithm_generate_key(CCadesSymmetricAlgorithm *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->GenerateKey((CADESCOM_ENCRYPTION_ALGORITHM)value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_diversify_key(CCadesSymmetricAlgorithm *m, CCadesSymmetricAlgorithm **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        NS_SHARED_PTR::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesSymmetricAlgorithmObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->DiversifyKey(pObj));
        CCadesSymmetricAlgorithm *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesSymmetricAlgorithm_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_encrypt(CCadesSymmetricAlgorithm *m, char *value, int isFinal, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pbData(value);
        CryptoPro::CStringProxy sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Encrypt(pbData.GetBuffer(), pbData.GetLength(), isFinal, sValue));
        int len = strlen(sValue.c_str());
        char *buf = (char *)calloc(len + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, sValue.c_str(), len);
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSymmetricAlgorithm_decrypt(CCadesSymmetricAlgorithm *m, char *value, int isFinal, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA pbData(value);
        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Decrypt(pbData.GetBuffer(), pbData.GetLength(), isFinal, blob));
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

HRESULT CCadesSymmetricAlgorithm_put_legacy_plugin_symmetric_export(CCadesSymmetricAlgorithm *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_LegacyPluginSymmetricExport(value));
    }
    CCADESCATCH
    return S_OK;
}
