---
tags: [cpp, brocode]
source: "BroCode - Dynamic Memory"
date: 2026-11-14
---

# Bộ nhớ động (`new` / `delete`)

#cpp/dynamic-memory #cpp/con-tro #brocode

> [!note] Khái niệm
> **Bộ nhớ động (dynamic memory)** là bộ nhớ được xin cấp phát **trong lúc chương trình đang chạy**, bằng toán tử `new`. Nó nằm ở vùng **heap** thay vì **stack**. Hữu ích khi ==không biết trước cần bao nhiêu bộ nhớ== (ví dụ số phần tử do người dùng nhập), nên chương trình linh hoạt hơn.

Liên quan: [[CPP - Con trỏ (Pointers)]], [[CPP - Con trỏ rỗng (nullptr)]], [[CPP - Địa chỉ bộ nhớ (Memory Address)]]

## Stack vs Heap

| | Stack | Heap |
|---|---|---|
| Ví dụ | `int x = 5;` | `new int` |
| Ai dọn? | Tự động khi hết phạm vi | <span style="color:#e06c75">Mình tự `delete`</span> |
| Kích thước | Phải biết lúc compile | Quyết định lúc chạy |

> [!example] Ví dụ ngăn tủ
> Heap giống **nhà gửi đồ có hàng ngàn ngăn tủ**. Con trỏ là **tờ giấy ghi số ngăn**, không phải đồ. `new` = thuê một ngăn và nhận tờ giấy. `delete` = trả ngăn lại.

## Cú pháp & Ví dụ

```cpp
#include <bits/stdc++.h>

int main() {
    // Phần 1: cấp phát 1 biến int
    int *pNum = NULL;
    pNum = new int;          // xin 1 ô int trên heap

    *pNum = 21;              // mở ô đó ra, bỏ 21 vào

    std::cout << "address: " << pNum << "\n";   // địa chỉ (tờ giấy)
    std::cout << "value: " << *pNum << "\n";    // giá trị (đồ trong ngăn)

    delete pNum;             // trả ô nhớ lại

    // Phần 2: cấp phát mảng với kích thước nhập lúc chạy
    char *pGrades = NULL;

    int size;
    std::cout << "How many grades to enter in?: ";
    std::cin >> size;
    pGrades = new char[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for (int i = 0; i < size; i++) {
        std::cout << pGrades[i] << " ";
    }

    delete[] pGrades;        // mảng thì dùng delete[]
    return 0;
}
```

- `pNum` là **địa chỉ**, còn `*pNum` là **giá trị nằm tại địa chỉ đó**.
- Không thể viết `char grades[size];` theo chuẩn C++ vì ==kích thước mảng thường phải biết lúc compile==. `new char[size]` giải quyết chuyện này.
- Sau `new char[size]`, dùng `pGrades[i]` y hệt mảng thường.

> [!important] Quy tắc vàng: xài thì phải trả
> Mỗi `new` phải có **đúng một** `delete` tương ứng, không thừa không thiếu.
> - `new` ↔ `delete`
> - `new[]` ↔ `delete[]`
>
> Dùng nhầm cặp là **undefined behavior**.

## Dấu `*` có 2 vai

```cpp
int *y = x;   // có KIỂU đứng trước → đang KHAI BÁO con trỏ
*y = 9;       // không có kiểu → "mở ngăn tủ" (dereference)
```

> [!tip] Mẹo phân biệt
> Nhìn xem có kiểu dữ liệu (`int`, `double`...) đứng ngay trước dấu `*` không. Có thì là khai báo con trỏ, không có thì là mở ngăn.

## Chép con trỏ vs chép giá trị

```cpp
int *x = new int;  *x = 4;
int *y = new int;  *y = 0;

*y = *x;   // chép GIÁ TRỊ → 2 ngăn riêng, y có thêm số 4
*x = 7;
std::cout << *y;   // 4 (y không đổi theo x)
```

```cpp
y = x;     // chép ĐỊA CHỈ → 2 con trỏ cùng trỏ 1 ngăn (chia sẻ)
```

> [!note] Tự rút ra
> `=` luôn chép thứ đang nằm trong biến bên phải sang biến bên trái. Với `int` đó là số, với con trỏ đó là **địa chỉ**. Muốn 2 biến "đồng bộ" nhau thì cho chúng ==chung một ô nhớ== (`y = x`), muốn tách riêng thì chép giá trị (`*y = *x`).

## Cạm bẫy thường gặp

> [!warning] Memory leak (rò rỉ bộ nhớ)
> Quên `delete`, hoặc ghi đè con trỏ khi ô cũ chưa trả: <span style="color:#e06c75">không còn ai biết địa chỉ để trả</span>. Chương trình nhỏ thì OS dọn khi thoát, nhưng server/game chạy lâu sẽ ăn hết RAM.

> [!warning] Double delete & dangling pointer
> `delete` hai lần cùng một ô, hoặc dùng con trỏ sau khi `delete`, đều là <span style="color:#e06c75">undefined behavior</span>. Có thể không crash ngay nên khó phát hiện.

```cpp
// SAI: ngăn của b (chứa 8) bị leak, rồi delete a/b trả cùng 1 ngăn 2 lần
int *a = new int; *a = 5;
int *b = new int; *b = 8;
b = a;
delete a;
delete b;    // double delete!
```

```cpp
// ĐÚNG: trả ngăn cũ trước khi đổi con trỏ
int *a = new int; *a = 5;
int *b = new int; *b = 8;
delete b;    // trả ngăn B trước
b = a;       // rồi mới đổi sang ngăn A
delete a;    // mỗi ngăn trả đúng 1 lần
a = nullptr;
b = nullptr;
```

> [!tip] Thói quen tốt
> Sau `delete`, gán `ptr = nullptr;` để đánh dấu "không trỏ đi đâu". C++ hiện đại nên dùng `nullptr` thay `NULL`, và trong CP thì ==`std::vector` thường là lựa chọn tốt hơn== (nó tự dọn bộ nhớ giùm).

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `new` | Xin bộ nhớ trên heap, trả về địa chỉ |
| `delete` / `delete[]` | Trả bộ nhớ, dùng đúng cặp với `new` / `new[]` |
| `pNum` vs `*pNum` | Địa chỉ vs giá trị tại địa chỉ |
| `y = x` | Hai con trỏ chung 1 ô nhớ |
| `*y = *x` | Chép giá trị sang ô riêng của y |
| Leak | Mất địa chỉ ô chưa trả |
| Double delete | Trả cùng 1 ô hai lần |

> [!question] Tự luyện
> 1. Viết chương trình **Sổ điểm thông minh**: nhập số học sinh `n`, dùng `new double[n]`, tính điểm trung bình, cao nhất, thấp nhất (nhớ lưu cả vị trí học sinh bằng `int`), rồi `delete[]`.
> 2. Viết chương trình nhập chi tiêu đến khi gặp `0`, tự mở rộng mảng: khi đầy thì tạo mảng mới gấp đôi, copy sang, `delete[]` mảng cũ. Sau đó thử tự viết class `MyVector`.
