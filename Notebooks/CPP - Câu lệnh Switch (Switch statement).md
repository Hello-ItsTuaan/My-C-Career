---

## tags: [cpp, brocode] source: "BroCode - Switch Statements" date: 2026-09-04

# Câu lệnh switch (`switch`)

#cpp/switch #cpp/co-ban #brocode

> [!note] Khái niệm `switch` là cách thay thế cho một chuỗi dài `else if` — thay vì so sánh nhiều điều kiện, ta so sánh **một giá trị duy nhất** với từng `case` cụ thể. Nó gọn hơn và dễ đọc hơn khi có nhiều nhánh giá trị rời rạc (số tháng, ký tự điểm số, lựa chọn menu...).

## Cú pháp & Ví dụ

```cpp
int month;
std::cout << "Please enter month (1-12): ";
std::cin >> month;

switch (month) {
    case 1:
        std::cout << "It's January";
        break;
    case 2:
        std::cout << "It's February";
        break;
    // ...
    default:
        std::cout << "Please enter a valid number (1-12)";
}
```

Giá trị trong `switch(...)` chỉ được so khớp với `case` khi kiểu dữ liệu là **số nguyên hoặc ký tự** (`int`, `char`, `enum`...) — không dùng được với `std::string` hay `double`. Đây là lý do ví dụ thứ hai của m dùng `char grade` thay vì `string`.

```cpp
char grade;
std::cin >> grade;

switch (grade) {
    case 'A':
        std::cout << "You did great!";
        break;
    case 'B':
        std::cout << "Nice, try again!";
        break;
    case 'C':
        std::cout << "You need to study harder";
    default:
        std::cout << "Please enter a valid grade!";
}
```

==Mỗi `case` cần một `break` ở cuối, nếu không code sẽ "rơi" (fall-through) xuống case kế tiếp và chạy luôn cả nhánh đó.== Ví dụ code case `'C'` ở trên thiếu `break` → khi nhập `'C'`, chương trình in cả dòng của `case 'C'` **lẫn** dòng `default` luôn, dù không nhập sai gì cả.

> [!warning] Cạm bẫy thường gặp Quên `break` là lỗi kinh điển với `switch`. Không giống `if/else` (chỉ chạy đúng 1 nhánh), `switch` thiếu `break` sẽ <span style="color:#e06c75">chạy tràn xuống các case phía dưới cho đến khi gặp `break` hoặc hết switch</span>. Đây gọi là **fall-through**, đôi khi được dùng cố ý (nhiều case cùng xử lý chung 1 hành động) nhưng nếu không cố ý thì là bug.

> [!question] `break` vs `return` khác nhau thế nào? Cả hai đều có thể "kết thúc" một đoạn code, nhưng khác phạm vi:
> 
> - `break` chỉ thoát khỏi **vòng lặp hoặc switch gần nhất** chứa nó — code sau switch/loop đó vẫn chạy tiếp bình thường.
> - `return` thoát khỏi **toàn bộ hàm** (kể cả `main()`) ngay lập tức, và có thể trả về một giá trị cho nơi gọi hàm (`return 0;`, `return x;`). Nếu dùng `return` bên trong `main()`, chương trình kết thúc luôn vì đã ra khỏi hàm `main`.
> 
> So với Python: `break` trong C++ giống hệt `break` trong Python (thoát loop/switch). `return` cũng giống Python — thoát hàm, có thể trả giá trị hoặc `return;` (return rỗng, giống `return None`). Điểm khác duy nhất là Python không có `switch` (trước Python 3.10 thì hoàn toàn không, từ 3.10 có `match`), nên trong Python m chỉ quen thấy `break` ở vòng lặp thôi.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|Kiểu dữ liệu dùng được|`int`, `char`, `enum` — **không** dùng `string`/`double`|
|`break`|Thoát khỏi `switch`/loop hiện tại, không thoát hàm|
|`return`|Thoát toàn bộ hàm, có thể trả về giá trị|
|Thiếu `break`|Gây fall-through — chạy luôn case phía dưới|
|`default`|Giống `else` — chạy khi không case nào khớp|

> [!question] Tự luyện
> 
> 1. Sửa lại ví dụ `grade` để thêm `break` còn thiếu ở case `'C'`, rồi thử bỏ `break` ở case `'A'` xem console in ra gì khi nhập `'A'`.
> 2. Viết thêm case `'D'` và `'F'` cho bài chấm điểm, mỗi case một câu nhận xét khác nhau.