#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

int answer(std::string& expression) {
    std::stack<int> stack;
    std::istringstream ss(expression);
    std::string data;

    while (ss >> data) {
        if (isdigit(data[0]) || (data[0] == '-' && data.size() > 1 && isdigit(data[1]))) {
            stack.push(std::stoi(data));
        }
        else {
            int num2 = stack.top(); stack.pop();
            int num1 = stack.top(); stack.pop();
            int result;

            if (data[0] == '+') {
                result = num1 + num2;
            }
            else if (data[0] == '-') {
                result = num1 - num2;
            }
            else if (data[0] == '*') {
                result = num1 * num2;
            }
            else if (data[0] == '/') {
                if ((num1 < 0) != (num2 < 0) && num1 % num2 != 0) {
                    result = num1 / num2 - 1;
                }
                else {
                    result = num1 / num2;
                }
            }
            else if (data[0] == '^') {
                result = std::pow(num1, num2);
            }

            stack.push(result);
        }
    }

    return stack.top();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No expression given." << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    int result = answer(expression);
    std::cout << result << std::endl;

    return 0;
}