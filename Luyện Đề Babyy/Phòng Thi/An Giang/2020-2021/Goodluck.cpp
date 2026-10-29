#include <bits/stdc++.h>
int main() {
    freopen("BAI02.INP", "r", stdin);
    freopen("BAI02.OUT", "w", stdout);
    
    std::string chuoi1, chuoi2;
    std::cin >> chuoi1 >> chuoi2;


    std::vector <char> cleanedChuoi1Va2 = {};
    std::vector <char> lower = {};
    std::vector <char> upper = {};
//? Kiểm tra các phần tử trong vector là letter;
    for (char i : chuoi1) {
        if (isalpha(i)) {
            cleanedChuoi1Va2.push_back(i);
        }
        else {
            continue;
        }
    }

    for (char i : chuoi2) {
        if (isalpha(i)) {
            cleanedChuoi1Va2.push_back(i);
        }
        else {
            continue;
        }
    }

//?Tách thành 2 vectors, 1 chỉ chữ HOA, 1 chỉ chữ !HOA
    for (char j : cleanedChuoi1Va2) {
        if (isupper(j)) {
            upper.push_back(j);
        } else {
            lower.push_back(j);
        }
    }

    std::sort(lower.rbegin(), lower.rend());
    std::sort(upper.rbegin(), upper.rend());

//?In RA theo thứ tự (reversedAlphabet và isUpper) (reversedAlphabet và islower)
    for (char i : upper) {
        std::cout << i;
    }

    for (char i : lower) {
        std::cout << i;
    }


    return 0;
}