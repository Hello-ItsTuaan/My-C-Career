---
tags: [cpp, brocode]
source: "BroCode - While Loops"
date: 2026-09-20
---

# Vòng lặp While (`while`)

#cpp/vong-lap #cpp/dieu-khien #brocode

> [!note] Khái niệm
> `while` là vòng lặp kiểm tra điều kiện TRƯỚC, nếu đúng thì mới chạy code bên trong, chạy xong lại quay lên kiểm tra tiếp — cứ thế lặp đến khi điều kiện sai thì dừng. Vì kiểm tra trước nên có khả năng ==không chạy lần nào== nếu điều kiện sai ngay từ đầu.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    std::string name;
    while (name.empty()) {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name << "\n";
    return 0;
}
```

Biến `name` bắt đầu rỗng (`""`), nên `name.empty()` trả về `true` → vòng lặp chạy, hỏi người dùng nhập tên. Nếu người dùng bấm Enter mà không gõ gì, `name` vẫn rỗng → lặp lại hỏi tiếp. Chỉ khi nhập được chuỗi khác rỗng thì `name.empty()` mới thành `false` và thoát vòng lặp. Đây là kiểu dùng `while` rất phổ biến: <span style="color:#61afef">validate input cho tới khi hợp lệ</span>.

> [!tip] Mẹo
> Dùng `while` khi m không chắc code bên trong có cần chạy hay không. Nếu chắc chắn phải chạy ít nhất 1 lần thì nên nghĩ tới `do-while` (xem [[CPP - Vòng lặp Do-While (Do-While Loop)]]).

> [!warning] Cạm bẫy thường gặp
> Quên cập nhật biến điều kiện bên trong vòng lặp → vòng lặp chạy vô hạn (infinite loop). Ở ví dụ trên biến `name` được "cập nhật" tự nhiên qua `getline`, nhưng nếu logic phức tạp hơn, m phải tự đảm bảo điều kiện có ngày thay đổi.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Kiểm tra điều kiện | TRƯỚC khi chạy code bên trong |
| Có thể chạy 0 lần | Nếu điều kiện sai ngay từ đầu |
| Dùng khi nào | Không biết trước số lần lặp, cần validate input |

> [!question] Tự luyện
> 1. Sửa code để giới hạn số lần nhập tối đa 3 lần, nếu vẫn rỗng thì tự động gán `name = "Guest"`.
> 2. Viết 1 vòng `while` yêu cầu nhập số nguyên dương, lặp lại nếu nhập số âm hoặc bằng 0.
