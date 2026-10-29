#include <iostream>


int main() {
    //? Ternary operator ?= :  replacement to an if else statement
    //^Condition ? expression1 :expression2;


    // int grade = 50;
    // grade >= 60 ? std::cout << "You passed!" : std::cout << "You failed!";

    // int number = 9;
    // number % 2 == 1 ? std::cout << "ODD" : std::cout << "EVEN";

    bool hungry = true;

    // hungry ? std::cout << "You are hungry" : std::cout << "You're full";
    std::cout << (hungry ? "You're hungry" : "You're full"); 
    return 0;

    

}