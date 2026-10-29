#include <iostream>

int main() {
    // pointers = variable that stores a memory address of another variable
    //                      sometime it is easier to work with an address

    // & address-of operator
    // * deference operator


    std::string name = "Tuaan";
    int age = 13;
    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"}; 

    int *pAge = &age;
    std::string *pName = &name;
    // std::string *pFreepizzas = &freePizzas;
    std::string *pFreepizzas = freePizzas;

    std::cout << *pName << "\n" << *pAge << "\n";
    // std::cout << freePizzas << "\n"; //memory address (Ex: 0x44907ffa30);
    std::cout << *pFreepizzas << "\n";
    
    return 0;
}