#pragma once

#include "heap.h"

namespace lab1 {

class binomial_heap final : public heap {
 private:
  class node {
   public:
    int priority_;
    char *value_;
    node *parent_;
    node *child_;
    node *sibling_;
    size_t degree_;

    node(const char *value, int priority);

    ~node() noexcept;
  };

  node *minimal_;
  node *roots_;
  size_t size_;

  void cleanup(node *n);
  void cleanup_list(node *n);
  void clone(const binomial_heap &other);

 public:
  binomial_heap();
  binomial_heap(const binomial_heap &other);
  ~binomial_heap() noexcept override;
  binomial_heap &operator=(const binomial_heap &other);

  [[nodiscard]] size_t size() const override;
  void insert(const char *value, int priority) override;
  [[nodiscard]] const char *top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  heap *merge(heap *other) override;
};
}  // namespace lab1
