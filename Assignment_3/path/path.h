#pragma once
#include <vector>
#include <string>

class Path {
    private:
        int rows;
        int cols;
        std::vector<std::vector<int> > map;

    public:
        Path(std::string fname, int rows, int cols);
        ~Path();
        void display();
        std::pair<int, int> get_minimum_coordinate();
        std::pair <int, int> get_maximum_coordinate();
        bool path_exists();
};