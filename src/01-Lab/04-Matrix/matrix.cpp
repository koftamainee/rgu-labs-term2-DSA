#include "matrix.h"

#include <strings.h>

#include <cstring>
#include <new>
#include <stdexcept>

namespace lab1 {

double matrix::EPS_ = 1e-10;

void matrix::allocate_memory() {
  data_ = new double *[rows_];
  try {
    for (size_t i = 0; i < rows_; ++i) {
      data_[i] = new double[cols_];
    }
  } catch (std::bad_alloc &e) {
    for (size_t j = 0; j < rows_; ++j) {
      delete[] data_[j];
    }
    delete[] data_;
    throw;
  }
}

void matrix::deallocate_memory() {
  for (int i = 0; i < rows_; ++i) {
    delete[] data_[i];
  }
  delete[] data_;
}

matrix::matrix(size_t rows, size_t cols) {
  rows_ = rows;
  cols_ = cols;
  allocate_memory();
  for (int i = 0; i < rows_; ++i) {
    std::memset(data_[i], 0, sizeof(double) * cols_);
  }
}

matrix::~matrix() noexcept { deallocate_memory(); }

matrix::matrix(const matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  allocate_memory();
  for (int i = 0; i < rows_; ++i) {
    std::memcpy(data_[i], other.data_[i], sizeof(double) * cols_);
  }
}

matrix &matrix::operator=(const matrix &other) {
  if (&other == this) {
    return *this;
  }
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    allocate_memory();
  }
  for (int i = 0; i < rows_; ++i) {
    std::memcpy(data_[i], other.data_[i], sizeof(double) * cols_);
  }
  return *this;
}

matrix matrix::operator+(const matrix &other) const {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::invalid_argument(
        "Matrix addition works only with matrices of equal size");
  }

  matrix temp(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      temp.data_[i][j] = data_[i][j] + other.data_[i][j];
    }
  }

  return temp;
}

matrix &matrix::operator+=(const matrix &other) {
  *this = *this + other;
  return *this;
}

matrix matrix::operator-(const matrix &other) const {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::invalid_argument(
        "Matrix addition works only with matrices of equal size");
  }

  matrix temp(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      temp.data_[i][j] = data_[i][j] - other.data_[i][j];
    }
  }

  return temp;
}

matrix &matrix::operator-=(const matrix &other) {
  *this = *this - other;
  return *this;
}

matrix matrix::operator*(const matrix &other) const {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Matrix multiplication requires the number of columns in the first "
        "matrix to be equal to the number of rows in the second matrix");
  }

  matrix temp(rows_, other.cols_);
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < other.cols_; ++j) {
      temp.data_[i][j] = 0;
      for (size_t k = 0; k < cols_; ++k) {
        temp.data_[i][j] += data_[i][k] * other.data_[k][j];
      }
    }
  }
  return temp;
}

matrix &matrix::operator*=(const matrix &other) {
  *this = *this * other;
  return *this;
}

matrix matrix::operator*(double other) const {
  matrix temp(*this);
  for (int i = 0; i < temp.rows_; ++i) {
    for (int j = 0; j < temp.cols_; ++j) {
      temp.data_[i][j] = data_[i][j] * other;
    }
  }
  return temp;
}

matrix &matrix::operator*=(double other) {
  *this = *this * other;
  return *this;
}

matrix operator*(double number, const matrix &mat) { return mat * number; }

matrix matrix::transpose() const {
  matrix transposed(cols_, rows_);
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < cols_; ++j) {
      transposed.data_[j][i] = data_[i][j];
    }
  }
  return transposed;
}

double matrix::det() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square to compute determinant");
  }

  matrix temp(*this);
  double det = 1.0;
  for (size_t i = 0; i < rows_; ++i) {
    size_t max_row = i;
    for (size_t j = i + 1; j < rows_; ++j) {
      if (std::abs(temp.data_[j][i]) > std::abs(temp.data_[max_row][i])) {
        max_row = j;
      }
    }
    if (i != max_row) {
      auto *forswap = temp.data_[i];
      temp.data_[i] = temp.data_[max_row];
      temp.data_[max_row] = forswap;
      std::swap(temp.data_[i], temp.data_[max_row]);
      det = -det;
    }

    if (std::abs(temp.data_[i][i]) <= EPS_) {
      return 0.0;
    }

    det *= temp.data_[i][i];
    for (size_t j = i + 1; j < rows_; ++j) {
      double factor = temp.data_[j][i] / temp.data_[i][i];
      for (size_t k = i; k < cols_; ++k) {
        temp.data_[j][k] -= factor * temp.data_[i][k];
      }
    }
  }
  return det;
}

matrix matrix::inverse() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square to compute inverse");
  }

  matrix augmented = create_augmented_matrix();
  gaussian_elimination(augmented);
  return extract_inverse(augmented);
}

matrix matrix::create_augmented_matrix() const {
  matrix augmented(rows_, 2 * cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      augmented.data_[i][j] = data_[i][j];
    }
    augmented.data_[i][cols_ + i] = 1;
  }
  return augmented;
}

void matrix::gaussian_elimination(matrix &augmented) const {
  for (int i = 0; i < rows_; ++i) {
    size_t max_row = i;
    for (int j = i + 1; j < rows_; ++j) {
      if (std::abs(augmented.data_[j][i]) >
          std::abs(augmented.data_[max_row][i])) {
        max_row = j;
      }
    }
    if (i != max_row) {
      std::swap(augmented.data_[i], augmented.data_[max_row]);
    }
    if (std::abs(augmented.data_[i][i]) <= EPS_) {
      throw std::invalid_argument("Matrix is singular, no inverse exists");
    }
    double factor = augmented.data_[i][i];
    for (int j = 0; j < 2 * cols_; ++j) {
      augmented.data_[i][j] /= factor;
    }
    for (int j = 0; j < rows_; ++j) {
      if (j != i) {
        factor = augmented.data_[j][i];
        for (int k = 0; k < 2 * cols_; ++k) {
          augmented.data_[j][k] -= factor * augmented.data_[i][k];
        }
      }
    }
  }
}

matrix matrix::extract_inverse(const matrix &augmented) const {
  matrix inv(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      inv.data_[i][j] = augmented.data_[i][cols_ + j];
    }
  }
  return inv;
}

double *matrix::operator[](size_t index) const { return data_[index]; }

double &matrix::at(size_t row, size_t col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Invalid index for matrix");
  }
  return data_[row][col];
}

std::ostream &operator<<(std::ostream &out, const matrix &mat) {
  for (int i = 0; i < mat.rows_; ++i) {
    out << "[";
    for (int j = 0; j < mat.cols_; ++j) {
      out << mat[i][j];
      if (j < mat.cols_ - 1) {
        out << ", ";
      }
    }
    if (i < mat.rows_ - 1) {
      out << "],";
    } else {
      out << "].";
    }
    out << std::endl;
  }
  return out;
}
}  // namespace lab1
