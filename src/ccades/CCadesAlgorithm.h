#ifndef CCADESALGORITHM_H
#define CCADESALGORITHM_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesAlgorithm_t;
typedef struct CCadesAlgorithm_t CCadesAlgorithm;

HRESULT CCadesAlgorithm_create(CCadesAlgorithm **m);
HRESULT CCadesAlgorithm_destroy(CCadesAlgorithm *m);

HRESULT CCadesAlgorithm_get_name(CCadesAlgorithm *m, int *result);
HRESULT CCadesAlgorithm_put_name(CCadesAlgorithm *m, int value);
HRESULT CCadesAlgorithm_get_key_length(CCadesAlgorithm *m, int *result);
HRESULT CCadesAlgorithm_put_key_length(CCadesAlgorithm *m, int value);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESALGORITHM_H__ */