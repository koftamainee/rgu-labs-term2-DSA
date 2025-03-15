#include "tests/test_matrix.h"

#include "iostream"
#include "matrix.h"

namespace {
void demonstrate_addition() {
  lab1::matrix mat1(2, 2);
  mat1[0][0] = 1;
  mat1[0][1] = 2;
  mat1[1][0] = 3;
  mat1[1][1] = 4;

  lab1::matrix mat2(2, 2);
  mat2[0][0] = 5;
  mat2[0][1] = 6;
  mat2[1][0] = 7;
  mat2[1][1] = 8;

  lab1::matrix result = mat1 + mat2;

  std::cout << "Matrix Addition:" << std::endl;
  std::cout << "Matrix 1:" << std::endl << mat1 << std::endl;
  std::cout << "Matrix 2:" << std::endl << mat2 << std::endl;
  std::cout << "Result:" << std::endl << result << std::endl;
}

void demonstrate_subtraction() {
  lab1::matrix mat1(2, 2);
  mat1[0][0] = 5;
  mat1[0][1] = 6;
  mat1[1][0] = 7;
  mat1[1][1] = 8;

  lab1::matrix mat2(2, 2);
  mat2[0][0] = 1;
  mat2[0][1] = 2;
  mat2[1][0] = 3;
  mat2[1][1] = 4;

  lab1::matrix result = mat1 - mat2;

  std::cout << "Matrix Subtraction:" << std::endl;
  std::cout << "Matrix 1:" << std::endl << mat1 << std::endl;
  std::cout << "Matrix 2:" << std::endl << mat2 << std::endl;
  std::cout << "Result:" << std::endl << result << std::endl;
}

void demonstrate_multiplication() {
  lab1::matrix mat1(2, 3);
  mat1[0][0] = 1;
  mat1[0][1] = 2;
  mat1[0][2] = 3;
  mat1[1][0] = 4;
  mat1[1][1] = 5;
  mat1[1][2] = 6;

  lab1::matrix mat2(3, 2);
  mat2[0][0] = 7;
  mat2[0][1] = 8;
  mat2[1][0] = 9;
  mat2[1][1] = 10;
  mat2[2][0] = 11;
  mat2[2][1] = 12;

  lab1::matrix result = mat1 * mat2;

  std::cout << "Matrix Multiplication:" << std::endl;
  std::cout << "Matrix 1:" << std::endl << mat1 << std::endl;
  std::cout << "Matrix 2:" << std::endl << mat2 << std::endl;
  std::cout << "Result:" << std::endl << result << std::endl;
}

void demonstrate_scalar_multiplication() {
  lab1::matrix mat(2, 2);
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[1][0] = 3;
  mat[1][1] = 4;

  double scalar = 2.5;
  lab1::matrix result = mat * scalar;

  std::cout << "Scalar Multiplication:" << std::endl;
  std::cout << "Matrix:" << std::endl << mat << std::endl;
  std::cout << "Scalar: " << scalar << std::endl;
  std::cout << "Result:" << std::endl << result << std::endl;
}

void demonstrate_transpose() {
  lab1::matrix mat(2, 3);
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[0][2] = 3;
  mat[1][0] = 4;
  mat[1][1] = 5;
  mat[1][2] = 6;

  lab1::matrix result = mat.transpose();

  std::cout << "Matrix Transpose:" << std::endl;
  std::cout << "Original Matrix:" << std::endl << mat << std::endl;
  std::cout << "Transposed Matrix:" << std::endl << result << std::endl;
}

void demonstrate_determinant() {
  lab1::matrix mat(3, 3);
  mat[0][0] = 4;
  mat[0][1] = 7;
  mat[0][2] = 9;
  mat[1][0] = 2;
  mat[1][1] = 6;
  mat[1][2] = 8;
  mat[2][0] = 3;
  mat[2][1] = 5;
  mat[2][2] = 11;

  double determinant = mat.det();

  std::cout << "Matrix Determinant:" << std::endl;
  std::cout << "Matrix:" << std::endl << mat << std::endl;
  std::cout << "Determinant: " << determinant << std::endl;
}

void demonstrate_inverse() {
  lab1::matrix mat(3, 3);
  mat[0][0] = 2;
  mat[0][1] = 5;
  mat[0][2] = 83;
  mat[1][0] = 43;
  mat[1][1] = 0.5;
  mat[1][2] = 1;
  mat[2][0] = 7;
  mat[2][1] = 13;
  mat[2][2] = 11;

  lab1::matrix result = mat.inverse();

  std::cout << "Matrix Inverse:" << std::endl;
  std::cout << "Original Matrix:" << std::endl << mat << std::endl;
  std::cout << "Inverse Matrix:" << std::endl << result << std::endl;
}
}  // namespace

void lab1::test::matrix(int argc, char **argv) {
  demonstrate_addition();
  demonstrate_subtraction();
  demonstrate_multiplication();
  demonstrate_scalar_multiplication();
  demonstrate_transpose();
  demonstrate_determinant();
  demonstrate_inverse();
}
