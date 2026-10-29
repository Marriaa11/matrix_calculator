#include <gtest/gtest.h>
#include "matrix.h"
#include <stdexcept>

TEST(MatrixTest, CreateMatrix_NormalCase) {
    Matrix A = create_matrix(3, 4);
    EXPECT_EQ(A.rows, 3);
    EXPECT_EQ(A.cols, 4);
    EXPECT_NE(A.data, nullptr);
    free_matrix(A);
}

TEST(MatrixTest, MatrixSum_NormalCase) {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    Matrix A = matrix_from_array(arr, 2, 3);
    double sum = matrix_sum(A);
    EXPECT_DOUBLE_EQ(sum, 21.0);
    free_matrix(A);
}

TEST(MatrixTest, Addition_NormalCase) {
    double arr1[] = {1, 2, 3, 4};
    double arr2[] = {5, 6, 7, 8};
    Matrix A = matrix_from_array(arr1, 2, 2);
    Matrix B = matrix_from_array(arr2, 2, 2);
    Matrix C = matrix_add(A, B);
    EXPECT_DOUBLE_EQ(C.data[0][0], 6.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 12.0);
    free_matrix(A); free_matrix(B); free_matrix(C);
}

TEST(MatrixTest, MatrixSum_SingleElement) {
    double arr[] = {42.0};
    Matrix A = matrix_from_array(arr, 1, 1);
    EXPECT_DOUBLE_EQ(matrix_sum(A), 42.0);
    free_matrix(A);
}

TEST(MatrixTest, MatrixSum_NegativeValues) {
    double arr[] = {-1.0, -2.0, 3.0, 4.0};
    Matrix A = matrix_from_array(arr, 2, 2);
    EXPECT_DOUBLE_EQ(matrix_sum(A), 4.0);
    free_matrix(A);
}

TEST(MatrixTest, CreateMatrix_ZeroRows) {
    EXPECT_THROW(create_matrix(0, 3), std::invalid_argument);
}

TEST(MatrixTest, MatrixSum_EmptyMatrix_Throws) {
    Matrix empty{nullptr, 0, 0};
    EXPECT_THROW(matrix_sum(empty), std::invalid_argument);
}

TEST(MatrixTest, Addition_SizeMismatch) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    EXPECT_THROW(matrix_add(A, B), std::invalid_argument);
    free_matrix(A); free_matrix(B);
}