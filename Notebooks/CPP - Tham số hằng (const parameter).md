---
tags: [cpp, brocode]
source: "BroCode - const parameters"
date: 2026-10-24
---

# Tham số hằng (`const` parameter)

#cpp/const #cpp/ham #brocode

> [!note] Khái niệm
> **const parameter** là tham số của hàm được khai báo với `const`, nghĩa là bên trong hàm tham số đó ==chỉ được đọc, không được sửa==. Nó làm code <span style="color:#61afef">an toàn hơn</span> (trình biên dịch chặn lỗi sửa nhầm) và <span style="color:#61afef">thể hiện rõ ý định</span> của người viết: "hàm này chỉ dùng giá trị, không thay đổi nó".

Liên quan: [[CPP - Hằng số (const)]], [[CPP - Truyền tham chiếu (Pass by Reference)]]

## Cú pháp & Ví dụ

```cpp
#include <iostream>
#include <string>

void printInfo(const std::string &name, const int &age);

int main() {
    std::string name = "Tuaan";
    int age = 13;

    printInfo(name, age);
    return 0;
}

void printInfo(const std::string &name, const int &age) {
    // name = " ";   // ❌ lỗi biên dịch: name là const
    // age = 0;      // ❌ lỗi biên dịch: age là const
    std::cout << name << "\n" << age;   // ✅ chỉ đọc thì được
}
```

- `const std::string &name` = tham chiếu (`&`) tới một `string` mà hàm ==không được phép sửa==.
- Nếu bỏ comment dòng `name = " ";` hoặc `age = 0;` thì compiler báo lỗi ngay, nhờ vậy bug bị chặn ở giai đoạn biên dịch, không đợi tới lúc chạy.
- Prototype (khai báo hàm phía trên `main`) và phần định nghĩa phía dưới phải ghi `const` giống nhau cho dễ đọc.

## Liên hệ với pass by value / pass by reference

Đây là chỗ hay bị lẫn. `const` và `&` là **hai việc khác nhau**:

| Thành phần | Nó làm gì |
|---|---|
| `&` (tham chiếu) | Không copy, hàm dùng ==chính biến gốc== trong `main` (nhanh, tiết kiệm bộ nhớ) |
| `const` | Cấm hàm sửa tham số (an toàn) |
| `const T &` | Cả hai: nhanh như pass by reference, nhưng không thể làm hỏng biến gốc |

```cpp
void f1(std::string s);              // pass by value: copy, sửa s không ảnh hưởng main
void f2(std::string &s);             // pass by reference: không copy, sửa s LÀM THAY ĐỔI biến gốc
void f3(const std::string &s);       // const reference: không copy, KHÔNG sửa được
```

> [!tip] Quy tắc thực tế
> - Kiểu **nhỏ** (`int`, `double`, `char`, `bool`): truyền theo giá trị là đủ, ví dụ `void f(int age)`.
> - Kiểu **lớn** (`std::string`, `vector`, struct): dùng `const T &` để tránh copy mà vẫn an toàn.
> - Trong code gốc, `const int &age` hơi thừa vì `int` copy rất rẻ. Dùng để luyện cú pháp thì ổn, nhưng thực tế người ta hay viết `int age`.

> [!warning] Cạm bẫy thường gặp
> - Quên `const` ở một trong hai chỗ (prototype hoặc định nghĩa) thì hai khai báo coi như <span style="color:#e06c75">khác nhau</span>, dễ ra lỗi linker.
> - `const &` cho phép truyền cả giá trị tạm như `printInfo("Tuaan", 13);`, còn `&` thường (không const) thì ==không== nhận được.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `const` parameter | Hàm chỉ đọc, không sửa được tham số |
| `const T &` | Không copy + không sửa được: tốt cho `string`, `vector` |
| Kiểu nhỏ như `int` | Truyền theo giá trị là đủ |
| Lỗi sửa nhầm | Bị phát hiện lúc biên dịch, không phải lúc chạy |

> [!question] Tự luyện
> 1. Bỏ comment dòng `age = 0;` rồi đọc thông báo lỗi của compiler. Nó nói gì?
> 2. Đổi hàm thành `void printInfo(std::string &name, int &age)` (bỏ `const`) rồi thử gọi `printInfo("Tuaan", 13);`. Vì sao lỗi, còn bản có `const` thì chạy được?
