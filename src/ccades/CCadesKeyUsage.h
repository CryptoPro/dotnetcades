#ifndef CCADESKEYUSAGE_H
#define CCADESKEYUSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesKeyUsage_t;
typedef struct CCadesKeyUsage_t CCadesKeyUsage;

HRESULT CCadesKeyUsage_create(CCadesKeyUsage **m);
HRESULT CCadesKeyUsage_destroy(CCadesKeyUsage *m);

HRESULT CCadesKeyUsage_get_is_present(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_critical(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_crl_sign_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_data_encipherment_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_decipher_only_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_digital_signature_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_encipher_only_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_key_agreement_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_key_cert_sign_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_key_encipherment_enabled(CCadesKeyUsage *m, int *result);
HRESULT CCadesKeyUsage_get_is_non_repudiation_enabled(CCadesKeyUsage *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESKEYUSAGE_H__ */