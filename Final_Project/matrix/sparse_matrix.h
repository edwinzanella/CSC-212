#pragma once
#include "sparse_node.h"
#include <vector>
#include <string>

class SparseMatrix {
private:
    SparseNode* head;
    int rows;
    int cols;

public:
    SparseMatrix();
    SparseMatrix(std::string fname);
    ~SparseMatrix();
    void display();
    SparseMatrix add(SparseMatrix& other);
    SparseMatrix multiply(SparseMatrix& other);
};
