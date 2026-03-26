#ifndef CCADESVERSION_H
#define CCADESVERSION_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesVersion_t;
typedef struct CCadesVersion_t CCadesVersion;

HRESULT CCadesVersion_create(CCadesVersion **m);
HRESULT CCadesVersion_destroy(CCadesVersion *m);

HRESULT CCadesVersion_to_string(CCadesVersion *m, char **result);
HRESULT CCadesVersion_get_major_version(CCadesVersion *m, int *result);
HRESULT CCadesVersion_get_minor_version(CCadesVersion *m, int *result);
HRESULT CCadesVersion_get_build_version(CCadesVersion *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESVERSION_H__ */