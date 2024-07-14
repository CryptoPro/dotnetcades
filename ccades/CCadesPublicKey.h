#ifndef CCADESPUBLICKEY_H
#define CCADESPUBLICKEY_H

#include "CCadesOID.h"
#include "CCadesEncodedData.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesPublicKey_t;
typedef struct CCadesPublicKey_t CCadesPublicKey;

HRESULT CCadesPublicKey_create(CCadesPublicKey **m);
HRESULT CCadesPublicKey_destroy(CCadesPublicKey *m);

HRESULT CCadesPublicKey_get_algorithm(CCadesPublicKey *m, CCadesOID **result);
HRESULT CCadesPublicKey_get_encoded_key(CCadesPublicKey *m, CCadesEncodedData **result);
HRESULT CCadesPublicKey_get_encoded_parameters(CCadesPublicKey *m, CCadesEncodedData **result);
HRESULT CCadesPublicKey_get_length(CCadesPublicKey *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESPublicKey_H__ */
