#ifndef CCADESRECIPIENTS_H
#define CCADESRECIPIENTS_H

#include "CCadesCertificate.h"
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesRecipients_t;
typedef struct CCadesRecipients_t CCadesRecipients;

HRESULT CCadesRecipients_create(CCadesRecipients **m);
HRESULT CCadesRecipients_destroy(CCadesRecipients *m);

HRESULT CCadesRecipients_get_count(CCadesRecipients *m, int *result);
HRESULT CCadesRecipients_get_item(CCadesRecipients *m, int value, CCadesCertificate **result);
HRESULT CCadesRecipients_remove(CCadesRecipients *m, int value);
HRESULT CCadesRecipients_add(CCadesRecipients *m, CCadesCertificate *obj);
HRESULT CCadesRecipients_clear(CCadesRecipients *m);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESRECIPIENTS_H__ */