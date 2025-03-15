#include "leftist_heap.h"

#include <stdexcept>

namespace lab1 {

int leftist_heap::get_rank(node *n) { return (n != nullptr) ? n->rank_ : 0; }

leftist_heap::node *leftist_heap::merge_nodes(node *a, node *b) {
  if (a == nullptr) {
    return b;
  }
  if (b == nullptr) {
    return a;
  }

  if (a->priority_ < b->priority_) {
    node *temp = a;
    a = b;
    b = temp;
  }

  a->right_ = merge_nodes(static_cast<node *>(a->right_), b);

  if (get_rank(static_cast<node *>(a->left_)) <
      get_rank(static_cast<node *>(a->right_))) {
    node *temp = static_cast<node *>(a->left_);
    a->left_ = a->right_;
    a->right_ = temp;
  }

  a->rank_ = get_rank(static_cast<node *>(a->right_)) + 1;
  return a;
}

heap *leftist_heap::merge(heap *other) {
  skew_heap::merge(other);
  auto *other_lh = dynamic_cast<leftist_heap *>(other);
  if (other_lh == nullptr) {
    throw std::invalid_argument("Invalid heap type");
  }

  root_ = merge_nodes(static_cast<node *>(root_),
                      static_cast<node *>(other_lh->root_));
  size_ += other_lh->size_;
  other_lh->root_ = nullptr;
  other_lh->size_ = 0;
  return this;
}

}  // namespace lab1
