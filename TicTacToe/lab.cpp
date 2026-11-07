#include <iostream>
int main() {
    char i = 'a';
    std::cout << "\033[42;30m" << i << "\033[0m";
    return 0;
}