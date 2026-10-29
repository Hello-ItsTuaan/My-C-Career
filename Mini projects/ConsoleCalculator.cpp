#include <iostream>

int main() {
    double num1;
    double num2;
    double result = 0;


    std::cout << "====== CALCULATOR ======\n";
    std::cout << "Enter either (+ - / *): ";

    char op;
    std::cin >> op;

    if (op != '+' && op != '-' && op != '*' && op != '/') {
    std::cout << "Invalid operator!\n";
    return 1;
    }


    std::cout << "Enter  #1: ";
    if(!(std::cin >> num1)) {
        std::cout << "\nPlease enter a valid number!" << "\n";
        return 1;
    }

    std::cout << "Enter #2: ";
    if(!(std::cin >> num2)) {
        std::cout << "\nPlease enter a valid number!" << "\n";
        return 1;
    }


    //^Review switch;


    switch(op) {
        case '+':
        result = num1 + num2;
        break;

        case '-':
        result = num1 - num2;
        break;

        case '/':
        if (num2 == 0) {
            std::cout << "Cannot divide by zero!\n";
            return 1;
        }
        result = num1 / num2;
        break;

        case '*':
        result = num1 * num2;
        break;

        default:
            std::cout << "\nSomething ain't right!\n";
            return 1;
    }
    std::cout << "Result: " << result << "\n";
    std::cout << "========================\n";



    return 0;
}