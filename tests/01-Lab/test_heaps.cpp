#include "tests/test_heaps.h"

#include <iostream>

namespace lab1::test::heaps {
void demonstrate_insert_and_top(lab1::heap &heap) {
  std::cout << "Demonstrating insert and top operations:\n";
  heap.insert("Task1", 3);
  heap.insert("Task2", 3);
  heap.insert("Task4", 3);
  heap.insert("Task5", 3);
  heap.insert("Task6", -5);
  heap.insert("Task7", 0);
  heap.insert("Task8", 7);
  heap.insert("Task9", 5);
  heap.insert("Task10", 43);
  heap.insert("Task11", 12);
  heap.insert("Task12", 491);

  std::cout << "Top element: " << heap.top()
            << " with priority: " << heap.top_priority() << "\n";
}

void demonstrate_pop(lab1::heap &heap) {
  std::cout << "\nDemonstrating pop operation:\n";
  std::cout << "Before pop, top element: " << heap.top()
            << " with priority: " << heap.top_priority() << "\n";
  heap.pop();
  std::cout << "After pop, top element: " << heap.top()
            << " with priority: " << heap.top_priority() << "\n";
}

void demonstrate_merge(lab1::heap &heap1, lab1::heap &heap2) {
  std::cout << "\nDemonstrating merge operation:\n";
  heap1.insert("Task4", 5);
  heap2.insert("Task5", 4);

  heap1.merge(&heap2);

  std::cout << "After merge, top element of heap1: " << heap1.top()
            << " with priority: " << heap1.top_priority() << "\n";
  std::cout << "heap1 size: " << heap1.size() << " heap2 size: " << heap2.size()
            << std::endl;
}
}  // namespace lab1::test::heaps
