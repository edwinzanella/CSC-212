#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    // Generate a board from the give file
    std::ifstream infile(f_name);

    unsigned int add_to;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            infile >> add_to;
            this->board[i][j] = add_to;
        }
    }
}

bool Sudoku::solve() {
    unsigned int row, col;
    if (!is_empty(row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (solve())
                return true;
            board[row][col] = EMPTY;
        }
    }

    return false;
}

// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return (this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){
    for (unsigned int col = 0; col < BOARD_SIZE; col++) {
        if (board[row][col] == num)
            return true;
    }

    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){
    for (unsigned int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][col] == num)
            return true;
    }

    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){
    for (unsigned int row = 0; row < 3; row++) {
        for (unsigned int col = 0; col < 3; col++) {
            if (board[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }

    return false;
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Sudoku::is_empty(unsigned int &row, unsigned int &col) {
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY)
                return true;
        }
    }
    return false;
}

int main(int argc, char * argv[])
{
    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}
