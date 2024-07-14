#ifndef CCADESSIGNEDDATA_H
#define CCADESSIGNEDDATA_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificates.h"
#include "CCadesSigners.h"
#include "CCadesSigner.h"
#include "CCadesHashedData.h"

struct CCadesRawSignature_t;
typedef struct CCadesRawSignature_t CCadesRawSignature;

HRESULT CCadesRawSignature_create(CCadesRawSignature **m);
HRESULT CCadesRawSignature_destroy(CCadesRawSignature *m);

HRESULT CCadesRawSignature_sign_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char **result);
HRESULT CCadesRawSignature_verify_hash(CCadesRawSignature *m, CCadesHashedData *hashed, CCadesCertificate *signer, char* value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNEDDATA_H__ */