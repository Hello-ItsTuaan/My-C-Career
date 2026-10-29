#include <iostream>

// Type conversion = conversion of a value of one data type to another
                    //? Implicit = automatic;
                    //? Explicit = Precede a value with new data type  (int)

int main( ) {
    // // int x = 3.14; output = 3;
    // // double x = 3.14; output = 3.14
    // double x = (int) 3.14; //convert x to int
    // std::cout << x;

    // char x = 100; // output = d (binary code); - std::cout << char (100);

    int correct = 8;
    int question = 10;
    int incorrect = question - correct;


    double scoreLost = incorrect / (double) question * 100; //! WRONG! int devision, we need to use (double) question. Idk why
    //? Nếu không có (double) => int / int (tức 2 / 10 = 0, 0 * 100 = 0) 


    std::cout << scoreLost << "%";

    return 0;
}