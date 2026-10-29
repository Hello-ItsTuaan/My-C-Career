---
tags: [cpp, brocode]
source: "BroCode - Passing arrays to functions"
date: 2026-10-11
---

# Truyền mảng vào hàm (`double prices[]`)

#cpp/array #cpp/ham #brocode

> [!note] Khái niệm
> Khi muốn một hàm xử lý cả một mảng (tính tổng, tìm max, in ra...), ta truyền mảng vào hàm qua tham số dạng `double prices[]`. Điểm mấu chốt: ==hàm không biết mảng dài bao nhiêu==, nên ta phải truyền thêm `size` như một tham số riêng.

Liên quan: [[CPP - Mảng (Arrays)]] · [[CPP - Hàm (Functions)]] · [[CPP - Vòng lặp for (For Loops)]]

## Cú pháp & Ví dụ

```cpp
#include <iostream>

double getTotal(double prices[], int size);   // function prototype

int main() {
    double prices[] = {49.99, 15.5, 75, 9.99};

    int size = sizeof(prices)/sizeof(double); // 32 bytes / 8 bytes = 4 phần tử

    double total = getTotal(prices, size);

    std::cout << "$" << total;                // $150.48
    return 0;
}

double getTotal(double prices[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += prices[i];
    }
    return total;
}
```

**Đi từng phần:**

- `double getTotal(double prices[], int size);` → khai báo **prototype** phía trên `main()` để `main` gọi được hàm định nghĩa ở dưới. Tham số đầu là mảng, tham số thứ hai là số phần tử.
- `sizeof(prices)/sizeof(double)` → `sizeof(prices)` là tổng số byte của cả mảng, chia cho số byte của 1 phần tử ⇒ ra <span style="color:#61afef">số phần tử của mảng</span>. Ở đây `double` = 8 byte, mảng 32 byte ⇒ `size = 4`.
- `getTotal(prices, size)` → truyền **tên mảng** (không có `[]`) và `size`.
- Trong hàm, dùng `for` chạy từ `0` đến `size - 1` để cộng dồn vào `total`, rồi `return total`.

> [!important] Phải nhớ
> Tính `size` ==ở nơi mảng được khai báo (ở đây là `main`)== rồi truyền vào hàm. Đừng cố tính `size` bên trong hàm.

> [!warning] Cạm bẫy thường gặp
> Bên trong `getTotal`, `prices` thực chất chỉ là một **con trỏ** tới phần tử đầu tiên (hiện tượng *array decay*). Nên nếu viết `sizeof(prices)/sizeof(double)` *trong hàm*, kết quả là <span style="color:#e06c75">kích thước con trỏ (thường 8 byte) chia 8 = 1</span>, chứ không phải 4!
>
> ```cpp
> // ❌ SAI - trong hàm, prices chỉ là con trỏ
> double getTotal(double prices[]) {
>     int size = sizeof(prices)/sizeof(double); // = 1 (sai bét)
> }
>
> // ✅ ĐÚNG - nhận size từ bên ngoài
> double getTotal(double prices[], int size) { ... }
> ```

> [!tip] Mẹo
> - `double prices[]` và `double* prices` là **một**: cả hai đều nhận con trỏ. Xem thêm [[CPP - Con trỏ (Pointers)]].
> - Vì hàm làm việc trực tiếp trên mảng gốc (không copy), nếu sửa `prices[i]` trong hàm thì mảng ngoài `main` cũng đổi theo. Hàm chỉ đọc dữ liệu thì nên viết `const double prices[]` cho an toàn.
> - Thêm `std::endl` hoặc `"\n"` sau `std::cout << "$" << total;` nếu muốn xuống dòng cho gọn terminal.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Mảng truyền vào hàm | Dạng `type name[]`, truyền bằng tên mảng |
| Hàm không biết độ dài mảng | Mảng "decay" thành con trỏ khi vào hàm |
| Tính `size` | `sizeof(array)/sizeof(type)` — làm ở nơi khai báo mảng |
| Truyền `size` | Là một tham số riêng của hàm |
| Sửa mảng trong hàm | Ảnh hưởng tới mảng gốc ở ngoài |
| Prototype | Khai báo hàm trước `main()` nếu định nghĩa nằm sau |

> [!question] Tự luyện
> 1. Viết thêm hàm `double getAverage(double prices[], int size)` trả về giá trung bình, rồi in ra trong `main`.
> 2. Thử cố tình viết `sizeof(prices)/sizeof(double)` bên trong `getTotal` và in ra xem được số mấy. Giải thích vì sao khác `4`.
