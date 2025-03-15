#include "skew_heap.h"

#include <stdexcept>

namespace lab1 {

void skew_heap::cleanup() { clean_node(root_); }

void skew_heap::clean_node(node *root) {
  if (root == nullptr) {
    return;
  }
  clean_node(root->left_);
  clean_node(root->right_);
  delete root;
}

void skew_heap::clone_heap(skew_heap const &from) {
  root_ = clone_node(from.root_);
  size_ = from.size_;
}

skew_heap::node *skew_heap::clone_node(node const *to_clone) {
  if (to_clone == nullptr) {
    return nullptr;
  }
  auto *new_node = new node(to_clone->value_, to_clone->priority_);

  new_node->left_ = clone_node(to_clone->left_);
  new_node->right_ = clone_node(to_clone->right_);
  return new_node;
}

skew_heap::skew_heap() : root_(nullptr), size_(0) {}

skew_heap::~skew_heap() noexcept { cleanup(); }

skew_heap::skew_heap(skew_heap const &other) { clone_heap(other); }

skew_heap &skew_heap::operator=(skew_heap const &other) {
  if (&other == this) {
    return *this;
  }
  cleanup();
  clone_heap(other);
  return *this;
}

[[nodiscard]] size_t skew_heap::size() const { return size_; }

void skew_heap::insert(const char *value, int priority) {
  root_ = merge_nodes(root_, new node(value, priority));
  ++size_;
}

[[nodiscard]] const char *skew_heap::top() const {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  return root_->value_;
}

[[nodiscard]] int skew_heap::top_priority() const {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  return root_->priority_;
}

void skew_heap::pop() {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  node *to_delete = root_;
  root_ = merge_nodes(root_->left_, root_->right_);
  delete to_delete;
  --size_;
}

heap *skew_heap::merge(heap *other_heap) {
  auto *other = dynamic_cast<skew_heap *>(other_heap);
  if (other == nullptr) {
    throw std::invalid_argument("Invalid heap type");
  }

  if (size_ == 0) {
    root_ = other->root_;
    size_ = other->size_;
    other->root_ = nullptr;
    other->size_ = 0;
    return this;
  }
  if (other->size_ == 0) {
    return this;
  }
  size_ += other->size_;
  root_ = merge_nodes(root_, other->root_);
  other->root_ = nullptr;
  other->size_ = 0;
  return this;
}

skew_heap::node *skew_heap::merge_nodes(node *a, node *b) {
  if (a == nullptr) {
    return b;
  }
  if (b == nullptr) {
    return a;
  }
  if (a->priority_ > b->priority_) {
    swap(a, b);
  }
  swap(a->left_, a->right_);
  a->left_ = merge_nodes(b, a->left_);
  return a;
}

void skew_heap::swap(node *&a, node *&b) {
  node *temp = a;
  a = b;
  b = temp;
}

}  // namespace lab1
