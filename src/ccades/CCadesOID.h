#ifndef CCADESOID_H
#define CCADESOID_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesOID_t;
typedef struct CCadesOID_t CCadesOID;

HRESULT CCadesOID_create(CCadesOID **m);
HRESULT CCadesOID_destroy(CCadesOID *m);

HRESULT CCadesOID_get_friendly_name(CCadesOID *m, char **result);
HRESULT CCadesOID_put_friendly_name(CCadesOID *m, char *value);
HRESULT CCadesOID_get_name(CCadesOID *m, int *result);
HRESULT CCadesOID_put_name(CCadesOID *m, int value);
HRESULT CCadesOID_get_value(CCadesOID *m, char **result);
HRESULT CCadesOID_put_value(CCadesOID *m, char *value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESOID_H__ */
