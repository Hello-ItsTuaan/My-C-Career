---
tags: [cpp, brocode]
source: "BroCode - Arrays & sizeof()"
date: 2026-10-08
---

# Mảng và toán tử sizeof (`array` & `sizeof`)

#cpp/array #cpp/sizeof #cpp/co-ban #brocode

> [!note] Khái niệm
> **Mảng (array)** là một cấu trúc dữ liệu có thể chứa **nhiều giá trị cùng kiểu** trong một biến duy nhất. Mỗi giá trị được truy cập bằng một **chỉ số (index)** bắt đầu từ `0`. Hiểu đơn giản: giống như một biến nhưng "to" hơn, chứa được cả một dãy giá trị.
>
> **`sizeof()`** là toán tử cho biết kích thước (tính bằng **byte**) của một biến, kiểu dữ liệu, mảng, đối tượng, v.v.

---

## 1. Khai báo và truy cập phần tử mảng

```cpp
#include <iostream>

int main() {
    std::string car[] = {"Corvette", "Camry", "Honda"};

    std::cout << car[0] << "\n"; // Corvette
    std::cout << car[1] << "\n"; // Camry
    std::cout << car[2] << "\n"; // Honda

    car[0] = "Skibidi";          // đổi giá trị phần tử đầu tiên
    std::cout << car[0];         // Skibidi

    return 0;
}
```

- Khai báo mảng: `kiểu tên[] = {giá trị 1, giá trị 2, ...};` — compiler tự đếm số phần tử.
- Truy cập bằng `tên[index]`, và ==index luôn bắt đầu từ 0, không phải 1==.
- Gán lại giá trị cho từng phần tử: `car[0] = "Skibidi";`

Mảng có kích thước cố định, khai báo trước rồi gán sau cũng được:

```cpp
std::string car[1];   // mảng có đúng 1 phần tử
car[0] = "Camry";     // phần tử duy nhất nằm ở index 0
```

Mảng không chỉ chứa `string`, kiểu nào cũng được:

```cpp
double price[] = {5.00, 7.50, 9.99, 15.00};
std::cout << price[0];   // in ra 5 (không phải 5.00)
```

> [!tip] Vì sao in ra `5` chứ không phải `5.00`?
> `std::cout` mặc định **bỏ các số 0 thừa** ở phần thập phân. Muốn in đúng 2 chữ số thập phân thì dùng `std::fixed` và `std::setprecision(2)` (cần `#include <iomanip>`).

---

## 2. Toán tử `sizeof()`

```cpp
#include <iostream>

int main() {
    std::string name = "Nguyen Ba Minh Tuan";
    std::cout << sizeof(name) << " bytes\n";       // kích thước của object string, KHÔNG phải độ dài chữ

    double gpa = 2.5;
    std::cout << sizeof(double) << " bytes\n";     // 8 bytes (dùng được trực tiếp với tên kiểu)

    char grade = 'F';
    std::cout << sizeof(grade) << " bytes\n";      // 1 byte

    bool student = true;
    std::cout << sizeof(student) << " bytes\n";    // 1 byte

    char anotherGrade[] = {'A', 'B', 'C', 'D', 'F', 'E'};      // 6 phần tử x 1 byte = 6
    std::cout << sizeof(anotherGrade) << " bytes\n";           // 6 bytes
    std::cout << sizeof(anotherGrade)/sizeof(char) << " elements\n"; // 6 elements

    std::string students[] = {"Patrick", "Spongebob", "Squidward"};
    std::cout << sizeof(students)/sizeof(std::string) << " elements"; // 3 elements

    return 0;
}
```

| Biểu thức | Kết quả (thường gặp) | Ghi chú |
|---|---|---|
| `sizeof(double)` | 8 bytes | dùng với tên kiểu |
| `sizeof(char)` | 1 byte | luôn luôn là 1 theo chuẩn C++ |
| `sizeof(bool)` | 1 byte | phụ thuộc compiler nhưng thường là 1 |
| `sizeof(name)` (string) | ~32 bytes | ==không liên quan đến số ký tự trong chuỗi== |
| `sizeof(anotherGrade)` | 6 bytes | 6 phần tử `char` x 1 byte |

