---
tags: [cpp, brocode]
source: "BroCode - Logical Operators"
date: 2026-09-10
---

# Toán tử Logic (`&&`, `||`, `!`)

#cpp/toan-tu-logic #brocode #cpp/dieu-kien

> [!note] Khái niệm
> Toán tử logic dùng để **kết hợp hoặc đảo ngược** các điều kiện boolean (đúng/sai) lại với nhau, giúp `if` xử lý được những trường hợp phức tạp hơn "chỉ 1 điều kiện đơn".
> - `&&` (AND) → cả hai điều kiện phải **đúng** thì kết quả mới đúng.
> - `||` (OR) → chỉ cần **một trong hai** điều kiện đúng là đủ.
> - `!` (NOT) → đảo ngược trạng thái logic (true ↔ false).

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    int temp;
    bool sunny;

    std::cout << "Enter the temperature" << "\n";
    std::cin >> temp;

    if (temp > 0 && temp < 30) {
        std::cout << "The temperature is good" << "\n";
    } else if (temp <= 0 || temp >= 30) {
        std::cout << "The temperature is bad" << "\n";
    } else {
        std::cout << "Something ain't right!" << "\n";
    }

    if (!sunny) {
        std::cout << /* ... */;
    }
    return 0;
}
```

Ở nhánh đầu tiên, `temp > 0 && temp < 30` là ví dụ kinh điển của `&&`: ==cả hai vế đều phải đúng== thì mới in ra "The temperature is good" — tức là nhiệt độ phải nằm gọn trong khoảng (0, 30).

Nhánh `else if` dùng `||` để bắt phần **bù** của khoảng trên: chỉ cần `temp <= 0` **hoặc** `temp >= 30` là đủ để coi là xấu. Đây là <span style="color:#61afef">phần bù logic (logical complement)</span> của điều kiện `&&` phía trên — thực ra 2 điều kiện `(temp > 0 && temp < 30)` và `(temp <= 0 || temp >= 30)` phủ **toàn bộ** trường hợp có thể xảy ra, nên khối `else` cuối gần như không bao giờ chạy tới (dead code) trong đoạn này.

`!sunny` là toán tử `!`: nếu `sunny` đang là `false` thì `!sunny` sẽ thành `true`.

> [!tip] Mẹo
> Không cần viết `if (sunny == true)` hay `if (sunny == false)` — vì `sunny` vốn đã là kiểu `bool` rồi, viết thẳng `if (sunny)` hoặc `if (!sunny)` là đủ, gọn và đúng chuẩn C++.

> [!warning] Cạm bẫy thường gặp — 2 lỗi đang nằm sẵn trong code này 👀
> 1. **Biến `bool sunny` chưa được khởi tạo giá trị** trước khi dùng ở `if (!sunny)`. Với biến local không có giá trị mặc định, `sunny` đang chứa <span style="color:#e06c75">rác trong bộ nhớ (garbage value)</span> — chương trình vẫn có thể **biên dịch được** nhưng kết quả `true`/`false` là **không xác định (undefined behavior)**. Luôn nhớ `bool sunny = false;` (hoặc gán giá trị từ `cin`) trước khi kiểm tra nó.
> 2. Dòng `std::cout << ;` bị bỏ dở — thiếu toán hạng bên phải của `<<` và dấu `;`. Đoạn này sẽ **không biên dịch được** cho tới khi điền nốt nội dung muốn in ra, ví dụ `std::cout << "It's sunny!" << "\n";`.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `&&` (AND) | Đúng khi **cả hai** điều kiện đều đúng |
| `\|\|` (OR) | Đúng khi **ít nhất một** điều kiện đúng |
| `!` (NOT) | Đảo ngược giá trị boolean (true ↔ false) |
| Biến `bool` chưa gán giá trị | Chứa rác, dùng trong điều kiện là undefined behavior — luôn khởi tạo trước |

> [!question] Tự luyện
> 1. Sửa lại đoạn code trên: khởi tạo `sunny` bằng cách hỏi người dùng nhập `1` (có nắng) hoặc `0` (không nắng), rồi hoàn thiện dòng `cout` còn thiếu bên trong `if (!sunny)`.
> 2. Viết điều kiện kiểm tra "nhiệt độ đẹp trời" là: nhiệt độ nằm trong khoảng (20, 30) **và** trời đang có nắng (`sunny == true`) — dùng `&&` để kết hợp 2 điều kiện đó.
