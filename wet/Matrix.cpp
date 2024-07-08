
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

////    these 3 operators use the 3 with = below
////    note that checking for unmatched sizes is done within operators with =
Matrix Matrix::operator+(const Matrix &to_add) const {
    ////    first copy the current (this) matrix
    Matrix result(*this);
    ////    and then use operator+=
    return (result += to_add);
}

Matrix Matrix::operator-(const Matrix &to_add) const {
    ////    first copy the current (this) matrix
    Matrix result(*this);
    ////    and then use operator-=
    return (result -= to_add);
}

Matrix Matrix::operator*(const Matrix &to_add) const {
    ////    first copy the current (this) matrix
    Matrix result(*this);
    ////    and then use operator*=
    return (result *= to_add);
}

////    implemented fully
Matrix &Matrix::operator+=(const Matrix &to_add) {
    ////    if both have no elements
    if(this->rows == 0 && this-> cols == 0 && to_add.rows == 0 && to_add.cols == 0){
        return *this;
    }
    ////    reaches here if one has no elements and the other one does
    if((this->rows == 0 && to_add.rows != 0) || (this->rows != 0 && to_add.rows == 0)){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    ////    check for errors with sizes
    if(this->rows != to_add.rows || this->cols != to_add.cols || to_add.rows == 0 || to_add.cols == 0){
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

////    uses the += and the unary - operators
Matrix &Matrix::operator-=(const Matrix &to_add) {
    return (*this) += (-to_add);
}

////    this differs from the += and -= operators
Matrix &Matrix::operator*=(const Matrix &to_add) {
    ////    if both have no elements
    if(this->rows == 0 && this-> cols == 0 && to_add.rows == 0 && to_add.cols == 0){
        return *this;
    }
    ////    reaches here if one has no elements and the other one does
    if((this->rows == 0 && to_add.rows != 0) || (this->rows != 0 && to_add.rows == 0)){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    ////    check for errors with sizes for multiplication
    if(this->cols != to_add.rows || to_add.rows == 0 || to_add.cols == 0){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix result(this->rows, to_add.cols);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < to_add.cols; ++j) {
            for (int k = 0; k < this->cols; ++k) {
                result(i, j) = this->matrix[i * cols + k] * to_add(k, j);
            }
        }
    }
    ////    this assigns the result to this, which in turn deletes the old data from this matrix
    *this = result;
    return *this;
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

////    uses the operator * below it
Matrix operator*(int scalar, const Matrix &matrix) {
    return matrix * scalar;
}

////    uses the operator *= below it
Matrix operator*(const Matrix &matrix, int scalar) {
    ////    first copy the matrix
    Matrix result(matrix);
    ////    and then use the *=
    return (result *= scalar);
}

////    implemented fully
Matrix &Matrix::operator*=(int scalar) {
    ////    check if no elements, nothing to do
    if(this-> rows == 0 && this->cols == 0){
        return *this;
    }
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            this->matrix[i * rows + j] *= scalar;
        }
    }
    return *this;
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
