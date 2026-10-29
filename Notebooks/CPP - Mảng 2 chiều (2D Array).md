---
tags: [cpp, brocode]
source: "BroCode - 2D arrays (mảng 2 chiều)"
date: 2026-10-17
---

# Mảng 2 chiều (`2D array`)

#cpp/array #cpp/2d-array #brocode

> [!note] Khái niệm
> Mảng 2 chiều là **"mảng của các mảng"** — giống một cái bảng có **hàng (row)** và **cột (column)**. Muốn lấy một phần tử, ta cần *2 chỉ số*: `arr[hàng][cột]`. Nó hay dùng để lưu bảng dữ liệu, bàn cờ, ma trận, bản đồ lưới... Nền tảng 1 chiều xem ở [[CPP - Mảng string và vòng lặp nhập liệu]].

## Cú pháp & Ví dụ

```cpp
#include <iostream>
//a.k.a 2d array
int main() {
    std::string car[][3] = {{"Mustard", "Escape", "F-150"},
                           {"Corvette", "Equinox", "Silverado"},
                           {"Challenger", "Durango", "Ram 1500"}};

    std::cout << car[0][1] << " ";

    int rows = sizeof(car)/sizeof(car[0]);
    int columns = sizeof(car[0])/sizeof(car[0][0]);


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << car[i][j] << ", ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

### 1. Khai báo & khởi tạo

Hình dung `car` như bảng 3 hàng × 3 cột:

| | cột 0 | cột 1 | cột 2 |
|---|---|---|---|
| **hàng 0** | Mustard | Escape | F-150 |
| **hàng 1** | Corvette | Equinox | Silverado |
| **hàng 2** | Challenger | Durango | Ram 1500 |

- Mỗi cặp `{...}` bên trong là **một hàng**; cặp `{...}` bên ngoài bao tất cả các hàng.
- ==Khi khởi tạo ngay lúc khai báo, có thể bỏ trống số hàng `[]`, nhưng bắt buộc phải ghi số cột `[3]`.== Trình biên dịch tự đếm số hàng từ danh sách giá trị.
- Truy cập phần tử: `car[0][1]` → hàng 0, cột 1 → `"Escape"`. Chỉ số luôn bắt đầu từ `0`.

### 2. Tính số hàng và số cột bằng `sizeof`

```cpp
int rows    = sizeof(car)/sizeof(car[0]);          // toàn bộ mảng / 1 hàng
int columns = sizeof(car[0])/sizeof(car[0][0]);    // 1 hàng / 1 phần tử
```

- `sizeof(car)` = kích thước **cả bảng**; `sizeof(car[0])` = kích thước **một hàng** → chia ra **số hàng** (`3`).
- `sizeof(car[0])` = một hàng; `sizeof(car[0][0])` = **một phần tử** → chia ra **số cột** (`3`).
- Cùng ý tưởng với mảng 1 chiều, chỉ là chia thêm một tầng. Lưu ý: cách này <span style="color:#d19a66">chỉ đúng khi mảng còn ở cùng scope khai báo</span> (truyền vào hàm là mất, xem [[CPP - Truyền mảng vào hàm]]).

### 3. Duyệt bằng 2 vòng `for` lồng nhau

```cpp
for (int i = 0; i < rows; i++) {        // vòng ngoài: đi từng hàng
    for (int j = 0; j < columns; j++) { // vòng trong: đi từng cột của hàng đó
        std::cout << car[i][j] << ", ";
    }
    std::cout << "\n";                  // hết 1 hàng thì xuống dòng
}
```

- Vòng **ngoài** chọn hàng `i`, vòng **trong** chạy hết các cột `j` của hàng đó rồi mới quay lại tăng `i`.
- `"\n"` đặt ở vòng ngoài (sau vòng trong) nên mỗi hàng nằm trên một dòng, đúng hình dạng bảng.

**Kết quả chạy:** (chú ý `Escape ` in ra trước nhờ dòng `cout << car[0][1]` ở đầu)

```
Escape Mustard, Escape, F-150, 
Corvette, Equinox, Silverado, 
Challenger, Durango, Ram 1500, 
```

> [!tip] Mẹo
> Quy ước đặt tên quen thuộc: `i` cho hàng, `j` cho cột. Nếu dễ lẫn, đặt hẳn `row` / `col` cho code dễ đọc hơn — đặc biệt khi làm bài lưới/ma trận trong competitive programming.

> [!warning] Cạm bẫy thường gặp
> - Bỏ luôn số cột: `std::string car[][] = {...}` → <span style="color:#e06c75">lỗi biên dịch</span>, vì compiler cần biết mỗi hàng dài bao nhiêu để tính vị trí phần tử.
> - Đảo `car[j][i]` thành `car[i][j]` (hoặc ngược lại) → in sai thứ tự, hoặc đọc ngoài mảng nếu bảng **không vuông** (ví dụ 2 hàng × 3 cột).
> - Dấu `, ` thừa ở cuối mỗi hàng khi in (như output trên) — chấp nhận được khi học, nhưng bài thi thường bắt in đúng định dạng.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `type arr[R][C]` | Mảng 2 chiều: R hàng, C cột |
| `arr[][C] = {{...},{...}}` | Khởi tạo: được bỏ số hàng, **không** được bỏ số cột |
| `arr[i][j]` | Phần tử ở hàng `i`, cột `j` (đếm từ 0) |
| `sizeof(arr)/sizeof(arr[0])` | Số hàng |
| `sizeof(arr[0])/sizeof(arr[0][0])` | Số cột |
| 2 vòng `for` lồng nhau | Vòng ngoài = hàng, vòng trong = cột |

> [!question] Tự luyện
> 1. Thêm một hàng thứ 4 vào `car` (không sửa phần tính `rows`), chạy lại xem `rows` có tự thành `4` không.
> 2. Sửa vòng in để **không** in dấu `, ` thừa ở cuối mỗi hàng (gợi ý: kiểm tra `j` có phải cột cuối chưa).
> 3. Thử in **theo cột** thay vì theo hàng — tức là in cột 0 của cả 3 hàng trước, rồi cột 1... (đảo vai trò hai vòng `for`).
