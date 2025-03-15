#include "bigint.h"

#include <cstring>

namespace lab2 {
bigint::bigint() : sign_(0), numbers_(nullptr), size_(0), capacity_(0) {}

bigint::bigint(char const *value, std::size_t base) {}  // TODO

bigint::bigint(int const *value, std::size_t size) {}  // TODO

bigint::bigint(int value)
    : sign_(value), numbers_(nullptr), size_(0), capacity_(0) {}

bigint::bigint(bigint const &other)
    : size_(other.sign_), sign_(other.sign_), capacity_(other.capacity_) {
  if (other.numbers_ != nullptr) {
    numbers_ = new int[capacity_];
    std::memcpy(numbers_, other.numbers_, size_);
  }
}

bigint::~bigint() noexcept { delete[] numbers_; }

std::optional<int> bigint::to_int() {
  if (numbers_ == nullptr) {
    return sign_;
  }
  return false;
}

bigint &bigint::operator=(bigint const &other) {
  if (this == &other) {
    return *this;
  }

  delete[] numbers_;

  sign_ = other.sign_;
  size_ = other.size_;
  capacity_ = other.capacity_;

  numbers_ = new int[capacity_];

  if (other.numbers_ != nullptr) {
    numbers_ = new int[capacity_];
    std::memcpy(numbers_, other.numbers_, size_);
  }
  return *this;
}

}  // namespace lab2
