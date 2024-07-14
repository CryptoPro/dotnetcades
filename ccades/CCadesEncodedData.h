#ifndef CCADESENCODEDDATA_H
#define CCADESENCODEDDATA_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesEncodedData_t;
typedef struct CCadesEncodedData_t CCadesEncodedData;

HRESULT CCadesEncodedData_create(CCadesEncodedData **m);
HRESULT CCadesEncodedData_destroy(CCadesEncodedData *m);

HRESULT CCadesEncodedData_format(CCadesEncodedData *m, int value, char **result);
HRESULT CCadesEncodedData_get_value(CCadesEncodedData *m, int value, char **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESENCODEDDATA_H__ */