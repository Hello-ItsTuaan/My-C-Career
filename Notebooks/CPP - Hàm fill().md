---
tags: [cpp, brocode]
source: "BroCode - fill()"
date: 2026-10-15
---

# Hàm điền giá trị (`fill()`)

#cpp/fill #cpp/mang #cpp/algorithm #brocode

> [!note] Khái niệm
> `std::fill(begin, end, value)` là hàm trong thư viện `<algorithm>` dùng để ==gán cùng một giá trị cho toàn bộ một đoạn phần tử==, thay vì phải viết vòng `for` tay. Đoạn được điền là **nửa mở** `[begin, end)` — tức là phần tử ở `begin` được điền, còn phần tử ở `end` thì **không**.

Liên quan: [[CPP - Mảng (Arrays)]] · [[CPP - Vòng lặp for (for loops)]] · [[CPP - Truyền mảng vào hàm]]

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    const int size = 100;
    std::string anotherFoods[size] = {};

    fill(anotherFoods, anotherFoods + (size/3), "pizza");                 // [0, 33)   -> pizza
    fill(anotherFoods + size/3, anotherFoods + size, "Hamburger");        // [33, 100) -> Hamburger
    fill(anotherFoods + (size/3*2), anotherFoods + size, "Hotdog");       // [66, 100) -> Hotdog (ghi đè)

    for (std::string food : anotherFoods) {
        std::cout << food << "\n";
    }

    return 0;
}
```

**Đọc từng phần:**

- `anotherFoods` (tên mảng) chính là địa chỉ phần tử đầu tiên → dùng làm `begin`.
- `anotherFoods + n` là địa chỉ phần tử thứ `n` → dùng làm `end`. Đây là **số học con trỏ**: cộng `n` nghĩa là nhảy tới `n` phần tử, không phải `n` byte.
- Dùng `size` thay vì số `100` cứng → đổi kích thước mảng chỉ cần sửa 1 chỗ.

### Bảng phân vùng của đoạn code trên

| Lệnh `fill` | Đoạn điền | Giá trị | Kết quả cuối cùng |
|---|---|---|---|
| 1 | `[0, 33)` | `"pizza"` | index 0 → 32 là pizza |
| 2 | `[33, 100)` | `"Hamburger"` | tạm thời index 33 → 99 là Hamburger |
| 3 | `[66, 100)` | `"Hotdog"` | **ghi đè** index 66 → 99 thành Hotdog |

==Kết quả cuối: 33 pizza, 33 Hamburger, 34 Hotdog== (vì `100/3 = 33` là chia nguyên, nên phần dư rơi vào đoạn cuối).

> [!important] Thứ tự lệnh quan trọng
> Lệnh `fill` sau sẽ <span style="color:#d19a66">ghi đè</span> lệnh trước nếu hai đoạn chồng lên nhau. Ở đây lệnh 2 điền Hamburger tới tận cuối mảng, rồi lệnh 3 mới "cắt" lại phần cuối thành Hotdog. Đảo thứ tự lệnh 2 và 3 là kết quả đổi hoàn toàn (Hamburger sẽ đè hết Hotdog).

> [!tip] Mẹo
> - Chia mảng thành các vùng bằng cách tính mốc: `size/3`, `size/3*2`. Đoạn cuối luôn kết thúc ở `+ size` để không bị sót phần dư.
> - Muốn reset mảng số về 0 hoặc -1 (rất hay gặp khi làm bài thi giải thuật): `fill(arr, arr + n, 0);` — gọn hơn vòng `for` nhiều. Ghi chú này hữu ích cho hướng [[CPP - Mảng đánh dấu (seen) và size_t]].
> - Dùng `const auto&` trong vòng range-for để khỏi copy string mỗi lần: `for (const std::string& food : anotherFoods)`.

> [!warning] Cạm bẫy thường gặp
> - <span style="color:#e06c75">Điền vượt biên:</span> `fill(arr, arr + 101, ...)` với mảng 100 phần tử → ghi ra ngoài vùng nhớ (undefined behavior). Nhớ `end` là vị trí **sau** phần tử cuối.
> - <span style="color:#e06c75">Thiếu header:</span> code gốc chỉ có `#include <iostream>` mà vẫn chạy được là nhờ may mắn của compiler (và cơ chế ADL, vì đối số là con trỏ tới `std::string`). Viết chuẩn thì phải có `#include <algorithm>` và `#include <string>`, và gọi `std::fill(...)`. Với mảng `int` thì không còn "may mắn" nữa, thiếu `std::` là lỗi biên dịch.
> - Dòng `std::string foods[10] = {"pizza", ...}` ở đầu bài chỉ là cách điền **thủ công lúc khai báo**, nó không dùng `fill()` và chỉ phù hợp khi mảng nhỏ. Mảng 100 phần tử thì viết tay là bất khả thi → đó chính là lý do `fill()` tồn tại.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Cú pháp | `std::fill(begin, end, value)` |
| Header | `<algorithm>` |
| Đoạn điền | Nửa mở `[begin, end)` — `end` không được điền |
| Với mảng | `begin = arr`, `end = arr + n` |
| Chồng đoạn | Lệnh sau ghi đè lệnh trước |
| Phần dư khi chia | `size/3` là chia nguyên → đoạn cuối nhận phần dư |

> [!question] Tự luyện
> 1. Tạo mảng `int nums[50]`, dùng `fill` để chia thành 5 đoạn: 1, 2, 3, 4, 5 (mỗi đoạn 10 phần tử), rồi in ra và đếm xem mỗi số xuất hiện đúng 10 lần không.
> 2. Sửa code gốc thành 4 món ăn (pizza / Hamburger / Hotdog / Sushi) chia đều cho `size = 100`. Dự đoán trước mỗi món chiếm bao nhiêu phần tử, rồi chạy kiểm tra.
