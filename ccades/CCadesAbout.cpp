#include "stdafx.h"
#include <stdlib.h>
#include "CCadesAbout.h"
#include "CPPCadesAbout.h"

using namespace CryptoPro::PKI::CAdES;

struct CCadesAbout_t
{
    boost::shared_ptr<CPPCadesAboutObject> obj;
};
struct CCadesVersion_t
{
    boost::shared_ptr<CPPVersionObject> obj;
};

HRESULT CCadesAbout_create(CCadesAbout **result)
{
    try
    {
        CCadesAbout *m = (typeof(m))calloc(1, sizeof(*m));
        if (!m)
        {
            printf("Memory allocation failed");
            return E_UNEXPECTED;
        }
        m->obj = boost::make_shared<CPPCadesAboutObject>();
        *result = m;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAbout_destroy(CCadesAbout *m)
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

HRESULT CCadesAbout_get_version(CCadesAbout *m, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_Version(sValue));
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

HRESULT CCadesAbout_get_major_version(CCadesAbout *m, int *result)
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

HRESULT CCadesAbout_get_minor_version(CCadesAbout *m, int *result)
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

HRESULT CCadesAbout_get_build_version(CCadesAbout *m, int *result)
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

HRESULT CCadesAbout_get_csp_version(CCadesAbout *m, char *szProvName, int dwProvType, CCadesVersion **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA provName(szProvName);
        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPVersionObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_CSPVersion(provName, dwProvType, pObj));
        CCadesVersion *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesVersion_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAbout_get_plugin_version(CCadesAbout *m, CCadesVersion **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        boost::shared_ptr<CryptoPro::PKI::CAdES::CPPVersionObject> pObj;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_PluginVersion(pObj));
        CCadesVersion *ret = NULL;
        ATL_HR_ERRORCHECK_RETURN(CCadesVersion_create(&ret));
        ret->obj = pObj;
        *result = ret;
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAbout_get_csp_name(CCadesAbout *m, int dwProvType, char **result)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlString sValue;
        ATL_HR_ERRORCHECK_RETURN(m->obj->get_CSPName(dwProvType, sValue));
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

HRESULT CCadesAbout_media_filter(CCadesAbout *m, int dwMediaType)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        ATL_HR_ERRORCHECK_RETURN(m->obj->MediaFilter(dwMediaType));
    }
    CCADESCATCH
    return S_OK;
}

HRESULT CCadesAbout_reader_filter(CCadesAbout *m, int EnabledTypes, int EnabledOperations, char *FilterRegexp)
{
    try
    {
        if (!m)
        {
            return E_INVALIDARG;
        }

        CAtlStringA sRegexFilter(FilterRegexp);
        ATL_HR_ERRORCHECK_RETURN(m->obj->ReaderFilter(EnabledTypes, EnabledOperations, sRegexFilter));
    }
    CCADESCATCH
    return S_OK;
}
