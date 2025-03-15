#pragma once

#include "skew_heap.h"

namespace lab1 {

class leftist_heap final : public skew_heap {
 private:
  class node : public skew_heap::node {
   public:
    int rank_;

    node(const char *value, int priority);
  };

  static int get_rank(node *n);
  static node *merge_nodes(node *a, node *b);

 public:
  heap *merge(heap *other) override;
};

}  // namespace lab1
