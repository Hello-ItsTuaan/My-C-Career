#include <iostream>


int main() {
    double temp;    
    char unit;
    std::cout << "******* Temperature Conversion *******" << "\n";
    std::cout << "F = Farenheiht" << "\n";

    std::cout << "C = Celcius" << "\n";

    std::cout << "What unit you need to convert to: ";
    std::cin >> unit;

    if (unit == 'F' || unit == 'f') {
        std::cout << "Enter temperature in Celcius: ";
        std::cin >> temp;
        std::cout << "Your temperature in Farenheigt: " << (temp * 9 /5) + 32<< " F" << "\n";
    }
    else if (unit == 'C' || unit == 'c') {
        std::cout << "Enter temperature in Farenheigt: ";
        std::cin >> temp;
        std::cout << "Your temperature in Celcius: " << (temp -32) * 1.8 << " C" << "\n";
    }
    else {
        std::cout << "Please only input only C or F";
        return 1;
    }
    std::cout << "**********************" << "\n";
    return 0;
}