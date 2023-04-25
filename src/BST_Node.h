#pragma once

class BST_Node {
public:
    int key;
    BST_Node* parent = nullptr;
    BST_Node* child_right = nullptr;
    BST_Node* child_left = nullptr;
public:
    BST_Node(int key);
};

