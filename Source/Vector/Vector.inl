#ifndef _VECTOR_INLINE_INCLUDED_
#define _VECTOR_INLINE_INCLUDED_



template<typename T>
inline Vector<T>::Vector() {
    this->data      =   nullptr;

    this->size      =   0;
    this->capacity  =   0;
}

template<typename T>
inline Vector<T>::Vector(const std::size_t& capacity) {
    
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& instance) {
    this->allocate(instance);

    this->size      =   instance.size;
    this->capacity  =   instance.capacity;
}



#endif
