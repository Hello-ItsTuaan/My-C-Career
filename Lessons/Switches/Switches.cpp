// #include <iostream>

// int main() {
//     //^Switches = alternative to using many "else if" statements
//     //^           compare one value against mathcing cases.

//     int month;
//     std::cout << "Please enter month (1-12): ";
//     std::cin >> month;

//     switch(month) {
//         case 1:
//             std::cout << "It's is January";
//             break; //what is the different between return and break (:v) it all ends the programme, is it like in Python? (return a value and break without return anything!?).
//         case 2:
//             std::cout << "It's is February";
//             break;
//         case 3:
//             std::cout << "It's is March";
//             break;
//         case 4:
//             std::cout << "It's is April";
//             break;
//         case 5:
//             std::cout << "It's is May";
//             break;
//         case 6:
//             std::cout << "It's is June";
//             break;
//         case 7:
//             std::cout << "It's is July";
//             break;
//         case 8:
//             std::cout << "It's is August";
//             break;
//         case 9:
//             std::cout << "It's is Septemper";
//             break;
//         case 10: 
//             std::cout << "It's October";
//             break;
//         case 11:
//             std::cout << "It's November";
//             break;
//         case 12:
//             std::cout << "It's December";
//             break;
//         default: //like else
//             std::cout << "Please only enter in only numbers (1-12)";
//     }   

//     return 0;
// }


#include <iostream>


int main() {
    char grade;
    std::cout << "Please enter you grade: ";
    std::cin >> grade;


    switch (grade) {
        case 'A':
            std::cout << "You did it great!";
            break;
       case 'B':
            std::cout << "It's nice to try again!";
            break;
        case 'C': 
            std::cout << "You stupid as f";
        default: 
            std::cout << "Please enter a valid grade!";
    }
}