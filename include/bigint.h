#pragma once

#include <cstddef>
#include <iostream>
#include <optional>

namespace lab2 {

class bigint final {
 private:
  static constexpr size_t base_ = size_t{1} << (8 * sizeof(int));

  int sign_;
  int *numbers_;

  std::size_t size_;
  std::size_t capacity_;

 public:
  bigint();
  bigint(char const *value, std::size_t base);
  bigint(int const *value, std::size_t size);
  bigint(long long value);
  bigint(bigint const &other);
  ~bigint() noexcept;

  std::optional<int> to_int();

  bigint &operator=(bigint const &other);

  bigint &operator++() &;
  bigint operator++(int) &;

  bigint &operator--() &;
  bigint operator--(int) &;

  bigint &operator+=(bigint const &other) &;
  friend bigint operator+(bigint const &first, bigint const &second);

  bigint &operator-=(bigint const &other) &;
  friend bigint operator-(bigint const &first, bigint const &second);

  bigint &operator*=(bigint const &other) &;
  friend bigint operator*(bigint const &first, bigint const &second);

  bigint &operator/=(bigint const &other) &;
  friend bigint operator/(bigint const &first, bigint const &second);

  bigint &operator%=(bigint const &other) &;
  friend bigint operator%(bigint const &first, bigint const &second);

  friend bool operator==(bigint const &first, bigint const &second);
  friend bool operator!=(bigint const &first, bigint const &second);

  friend bool operator<(bigint const &first, bigint const &second);
  friend bool operator<=(bigint const &first, bigint const &second);

  friend bool operator>(bigint const &first, bigint const &second);
  friend bool operator>=(bigint const &first, bigint const &second);

  bigint operator~();

  bigint &operator&=(bigint const &other) &;
  friend bigint operator&(bigint const &first, bigint const &second);

  bigint &operator|=(bigint const &other) &;
  friend bigint operator|(bigint const &first, bigint const &second);

  bigint &operator^=(bigint const &other) &;
  friend bigint operator^(bigint const &first, bigint const &second);

  bigint &operator<<=(bigint const &other) &;
  friend bigint operator<<(bigint const &first, bigint const &second);

  bigint &operator>>=(bigint const &other) &;
  friend bigint operator>>(bigint const &first, bigint const &second);

  friend std::ostream &operator<<(std::ostream &out, bigint const &num);
  friend std::istream &operator>>(std::istream &in, bigint &num);
};

}  // namespace lab2
