#include "stdafx.h"
#include <stdlib.h>
#include "CCadesCertificates.h"
#include "CCadesCertificates.h"
#include "CPPCadesCPCertificates.h"
#include "CPPCadesCPCertificate.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesCertificates_t
{
    boost::shared_ptr<CPPCadesCPCertificatesObject> obj;
};
struct CCadesCertificate_t
{
    boost::shared_ptr<CPPCadesCPCertificateObject> obj;
};

HRESULT CCadesCertificates_create(CCadesCertificates **result)
{
    try
    {
        CCadesCertificates *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPCertificatesObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificates_destroy(CCadesCertificates *m)
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

HRESULT CCadesCertificates_get_count(CCadesCertificates *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        unsigned int r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Count(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificates_get_item(CCadesCertificates *m, int value, CCadesCertificate **result)
{
    try
    {
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificateObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Item(value, pObj));

        CCadesCertificate *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesCertificate_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesCertificates_find_s(CCadesCertificates *m, int FindType, char *Criteria, int ValidOnly, CCadesCertificates **result)
{
    try
    {
        FindCriteria findCriteria;
        findCriteria.str = CAtlString(Criteria);
        findCriteria.dwCriteriaFlag = FIND_CRITERIA_STRING;
        CAPICOM_CERTIFICATE_FIND_TYPE type = (CAPICOM_CERTIFICATE_FIND_TYPE)FindType;

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPCadesCPCertificatesObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Find(type, &findCriteria, ValidOnly, pObj));
        CCadesCertificates *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesCertificates_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}
