#ifndef _DOUBLY_LINKED_LIST_HEADER_INCLUDED_
#define _DOUBLY_LINKED_LIST_HEADER_INCLUDED_



#include <cstddef>
#include <cstdlib>

#include <exception>
#include <stdexcept>



template<typename T>
struct Node {
    Node() {
        this->data  =   0       ;
        this->prev  =   nullptr ;
        this->next  =   nullptr ;
    }

    Node(const T& data) {
        this->data  =   data;
        this->prev  =   nullptr;
        this->next  =   nullptr;
    }

    inline bool operator==(const Node& node)    const noexcept  { return this->prev == node->prev && this->next == node->next;  }
    inline bool operator!=(const Node& node)    const noexcept  { return this->prev != node->prev || this->next != node->next;  }

    T       data;
    Node*   prev;
    Node*   next;
};



template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList(                           );
    DoublyLinkedList(const DoublyLinkedList<T>& );
    DoublyLinkedList(DoublyLinkedList<T>&&      );

    ~DoublyLinkedList();



public:
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&   );
    DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&&        );



private:
    std::size_t size;
    Node*       head;
    Node*       tail;
};



#include "DoublyLinkedList.hpp"



#endif
