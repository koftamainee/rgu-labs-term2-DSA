#include "logical_values_array.h"

#include <stdexcept>

namespace lab1 {
logical_values_array::logical_values_array(unsigned int value) {
  value_ = value;
}

unsigned int logical_values_array::value() const { return value_; }

logical_values_array logical_values_array::logical_not() const {
  return {~value_};
}

logical_values_array logical_values_array::logical_and(
    const logical_values_array& other) const {
  return {value_ & other.value_};
}
logical_values_array logical_values_array::logical_or(
    const logical_values_array& other) const {
  return {value_ | other.value_};
}

logical_values_array logical_values_array::logical_implication(
    const logical_values_array& other) const {
  return {~value_ | other.value_};
}

logical_values_array logical_values_array::logical_coimplication(
    const logical_values_array& other) const {
  return {value_ | ~other.value_};
}

logical_values_array logical_values_array::logical_xor(
    const logical_values_array& other) const {
  return {value_ ^ other.value_};
}

logical_values_array logical_values_array::logical_equivalence(
    const logical_values_array& other) const {
  return {~(value_ ^ other.value_)};
}

logical_values_array logical_values_array::logical_pierce_arrow(
    const logical_values_array& other) const {
  return {~(value_ | other.value_)};
}
logical_values_array logical_values_array::logical_sheffer_stroke(
    const logical_values_array& other) const {
  return {~(value_ & other.value_)};
}

bool logical_values_array::at(size_t pos) const {
  if (pos > sizeof(value_) * 8) {
    throw std::out_of_range("Too big index for logical_values_array");
  }
  return (*this)[pos];
}
bool logical_values_array::operator[](size_t pos) const {
  return ((value_ >> pos) & 1) != 0U;
}

void logical_values_array::to_binary_string(char* buffer) const {
  unsigned int mask = 1 << (sizeof(value_) * 8 - 1);
  for (int i = 0; i < sizeof(value_) * 8; ++i) {
    *buffer++ = ((value_ & mask) != 0U) ? '1' : '0';
    mask >>= 1;
  }
  *buffer = '\0';
}
}  // namespace lab1
