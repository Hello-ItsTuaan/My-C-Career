#include <bits/stdc++.h>

// ─────────────────────────────────────────────
// | FUNCTION DECLARATIONS |
// ─────────────────────────────────────────────
int getDigit(const int number);
int sumOddDigits(const std::string& cardNumber);
int sumEvenDigits(const std::string& cardNumber);

int main() {
    long long n;

    // ! IMPORTANT: đọc input TRƯỚC khi freopen,
    // ? Why this exists: freopen xong thì cout chạy vào file,
    //   dòng "Enter a range" sẽ không hiện trên màn hình nữa
    std::cout << "Enter a range: ";
    std::cin >> n;

    // WARNING: mode phải là "w" (ghi), không phải "r" (đọc)
    freopen("output.txt", "w", stdout);

    for (long long i = 0; i <= n; i++) {
        // TODO: dùng biến số để đếm, rồi đổi sang string để tính Luhn
        std::string cardNumber = std::to_string(i);
        int result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

        if (result % 10 == 0) {
            std::cout << cardNumber << "\n";
        }
    }

    return 0;
}

int getDigit(const int number) {
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string& cardNumber) {
    int sum = 0;

    // ! IMPORTANT: đi lùi nên điều kiện là i >= 0 (không phải <= 0)
    for (int i = static_cast<int>(cardNumber.size()) - 2; i >= 0; i -= 2) {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
}

int sumEvenDigits(const std::string& cardNumber) {
    int sum = 0;

    for (int i = static_cast<int>(cardNumber.size()) - 1; i >= 0; i -= 2) {
        sum += getDigit(cardNumber[i] - '0');
    }

    return sum;
}