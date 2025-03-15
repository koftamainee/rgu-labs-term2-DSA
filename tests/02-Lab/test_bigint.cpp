#include "tests/test_bigint.h"

#include <iostream>

#include "bigint.h"

namespace lab2::test {

void bigint(int argc, char **argv) {
  lab2::bigint a("ABC", 16);
  int b = 52;

  a = a + b;
  a = b + a;
  a += b;
}

}  // namespace lab2::test
