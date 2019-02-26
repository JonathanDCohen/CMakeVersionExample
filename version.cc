#include <iostream>
#include "lib/lib.h"

int main() {
  std::cout << "client: " << __cplusplus << std::endl;
  std::cout << "lib: " << get() << std::endl;
}
