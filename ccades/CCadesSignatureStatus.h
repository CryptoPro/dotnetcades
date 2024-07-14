#ifndef CCADESSIGNATURESTATUS_H
#define CCADESSIGNATURESTATUS_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesSignatureStatus_t;
typedef struct CCadesSignatureStatus_t CCadesSignatureStatus;

HRESULT CCadesSignatureStatus_create(CCadesSignatureStatus **m);
HRESULT CCadesSignatureStatus_destroy(CCadesSignatureStatus *m);
HRESULT CCadesSignatureStatus_is_valid(CCadesSignatureStatus *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESSIGNATURESTATUS_H__ */