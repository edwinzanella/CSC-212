#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "priority_queue.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No File Given" << std::endl;
        return 1;
    }

    //enqueue and print first line
    PriorityQueue queue;
    std::string fname = argv[1];
    std::ifstream infile(fname);
    std::string line;

    std::getline(infile, line);
    std::stringstream ss(line);
    int data;
    int index = 0;

    while (ss >> data) {
        queue.enqueue(data, index++);
    }

    std::cout << queue.to_string() << std::endl;

    // Rest of the lines
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        int data, priority;

        if (line == "-") {
            queue.dequeue();
            std::cout << queue.to_string() << std::endl;
        }

        else if (line == "?") {
            std::pair<int, int> peek = queue.peek();

            if (peek.second == -1) {
                std::cout << "" << std::endl;
            }
            else {
                std::cout << "(" << peek.first << "," << peek.second << ")" << std::endl;
            }
        }

        else if (ss >> data >> priority) {
            queue.enqueue(data, priority);
            std::cout << queue.to_string() << std::endl;
        }
    }

}