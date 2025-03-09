#include "path.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

Path::Path(std::string fname, int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->map = std::vector<std::vector<int>>(rows, std::vector<int>(cols));

    std::ifstream infile(fname);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            infile >> value;
            this->map[i][j] = value;
        }
    }
}

Path::~Path() {}

void Path::display() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::pair<int, int> Path::get_minimum_coordinate() {
    int min = -1;
    std::pair<int, int> min_coordinate = {0, 0};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (min == -1 || map[i][j] < min) {
                min = map[i][j];
                min_coordinate = {i, j};
            }
        }
    }

    return min_coordinate;
}

std::pair<int, int> Path::get_maximum_coordinate() {
    int max = -1;
    std::pair<int, int> max_coordinate = {0, 0};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (max == -1 || map[i][j] > max) {
                max = map[i][j];
                max_coordinate = {i, j};
            }
        }
    }

    return max_coordinate;
}

bool Path::path_exists() {
    std::pair<int, int> min = get_minimum_coordinate();
    std::pair<int, int> max = get_maximum_coordinate();
    int min_value = map[min.first][max.second];
    int max_value = map[min.first][max.second];

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::queue<std::pair<int, int>> queue;
    queue.push(min);
    visited[min.first][max.second] = true;

    std::vector<int> direction_row = {-1, 1, 0, 0};
    std::vector<int> direction_col = {0, 0, -1, 1};

    while (!queue.empty()) {
        std::pair<int, int> current = queue.front();
        int current_row = current.first;
        int current_col = current.second;
        queue.pop();

        if (current_row == max.first && current_col == max.second) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int new_row = current_row + direction_row[i];
            int new_col = current_col + direction_col[i];

            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols &&
                !visited[new_row][new_col] && map[new_row][new_col] >= map[current_row][current_col]) {
                visited[new_row][new_col] = true;
                queue.push({new_row, new_col});
            }
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::string fname = argv[1];
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);

    Path path(fname, rows, cols);

    std::pair<int, int> min = path.get_minimum_coordinate();
    std::pair<int, int> max = path.get_maximum_coordinate();

    std::cout << min.first + 1 << " " << min.second + 1 << " ";
    std::cout << max.first + 1 << " " << max.second + 1 << " ";

    if (path.path_exists()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}