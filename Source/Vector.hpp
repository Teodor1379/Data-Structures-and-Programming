#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <cstddef>
#include <cstdlib>

template<typename T>
class Vector {
public:
    Vector();
    Vector(const std::size_t&);
    Vector(const Vector<T>&);

    ~Vector();

    Vector<T>& operator=(const Vector<T>&);

    void pushBack(const T&);
    void popBack();

private:
    T*          data;

    std::size_t size;
    std::size_t capacity;
};

#include "Vector.inl"

#endif
