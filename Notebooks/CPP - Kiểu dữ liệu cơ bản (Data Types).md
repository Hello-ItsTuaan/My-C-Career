---

## tags: [cpp, brocode] source: "BroCode - C++ Full Course (Data Types)" date: 2026-08-29

# Kiểu dữ liệu cơ bản (Data Types)

#cpp/kieu-du-lieu #cpp/co-ban #brocode

> [!note] Khái niệm C++ là ngôn ngữ **kiểu tĩnh (statically typed)** — mỗi biến phải được khai báo với một kiểu dữ liệu cụ thể, và kiểu đó ==quyết định loại giá trị nào biến được phép chứa==. Đây là 5 kiểu cơ bản hay gặp nhất.

## 1. `int` — số nguyên

```cpp
int x;
x = 5;
std::cout << x << std::endl;
```

- Có thể khai báo trước (`int x;`) rồi gán giá trị sau (`x = 5;`) — khác với `const`, `int` thường **không bắt buộc** phải gán ngay lúc khai báo.
- <span style="color:#61afef">Không lưu được phần thập phân</span> — `int` chỉ chứa số nguyên.

## 2. `double` — số thực (có phần thập phân)

```cpp
double price = 10.99;
double temperature = 30.5;
double gpa = 9.3;
```

Dùng khi cần độ chính xác thập phân: giá tiền, nhiệt độ, điểm GPA...

> [!example] Ví dụ thực tế — đổi độ F sang độ C
> 
> ```cpp
> int Fahrenheit = 70;
> double Celsius = (Fahrenheit - 32) / 1.8;
> std::cout << Celsius << std::endl;
> ```
> 
> Chú ý phép chia `/ 1.8` — vì `1.8` là số thập phân nên kết quả tự động được tính ra `double`, dù `Fahrenheit` là `int`. Đây là ví dụ điển hình cho việc **trộn kiểu dữ liệu trong 1 biểu thức**.

## 3. `char` — một ký tự đơn

```cpp
char grade = 'A';
char initial = 'B';
char currency = '$';
```

> [!warning] Cạm bẫy thường gặp `char` chỉ chứa **đúng 1 ký tự**, và phải dùng ==nháy đơn `' '`== (không phải nháy kép `" "`). Viết `char grade = "A";` sẽ báo lỗi:
> 
> ```
> error: invalid conversion from 'const char*' to 'char' [-fpermissive]
> ```
> 
> Vì `"A"` được compiler hiểu là chuỗi (string) — tức một con trỏ `const char*` — chứ không phải 1 ký tự đơn.

## 4. `bool` — đúng/sai

```cpp
bool student = false;
bool power = true;
bool forSale = true;
```

Chỉ nhận 1 trong 2 giá trị: `true` hoặc `false` — dùng cho các trạng thái bật/tắt, có/không.

## 5. `std::string` — chuỗi văn bản

```cpp
std::string name = "Minh Tuan";
std::string day = "Friday";
std::string age = "13";
std::string lopHoc = "8A5";

std::cout << "Hello " << name << std::endl;
std::cout << "You're " << age << std::endl;
```

- `string` không phải kiểu nguyên thủy (primitive) như 4 kiểu trên — nó là một **object**, đại diện cho một chuỗi ký tự, dùng nháy kép `" "`.
- Cần `#include <string>` (hoặc thường đã có sẵn qua `<iostream>` tuỳ trình biên dịch, nhưng include tường minh vẫn là thói quen tốt).

> [!tip] Mẹo Ở ví dụ trên, `age` được khai báo là `std::string age = "13";` — <span style="color:#d19a66">lưu số dưới dạng chuỗi thì không tính toán được</span> (`age + 1` sẽ không cộng ra `14`). Nếu tuổi cần dùng để tính toán (ví dụ tính năm sinh), nên khai báo là `int age = 13;` thay vì string — thử ngay ở phần Tự luyện bên dưới.

## Tóm tắt nhanh

|Kiểu|Chứa gì|Ví dụ giá trị|Ký hiệu nháy|
|---|---|---|---|
|`int`|Số nguyên|`5`|không cần|
|`double`|Số thực (thập phân)|`10.99`|không cần|
|`char`|1 ký tự|`'A'`|nháy đơn `' '`|
|`bool`|true / false|`true`|không cần|
|`std::string`|Chuỗi văn bản|`"Minh Tuan"`|nháy kép `" "`|

## ✅ Đã tự luyện (buổi ôn 29/08)

1. Khai báo `int age = 13;` rồi in `age + 1` → ra `14`, xác nhận `int` tính toán được còn `string` thì không.
2. Thử gán `char grade = "A";` (nháy kép) → compiler báo đúng lỗi `invalid conversion from 'const char*' to 'char'` như dự đoán ở phần Cạm bẫy.
3. Bài Fahrenheit → Celsius: `(Fahrenheit - 32) / 1.8` → minh hoạ việc trộn `int` với hằng số thập phân ra kết quả `double`.

> [!question] Tự luyện tiếp theo
> 
> 1. Sửa công thức Celsius → Fahrenheit ngược lại: `Fahrenheit = Celsius * 1.8 + 32`, thử với `Celsius = 25`.
> 2. Khai báo `int lopHoc = 8;` và `char khoi = 'A';` (tách `"8A5"` thành 2 biến riêng) thay vì gộp chung 1 string — so sánh cách nào hợp lý hơn khi cần xử lý số/ký tự riêng lẻ.