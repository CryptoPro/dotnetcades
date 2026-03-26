#ifndef CCADESEKUS_H
#define CCADESEKUS_H

#include "CCadesEKU.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesEKUs_t;
typedef struct CCadesEKUs_t CCadesEKUs;

HRESULT CCadesEKUs_create(CCadesEKUs **m);
HRESULT CCadesEKUs_destroy(CCadesEKUs *m);

HRESULT CCadesEKUs_get_count(CCadesEKUs *m, int *result);
HRESULT CCadesEKUs_get_item(CCadesEKUs *m, int value, CCadesEKU **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESEKUS_H__ */