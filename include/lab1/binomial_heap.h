#pragma once

#include "heap.h"

namespace lab1 {
class binomial_heap final : public heap {
 private:
 public:
  binomial_heap();
  binomial_heap(binomial_heap &other);
  ~binomial_heap();
  binomial_heap operator=(binomial_heap &other);

  [[nodiscard]] size_t size() const override;
  [[nodiscard]] size_t capacity() const override;
  void insert(const char *value, int priority) override;
  [[nodiscard]] const char *top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  binomial_heap &merge(heap &other) override;
};
}  // namespace lab1
