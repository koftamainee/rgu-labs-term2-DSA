#pragma once

#include <cstddef>

namespace lab1 {

class logical_values_array final {
 private:
  unsigned int value_;

 public:
  logical_values_array(unsigned int value = 0);
  ~logical_values_array() noexcept = default;
  logical_values_array(const logical_values_array& other) = default;
  logical_values_array& operator=(const logical_values_array& other) = default;

  [[nodiscard]] unsigned int value() const;

  [[nodiscard]] logical_values_array logical_not() const;
  [[nodiscard]] logical_values_array logical_and(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_or(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_implication(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_coimplication(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_xor(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_equivalence(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_pierce_arrow(
      const logical_values_array& other) const;
  [[nodiscard]] logical_values_array logical_sheffer_stroke(
      const logical_values_array& other) const;

  [[nodiscard]] static bool equals(const logical_values_array& first,
                                   const logical_values_array& second) {
    return (first.value_ == second.value_);
  }

  [[nodiscard]] bool at(size_t pos) const;
  bool operator[](size_t pos) const;

  void to_binary_string(char* buffer) const;
};

}  // namespace lab1
