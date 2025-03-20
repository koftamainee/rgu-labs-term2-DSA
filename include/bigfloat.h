#pragma once

#include <optional>
#include <ostream>

#include "bigint.h"

namespace lab2 {

class bigfloat final {
 private:
  bigint numerator_;
  bigint demonimator_;

 public:
  static constexpr double DEFAULT_EPS = 1e-10;

  bigfloat() = default;
  bigfloat(bigint const &numerator, bigint const &demonimator);
  bigfloat(bigint const &num);
  bigfloat(double num);
  bigfloat(bigfloat const &other);
  ~bigfloat() noexcept = default;

  std::optional<double> to_double();

  bigfloat &operator=(bigfloat const &other);

  bigfloat &operator+=(bigfloat const &other) &;
  friend bigfloat operator+(bigfloat const &first, bigfloat const &second);

  bigfloat &operator-=(bigfloat const &other) &;
  friend bigfloat operator-(bigfloat const &first, bigfloat const &second);

  bigfloat &operator*=(bigfloat const &other) &;
  friend bigfloat operator*(bigfloat const &first, bigfloat const &second);

  bigfloat &operator/=(bigfloat const &other) &;
  friend bigfloat operator/(bigfloat const &first, bigfloat const &second);

  bigfloat &operator%=(bigfloat const &other) &;
  friend bigfloat operator%(bigfloat const &first, bigfloat const &second);

  friend bool operator==(bigfloat const &first, bigfloat const &second);
  friend bool operator!=(bigfloat const &first, bigfloat const &second);

  friend bool operator<(bigfloat const &first, bigfloat const &second);
  friend bool operator<=(bigfloat const &first, bigfloat const &second);

  friend bool operator>(bigfloat const &first, bigfloat const &second);
  friend bool operator>=(bigfloat const &first, bigfloat const &second);

  friend std::ostream &operator<<(std::ostream &out, bigfloat const &num);
  friend std::istream &operator>>(std::istream &in, bigfloat const &num);

  friend bigfloat sin(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat tg(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat ctg(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat sec(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat cosec(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat arcsin(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat arccos(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat arctg(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat arcctg(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat arcsec(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat arccosec(bigfloat const &number, bigfloat const &EPS);

  friend bigfloat pow(bigfloat const &base, bigint const &exp);
  friend bigfloat radical(bigfloat const &radicand, bigint const &index,
                          bigfloat const &EPS);
  friend bigfloat sqrt(bigfloat const &radicand, bigfloat const &EPS);

  friend bigfloat log2(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat log(bigfloat const &number, bigfloat const &EPS);
  friend bigfloat log10(bigfloat const &number, bigfloat const &EPS);
};

bigfloat cos(bigfloat const &number,
             bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat tg(bigfloat const &number,
            bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat ctg(bigfloat const &number,
             bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat sec(bigfloat const &number,
             bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat cosec(bigfloat const &number,
               bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat arcsin(bigfloat const &number,
                bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat arccos(bigfloat const &number,
                bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat arctg(bigfloat const &number,
               bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat arcctg(bigfloat const &number,
                bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat arcsec(bigfloat const &number,
                bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat arccosec(bigfloat const &number,
                  bigfloat const &EPS = bigfloat::DEFAULT_EPS);

bigfloat radical(bigfloat const &radicand, bigint const &index,
                 bigfloat const &EPS);
bigfloat sqrt(bigfloat const &radicand, bigfloat const &EPS);

bigfloat log2(bigfloat const &number,
              bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat log(bigfloat const &number,
             bigfloat const &EPS = bigfloat::DEFAULT_EPS);
bigfloat log10(bigfloat const &number,
               bigfloat const &EPS = bigfloat::DEFAULT_EPS);

}  // namespace lab2
