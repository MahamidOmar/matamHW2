
#ifndef MATAMHW2_MATRIX_H
#define MATAMHW2_MATRIX_H

#include <iostream>


class Matrix {
private:
    int height;
    int width;
    int *matrix;
public:
    ////    empty constructor
    Matrix();

    ////    constructor with width and height
    Matrix(int height, int width);

    ////    copy constructor
    Matrix(const Matrix& matrix);

    ////    destructor
    ~Matrix();

    ////    operator= for matrix
    Matrix& operator=(const Matrix& matrix);

    ////    operator() for reading
    int operator()(int row, int column) const;

    ////    operator() for writing
    int& operator()(int row, int column);

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
