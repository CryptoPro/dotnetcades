#ifndef CCADESATTRIBUTE_H
#define CCADESATTRIBUTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesOID.h"

struct CCadesAttribute_t;
typedef struct CCadesAttribute_t CCadesAttribute;

HRESULT CCadesAttribute_create(CCadesAttribute **m);
HRESULT CCadesAttribute_destroy(CCadesAttribute *m);

HRESULT CCadesAttribute_get_oid(CCadesAttribute *m, CCadesOID **result);
HRESULT CCadesAttribute_put_oid(CCadesAttribute *m, char *value);
HRESULT CCadesAttribute_get_value(CCadesAttribute *m, char **result);
HRESULT CCadesAttribute_put_value(CCadesAttribute *m, char *value);
HRESULT CCadesAttribute_put_name(CCadesAttribute *m, int value);
HRESULT CCadesAttribute_get_name(CCadesAttribute *m, int *result);
HRESULT CCadesAttribute_put_value_encoding(CCadesAttribute *m, int value);
HRESULT CCadesAttribute_get_value_encoding(CCadesAttribute *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESATTRIBUTE_H__ */