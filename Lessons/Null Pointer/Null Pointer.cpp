#include <bits/stdc++.h>

int main() {
    // NULL value = a special value that means something has no value.
    //              When a pointer is holding a null value
    //              that pointer is not pointing at anything (null pointer);

    // nullprt = keyword represents a null pointer literal

    // nullprts are helpful when determining if an address
    // was successfully assigned to a pointer

    //! When using pointers, be careful that your code isn't dereferencing nullprt, or poiting to FREE MEMORY
    // this will cause undefined behavior 

    // int *pointer; 
    int *pointer = nullptr;
    int x = 123;

    pointer = &x;
    //btw note that * is a deference operator (it takes out the value of the & address)

    if (pointer == nullptr) {
        std::cout << "Address was not assigned." << "\n";
        std::cout << *pointer;
    } else {
        std::cout << "Address was assigned." << "\n";
        std::cout << *pointer;
    }
    return 0;
}