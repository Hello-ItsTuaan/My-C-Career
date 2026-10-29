#include <iostream>

int main() {
    int x;
    x = 5;
    std::cout << x << std::endl;

    // double (number including decimal)

    double price = 10.99;
    double temperture = 30.5;
    double gpa = 9.3;

    // char (single character)
    char grade = 'A';
    char intitial = 'B';
    char currency = '$';

    std::cout << intitial << std::endl;

    //boolearn (true/false)
    bool student = false;
    bool power = true;
    bool forSale = true;

    //string (objects that represents a sequence of text)
    std::string name = "Minh Tuan";
    std::string day = "Friday";
    std::string age = "13";
    std::string lopHoc = "8A5";

    std::cout << "Hello " << name << std::endl;
    std::cout << "You're " << age << std::endl;


    return 0;
}