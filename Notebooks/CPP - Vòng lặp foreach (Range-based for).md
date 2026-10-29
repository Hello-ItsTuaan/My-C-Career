---
tags: [cpp, brocode]
source: "BroCode - foreach loop"
date: 2026-10-10
---

# Vòng lặp foreach (`range-based for`)

#cpp/foreach #cpp/vong-lap #brocode

> [!note] Khái niệm
> **foreach loop** là kiểu vòng lặp giúp việc <span style="color:#61afef">duyệt qua từng phần tử</span> của một tập dữ liệu (mảng, vector, string...) trở nên dễ dàng hơn. Thay vì tự quản lý chỉ số `i`, ta chỉ cần nói: "với mỗi phần tử trong tập này, hãy làm X". Trong C++ chính thức gọi là ==range-based for loop==.
>
> Liên quan: [[CPP - Vòng lặp for (for loop)]], [[CPP - Mảng (Arrays)]]

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {

    std::string students[] = {"Tuaan", "Spongbob", "gay", "Sandy"};

    // Cách cũ: for loop thường, phải tự tính số phần tử
    // for (int i = 0; i < sizeof(students)/sizeof(std::string); i++) {
    //     std::cout << students[i] << "\n";
    // }

    // Cách mới: foreach
    for (std::string student : students) {
        std::cout << student << "\n";
    }

    int grades[] = {65, 72, 81, 93};

    for (auto grade : grades) {
        std::cout << grade << "\n";
    } // auto = tự động suy ra kiểu dữ liệu

    return 0;
}
```

**Cú pháp tổng quát:**

```cpp
for (kiểu_dữ_liệu tên_biến : tập_dữ_liệu) {
    // tên_biến lần lượt là từng phần tử
}
```

- Dấu `:` đọc là "trong" (in) → `student : students` = "mỗi `student` trong `students`".
- ==Không cần chỉ số `i`, không cần `sizeof(...)/sizeof(...)`== → code ngắn và khó sai hơn nhiều.
- Biến `student` ở mỗi vòng lặp là <span style="color:#98c379">một bản sao</span> của phần tử hiện tại (xem phần cạm bẫy bên dưới).

### So sánh for thường và foreach

| | `for` thường | `foreach` |
|---|---|---|
| Cần chỉ số `i` | Có | Không |
| Tính số phần tử | Tự tính (`sizeof`/`sizeof`) | Tự động |
| Truy cập phần tử | `students[i]` | `student` |
| Khi cần biết vị trí | Dễ | Phải tự đếm thêm |
| Độ dài code | Dài hơn | Ngắn gọn |

> [!tip] `auto` — để compiler tự đoán kiểu
> `auto grade : grades` thì compiler tự hiểu `grade` là `int`. Đỡ phải gõ kiểu dài như `std::string`, và đặc biệt hữu ích khi kiểu dữ liệu rất dài hoặc phức tạp. Với mảng `std::string`, viết `auto student : students` cũng chạy y hệt.

> [!tip] Muốn nhanh hơn với string: dùng tham chiếu `const &`
> ```cpp
> for (const std::string& student : students) {
>     std::cout << student << "\n";
> }
> ```
> Cách này ==không copy== từng chuỗi (tiết kiệm bộ nhớ/thời gian với dữ liệu lớn) và `const` đảm bảo không lỡ sửa nhầm. Với `int` thì copy rất rẻ nên `auto grade` là đủ.

> [!warning] Cạm bẫy thường gặp
> 1. **Thiếu `#include <string>`**: code gốc dùng `std::string` nhưng chỉ include `<iostream>`. Thường vẫn chạy vì `<iostream>` kéo theo `<string>` ở nhiều compiler, nhưng <span style="color:#e06c75">không được đảm bảo</span>, nên include đầy đủ cho chắc.
> 2. **Muốn sửa phần tử gốc thì phải dùng tham chiếu `&`**: `for (auto grade : grades) grade++;` chỉ sửa bản sao, mảng gốc không đổi. Phải viết `for (auto& grade : grades)`.
> 3. **Không dùng được với con trỏ/mảng đã "decay"**: nếu truyền mảng vào hàm (dạng `int* arr`), foreach sẽ lỗi vì mất thông tin kích thước. Lúc đó dùng `std::vector` hoặc `std::array`.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| foreach là gì | Duyệt từng phần tử của tập dữ liệu mà không cần chỉ số |
| Cú pháp | `for (kiểu tên : tập_dữ_liệu) { ... }` |
| `auto` | Compiler tự suy ra kiểu dữ liệu của biến |
| Mặc định | Biến lặp là **bản sao** của phần tử |
| Sửa phần tử gốc | Dùng `auto&` |
| Chỉ đọc, tránh copy | Dùng `const auto&` / `const std::string&` |

> [!question] Tự luyện
> 1. Viết foreach để **tính tổng** mảng `grades`, rồi in ra điểm trung bình (nhớ ép kiểu sang `double`!).
> 2. Dùng `for (auto& grade : grades)` để **cộng thêm 5 điểm** cho mỗi người, rồi in lại mảng. Thử bỏ dấu `&` xem kết quả khác thế nào.
