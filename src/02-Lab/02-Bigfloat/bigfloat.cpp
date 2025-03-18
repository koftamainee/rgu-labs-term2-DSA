#include "bigfloat.h"

namespace lab2 {

bigfloat::bigfloat(bigint const &numerator, bigint const &demonimator) {}
bigfloat::bigfloat(bigint const &num) {}
bigfloat::bigfloat(double num) {}
bigfloat::bigfloat(bigfloat const &other) {}

std::optional<double> bigfloat::to_double() {}

bigfloat &bigfloat::operator=(bigfloat const &other) {}

bigfloat &bigfloat::operator+=(bigfloat const &other) & {}
bigfloat operator+(bigfloat const &first, bigfloat const &second) {}

bigfloat &bigfloat::operator-=(bigfloat const &other) & {}
bigfloat operator-(bigfloat const &first, bigfloat const &second) {}

bigfloat &bigfloat::operator*=(bigfloat const &other) & {}
bigfloat operator*(bigfloat const &first, bigfloat const &second) {}

bigfloat &bigfloat::operator/=(bigfloat const &other) & {}
bigfloat operator/(bigfloat const &first, bigfloat const &second) {}

bigfloat &bigfloat::operator%=(bigfloat const &other) & {}
bigfloat operator%(bigfloat const &first, bigfloat const &second) {}

bool operator==(bigfloat const &first, bigfloat const &second) {}
bool operator!=(bigfloat const &first, bigfloat const &second) {}

bool operator<(bigfloat const &first, bigfloat const &second) {}
bool operator<=(bigfloat const &first, bigfloat const &second) {}

bool operator>(bigfloat const &first, bigfloat const &second) {}
bool operator>=(bigfloat const &first, bigfloat const &second) {}

std::ostream &operator<<(std::ostream &out, bigfloat const &num) {}
std::istream &operator>>(std::istream &in, bigfloat const &num) {}

double sin(bigfloat const &number, bigfloat const &EPS) {}
double tg(bigfloat const &number, bigfloat const &EPS) {}
double ctg(bigfloat const &number, bigfloat const &EPS) {}
double sec(bigfloat const &number, bigfloat const &EPS) {}
double cosec(bigfloat const &number, bigfloat const &EPS) {}
double arcsin(bigfloat const &number, bigfloat const &EPS) {}
double arccos(bigfloat const &number, bigfloat const &EPS) {}
double arctg(bigfloat const &number, bigfloat const &EPS) {}
double arcctg(bigfloat const &number, bigfloat const &EPS) {}
double arcsec(bigfloat const &number, bigfloat const &EPS) {}
double arccosec(bigfloat const &number, bigfloat const &EPS) {}

bigfloat pow(bigfloat const &base, bigint const &exp) {}
bigfloat radical(bigfloat const &radicand, bigint const &index,
                 bigfloat const &EPS) {}
bigfloat sqrt(bigfloat const &radicand, bigfloat const &EPS) {}

bigfloat log2(bigfloat const &number, bigfloat const &EPS) {}
bigfloat log(bigfloat const &number, bigfloat const &EPS) {}
bigfloat log10(bigfloat const &number, bigfloat const &EPS) {}

}  // namespace lab2
