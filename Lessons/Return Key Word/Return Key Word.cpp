#include <iostream>
#include <cmath>


double square(double number) {
    return pow(number, 2);
}

int main() {
    int number;
    std::cin >> number;
    double result = square(number);
    std::cout << result;

    return 0;
}