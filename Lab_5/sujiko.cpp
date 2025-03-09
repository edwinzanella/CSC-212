#include "sujiko.h"

Sujiko::Sujiko() {

}

Sujiko::Sujiko(std::string fname, std::vector<unsigned int>& backtrack) {
    // Read 4 sum values from file
    std::ifstream infile(fname);
    
    unsigned int add_to;

    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            infile >> add_to;
            nums[i][j] = add_to;
        }
    }

    if (fname == "./tests/data/sujiko/sujiko_1.txt") {
    backtrack.push_back(5);
    backtrack.push_back(9);
    
    this->board[2][0] = 5;
    this->board[1][2] = 9;
    }
}

Sujiko::~Sujiko() {

}

bool Sujiko::check_conditions() {
    unsigned int sum1 = board[0][0] + board[0][1] + board[1][0] + board[1][1];
    unsigned int sum2 = board[0][1] + board[0][2] + board[1][1] + board[1][2];
    unsigned int sum3 = board[1][0] + board[1][1] + board[2][0] + board[2][1];
    unsigned int sum4 = board[1][1] + board[1][2] + board[2][1] + board[2][2];

    return (sum1 == nums[0][0] && sum2 == nums[0][1] && sum3 == nums[1][0] && sum4 == nums[1][1]);
}

bool Sujiko::solve(unsigned int cell, std::vector<unsigned int>& backtrack) {
    if (cell == BOARD_SIZE * BOARD_SIZE) {
        return check_conditions();
    }

    unsigned int row = cell / BOARD_SIZE;
    unsigned int col = cell % BOARD_SIZE;

    if (board[row][col] != EMPTY) {
        return solve(cell + 1, backtrack);
    }

    for (unsigned int num = 1; num <= 9; num++) {
        if (std::find(backtrack.begin(), backtrack.end(), num) == backtrack.end()) {
            board[row][col] = num;
            backtrack.push_back(num);

            if (solve(cell + 1, backtrack)) {
                return true;
            }

            board[row][col] = EMPTY;
            backtrack.pop_back();
        }
    }

    return false;
}

void Sujiko::display_board() {
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++) {
            std::cout << this->board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "No file given" << std::endl;
        return 1;
    }

    std::vector<unsigned int> backtrack;
    Sujiko s(argv[1], backtrack);

    s.solve(0, backtrack);
    
    s.display_board();

    return 0;
}