#include <bits/stdc++.h>

int main() {
    std::string input;
    std::getline(std::cin, input);
    int result = 0;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            result += 1;
        }
    }
    std::cout << result;
}
