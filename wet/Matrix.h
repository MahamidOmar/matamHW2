
#ifndef MATAMHW2_MATRIX_H
#define MATAMHW2_MATRIX_H


class Matrix {
private:
    int height;
    int width;
    int matrix[];
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

};


#endif //MATAMHW2_MATRIX_H
