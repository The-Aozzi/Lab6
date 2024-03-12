#include "matrix.h"
#include <random>
#include <cstdlib>
#include <ctime>



Matrix::Matrix::Matrix() : storage({{0, 0}, {0, 0}}) {}

Matrix::Matrix::Matrix(int rows, int columns)
{
    srand(time(0));
    rand();
    rand();
    for (int i = 0; i < rows; ++i)
    {
        storage.push_back(std::vector<int>());
        for (int j = 0; j < columns; ++j)
        {
            storage.back().push_back(rand());
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const Matrix::Matrix &matrix)
{
    for (auto &row : matrix.storage)
    {
        for (int e : row)
        {
            stream << e << ' ';
        }
        stream << '\n';
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Matrix::Matrix &matrix)
{
    int rows, columns;
    stream >> rows >> columns;
    matrix.storage.clear();
    for (int i = 0; i < rows; ++i)
    {
        matrix.storage.push_back(std::vector<int>());
        for (int j = 0; j < columns; ++j)
        {
            matrix.storage.back().push_back(0);
            stream >> matrix.storage.back().back();
        }
    }
    return stream;
}

Matrix::Matrix operator+(const Matrix::Matrix &left, const Matrix::Matrix &right)
{
    if (left.storage.size() != right.storage.size() || left.storage[0].size() != right.storage[0].size())
    {
        throw Matrix::Exception();
    }
    Matrix::Matrix result = left;

    for (int i = 0; i < left.storage.size(); ++i)
    {
        for (int j = 0; j < left.storage[0].size(); ++j)
        {
            result.storage[i][j] += right.storage[i][j];
        }
    }
    return result;
}

Matrix::Matrix operator-(const Matrix::Matrix &left, const Matrix::Matrix &right)
{
    if (left.storage.size() != right.storage.size() || left.storage[0].size() != right.storage[0].size())
    {
        throw Matrix::Exception();
    }
    Matrix::Matrix result = left;

    for (int i = 0; i < left.storage.size(); ++i)
    {
        for (int j = 0; j < left.storage[0].size(); ++j)
        {
            result.storage[i][j] -= right.storage[i][j];
        }
    }
    return result;
}

Matrix::Matrix operator*(const Matrix::Matrix &left, const Matrix::Matrix &right)
{
    if (left.storage[0].size() != right.storage.size()){
        throw; //TODO
    }
    Matrix::Matrix result;
    result.storage = std::vector(left.storage.size(), std::vector<int>(right.storage[0].size()));

    for (int row = 0; row < result.storage.size(); ++row) {
        for (int col = 0; col < result.storage[0].size(); ++col) {
            for (int inner = 0; inner < left.storage[0].size(); ++inner) {
                result.storage[row][col] += left.storage[row][inner] * right.storage[inner][col];
            }
        }
    }
    return result;
}

Matrix::Matrix operator*(const Matrix::Matrix &matrix, int number)
{
    Matrix::Matrix result = matrix;

    for (int i = 0; i < matrix.storage.size(); ++i)
    {
        for (int j = 0; j < matrix.storage[0].size(); ++j)
        {
            result.storage[i][j] *= number;
        }
    }
    return result;
}

bool operator==(const Matrix::Matrix &left, const Matrix::Matrix &right)
{
    if (left.storage.size() != right.storage.size() || left.storage[0].size() != right.storage[0].size())
    {
        return false;
    }
    for (int i = 0; i < left.storage.size(); ++i)
    {
        for (int j = 0; j < left.storage[0].size(); ++j)
        {
            if (left.storage[i][j] != right.storage[i][j])
                return false;
        }
    }
    return true;
}

namespace Matrix
{
    Matrix &Matrix::operator=(const Matrix &other)
    {
        this->storage = other.storage;
        return *this;
    }
}
