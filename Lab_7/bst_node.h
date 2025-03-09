#pragma once

class Node {
    private:
        int data;
        Node* left_child;
        Node* right_child;
        friend class BSTree;

    public:
        Node(int data);
        ~Node();
};