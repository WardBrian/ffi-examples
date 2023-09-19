#ifdef __cplusplus
#include "foo.hpp"  // if we're compiling C++, we can include the original header
extern "C" {
#else
typedef struct Frobulator
    Frobulator;  // opaque struct for type safety in C callers
#endif
typedef struct foo_error foo_error;

Frobulator *foo_create_frobulator(int x, int y, foo_error **err);
void foo_destroy_frobulator(Frobulator *frobulator);

int foo_compute(const Frobulator *frobulator, const double *data,
                double *result, int len, foo_error **err);

const char *foo_error_get_message(const foo_error *err);
void foo_destroy_error(foo_error *err);

#ifdef __cplusplus
}  // extern "C"
#endif
