---
tags: [cpp, brocode]
source: "BroCode - Functions"
date: 2026-09-27
---

# Hàm (`function`)

#cpp/functions #cpp/co-ban #brocode

> [!note] Khái niệm
> Hàm là một khối code có thể **tái sử dụng** (reusable), được đặt tên riêng để làm một việc cụ thể. Thay vì viết đi viết lại cùng một đoạn code, mình gói nó vào một hàm rồi gọi tên hàm đó bao nhiêu lần cũng được.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

// Khai báo hàm (function declaration / prototype)
// Phải khai báo trước nếu hàm được định nghĩa ở dưới main()
void Happy_Birthday(std::string name, int age);

int main() {
    std::string name = "Tuaan";
    int age = 13;
    Happy_Birthday(name, age);
    Happy_Birthday(name, age);
    Happy_Birthday(name, age);

    return 0;
}

// Định nghĩa hàm (function definition) — nội dung thực sự của hàm
void Happy_Birthday(std::string name, int age) {
    std::cout << "Happy Birthday to " << name << "\n";
    std::cout << "Happy Birthday to you " << name << "\n";
    std::cout << "Happy Birthday dear you " << name << "\n";
    std::cout << "Happy Birthday to you " << name << "\n";
    std::cout << "You're now " << age << "\n\n";
}
```

Có 2 phần tách biệt:
- **Khai báo (declaration/prototype)** — dòng `void Happy_Birthday(std::string name, int age);` ở trên `main()`. Đây chỉ là "lời hứa" cho trình biên dịch biết hàm này tồn tại, tên gì, nhận tham số gì, trả về gì.
- **Định nghĩa (definition)** — phần thân hàm nằm dưới `main()`, chứa code thực sự sẽ chạy.

==Nếu định nghĩa hàm nằm phía dưới `main()`, bắt buộc phải khai báo (declare) nó trước `main()`==, nếu không trình biên dịch sẽ báo lỗi vì chưa "biết" tới hàm đó khi đọc tới dòng gọi hàm trong `main()`.

Hàm ở đây nhận 2 tham số (`parameters`): `name` kiểu <span style="color:#61afef">std::string</span> và `age` kiểu <span style="color:#61afef">int</span>. Khi gọi `Happy_Birthday(name, age)`, giá trị thật được truyền vào gọi là **đối số (arguments)**.

`void` nghĩa là hàm này không trả về giá trị gì cả — nó chỉ in ra màn hình rồi kết thúc.

> [!tip] Mẹo
> Nếu chỉ dùng một hàm và định nghĩa nó **trước** `main()`, thì không cần khai báo (declare) riêng nữa — declaration chỉ thật sự cần khi định nghĩa nằm sau nơi gọi hàm.

> [!warning] Cạm bẫy thường gặp
> Quên dấu `;` ở cuối dòng khai báo hàm (prototype) là lỗi cực kỳ phổ biến — declaration là một câu lệnh (statement) nên luôn cần `;`, còn phần định nghĩa thì không (vì nó kết thúc bằng khối `{ }`).

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Function declaration | Khai báo tên, tham số, kiểu trả về — kết thúc bằng `;` |
| Function definition | Thân hàm thực sự — nằm trong `{ }` |
| Parameters vs Arguments | Parameters là biến khai báo trong hàm; Arguments là giá trị thật truyền vào lúc gọi |
| `void` | Hàm không trả về giá trị nào |
| Tái sử dụng | Gọi hàm nhiều lần thay vì copy-paste code |

> [!question] Tự luyện
> 1. Thêm tham số thứ 3 kiểu `std::string` tên `message` để in thêm một lời chúc tùy chỉnh sau dòng "You're now...".
> 2. Viết thêm một hàm `int` có tên `Calculate_Birth_Year(int currentYear, int age)` trả về năm sinh dựa trên tuổi, rồi gọi nó trong `main()`.
