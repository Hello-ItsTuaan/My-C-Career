#include <iostream>
#include <cmath>

int main() {
    double a;
    double b;

    double c;


    std::cout << "Enter side A: ";
    std::cin >> a;

    std::cout << "Enter side B: ";
    std::cin >> b;


    a = pow(a, 2); // bình phương   
    b = pow(b, 2); // bình phương

    c = sqrt(a + b); // Căn bậc 2; (định lý Pythagore: A2 + B2 = C2 => C = sqrt(a + b))
    //^: chúng ta có thể sử dụng c = sqrt (pow(a, 2) + pow(b, 2))


    std::cout << "Side C: " << c;
    return 0;
}