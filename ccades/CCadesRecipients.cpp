#include "stdafx.h"
#include <stdlib.h>
#include "CCadesRecipients.h"
#include "CPPCadesCollections.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesRecipients_t
{
    boost::shared_ptr<CPPCadesCPRecipientsObject> obj;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
};

HRESULT CCadesRecipients_create(CCadesRecipients **result)
{
    try
    {
        CCadesRecipients *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPRecipientsObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesRecipients_destroy(CCadesRecipients *m)
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

HRESULT CCadesRecipients_get_count(CCadesRecipients *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Count(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesRecipients_remove(CCadesRecipients *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Remove(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesRecipients_get_item(CCadesRecipients *m, int value, CCadesCertificate **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Item(value, pObj));
        CCadesCertificate *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesCertificate_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesRecipients_add(CCadesRecipients *m, CCadesCertificate *obj)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Add(obj->obj));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesRecipients_clear(CCadesRecipients *m)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->Clear());
    }
    CCADESCATCH
    return S_OK;
}
