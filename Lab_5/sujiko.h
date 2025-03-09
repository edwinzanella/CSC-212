#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class Sujiko{
private:
    const unsigned int EMPTY = 0;
    const unsigned int BOARD_SIZE = 3;
    std::vector<std::vector<unsigned int> > board = std::vector<std::vector<unsigned int> >(3, std::vector<unsigned int>(3, 0));
    std::vector<std::vector<unsigned int> > nums = std::vector<std::vector<unsigned int> >(2, std::vector<unsigned int>(2, 0));

public:
    Sujiko();
    explicit Sujiko(std::string fname, std::vector<unsigned int>& backtrack);
    ~Sujiko();

    bool solve(unsigned int cell, std::vector<unsigned int>& backtrack);
    void display_board();
    bool check_conditions();
};