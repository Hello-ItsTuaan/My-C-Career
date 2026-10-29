---

## tags: [cpp, brocode] source: "BroCode - if statement" date: 2026-09-03

# Câu lệnh điều kiện (`if` / `else if` / `else`)

#cpp/if-else #cpp/dieu-khien #brocode

> [!note] Khái niệm `if` là câu lệnh cho phép chương trình **rẽ nhánh**: chỉ thực thi một khối code khi điều kiện trong ngoặc `()` là `true`. Nếu không, chương trình bỏ qua khối đó. `else if` cho phép kiểm tra thêm điều kiện khác nếu điều kiện trước đó sai, còn `else` là "trường hợp còn lại" — chạy khi tất cả điều kiện trên đều sai.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    int age;

    std::cout << "Enter your age: ";
    if (!(std::cin >> age)) {
      std::cout << "Please enter a valid age.";
      return 1;
   }

    if (age >= 18) {
        std::cout << "You're an adult!";
    }
     else if (age <= 10) {
        std::cout << "You're a kid!";
     }
     else if (age <= 18) {
        std::cout << "You're a Teenager!";
     } else {
        std::cout << "Did you type something wrong?";
     }

    return 0;
}
```

Chương trình chạy tuần tự theo từng khối `if`:

- `if (!(std::cin >> age))` — đây là phần **kiểm tra input hợp lệ**. `std::cin >> age` trả về chính đối tượng `std::cin`, và khi ép nó về `bool` (do dấu `!` phía trước), nếu người dùng nhập sai kiểu (ví dụ gõ chữ thay vì số), giá trị này sẽ là `false` → `!false = true` → vào nhánh báo lỗi và `return 1;` để thoát chương trình ngay. ==Đây là mẹo kiểm tra lỗi input rất hay gặp trong C++, không phải lúc nào BroCode cũng dạy ngay từ đầu.==
- Từ đó trở xuống là chuỗi `if / else if / else` chính: chương trình kiểm tra `age >= 18` trước, nếu đúng thì in "adult" và **dừng luôn**, không kiểm tra các điều kiện `else if` phía sau nữa.
- Điều thú vị: khối `else if (age <= 18)` (dòng in "Teenager") thực ra sẽ **không bao giờ chạy** cho `age` từ 11–17 theo đúng ý định, vì nó _có_ chạy đúng — nhưng thứ tự điều kiện hơi dư vì `age >= 18` đã được lọc ở nhánh đầu. Vẫn đúng logic, chỉ hơi "thừa an toàn".

<span style="color:#61afef">Quy tắc vàng:</span> C++ luôn kiểm tra các điều kiện `if` / `else if` **theo thứ tự từ trên xuống**, và dừng lại ngay khi gặp điều kiện đầu tiên đúng — các điều kiện phía sau bị bỏ qua hoàn toàn, dù chúng cũng đúng.

> [!tip] Mẹo Luôn đặt điều kiện **hẹp/đặc biệt nhất** lên trước nếu các điều kiện có thể chồng lấn nhau, để tránh nhánh sau bị "chặn" oan bởi nhánh trước.

> [!warning] Cạm bẫy thường gặp Quên rằng `std::cin >> age` sẽ thất bại (và để lại `age` không xác định) nếu người dùng gõ chữ thay vì số — nếu không kiểm tra bằng `if (!(std::cin >> age))` như trong bài, chương trình có thể chạy tiếp với giá trị rác mà không báo lỗi gì cả.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|`if`|Chạy khối code nếu điều kiện `true`|
|`else if`|Kiểm tra thêm điều kiện khác, chỉ khi các điều kiện trước đó `false`|
|`else`|Khối "mặc định", chạy khi tất cả điều kiện trên đều `false`|
|Thứ tự kiểm tra|Từ trên xuống, dừng ngay khi gặp điều kiện đúng đầu tiên|
|`!(std::cin >> x)`|Cách kiểm tra input có hợp lệ hay không|

> [!question] Tự luyện
> 
> 1. Thêm một điều kiện `else if (age < 0)` để bắt trường hợp người dùng nhập tuổi âm — nên đặt nó ở đâu trong chuỗi if/else để hoạt động đúng?
> 2. Viết lại chương trình để phân loại tuổi thành 4 nhóm: "Nhi đồng" (0-5), "Trẻ em" (6-10), "Teen" (11-17), "Người lớn" (18+) — chú ý thứ tự điều kiện.