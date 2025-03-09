#include "sparse_matrix.h"
#include <fstream>
#include <iostream>

SparseMatrix::SparseMatrix() {
    head = nullptr;
    rows = 0;
    cols = 0;
}

SparseMatrix::SparseMatrix(std::string fname) {
    std::ifstream infile(fname);
    if (!infile) {
        std::cerr << "File could not be opened" << std::endl;
        head = nullptr;
        rows = 0;
        cols = 0;
        return;
    }

    infile >> rows >> cols;

    head = nullptr;
    SparseNode* current = nullptr;

    // loop through each element in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            infile >> value;

            // only process non-zero values
            if (value != 0) {
                SparseNode* newNode = new SparseNode(i, j, value);

                // sets the new node to the head if a value hasn't been assigned to head yet
                if (head == nullptr) {
                    head = newNode;
                    current = head;
                }
                else {
                    current->next = newNode;
                    current = current->next;
                }
            }
        }
    }

    infile.close();
}

SparseMatrix::~SparseMatrix() {
    
}

void SparseMatrix::display() {
    SparseNode* current = head;
    while (current != nullptr) {
        std::cout << "Row: " << current->row << " Column: " << current->col << " Value: " << current->data << std::endl;
        current = current->next;
    }
}

SparseMatrix SparseMatrix::add(SparseMatrix& other) {
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cerr << "Incompatible matrix dimensions for addition" << std::endl;
        return SparseMatrix();
    }

    SparseMatrix result;

    SparseNode* current1 = this->head;
    SparseNode* current2 = other.head;
    SparseNode* result_current = nullptr;

    // traverse both matrices
    while (current1 != nullptr || current2 != nullptr) {
        // if first node is exhausted, add remaining nodes from the second matrix
        if (current1 == nullptr) {
            SparseNode* newNode = new SparseNode(current2->row, current2->col, current2->data);
            if (result.head == nullptr) {
                result.head = newNode;
                result_current = result.head;
            }
            else {
                result_current->next = newNode;
                result_current = result_current->next;
            }
            current2 = current2->next;
        }

        // if second node is exhausted, add remaining nodes from the first matrix
        else if (current2 == nullptr) {
            SparseNode* newNode = new SparseNode(current1->row, current1->col, current1->data);
            if (result.head == nullptr) {
                result.head = newNode;
                result_current = result.head;
            }
            else {
                result_current->next = newNode;
                result_current = result_current->next;
            }
            current1 = current1->next;
        }

        // if current1 comes first, create next node
        else if (current1->row < current2->row || (current1->row == current2->row && current1->col < current2->col)) {
            SparseNode* newNode = new SparseNode(current1->row, current1->col, current1->data);
            if (result.head == nullptr) {
                result.head = newNode;
                result_current = result.head;
            }
            else {
                result_current->next = newNode;
                result_current = result_current->next;
            }
            current1 = current1->next;
        }

        // if current2 comes first, create next node
        else if (current2->row < current1->row || (current2->row == current1->row && current2->col < current1->col)) {
            SparseNode* newNode = new SparseNode(current2->row, current2->col, current2->data);
            if (result.head == nullptr) {
                result.head = newNode;
                result_current = result.head;
            }
            else {
                result_current->next = newNode;
                result_current = result_current->next;
            }
            current2 = current2->next;
        }

        // if both current1 and current2 point to the same position, add their values
        else {
            int sum = current1->data + current2->data;
            if (sum != 0) {
                SparseNode* newNode = new SparseNode(current1->row, current1->col, sum);
                if (result.head == nullptr) {
                    result.head = newNode;
                    result_current = result.head;
                }
                else {
                    result_current->next = newNode;
                    result_current = result_current->next;
                }
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    return result;
}

SparseMatrix SparseMatrix::multiply(SparseMatrix& other) {
    if (this->cols != other.rows) {
        std::cerr << "Incompatible matrix dimensions for multiplication" << std::endl;
        return SparseMatrix();
    }

    SparseMatrix result;

    // creates a 2D vector to temporarily hold the values of the result matrix
    std::vector<std::vector<int>> temp(this->rows, std::vector<int>(other.cols, 0));
    SparseNode* current1 = this->head;

    // multiplies first matrix columns by second matrix rows and adds to temp
    while (current1 != nullptr) {
        SparseNode* current2 = other.head;
        while (current2 != nullptr) {
            if (current1->col == current2->row) {
                temp[current1->row][current2->col] += current1->data * current2->data;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }


    // convert vector values to a sparse matrix
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            if (temp[i][j] != 0) {
                SparseNode* newNode = new SparseNode(i, j, temp[i][j]);
                if (result.head == nullptr) {
                    result.head = newNode;
                }
                else {
                    SparseNode* current = result.head;
                    while (current->next != nullptr) {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
        }
    }

    return result;
}
