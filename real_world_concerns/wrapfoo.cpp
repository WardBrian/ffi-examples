
#include <vector>
#include <stdexcept>
#include <cstring>

#include "wrapfoo.h"
#include "foo.hpp"

struct foo_error {
 public:
  foo_error(char *message) : message(message) {}
  ~foo_error() { delete message; }
  const char *get_message() const { return message; }

 private:
  char *message;
};

const char *foo_error_get_message(const foo_error *err) {
  return err->get_message();
}

void foo_destroy_error(foo_error *err) { delete err; }

Frobulator *foo_create_frobulator(int x, int y, foo_error **err) {
  try {
    return new Frobulator(x, y);
  } catch (std::exception &e) {
    if (err != nullptr)
      *err = new foo_error(strdup(e.what()));
    return NULL;
  }
}

int foo_compute(const Frobulator *frobulator, const double *data,
                double *result, int len, foo_error **err) {
  try {
    std::vector<double> data_vec(data, data + len);
    std::vector<double> result_vec = frobulator->compute(data_vec);
    for (int i = 0; i < len; i++)
      result[i] = result_vec[i];
    return 0;
  } catch (std::exception &e) {
    if (err != nullptr)
      *err = new foo_error(strdup(e.what()));
    return -1;
  }
}

void foo_destroy_frobulator(Frobulator *frobulator) { delete frobulator; }
