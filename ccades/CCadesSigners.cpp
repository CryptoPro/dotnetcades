#include "stdafx.h"
#include <stdlib.h>
#include "CCadesSigners.h"
#include "CCadesOID.h"
#include "CPPCadesCollections.h"
#include "CPPCadesCPSigner.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesSigner_t
{
    boost::shared_ptr<CPPCadesCPSignerObject> obj;
};
struct CCadesSigners_t
{
    boost::shared_ptr<CPPCadesCPSignersObject> obj;
};

HRESULT CCadesSigners_create(CCadesSigners **result)
{
    try
    {
        CCadesSigners *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPSignersObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigners_destroy(CCadesSigners *m)
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

HRESULT CCadesSigners_get_count(CCadesSigners *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        unsigned int res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Count(&res));
        *result = (int)res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesSigners_get_item(CCadesSigners *m, int value, CCadesSigner **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPSignerObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Item(value, pObj));

        CCadesSigner *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesSigner_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}