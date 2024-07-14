#ifndef CCADESEKU_H
#define CCADESEKU_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesEKU_t;
typedef struct CCadesEKU_t CCadesEKU;

HRESULT CCadesEKU_create(CCadesEKU **m);
HRESULT CCadesEKU_destroy(CCadesEKU *m);

HRESULT CCadesEKU_get_name(CCadesEKU *m, int *result);
HRESULT CCadesEKU_put_name(CCadesEKU *m, int value);
HRESULT CCadesEKU_get_oid(CCadesEKU *m, char **result);
HRESULT CCadesEKU_put_oid(CCadesEKU *m, char* value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESEKU_H__ */