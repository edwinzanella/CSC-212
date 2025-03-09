#include <iostream>
#include "maze.h"
#include <vector>
#include <fstream>

void Maze::visited_vector(int rows, int cols, int seed){
    this->rows = rows;
    this->cols = cols;
    this->seed = seed;

    std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));

    visited[0][0] = 1;

    this->visited = visited;
}

void Maze::get_unvisited_neighbors(std::pair<int, int> current) {
    std::vector<std::pair<int, int>> neighbors;
    int x = current.first;
    int y = current.second;

    if (x > 0 && visited[x - 1][y] == 0) {
        neighbors.push_back({x - 1, y});
    }
    if (x < rows - 1 && visited[x + 1][y] == 0) {
        neighbors.push_back({x + 1, y});
    }
    if (y < cols - 1 && visited[x][y + 1] == 0) {
        neighbors.push_back({x, y + 1});
    }
    if (y > 0 && visited[x][y - 1] == 0) {
        neighbors.push_back({x, y - 1});
    }

    this->unvisited_neighbors = neighbors;
}

void Maze::initial_wall_vector(int rows, int cols) {
    rows = this->rows;
    cols = this->cols;

    std::vector<std::vector<std::string>> wall_vector(rows, std::vector<std::string>(cols, "1111"));

    wall_vector[0][0] = "0111";
    wall_vector[rows - 1][cols - 1] = "1011";

    if (rows == 1 && cols == 1) {
        wall_vector[0][0] = "0011";
    }

    this->wall_vector = wall_vector;
}

void Maze::remove_wall(std::pair<int, int> current, std::pair<int, int> neighbor) {
    int x = neighbor.first - current.first;
    int y = neighbor.second - current.second;

    if (x == -1) {
        wall_vector[current.first][current.second][0] = '0';
        wall_vector[neighbor.first][neighbor.second][1] = '0';
    }
    else if (x == 1) {
        wall_vector[current.first][current.second][1] = '0';
        wall_vector[neighbor.first][neighbor.second][0] = '0';
    }
    else if (y == -1) {
        wall_vector[current.first][current.second][3] = '0';
        wall_vector[neighbor.first][neighbor.second][2] = '0';
    }
    else if (y == 1) {
        wall_vector[current.first][current.second][2] = '0';
        wall_vector[neighbor.first][neighbor.second][3] = '0';
    }
}

void Maze::create_maze(int rows, int cols, int seed) {
    rows = this->rows;
    cols = this->cols;
    seed = this->seed;

    std::vector<std::pair<int, int>> backtrack;
    backtrack.push_back({0, 0});
    std::srand(seed);

    while (!backtrack.empty()) {
        current = backtrack.back();
        backtrack.pop_back();
        get_unvisited_neighbors(current);
        if (unvisited_neighbors.empty()) {
            continue;
        }

        backtrack.push_back(current);
        int idx = std::rand() / ((RAND_MAX + 1u) / unvisited_neighbors.size());
        std::pair<int, int> neighbor = unvisited_neighbors[idx];

        remove_wall(current, neighbor);

        visited[neighbor.first][neighbor.second] = 1;
        backtrack.push_back(neighbor);
    }
}

void Maze::convert_from_binary(int rows, int cols) {
    std::vector<std::vector<int>> integer_wall_vector(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            integer_wall_vector[i][j] = binary_to_decimal(wall_vector[i][j]);
        }
    }

    this->integer_wall_vector = integer_wall_vector;
}

int Maze::binary_to_decimal(std::string binary) {
    int decimal = 0;

    for (unsigned int i = 0; i < binary.size(); i++) {
        char digit = binary[i];
        decimal = decimal * 2 + (digit - '0');
    }

    return decimal;
}

void Maze::outfile(std::string fname) {
    std::ofstream outfile(fname);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            outfile << integer_wall_vector[i][j] << " ";
        }
        outfile << '\n';
    }

    outfile.close();
}

void Maze::run(int rows, int cols, int seed, std::string fname){
    visited_vector(rows, cols, seed);
    initial_wall_vector(rows, cols);
    create_maze(rows, cols, seed);
    convert_from_binary(rows, cols);
    outfile(fname);
}