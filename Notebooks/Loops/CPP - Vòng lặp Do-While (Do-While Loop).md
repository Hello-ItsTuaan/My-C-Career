---
tags: [cpp, brocode]
source: "BroCode - Do While Loops"
date: 2026-09-20
---

# Vòng lặp Do-While (`do...while`)

#cpp/vong-lap #cpp/dieu-khien #brocode

> [!note] Khái niệm
> `do-while` chạy code bên trong TRƯỚC, xong rồi mới kiểm tra điều kiện — nếu đúng thì lặp lại, sai thì dừng. Vì vậy code bên trong ==luôn chạy ít nhất 1 lần==, dù điều kiện có sai ngay từ đầu.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    int number;

    do {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while (number < 0);

    std::cout << "The number is: " << number;
    return 0;
}
```

Trong code gốc của m có đoạn bị comment lại dùng `while` thường — phải viết `cout`/`cin` 2 lần (1 lần trước vòng lặp để có giá trị ban đầu, 1 lần nữa bên trong vòng lặp) — đó là <span style="color:#e06c75">code trùng lặp không cần thiết</span>. `do-while` giải quyết vấn đề này bằng cách chạy code trước, kiểm tra sau, chỉ cần viết code 1 lần.

> [!tip] Mẹo
> Nhớ dấu `;` sau `while (điều kiện)` ở cuối `do-while` — lỗi cú pháp mới học rất hay quên (khác với `while` thường không cần dấu `;` sau `}`).

## So sánh nhanh

| | `while` | `do...while` |
|---|---|---|
| Kiểm tra điều kiện | Trước khi chạy | Sau khi chạy |
| Số lần chạy tối thiểu | 0 | 1 |
| Cú pháp kết thúc | `}` | `} while (...);` (có dấu `;`) |

Xem thêm: [[CPP - Vòng lặp While (While Loop)]]

> [!question] Tự luyện
> 1. Viết `do-while` yêu cầu nhập điểm từ 0-10, lặp lại nếu nhập ngoài khoảng đó.
> 2. Thử bỏ dấu `;` sau `while (number < 0)` xem trình biên dịch báo lỗi gì.
