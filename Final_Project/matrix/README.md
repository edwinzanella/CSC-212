# Sparse Matrices

Sparse matrices are a type of matrix in which most of the elements are zero. They are used to efficiently store and manipulate
data that is mostly empty, reducing memory usage and computational complexity compared to dense matrices.

This code implements sparse matrices using linked lists to hold non-zero values and their position in the matrix. It also implements
basic operations such as addition and multiplication of sparse matrices.

# Files 

- sparse_node.h: Header file for the SparseNode class.
- sparse_node.cpp: Implementation of the SparseNode class.
- sparse_matrix.h: Header file for the SparseMatrix class.
- sparse_matrix.cpp: Implementation of SparseMatrix class.
- sparse_addition.cpp: Demonstrates of addition of two sparse matrices.
- sparse_multiplication.cpp: Demonstrates of multiplication of two sparse matrices.

# Class Documentation

## SparseNode

The SparseNode class represents a node in a linked list. Each node stores the row index, column index, and value of a non-zero
element in the sparse matrix.

### Methods

SparseNode(int rows, int cols, int value): constructor for node object.

## SparseMatrix

The SparseMatrix class represents a sparse matrix using a linked list of SparseNode objects.

### Methods

SparseMatrix(): constructor for matrix object.
void insert(int row, int col, int value): inserts an element into the matrix.
void print(): prints the matrix.
SparseMatrix add(SparseMatrix& other): adds two sparse matrices together
SparseMatrix multiply(SparseMatrix& other): multiplies two sparse matrices together.

# Sparse Matrix Addition

Addition between two matrices requires each matrix to have the same number of columns and rows. 
Addition between matrices is done by adding the two values at the same row and column coordinate in both matrices.
The time complexity of matrix addition is O(n + m), making the time complexity O(n)

To compile the addition program for sparse matrices, use the following command line:
g++ -std=c++11 sparse_node.cpp sparse_matrix.cpp sparse_addition.cpp -o prog

To run the program, use the format below after compiling (assuming that both matrices are the same size):
./prog <first_matrix> <second_matrix>

Each text file starts with two numbers on the first line representing the number of rows and columns in the matrix. If these numbers
are different from each other, the program will throw an error before running the rest of the program.

The result in the terminal should display the two sparse matrices, and the sum sparse matrix.
The format for the output:
Row: <node_row> Column: <node_column> Value: <node_value>

# Sparse Matrix Multiplication

Multiplication between two matrices requires the number of the first matrix's columns to be the same number as the second matrix's rows.
Multiplication between matrices is done calculating the dot product of the i-th row of matrix one and the j-th column of matrix two.
The time complexity of matrix multiplication is O(n x m), making the time complexity O(n), but still slightly slower than addition.

To compile the addition program for sparse matrices, use the following command line:
g++ -std=c++11 sparse_node.cpp sparse_matrix.cpp sparse_multiplication.cpp -o prog

To run the program, use the format below after compiling (assuming the first matrix column and second matrix rows are the same length):
./prog <first_matrix> <second_matrix>

Each text file starts with two numbers on the first line representing the number of rows and columns in the matrix. If the columns of
the first matrix does not match with the rows of the second matrix, the progam will return an error.

The result in the terminal should display the two sparse matrices, and the product sparse matrix.
The format for the output:
Row: <node_row> Column: <node_column> Value: <node_value>