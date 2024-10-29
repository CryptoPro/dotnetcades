#ifndef CCADESSIGNERS_H
#define CCADESSIGNERS_H

#include "CCadesSigner.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesSigners_t;
typedef struct CCadesSigners_t CCadesSigners;

HRESULT CCadesSigners_create(CCadesSigners **m);
HRESULT CCadesSigners_destroy(CCadesSigners *m);

HRESULT CCadesSigners_get_count(CCadesSigners *m, int *result);
HRESULT CCadesSigners_get_item(CCadesSigners *m, int value, CCadesSigner **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNERS_H__ */