#include <iostream>

namespace first {
    int x = 0;

}

namespace second {
    int x = 1;

}

//// ? Cách 1:
// int main() {
//     int x = 2;
//     std::cout << x << std::endl; // I am the global x!
//     std::cout << first::x << std::endl; // I am the first x! :: means scope resolution operator.

//     return 0;

// }


////? Cách 2:

// int main() {
//     using namespace first;
//     std::cout << x << std::endl;
//     return 0;

// }


//// TIPS and TRICKS by BroCode:


int main() {
    // using namespace std; not really safe on big project
    using std::cout; // use this
    using std::string; // or this instead. (safer!)

    string name = "Tuan"; 
    cout << "Hello" << std::endl;
    return 0;

}

// TODO: Theory:
// Namespace = provides a solution for preventing name conflicts in large projects. 
//Each entity needs a unique name. 
//A namespace allows for identically named entities as long as the namespace are different.