#ifndef CCADESSYMMETRICALGORITHM_H
#define CCADESSYMMETRICALGORITHM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificate.h"

struct CCadesSymmetricAlgorithm_t;
typedef struct CCadesSymmetricAlgorithm_t CCadesSymmetricAlgorithm;

HRESULT CCadesSymmetricAlgorithm_create(CCadesSymmetricAlgorithm **m);
HRESULT CCadesSymmetricAlgorithm_destroy(CCadesSymmetricAlgorithm *m);

HRESULT CCadesSymmetricAlgorithm_put_divers_data(CCadesSymmetricAlgorithm *m, char* value);
HRESULT CCadesSymmetricAlgorithm_get_divers_data(CCadesSymmetricAlgorithm *m, char **result);
HRESULT CCadesSymmetricAlgorithm_put_iv(CCadesSymmetricAlgorithm *m, char* value);
HRESULT CCadesSymmetricAlgorithm_get_iv(CCadesSymmetricAlgorithm *m, char **result);
HRESULT CCadesSymmetricAlgorithm_generate_key(CCadesSymmetricAlgorithm *m, int value);
HRESULT CCadesSymmetricAlgorithm_diversify_key(CCadesSymmetricAlgorithm *m, CCadesSymmetricAlgorithm **result);
HRESULT CCadesSymmetricAlgorithm_export_key(CCadesSymmetricAlgorithm *m, CCadesCertificate *cert, char **result);
HRESULT CCadesSymmetricAlgorithm_import_key(CCadesSymmetricAlgorithm *m, char* value, CCadesCertificate *cert, char *password);
HRESULT CCadesSymmetricAlgorithm_encrypt(CCadesSymmetricAlgorithm *m, char *value, int isFinal, char **result);
HRESULT CCadesSymmetricAlgorithm_decrypt(CCadesSymmetricAlgorithm *m, char *value, int isFinal, char **result);
HRESULT CCadesSymmetricAlgorithm_set_legacy_plugin_symmetric_export(CCadesSymmetricAlgorithm *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSYMMETRICALGORITHM_H__ */
