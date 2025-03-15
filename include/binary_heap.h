#pragma once

#include <cstddef>

#include "heap.h"

namespace lab1 {
class binary_heap final : public heap {
  const size_t BINARY_HEAP_INITIAL_CAPACITY = 16;
  const size_t BINARY_HEAP_GROWTH_FACTOR = 2;
  struct node {
    char *value;
    int priority;
  };
  node *heap_array_;
  size_t capacity_;
  size_t size_;

  void resize(size_t new_capacity);
  void sift_up(size_t index);
  void sift_down(size_t index);

  void swap(node &first, node &second);

 public:
  binary_heap();
  binary_heap(const binary_heap &other);
  ~binary_heap() noexcept override;
  binary_heap &operator=(const binary_heap &other);

  [[nodiscard]] size_t size() const override;
  [[nodiscard]] size_t capacity() const;

  void insert(const char *value, int priority) override;
  [[nodiscard]] const char *top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  heap *merge(heap *other) override;
};
}  // namespace lab1
