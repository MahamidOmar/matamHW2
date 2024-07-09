
#ifndef MATAMHW2_MATAMVIDIA_H
#define MATAMHW2_MATAMVIDIA_H

#include "Matrix.h"
#include "Utilities.h"

using std::string;

class MataMvidia {
private:
    int length;
    Matrix* frames;
    string movie_name;
    string movie_creator;
public:
    ////    constructor
    MataMvidia(const string& movie_name, const string& movie_creator, Matrix* frames, int length);

    ////    copy constructor
    MataMvidia(const MataMvidia& to_copy);

    ////    destructor
    ~MataMvidia();

    ////    operator= for assignment
    MataMvidia& operator=(const MataMvidia& to_copy);

    ////    operator[] for writing
    Matrix& operator[](int index);

    ////    operator[] for reading
    const Matrix& operator[](int index) const;

    ////    operator+= between 2 MataMvidia's
    MataMvidia& operator+=(const MataMvidia& to_link);

    ////    operator+= between a MataMvidia and a matrix
    MataMvidia& operator+=(const Matrix& to_link);

    ////    operator+ that links 2 MataMvidia
    MataMvidia operator+(const MataMvidia& movie1) const;

    ////    operator<< for printing the movie frames
    friend std::ostream& operator<<(std::ostream& os, const Matrix& to_print);
};


#endif //MATAMHW2_MATAMVIDIA_H
