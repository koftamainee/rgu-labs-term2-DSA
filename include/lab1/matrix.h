#pragma once

#include <cstddef>
#include <ostream>

namespace lab1 {

class matrix {
 private:
  double **data_;
  size_t rows_, cols_;

  void allocate_memory();
  void deallocate_memory();

 public:
  matrix(size_t rows, size_t cols);
  ~matrix();
  matrix(const matrix &other);
  matrix &operator=(const matrix &other);

  matrix operator+(const matrix &other) const;
  matrix &operator+=(const matrix &other);

  matrix operator-(const matrix &other) const;
  matrix &operator-=(const matrix &other);

  matrix operator*(const matrix &other) const;
  matrix &operator*=(const matrix &other);

  matrix operator*(double other) const;
  matrix &operator*=(double other);

  friend matrix operator*(double number, const matrix &mat);

  matrix transpose() const;
  double det() const;
  matrix inverse() const;

  double *operator[](size_t index) const;
  double &at(size_t i, size_t j) const;

  friend std::ostream &operator<<(std::ostream &out, const matrix &mat);
};
}  // namespace lab1
