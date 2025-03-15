#include "tests/test_fibonacci_heap.h"

#include <iostream>

#include "fibonacci_heap.h"
#include "tests/test_heaps.h"

void lab1::test::fibonacci_heap(int argc, char **argv) {
  lab1::fibonacci_heap heap1;
  lab1::fibonacci_heap heap2;

  std::cout << "Heap1:" << std::endl;
  heaps::demonstrate_insert_and_top(heap1);
  std::cout << std::endl << "Heap2:" << std::endl;
  heaps::demonstrate_insert_and_top(heap2);

  heaps::demonstrate_pop(heap1);

  heaps::demonstrate_merge(heap1, heap2);
}
