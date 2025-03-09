#include "linked_list.h"
#include "node.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){
    std::string fname = argv[1];
    std::vector<int> data;
    std::ifstream infile(fname);
    LinkedList list;
    std::string line;

    list.choose_constructor(fname, list, infile);

    while (std::getline(infile, line)) {
        list.get_line(line, data, infile, list);
    }

    infile.close();
}