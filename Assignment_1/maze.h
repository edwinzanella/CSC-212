#ifndef MAZE_H
#define MAZE_H
#include <vector>

class Maze {
    private:
        int rows, cols, seed;
        std::vector<std::vector<int>> visited;
        std::vector<std::pair<int, int>> unvisited_neighbors;
        std::pair<int, int> current;
        std::vector<std::vector<std::string>> wall_vector;
        std::vector<std::vector<int>> integer_wall_vector;
    public:
        void visited_vector(int rows, int cols, int seed);
        void get_unvisited_neighbors(std::pair<int, int> current);
        void initial_wall_vector(int rows, int cols);
        void create_maze(int rows, int cols, int seed);
        void remove_wall(std::pair<int, int> current, std::pair<int, int> neighbor);
        void run(int rows, int cols, int seed, std::string fname);
        void convert_from_binary(int rows, int cols);
        int binary_to_decimal(std::string binary);
        void outfile(std::string fname);
};

#endif