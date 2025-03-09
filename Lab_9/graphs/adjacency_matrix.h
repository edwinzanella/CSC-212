#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class AdjMatrix {
    private:
        std::vector<std::vector<int>> matrix;
        int vertices;

        void resize(int new_size){
            matrix.resize(new_size);

            for (int i = 0; i < new_size; i++) {
                matrix[i].resize(new_size, 0);
            }

            vertices = new_size;
        }

    public:
        AdjMatrix(){
            vertices = 0;
        }

        void addEdge(int source, int dest, int weight) {
            int max_vertex = std::max(source, dest);

            if (max_vertex >= vertices) {
                resize(max_vertex + 1);
            }

            matrix[source][dest] = weight;
        }

        void printGraph(){
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        void outputGraph(std::string ofname) {
            std::ofstream dotfile(ofname);
            dotfile << "digraph G {" << std::endl;
            dotfile << std::endl;

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (matrix[i][j] != 0) {
                        dotfile << "    " << i << " -> " << j << " [label=\"" << matrix[i][j] << "\"];" << std::endl;
                    }
                }
            }

            dotfile << std::endl;
            dotfile << "}" << std::endl;
            dotfile.close();
        }
};