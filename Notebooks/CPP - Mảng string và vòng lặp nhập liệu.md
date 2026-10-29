---
tags: [cpp, brocode]
source: "BroCode - Array of strings + vòng lặp nhập liệu với break"
date: 2026-10-17
---

# Mảng string & vòng lặp nhập liệu (`std::string foods[5]`)

#cpp/array #cpp/string #cpp/input #brocode

> [!note] Khái niệm
> Mảng không chỉ chứa số — ta có thể khai báo **mảng các `std::string`** để lưu nhiều chuỗi cùng lúc. Kết hợp với vòng lặp `for` + `std::getline` + `break`, ta làm được chương trình cho người dùng nhập *tối đa N món*, và có thể **dừng sớm** bằng một từ khoá (ở đây là `q`).

## Cú pháp & Ví dụ

```cpp
#include <bits/stdc++.h>

int main() {
    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);
    std::string temp;

    for (int i = 0; i < size; i++) {
        std::cout << "Enter a food you like #" << i+1 << " or 'q' to quit: ";
        std::getline (std::cin >> std::ws, temp);

        if (temp == "q") {
            break;
        } else {
            foods[i] = temp;
        }
    }

    for (int i = 0; i < size && !foods[i].empty(); i++) {
        std::cout << i+1 << ". " << foods[i] << "\n";
    }

    return 0;
}
```

### 1. Khai báo mảng string & tính kích thước

- `std::string foods[5];` tạo 5 phần tử, ==mỗi phần tử tự động là chuỗi rỗng `""`== (khác với mảng `int` cục bộ, nơi giá trị ban đầu là rác).
- `sizeof(foods)/sizeof(foods[0])` = tổng byte của mảng chia byte của 1 phần tử → ra **số phần tử** (ở đây là `5`). Xem lại cách này ở [[CPP - Truyền mảng vào hàm]] — nó chỉ đúng khi mảng còn nằm *cùng scope* với chỗ khai báo.

### 2. Vòng lặp nhập: biến `temp` làm "trạm trung chuyển"

- Đọc vào `temp` **trước**, rồi mới quyết định có lưu vào `foods[i]` hay không.
- Nếu đọc thẳng vào `foods[i]` thì khi gõ `q`, chữ `"q"` sẽ bị lưu luôn vào mảng → in ra danh sách sẽ có món tên là "q" 🤡.
- `std::getline(std::cin >> std::ws, temp)` — `std::ws` bỏ khoảng trắng/xuống dòng thừa ở đầu, nên đọc được cả món có dấu cách như `"bun bo hue"`. Chi tiết ở [[CPP - Nhập xuất cơ bản (cin, cout, getline)]].
- `break` thoát khỏi vòng `for` ngay lập tức khi gặp `"q"`.

### 3. Vòng lặp in: điều kiện dừng kép

```cpp
for (int i = 0; i < size && !foods[i].empty(); i++)
```

- Dừng khi **hết mảng** (`i < size`) *hoặc* khi gặp **phần tử rỗng** (`foods[i].empty()`) — tức là chỗ người dùng chưa nhập gì.
- ==Thứ tự hai điều kiện rất quan trọng==: `i < size` phải đứng **trước**. Nhờ <span style="color:#61afef">short-circuit của `&&`</span>, nếu `i == size` thì vế phải không bao giờ được chạy, nên không truy cập `foods[5]` (ngoài mảng).

> [!tip] Mẹo: dùng "phần tử rỗng" làm sentinel
> Vì `std::string` mặc định rỗng, ta không cần thêm biến đếm `count` — chỉ cần in đến khi gặp chuỗi rỗng. Cách này gọn, nhưng chỉ an toàn khi chắc chắn người dùng **không thể** nhập chuỗi rỗng (ở đây `std::ws` đã lo chuyện đó).

> [!warning] Cạm bẫy thường gặp
> - Đảo thành `!foods[i].empty() && i < size` → khi `i == 5` sẽ đọc <span style="color:#e06c75">ngoài phạm vi mảng (undefined behavior)</span> nếu người dùng nhập đủ 5 món.
> - Quên `std::ws` → `getline` có thể nuốt luôn ký tự `\n` còn sót lại và trả về chuỗi rỗng.
> - Đọc thẳng vào `foods[i]` rồi mới kiểm tra `"q"` → `"q"` bị lưu vào mảng.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `std::string arr[N]` | Mảng N chuỗi, mỗi phần tử mặc định là `""` |
| `sizeof(arr)/sizeof(arr[0])` | Lấy số phần tử (chỉ đúng trong cùng scope khai báo) |
| `std::getline(std::cin >> std::ws, s)` | Đọc cả dòng, bỏ khoảng trắng đầu |
| `temp` trung gian | Kiểm tra từ khoá thoát trước khi lưu vào mảng |
| `break` | Thoát vòng lặp sớm |
| `i < size && !arr[i].empty()` | Dừng khi hết mảng hoặc gặp ô trống — nhớ để `i < size` đứng trước |

> [!question] Tự luyện
> 1. Sửa chương trình để dùng biến `count` đếm số món đã nhập, rồi in danh sách bằng `for (int i = 0; i < count; i++)` thay vì dùng `.empty()`.
> 2. Thêm phần in **ngược** danh sách món (từ món cuối nhập về món đầu) — gợi ý: bắt đầu từ chỉ số cuối hợp lệ rồi giảm dần.
