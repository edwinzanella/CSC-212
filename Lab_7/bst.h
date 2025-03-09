#pragma once
#include "bst_node.h"
#include <iostream>

class BSTree {
    private:
        Node* root;
        Node* insert (Node* node, int num);
        int height(Node* node);
        void preorder(Node* node, std::ostream&);
        void inorder(Node* node, std::ostream&);
        void postorder(Node* node, std::ostream&);
        void destroy(Node* node);
        Node* remove(Node* node, int num);

    public:
        BSTree();
        ~BSTree();
        void insert(int num);
        int height();
        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);
        void destroy();
        bool search(int num);
        void remove(int num);
};