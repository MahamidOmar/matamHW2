
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
        os << "|";
        for (int j = 0; j < to_print.cols; ++j) {
            ////    use the operator() from before, and after each element print |
            os << to_print(i, j) << "|";
        }
    }
    return os;
}

Matrix Matrix::operator+(const Matrix &to_add) const {

}

Matrix Matrix::operator-(const Matrix &to_add) const {
}

Matrix Matrix::operator*(const Matrix &to_add) const {
}

Matrix &Matrix::operator+=(const Matrix &to_add) {
    if(this->rows != to_add.rows || this->cols != to_add.cols){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->rows; ++j) {
            ////    use the operator() to add the value
            this->matrix[i * rows + cols] += to_add(i, j);
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &to_add) {
}

Matrix &Matrix::operator*=(const Matrix &to_add) {
}

Matrix Matrix::operator-() const {
    ////    initialize a matrix result
    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->rows; ++j) {
            ////    use the operator() to update the value
            result(i, j) = (-1) * (*this)(i, j);
        }
    }
    return result;
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
