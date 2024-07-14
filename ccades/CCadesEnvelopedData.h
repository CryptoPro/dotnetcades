#ifndef CCADESENVELOPEDDATA_H
#define CCADESENVELOPEDDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CCadesAlgorithm.h"
#include "CCadesRecipients.h"

struct CCadesEnvelopedData_t;
typedef struct CCadesEnvelopedData_t CCadesEnvelopedData;

HRESULT CCadesEnvelopedData_create(CCadesEnvelopedData **m);
HRESULT CCadesEnvelopedData_destroy(CCadesEnvelopedData *m);

HRESULT CCadesEnvelopedData_get_algorithm(CCadesEnvelopedData *m, CCadesAlgorithm **result);
HRESULT CCadesEnvelopedData_put_content(CCadesEnvelopedData *m, char* value);
HRESULT CCadesEnvelopedData_get_content(CCadesEnvelopedData *m, char **result);
HRESULT CCadesEnvelopedData_put_content_encoding(CCadesEnvelopedData *m, int value);
HRESULT CCadesEnvelopedData_get_content_encoding(CCadesEnvelopedData *m, int *result);
HRESULT CCadesEnvelopedData_get_recipients(CCadesEnvelopedData *m, CCadesRecipients **result);
HRESULT CCadesEnvelopedData_encrypt(CCadesEnvelopedData *m, int value, char **result);
HRESULT CCadesEnvelopedData_decrypt(CCadesEnvelopedData *m, char* value);
HRESULT CCadesEnvelopedData_stream_encrypt(CCadesEnvelopedData *m, char *value, int isFinal, char **result);
HRESULT CCadesEnvelopedData_stream_decrypt(CCadesEnvelopedData *m, char *value, int isFinal, char **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESENVELOPEDDATA_H__ */