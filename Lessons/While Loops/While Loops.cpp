#include <iostream>

int main() {
    std::string name;
    while (name.empty()) {  //seem easy heh? (i hope so lol)
        std::cout <<  "Enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name << "\n";
    return 0;
}