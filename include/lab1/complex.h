#pragma once

#include <iostream>

namespace lab1 {

class complex {
 private:
  double real_;
  double imaginary_;

 public:
  complex(double real = 0, double imaginary = 0)
      : real_(real), imaginary_(imaginary) {}

  ~complex() = default;
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

  double abs() const;
  double arg() const;

  friend std::ostream &operator<<(std::ostream &out, const complex &number);
  friend std::istream &operator>>(std::istream &in, complex &number);
};
}  // namespace lab1
