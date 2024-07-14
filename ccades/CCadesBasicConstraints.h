#ifndef CCADESBASICCONSTRAINTS_H
#define CCADESBASICCONSTRAINTS_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

struct CCadesBasicConstraints_t;
typedef struct CCadesBasicConstraints_t CCadesBasicConstraints;

HRESULT CCadesBasicConstraints_create(CCadesBasicConstraints **m);
HRESULT CCadesBasicConstraints_destroy(CCadesBasicConstraints *m);

HRESULT CCadesBasicConstraints_get_is_present(CCadesBasicConstraints *m, int *result);
HRESULT CCadesBasicConstraints_put_is_present(CCadesBasicConstraints *m, int value);
HRESULT CCadesBasicConstraints_get_is_critical(CCadesBasicConstraints *m, int *result);
HRESULT CCadesBasicConstraints_put_is_critical(CCadesBasicConstraints *m, int value);
HRESULT CCadesBasicConstraints_get_is_certificate_authority(CCadesBasicConstraints *m, int *result);
HRESULT CCadesBasicConstraints_get_is_path_len_constraint_present(CCadesBasicConstraints *m, int *result);
HRESULT CCadesBasicConstraints_get_path_len_constraint(CCadesBasicConstraints *m, int *result);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESBASICCONSTRAINTS_H__ */