#include <iostream>
#include "maze.h"

int main(int argc, char* argv[]){
    int seed, N, M;
    seed = atoi(argv[1]);
    N = atoi(argv[2]);
    M = atoi(argv[3]);
    std::string fname = argv[4];

    Maze maze;
    maze.run(N, M, seed, fname);
    
    return 0;
}