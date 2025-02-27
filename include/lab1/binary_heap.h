#pragma once

#include <cstddef>

#include "heap.h"

namespace lab1 {
class binary_heap : public heap {
  struct node {
    char *value;
    int key;
  };
  node *heap_array;
  size_t capacity;
  size_t size;

 public:
  binary_heap();
  ~binary_heap() override;
  binary_heap &operator=(heap &other) override;

  char *top() override;
  void pop() override;

  //  public:
  //   BinaryHeap();
  //   ~BinaryHeap();
  //   BinaryHeap &operator=(heap &other) override;
  //   void insert(char *value, int key) override;
  //   char *top() override;
  //   void pop() override;
  //   BinaryHeap &merge(heap &other) override;
  //  public:
  //   BinaryHeap();
  //   ~BinaryHeap();
  //   BinaryHeap &operator=(heap &other) override;
  //   void insert(char *value, int key) override;
  //   char *top() override;
  //   void pop() override;
  //   BinaryHeap &merge(heap &other) override;
};
}  // namespace lab1
//
//
//
//
//
//
// namespace lab1 {

// class BinaryHeap : public heap {
//  private:
//   struct Node {
//     char *value;
//     int key;
//   };
//
//   Node *heapArray;
//   int capacity;
//   int size;
//
//   void resize();
//   void heapifyUp(int index);
//   void heapifyDown(int index);
//
//  public:
//   BinaryHeap();
//   ~BinaryHeap();
//   BinaryHeap &operator=(heap &other) override;
//   void insert(char *value, int key) override;
//   char *top() override;
//   void pop() override;
//   BinaryHeap &merge(heap &other) override;
// };
//
// }  // namespace lab1
