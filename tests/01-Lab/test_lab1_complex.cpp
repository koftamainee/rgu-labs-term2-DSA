#include "tests/test_lab1_complex.h"

#include "lab1_complex.h"

void lab1::test::complex(int argc, char **argv) {
  class complex a(3, 4);
  class complex b(1, -2);

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  class complex c = a + b;
  std::cout << "a + b = " << c << std::endl;

  c = a - b;
  std::cout << "a - b = " << c << std::endl;

  c = a * b;
  std::cout << "a * b = " << c << std::endl;

  c = a / b;
  std::cout << "a / b = " << c << std::endl;

  std::cout << "|a| = " << a.abs() << std::endl;
  std::cout << "arg(a) = " << a.arg() << " radians" << std::endl;
}
