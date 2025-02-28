#include "lab1/tests/test_binary_heap.h"

#include <iostream>

#include "lab1/binary_heap.h"

namespace {
void demonstrate_insert_and_top(lab1::binary_heap &heap) {
  std::cout << "Demonstrating insert and top operations:\n";
  heap.insert("Task1", 3);
  heap.insert("Task2", 3);
  heap.insert("Task4", 3);
  heap.insert("Task5", 3);
  heap.insert("Task6", -5);
  heap.insert("Task7", 0);
  heap.insert("Task8", 7);
  heap.insert("Task9", 5);

  std::cout << "Top element: " << heap.top()
            << " with priority: " << heap.top_priority() << "\n";
}

void demonstrate_pop(lab1::binary_heap &heap) {
  std::cout << "\nDemonstrating pop operation:\n";
  std::cout << "Before pop, top element: " << heap.top()
            << " with priority: " << heap.top_priority() << "\n";
  heap.pop();
  std::cout << "After pop, top element: " << heap.top()
            << " with priority: " << heap.top_priority() << "\n";
}

void demonstrate_merge(lab1::binary_heap &heap1, lab1::binary_heap &heap2) {
  std::cout << "\nDemonstrating merge operation:\n";
  heap1.insert("Task4", 5);
  heap2.insert("Task5", 4);

  heap1.merge(heap2);

  std::cout << "After merge, top element of heap1: " << heap1.top()
            << " with priority: " << heap1.top_priority() << "\n";
  std::cout << "heap1 size: " << heap1.size() << " heap2 size: " << heap2.size()
            << std::endl;
}
}  // namespace

void lab1::test::binary_heap(int argc, char **argv) {
  lab1::binary_heap heap1;
  lab1::binary_heap heap2;

  std::cout << "Heap1:" << std::endl;
  demonstrate_insert_and_top(heap1);
  std::cout << std::endl << "Heap2:" << std::endl;
  demonstrate_insert_and_top(heap2);

  demonstrate_pop(heap1);

  demonstrate_merge(heap1, heap2);
}
