#ifndef _VECTOR_HEADER_INCLUDED_
#define _VECTOR_HEADER_INCLUDED_



#include <cstddef>
#include <cstdlib>

#include <exception>
#include <stdexcept>



template<typename T>
class Vector {
public:
    Vector(                     );
    Vector(const std::size_t&   );
    Vector(const Vector<T>&     );
    Vector(Vector<T>&&          );

    ~Vector();



public:
    Vector<T>& operator=(const Vector<T>&   );
    Vector<T>& operator=(Vector<T>&&        );



public:
    inline          T& operator[](const std::size_t& index)         noexcept    { return this->data[index]; }
    inline const    T& operator[](const std::size_t& index) const   noexcept    { return this->data[index]; }



public:
    inline std::size_t getSize()        const noexcept  { return this->size;        }
    inline std::size_t getCapacity()    const noexcept  { return this->capacity;    }



public:
    inline          T& front()          noexcept    { return this->data[0];                 }
    inline const    T& front()  const   noexcept    { return this->data[0];                 }

    inline          T& back()           noexcept    { return this->data[this->size - 1];    }
    inline const    T& back()   const   noexcept    { return this->data[this->size - 1];    }



public:
    void pushBack(const T&);
    void popBack();



public:
    bool empty()    const;



private:
    void   allocateMemory(const Vector<T>&  );
    void deallocateMemory(                  );



public:
    void reserveMemory(const std::size_t&);

    

public:
    class VectorIterator;



private:
    T*          data;

    std::size_t size;
    std::size_t capacity;

    static const std::size_t    REALLOC_STEP = 2;
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
