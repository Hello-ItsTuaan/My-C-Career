---

## tags: [cpp, brocode] source: "BroCode - Type Conversion" date: 2026-09-01

# Chuyển đổi kiểu dữ liệu (`Type Conversion`)

#cpp/type-conversion #cpp/co-ban #brocode

> [!note] Khái niệm Type conversion là việc chuyển giá trị từ kiểu dữ liệu này sang kiểu dữ liệu khác. Có 2 loại:
> 
> - **Implicit** (ngầm định): trình biên dịch tự động chuyển đổi, không cần mình ghi gì cả.
> - **Explicit** (tường minh): mình chủ động ép kiểu bằng cách viết kiểu mới trước giá trị, ví dụ `(int) 3.14`.

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    // int x = 3.14;              -> output = 3        (implicit, tự mất phần thập phân)
    // double x = 3.14;           -> output = 3.14      (không đổi vì cùng kiểu double)
    // double x = (int) 3.14;     -> ép kiểu về int rồi gán lại cho double -> mất .14
    // std::cout << x;

    // char x = 100;               -> output = 'd' (mã ASCII của 100 là 'd')
    // std::cout << char(100);     -> cách viết khác của explicit conversion

    int correct = 8;
    int question = 10;

    double score = correct / (double) question * 100;

    std::cout << score << "%";

    return 0;
}
```

Phần quan trọng nhất bài này là dòng `double score = correct / (double) question * 100;`.

Nếu viết `correct / question` thì cả hai đều là `int`, C++ sẽ thực hiện ==phép chia số nguyên (integer division)== — tức là phần thập phân bị cắt bỏ trước khi có cơ hội nhân với 100, kết quả sẽ sai hoàn toàn (ví dụ `8/10 = 0`, rồi `0 * 100 = 0`).

Bằng cách ép `question` thành `(double) question` <span style="color:#61afef">ngay trong phép chia</span>, C++ sẽ tự động nâng cả `correct` lên `double` để tính toán (đây gọi là _implicit promotion_ đi kèm với explicit cast mình chủ động thêm vào), nên phép chia trả về kết quả có phần thập phân chính xác.

> [!warning] Cạm bẫy thường gặp `int / int` luôn cho ra `int`, dù bạn gán kết quả cho biến `double`. Ép kiểu phải nằm **bên trong phép tính** (trước khi chia), không phải ép kiểu kết quả sau khi đã chia xong — lúc đó phần thập phân đã mất rồi, không lấy lại được. Đây chính là chỗ mà comment gốc `//! WRONG! int devision` đang nhắc tới.

> [!tip] Mẹo Muốn chắc chắn phép chia ra số thực, chỉ cần ép kiểu **một trong hai** toán hạng sang `double` là đủ — không cần ép cả hai, vì C++ sẽ tự "nâng cấp" toán hạng còn lại theo quy tắc implicit conversion.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|Implicit conversion|Tự động, không cần cú pháp đặc biệt (ví dụ gán `double` vào `int`)|
|Explicit conversion|Chủ động ép kiểu: `(kiểu) giá_trị`, ví dụ `(int) 3.14`|
|`char` ↔ số|Ép kiểu qua lại dùng bảng mã ASCII (100 → `'d'`)|
|Integer division|`int / int` luôn cắt bỏ phần thập phân, kể cả khi gán cho `double`|
|Cách sửa|Ép ít nhất 1 toán hạng sang `double` **trước khi** chia|

> [!question] Tự luyện
> 
> 1. Viết lại đoạn code trên nhưng tính phần trăm số câu **sai** thay vì đúng, vẫn phải cho ra số thập phân chính xác.
> 2. Thử bỏ `(double)` đi và chạy code, xem kết quả in ra là gì — giải thích tại sao.