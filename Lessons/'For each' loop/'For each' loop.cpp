#include <iostream>

int main() {
    //foreach loop = loop that eases the traversal over an
    //               iterable data set

    std::string students[] = {
        "Tuaan", 
        "Spongbob", 
        "gay", 
        "Sandy"
    };
    

    // for (int i = 0; i < sizeof(students)/sizeof(std::string); i++) {
    //     std::cout << students[i] << "\n";
    // }

    for (std::string student : students) {
        std::cout << student << "\n";
    }


    int grades[] = {
        65,
        72,
        81,
        93,
    };


    for (auto grade : grades) {
        std::cout << grade << "\n";
    } //auto give you an automatic data type  
    return 0;
}