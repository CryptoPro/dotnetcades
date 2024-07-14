#ifndef CCADESHASHEDDATA_H
#define CCADESHASHEDDATA_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesHashedData_t;
typedef struct CCadesHashedData_t CCadesHashedData;

HRESULT CCadesHashedData_create(CCadesHashedData **m);
HRESULT CCadesHashedData_destroy(CCadesHashedData *m);

HRESULT CCadesHashedData_put_algorithm(CCadesHashedData *m, int value);
HRESULT CCadesHashedData_get_algorithm(CCadesHashedData *m, int *result);
HRESULT CCadesHashedData_get_value(CCadesHashedData *m, char **result);
HRESULT CCadesHashedData_put_data_encoding(CCadesHashedData *m, int value);
HRESULT CCadesHashedData_get_data_encoding(CCadesHashedData *m, int *result);
HRESULT CCadesHashedData_get_key(CCadesHashedData *m, char **result);
HRESULT CCadesHashedData_put_key(CCadesHashedData *m, char* value);
HRESULT CCadesHashedData_hash(CCadesHashedData *m, char* value);
HRESULT CCadesHashedData_set_hash_value(CCadesHashedData *m, char* value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESHASHEDDATA_H__ */