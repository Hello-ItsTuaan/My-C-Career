
int main() {
    // const paremeter = parameter that is effectively read-only
    //                  code is more secure and conveys intent
    //                     useful for references and pointers
    std::string name = "Tuaan";
    int age = 13;

    printInfo(name, age);
    return 0;
}


void printInfo(std::string name, int age) {
    std::cout << name << "\n" << age;
}