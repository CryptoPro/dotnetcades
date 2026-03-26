#ifndef CCADESLICENSE_H
#define CCADESLICENSE_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCadesLicense_t;
typedef struct CCadesLicense_t CCadesLicense;

HRESULT CCadesLicense_create(CCadesLicense **m);
HRESULT CCadesLicense_destroy(CCadesLicense *m);

HRESULT CCadesLicense_get_company_name(CCadesLicense *m, int product, char **result);
HRESULT CCadesLicense_get_first_install_date(CCadesLicense *m, int product, char **result);
HRESULT CCadesLicense_get_serial_number(CCadesLicense *m, int product, char **result);
HRESULT CCadesLicense_get_type(CCadesLicense *m, int product, char **result);
HRESULT CCadesLicense_get_valid_to(CCadesLicense *m, int product, char **result);
HRESULT CCadesLicense_set_license(CCadesLicense *m, char *serial, char *user, char *company);

#ifdef __cplusplus
}
#endif

#endif /* __CCADESLICENSE_H__ */