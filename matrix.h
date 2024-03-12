#pragma once

#include <iostream>
#include <vector>

namespace Matrix
{
    class Matrix;
    class Exception{};
}

std::ostream &operator<<(std::ostream &stream, const Matrix::Matrix &matrix);

std::istream &operator>>(std::istream &stream, Matrix::Matrix &matrix);

Matrix::Matrix operator+(const Matrix::Matrix &left, const Matrix::Matrix &right);

Matrix::Matrix operator-(const Matrix::Matrix &left, const Matrix::Matrix &right);

Matrix::Matrix operator*(const Matrix::Matrix &left, const Matrix::Matrix &right);

Matrix::Matrix operator*(const Matrix::Matrix &matrix, int number);

bool operator==(const Matrix::Matrix &left, const Matrix::Matrix &right);

namespace Matrix
{
    class Matrix
    {
    public:
        Matrix();

        Matrix(int, int);

        friend Matrix(::operator+)(const Matrix &, const Matrix &);

        friend Matrix(::operator-)(const Matrix &, const Matrix &);

        friend Matrix(::operator*)(const Matrix &, const Matrix &);

        friend Matrix(::operator*)(const Matrix &, int);

        friend bool(::operator==)(const Matrix &, const Matrix &);

        friend std::ostream &(::operator<<)(std::ostream &, const Matrix &);

        friend std::istream &(::operator>>)(std::istream &, Matrix &);

        Matrix &operator=(const Matrix &other);

    private:
        std::vector<std::vector<int>> storage;
    };
}
