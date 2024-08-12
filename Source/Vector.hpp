#ifndef _VECTOR_HPP_INCLUDED_
#define _VECTOR_HPP_INCLUDED_

#include <cstddef>
#include <cstdlib>

#include <exception>
#include <stdexcept>

template<typename T>
class Vector {
public:
    Vector();
    Vector(const std::size_t&);
    Vector(const std::size_t&, const std::size_t&);
    Vector(const Vector<T>&);
    Vector(Vector<T>&&);

    ~Vector();

    Vector<T>& operator=(const Vector<T>&);
    Vector<T>& operator=(Vector<T>&&);

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

    inline          T& operator[](const std::size_t& index)         noexcept    { return this->data[index]; }
    inline const    T& operator[](const std::size_t& index) const   noexcept    { return this->data[index]; }

    inline std::size_t getSize()        const noexcept  { return this->size;        }
    inline std::size_t getCapacity()    const noexcept  { return this->capacity;    }

    inline          T& front()          noexcept    { return this->data[0];                 }
    inline const    T& front()  const   noexcept    { return this->data[0];                 }

    inline          T& back()           noexcept    { return this->data[this->size - 1];    }
    inline const    T& back()   const   noexcept    { return this->data[this->size - 1];    }

    void pushBack(const T&);
    void popBack();

    void sort();

public:
    class VectorIterator;

private:
    T*          data;

    std::size_t size;
    std::size_t capacity;

    static const std::size_t    REALLOC_STEP = 2;

private:
    void allocate(const Vector<T>&);
    void deallocate();

    void reserve(const std::size_t&);
};

template<typename T> bool operator==(const Vector<T>&, const Vector<T>&);
template<typename T> bool operator!=(const Vector<T>&, const Vector<T>&);
template<typename T> bool operator<=(const Vector<T>&, const Vector<T>&);
template<typename T> bool operator>=(const Vector<T>&, const Vector<T>&);
template<typename T> bool operator< (const Vector<T>&, const Vector<T>&);
template<typename T> bool operator> (const Vector<T>&, const Vector<T>&);

template<typename T>
class Vector<T>::VectorIterator {
public:

    inline VectorIterator&  operator++();
    inline VectorIterator&  operator--();

private:
    friend class Vector<T>;

    const Vector<T>*    owner; 
};

#include "Vector.inl"

#endif
