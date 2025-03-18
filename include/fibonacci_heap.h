#pragma once

#include "heap.h"

namespace lab1 {

class fibonacci_heap final : public heap {
 private:
  class node {
   public:
    int priority_;
    char *value_;
    node *parent_;
    node *child_;
    node *left_;
    node *right_;
    size_t degree_;
    bool mark_;

    node(const char *value, int priority);
    node();
    node(const node &other) = default;
    node &operator=(const node &other) = default;
    ~node();

    void cleanup() const;
  };

  size_t size_;
  node *min_;

  node *clone_heap(node *other);

  void union_lists(node *first, node *second) const;
  void consolidate();

 public:
  fibonacci_heap();
  ~fibonacci_heap() noexcept override;
  fibonacci_heap(const fibonacci_heap &other);
  fibonacci_heap &operator=(const fibonacci_heap &other);

  [[nodiscard]] size_t size() const override;
  void insert(const char *value, int priority) override;
  [[nodiscard]] const char *top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  heap *merge(heap *other) override;
};

}  // namespace lab1
