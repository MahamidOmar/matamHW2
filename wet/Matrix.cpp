
#include "Matrix.h"

////    initialize rows and cols to 0, and matrix to null
Matrix::Matrix() : rows(0), cols(0), matrix(nullptr){}

////    initialize rows and cols to the given parameters, and initialize matrix dynamically
Matrix::Matrix(int rows, int cols) : rows(rows), cols(0), matrix(new int[rows * cols]){
    ////    here rows cols, and matrix are already initialized
    for (int i = 0; i < rows * cols; ++i) {
        matrix[i] = 0;
    }
}

////    copy the rows and cols field, and initialize the matrix array dynamically accordingly
Matrix::Matrix(const Matrix &to_copy) : rows(to_copy.rows), cols(to_copy.cols),
                                        matrix(new int [to_copy.rows * to_copy.cols]) {
    ////    here rows cols, and matrix are already initialized
    for (int i = 0; i < rows * cols; ++i) {
        matrix[i] = to_copy.matrix[i];
    }
}

Matrix::~Matrix() {

}

Matrix &Matrix::operator=(const Matrix &matrix) {
}

int Matrix::operator()(int row, int column) const {
    return 0;
}

int &Matrix::operator()(int row, int column) {
}

std::ostream &operator<<(std::ostream &os, const Matrix &h) {
}

Matrix Matrix::operator+(const Matrix &matrix) const {
    return Matrix();
}

Matrix Matrix::operator-(const Matrix &matrix) const {
    return Matrix();
}

Matrix Matrix::operator*(const Matrix &matrix) const {
    return Matrix();
}

Matrix &Matrix::operator+=(const Matrix &matrix) {
}

Matrix &Matrix::operator-=(const Matrix &matrix) {
}

Matrix &Matrix::operator*=(const Matrix &matrix) {
}

Matrix Matrix::operator-() const {
    return Matrix();
}

Matrix operator*(int scalar, const Matrix &matrix) {
    return Matrix();
}

Matrix operator*(const Matrix &matrix, int scalar) {
    return Matrix();
}

Matrix &Matrix::operator*=(int scalar) {
}

bool operator==(const Matrix &h1, const Matrix &h2) {
    return false;
}

bool operator!=(const Matrix &h1, const Matrix &h2) {
    return false;
}

Matrix Matrix::rotateClockwise() const {
    return Matrix();
}

Matrix Matrix::rotateCounterClockwise() const {
    return Matrix();
}

Matrix Matrix::Transpose() const {
    return Matrix();
}
