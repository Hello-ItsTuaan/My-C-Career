#include <iostream>


int main() {
    // if statement = do something if a condition is true;
    // if not, then don't do it.


    int age;

    std::cout << "Enter your age: ";
    if (!(std::cin >> age)) {
      std::cout << "Please enter a valid age.";
      return 1;
   }

    if (age >= 18) {
        std::cout << "You're an adult!";
    }
     else if (age <= 10) {
        std::cout << "You're a kid!";
     }
     else if (age <= 18) {
        std::cout << "You're a Teenager!";
     } else {
        std::cout << "Did you type something wrong?";
     }

    return 0;
}