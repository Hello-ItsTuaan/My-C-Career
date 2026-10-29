#include <bits/stdc++.h>

int main() {    
    int soBan;
    std::cin >> soBan;
    
    std::vector <int> banDuocTang = {};
    std::vector <int> banDuocTangLonDan = {};

    for(int i = 0; i < soBan; i++) {
        int temp;
        std::cin >> temp;
        banDuocTang.push_back(temp);
    }

    banDuocTangLonDan = banDuocTang;
    std::sort (banDuocTangLonDan.begin(), banDuocTangLonDan.end());

    // for (int i = 0; i < banDuocTangLonDan.size(); i++) {
    //     std::cout << banDuocTangLonDan[i] << " ";
    // }

    for (int i = 0; i < banDuocTang.size(); i++) {
        int index = 0;
        for (int j = 0; j < banDuocTang.size(); j++) {
            index++;
            if (banDuocTang[j] == banDuocTangLonDan[i]) {
                std::cout << index << " ";
            }
        }
    }

    return 0;
}

/*

Input:
4
2 3 4 1

1 2 3 4

Output:
4 1 2 3

*/