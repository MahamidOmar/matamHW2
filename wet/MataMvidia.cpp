
#include "MataMvidia.h"

MataMvidia::MataMvidia(const string& movie_name, const string& movie_creator, Matrix* frames, int length)
                        :length(length),movie_name(movie_name), movie_creator(movie_creator){
    ////    check if illegal length is provided
    if(length <= 0){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    this->frames = new Matrix[length];
}

////    if reached the copy constructor, length is never 0
MataMvidia::MataMvidia(const MataMvidia &to_copy)
                        : length(to_copy.length), movie_name(to_copy.movie_name)
                        , movie_creator(to_copy.movie_creator){
    ////    here this->length is already initialized
    this->frames = new Matrix[length];
    for (int i = 0; i < length; ++i) {
        ////    this uses operator= defined for Matrix
        this->frames[i] = to_copy.frames[i];
    }
}

MataMvidia::~MataMvidia() {
    ////    we use delete[] because it is an array, and we need to call the destructor of Matrix for each one
    delete[] frames;
}


