#include <iostream>
#include <iomanip>

extern "C" {
#include "../C/euler.h"
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <iterations>" << std::endl;
    return 1;
  }

  int iter = std::stoi(argv[1]);
  std::cout << "e = " << std::setprecision(15) << euler(iter) << std::endl;
  return 0;
}
