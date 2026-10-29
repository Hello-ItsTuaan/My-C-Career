#include <iostream>

int main() {
    //? Const use for varibles that that you do not want to change (a static value)
    //! You should Const as often as possible (only if you know that varible is static - not going to be change!)
    const double PI = 3.14159;  
    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    std::cout << "Pi is " << PI << '\n' << "Your screen resolution is " << WIDTH << "x" << HEIGHT << std::endl;

    return 0;
};

