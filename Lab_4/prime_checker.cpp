#include <iostream>

bool is_prime(int number, int test_num){

    if (number <= 2) {
        if (number == 2) {
            return true;
        }
        else {
            return false;
        }
    }

    if (number % test_num == 0) {
        return false;
    }
    if (test_num > number / 2) {
        return true;
    }

    return is_prime(number, test_num + 1);
}

int main(int argc, char* argv[]) {
    int number = atoi(argv[1]);
    int test_num = 2;
    std::cout << is_prime(number, test_num) << std::endl;
}