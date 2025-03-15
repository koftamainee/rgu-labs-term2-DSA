#include <cmath>
#include <stdexcept>

#include "lab1_complex.h"

namespace lab1 {

double complex::EPS_ = 1e-10;

complex complex::operator+(const complex &other) const {
  return {real_ + other.real_, imaginary_ + other.imaginary_};
}

complex &complex::operator+=(const complex &other) {
  *this = *this + other;
  return *this;
}

complex complex::operator-(const complex &other) const {
  return {real_ - other.real_, imaginary_ - other.imaginary_};
}

complex &complex::operator-=(const complex &other) {
  *this = *this - other;
  return *this;
}

complex complex::operator*(const complex &other) const {
  complex temp;
  temp.real_ = (real_ * other.real_) - (imaginary_ * other.imaginary_);
  temp.imaginary_ = (real_ * other.imaginary_) + (imaginary_ * other.real_);
  return temp;
}

complex &complex::operator*=(const complex &other) {
  *this = *this * other;
  return *this;
}

complex complex::operator/(const complex &other) const {
  double denominator =
      (other.real_ * other.real_) + (other.imaginary_ * other.imaginary_);

  if (denominator <= EPS_) {
    throw std::invalid_argument("Division by zero");
  }

  complex temp;
  temp.real_ =
      (real_ * other.real_ + imaginary_ * other.imaginary_) / denominator;
  temp.imaginary_ =
      (imaginary_ * other.real_ - real_ * other.imaginary_) / denominator;

  return temp;
}

complex &complex::operator/=(const complex &other) {
  *this = *this / other;
  return *this;
}

double complex::abs() const {
  return std::sqrt((real_ * real_) + (imaginary_ * imaginary_));
}

double complex::arg() const { return std::atan(real_ / imaginary_); }

std::ostream &operator<<(std::ostream &out, const complex &number) {
  if (number.imaginary_ < 0) {
    out << number.real_ << " " << number.imaginary_ << "i";
  } else {
    out << number.real_ << " + " << number.imaginary_ << "i";
  }
  return out;
}

std::istream &operator>>(std::istream &in, complex &number) {
  double real = 0;
  double imaginary = 0;
  char c;

  in >> real >> c;
  if (c != '+' && c != '-') {
    in.setstate(std::ios::failbit);
    return in;
  }
  in >> imaginary >> c;
  if (c != 'i') {
    in.setstate(std::ios::failbit);
    return in;
  }

  if (in) {
    number.real_ = real;
    number.imaginary_ = imaginary;
  }

  return in;
}
}  // namespace lab1
