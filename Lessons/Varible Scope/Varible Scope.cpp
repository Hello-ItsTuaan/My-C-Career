// // #include <iostream>
// void print();
// int myNum = 3;
// int main() {
//     //?LOCAL varibles = declared inside a function or block {};
//     //?GLOBAL varibles = declared outside of all function;

//     int myNum = 1; // LOCAL
//     std::cout << myNum;
    

//     return 0;
// }

// // void print() {
// //     std::cout << myNum; //WON'T WORK
// // }
// void print() {
//     int myNum = 2;
//     std::cout << myNum;
// }


#include <iostream>
void print();
int myNum = 3;
int main() {
    //?LOCAL varibles = declared inside a function or block {};
    //?GLOBAL varibles = declared outside of all function;

    std::cout << myNum;
    

    return 0;
}

// void print() {
//     std::cout << myNum; //WON'T WORK
// }
void print() {
    std::cout << myNum; 
}
//! C++ ALWAYS prefer local varible over Global
// for example:
/*int myNum = 2;
std::cout << myNum  << "\n"; (becuse it prefers local over global, so if the global varible has value like 1, it still prints 2!) 
std::cout << ::myNum << "\n" (if you want yo use the global varible/value)*/