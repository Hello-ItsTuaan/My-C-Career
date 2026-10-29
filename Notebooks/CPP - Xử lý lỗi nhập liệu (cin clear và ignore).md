---
tags: [cpp, brocode]
source: "Rock Paper Scissors - validate input"
date: 2026-10-04
---

# Xử lý lỗi nhập liệu (`cin.clear()` và `cin.ignore()`)

#cpp/input #cpp/co-ban #brocode

> [!note] Khái niệm
> Khi người dùng nhập sai kiểu (ví dụ gõ chữ `abc` vào biến `int`), `cin` rơi vào ==trạng thái lỗi (fail state)== và **ngừng đọc** mọi thứ sau đó. Hai hàm `cin.clear()` và `cin.ignore()` dùng để "cứu" `cin` khỏi trạng thái này. Xem thêm [[CPP - Đầu vào của người dùng (User input)]].

## Cú pháp & Ví dụ

```cpp
#include <iostream>
#include <limits>

int main() {
    int choice;

    std::cout << "Choose 1, 2 or 3: ";

    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        std::cin.clear();                                              // bước 1: xóa cờ lỗi
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // bước 2: bỏ dữ liệu rác
        std::cout << "Invalid! Choose 1, 2 or 3: ";
    }

    std::cout << "You chose " << choice << "\n";
    return 0;
}
```

### `cin.clear()`

- <span style="color:#61afef">Xóa các cờ lỗi</span> (`failbit`) để `cin` hoạt động lại bình thường.
- ==Nó KHÔNG xóa dữ liệu rác đang nằm trong bộ đệm.== Nếu chỉ `clear()` thôi, lần `cin >> choice` tiếp theo sẽ đọc lại đúng cái rác đó và fail tiếp, dẫn tới vòng lặp vô hạn.

### `cin.ignore(count, delimiter)`

- Bỏ qua (xóa) tối đa `count` ký tự trong bộ đệm, **dừng sớm** khi gặp ký tự `delimiter` (và bỏ luôn ký tự đó).
- Tham số thứ 2 là **1 ký tự (`char`)**, không phải chuỗi.
- `cin.ignore(10000, '\n')`: bỏ tối đa 10000 ký tự hoặc tới hết dòng.
- `cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')`: bỏ **không giới hạn** tới hết dòng (cần `#include <limits>`).
- `cin.ignore()` không tham số = bỏ đúng 1 ký tự.

| Hàm | Làm gì | Xử lý cái gì |
|---|---|---|
| `cin.clear()` | Xóa cờ lỗi | <span style="color:#98c379">Trạng thái</span> của `cin` |
| `cin.ignore(n, '\n')` | Bỏ ký tự thừa | <span style="color:#d19a66">Dữ liệu</span> trong bộ đệm |

> [!tip] Dùng `ignore` ở đâu nữa?
> Sau `cin >> x`, ký tự xuống dòng `'\n'` vẫn nằm trong bộ đệm. Nếu ngay sau đó gọi `getline`, nó sẽ đọc ra **chuỗi rỗng**. Chèn `std::cin.ignore(10000, '\n');` vào giữa là xong. (Giống `std::ws`, nhưng `ignore` bỏ cả dòng thừa.)

> [!warning] Cạm bẫy thường gặp
> **Thứ tự phải là `clear()` trước, `ignore()` sau.** Khi `cin` đang ở trạng thái lỗi, `ignore()` không làm gì cả, rác vẫn còn nguyên.
>
> ```cpp
> // SAI: ignore lúc cin còn lỗi -> không có tác dụng
> std::cin.ignore(10000, '\n');
> std::cin.clear();
>
> // ĐÚNG
> std::cin.clear();
> std::cin.ignore(10000, '\n');
> ```

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Nhập sai kiểu | `cin` vào fail state, các lần đọc sau bị bỏ qua |
| `cin.clear()` | Reset cờ lỗi, nhưng rác vẫn còn trong bộ đệm |
| `cin.ignore(n, '\n')` | Xóa rác tới hết dòng (delimiter là `char`) |
| Thứ tự | ==`clear()` rồi mới `ignore()`== |
| Mẫu hay dùng | `while` lặp tới khi nhập đúng, trong thân lặp gọi cả hai hàm |

> [!question] Tự luyện
> 1. Viết hàm `getAge()` bắt nhập lại cho tới khi người dùng nhập số nguyên từ 1 đến 120.
> 2. Thử bỏ dòng `cin.ignore(...)` rồi nhập `abc`. Chuyện gì xảy ra? Sau đó thử đảo thứ tự `ignore` và `clear` xem có khác không.
