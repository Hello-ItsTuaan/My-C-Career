---
tags: [cpp, brocode]
source: "BroCode - Truyền mảng vào hàm (pass array to function) + sizeof"
date: 2026-10-10
---

# Truyền mảng vào hàm (`double prices[]`, `sizeof`)

#cpp/mang #cpp/ham #brocode

> [!note] Khái niệm
> Khi muốn một hàm xử lý **cả một mảng** (ví dụ: cộng tổng giá tiền), ta truyền mảng vào hàm qua tham số dạng `double prices[]`. Nhưng hàm ==không tự biết mảng có bao nhiêu phần tử== — nên ta phải tính `size` ở nơi khai báo mảng (bằng `sizeof`) rồi <span style="color:#61afef">truyền thêm `size` làm tham số thứ hai</span>.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

double getTotal(double prices[], int size);   // prototype (khai báo trước)

int main() {
    double prices[] = {49.99, 15.5, 75, 9.99};

    int size = sizeof(prices)/sizeof(double); // 32 byte / 8 byte = 4 phần tử

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

**Đi qua từng phần:**

1. `double getTotal(double prices[], int size);` — *function prototype*: báo cho compiler biết hàm tồn tại trước khi `main()` gọi nó (định nghĩa thật nằm bên dưới `main`).
2. `double prices[] = {...};` — không ghi số phần tử trong `[]`, compiler tự đếm theo danh sách khởi tạo (ở đây là 4).
3. `sizeof(prices)/sizeof(double)` — ==tổng số byte của mảng chia cho số byte của một phần tử== = số phần tử. Với `double` (8 byte) × 4 phần tử = 32 byte → 32 / 8 = **4**.
4. `getTotal(prices, size)` — truyền tên mảng (không có `[]`) và kích thước vào hàm.
5. Trong hàm: biến `total` khởi tạo `0`, vòng `for` chạy từ `0` đến `size - 1`, cộng dồn từng `prices[i]`, cuối cùng `return total`.

| Biểu thức | Giá trị | Ý nghĩa |
|---|---|---|
| `sizeof(prices)` | 32 | tổng byte của cả mảng (4 × 8) |
| `sizeof(double)` | 8 | số byte của 1 phần tử |
| `size` | 4 | số phần tử trong mảng |
| `total` | 150.48 | 49.99 + 15.5 + 75 + 9.99 |

> [!tip] Mẹo
> Đặt tên tham số trùng tên biến ngoài `main` (`prices`, `size`, `total`) hoàn toàn hợp lệ — mỗi hàm có **scope riêng** (xem lại [[CPP - Biến cục bộ và toàn cục (Scope)]]). Hai `total` ở `main` và trong `getTotal` là hai biến khác nhau.

> [!warning] Cạm bẫy thường gặp
> Mảng truyền vào hàm ==bị "rơi" thành con trỏ (array decay)==: `double prices[]` trong tham số thực chất là `double* prices`. Hậu quả:
> - <span style="color:#e06c75">Không thể dùng `sizeof(prices)` bên trong `getTotal`</span> để tính số phần tử — nó chỉ trả về kích thước của **con trỏ** (thường 8 byte), không phải cả mảng.
> - Vì thế phải tính `size` ở `main` (nơi mảng còn "nguyên vẹn") rồi truyền vào.
> - Hàm nhận **địa chỉ** của mảng gốc, nên nếu sửa `prices[i]` trong hàm thì mảng ở `main` cũng bị đổi theo (xem [[CPP - Con trỏ (Pointers)]]).

```cpp
// ❌ SAI — sizeof trong hàm chỉ ra kích thước con trỏ
double getTotal(double prices[]) {
    int size = sizeof(prices)/sizeof(double); // = 8/8 = 1 (sai!)
    ...
}

// ✅ ĐÚNG — truyền size từ nơi mảng được khai báo
double getTotal(double prices[], int size) {
    for (int i = 0; i < size; i++) { ... }
}
```

> [!example] Ghi chú thêm
> Cách `sizeof(arr)/sizeof(arr[0])` còn an toàn hơn vì không phụ thuộc kiểu dữ liệu (đổi `double` thành `int` không cần sửa dòng này). Sau này với `std::vector` thì chỉ cần `.size()` — không cần mẹo `sizeof` nữa.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Truyền mảng vào hàm | Dùng `kiểu tên[]`, khi gọi chỉ ghi **tên mảng** (không có `[]`) |
| Tính số phần tử | `sizeof(mảng) / sizeof(kiểu)` — chỉ đúng ở nơi mảng được khai báo |
| Phải truyền thêm `size` | Hàm không tự biết độ dài mảng (array decay) |
| Function prototype | Khai báo hàm trước `main` để gọi được hàm định nghĩa phía dưới |
| Mảng truyền vào là tham chiếu ngầm | Sửa phần tử trong hàm → mảng gốc đổi theo |

> [!question] Tự luyện
> 1. Viết thêm hàm `double getAverage(double prices[], int size)` trả về **giá trung bình** của mảng `prices`.
> 2. Viết hàm `double getMax(double prices[], int size)` tìm **giá cao nhất** (gợi ý: khởi tạo `max = prices[0]`, rồi so sánh trong vòng `for`). Thử thêm 1 phần tử vào mảng và kiểm tra `size` có tự cập nhật đúng không.
