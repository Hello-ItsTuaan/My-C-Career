#include <iostream>

//parenthesis
//multiplication & division
//addition and subtraction


int main() {
    int students = 20; //(output 6)
    // double students = 20; (output: 6.666667)
        //todo: PLUS
    //? students = students + 1;
    // students ++1;
    //! students += 1;

        //todo: MINUS
    //? students = students - 1;
    // students -= 1;
    //! students -- 1;

        //todo: MULTIPLIER
    //? students = students * 2
    //! students *= 2;

        //todo: DIVIDE
    //? students = students / 2;
    students /= 3;

    int remainder = students % 3;
    std::cout << "Remainder: " << remainder << std::endl;
    std::cout << students << std::endl;
    return 0;

}