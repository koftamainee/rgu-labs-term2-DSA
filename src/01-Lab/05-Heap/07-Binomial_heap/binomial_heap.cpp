#include "lab1/binomial_heap.h"

#include <cstring>

namespace lab1 {

binomial_heap::node::node(int priority, const char *value)
    : priority_(priority),
      value_(nullptr),
      parent_(nullptr),
      child_(nullptr),
      sibling_(nullptr) {
  value_ = new char[strlen(value) + 1];
  std::strcpy(value_, value);
}

binomial_heap::node::~node() noexcept {
  delete[] value_;
  delete child_;
  delete sibling_;
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

void binomial_heap::copy_from(const binomial_heap &other) {
  if (other.roots_ != nullptr) {
    roots_ = other.roots_->clone();
    size_ = other.size_;

    minimal_ = roots_;
    for (node *current = roots_; current != nullptr;
         current = current->sibling_) {
      if (current->priority_ < minimal_->priority_) {
        minimal_ = current;
      }
    }
  } else {
    roots_ = nullptr;
    minimal_ = nullptr;
    size_ = 0;
  }
}

void binomial_heap::cleanup() {
  delete roots_;
  minimal_ = nullptr;
  size_ = 0;
}

binomial_heap::binomial_heap() : size_(0), minimal_(nullptr), roots_(nullptr) {}

binomial_heap::binomial_heap(binomial_heap &other) { copy_from(other); }

binomial_heap::~binomial_heap() noexcept { cleanup(); }

binomial_heap binomial_heap::operator=(binomial_heap &other) {
  if (this == &other) {
    return *this;
  }
  cleanup();
  copy_from(other);
  return *this;
}

[[nodiscard]] size_t binomial_heap::size() const { return size_; }

void binomial_heap::insert(const char *value, int priority) {}
[[nodiscard]] const char *binomial_heap::top() const {
  return minimal_->value_;
}
[[nodiscard]] int binomial_heap::top_priority() const {
  return minimal_->priority_;
}
void binomial_heap::pop() {}

binomial_heap &binomial_heap::merge(heap &other) {}
}  // namespace lab1
