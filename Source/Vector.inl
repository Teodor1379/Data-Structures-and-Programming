#ifndef _VECTOR_INL_INCLUDED_
#define _VECTOR_INL_INCLUDED_

template<typename T>
inline Vector<T>::Vector() {
    this->data      =   nullptr;

    this->size      =   0;
    this->capacity  =   0;
}

#endif
