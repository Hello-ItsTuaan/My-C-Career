---

## tags: [cpp, brocode] source: "BroCode - C++ Full Course (const)" date: 2026-08-29

# Hằng số (`const`)

#cpp/const #cpp/co-ban #brocode

> [!note] Khái niệm `const` dùng để khai báo một **biến bất biến** — tức là giá trị mà bạn ==chắc chắn sẽ không thay đổi== trong suốt chương trình (một "static value"). Ví dụ điển hình: hằng số toán học (`PI`), hằng số vật lý (`LIGHT_SPEED`), hoặc các thông số cấu hình cố định (độ phân giải màn hình).

## Cú pháp & Ví dụ

```cpp
#include <iostream>

    const double PI = 3.14159;
    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    std::cout << "Pi is " << PI << '\n'
              << "Your screen resolution is " << WIDTH << "x" << HEIGHT << std::endl;

    return 0;
}
```

- Cú pháp: `const <kiểu dữ liệu> <TÊN_BIẾN> = <giá_trị>;`
- Quy ước đặt tên: hằng số thường viết **UPPER_SNAKE_CASE** (`LIGHT_SPEED`, `WIDTH`) để phân biệt với biến thường — dễ nhận ra ngay là "cái này không được sửa".
- <span style="color:#61afef">`const` phải được gán giá trị ngay lúc khai báo</span> — không thể khai báo `const int x;` rồi gán sau.

> [!tip] Mẹo (từ comment gốc của BroCode) Nên dùng `const` **càng nhiều càng tốt**, miễn là bạn chắc chắn biến đó là tĩnh (không đổi). Đây là một thói quen code tốt: nó giúp người đọc code (và cả compiler) biết ngay biến nào an toàn, không bị thay đổi ngoài ý muốn ở đâu đó trong chương trình.

> [!warning] Cạm bẫy thường gặp Cố gắng gán lại giá trị cho biến `const` sau khi khai báo sẽ gây ==lỗi biên dịch (compile error)==:
> 
> ```cpp
> const int WIDTH = 1920;
> WIDTH = 2560; // ❌ Lỗi: assignment of read-only variable 'WIDTH'
> ```
> 
> <span style="color:#e06c75">Compiler sẽ chặn ngay tại bước biên dịch</span>, không phải lúc chạy chương trình — đây chính là lợi ích chính của `const`.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|`const` = bất biến|Giá trị không đổi sau khi khởi tạo|
|Phải gán ngay|Không thể khai báo rồi gán giá trị sau|
|Đặt tên UPPER_SNAKE_CASE|Quy ước phổ biến, không bắt buộc nhưng nên theo|
|Dùng càng nhiều càng tốt|Miễn là biến đó thật sự tĩnh|

> [!question] Tự luyện
> 
> 1. Viết thêm một hằng số `const int MAX_PLAYERS = 4;` và in ra câu "Số người chơi tối đa: 4".
> 2. Thử bỏ dòng gán giá trị ban đầu của `PI` (chỉ khai báo `const double PI;`) và xem compiler báo lỗi gì.