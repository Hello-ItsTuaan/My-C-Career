#include <bits/stdc++.h>
 
int searchArray(std::string array[], int size, std::string element);
std::string lower(std::string stringValue);

int main() {
    std::string foods[] = {"Pizza", "Hamburger", "Hotdog"};
    int size = sizeof(foods)/sizeof(foods[0]);
    int index;
    std::string myFood;
    std::cout << "Enter element to search for:\n";
    std::cout << "> ";

    std::getline(std::cin, myFood);
    index = searchArray(foods, size, myFood);

    if (index != -1) {
        std::cout<< "'" << myFood << "' is at index " << index << "\n";
    } else {
        std::cout << "Cannot find '" << myFood << "' in the array!" << "\n";
    }

    std::cout << "\nThe array: ";
    for (int i = 0; i < size; i++) {
        std::cout << foods[i] << ", ";
    }

    return 0;
}

int searchArray(std::string array[], int size, std::string element) {
    for (int i = 0; i < size; i++) {
        if (lower(array[i]) == lower(element)) {
            return i;
        }
    }
    return -1; //-1 = NOT FOUND
}

std::string lower(std::string stringValue) {
    std::string lower;
    for (char i : stringValue) {
        lower += tolower(i);
    }
    return lower;
}