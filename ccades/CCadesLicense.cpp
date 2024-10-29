#include "stdafx.h"
#include <stdlib.h>
#include "CCadesLicense.h"
#include "CPPCadesCPLicense.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesLicense_t
{
    NS_SHARED_PTR::shared_ptr<CPPCadesCPLicenseObject> obj;
};

HRESULT CCadesLicense_create(CCadesLicense **result)
{
    try
    {
        CCadesLicense *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = NS_SHARED_PTR::make_shared<CPPCadesCPLicenseObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesLicense_destroy(CCadesLicense *m)
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

HRESULT CCadesLicense_get_company_name(CCadesLicense *m, int product, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->CompanyName(product, sValue));
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

HRESULT CCadesLicense_get_first_install_date(CCadesLicense *m, int product, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->FirstInstallDate(product, sValue));
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

HRESULT CCadesLicense_get_serial_number(CCadesLicense *m, int product, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->SerialNumber(product, sValue));
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

HRESULT CCadesLicense_get_type(CCadesLicense *m, int product, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->Type(product, sValue));
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

HRESULT CCadesLicense_get_valid_to(CCadesLicense *m, int product, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->ValidTo(product, sValue));
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

HRESULT CCadesLicense_set_license(CCadesLicense *m, char *serial, char *user, char *company)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringW sSerialNumber(serial);
        CAtlStringW sOwner(user);
        CAtlStringW sCompany(company);
        ATL_HR_ERRORCHECK_RETURN(m->obj->SetLicense(sSerialNumber, sOwner, sCompany));
    }
    CCADESCATCH
    return S_OK;
}
