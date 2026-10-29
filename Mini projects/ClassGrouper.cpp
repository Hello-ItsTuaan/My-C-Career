#include <iostream>

int main() {
    int totalStudent;
    int groups;

    std::cout << "Please enter your class's total student: ";
    std::cin >> totalStudent;
    std::cout << std::endl;

    std::cout << "Please enter your groups you want to seperate: ";
    std::cin >> groups;
    std::cout << std::endl;

    int remainder = totalStudent % groups;
    int result = totalStudent / groups;

    std::cout << "Groups: " << groups << std::endl << "Remainder students(s): " << remainder << std::endl;
    std::cin.ignore();
    std::cin.get();

    return 0;
    
}