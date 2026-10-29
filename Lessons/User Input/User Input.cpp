#include <iostream>

int main() {
    // cout << (Insertion Operator)
    // cin >> (Extraction Operator)

    std::string name;
    std::string city;
    int age;


    // std::cout << "What is your name: \n";
    // std::cin >> name;

    std::cout << "Where are you living: \n";
    std::getline (std::cin >> std::ws, city);

    std::cout << "How old are you: \n";
    std::cin >> age;

    std::cout << "What is your full name: \n";
    std::getline(std::cin >> std::ws, name); // If there is something above this, it won't work, so we need to add std::ws

    std::cout << "Hello, " << name << "\n";
    std::cout << "You're " << age << "\n";
    std::cout << "You're living at " << city;


    return 0;
}