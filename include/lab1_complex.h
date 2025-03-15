#pragma once

#include <iostream>

namespace lab1 {

class complex final {
 private:
  static double EPS_;
  double real_;
  double imaginary_;

 public:
  complex(double real = 0, double imaginary = 0)
      : real_(real), imaginary_(imaginary) {}

  virtual ~complex() noexcept = default;
  complex(const complex &other) = default;
  complex &operator=(const complex &other) = default;

  complex operator+(const complex &other) const;
  complex &operator+=(const complex &other);

  complex operator-(const complex &other) const;
  complex &operator-=(const complex &other);

  complex operator*(const complex &other) const;
  complex &operator*=(const complex &other);

  complex operator/(const complex &other) const;
  complex &operator/=(const complex &other);

  [[nodiscard]] double abs() const;
  [[nodiscard]] double arg() const;

  friend std::ostream &operator<<(std::ostream &out, const complex &number);
  friend std::istream &operator>>(std::istream &in, complex &number);
};
}  // namespace lab1
