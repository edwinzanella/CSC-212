#include "n_queens.h"

NQueens::NQueens(){
    this->board_size = 0;
    this->board = nullptr;
}

NQueens::~NQueens(){
    delete this->board;
}

NQueens::NQueens(unsigned int n){
    this->board_size = n;

    board = new std::vector<std::vector<unsigned int >>(n, std::vector<unsigned int>(n));
}

bool NQueens::solve_rec(int col){
    //If all queens are placed then return true
    if (col + 1 > this->board_size) {
        return true;
    }

    for (int row = 0; row < this->board_size; row++) {
        if (is_valid_row(row, col)) {
            (*this->board)[row][col] = 1;

        if (solve_rec(col + 1)) {
            return true;
        }

        (*this->board)[row][col] = 0;
        }
    }

    return false;
}

bool NQueens::is_valid_row(unsigned int row, unsigned int col){
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if ((*this->board)[row][i]) { return false; }

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if ((*this->board)[i][j]) { return false; }

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < this->board_size; i++, j--)
        if ((*this->board)[i][j]) { return false; }

    return true;
}

void NQueens::display_board(){
    for (unsigned int i = 0; i < this->board_size; i++) {
        for (unsigned int j = 0; j < this->board_size; j++){
            std::cout << (*this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char*argv[])
{
    unsigned int n = std::stoi(argv[1]);

    NQueens Q(n);

    Q.solve_rec(0);

    Q.display_board();

    return 0;
}
