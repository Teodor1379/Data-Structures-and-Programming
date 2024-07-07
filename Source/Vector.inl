#ifndef VECTOR_INL_INCLUDED
#define VECTOR_INL_INCLUDED

template<typename T>
inline Vector<T>::Vector() {
    this->data      =   nullptr;

    this->size      =   0;
    this->capacity  =   0;
}

#endif
