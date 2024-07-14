#include "stdafx.h"
#include <stdlib.h>
#include "CCadesBlobs.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPAttribute.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesBlobs_t
{
    boost::shared_ptr<CPPCadesCPBlobsObject> obj;
};
struct CCadesAttribute_t
{
    boost::shared_ptr<CPPCadesCPAttributeObject> obj;
};

HRESULT CCadesBlobs_create(CCadesBlobs **result)
{
    try
    {
        CCadesBlobs *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPBlobsObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBlobs_destroy(CCadesBlobs *m)
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

HRESULT CCadesBlobs_get_count(CCadesBlobs *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        unsigned int r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Count(&r));
        *result = (int)r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBlobs_get_item(CCadesBlobs *m, int value, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::CBlob> blob;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Item(value, blob));
        char *buf = (char *)calloc(blob->cbData() + 1, sizeof(char));
        if (!buf)
        {
            return E_UNEXPECTED;
        }
        memcpy(buf, blob->pbData(), blob->cbData());
        *result = buf;
    }
    CCADESCATCH
    return S_OK;
}
