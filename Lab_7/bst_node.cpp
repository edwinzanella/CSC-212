#include "bst_node.h"

Node::Node(int data) {
    this->data = data;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

Node::~Node() {

}