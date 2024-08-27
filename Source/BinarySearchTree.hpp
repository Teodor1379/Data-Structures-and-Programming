#ifndef __BINARY_SEARCH_TREE_HEADER_INCLUDED__
#define __BINARY_SEARCH_TREE_HEADER_INCLUDED__

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
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T>&);
    BinarySearchTree(BinarySearchTree<T>&&);

    ~BinarySearchTree();

    BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);
    BinarySearchTree<T>& operator=(BinarySearchTree<T>&&);

private:
    Node*   root;
};

#include "BinarySearchTree.inl"

#endif
