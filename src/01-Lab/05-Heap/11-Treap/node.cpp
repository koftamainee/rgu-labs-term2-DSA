#include <cstdlib>
#include <cstring>

#include "treap.h"

namespace lab1 {

treap::node::node(char const *value, int key, int priority)
    : key_(key), left_(nullptr), right_(nullptr), priority_(priority) {
  std::size_t len = strlen(value);
  value_ = new char[len + 1];
  std::strcpy(value_, value);
}

treap::node::node(node const &other)
    : key_(other.key_),
      left_(nullptr),
      right_(nullptr),
      priority_(other.priority_) {
  std::size_t len = strlen(other.value_);
  value_ = new char[len + 1];
  std::strcpy(value_, other.value_);
}

treap::node::~node() noexcept { delete[] value_; }

}  // namespace lab1
