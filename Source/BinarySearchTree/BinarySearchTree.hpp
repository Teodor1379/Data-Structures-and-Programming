#ifndef _BINARY_SEARCH_TREE_HEADER_INCLUDED_
#define _BINARY_SEARCH_TREE_HEADER_INCLUDED_



#include <cstddef>
#include <cstdlib>

#include <exception>
#include <stdexcept>



template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T       data;
        Node*   left;
        Node*   right;
    };



public:
    BinarySearchTree(                           );
    BinarySearchTree(const BinarySearchTree<T>& );
    BinarySearchTree(BinarySearchTree<T>&&      );

    ~BinarySearchTree();



public:
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);
    BinarySearchTree<T>& operator=(BinarySearchTree<T>&&);



private:
    Node*   root;
};



#include "BinarySearchTree.inl"



#endif
