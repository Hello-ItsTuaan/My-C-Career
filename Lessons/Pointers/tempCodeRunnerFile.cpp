#include <iostream>

int main() {
    // pointers = variable that stores a memory address of another variable
    //                      sometime it is easier to work with an address

    // & address-of operator
    // * deference operator


    std::string name = "Tuaan";
    std::string *pName = &name;

    std::cout << pName;


    return 0;
}