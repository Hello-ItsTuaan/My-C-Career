---
tags: [cpp, brocode]
source: "BroCode - Chuỗi (std::string Methods)"
date: 2026-09-14
---

# Xử Lý Chuỗi Cơ Bản (`std::string` Methods)

#cpp/string #cpp/co-ban #brocode

> [!note] Khái niệm
> `std::string` không chỉ là một dãy ký tự — nó là một **object** đi kèm
> hàng loạt **method** dựng sẵn để đọc, kiểm tra, và chỉnh sửa chuỗi mà
> không cần tự viết vòng lặp thủ công. Cú pháp chung: `tenBien.method(...)`.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    name.length();          // trả về độ dài chuỗi (số ký tự)
    name.empty();            // kiểm tra chuỗi có rỗng không -> true/false

    if (name.empty()) {
        std::cout << "You didn't enter your name" << "\n";
    } else if (name.length() > 12) {
        std::cout << "Your name can't be longer than 12 characters!\n";
    } else {
        std::cout << "Welcome " << name << "\n";
    }

    name.append("@gmail.com");            // nối thêm chuỗi vào cuối
    std::cout << "Your username is " << name << "\n";

    std::cout << name.at(0) << "\n";          // lấy ký tự tại vị trí index 0
    std::cout << name.insert(0, "#") << "\n"; // chèn "#" vào vị trí index 0
    std::cout << name.find(' ') << "\n";      // tìm vị trí index của ' '

    std::cout << name.erase(1, 2) << "\n";    // xoá 2 ký tự, bắt đầu từ index 1
    name.clear();                              // xoá sạch toàn bộ chuỗi

    return 0;
}
```

Đoạn code gốc bị lỗi từ vựng nhỏ: comment ghi *"can't be longer than 12
digits"* — nhưng `.length()` đếm **ký tự (characters)**, không phải
**chữ số (digits)**. "Nguyễn Bá Minh Tuấn" đâu phải là một con số đâu 😄,
nên bản refactor phía trên đã sửa lại thành "characters" cho đúng nghĩa.

Giải thích các method chính:

- **`.length()`** — trả về số ký tự trong chuỗi (kiểu `size_t`).
- **`.empty()`** — trả về `true` nếu chuỗi rỗng (`""`), dùng để validate input.
- **`.append(str)`** — nối thêm `str` vào cuối chuỗi hiện tại (giống `+=`).
- **`.at(index)`** — trả về ký tự tại vị trí `index`, có kiểm tra lỗi
  (ném exception nếu index vượt giới hạn) — an toàn hơn `name[index]`.
- **`.insert(index, str)`** — chèn `str` vào chuỗi tại vị trí `index`.
- **`.find(value)`** — trả về **index** đầu tiên tìm thấy `value`; nếu
  không tìm thấy sẽ trả về `std::string::npos` (một hằng số rất lớn).
- **`.erase(pos, count)`** — xoá bớt ký tự trong chuỗi.
- **`.clear()`** — xoá sạch, chuỗi trở thành `""`.

> [!warning] Cạm bẫy thường gặp — `erase()` không nhận (start, end)!
> Comment gốc ghi `erase(1, 2)` là "starting index, ending index" —
> ==đây là hiểu sai==. Tham số thứ hai của `.erase()` là **count** (số
> lượng ký tự cần xoá), **không phải** vị trí kết thúc. Vậy
> `erase(1, 2)` nghĩa là: bắt đầu từ index 1, xoá **2 ký tự** — chứ
> không phải "xoá từ index 1 đến index 2". Nhầm chỗ này rất dễ dẫn tới
> xoá sai đoạn chuỗi khi index/length của chuỗi thay đổi.

> [!tip] Mẹo
> Dùng <span style="color:#61afef">`.at(index)`</span> thay vì
> `name[index]` khi chưa chắc index có hợp lệ hay không — `.at()` sẽ
> ném exception rõ ràng thay vì gây undefined behavior như `[]`.

## Tóm tắt nhanh

| Method | Ý nghĩa |
|---|---|
| `.length()` | Số ký tự trong chuỗi |
| `.empty()` | Có rỗng hay không (bool) |
| `.append(str)` | Nối thêm chuỗi vào cuối |
| `.at(i)` | Lấy ký tự tại vị trí i (có kiểm tra lỗi) |
| `.insert(i, str)` | Chèn chuỗi vào vị trí i |
| `.find(val)` | Tìm index đầu tiên của val (hoặc `npos`) |
| `.erase(pos, count)` | Xoá `count` ký tự bắt đầu từ `pos` |
| `.clear()` | Xoá sạch chuỗi |

> [!question] Tự luyện
> 1. Viết lại đoạn code để dùng `.find("@gmail.com")` kiểm tra xem
>    username đã có domain gmail hay chưa trước khi `.append()`.
> 2. Sửa lỗi giả định: nếu `.find(' ')` trả về `std::string::npos`
>    (không có khoảng trắng), in ra thông báo phù hợp thay vì in ra một
>    con số vô nghĩa.
