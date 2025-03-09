#include <iostream>

int sum_of_digits(int number) {
    if (number == 0) {
        return number;
    }

    return number % 10 + sum_of_digits(number / 10);
}

int main(int argc, char *argv[]){
    int number = atoi(argv[1]);
    std::cout << sum_of_digits(number) << std::endl;
}