---
tags: [cpp, brocode]
source: "BroCode - nullptr"
date: 2026-11-10
---

# Con trỏ rỗng (`nullptr`)

#cpp/nullptr #cpp/con-tro #brocode

> [!note] Khái niệm
> `NULL` là một giá trị đặc biệt có nghĩa là "chưa có giá trị". Khi một con trỏ đang giữ giá trị null, nó ==không trỏ vào đâu cả== (gọi là *null pointer*). Từ khoá `nullptr` là *null pointer literal* — cách viết chuẩn của C++ hiện đại để biểu diễn điều đó. Xem lại nền tảng ở [[CPP - Con trỏ (Pointers)]] và [[CPP - Địa chỉ bộ nhớ (Memory Address)]].

## Cú pháp & Ví dụ

```cpp
#include <bits/stdc++.h>

int main() {
    // int *pointer;               // ❌ con trỏ "rác" - chưa khởi tạo, trỏ lung tung
    int *pointer = nullptr;        // ✅ khởi tạo rỗng, an toàn
    int x = 123;

    pointer = &x;                  // gán địa chỉ của x cho con trỏ

    if (pointer == nullptr) {
        std::cout << "Address was not assigned." << "\n";
    } else {
        std::cout << "Address was assigned." << "\n";
        std::cout << *pointer;     // an toàn: ở nhánh này pointer chắc chắn có địa chỉ
    }
    return 0;
}
```

- `int *pointer = nullptr;` → con trỏ **có giá trị xác định** (rỗng) thay vì chứa địa chỉ rác ngẫu nhiên.
- `*` là <span style="color:#61afef">toán tử giải tham chiếu (dereference)</span>: lấy ra giá trị nằm tại địa chỉ mà con trỏ đang giữ.
- `if (pointer == nullptr)` là cách ==kiểm tra xem địa chỉ đã được gán thành công chưa== trước khi dùng con trỏ.

> [!tip] Mẹo
> Luôn khởi tạo con trỏ bằng `nullptr` nếu chưa có địa chỉ để gán, và kiểm tra `!= nullptr` trước khi dereference. Ở C++ hiện đại dùng `nullptr` thay cho `NULL` hoặc `0`.

> [!warning] Cạm bẫy thường gặp
> Code gốc có một chỗ ==rất dễ gây hiểu nhầm==: dòng `std::cout << *pointer;` nằm **bên trong nhánh `pointer == nullptr`**. Nhánh đó nghĩa là "con trỏ **chưa** có địa chỉ" mà lại đi dereference nó → <span style="color:#e06c75">undefined behavior</span> (thường là crash / segfault).
> Chương trình chạy không lỗi chỉ vì `pointer = &x;` đã chạy trước nên nhánh đó **không bao giờ được thực thi**. Nếu xoá dòng gán đi, code sẽ nổ ngay.

```cpp
// ❌ SAI: dereference ngay trong nhánh con trỏ rỗng
if (pointer == nullptr) {
    std::cout << *pointer;   // UB!
}

// ✅ ĐÚNG: chỉ dereference khi chắc chắn không rỗng
if (pointer == nullptr) {
    std::cout << "Address was not assigned.\n";
} else {
    std::cout << *pointer;
}
```

> [!important] Phải nhớ
> Không bao giờ dereference `nullptr`, và cũng không dereference con trỏ đang trỏ vào vùng nhớ đã được giải phóng (free memory). Cả hai đều gây <span style="color:#e06c75">undefined behavior</span>.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `nullptr` | Từ khoá biểu diễn con trỏ rỗng (null pointer literal) |
| `NULL` | Giá trị "không có gì"; con trỏ giữ null thì không trỏ vào đâu |
| Khởi tạo `= nullptr` | Tránh con trỏ chứa địa chỉ rác |
| `if (p == nullptr)` | Kiểm tra địa chỉ đã được gán chưa |
| `*p` khi `p == nullptr` | ❌ Undefined behavior |

> [!question] Tự luyện
> 1. Xoá dòng `pointer = &x;` rồi chạy lại code gốc (bản có `*pointer` trong nhánh nullptr) — quan sát chuyện gì xảy ra, rồi sửa lại cho đúng.
> 2. Viết hàm `void printValue(int *p)` in ra giá trị `*p` nếu `p != nullptr`, ngược lại in "Null pointer!". Gọi thử với `nullptr` và với `&x`.
