#include <iostream>
#include <ctime>
#include <cmath>

int main() {
    int m, n, a, b;
    std::cout << "Please enter the range for the game: (ex: 1 100)" << "\n";
    std::cin >> a >> b;

    srand(time(NULL));
    n = rand() % (b - a + 1) + a;

    do {
        std::cout << "Enter your number: ";
        std::cin >> m;

        if (m != n) {
            int diff = abs(m - n);
            // | MAIN SECTION | Thêm nhiễu ngẫu nhiên +/-2 vào khoảng cách thật để tạo hint mơ hồ
            // ? Why this exists: tránh crash khi diff nhỏ, đồng thời hint đổi theo từng lần đoán
            int noise = rand() % 5 - 2;          // random trong [-2, 2]
            int x = std::max(0, diff + noise);   // ! IMPORTANT: không cho x âm

            std::cout << "Almost right! The difference is about " << x << "\n";
        }
    } while (m != n);

    std::cout << "You have guessed the number correctly!\nThe number is " << n << "\n";

    return 0;
}