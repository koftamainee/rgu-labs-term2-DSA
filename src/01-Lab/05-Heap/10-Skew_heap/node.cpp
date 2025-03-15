#include <cstring>

#include "skew_heap.h"

namespace lab1 {

skew_heap::node::node(char const *value, int priority)
    : left_(nullptr), right_(nullptr) {
  std::size_t len = strlen(value);
  value_ = new char[len + 1];
  std::strcpy(value_, value);
  priority_ = priority;
}

skew_heap::node::~node() noexcept { delete[] value_; }

}  // namespace lab1
