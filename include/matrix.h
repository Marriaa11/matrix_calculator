#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

/**
 * @brief Структура матрицы.
 * @warning Память освобождается через free_matrix().
 */
typedef struct {
    double** data; ///< Указатель на двумерный массив
    int rows;      ///< Количество строк
    int cols;      ///< Количество столбцов
} Matrix;

// Базовые операции
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix& m);
Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_multiply(Matrix a, Matrix b);

// Вспомогательные функции
void print_matrix(Matrix m);
Matrix matrix_from_array(double* data, int rows, int cols);

// Индивидуальное задание №1
/**
 * @brief Вычисление суммы всех элементов матрицы.
 * @param m Исходная матрица.
 * @return double Сумма элементов.
 * @exception std::invalid_argument Если матрица пустая.
 */
double matrix_sum(Matrix m);

#endif // MATRIX_H