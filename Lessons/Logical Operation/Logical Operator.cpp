#include <iostream>


int main() {
    // && = check if two conditions are true;
    // || = check if at least one of two conditions is true;
    // ! = reverse the logical state of its operand;


    int temp;
    bool sunny;

    std::cout << "Enter the temperature" << "\n";
    std::cin >> temp;

    if (temp > 0 && temp < 30) {
        std::cout << "The temperature is good" << "\n";
    } else if(temp <= 0 || temp >= 30) {
        std::cout << "The temperature is bad" << "\n";
    }
    else {
        std::cout << "Something ain't right!" << "\n";
    }

    if (!sunny) {
        std::cout << "wtf niga?" << "\n";
    }
    return 0;
}