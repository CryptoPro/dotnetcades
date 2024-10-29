#include "stdafx.h"
#include <stdlib.h>
#include "CCadesBasicConstraints.h"
#include "CPPCadesCPBasicConstraints.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesBasicConstraints_t
{
    boost::shared_ptr<CPPCadesCPBasicConstraintsObject> obj;
};

HRESULT CCadesBasicConstraints_create(CCadesBasicConstraints **result)
{
    try
    {
        CCadesBasicConstraints *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesCPBasicConstraintsObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_destroy(CCadesBasicConstraints *m)
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

HRESULT CCadesBasicConstraints_get_is_present(CCadesBasicConstraints *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsPresent(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_put_is_present(CCadesBasicConstraints *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_IsPresent(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_get_is_critical(CCadesBasicConstraints *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsCritical(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_put_is_critical(CCadesBasicConstraints *m, int value)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->put_IsCritical(value));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_get_is_certificate_authority(CCadesBasicConstraints *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsCertificateAuthority(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_get_is_path_len_constraint_present(CCadesBasicConstraints *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        BOOL res;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_IsPathLenConstraintPresent(&res));
        *result = res;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesBasicConstraints_get_path_len_constraint(CCadesBasicConstraints *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_PathLenConstraint(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}
