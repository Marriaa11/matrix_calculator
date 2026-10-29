#include "matrix.h"

Matrix create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive integers");
    }
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new double*[rows];
    if (mat.data == nullptr) throw std::bad_alloc();
    
    for (int i = 0; i < rows; i++) {
        mat.data[i] = new double[cols];
        if (mat.data[i] == nullptr) {
            for (int j = 0; j < i; j++) delete[] mat.data[j];
            delete[] mat.data;
            throw std::bad_alloc();
        }
        for (int j = 0; j < cols; j++) mat.data[i][j] = 0.0;
    }
    return mat;
}

void free_matrix(Matrix& m) {
    if (m.data == nullptr) return;
    for (int i = 0; i < m.rows; i++) {
        if (m.data[i] != nullptr) {
            delete[] m.data[i];
            m.data[i] = nullptr;
        }
    }
    delete[] m.data;
    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;
}

Matrix matrix_add(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    Matrix result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[i][j] = a.data[i][j] + b.data[i][j];
    return result;
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        throw std::invalid_argument("Incompatible dimensions for multiplication");
    }
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < b.cols; j++)
            for (int k = 0; k < a.cols; k++)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
    return result;
}

void print_matrix(Matrix m) {
    if (m.data == nullptr || m.rows <= 0 || m.cols <= 0) {
        std::cout << "[Empty matrix]" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < m.rows; i++) {
        std::cout << "[";
        for (int j = 0; j < m.cols; j++) {
            std::cout << std::setw(6) << m.data[i][j];
            if (j < m.cols - 1) std::cout << " ";
        }
        std::cout << "]" << std::endl;
    }
}

Matrix matrix_from_array(double* data, int rows, int cols) {
    Matrix m = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m.data[i][j] = data[i * cols + j];
    return m;
}

// ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ №1
double matrix_sum(Matrix m) {
    if (m.data == nullptr || m.rows <= 0 || m.cols <= 0) {
        throw std::invalid_argument("Cannot compute sum of empty matrix");
    }
    double sum = 0.0;
    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            sum += m.data[i][j];
    return sum;
}