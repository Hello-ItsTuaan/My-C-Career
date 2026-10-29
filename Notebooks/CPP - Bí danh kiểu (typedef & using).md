---

## tags: [cpp, brocode] source: "BroCode - typedef & using" date: 2026-08-30

# Bí danh kiểu (`typedef` / `using`)

#cpp/type-alias #cpp/co-ban #brocode

> [!note] Khái niệm `typedef` là từ khóa dùng để tạo một **tên gọi khác (bí danh)** cho một kiểu dữ liệu đã có sẵn. Nó không tạo ra kiểu mới, chỉ đơn giản là gắn thêm một cái tên cho kiểu cũ, giúp code dễ đọc hơn và giảm gõ nhầm khi phải lặp lại những kiểu dài dòng (ví dụ `std::vector<std::pair<std::string, int>>`).

## Cú pháp & Ví dụ

```cpp
#include <iostream>
#include <vector>

// typedef std::vector<std::pair<std::string, int>> pairlist_t;
// typedef std::string text_t;
// typedef int number_t;

using text_t = std::string;
using number_t = int;

int main() {
    text_t firstName = "Tuan";
    number_t age = 13;

    std::cout << firstName << '\n';
    std::cout << age << '\n';
    return 0;
}
```

Cả hai dòng comment `typedef` và hai dòng `using` phía dưới làm **cùng một việc**: biến `text_t` thành bí danh của `std::string`, và `number_t` thành bí danh của `int`. Sau đó `firstName` và `age` có thể khai báo bằng `text_t` / `number_t` y hệt như dùng `std::string` / `int` trực tiếp.

==`using` là cách viết hiện đại hơn và nên ưu tiên dùng thay cho `typedef`==, đặc biệt vì `using` hoạt động tốt hơn với template (sẽ học ở bài sau).

> [!tip] Mẹo Chỉ nên tạo bí danh kiểu khi nó **thực sự giúp code rõ nghĩa hơn** — ví dụ rút gọn `std::vector<std::pair<std::string, int>>` thành `pairlist_t` thì rất đáng, nhưng đổi `int` thành `number_t` như trong bài chỉ mang tính minh họa cú pháp, không có lợi ích rõ ràng trong thực tế.

> [!warning] Cạm bẫy thường gặp Đừng nhầm bí danh kiểu với việc tạo ra <span style="color:#e06c75">một kiểu dữ liệu mới</span> — `text_t` và `std::string` là **hoàn toàn giống nhau** đối với trình biên dịch, chỉ khác tên gọi. Không có kiểm tra kiểu chặt chẽ hơn hay an toàn hơn khi dùng alias.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|`typedef <kiểu cũ> <tên mới>;`|Cú pháp cũ, đặt tên mới ở cuối|
|`using <tên mới> = <kiểu cũ>;`|Cú pháp mới, đọc tự nhiên như gán biến, nên ưu tiên dùng|
|Mục đích|Tăng khả năng đọc code, giảm gõ lặp/gõ sai kiểu dài|
|Không tạo kiểu mới|Chỉ là tên gọi khác, trình biên dịch coi là cùng một kiểu|
|Nên dùng khi nào|Khi kiểu gốc dài/phức tạp (VD: `std::vector<std::pair<...>>`), không cần thiết với kiểu đơn giản như `int`|

> [!question] Tự luyện
> 
> 1. Tạo bí danh `pairlist_t` cho `std::vector<std::pair<std::string, int>>` bằng `using`, rồi khai báo một biến kiểu đó và thêm vài phần tử bằng `push_back`.
> 2. Thử tạo bí danh `celsius_t` cho `double`, viết một hàm nhận `celsius_t` và trả về nhiệt độ đổi sang Fahrenheit.