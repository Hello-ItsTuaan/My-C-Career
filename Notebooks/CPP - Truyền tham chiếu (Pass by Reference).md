---
tags: [cpp, brocode]
source: "BroCode - Pass by value vs pass by reference (swap)"
date: 2026-10-21
---

# Truyền tham chiếu (`pass by reference`)

#cpp/reference #cpp/ham #brocode

> [!note] Khái niệm
> Khi gọi hàm, C++ có 2 cách đưa biến vào hàm:
> - **Pass by value** (truyền giá trị): hàm nhận ==một bản sao== của biến. Sửa bản sao không ảnh hưởng biến gốc.
> - **Pass by reference** (truyền tham chiếu): hàm nhận ==chính biến gốc== (dưới một cái tên khác). Sửa trong hàm là sửa luôn biến ở nơi gọi.
>
> Dấu **`&`** đặt sau kiểu dữ liệu trong danh sách tham số (`std::string &x`) báo cho C++ biết đây là tham chiếu.

## Cú pháp & Ví dụ

```cpp
#include <iostream>
#include <string>

void swap(std::string &x, std::string &y);

int main() {
    std::string x = "Kool-Aid";
    std::string y = "Water";

    swap(x, y);
    std::cout << "X: " << x << "\n"; // Water
    std::cout << "Y: " << y << "\n"; // Kool-Aid

    return 0;
}

void swap(std::string &x, std::string &y) {
    std::string temp;

    temp = x;
    x = y;
    y = temp;
}
```

Giải thích:

- Hàm `swap` hoán đổi giá trị của 2 biến bằng một biến trung gian `temp` (giống đổ nước ra ly thứ ba để đổi chỗ 2 ly 🥤).
- Vì tham số là `&x`, `&y` nên ==`x`, `y` trong `swap` chính là `x`, `y` của `main`== (cùng một vùng nhớ, chỉ khác tên gọi).
- Bỏ dấu `&` đi (pass by value) thì `swap` chỉ hoán đổi 2 **bản sao**, `main` in ra vẫn là `Kool-Aid` và `Water` → không hoán đổi được gì.

| | Pass by value | Pass by reference |
|---|---|---|
| Khai báo | `void swap(std::string x, std::string y)` | `void swap(std::string &x, std::string &y)` |
| Hàm nhận | Bản sao | Chính biến gốc |
| Sửa trong hàm | <span style="color:#e06c75">Không ảnh hưởng biến gốc</span> | <span style="color:#98c379">Thay đổi biến gốc</span> |
| Địa chỉ `&x` trong hàm so với `main` | Khác nhau | Giống nhau |
| Chi phí | Phải copy (string dài thì tốn) | Không copy |

> [!important] Ghi chú của mình (đã chỉnh lại cho đúng)
> Nhận xét "`x` và `y` trong `main` và trong `swap` có địa chỉ bộ nhớ khác nhau nên sửa trong `swap` không ảnh hưởng `main`" **đúng với bản pass by value**.
> Với **pass by reference** thì ngược lại: địa chỉ ==giống nhau==, nên sửa trong `swap` là sửa luôn `main`. Có thể tự kiểm chứng bằng cách in `&x` ở cả 2 hàm (xem lại [[CPP - Địa chỉ bộ nhớ (Memory Address)]]).

> [!tip] Mẹo
> - Thường dùng pass by reference khi cần **sửa biến gốc** (như `swap`) hoặc khi truyền **object lớn** (string, vector) để tránh copy tốn thời gian.
> - Tên `swap` trùng với `std::swap` có sẵn. Nếu sau này dùng `using namespace std;` thì dễ bị lỗi mơ hồ (*ambiguous*), nên đặt tên khác như `mySwap`. Còn thực tế khi code thi thì cứ gọi `std::swap(a, b)` có sẵn.

> [!warning] Cạm bẫy thường gặp
> Quên dấu `&` trong **cả khai báo (prototype) lẫn định nghĩa hàm** là lỗi rất hay gặp: code vẫn chạy, không báo lỗi, nhưng kết quả không đổi vì hàm âm thầm làm việc trên bản sao. Hai chỗ này phải <span style="color:#e06c75">khớp nhau</span>.

## Liên hệ

Tham chiếu và [[CPP - Con trỏ (Pointers)]] cùng giải quyết bài toán "làm việc với biến gốc", nhưng tham chiếu gọn hơn vì không cần dùng `*` hay `&` khi gọi. Cũng liên quan tới [[CPP - Hàm (Functions)]] và [[CPP - Mảng (Arrays)]] (mảng truyền vào hàm thực chất cũng không bị copy).

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `type &name` trong tham số | Khai báo tham chiếu: hàm dùng chính biến gốc |
| Không có `&` | Pass by value: hàm chỉ sửa bản sao |
| `swap(x, y)` | Gọi bình thường, không cần viết `&` ở chỗ gọi |
| Prototype và định nghĩa | Phải cùng có `&` |
| Cần `temp` | Để không mất giá trị khi đổi chỗ 2 biến |

> [!question] Tự luyện
> 1. Bỏ dấu `&` ở cả prototype và định nghĩa của `swap`, chạy lại và quan sát kết quả. Rồi thêm `std::cout << &x << "\n";` vào cả `main` và `swap` để so sánh địa chỉ ở 2 phiên bản.
> 2. Viết hàm `void addOne(int &n)` làm `n` tăng thêm 1, gọi từ `main` rồi in `n` ra. Sau đó thử viết bản không có `&` xem khác gì.
