#pragma once
#include "BST_Node.h"
#include <iostream>

class BSTree {
public:
    BST_Node* root;
public:
    BSTree();
    ~BSTree();
    //metody dla których mierzę czas
    void add_node(int key);
    void erase_node(BST_Node *node_to_erase);

    BST_Node* search(int key);

    //metody dodatkowe
    BST_Node* search_max();
    BST_Node* search_min();

    void print();

private:
    void print_structure(BST_Node* node, int depth);
    void deleteTree(BST_Node *parent);
};