#include <iostream>

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // ! Check độ dài và tình trạng rỗng của chuỗi
    if (name.empty()) {
        std::cout << "You didn't enter your name\n";
    } else if (name.length() > 12) {
        std::cout << "Your name can't be longer than 12 characters!\n";
    } else {
        std::cout << "Welcome " << name << "\n";
    }

    // | Tạo username từ tên + domain gmail |
    name.append("@gmail.com");
    std::cout << "Your username is " << name << "\n";

    std::cout << name.at(0) << "\n";               // ký tự tại index 0
    std::cout << name.insert(0, "#") << "\n";      // chèn "#" ở đầu chuỗi
    std::cout << name.find(' ') << "\n";            // tìm index của khoảng trắng

    // WARNING: erase(pos, count) -> xoá "count" ký tự, KHÔNG phải index kết thúc
    std::cout << name.erase(1, 2) << "\n";

    name.clear(); // xoá sạch toàn bộ chuỗi

    return 0;
}