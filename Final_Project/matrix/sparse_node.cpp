#include "sparse_node.h"

SparseNode::SparseNode(int row, int col, int data) {
    this->row = row;
    this->col = col;
    this->data = data;
    this->next = nullptr;
}

SparseNode::~SparseNode() {
    
}
