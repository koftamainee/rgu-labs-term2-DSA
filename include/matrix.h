#pragma once

#include <cstddef>
#include <ostream>

namespace lab1 {

class matrix final {
 private:
  static double EPS_;
  double **data_;
  size_t rows_, cols_;

  void allocate_memory();
  void deallocate_memory();

  [[nodiscard]] matrix create_augmented_matrix() const;
  void gaussian_elimination(matrix &augmented) const;
  [[nodiscard]] matrix extract_inverse(const matrix &augmented) const;

 public:
  matrix(size_t rows, size_t cols);
  ~matrix() noexcept;
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

  [[nodiscard]] matrix transpose() const;
  [[nodiscard]] double det() const;
  [[nodiscard]] matrix inverse() const;

  double *operator[](size_t index) const;
  [[nodiscard]] double &at(size_t row, size_t col) const;

  friend std::ostream &operator<<(std::ostream &out, const matrix &mat);
};
}  // namespace lab1
