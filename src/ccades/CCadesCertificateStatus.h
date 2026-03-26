#ifndef CCADESCERTIFICATESTATUS_H
#define CCADESCERTIFICATESTATUS_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesCertificateStatus_t;
typedef struct CCadesCertificateStatus_t CCadesCertificateStatus;

HRESULT CCadesCertificateStatus_create(CCadesCertificateStatus **m);
HRESULT CCadesCertificateStatus_destroy(CCadesCertificateStatus *m);

HRESULT CCadesCertificateStatus_get_result(CCadesCertificateStatus *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESCERTIFICATESTATUS_H__ */