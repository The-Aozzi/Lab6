#include <iostream>
#include "matrix.h"

int main(int, char**){
    Matrix::Matrix a;
    std::cin >> a;
    std::cout << a + Matrix::Matrix(2, 2);
}
