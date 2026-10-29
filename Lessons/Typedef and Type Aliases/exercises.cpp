#include <iostream>

using celcius_t = double;

int main() {
    celcius_t celcius;
    std::cout << "Please enter your Celcius temperature: ";
    std::cin >> celcius;

    celcius_t Fahrenheit = (celcius * 1.8) + 32;

    std::cout << Fahrenheit  << std::endl;
}