---
tags: [cpp, brocode]
source: "BroCode - Memory addresses"
date: 2026-10-21
---

# Địa chỉ bộ nhớ (`memory address` & `&`)

#cpp/memory-address #cpp/con-tro #brocode

> [!note] Khái niệm
> **Địa chỉ bộ nhớ (memory address)** là ==vị trí trong bộ nhớ (RAM) nơi dữ liệu của một biến được lưu==. Mỗi biến bạn khai báo đều "ở" tại một địa chỉ riêng, giống như mỗi căn nhà có một số nhà.
> Muốn xem địa chỉ đó, dùng toán tử **`&`** (*address-of operator* — toán tử lấy địa chỉ) đặt ngay trước tên biến.

## Cú pháp & Ví dụ

```cpp
#include <bits/stdc++.h>

int main() {
    // memory address = a location in memory where data is stored
    // a memory address can be accessed with & (address-of operator)

    std::string name = "Tuaan";
    int age = 13;
    bool student = true;

    std::cout << &name << "\n";
    std::cout << &age << "\n";
    std::cout << &student << "\n";

    return 0;
}
```

**Kết quả mẫu** (mỗi máy, mỗi lần chạy sẽ ra số khác nhau):

```text
0x7ffd5c1a3b40
0x7ffd5c1a3b3c
0x7ffd5c1a3b3b
```

Giải thích:

- `name`, `age`, `student` là 3 biến khác nhau → ==mỗi biến có một địa chỉ riêng==.
- `&name` **không** in ra chữ `"Tuaan"` mà in ra *nơi* chữ đó đang nằm. Muốn lấy giá trị thì dùng `name`, muốn lấy địa chỉ thì dùng `&name`.
- Địa chỉ được in dưới dạng <span style="color:#61afef">hệ thập lục phân (hex)</span>, bắt đầu bằng `0x`.
- Các địa chỉ nằm gần nhau vì biến cục bộ được xếp liền kề trong vùng nhớ **stack**; khoảng cách giữa chúng phụ thuộc vào kích thước từng kiểu (`std::string` lớn hơn `int`, `int` lớn hơn `bool`).

| Biểu thức | Nghĩa | Ví dụ kết quả |
|---|---|---|
| `age` | giá trị lưu trong biến | `13` |
| `&age` | địa chỉ nơi biến `age` nằm | `0x7ffd5c1a3b3c` |

> [!example] Hình dung
> RAM giống một dãy tủ khóa đánh số. Biến `age` là món đồ nằm trong một ngăn tủ. `age` cho bạn món đồ, còn `&age` cho bạn **số của ngăn tủ**.

> [!tip] Mẹo
> Địa chỉ in ra sẽ <span style="color:#d19a66">thay đổi giữa các lần chạy</span> (hệ điều hành xếp bộ nhớ ngẫu nhiên vì lý do bảo mật), nên đừng cố "đoán" hay ghi nhớ một địa chỉ cụ thể. Điều cần nhớ là *khái niệm*, không phải con số.

> [!warning] Cạm bẫy thường gặp
> Với biến kiểu `char`, `std::cout << &c` **không** in ra địa chỉ mà `cout` sẽ coi nó là chuỗi C-style và in ký tự rác cho tới khi gặp `'\0'`. Muốn in địa chỉ của `char`, ép kiểu: `std::cout << static_cast<void*>(&c);`

## Liên hệ bài sau

Địa chỉ bộ nhớ là nền móng của [[CPP - Con trỏ (Pointers)]]: một con trỏ chính là một biến dùng để ==lưu địa chỉ của biến khác==. Cũng liên quan tới [[CPP - Biến (Variables)]] và [[CPP - Kiểu dữ liệu cơ bản (Data Types)]] (kiểu quyết định biến chiếm bao nhiêu byte).

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Memory address | Vị trí trong bộ nhớ nơi dữ liệu được lưu |
| `&` (address-of) | Đặt trước tên biến để lấy địa chỉ của biến đó |
| Mỗi biến một địa chỉ | `&name`, `&age`, `&student` đều khác nhau |
| Dạng hiển thị | Số hex, bắt đầu bằng `0x` |
| Không cố định | Địa chỉ đổi mỗi lần chạy chương trình |

> [!question] Tự luyện
> 1. Khai báo thêm `double gpa = 3.5;` và `char grade = 'A';`, in `&gpa`. Với `grade`, thử in `&grade` rồi thử `static_cast<void*>(&grade)` — kết quả khác nhau thế nào?
> 2. Chạy chương trình 3 lần liên tiếp. Địa chỉ có giống nhau không? Thử in `sizeof(name)`, `sizeof(age)`, `sizeof(student)` rồi so với hiệu giữa các địa chỉ.
