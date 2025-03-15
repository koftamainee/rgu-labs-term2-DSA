#include "fibonacci_heap.h"

#include <cmath>
#include <stdexcept>

namespace lab1 {

fibonacci_heap::fibonacci_heap() : size_(0), min_(nullptr) {}

fibonacci_heap::~fibonacci_heap() noexcept {
  if (min_ != nullptr) {
    min_->cleanup();
    delete min_;
  }
}

fibonacci_heap::fibonacci_heap(const fibonacci_heap &other) {
  min_ = clone_heap(other.min_);
  size_ = other.size_;
}

fibonacci_heap &fibonacci_heap::operator=(const fibonacci_heap &other) {
  if (this == &other) {
    return *this;
  }

  if (min_ != nullptr) {
    min_->cleanup();
    delete min_;
  }

  min_ = clone_heap(other.min_);
  size_ = other.size_;
  return *this;
}

[[nodiscard]] size_t fibonacci_heap::size() const { return size_; }

void fibonacci_heap::insert(const char *value, int priority) {
  auto *new_node = new node(value, priority);
  if (size_ == 0) {
    min_ = new_node;
    min_->left_ = min_;
    min_->right_ = min_;

  } else {
    node *prev_right = min_->right_;
    min_->right_ = new_node;
    new_node->left_ = min_;
    new_node->right_ = prev_right;
    prev_right->left_ = new_node;

    if (new_node->priority_ < min_->priority_) {
      min_ = new_node;
    }
    new_node->parent_ = nullptr;
  }

  ++size_;
}

void fibonacci_heap::union_lists(node *first, node *second) const {
  if (first == nullptr || second == nullptr) {
    return;
  }
  node *L = first->left_;
  node *R = second->right_;
  second->right_ = first;
  first->left_ = second;
  L->right_ = R;
  R->left_ = L;
}

[[nodiscard]] const char *fibonacci_heap::top() const {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  return min_->value_;
}

[[nodiscard]] int fibonacci_heap::top_priority() const {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  return min_->priority_;
}

void fibonacci_heap::pop() {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }

  node *prev_min = min_;

  if (min_->child_ != nullptr) {
    node *child = min_->child_;
    do {
      node *next_child = child->right_;
      union_lists(min_, child);
      child->parent_ = nullptr;
      child = next_child;
    } while (child != min_->child_);
  }

  node *L = min_->left_;
  node *R = min_->right_;
  L->right_ = R;
  R->left_ = L;

  if (min_->right_ == min_) {
    delete min_;
    min_ = nullptr;
    size_ = 0;
    return;
  }
  delete min_;
  min_ = R;
  consolidate();
  --size_;
}

void fibonacci_heap::consolidate() {
  const auto array_size = static_cast<size_t>(std::ceil(std::log2(size_ + 1)));
  node **A = new node *[array_size]();

  node *current = min_;
  do {
    node *next = current->right_;
    node *degree_node = A[current->degree_];

    while (degree_node != nullptr) {
      node *add_to;
      node *adding;
      if (degree_node->priority_ < current->priority_) {
        add_to = degree_node;
        adding = current;
      } else {
        add_to = current;
        adding = degree_node;
      }

      union_lists(add_to->child_, adding);
      adding->parent_ = add_to;
      A[add_to->degree_] = nullptr;
      ++(add_to->degree_);
      current = add_to;
      degree_node = A[current->degree_];
    }

    A[current->degree_] = current;
    current = next;
  } while (current != min_);

  min_ = nullptr;
  for (int i = 0; i < array_size; ++i) {
    if (A[i] != nullptr) {
      if ((min_ == nullptr) || A[i]->priority_ < min_->priority_) {
        min_ = A[i];
      }
    }
  }

  delete[] A;
}

heap *fibonacci_heap::merge(heap *other_heap) {
  auto *other = dynamic_cast<fibonacci_heap *>(other_heap);
  if (other == nullptr) {
    throw std::invalid_argument("Invalid heap type");
  }
  if (other->size_ == 0) {
    return this;
  }

  if (size_ == 0) {
    min_ = other->min_;
    size_ = other->size_;
  } else {
    union_lists(min_, other->min_);
    size_ += other->size_;
  }
  if ((min_ != nullptr) || ((other->min_ != nullptr) && other->min_ < min_)) {
    min_ = other->min_;
  }

  other->min_ = nullptr;
  other->size_ = 0;

  return this;
}

}  // namespace lab1
