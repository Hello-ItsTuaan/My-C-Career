#include <iostream>

int main() {
    std::cout << "Enter first number: ";
    double firstNumber;
    if (!(std::cin >> firstNumber)) {
        std::cout << "Please enter a valid number";
        return 1;
    }
    
    std::cout << "Enter second number: ";
    double secondNumber;
    if (!(std::cin >> secondNumber)) {
        std::cout << "Please enter a valid number";
        return 1;
    }



    std::cout << "Please enter your operation (+, -, *, /): ";
    char operation;


    
    if (!(std::cin >> operation)) {
        std::cout << "Please enter a valid operation";
        return 1;
    }
    
    if (operation == '*') {
        std::cout << "Your answer is: " << firstNumber * secondNumber;
    } else if (operation == '+') {
        std::cout << "Your answer is: " << firstNumber + secondNumber;
    } else if (operation == '-') {
        std::cout << "Your answer is: " << firstNumber - secondNumber;
    } else if (operation == '/') {
        if (secondNumber == 0) {
            std::cout << "SecondNumber can't be 0";
        } else {
        std::cout << "Your answer is: " << firstNumber / secondNumber;
        }
    } else {
        std::cout << "Please enter a valid operation";
    }
    return 0;
}