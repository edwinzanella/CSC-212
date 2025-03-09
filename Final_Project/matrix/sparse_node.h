#pragma once

class SparseNode {
private:
    int row;
    int col;
    int data;
    SparseNode* next;
    friend class SparseMatrix;

public:
    SparseNode(int row, int col, int data);
    ~SparseNode();
};
