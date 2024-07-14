#ifndef CCADESBLOBS_H
#define CCADESBLOBS_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesBlobs_t;
typedef struct CCadesBlobs_t CCadesBlobs;

HRESULT CCadesBlobs_create(CCadesBlobs **m);
HRESULT CCadesBlobs_destroy(CCadesBlobs *m);
HRESULT CCadesBlobs_error(CCadesBlobs *m, char **result);

HRESULT CCadesBlobs_get_count(CCadesBlobs *m, int *result);
HRESULT CCadesBlobs_get_item(CCadesBlobs *m, int value, char **result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESBLOBS_H__ */