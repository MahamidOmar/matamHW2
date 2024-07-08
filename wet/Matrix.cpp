
#include "Matrix.h"
#include "Utilities.h"

////    initialize rows and cols to 0, and matrix to null
Matrix::Matrix() : rows(0), cols(0), matrix(nullptr){}

////    initialize rows and cols to the given parameters, and initialize matrix dynamically
Matrix::Matrix(int rows, int cols) : rows(rows), cols(0), matrix(new int[rows * cols]){
    ////    check if rows or cols are zero or negative
    if(rows <= 0 || cols <= 0){
        exitWithError(MatamErrorType::OutOfBounds);
    }
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

////    just need to destroy the dynamically allocated matrix
Matrix::~Matrix() {
    delete[] matrix;
}

Matrix &Matrix::operator=(const Matrix &to_copy) {
    ////    check if this is equal to other, then no copy needed
    if(*this == to_copy){
        return *this;
    }
    ////    copy the rows and cols fields first
    this->rows = to_copy.rows;
    this->cols = to_copy.cols;
    ////    delete the old dynamically allocated matrix
    delete [] this->matrix;
    ////    and then allocate a new matrix
    this->matrix = new int[this->rows * this->cols];
    ////    and now copy the elements inside the matrix
    for (int i = 0; i < rows * cols; ++i) {
        matrix[i] = to_copy.matrix[i];
    }
    return *this;
}

int Matrix::operator()(int i, int j) const {
    ////    check if illegal indexes
    if(i < 0 || j < 0 || i > rows || j > cols){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->matrix[i * rows + j];
}

int &Matrix::operator()(int i, int j) {
    ////    check if illegal indexes
    if(i < 0 || j < 0 || i > rows || j > cols){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->matrix[i * rows + j];
}

std::ostream &operator<<(std::ostream &os, const Matrix &to_print) {
    for (int i = 0; i < to_print.rows; ++i) {
        ////    first print the | before printing each row
        std::cout << "|";
        for (int j = 0; j < to_print.cols; ++j) {
            ////    use the operator() from before, and after each element print |
            std::cout << to_print(i, j) << "|";
        }
    }
}

Matrix Matrix::operator+(const Matrix &to_add) const {
    return Matrix();
}

Matrix Matrix::operator-(const Matrix &to_add) const {
    return Matrix();
}

Matrix Matrix::operator*(const Matrix &to_add) const {
    return Matrix();
}

Matrix &Matrix::operator+=(const Matrix &to_add) {
}

Matrix &Matrix::operator-=(const Matrix &to_add) {
}

Matrix &Matrix::operator*=(const Matrix &to_add) {
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
