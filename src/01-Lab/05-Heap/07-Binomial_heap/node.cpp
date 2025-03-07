#include <cstring>

#include "lab1/binomial_heap.h"

namespace lab1 {
binomial_heap::node::node(const char* value, int priority)
    : priority_(priority),
      parent_(nullptr),
      child_(nullptr),
      sibling_(nullptr),
      degree_(0) {
  if (value != nullptr) {
    size_t len = std::strlen(value) + 1;
    value_ = new char[len];
    std::strcpy(value_, value);
  } else {
    value_ = nullptr;
  }
}

binomial_heap::node::~node() noexcept { delete[] value_; }

binomial_heap::node* binomial_heap::node::clone() const {
  node* new_node = new node(value_, priority_);
  new_node->degree_ = degree_;
  if (child_ != nullptr) {
    new_node->child_ = child_->clone();
    node* current = new_node->child_;
    node* orig = child_->sibling_;
    while (orig != nullptr) {
      current->sibling_ = orig->clone();
      current = current->sibling_;
      orig = orig->sibling_;
    }
  }
  return new_node;
}

}  // namespace lab1
