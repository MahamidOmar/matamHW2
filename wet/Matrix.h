
#ifndef MATAMHW2_MATRIX_H
#define MATAMHW2_MATRIX_H

#include <iostream>


class Matrix {
private:
    int rows;
    int cols;
    int *matrix;
public:
    ////    empty constructor
    Matrix();

    ////    constructor with cols and rows
    Matrix(int rows, int cols);

    ////    copy constructor
    Matrix(const Matrix& matrix);

    ////    destructor
    ~Matrix();

    ////    operator= for matrix
    Matrix& operator=(const Matrix& matrix);

    ////    operator() for reading
    int operator()(int i, int j) const;

    ////    operator() for writing
    int& operator()(int i, int j);

    ////    operator << for printing
    friend std::ostream& operator<<(std::ostream& os, const Matrix& h);

    ////    arithmetic operators for Matrix
    Matrix operator+(const  Matrix& matrix) const;

    Matrix operator-(const  Matrix& matrix) const;

    Matrix operator*(const  Matrix& matrix) const;

    Matrix& operator+=(const Matrix& matrix);

    Matrix& operator-=(const Matrix& matrix);

    Matrix& operator*=(const Matrix& matrix);

    Matrix operator-()const;

    friend Matrix operator*(int scalar, const Matrix& matrix);

    friend Matrix operator*(const Matrix& matrix, int scalar);

    Matrix& operator*=(int scalar);

    ////    operators for comparing matrix

    friend bool operator==(const Matrix& h1, const Matrix& h2);

    friend bool operator!=(const Matrix& h1, const Matrix& h2);

    ////    methods for Matrix
    Matrix rotateClockwise() const;

    Matrix rotateCounterClockwise() const;

    Matrix Transpose() const;

};


#endif //MATAMHW2_MATRIX_H
