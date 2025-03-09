#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "queue.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No File Given" << std::endl;
        return 1;
    }

    //enqueue and print first line
    Queue queue;
    std::string fname = argv[1];
    std::ifstream infile(fname);

    std::string line;
    std::getline(infile, line);
    std::stringstream ss(line);
    std::string data;

    while (ss >> data) {
        queue.enqueue(std::stoi(data));
    }

    std::cout << queue.to_string() << std::endl;

    // rest of the lines
    while (infile >> data) {
        if (data == "-") {
            queue.dequeue();
            std::cout << queue.to_string() << std::endl;
        }
        else if (data == "?"){
            std::cout << queue.peek() << std::endl;
        }
        else {
            queue.enqueue(stoi(data));
            std::cout << queue.to_string() << std::endl;
        }
    }

}