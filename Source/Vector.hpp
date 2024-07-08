#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <cstddef>
#include <cstdlib>

#include <exception>
#include <stdexcept>

template<typename T>
class Vector {
public:
    Vector();
    Vector(const std::size_t&);
    Vector(const Vector<T>&);

    ~Vector();

    Vector<T>& operator=(const Vector<T>&);

    Vector<T>& operator+=(const Vector<T>&);
    Vector<T>& operator-=(const Vector<T>&);
    Vector<T>& operator*=(const Vector<T>&);
    Vector<T>& operator/=(const Vector<T>&);
    Vector<T>& operator%=(const Vector<T>&);

    Vector<T> operator+(const Vector<T>&)   const;
    Vector<T> operator-(const Vector<T>&)   const;
    Vector<T> operator*(const Vector<T>&)   const;
    Vector<T> operator/(const Vector<T>&)   const;
    Vector<T> operator%(const Vector<T>&)   const;

    void pushBack(const T&);
    void popBack();

    void sort();

private:
    T*          data;

    std::size_t size;
    std::size_t capacity;

private:
    void allocate(const Vector<T>&);
    void deallocate();
};

#include "Vector.inl"

#endif
