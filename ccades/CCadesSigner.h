#ifndef CCADESSIGNER_H
#define CCADESSIGNER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesAttributes.h"
#include "CCadesCertificate.h"
#include "CCadesSignatureStatus.h"
#include "CCadesBlobs.h"

struct CCadesSigner_t;
typedef struct CCadesSigner_t CCadesSigner;

HRESULT CCadesSigner_create(CCadesSigner **m);
HRESULT CCadesSigner_destroy(CCadesSigner *m);

HRESULT CCadesSigner_get_authenticated_attributes2(CCadesSigner *m, CCadesAttributes **result);
HRESULT CCadesSigner_put_authenticated_attributes2(CCadesSigner *m, CCadesAttributes *obj);
HRESULT CCadesSigner_get_unauthenticated_attributes(CCadesSigner *m, CCadesAttributes **result);
HRESULT CCadesSigner_put_unauthenticated_attributes(CCadesSigner *m, CCadesAttributes *obj);
HRESULT CCadesSigner_get_certificate(CCadesSigner *m, CCadesCertificate **result);
HRESULT CCadesSigner_put_certificate(CCadesSigner *m, CCadesCertificate *obj);
HRESULT CCadesSigner_put_options(CCadesSigner *m, int value);
HRESULT CCadesSigner_get_options(CCadesSigner *m, int *result);
HRESULT CCadesSigner_get_ocsp_responses(CCadesSigner *m, CCadesBlobs **result);
HRESULT CCadesSigner_get_crls(CCadesSigner *m, CCadesBlobs **result);
HRESULT CCadesSigner_put_tsa_address(CCadesSigner *m, char* value);
HRESULT CCadesSigner_get_tsa_address(CCadesSigner *m, char **result);
HRESULT CCadesSigner_get_signature_timestamp_time(CCadesSigner *m, char **result);
HRESULT CCadesSigner_get_signing_time(CCadesSigner *m, char **result);
HRESULT CCadesSigner_put_key_pin(CCadesSigner *m, char* value);
HRESULT CCadesSigner_get_signature_status(CCadesSigner *m, CCadesSignatureStatus **result);
HRESULT CCadesSigner_get_check_certificate(CCadesSigner *m, int *result);
HRESULT CCadesSigner_put_check_certificate(CCadesSigner *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNER_H__ */