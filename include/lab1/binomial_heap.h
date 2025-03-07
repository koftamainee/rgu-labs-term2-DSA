#pragma once

#include "heap.h"

namespace lab1 {

class binomial_heap final : public heap {
 private:
  class node {
   public:
    int priority_;
    char* value_;
    node* parent_;
    node* child_;
    node* sibling_;
    size_t degree_;

    node(int priority, const char* value);

    ~node() noexcept;

    [[nodiscard]] node* clone() const;
  };

  node* minimal_;
  node* roots_;
  size_t size_;

  void copy_from(const binomial_heap& other);
  void cleanup();

  node* circular_to_linear(node* circ);
  node* linear_to_circular(node* head);
  node* merge_root_lists(node* list1, node* list2);
  node* consolidate(node* head);
  node* find_minimum(node* circ) const;
  node* remove_from_circular(node* circ, node* target);
  node* reverse_list(node* head);

 public:
  binomial_heap();
  binomial_heap(binomial_heap& other);
  ~binomial_heap() noexcept;
  binomial_heap& operator=(binomial_heap& other);

  [[nodiscard]] size_t size() const override;
  void insert(const char* value, int priority) override;
  [[nodiscard]] const char* top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  binomial_heap& merge(heap& other) override;
};
}  // namespace lab1
