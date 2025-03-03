#include "lab1/binomial_heap.h"

namespace lab1 {
binomial_heap::binomial_heap() : head_(nullptr), size_(0) {}

binomial_heap::binomial_heap(binomial_heap &other) {}
binomial_heap::~binomial_heap() {
  while (size_ > 0) {
    pop();
  }
}
binomial_heap binomial_heap::operator=(binomial_heap &other) {
  if (&other == this) {
    return *this;
  }
}
//
// [[nodiscard]] size_t size() const override;
// [[nodiscard]] size_t capacity() const override;
// void insert(const char *value, int priority) override;
// [[nodiscard]] const char *top() const override;
// [[nodiscard]] int top_priority() const override;
// void pop() override;
//
// binomial_heap &merge(binomial_heap &other);
}  // namespace lab1
