#ifndef _VECTOR_INL_INCLUDED_
#define _VECTOR_INL_INCLUDED_

template<typename T>
inline Vector<T>::Vector() {
    this->data      =   nullptr;

    this->size      =   0;
    this->capacity  =   0;
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& instance) {
    this->allocate(instance);

    this->size      =   instance.size;
    this->capacity  =   instance.capacity;
}

template<typename T>
inline void Vector<T>::allocate(const Vector<T>& instance) {
    if (instance.size == 0) {
        this->data  =   nullptr;
        return;
    }

    this->data = new T[instance.capacity];

    try {
        for (std::size_t i = 0; i < instance.size; ++i) {
            this->data[i] = instance.data[i];
        }
    } catch (std::exception& exception) {
        delete[] this->data;

        this->data  =   nullptr;

        throw exception;
    }
}

#endif
