#include <iostream>


void Happy_Birthday(std::string name, int age); //declare a function of you put the function outside of the scope!


int main() {
    //function = a block of resuable code;
    std::string name = "Tuaan";
    int age = 13;
    Happy_Birthday(name, age);
    Happy_Birthday(name, age);
    Happy_Birthday(name, age);


    return 0;
}

void Happy_Birthday(std::string name, int age) { 
    std::cout << "Happy Birdthday to " << name << "\n";
    std::cout << "Happy Birdthday to you " << name << "\n";
    std::cout << "Happy Birdthday dear you " << name << "\n";
    std::cout << "Happy Birdthday to you " << name << "\n";
    std::cout << "You're now " << age << "\n\n";
}