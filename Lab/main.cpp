#include <fstream>
#include <iostream>
#include <string>
int main() {
  int n;

  // Nhập số lượng phần tử n từ người dùng
  std::cout << "Nhap vao so max n de hardcode: ";
  if (!(std::cin >> n) || n < 1) {
    std::cerr << "Vui long nhap mot so nguyen duong hop le!" << std::endl;
    return 1;
  }

  // Mở file OddOrEven.py để ghi dữ liệu
  std::ofstream outFile("OddOrEven.py");

  if (!outFile) {
    std::cerr << "Khong the tao file OddOrEven.py!" << std::endl;
    return 1;
  }

  // Ghi đoạn mã nhận input từ người dùng trong Python
  outFile << "# File duoc tu dong sinh ra boi chuong trinh C++ (Phong cach "
             "Hardcode)\n";
  outFile << "try:\n";
  outFile << "    num = int(input(\"Nhap vao mot so kiem tra: \"))\n";

  // Bắt đầu chuỗi hardcode if-elif bằng C++
  for (int i = 1; i <= n; ++i) {
    std::string status = (i % 2 == 0) ? "Chan (Even)" : "Le (Odd)";

    if (i == 1) {
      outFile << "    if num == 1:\n";
    } else {
      outFile << "    elif num == " << i << ":\n";
    }
    outFile << "        print(f\"{num} la so " << status << "\")\n";
  }

  // Xử lý các trường hợp nằm ngoài phạm vi hardcode từ 1 đến n
  outFile << "    else:\n";
  outFile << "        print(\"So nay nam ngoai pham vi hardcode (1 den " << n
          << ")!\")\n";

  // Bẫy lỗi nếu người dùng nhập chữ thay vì số trong Python
  outFile << "except ValueError:\n";
  outFile << "    print(\"Vui long nhap mot so nguyen hop le!\")\n";

  // Đóng file
  outFile.close();

  std::cout << "Da tao file 'OddOrEven.py' hardcode thanh cong tu 1 den " << n
            << "!" << std::endl;

  return 0;
}
