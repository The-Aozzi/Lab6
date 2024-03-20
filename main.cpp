#include <iostream>
#include "matrix.h"

int main(int, char **)
{
    std::cout << std::boolalpha;
    Matrix::Matrix first_matrix, second_matrix;
    std::cin >> first_matrix >> second_matrix;
    std::cout << first_matrix + second_matrix << std::endl;
    std::cout << first_matrix - second_matrix << std::endl;
    std::cout << first_matrix * second_matrix << std::endl;
    std::cout << (first_matrix == second_matrix) << std::endl;
    int scalar;
    std::cin >> scalar;
    std::cout << first_matrix * scalar << std::endl;
    std::cout << Matrix::Matrix() << std::endl << Matrix::Matrix(3, 3);
    std::cin >> first_matrix >> second_matrix;
    std::cout << Matrix::Convolution(first_matrix, second_matrix);
    std::cout << Matrix::MaxPooling(first_matrix, 2);
}
