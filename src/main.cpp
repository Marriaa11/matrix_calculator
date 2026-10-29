#include "matrix.h"

int main() {
    try {
        double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        Matrix A = matrix_from_array(arr1, 2, 3);
        
        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);
        
        double sum = matrix_sum(A);
        std::cout << "\nSum of all elements: " << sum << std::endl;
        
        free_matrix(A);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}