#include <cstring>

#include "binomial_heap.h"

namespace lab1 {
binomial_heap::node::node(const char* value, int priority)
    : priority_(priority),
      sibling_(nullptr),
      child_(nullptr),
      parent_(nullptr) {
  if (value != nullptr) {
    size_t len = std::strlen(value) + 1;
    value_ = new char[len];
    std::strcpy(value_, value);
  } else {
    value_ = nullptr;
  }
}

binomial_heap::node::~node() noexcept { delete[] value_; }

}  // namespace lab1
