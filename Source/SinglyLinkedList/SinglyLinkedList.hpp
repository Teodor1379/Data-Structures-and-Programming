#ifndef _SINGLY_LINKED_LIST_HEADER_INCLUDED_
#define _SINGLY_LINKED_LIST_HEADER_INCLUDED_



#include <cstddef>
#include <cstdlib>

#include <exception>
#include <stdexcept>



template<typename T>
struct Node {
    T       data;
    Node*   next;

    Node();
    Node(const T&);
    Node(const T&, Node*);

    Node() {
        this->data  =   T();
        this->next  =   nullptr;
    }

    Node(const T& data) {
        this->data  =   data;
        this->next  =   nullptr;
    }

    Node(const T& data, Node* next) {
        this->data  =   data;
        this->next  =   next;
    }
};



template<typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList(                           );
    SinglyLinkedList(const SinglyLinkedList<T>& );
    SinglyLinkedList(SinglyLinkedList<T>&&      );

    ~SinglyLinkedList();



public:
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&   );
    SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&&        );



private:
    Node*   head;
    Node*   tail;
};



template<typename T> bool operator==(const SinglyLinkedList<T>, const SinglyLinkedList<T>);
template<typename T> bool operator!=(const SinglyLinkedList<T>, const SinglyLinkedList<T>);
template<typename T> bool operator<=(const SinglyLinkedList<T>, const SinglyLinkedList<T>);
template<typename T> bool operator>=(const SinglyLinkedList<T>, const SinglyLinkedList<T>);
template<typename T> bool operator< (const SinglyLinkedList<T>, const SinglyLinkedList<T>);
template<typename T> bool operator> (const SinglyLinkedList<T>, const SinglyLinkedList<T>);



#include "SinglyLinkedList.inl"



#endif
