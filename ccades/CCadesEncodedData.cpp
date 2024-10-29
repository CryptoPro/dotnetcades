#include "stdafx.h"
#include <stdlib.h>
#include "CCadesEncodedData.h"
#include "CPPCadesCPEncodedData.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesEncodedData_t
{
    boost::shared_ptr<CPPCadesCPEncodedDataObject> obj;
};

HRESULT CCadesEncodedData_create(CCadesEncodedData **result)
{
    try
    {
        CCadesEncodedData *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPEncodedDataObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesEncodedData_destroy(CCadesEncodedData *m)
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

HRESULT CCadesEncodedData_format(CCadesEncodedData *m, int value, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringW sValueW;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Format(value, sValueW));
        CAtlStringA sValue(sValueW);
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

HRESULT CCadesEncodedData_get_value(CCadesEncodedData *m, int value, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CryptoPro::CBlob blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Value((CAPICOM_ENCODING_TYPE)value, blob));
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
