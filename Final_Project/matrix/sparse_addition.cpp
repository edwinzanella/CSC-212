#include "sparse_matrix.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Two files not given" << std::endl;
        return 1;
    }

    std::string fname1 = argv[1];
    std::string fname2 = argv[2];

    SparseMatrix matrix1(fname1);
    SparseMatrix matrix2(fname2);

    std::cout << "Sparse Matrix 1:" << '\n';
    matrix1.display();
    std::cout << '\n';

    std::cout << "Sparse Matrix 2:" << '\n';
    matrix2.display();
    std::cout << '\n';

    SparseMatrix result = matrix1.add(matrix2);

    std::cout << "Sum Matrices:" << '\n';
    result.display();
    std::cout << '\n';

    return 0;
}
