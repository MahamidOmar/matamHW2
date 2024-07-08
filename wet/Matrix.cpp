
#include "Matrix.h"

Matrix::Matrix() {

}

Matrix::Matrix(int height, int width) {

}

Matrix::Matrix(const Matrix &matrix) {

}

Matrix::~Matrix() {

}

Matrix &Matrix::operator=(const Matrix &matrix) {
    return <#initializer#>;
}

int Matrix::operator()(int row, int column) const {
    return 0;
}

int &Matrix::operator()(int row, int column) {
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream &os, const Matrix &h) {
    return <#initializer#>;
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
    return <#initializer#>;
}

Matrix &Matrix::operator-=(const Matrix &matrix) {
    return <#initializer#>;
}

Matrix &Matrix::operator*=(const Matrix &matrix) {
    return <#initializer#>;
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
    return <#initializer#>;
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
