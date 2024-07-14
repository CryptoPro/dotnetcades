#ifndef CCADESCERTIFICATE_H
#define CCADESCERTIFICATE_H

#include "CCadesBasicConstraints.h"
#include "CCadesCertificateStatus.h"
#include "CCadesExtendedKeyUsage.h"
#include "CCadesKeyUsage.h"
#include "CCadesPrivateKey.h"
#include "CCadesPublicKey.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCertificate_t;
typedef struct CCadesCertificate_t CCadesCertificate;

HRESULT CCadesCertificate_create(CCadesCertificate **m);
HRESULT CCadesCertificate_destroy(CCadesCertificate *m);

HRESULT CCadesCertificate_get_info(CCadesCertificate *m, int value, char **result);
HRESULT CCadesCertificate_has_private_key(CCadesCertificate *m, int *result);
HRESULT CCadesCertificate_is_valid(CCadesCertificate *m, CCadesCertificateStatus **result);
HRESULT CCadesCertificate_extended_key_usage(CCadesCertificate *m, CCadesExtendedKeyUsage **result);
HRESULT CCadesCertificate_key_usage(CCadesCertificate *m, CCadesKeyUsage **result);
HRESULT CCadesCertificate_export(CCadesCertificate *m, int value, char **result);
HRESULT CCadesCertificate_import(CCadesCertificate *m, char *value);
HRESULT CCadesCertificate_get_thumbprint(CCadesCertificate *m, char **result);
HRESULT CCadesCertificate_get_serial_number(CCadesCertificate *m, char **result);
HRESULT CCadesCertificate_get_subject_name(CCadesCertificate *m, char **result);
HRESULT CCadesCertificate_get_issuer_name(CCadesCertificate *m, char **result);
HRESULT CCadesCertificate_get_version(CCadesCertificate *m, int *result);
HRESULT CCadesCertificate_get_valid_to_date(CCadesCertificate *m, char **result);
HRESULT CCadesCertificate_get_valid_from_date(CCadesCertificate *m, char **result);
HRESULT CCadesCertificate_basic_constraints(CCadesCertificate *m, CCadesBasicConstraints **result);
HRESULT CCadesCertificate_public_key(CCadesCertificate *m, CCadesPublicKey **result);
HRESULT CCadesCertificate_private_key(CCadesCertificate *m, CCadesPrivateKey **result);
HRESULT CCadesCertificate_find_private_key(CCadesCertificate *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCERTIFICATE_H__ */