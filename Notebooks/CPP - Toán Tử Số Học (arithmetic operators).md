---

## tags: [cpp, brocode] source: "BroCode - Arithmetic Operators" date: 2026-08-31

# Toán tử số học (`Arithmetic Operators`)

#cpp/arithmetic #cpp/co-ban #brocode

> [!note] Khái niệm Toán tử số học dùng để thực hiện các phép tính toán học cơ bản trên biến số: cộng, trừ, nhân, chia, và lấy phần dư (modulo). Thứ tự ưu tiên tính toán tuân theo quy tắc toán học quen thuộc: ==ngoặc đơn → nhân/chia → cộng/trừ== (giống PEMDAS/BODMAS).

## Cú pháp & Ví dụ

```cpp
#include <iostream>

int main() {
    int students = 20;

    students += 1;   // cộng dồn (tương đương students = students + 1;)
    students -= 1;   // trừ dồn (tương đương students = students - 1;)
    students *= 2;   // nhân dồn (tương đương students = students * 2;)
    students /= 3;   // chia dồn (tương đương students = students / 3;)

    int remainder = students % 3; // lấy phần dư của phép chia
    std::cout << "Remainder: " << remainder << std::endl;
    std::cout << students << std::endl;
    return 0;
}
```

Vì `students` là kiểu `int`, phép chia `/` sẽ là **chia lấy nguyên** (integer division) — phần thập phân bị cắt bỏ chứ không làm tròn. Đây là lý do output là số nguyên; nếu khai báo `double students = 20;` thay vì `int`, kết quả sẽ giữ lại phần thập phân đầy đủ.

<span style="color:#61afef">Toán tử gán rút gọn</span> (`+=`, `-=`, `*=`, `/=`) là cách viết ngắn gọn hơn cho `x = x <phép_toán> y`, giúp code gọn và dễ đọc hơn khi cập nhật giá trị của chính biến đó.

> [!tip] Mẹo Toán tử `%` (modulo) chỉ hoạt động với số nguyên (`int`), không dùng được trực tiếp với `double`/`float`. Rất hữu ích để kiểm tra tính chẵn/lẻ (`x % 2 == 0`) hoặc chia đều dữ liệu vào các nhóm.

> [!warning] Cạm bẫy thường gặp Cú pháp <span style="color:#e06c75">`students ++1;`</span> và <span style="color:#e06c75">`students -- 1;`</span> đều **sai cú pháp**, không biên dịch được. Toán tử tăng/giảm 1 đơn vị đúng phải là:
> 
> - `students++;` hoặc `++students;` (tăng 1)
> - `students--;` hoặc `--students;` (giảm 1)
> 
> Không có khoảng trắng và không viết `++1`/`--1` như một biểu thức riêng — `++`/`--` là toán tử gắn liền với biến, không phải phép cộng/trừ với số 1 viết tách rời.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|Thứ tự ưu tiên|`()` → `*` `/` `%` → `+` `-`|
|`int / int`|Chia lấy nguyên, mất phần thập phân|
|`%` (modulo)|Chỉ dùng với số nguyên, lấy phần dư|
|`+=`, `-=`, `*=`, `/=`|Toán tử gán rút gọn, viết ngắn gọn cho phép gán lại|
|`x++` / `x--`|Tăng/giảm 1 đơn vị — không viết `++1` hay `-- 1`|

> [!question] Tự luyện
> 
> 1. Đổi `int students` thành `double students` rồi chạy lại `students /= 3;` — quan sát sự khác biệt về kết quả so với dùng `int`.
> 2. Viết thêm một biến `int total = 17;` và tính `total % 5`, dự đoán kết quả trước khi chạy code để kiểm tra hiểu biết về modulo.