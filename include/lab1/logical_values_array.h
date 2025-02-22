#pragma once

#include <cstddef>

namespace lab1 {

class logical_values_array {
 private:
  unsigned int value_;

 public:
  logical_values_array(unsigned int value = 0);
  ~logical_values_array() = default;
  logical_values_array(const logical_values_array& other) = default;
  logical_values_array& operator=(const logical_values_array& other) = default;

  unsigned int value() const;

  logical_values_array logical_not() const;
  logical_values_array logical_and(const logical_values_array& other) const;
  logical_values_array logical_or(const logical_values_array& other) const;
  logical_values_array logical_implication(
      const logical_values_array& other) const;
  logical_values_array logical_coimplication(
      const logical_values_array& other) const;
  logical_values_array logical_xor(const logical_values_array& other) const;
  logical_values_array logical_equivalence(
      const logical_values_array& other) const;
  logical_values_array logical_pierce_arrow(
      const logical_values_array& other) const;
  logical_values_array logical_sheffer_stroke(
      const logical_values_array& other) const;

  bool equals(const logical_values_array& other);

  bool at(size_t pos) const;
  bool operator[](size_t pos) const;

  void to_binary_string(char* buffer) const;
};

}  // namespace lab1
