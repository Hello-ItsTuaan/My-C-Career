// //Ex 1:
// #include <iostream>


// int main() {
//     std::string result;
//     int number;


//     std::cin >> number;

//     number % 2 == 1 ? result = "ODD" : result = "EVEN";
//     std::cout << "Result: " << result << "\n";
//     return 0;
// }


// EX 2:
#include <iostream>

int main() {
    int grade;
    char letter;

    std::cin >> grade;
    grade >= 60 ? letter = 'P' : letter = 'F';
    std::cout << letter;
    return 0;
}