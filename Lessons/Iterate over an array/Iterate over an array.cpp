#include <iostream>

int main() {
    std::string students[] = {"Spongbob", "Patric", "Squidward", "Tuaan"};
    // std::cout << students[0] << "\n";
    // std::cout << students[1] << "\n";
    // std::cout << students[2] << "\n";

    for (int i = 0; i <= sizeof(students)/sizeof(std::string); i++) {
        std::cout << students [i] << "\n";
    }

    return 0;
}