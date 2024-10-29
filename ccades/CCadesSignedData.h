#ifndef CCADESSIGNEDDATA_H
#define CCADESSIGNEDDATA_H

#include "CCadesSigners.h"
#include "CCadesCertificates.h"
#include "CCadesSigner.h"
#include "CCadesHashedData.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesSignedData_t;
typedef struct CCadesSignedData_t CCadesSignedData;

HRESULT CCadesSignedData_create(CCadesSignedData **m);
HRESULT CCadesSignedData_destroy(CCadesSignedData *m);

HRESULT CCadesSignedData_get_certificates(CCadesSignedData *m, CCadesCertificates **result);
HRESULT CCadesSignedData_put_content(CCadesSignedData *m, char *value);
HRESULT CCadesSignedData_get_content(CCadesSignedData *m, char **result);
HRESULT CCadesSignedData_put_content_encoding(CCadesSignedData *m, int value);
HRESULT CCadesSignedData_get_content_encoding(CCadesSignedData *m, int *result);
HRESULT CCadesSignedData_get_signers(CCadesSignedData *m, CCadesSigners **result);
HRESULT CCadesSignedData_put_display_data(CCadesSignedData *m, int value);
HRESULT CCadesSignedData_get_display_data(CCadesSignedData *m, int *result);
HRESULT CCadesSignedData_cosign(CCadesSignedData *m, CCadesSigner *signer, int EncodingType, char **result);
HRESULT CCadesSignedData_sign(CCadesSignedData *m, CCadesSigner *signer, int isDetached, int EncodingType, char **result);
HRESULT CCadesSignedData_verify(CCadesSignedData *m, char *value, int isDetached, int Flag);
HRESULT CCadesSignedData_cosign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, int EncodingType, char **result);
HRESULT CCadesSignedData_enhance_cades(CCadesSignedData *m, int CadesType, char *TSAAddress, int EncodingType, char **result);
HRESULT CCadesSignedData_sign_cades(CCadesSignedData *m, CCadesSigner *signer, int CadesType, int isDetached, int EncodingType, char **result);
HRESULT CCadesSignedData_verify_cades(CCadesSignedData *m, char *value, int CadesType, int isDetached);
HRESULT CCadesSignedData_cosign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType, char **result);
HRESULT CCadesSignedData_sign_hash(CCadesSignedData *m, CCadesHashedData *hashed, CCadesSigner *signer, int CadesType, int EncodingType, char **result);
HRESULT CCadesSignedData_verify_hash(CCadesSignedData *m, CCadesHashedData *hashed, char *value, int CadesType);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNEDDATA_H__ */