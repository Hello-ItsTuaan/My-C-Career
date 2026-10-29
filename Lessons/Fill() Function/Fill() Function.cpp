#include <iostream>

int main() {    
    // fill() = fill a range of elements with a specified value;
    //          fill(begin, end, value);

    std::string foods[10] = {"pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza"};
    const int size = 100;
    std::string anotherFoods[size] = {};
    
//    fill(anotherFoods, anotherFoods + 100, "pizza");

    // fill(anotherFoods, anotherFoods + (size), "pizza");

    

    fill(anotherFoods, anotherFoods + (size/3), "pizza");
    fill(anotherFoods + size/3, anotherFoods + size, "Hamburger");  
    fill(anotherFoods + (size/3*2), anotherFoods + size, "Hotdog");  

    for (std::string food : anotherFoods) {
        std::cout << food << "\n";
    }

    return 0;
}