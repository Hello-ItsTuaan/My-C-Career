#include <iostream>


void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);


int main() {
    bakePizza("nigga", "gay");
    return 0;
}


void bakePizza() {
    std::cout << "Here is your pizza!" << std::endl;
}

void bakePizza(std::string topping1) {
    std::cout << "Here is your " << topping1 << " pizza!" << std::endl;
}

void bakePizza(std::string topping1, std::string topping2) {
    std::cout << "Here is your " << topping1 << " and your " << topping2 << " pizza!" << std::endl;
}