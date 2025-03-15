#include <cstring>

#include "fibonacci_heap.h"

namespace lab1 {

fibonacci_heap::node::node() : value_(nullptr), priority_(0) {}

fibonacci_heap::node::node(const char *value, int priority)
    : priority_(priority) {
  size_t len = std::strlen(value);
  value_ = new char[len];
  std::strcpy(value_, value);
}

fibonacci_heap::node::~node() { delete[] value_; }

void fibonacci_heap::node::cleanup() const {
  left_->right_ = nullptr;

  node *to_clean = right_;
  node *prev = nullptr;
  while (to_clean != nullptr) {
    prev = to_clean;
    to_clean = to_clean->right_;
    delete prev;
  }
  if (child_ != nullptr) {
    child_->cleanup();
    delete child_;
  }
}

fibonacci_heap::node *fibonacci_heap::clone_heap(node *other) {
  if (other == nullptr) {
    return nullptr;
  }

  node *copy = new node(other->value_, other->priority_);
  copy->degree_ = other->degree_;
  copy->mark_ = other->mark_;

  if (other->child_ != nullptr) {
    copy->child_ = clone_heap(other->child_);
    copy->child_->parent_ = copy;
  }

  node *curr = other->right_;
  node *prev_copy = copy;
  while (curr != other) {
    node *new_node = new node(curr->value_, curr->priority_);
    new_node->degree_ = curr->degree_;
    new_node->mark_ = curr->mark_;

    if (curr->child_ != nullptr) {
      new_node->child_ = clone_heap(curr->child_);
      new_node->child_->parent_ = new_node;
    }

    prev_copy->right_ = new_node;
    new_node->left_ = prev_copy;
    prev_copy = new_node;
    curr = curr->right_;
  }

  prev_copy->right_ = copy;
  copy->left_ = prev_copy;

  return copy;
}
}  // namespace lab1
