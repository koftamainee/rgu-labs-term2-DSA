#pragma once

#include "heap.h"

namespace lab1 {
class skew_heap : public heap {
 protected:
  class node {
   public:
    node *left_;
    node *right_;
    int priority_;
    char *value_;

    node(const char *value, int priority);
    virtual ~node() noexcept;
  };

  node *root_;
  std::size_t size_;

  void cleanup();
  void clean_node(node *root);
  void clone_heap(skew_heap const &from);
  node *clone_node(node const *to_clone);
  static void swap(node *&a, node *&b);

  static node *merge_nodes(node *a, node *b);

 public:
  skew_heap();
  ~skew_heap() noexcept override;
  skew_heap(skew_heap const &other);
  skew_heap &operator=(skew_heap const &other);

  [[nodiscard]] size_t size() const override;

  void insert(const char *value, int priority) override;
  [[nodiscard]] const char *top() const override;
  [[nodiscard]] int top_priority() const override;
  void pop() override;

  heap *merge(heap *other) override;
};

}  // namespace lab1
