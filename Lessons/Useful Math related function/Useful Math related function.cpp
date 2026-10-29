//! MAX
// #include <iostream>

// int main() {
//     double x = 3;
//     double y = 4;
//     double z;

//     z = std::max(x, y);
//     std::cout << z;

//     return 0;
// }

//!MIN
// #include <iostream>
// #include <cmath>


// int main() {
//     double x = 3;
//     double y = 4;
//     double z;

//     z = std::min(x, y);
//     std::cout << z;

//     return 0;
// }

//TODO Cmath (power)

#include <iostream>
#include <cmath>


int main() {
    double price = 49.999;
    double a = 5;
    double x = 3.99;
    double y = 4;
    double z;

    // z = pow(2, 3);
    // z = pow (2, 4);
    // z = abs(-3);
    // z = sqrt(9);
    // z = round(x);
    // z = ceil(x);
    // z = floor(x);

    //? Exercise 1
    z = std::max(std::max(x, y), a);


    std::cout << z << "\n";


    //? Exercise 2
    std::cout << round(price) << "\n";
    std::cout << ceil(price) << "\n";
    return 0;
}
