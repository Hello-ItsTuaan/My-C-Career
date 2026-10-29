---
tags: [cpp, brocode]
source: "BroCode - Ternary Operator"
date: 2026-09-08
---

# Toán tử ba ngôi (`Ternary Operator`)

#cpp/ternary #cpp/dieu-khien #brocode

> [!note] Khái niệm
> Toán tử ba ngôi (`? :`) là cách viết **rút gọn** cho một câu lệnh `if / else` đơn giản chỉ có đúng 1 điều kiện và 2 kết quả. Gọi là "ba ngôi" vì nó cần **ba phần**: điều kiện, kết quả khi đúng, kết quả khi sai — tất cả gói gọn trong 1 dòng.

## Cú pháp & Ví dụ

```cpp
condition ? expression1 : expression2;
// true  -> chạy expression1
// false -> chạy expression2
```

```cpp
#include <iostream>

int main() {
    bool hungry = true;

    std::cout << (hungry ? "You're hungry" : "You're full");
    return 0;
}
```

So sánh với cách viết `if/else` truyền thống:

```cpp
// Cách dài (if/else)
if (hungry) {
    std::cout << "You're hungry";
} else {
    std::cout << "You're full";
}

// Cách ngắn (ternary) — CÙNG kết quả
std::cout << (hungry ? "You're hungry" : "You're full");
```

==Toán tử ba ngôi chỉ nên dùng khi cả 2 nhánh đều ngắn gọn== (in ra 1 câu, gán 1 giá trị...) — nếu logic phức tạp hơn (nhiều dòng, nhiều điều kiện lồng nhau), quay lại dùng `if/else` bình thường cho dễ đọc.

Một vài ví dụ khác từ bài học (dạng comment, cùng cấu trúc):

```cpp
int grade = 50;
grade >= 60 ? std::cout << "You passed!" : std::cout << "You failed!";

int number = 9;
number % 2 == 1 ? std::cout << "ODD" : std::cout << "EVEN";
```

Ở ví dụ `hungry`, code đặt cả biểu thức ternary trong dấu ngoặc `(...)` trước khi đưa vào `std::cout <<` — đây là cách viết **an toàn và rõ ràng hơn** so với viết `std::cout << hungry ? "..." : "...";` không ngoặc, vì <span style="color:#61afef">toán tử `<<` có độ ưu tiên cao hơn `?:`</span>, nên nếu thiếu ngoặc, trình biên dịch có thể hiểu sai thứ tự thực thi.

> [!tip] Mẹo
> Ternary hợp nhất khi **gán giá trị cho biến** dựa trên điều kiện, ví dụ: `int max = (a > b) ? a : b;` — ngắn hơn nhiều so với viết cả khối `if/else` chỉ để gán 1 biến.

> [!warning] Cạm bẫy thường gặp
> Quên bọc ngoặc `()` quanh biểu thức ternary khi dùng chung với `std::cout <<` hoặc các toán tử khác có độ ưu tiên cao hơn — dễ gây lỗi biên dịch hoặc kết quả không như mong đợi. Luôn bọc ngoặc cho chắc: `std::cout << (dieu_kien ? a : b);`

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Cú pháp | `condition ? expression1 : expression2;` |
| Thay thế cho | `if/else` đơn giản, chỉ 1 điều kiện — 2 kết quả |
| Khi nào dùng | Logic ngắn gọn (1 dòng); không nên dùng cho logic phức tạp |
| Với `std::cout` | Luôn bọc ngoặc `()` quanh biểu thức ternary |
| "Ba ngôi" nghĩa là | 3 phần: điều kiện, kết quả đúng, kết quả sai |

> [!question] Tự luyện
> 1. Viết lại bài kiểm tra chẵn/lẻ (`number % 2 == 1 ? "ODD" : "EVEN"`) nhưng gán kết quả vào một biến `std::string result` thay vì in trực tiếp, rồi in `result` ra sau.
> 2. Viết một ternary kiểm tra điểm số (`grade`) và gán vào biến `char letter` giá trị `'P'` (Pass) nếu `grade >= 60`, ngược lại `'F'` (Fail) — thử in `letter` ra xem có đúng không.
