#include <iostream>

int main() {
    //?             Do while loops, do some blocks of code first,
    //?                                        THEN, repeart againt if the condition is true;


    int number;
    
    // std::cout << "Enter a positive number: ";
    // std::cin >> number;
    //! It's fine, but we are using 2 lines of same code;
    // while (number < 0 ) {
    //     std::cout << "Enter a positive number: ";
    //     std::cin >> number;
    // }


    //Instead we can do this using do while loops;



    do { 
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while (number < 0);

    //? Will asign the Varible "number" first then check

    std::cout << "The number is: " << number;
    return 0;
}