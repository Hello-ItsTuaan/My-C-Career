#include <iostream>

int main() {
    /*
        | MAIN SECTION |
        In ra 1 hình chữ nhật gồm "row" hàng và "columns" cột
        bằng ký tự do người dùng nhập
    */

    int row, columns;
    char symbol;

    std::cout << "How many rows?: ";
    std::cin >> row;

    std::cout << "How many columns?: ";
    std::cin >> columns;

    std::cout << "Enter a symbol to use: ";
    std::cin >> symbol;

    // | MAIN SECTION | Vòng lặp in hình chữ nhật

    int currentCol = columns;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= currentCol; j++) {   // ! IMPORTANT: phải tăng j, không phải trừ columns
            std::cout << symbol;
        }
        std::cout << "\n";
        currentCol -= 1;
    }

    return 0;
}