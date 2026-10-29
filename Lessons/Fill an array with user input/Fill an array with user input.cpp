#include <bits/stdc++.h>

int main() {
    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);
    std::string temp;
    
    for (int i = 0; i < size; i++) {
        std::cout << "Enter a food you like #" << i+1 << " or 'q' to quit: ";
        std::getline (std::cin >> std::ws, temp);

        if (temp == "q") {
            break;
        } else {
            foods[i] = temp;
        }
    }  

    for (int i = 0; i < size && !foods[i].empty(); i++) {
        std::cout << i+1 << ". " << foods[i] << "\n";
    }

    return 0;
}