#ifndef CCADESRAWSIGNATURE_H
#define CCADESRAWSIGNATURE_H

#include "CCadesHashedData.h"
#include "CCadesCertificate.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesRawSignature_t;
typedef struct CCadesRawSignature_t CCadesRawSignature;

HRESULT CCadesRawSignature_create(CCadesRawSignature **m);
HRESULT CCadesRawSignature_destroy(CCadesRawSignature *m);

HRESULT CCadesRawSignature_sign_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char **result);
HRESULT CCadesRawSignature_verify_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char *value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESRAWSIGNATURE_H__ */
