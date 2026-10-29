---
tags: [cpp, brocode]
source: "BroCode - For Loops"
date: 2026-09-20
---

# Vòng lặp For (`for`)

#cpp/vong-lap #cpp/dieu-khien #brocode

> [!note] Khái niệm
> `for` gói gọn 3 phần trong 1 dòng: khởi tạo biến đếm, điều kiện lặp, và cách biến đếm thay đổi mỗi vòng — `for (khởi_tạo; điều_kiện; cập_nhật)`. Phù hợp nhất khi ==biết trước số lần lặp==.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    for (int i = 3; i >= 0; i--) {
        std::cout << i << "\n";
    }
    std::cout << "Happy new year!\n" << "\n";
    return 0;
}
```

`i` bắt đầu từ `3`, điều kiện `i >= 0` còn đúng thì còn chạy, mỗi vòng `i--` giảm 1 → in ra `3 2 1 0` rồi kết thúc, giống hệt đếm ngược năm mới 🎉. Code gốc của m còn để cả vòng `for` trong 1 cặp `{ }` riêng — đây chỉ là <span style="color:#d19a66">block phạm vi (scope block)</span> không bắt buộc, dùng để nhóm code cho dễ đọc, không ảnh hưởng gì tới cách vòng lặp chạy.

> [!tip] Mẹo
> 3 phần trong `for` đều có thể để trống (`for (;;)`), nhưng lúc đó m phải tự lo điều kiện dừng ở đâu đó bên trong, nếu không sẽ lặp vô hạn.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Cấu trúc | `for (khởi tạo; điều kiện; cập nhật)` |
| Dùng khi nào | Biết trước số lần lặp (đếm lên/xuống) |
| `i--` vs `i++` | Đếm ngược vs đếm xuôi, tuỳ hướng bài toán |

> [!question] Tự luyện
> 1. Sửa vòng lặp để đếm xuôi từ 0 đến 3 thay vì đếm ngược.
> 2. Viết `for` in ra tất cả số chẵn từ 1 đến 20.
