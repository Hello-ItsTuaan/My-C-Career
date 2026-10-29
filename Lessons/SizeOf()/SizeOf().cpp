#include <iostream>

int main() {
    //sizeOf() = determines the size in bytes of a:
    //           varibles, data, type, class, objects, etc;

    std::string name = "Nguyen Ba Minh Tuan";
    std::cout << sizeof(name) << " bytes\n";

    double gpa = 2.5;
    std::cout << sizeof(double) << " bytes\n";

    char grade = 'F';
    std::cout << sizeof(grade) << " bytes\n";

    bool student = true;
    std::cout << sizeof(student) << " bytes\n";

    char anotherGrade[] = {'A', 'B', 'C', 'D', 'F', 'E'}; // 1 + 1 + 1 + 1 + 1 = 6
    std::cout << sizeof(anotherGrade) << " bytes\n";
    std::cout << sizeof(anotherGrade)/sizeof(char) << " elements\n"; //useful tricks!

    std::string students[] = {"Patrick", "Spongebob", "Squidward"};
    std::cout << sizeof(students)/sizeof(std::string) << " elements";

    return 0;
}