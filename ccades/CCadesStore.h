#ifndef CCADESSTORE_H
#define CCADESSTORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesCertificates.h"
#include "CCadesCRL.h"

struct CCadesStore_t;
typedef struct CCadesStore_t CCadesStore;

HRESULT CCadesStore_create(CCadesStore **m);
HRESULT CCadesStore_destroy(CCadesStore *m);

HRESULT CCadesStore_open(CCadesStore *m, int value, char* name, int mode);
HRESULT CCadesStore_close(CCadesStore *m);
HRESULT CCadesStore_add(CCadesStore *m, CCadesCertificate *obj);
HRESULT CCadesStore_add_crl(CCadesStore *m, CCadesCRL *obj);
HRESULT CCadesStore_get_certificates(CCadesStore *m, CCadesCertificates **result);
HRESULT CCadesStore_get_location(CCadesStore *m, int *result);
HRESULT CCadesStore_get_name(CCadesStore *m, char **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSTORE_H__ */