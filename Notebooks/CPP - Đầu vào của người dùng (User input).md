---

## tags: [cpp, brocode] source: "BroCode - Basic I/O (cin, cout, getline)" date: 2026-09-01

# Nhập/Xuất dữ liệu cơ bản (`cin`, `cout`, `getline`)

#cpp/co-ban #cpp/io #brocode

> [!note] Khái niệm `std::cout` (Insertion Operator `<<`) dùng để **xuất** dữ liệu ra màn hình, còn `std::cin` (Extraction Operator `>>`) dùng để **nhập** dữ liệu từ bàn phím. Với chuỗi có khoảng trắng (ví dụ họ tên đầy đủ), `cin >>` không đủ dùng — phải dùng `std::getline()`.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    std::string name;
    int age;

    std::cout << "How old are you: \n";
    std::cin >> age;

    std::cout << "What is your full name: \n";
    std::getline(std::cin >> std::ws, name);

    std::cout << "You're " << age << "\n";
    std::cout << "Hello, " << name;

    return 0;
}
```

- `std::cin >> age` chỉ đọc đến khi gặp khoảng trắng/Enter — và quan trọng là nó **để lại ký tự `\n` (Enter)** trong buffer sau khi đọc xong.
- `std::getline(std::cin, name)` đọc **cả dòng** kể cả khoảng trắng — nhưng nếu buffer còn sót `\n` từ lần `cin >>` trước đó, `getline` sẽ đọc ngay dòng trống đó và "nuốt mất" input thật của bạn.
- ==`std::ws` là "manipulator" giúp bỏ qua (skip) hết khoảng trắng/newline còn sót trước khi `getline` bắt đầu đọc== — đây chính là lý do dòng code ghi `std::getline(std::cin >> std::ws, name)` thay vì `std::getline(std::cin, name)` trơn.
- Đúng như comment gốc của bạn: <span style="color:#d19a66">nếu phía trên có một lệnh `cin >>` khác</span> mà không dùng `std::ws`, `getline` phía sau sẽ bị lỗi (đọc ra chuỗi rỗng).

> [!tip] Mẹo Quy tắc nhỏ dễ nhớ: hễ **sau một `cin >> bienSo`** mà **có một `getline` ngay sau đó**, luôn chêm `std::ws` vào để dọn dẹp buffer trước. Nếu `getline` là input **đầu tiên** trong chương trình thì không cần, vì buffer chưa có gì để dọn.

> [!warning] Cạm bẫy thường gặp <span style="color:#e06c75">Quên `std::ws` là lỗi kinh điển của người mới</span> — chương trình chạy không báo lỗi gì cả, nhưng biến `name` sẽ tự nhiên rỗng toanh, khiến nhiều người ngồi debug cả buổi mà không hiểu tại sao 🫠. Đây không phải lỗi cú pháp, mà là lỗi **buffer còn sót ký tự**.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|`std::cout <<`|Xuất dữ liệu ra màn hình|
|`std::cin >>`|Nhập dữ liệu, dừng lại ở khoảng trắng, để sót `\n` trong buffer|
|`std::getline(std::cin, x)`|Đọc cả dòng kể cả khoảng trắng|
|`std::ws`|Dọn buffer, bỏ qua whitespace còn sót trước khi `getline` đọc|
|`std::getline(std::cin >> std::ws, x)`|Combo chuẩn khi `getline` đứng sau một `cin >>` khác|

> [!question] Tự luyện
> 
> 1. Thử xóa `std::ws` khỏi code gốc, chạy lại xem `name` bị gì — quan sát kỹ hiện tượng để nhớ lâu hơn.
> 2. Viết thêm một biến `std::string city` và hỏi "Bạn sống ở đâu?" ngay sau phần nhập `age`, dùng đúng combo `std::ws` — thử xem có tự tin làm đúng ngay lần đầu không 😏.