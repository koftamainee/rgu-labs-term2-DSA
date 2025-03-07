#include "lab1/tests/test_binomial_heap.h"

#include <iostream>

#include "lab1/binomial_heap.h"

namespace {

void demo_insert() {
  std::cout << "Demo Insert:" << std::endl;
  lab1::binomial_heap heap;
  heap.insert("apple", 5);
  heap.insert("banana", 3);
  heap.insert("cherry", 7);
  std::cout << "Heap top (min element): " << heap.top() << " with priority "
            << heap.top_priority() << std::endl
            << std::endl;
}

// Demonstrates merging two heaps.
void demo_merge() {
  std::cout << "Demo Merge:" << std::endl;
  lab1::binomial_heap heap1;
  lab1::binomial_heap heap2;

  // Fill first heap.
  heap1.insert("alpha", 10);
  heap1.insert("beta", 15);

  // Fill second heap.
  heap2.insert("gamma", 5);
  heap2.insert("delta", 20);

  // Merge heap2 into heap1.
  heap1.merge(heap2);
  std::cout << "After merging, heap top: " << heap1.top() << " with priority "
            << heap1.top_priority() << std::endl;
  std::cout << "Heap2 size after merge: " << heap2.size() << " (should be 0)"
            << std::endl
            << std::endl;
}

// Demonstrates removal (pop) operations.
void demo_pop() {
  std::cout << "Demo Pop:" << std::endl;
  lab1::binomial_heap heap;
  heap.insert("first", 8);
  heap.insert("second", 2);
  heap.insert("third", 4);

  std::cout << "Before pop, top: " << heap.top() << " with priority "
            << heap.top_priority() << std::endl;
  heap.pop();
  std::cout << "After one pop, top: " << heap.top() << " with priority "
            << heap.top_priority() << std::endl;
  heap.pop();
  std::cout << "After second pop, top: " << heap.top() << " with priority "
            << heap.top_priority() << std::endl;
  std::cout << "Remaining size: " << heap.size() << std::endl << std::endl;
}

}  // namespace

namespace lab1::test {
void binomial_heap(int argc, char **argv) {
  demo_insert();
  demo_pop();
  demo_merge();
}
}  // namespace lab1::test
