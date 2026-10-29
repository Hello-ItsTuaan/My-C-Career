---
tags: [cpp, brocode]
source: "BroCode - Random Numbers"
date: 2026-09-22
---

# Số ngẫu nhiên (`rand`, `srand`)

#cpp/random #cpp/co-ban #brocode

> [!note] Khái niệm
> C++ không có "ngẫu nhiên thật" — `rand()` sinh ra **pseudo-random number**
> (số giả-ngẫu-nhiên), tức là một dãy số được tính toán bằng công thức, trông
> "random" nhưng thực chất là xác định (deterministic) nếu biết điểm khởi đầu
> gọi là **seed**. `srand()` dùng để đặt seed đó.

## Cú pháp & Ví dụ

```cpp
#include <ctime>
#include <iostream>

int main() {
    srand(time(NULL));
    int num1 = rand() % 100 + 1; // 1 - 100
    int num2 = rand() % 100 + 1;
    int num3 = rand() % 100 + 1;

    std::cout << num1 << "\n";
    std::cout << num2 << "\n";
    std::cout << num3 << "\n";

    return 0;
}
```

- `srand(time(NULL))` — set seed bằng **thời gian hiện tại** (số giây kể từ
  1/1/1970), nên mỗi lần chạy chương trình seed đều khác nhau →
  ==dãy số random khác nhau mỗi lần chạy==.
- `rand()` — trả về một số nguyên ngẫu nhiên (giả), thường trong khoảng rất
  lớn (0 đến `RAND_MAX`).
- `rand() % 100 + 1` — công thức kinh điển để giới hạn phạm vi:
  - `% 100` → ép số về khoảng `0 - 99`
  - `+ 1` → dịch lên thành `1 - 100`
  - Muốn đổi phạm vi thì chỉ cần đổi số chia, ví dụ `% 50 + 1` →
    <span style="color:#61afef">khoảng 1 - 50</span>.

> [!tip] Mẹo
> Công thức tổng quát để random trong khoảng `[min, max]`:
> `rand() % (max - min + 1) + min`

> [!warning] Cạm bẫy thường gặp
> Nếu **quên gọi `srand()`** (hoặc gọi `srand()` với cùng một số cố định),
> chương trình sẽ <span style="color:#e06c75">sinh ra cùng một dãy số y hệt
> mỗi lần chạy</span> — nhìn tưởng random nhưng thực chất không phải. Cũng
> chỉ nên gọi `srand()` **một lần duy nhất** ở đầu `main()`, gọi nhiều lần
> (ví dụ trong vòng lặp) có thể làm các số bị trùng nhau.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `rand()` | Sinh số giả-ngẫu-nhiên (pseudo-random) |
| `srand(seed)` | Đặt điểm khởi đầu cho dãy số |
| `srand(time(NULL))` | Seed theo thời gian thực → mỗi lần chạy khác nhau |
| `rand() % N + 1` | Giới hạn số về khoảng `1 - N` |
| `<ctime>` | Header cần include để dùng `time()` |

> [!question] Tự luyện
> 1. Sửa code để random số trong khoảng `1 - 6` (mô phỏng xúc xắc/dice).
> 2. Thử bỏ dòng `srand(time(NULL))` đi rồi chạy chương trình 2-3 lần liên
>    tiếp — quan sát xem kết quả có giống nhau không, vì sao?
