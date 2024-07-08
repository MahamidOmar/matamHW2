
#include "Matrix.h"

Matrix::Matrix() : height(0), width(0), matrix(nullptr){}

Matrix::Matrix(int height, int width) : height(height), width(0), matrix(new int[height * width]){
    for (int i = 0; i < height * width; ++i) {

    }
}

Matrix::Matrix(const Matrix &matrix) {

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
