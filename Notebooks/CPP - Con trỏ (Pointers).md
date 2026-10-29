---
tags: [cpp, brocode]
source: "BroCode - Pointers"
date: 2026-10-25
---

# Con trỏ (`pointers`)

#cpp/pointers #cpp/bo-nho #brocode

> [!note] Khái niệm
> **Con trỏ** là một biến dùng để lưu ==địa chỉ bộ nhớ của một biến khác==. Thay vì chứa giá trị (như `13`), nó chứa "địa chỉ nhà" của nơi đang chứa giá trị đó. Có những lúc làm việc trực tiếp với địa chỉ sẽ dễ hơn là làm việc với bản sao của giá trị.

Liên quan: [[CPP - Địa chỉ bộ nhớ (Memory Address)]] · [[CPP - Truyền tham chiếu (Pass by Reference)]]

## Hai toán tử cần nhớ

| Toán tử | Tên | Ý nghĩa |
|---|---|---|
| `&` | address-of | "Cho tôi **địa chỉ** của biến này" |
| `*` | dereference (giải tham chiếu) | "**Đi tới** địa chỉ này rồi lấy/sửa giá trị bên trong" |

Hai toán tử này là hai chiều ngược nhau: `&` đi từ giá trị ra địa chỉ, `*` đi từ địa chỉ về giá trị.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    std::string name = "Tuaan";
    int age = 13;
    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

    int *pAge = &age;                       // pAge giữ địa chỉ của age
    std::string *pName = &name;             // pName giữ địa chỉ của name
    std::string *pFreepizzas = freePizzas;  // tên mảng tự "decay" thành con trỏ phần tử đầu

    std::cout << *pName << "\n" << *pAge << "\n";   // Tuaan, 13
    std::cout << *pFreepizzas << "\n";              // pizza1

    return 0;
}
```

- `int *pAge = &age;` nghĩa là: `pAge` là ==con trỏ trỏ tới `int`==, và đang giữ địa chỉ của `age`.
- `*pAge` đi tới địa chỉ đó và lấy ra giá trị `13`. Đây **không** phải "decompile" hay dịch HEX gì cả, chỉ là đi theo địa chỉ rồi nhìn vào bên trong.
- `pAge` là một biến riêng, có địa chỉ riêng (`&pAge` khác `&age`). Nó giống tờ giấy ghi địa chỉ, không phải bản thân ngôi nhà.

> [!important] Dấu `*` có 2 nghĩa
> - `int *pAge` (lúc **khai báo**): "pAge là con trỏ trỏ tới int"
> - `*pAge` (lúc **sử dụng**): "đi tới địa chỉ đó, lấy/sửa giá trị bên trong"

## Đổi hướng trỏ vs sửa giá trị

Đây là chỗ dễ lẫn nhất:

```cpp
int age  = 13;
int age2 = 99;

int *pAge = &age;
pAge = &age2;     // ĐỔI tờ giấy: giờ pAge trỏ sang age2 (không in gì, không sửa giá trị nào)
*pAge = 50;       // SỬA đồ trong nhà đang được chỉ → age2 thành 50

// age  = 13 (không ai đụng tới)
// age2 = 50
```

| Câu lệnh | Tác dụng |
|---|---|
| `pAge = &age2;` | Đổi **con trỏ** trỏ đi đâu (giá trị `age`, `age2` giữ nguyên) |
| `*pAge = 50;` | Sửa **giá trị** tại nơi con trỏ **đang** trỏ tới |

> [!tip] Hình dung
> Biến = ngôi nhà có đồ đạc. Con trỏ = tờ giấy ghi địa chỉ nhà. `pAge = &age2` là xóa địa chỉ cũ, viết địa chỉ mới lên tờ giấy. `*pAge = 50` là cầm tờ giấy đi tới nhà đó rồi đổi đồ bên trong.

## Vậy dùng con trỏ để làm gì?

Với code ở trên thì chưa cần con trỏ. Nó có giá trị khi:

1. **Sửa biến gốc trong hàm** (truyền địa chỉ thay vì bản sao)
2. **Tránh copy dữ liệu lớn**
3. **Cấp phát bộ nhớ động** (`new` / `delete`)
4. **Cấu trúc dữ liệu**: linked list, cây, đồ thị (rất hay gặp khi học CP)
5. Mảng bên dưới thực chất là số học con trỏ

```cpp
void addOneCopy(int x)     { x = x + 1; }    // chỉ sửa bản sao
void addOnePointer(int *x) { *x = *x + 1; }  // sửa biến thật

int age = 13;
addOneCopy(age);       // age vẫn 13
addOnePointer(&age);   // age thành 14
```

> [!warning] Cạm bẫy thường gặp
> - `&freePizzas` **không** cùng kiểu với `freePizzas`: nó là "con trỏ tới cả mảng 5 string", không phải "con trỏ tới 1 string". Vì vậy dòng `std::string *p = &freePizzas;` bị lỗi, còn `= freePizzas;` thì đúng.
> - Nhầm `pAge = ...` với `*pAge = ...`: một cái đổi hướng trỏ, một cái sửa giá trị.
> - <span style="color:#e06c75">Con trỏ chưa được gán địa chỉ mà đem đi dereference là lỗi nguy hiểm</span>, nên luôn gán địa chỉ hợp lệ trước khi dùng `*`.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `&x` | Địa chỉ của `x` |
| `int *p = &x;` | `p` lưu địa chỉ của `x` |
| `*p` | Giá trị tại địa chỉ `p` đang giữ |
| `p = &y;` | Đổi `p` sang trỏ `y` |
| `*p = 5;` | Sửa giá trị tại nơi `p` đang trỏ |
| Tên mảng | Tự decay thành con trỏ tới phần tử đầu |

> [!question] Tự luyện
> 1. Viết hàm `void swapPtr(int *a, int *b)` hoán đổi giá trị 2 biến `int` bằng con trỏ, rồi so sánh với bản `&` ở [[CPP - Truyền tham chiếu (Pass by Reference)]].
> 2. In ra `pAge`, `&pAge`, `&age`, `*pAge` và giải thích vì sao 2 số nào giống nhau, 2 số nào khác nhau.
