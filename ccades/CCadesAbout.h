#ifndef CCADESABOUT_H
#define CCADESABOUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesVersion.h"

struct CCadesAbout_t;
typedef struct CCadesAbout_t CCadesAbout;

HRESULT CCadesAbout_create(CCadesAbout **m);
HRESULT CCadesAbout_destroy(CCadesAbout *m);

HRESULT CCadesAbout_get_version(CCadesAbout *m, char **result);
HRESULT CCadesAbout_get_csp_name(CCadesAbout *m, int dwProvType, char **result);
HRESULT CCadesAbout_get_major_version(CCadesAbout *m, int *result);
HRESULT CCadesAbout_get_minor_version(CCadesAbout *m, int *result);
HRESULT CCadesAbout_get_build_version(CCadesAbout *m, int *result);
HRESULT CCadesAbout_get_csp_version(CCadesAbout *m, char *szProvName, int dwProvType, CCadesVersion **result);
HRESULT CCadesAbout_get_plugin_version(CCadesAbout *m, CCadesVersion **result);
HRESULT CCadesAbout_media_filter(CCadesAbout *m, int dwMediaType);
HRESULT CCadesAbout_reader_filter(CCadesAbout *m, int EnabledTypes, int EnabledOperations, char *FilterRegexp);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESABOUT_H__ */