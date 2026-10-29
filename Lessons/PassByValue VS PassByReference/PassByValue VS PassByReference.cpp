#include <iostream>

void swap (std::string &x, std::string &y);

int main() {
    std::string x = "Kool-Aid";
    std::string y = "Water";
    std::string temp;



    // temp = x; // Kool Aid
    // x = y; // Water
    // y = temp; //Kool Aid

    //reference pass value by memory address!
    swap(x, y);
    std::cout << "X: " << x << "\n";
    std::cout << "Y: " << y << "\n";
    //? x and y in the main function and swap function have different memory address, so when you change the value of x and y in swap function, it won't affect x and y in the main (that what i think);
    //? We usually pass by reference.
    return 0;
}

void swap (std::string &x, std::string &y) {
    // void swap (std::string x, std::string y) {
    std::string temp;

    temp = x;
    x = y;
    y = temp;
}