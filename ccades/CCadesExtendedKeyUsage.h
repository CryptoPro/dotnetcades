#ifndef CCADESEXTENDEDKEYUSAGE_H
#define CCADESEXTENDEDKEYUSAGE_H

#include <stdbool.h>
#include "CCadesEKUs.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesExtendedKeyUsage_t;
typedef struct CCadesExtendedKeyUsage_t CCadesExtendedKeyUsage;

HRESULT CCadesExtendedKeyUsage_create(CCadesExtendedKeyUsage **m);
HRESULT CCadesExtendedKeyUsage_destroy(CCadesExtendedKeyUsage *m);

HRESULT CCadesExtendedKeyUsage_get_ekus(CCadesExtendedKeyUsage *m, CCadesEKUs **result);
HRESULT CCadesExtendedKeyUsage_get_is_present(CCadesExtendedKeyUsage *m, int *result);
HRESULT CCadesExtendedKeyUsage_get_is_critical(CCadesExtendedKeyUsage *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESEXTENDEDKEYUSAGE_H__ */