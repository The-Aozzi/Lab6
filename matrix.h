#pragma once

#include <iostream>
#include <vector>

namespace Matrix
{
    /// @brief Represents dynamic sized matrix.
    class Matrix;
    /// @brief Raised when any error occurs.
    class Exception{};
    /// @brief Represents a `Matrix` constructed via a convolution operation.
    class Convolution;
    /// @brief Represents a `Matrix` constructed via a max-pooling operation. 
    class MaxPooling;
}

/// @brief Prints a matrix into given stream.
/// @param stream A stream to be output to.
/// @param matrix A matrix to be output.
/// @return Reference to the argument `stream`.
std::ostream &operator<<(std::ostream &stream, const Matrix::Matrix &matrix);

/// @brief Makes a new matrix from text representation.
/// @param stream A stream to read matrix from.
/// @param matrix A matrix variable to hold input matrix.
/// @return Reference to the argument `stream`.
std::istream &operator>>(std::istream &stream, Matrix::Matrix &matrix);

/// @brief Add two matrices.
/// @param left Left operand.
/// @param right Right operand.
/// @return The sum of matrices.
Matrix::Matrix operator+(const Matrix::Matrix &left, const Matrix::Matrix &right);

/// @brief Subtract two matrices.
/// @param left Left operand.
/// @param right Right operand.
/// @return The difference of matrices.
Matrix::Matrix operator-(const Matrix::Matrix &left, const Matrix::Matrix &right);

/// @brief Multiply two matrices.
/// @param left Left operand.
/// @param right Right operand.
/// @return The product of matrices.
Matrix::Matrix operator*(const Matrix::Matrix &left, const Matrix::Matrix &right);

/// @brief Multiply a matrix by a scalar.
/// @param left The matrix.
/// @param right The scalar.
/// @return The result matrix.
Matrix::Matrix operator*(const Matrix::Matrix &matrix, int number);

/// @brief Compare two matrices.
/// @param left Left operand.
/// @param right Right operand.
/// @return `true` if matrices have the same size and all correspondig elements are equal; `false` otherwise.
bool operator==(const Matrix::Matrix &left, const Matrix::Matrix &right);

namespace Matrix
{
    class Matrix
    {
    public:

        /// @brief Costruct a 2x2 zero matrix.
        Matrix();

        /// @brief Construct a `rows` x `columns` matrix with random entries.
        /// @param rows 
        /// @param columns 
        Matrix(int rows, int columns);

        friend Matrix(::operator+)(const Matrix &, const Matrix &);

        friend Matrix(::operator-)(const Matrix &, const Matrix &);

        friend Matrix(::operator*)(const Matrix &, const Matrix &);

        friend Matrix(::operator*)(const Matrix &, int);

        friend bool(::operator==)(const Matrix &, const Matrix &);

        friend std::ostream &(::operator<<)(std::ostream &, const Matrix &);

        friend std::istream &(::operator>>)(std::istream &, Matrix &);

        /// @brief Copy assignment operator.
        Matrix &operator=(const Matrix &other);

        friend class Convolution;
        friend class MaxPooling;

    private:
        std::vector<std::vector<int>> storage;
    };

    class Convolution : public Matrix
    {
    public:
        using Matrix::Matrix;
        /// @brief Convolution of the given matrices.
        /// @param left Left operand.
        /// @param right Right operand.
        Convolution(const Matrix &left, const Matrix &right);
    };

    class MaxPooling : public Matrix
    {
    public:
        using Matrix::Matrix;
        /// @brief Max-pooling of the given matrix.
        /// @param left The matrix to max-pool.
        /// @param right Max-pooling kernel size.
        MaxPooling(const Matrix &matrix, int kernel_size);
    };
}
