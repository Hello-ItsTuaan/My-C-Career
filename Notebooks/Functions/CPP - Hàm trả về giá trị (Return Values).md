---
tags: [cpp, brocode]
source: "BroCode - Functions (Return Values)"
date: 2026-09-27
---

# Hàm trả về giá trị (`return`)

#cpp/functions #cpp/return-values #brocode

> [!note] Khái niệm
> Không phải hàm nào cũng chỉ để in ra màn hình — hàm còn có thể **tính toán rồi trả kết quả về** cho nơi đã gọi nó, thông qua từ khóa `return`. Khi đó hàm phải khai báo kiểu dữ liệu trả về (thay vì `void`) đúng với kiểu của giá trị mà nó `return`.

## Cú pháp & Ví dụ

```cpp
#include <iostream>
#include <cmath>

double square(double number) {
    return pow(number, 2);
}

int main() {
    int number;
    std::cin >> number;
    double result = square(number);
    std::cout << result;

    return 0;
}
```

`double square(double number)` — chữ `double` đầu tiên chính là **kiểu dữ liệu trả về**, khai báo rằng hàm này khi chạy xong sẽ đưa lại một giá trị kiểu `double`. ==Kiểu trả về phải khớp với kiểu của biểu thức sau `return`==, ở đây `pow(number, 2)` cũng trả về `double` nên hợp lệ.

`pow(number, 2)` là hàm có sẵn từ thư viện <span style="color:#61afef">&lt;cmath&gt;</span>, dùng để tính lũy thừa: `pow(a, b)` = a mũ b. Muốn dùng `pow` bắt buộc phải `#include <cmath>` ở đầu file.

Ở `main()`, dòng `double result = square(number);` — giá trị `square` trả về được **gán** vào biến `result` để dùng tiếp, khác hẳn với hàm `void` ở bài trước chỉ chạy xong rồi thôi, không đưa gì lại cả.

Lưu ý nhỏ: `number` được khai báo là `int` nhưng hàm `square` lại nhận tham số kiểu `double` — C++ tự động **ép kiểu ngầm** (implicit conversion) từ `int` sang `double` khi truyền vào, nên code vẫn chạy bình thường không báo lỗi.

> [!tip] Mẹo
> Nếu hàm có `return` một giá trị, kiểu trả về của hàm **không được để là `void`** — phải ghi đúng kiểu dữ liệu (int, double, std::string,...) thì trình biên dịch mới cho biên dịch qua.

> [!warning] Cạm bẫy thường gặp
> Quên viết `return` trong hàm có kiểu trả về khác `void` sẽ khiến chương trình có hành vi không xác định (undefined behavior) — trình biên dịch đôi khi chỉ cảnh báo (warning) chứ không báo lỗi (error), nên rất dễ bị bỏ sót.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Kiểu trả về | Kiểu dữ liệu hàm sẽ `return` (int, double, std::string,...) thay vì `void` |
| `return` | Đưa giá trị tính toán được về nơi gọi hàm, đồng thời kết thúc hàm ngay lập tức |
| `pow(a, b)` | Hàm tính lũy thừa từ thư viện `<cmath>` |
| Ép kiểu ngầm | C++ tự chuyển `int` → `double` khi truyền tham số nếu cần, không cần ép tay |

> [!question] Tự luyện
> 1. Viết hàm `double cube(double number)` trả về lập phương của số, dùng `pow(number, 3)`.
> 2. Viết hàm `bool isEven(int number)` trả về `true`/`false` xem số có chia hết cho 2 hay không, rồi in kết quả ra bằng `std::boolalpha`.
