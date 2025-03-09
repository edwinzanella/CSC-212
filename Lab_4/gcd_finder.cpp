#include <iostream>

int gcd_finder(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return gcd_finder(num2, num1 % num2);
}

int main(int argc, char* argv[]) {
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    
    std::cout << gcd_finder(num1, num2) << std::endl;
}