> [!important] Mẹo đếm số phần tử của mảng
> ==`sizeof(mảng) / sizeof(kiểu_phần_tử)` = số phần tử trong mảng==.
>
> Ví dụ: `sizeof(students) / sizeof(std::string)` → `3`. Đây là cách để vòng lặp tự biết mảng dài bao nhiêu mà không cần hard-code số.

> [!warning] Cạm bẫy: `sizeof(string)` không phải độ dài chuỗi
> `sizeof(name)` với `name = "Nguyen Ba Minh Tuan"` **không** ra 19. Nó trả về kích thước của chính object `std::string` (thường cố định ~32 bytes). Muốn lấy độ dài chữ thì dùng `name.length()` hoặc `name.size()` (xem [[CPP - std::string methods]]).

---

## 3. Duyệt mảng bằng vòng for (và lỗi vượt quá giới hạn)

```cpp
#include <iostream>

int main() {
    std::string students[] = {"Spongebob", "Patrick", "Squidward", "Tuaan"};

    for (int i = 0; i <= sizeof(students)/sizeof(std::string); i++) { // ❌ SAI
        std::cout << students[i] << "\n";
    }

    return 0;
}
```

Mảng này có **4 phần tử**, index hợp lệ là `0, 1, 2, 3`. Nhưng điều kiện `i <= 4` làm vòng lặp chạy thêm lần với `i = 4`, tức là đọc `students[4]` — một ô nhớ **không thuộc mảng**.

```cpp
// ✅ ĐÚNG: dùng < thay vì <=
for (int i = 0; i < sizeof(students)/sizeof(std::string); i++) {
    std::cout << students[i] << "\n";
}
```

> [!warning] Out-of-bounds = Undefined Behavior
> Truy cập index ngoài phạm vi mảng là <span style="color:#e06c75">hành vi không xác định (undefined behavior)</span>: có thể in ra rác, có thể crash, có thể "chạy bình thường" một cách đáng sợ. C++ **không** tự kiểm tra giúp bạn.
>
> Quy tắc nhớ: mảng có `n` phần tử thì index hợp lệ là `0` đến `n - 1`, nên điều kiện lặp là <span style="color:#98c379">`i < n`</span>, không phải `i <= n`.

> [!tip] Lưu ý thêm
> - `#include <string>` nên được thêm khi dùng `std::string` (nhiều compiler chạy được nhờ `<iostream>` kéo theo, nhưng không đảm bảo).
> - Mẹo `sizeof(mảng)/sizeof(kiểu)` chỉ đúng **ở nơi mảng được khai báo**. Khi truyền mảng vào hàm, nó biến thành con trỏ và `sizeof` sẽ ra kích thước con trỏ (8 bytes), không phải cả mảng.

---

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Mảng chứa nhiều giá trị **cùng kiểu** | `std::string car[] = {"A", "B", "C"};` |
| Index bắt đầu từ **0** | phần tử đầu là `car[0]`, phần tử cuối là `car[n-1]` |
| Gán lại phần tử | `car[0] = "Skibidi";` |
| `sizeof()` trả về **bytes** | dùng cho biến, kiểu, mảng, object |
| Số phần tử mảng | `sizeof(arr) / sizeof(arr[0])` hoặc `/ sizeof(kiểu)` |
| Vòng lặp duyệt mảng | dùng `i < n`, **không** dùng `i <= n` |
| `sizeof(string)` | kích thước object, không phải độ dài chữ |

Liên quan: [[CPP - Biến (Variables)]] · [[CPP - Kiểu dữ liệu cơ bản (Data Types)]] · [[CPP - Vòng lặp for (for loops)]]

> [!question] Tự luyện
> 1. Khai báo `int scores[] = {80, 95, 70, 100, 65};`, dùng `sizeof` để tính số phần tử, rồi dùng vòng `for` in tất cả điểm và **tính tổng**.
> 2. Cố tình đổi điều kiện thành `i <= n` rồi chạy thử, quan sát xem máy in ra gì ở lần cuối. Sau đó sửa lại cho đúng và giải thích vì sao lỗi xảy ra.
