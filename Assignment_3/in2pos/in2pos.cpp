#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int pemdas(char operation) {
    if (operation == '+' || operation == '-') {
        return 1;
    } else if (operation == '*' || operation == '/') {
        return 2;
    } else if (operation == '^') {
        return 3;
    }
    return 0;
}

bool right_associative(char operation) {
    if (operation == '^') {
        return true;
    }
    return false;
}

std::string infix_to_postfix(std::string expression) {
    std::stack<char> stack;
    std::string postfix;
    std::istringstream ss(expression);
    std::string data;

    while (ss >> data) {
        if (isdigit(data[0]) || (data[0] == '-' && data.size() > 1 && isdigit(data[1]))) {
            postfix += data + " ";
        } 

        else if (data == "(") {
            stack.push('(');
        } 

        else if (data == ")") {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                postfix += " ";
                stack.pop();
            }
            stack.pop();
        }

        else {
            while (!stack.empty() && 
                   ((right_associative(data[0]) && pemdas(stack.top()) > pemdas(data[0])) ||
                    (!right_associative(data[0]) && pemdas(stack.top()) >= pemdas(data[0])))) {
                postfix += stack.top();
                postfix += " ";
                stack.pop();
            }
            stack.push(data[0]);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        postfix += " ";
        stack.pop();
    }

    return postfix;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No expression given." << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    std::string postfix = infix_to_postfix(expression);
    std::cout << postfix << std::endl;

    return 0;
}