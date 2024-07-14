#ifndef CCADESPRIVATEKEY_H
#define CCADESPRIVATEKEY_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesPrivateKey_t;
typedef struct CCadesPrivateKey_t CCadesPrivateKey;

HRESULT CCadesPrivateKey_create(CCadesPrivateKey **m);
HRESULT CCadesPrivateKey_destroy(CCadesPrivateKey *m);

HRESULT CCadesPrivateKey_change_pin(CCadesPrivateKey *m);
HRESULT CCadesPrivateKey_get_container_name(CCadesPrivateKey *m, char **result);
HRESULT CCadesPrivateKey_get_unique_container_name(CCadesPrivateKey *m, char **result);
HRESULT CCadesPrivateKey_get_provider_name(CCadesPrivateKey *m, char **result);
HRESULT CCadesPrivateKey_get_provider_type(CCadesPrivateKey *m, int *result);
HRESULT CCadesPrivateKey_get_key_spec(CCadesPrivateKey *m, int *result);
HRESULT CCadesPrivateKey_get_is_default_pin(CCadesPrivateKey *m, int *result);
HRESULT CCadesPrivateKey_set_cache_pin(CCadesPrivateKey *m, int value);
HRESULT CCadesPrivateKey_set_key_pin(CCadesPrivateKey *m, char* value);
HRESULT CCadesPrivateKey_get_carrier_flags(CCadesPrivateKey *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESPrivateKey_H__ */