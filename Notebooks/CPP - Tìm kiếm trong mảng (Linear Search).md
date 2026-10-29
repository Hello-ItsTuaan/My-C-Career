---
tags: [cpp, brocode]
source: "BroCode - Search an array for an element"
date: 2026-10-11
---

# Tìm kiếm trong mảng (`Linear Search`)

#cpp/array #cpp/tim-kiem #brocode

> [!note] Khái niệm
> **Linear search (tìm kiếm tuyến tính)**: duyệt mảng từ phần tử đầu đến cuối, so sánh từng phần tử với giá trị cần tìm. Thấy thì ==trả về chỉ số (index)==, duyệt hết mà không thấy thì trả về `-1`. Đây là thuật toán tìm kiếm đơn giản nhất, không cần mảng đã sắp xếp.

Liên quan: [[CPP - Truyền mảng vào hàm (Passing Arrays to Functions)]] · [[CPP - Vòng lặp for (For Loops)]] · [[CPP - String methods]]

## Cú pháp & Ví dụ

```cpp
#include <bits/stdc++.h>

int searchArray(std::string array[], int size, std::string element);
std::string lower(std::string stringValue);

int main() {
    std::string foods[] = {"Pizza", "Hamburger", "Hotdog"};
    int size = sizeof(foods)/sizeof(foods[0]);   // số phần tử
    int index;
    std::string myFood;
    std::cout << "Enter element to search for:\n";
    std::cout << "> ";

    std::getline(std::cin, myFood);
    index = searchArray(foods, size, myFood);

    if (index != -1) {
        std::cout << myFood << " is at index " << index << "\n";
    } else {
        std::cout << "Cannot find " << myFood << " in the array!" << "\n";
    }

    return 0;
}

int searchArray(std::string array[], int size, std::string element) {
    for (int i = 0; i < size; i++) {
        if (lower(array[i]) == lower(element)) {
            return i;                // thấy rồi → trả về index ngay
        }
    }
    return -1; //-1 = NOT FOUND
}

std::string lower(std::string stringValue) {
    std::string lower;
    for (char i : stringValue) {
        lower += tolower(i);         // đổi từng ký tự sang chữ thường
    }
    return lower;
}
```

**Đi từng phần:**

- `sizeof(foods)/sizeof(foods[0])` → chia tổng byte cho kích thước **phần tử đầu tiên**. Cách này <span style="color:#98c379">dùng được cho mọi kiểu dữ liệu</span>, không cần nhớ kiểu (bài trước phải ghi `sizeof(double)`, đổi kiểu là phải sửa theo).
- `std::getline(std::cin, myFood)` → đọc cả dòng, nên nhập được chuỗi có dấu cách (vd `"Ice Cream"`). Xem [[CPP - Nhập xuất cơ bản (Input Output)]].
- `searchArray(...)` → vòng `for` duyệt từ `0` đến `size - 1`. Gặp phần tử khớp thì `return i` ==thoát khỏi hàm ngay lập tức==, không duyệt tiếp.
- `return -1;` → **giá trị canh gác (sentinel)** báo "không tìm thấy". Chọn `-1` vì không có index hợp lệ nào âm.
- `lower(...)` → hàm phụ biến chuỗi thành chữ thường, dùng `for (char i : stringValue)` (range-based for) để duyệt từng ký tự. Nhờ vậy `"pizza"`, `"PIZZA"`, `"Pizza"` đều tìm ra cùng một kết quả: <span style="color:#61afef">tìm kiếm không phân biệt hoa/thường</span>.

> [!important] Phải nhớ
> Luôn kiểm tra kết quả trả về `!= -1` trước khi dùng nó làm index. Dùng `foods[-1]` là truy cập ngoài mảng, <span style="color:#e06c75">hành vi không xác định (undefined behavior)</span>.

> [!tip] Mẹo
> - Truyền `std::string` theo giá trị sẽ **copy** cả chuỗi mỗi lần gọi. Với chuỗi dài hoặc mảng lớn, nên dùng `const std::string& element` để khỏi copy (sẽ học ở bài tham chiếu, xem [[CPP - Tham chiếu (References)]]).
> - Trong `lower()`, biến local tên `lower` trùng tên với hàm `lower`. Chạy vẫn được nhưng dễ rối, nên đặt `result` cho rõ.
> - `<bits/stdc++.h>` là header "gom tất cả" của GCC, rất tiện khi luyện thi lập trình (competitive programming) nhưng ==không chuẩn== và MSVC không có. Code thật nên `#include` đúng header cần dùng: `<iostream>`, `<string>`, `<cctype>`.

> [!warning] Cạm bẫy thường gặp
> `tolower(i)` với `char` có dấu hoặc ký tự ngoài ASCII (giá trị âm) có thể gây UB. Cách an toàn:
>
> ```cpp
> lower += tolower(static_cast<unsigned char>(i));
> ```
>
> Ngoài ra `==` trên `std::string` so sánh **phân biệt hoa/thường**, nên phải qua `lower()` trước khi so sánh.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Linear search | Duyệt lần lượt từng phần tử, độ phức tạp `O(n)` |
| Trả về index hoặc `-1` | `-1` = NOT FOUND (sentinel value) |
| `return` trong vòng lặp | Thoát hàm ngay khi tìm thấy |
| `sizeof(arr)/sizeof(arr[0])` | Đếm số phần tử, đúng với mọi kiểu |
| So sánh không phân biệt hoa/thường | Đưa cả hai vế về chữ thường bằng `lower()` |
| `std::getline` | Đọc cả dòng, có dấu cách |

> [!question] Tự luyện
> 1. Sửa chương trình để tìm **tất cả** vị trí xuất hiện nếu mảng có phần tử trùng (vd `{"Pizza", "Hotdog", "pizza"}`) và in ra mọi index.
> 2. Thử nhập `PIZZA`, `hotdog`, `Sushi` và dự đoán kết quả trước khi chạy. Sau đó thử bỏ `lower()` đi và xem điều gì đổi.
