#include "tests/test_logical_values_array.h"

#include <iostream>

#include "logical_values_array.h"

void lab1::test::logical_values_array(int argc, char** argv) {
  class logical_values_array a(0b1100);  // 12 in decimal
  class logical_values_array b(0b1010);  // 10 in decimal

  char binary_str[33];

  std::cout << "Initial values:" << std::endl;
  a.to_binary_string(binary_str);
  std::cout << "a = " << binary_str << std::endl;
  b.to_binary_string(binary_str);
  std::cout << "b = " << binary_str << std::endl;

  std::cout << "\nLogical NOT:" << std::endl;
  class logical_values_array not_a = a.logical_not();
  not_a.to_binary_string(binary_str);
  std::cout << "~a = " << binary_str << std::endl;

  std::cout << "\nLogical AND:" << std::endl;
  class logical_values_array a_and_b = a.logical_and(b);
  a_and_b.to_binary_string(binary_str);
  std::cout << "a AND b = " << binary_str << std::endl;

  std::cout << "\nLogical OR:" << std::endl;
  class logical_values_array a_or_b = a.logical_or(b);
  a_or_b.to_binary_string(binary_str);
  std::cout << "a OR b = " << binary_str << std::endl;

  std::cout << "\nLogical Implication:" << std::endl;
  class logical_values_array a_implies_b = a.logical_implication(b);
  a_implies_b.to_binary_string(binary_str);
  std::cout << "a -> b = " << binary_str << std::endl;

  std::cout << "\nLogical Coimplication:" << std::endl;
  class logical_values_array a_coimplies_b = a.logical_coimplication(b);
  a_coimplies_b.to_binary_string(binary_str);
  std::cout << "a <- b = " << binary_str << std::endl;

  std::cout << "\nLogical XOR:" << std::endl;
  class logical_values_array a_xor_b = a.logical_xor(b);
  a_xor_b.to_binary_string(binary_str);
  std::cout << "a XOR b = " << binary_str << std::endl;

  std::cout << "\nLogical Equivalence:" << std::endl;
  class logical_values_array a_equiv_b = a.logical_equivalence(b);
  a_equiv_b.to_binary_string(binary_str);
  std::cout << "a <-> b = " << binary_str << std::endl;

  std::cout << "\nLogical Pierce Arrow (NOR):" << std::endl;
  class logical_values_array a_pierce_b = a.logical_pierce_arrow(b);
  a_pierce_b.to_binary_string(binary_str);
  std::cout << "a NOR b = " << binary_str << std::endl;

  std::cout << "\nLogical Sheffer Stroke (NAND):" << std::endl;
  class logical_values_array a_sheffer_b = a.logical_sheffer_stroke(b);
  a_sheffer_b.to_binary_string(binary_str);
  std::cout << "a NAND b = " << binary_str << std::endl;

  std::cout << "\nEquality Check:" << std::endl;
  std::cout << "a equals b? "
            << (lab1::logical_values_array::equals(a, b) ? "Yes" : "No")
            << std::endl;

  std::cout << "\nAccessing bits:" << std::endl;
  std::cout << "a[0] = " << a[0] << std::endl;
  std::cout << "a[1] = " << a[1] << std::endl;
  std::cout << "a[2] = " << a[2] << std::endl;
  std::cout << "a[3] = " << a[3] << std::endl;
}
