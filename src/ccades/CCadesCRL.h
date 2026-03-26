#ifndef CCADESCRL_H
#define CCADESCRL_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCRL_t;
typedef struct CCadesCRL_t CCadesCRL;

HRESULT CCadesCRL_create(CCadesCRL **m);
HRESULT CCadesCRL_destroy(CCadesCRL *m);

HRESULT CCadesCRL_import(CCadesCRL *m, char *value);
HRESULT CCadesCRL_export(CCadesCRL *m, int value, char **result);
HRESULT CCadesCRL_get_issuer_name(CCadesCRL *m, char **result);
HRESULT CCadesCRL_get_this_update(CCadesCRL *m, char **result);
HRESULT CCadesCRL_get_next_update(CCadesCRL *m, char **result);
HRESULT CCadesCRL_get_thumbprint(CCadesCRL *m, char **result);
HRESULT CCadesCRL_get_auth_key_id(CCadesCRL *m, char **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCRL_H__ */