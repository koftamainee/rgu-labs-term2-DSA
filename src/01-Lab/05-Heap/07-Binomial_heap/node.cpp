#include <cstring>

#include "lab1/binomial_heap.h"

namespace lab1 {
binomial_heap::node::node(int priority, const char *value)
    : priority_(priority),
      value_(nullptr),
      parent_(nullptr),
      child_(nullptr),
      sibling_(nullptr) {
  size_t len = std::strlen(value);
  value_ = new char[len + 1];
  std::strcpy(value_, value);
}

binomial_heap::node::~node() noexcept {
  delete[] value_;

  node *current = child_;
  while (current != nullptr) {
    node *next = current->sibling_;
    current->sibling_ = nullptr;
    delete current;
    current = next;
  }
}

[[nodiscard]] binomial_heap::node *binomial_heap::node::clone() const {
  node *new_node = new node(priority_, value_);
  new_node->degree_ = degree_;

  if (child_ != nullptr) {
    new_node->child_ = child_->clone();
    new_node->child_->parent_ = new_node;
  }

  if (sibling_ != nullptr) {
    new_node->sibling_ = sibling_->clone();
  }
  return new_node;
}

}  // namespace lab1
