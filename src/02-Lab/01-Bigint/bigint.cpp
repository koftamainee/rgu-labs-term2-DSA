#include "bigint.h"

#include <cstring>

namespace lab2 {

int bigint::operator[](std::size_t) const {}

bigint::bigint() : sign_(0), numbers_(nullptr) {}

bigint::bigint(char const *value, std::size_t base) {}  // TODO

bigint::bigint(int const *value, std::size_t size) {}  // TODO

bigint::bigint(int value) {}

bigint::bigint(bigint const &other) : sign_(other.sign_) {
  // TODO
}

bigint::~bigint() noexcept { delete[] numbers_; }

std::optional<int> bigint::to_int() {
  if (numbers_ == nullptr) {
    return sign_;
  }
  return false;
}

bigint &bigint::operator=(bigint const &other) {
  // if (this == &other) {
  //   return *this;
  // }
  //
  // delete[] numbers_;
  //
  // sign_ = other.sign_;
  // size_ = other.size_;
  // capacity_ = other.capacity_;
  //
  // numbers_ = new int[capacity_];
  //
  // if (other.numbers_ != nullptr) {
  //   numbers_ = new int[capacity_];
  //   std::memcpy(numbers_, other.numbers_, size_);
  // }
  // return *this; // FIXME
}

bigint &bigint::operator++() & {}
bigint const bigint::operator++(int) & {}

bigint &bigint::operator--() & {}
bigint const bigint::operator--(int) & {}

bigint &bigint::operator+=(bigint const &other) & {}
bigint operator+(bigint const &first, bigint const &second) {}

bigint &bigint::operator-=(bigint const &other) & {}
bigint operator-(bigint const &first, bigint const &second) {}

bigint &bigint::operator*=(bigint const &other) & {}
bigint operator*(bigint const &first, bigint const &second) {}

bigint &bigint::operator/=(bigint const &other) & {}
bigint operator/(bigint const &first, bigint const &second) {}

bigint &bigint::operator%=(bigint const &other) & {}
bigint operator%(bigint const &first, bigint const &second) {}

bool operator==(bigint const &first, bigint const &second) {}
bool operator!=(bigint const &first, bigint const &second) {}

bool operator<(bigint const &first, bigint const &second) {}
bool operator<=(bigint const &first, bigint const &second) {}

bool operator>(bigint const &first, bigint const &second) {}
bool operator>=(bigint const &first, bigint const &second) {}

bigint bigint::operator~() {}

bigint &bigint::operator&=(bigint const &other) & {}
bigint operator&(bigint const &first, bigint const &second) {}

bigint &bigint::operator|=(bigint const &other) & {}
bigint operator|(bigint const &first, bigint const &second) {}

bigint &bigint::operator^=(bigint const &other) & {}
bigint operator^(bigint const &first, bigint const &second) {}

bigint &bigint::operator<<=(bigint const &other) & {}
bigint operator<<(bigint const &first, bigint const &second) {}

bigint &bigint::operator>>=(bigint const &other) & {}
bigint operator>>(bigint const &first, bigint const &second) {}

std::ostream &operator<<(std::ostream &out, bigint const &num) {}
std::istream &operator>>(std::istream &in, bigint &num) {}

}  // namespace lab2
