#ifndef CCADESATTRIBUTES_H
#define CCADESATTRIBUTES_H

#include "CCadesAttribute.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesAttributes_t;
typedef struct CCadesAttributes_t CCadesAttributes;

HRESULT CCadesAttributes_create(CCadesAttributes **m);
HRESULT CCadesAttributes_destroy(CCadesAttributes *m);

HRESULT CCadesAttributes_get_count(CCadesAttributes *m, int *result);
HRESULT CCadesAttributes_get_item(CCadesAttributes *m, int value, CCadesAttribute **result);
HRESULT CCadesAttributes_remove(CCadesAttributes *m, int value);
HRESULT CCadesAttributes_add(CCadesAttributes *m, CCadesAttribute *obj);
HRESULT CCadesAttributes_clear(CCadesAttributes *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESATTRIBUTES_H__ */