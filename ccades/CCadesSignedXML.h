#ifndef CCADESSIGNEDXML_H
#define CCADESSIGNEDXML_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificates.h"
#include "CCadesSigners.h"
#include "CCadesSigner.h"

struct CCadesSignedXML_t;
typedef struct CCadesSignedXML_t CCadesSignedXML;

HRESULT CCadesSignedXML_create(CCadesSignedXML **m);
HRESULT CCadesSignedXML_destroy(CCadesSignedXML *m);

HRESULT CCadesSignedXML_get_signers(CCadesSignedXML *m, CCadesSigners **result);
HRESULT CCadesSignedXML_put_content(CCadesSignedXML *m, char* value);
HRESULT CCadesSignedXML_get_content(CCadesSignedXML *m, char **result);
HRESULT CCadesSignedXML_put_signature_type(CCadesSignedXML *m, int value);
HRESULT CCadesSignedXML_put_signature_method(CCadesSignedXML *m, char* value);
HRESULT CCadesSignedXML_put_digest_method(CCadesSignedXML *m, char* value);
HRESULT CCadesSignedXML_sign(CCadesSignedXML *m, CCadesSigner *signer, char *xpath, char **result);
HRESULT CCadesSignedXML_verify(CCadesSignedXML *m, char* value, char* xpath);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNEDXML_H__ */