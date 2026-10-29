#include <iostream>

void printInfo(const std::string &name, const int &age); //btw I forgot about past by references and value :v how can it affect this "Const" lesson lOL

int main() {
    // const paremeter = parameter that is effectively read-only
    //                  code is more secure and conveys intent
    //                     useful for references and pointers
    std::string name = "Tuaan";
    int age = 13;

    printInfo(name, age);
    return 0;
}


void printInfo(const std::string &name, const int &age) {
    // name = " ";
    // age = 0;
    std::cout << name << "\n" << age;
}