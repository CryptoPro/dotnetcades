#include "stdafx.h"
#include <stdlib.h>
#include "CCadesVersion.h"
#include "CPPVersion.h"

using namespace CryptoPro::PKI::CAdES;
struct CCadesVersion_t
{
    boost::shared_ptr<CPPVersionObject> obj;
};

HRESULT CCadesVersion_create(CCadesVersion **result)
{
    try
    {
        CCadesVersion *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPVersionObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesVersion_destroy(CCadesVersion *m)
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

HRESULT CCadesVersion_to_string(CCadesVersion *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->toString(sValue));
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

HRESULT CCadesVersion_get_major_version(CCadesVersion *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_MajorVersion(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesVersion_get_minor_version(CCadesVersion *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_MinorVersion(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesVersion_get_build_version(CCadesVersion *m, int *result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        DWORD r;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_BuildVersion(&r));
        *result = r;
    }
    CCADESCATCH
    return S_OK;
}
