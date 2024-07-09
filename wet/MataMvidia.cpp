
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

MataMvidia &MataMvidia::operator=(const MataMvidia &to_copy) {
    ////    check if assigning this to this
    ////    so no errors occur when copying
    if(this == &to_copy){
        return *this;
    }
    ////    if reached here length cannot be 0
    Matrix* copied_frames = new Matrix[to_copy.length];
    for (int i = 0; i < to_copy.length; ++i) {
        ////    uses operator= of Matrix
        copied_frames[i] = to_copy.frames[i];
    }
    ////    if reached here then the copying finished correctly
    ////    now need to delete the old frames
    delete []this->frames;
    ////    then assign the new frames array to this
    this->frames = copied_frames;
    ////    and finally copy the movie_name, movie_creator and length
    this->length = to_copy.length;
    this->movie_name = to_copy.movie_name;
    this->movie_creator = to_copy.movie_creator;
    return *this;
}

Matrix &MataMvidia::operator[](int index) {
    if(index < 0 || index >= this->length){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->frames[index];
}

const Matrix &MataMvidia::operator[](int index) const {
    if(index < 0 || index >= this->length){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->frames[index];
}

////    here no need to update the length because it is done in operator+= below
MataMvidia &MataMvidia::operator+=(const MataMvidia &to_link) {
    for (int i = 0; i < to_link.length; ++i) {
        ////    append to the end using operator+= between MataMvidia and Matrix from below
        (*this) += to_link[i];
    }
    return *this;
}

MataMvidia &MataMvidia::operator+=(const Matrix &to_link) {
    ////    first create a new Matrix array
    Matrix* new_frames = new Matrix[this->length + 1];
    ////    copy the old frames
    for (int i = 0; i < this->length; ++i) {
        ////    uses operator= from Matrix
        new_frames[i] = this->frames[i];
    }
    ////    then link the matrix to_link to the end, using the operator=
    new_frames[this->length] = to_link;
    ////    now delete the old frames array
    delete[] this->frames;
    ////    then assign the new_frames array to this
    this->frames = new_frames;
    ////    and increase the length accordingly
    ++(this->length);
    ////    finally return this
    return *this;
}

MataMvidia MataMvidia::operator+(const MataMvidia &movie1) const {

}

std::ostream& operator<<(std::ostream& os, const Matrix& to_print){

}

