#include "DynamicArray.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    std::string fname = argv[1];
    double scaling_factor = 2.0;
    int initial_capacity = 1;
    int default_value = 0;


    if (argc > 2) {
        scaling_factor = atof(argv[2]);
    }

    if (argc > 3) {
        initial_capacity = atoi(argv[3]);
    }

    if (argc > 4) {
        default_value = atoi(argv[4]);
    }

    DynamicArray dynamic_array(scaling_factor, initial_capacity);
    std::ifstream infile(fname);

    int value;
    int total = 0;
    while (infile >> value) {
        total ++;
    }

    infile.clear();
    infile.seekg(std::ios_base::beg);

    int half = total / 2;

    for (int i = 0; i < half && infile >> value; i++) {
        dynamic_array.append(value);
    }

    std::cout << dynamic_array.to_string() << std::endl;

    infile.clear();
    infile.seekg(half * 2);

    for (int i = 0; i < half && infile >> value; i++) {
        dynamic_array.prepend(value);
    }

    std::cout << dynamic_array.to_string() << std::endl;

    infile.close();


    std::cout << dynamic_array.get_capacity() << std::endl;
    std::cout << dynamic_array.get_length() << std::endl;
    return 0;
}