#ifndef CCADESCERTIFICATES_H
#define CCADESCERTIFICATES_H

#include "CCadesCertificate.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCertificates_t;
typedef struct CCadesCertificates_t CCadesCertificates;

HRESULT CCadesCertificates_create(CCadesCertificates **m);
HRESULT CCadesCertificates_destroy(CCadesCertificates *m);

HRESULT CCadesCertificates_get_count(CCadesCertificates *m, int *result);
HRESULT CCadesCertificates_get_item(CCadesCertificates *m, int value, CCadesCertificate **result);
HRESULT CCadesCertificates_find_s(CCadesCertificates *m, int FindType, char *Criteria, int bValidOnly, CCadesCertificates **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCERTIFICATES_H__ */