#include "binomial_heap.h"

#include <cstring>
#include <stdexcept>

namespace lab1 {

void binomial_heap::cleanup(node *n) {
  if (n == nullptr) {
    return;
  }
  while (n != nullptr) {
    cleanup(n->child_);
    node *prev = n;
    n = n->sibling_;
    delete prev;
  }
}

void binomial_heap::clone(const binomial_heap &other) {
  if (other.size_ > 0) {
    node *other_cur = other.roots_;
    node **new_pos = &roots_;
    while (other_cur != nullptr) {
      *new_pos = new node(*other_cur);
      new_pos = &((*new_pos)->sibling_);
      other_cur = other_cur->sibling_;
    }
    minimal_ = roots_;
    for (node *cur = roots_; cur != nullptr; cur = cur->sibling_) {
      if (cur->priority_ < minimal_->priority_) {
        minimal_ = cur;
      }
    }
    size_ = other.size_;
  }
}

binomial_heap::binomial_heap() : minimal_(nullptr), roots_(nullptr), size_(0) {}

binomial_heap::binomial_heap(const binomial_heap &other)
    : minimal_(nullptr), roots_(nullptr), size_(0) {
  clone(other);
}

binomial_heap::~binomial_heap() noexcept { cleanup(roots_); }

binomial_heap &binomial_heap::operator=(const binomial_heap &other) {
  if (this != &other) {
    node *cur = roots_;
    while (cur != nullptr) {
      node *next = cur->sibling_;
      delete cur;
      cur = next;
    }
    roots_ = nullptr;
    minimal_ = nullptr;
    size_ = 0;

    clone(other);
  }
  return *this;
}

size_t binomial_heap::size() const { return size_; }

void binomial_heap::insert(const char *value, int priority) {
  binomial_heap temp;
  temp.roots_ = new node(value, priority);
  temp.minimal_ = temp.roots_;
  temp.size_ = 1;
  merge(&temp);
}

const char *binomial_heap::top() const {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  return minimal_->value_;
}

int binomial_heap::top_priority() const {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }
  return minimal_->priority_;
}

void binomial_heap::pop() {
  if (size_ == 0) {
    throw std::invalid_argument("Heap is empty");
  }

  node *prev = nullptr;
  node *cur = roots_;
  while ((cur != nullptr) && cur != minimal_) {
    prev = cur;
    cur = cur->sibling_;
  }

  if (prev != nullptr) {
    prev->sibling_ = cur->sibling_;
  } else {
    roots_ = cur->sibling_;
  }

  node *child = cur->child_;
  node *reversed = nullptr;
  while (child != nullptr) {
    node *next = child->sibling_;
    child->sibling_ = reversed;
    child->parent_ = nullptr;
    reversed = child;
    child = next;
  }

  delete cur;
  size_--;

  binomial_heap temp;
  temp.roots_ = reversed;
  merge(&temp);
}

heap *binomial_heap::merge(heap *other) {
  auto *other_heap = dynamic_cast<binomial_heap *>(other);
  if (other_heap == nullptr) {
    throw std::invalid_argument("Invalid heap type");
  }

  node *new_roots = nullptr;
  node **pos = &new_roots;
  node *h1 = roots_;
  node *h2 = other_heap->roots_;

  while ((h1 != nullptr) && (h2 != nullptr)) {
    if (h1->degree_ < h2->degree_) {
      *pos = h1;
      h1 = h1->sibling_;
    } else {
      *pos = h2;
      h2 = h2->sibling_;
    }
    pos = &((*pos)->sibling_);
  }
  *pos = (h1 != nullptr) ? h1 : h2;

  roots_ = new_roots;
  minimal_ = nullptr;

  node *prev = nullptr;
  node *cur = roots_;
  node *next = (roots_ != nullptr) ? roots_->sibling_ : nullptr;
  while (next != nullptr) {
    if (cur->degree_ != next->degree_ ||
        ((next->sibling_ != nullptr) &&
         next->sibling_->degree_ == cur->degree_)) {
      prev = cur;
      cur = next;
    } else if (cur->priority_ <= next->priority_) {
      cur->sibling_ = next->sibling_;
      next->parent_ = cur;
      next->sibling_ = cur->child_;
      cur->child_ = next;
      cur->degree_++;
    } else {
      if (prev == nullptr) {
        roots_ = next;
      } else {
        prev->sibling_ = next;
      }
      cur->parent_ = next;
      cur->sibling_ = next->child_;
      next->child_ = cur;
      next->degree_++;
      cur = next;
    }
    next = cur->sibling_;
  }

  for (node *it = roots_; it != nullptr; it = it->sibling_) {
    if ((minimal_ == nullptr) || it->priority_ < minimal_->priority_) {
      minimal_ = it;
    }
  }
  size_ += other_heap->size_;
  other_heap->roots_ = nullptr;
  other_heap->minimal_ = nullptr;
  other_heap->size_ = 0;
  return this;
}

}  // namespace lab1
