---

## tags: [cpp, brocode] source: "BroCode - Math Functions (max, min, cmath)" date: 2026-09-02

# Hàm Toán Học Cơ Bản (`max`, `min`, `cmath`)

#cpp/math #cpp/co-ban #brocode

> [!note] Khái niệm C++ có sẵn một đống hàm toán học "xịn" khỏi cần tự viết. `std::max` và `std::min` (nằm trong `<algorithm>`, dùng được kể cả không include vẫn chạy vì BroCode hay include chung với `<iostream>`) dùng để lấy giá trị lớn nhất/nhỏ nhất giữa 2 số. Còn thư viện `<cmath>` thì cho cả rổ hàm: `pow` (lũy thừa), `abs` (trị tuyệt đối), `sqrt` (căn bậc 2), `round`/`ceil`/`floor` (làm tròn theo 3 kiểu khác nhau). ==Nhớ include đúng thư viện thì hàm mới chịu chạy==, không lọ chéo là toang.

## Cú pháp & Ví dụ

```cpp
#include <iostream>
#include <cmath>

int main() {
    double x = 3.99;
    double y = 4;
    double z;

    z = std::max(x, y);   // 4
    z = std::min(x, y);   // 3.99

    z = pow(2, 3);   // 2^3 = 8
    z = pow(2, 4);   // 2^4 = 16
    z = abs(-3);     // 3
    z = sqrt(9);      // 3
    z = round(x);    // 4  (làm tròn gần nhất)
    z = ceil(x);      // 4  (luôn làm tròn LÊN)
    z = floor(x);     // 3  (luôn làm tròn XUỐNG)

    std::cout << z;

    return 0;
}
```

Giải thích nhanh từng hàm:

- `std::max(x, y)` / `std::min(x, y)` — so sánh 2 giá trị, trả về cái lớn hơn/nhỏ hơn. Có thể dùng `max`/`min` không cần `std::` nếu đã `using namespace std;`.
- `pow(cơ_số, số_mũ)` — tính lũy thừa. `pow(2, 3)` là 2³ chứ không phải 3².
- `abs(số)` — trị tuyệt đối, luôn ra số dương.
- `sqrt(số)` — căn bậc 2. Truyền số âm vào là auto lỗi domain (NaN), <span style="color:#e06c75">không có phép tính ra số ảo đâu nha</span>.
- Bộ 3 làm tròn hay bị nhầm nhất:
    - `round(3.99)` → 4 (làm tròn theo quy tắc thông thường)
    - `ceil(3.99)` → 4 (luôn ngóc lên trên, kể cả 3.01 cũng thành 4)
    - `floor(3.99)` → 3 (luôn cắm đầu xuống dưới, kể cả 3.99 cũng thành 3)

> [!warning] Cạm bẫy thường gặp — quả LỌ trong chính code của m nè 🫵 Đoạn code gốc m gửi khai báo `double z;` rồi để tất cả các dòng gán `z = ...` bị comment hết, xong `std::cout << z;` vẫn chạy ngon 😭. Đây là **uninitialized variable** — biến chưa được gán giá trị mà đem đi in ra, kết quả là rác bộ nhớ (garbage value), lúc chạy ra số gì cũng được, hên xui. Nhớ chỉ được **uncomment đúng 1 dòng** mỗi lần test thôi, không là in ra 1 con số ất ơ nào đó rồi lại tưởng code m sai 🤡.

> [!tip] Mẹo Muốn test nhiều hàm cùng lúc mà không sợ giẫm chân nhau (biến `z` bị ghi đè liên tục), tạo hẳn nhiều biến riêng: `double zMax, zPow, zSqrt;` — in từng cái ra cho rõ ràng, đỡ phải comment/uncomment tới lui.

## Tóm tắt nhanh

|Hàm|Thư viện|Công dụng|Ví dụ|
|---|---|---|---|
|`std::max(a, b)`|`<algorithm>`|Lấy giá trị lớn hơn|`max(3, 4)` → 4|
|`std::min(a, b)`|`<algorithm>`|Lấy giá trị nhỏ hơn|`min(3, 4)` → 3|
|`pow(a, b)`|`<cmath>`|Lũy thừa a^b|`pow(2, 3)` → 8|
|`abs(a)`|`<cmath>`|Trị tuyệt đối|`abs(-3)` → 3|
|`sqrt(a)`|`<cmath>`|Căn bậc 2|`sqrt(9)` → 3|
|`round(a)`|`<cmath>`|Làm tròn gần nhất|`round(3.99)` → 4|
|`ceil(a)`|`<cmath>`|Làm tròn LÊN|`ceil(3.01)` → 4|
|`floor(a)`|`<cmath>`|Làm tròn XUỐNG|`floor(3.99)` → 3|

> [!question] Tự luyện
> 
> 1. Viết code tính xem trong 3 số `a, b, c` số nào lớn nhất bằng cách lồng 2 lần `std::max`.
> 2. Cho `double price = 49.999;`, in ra giá đã làm tròn lên tới hàng đơn vị bằng `ceil` — thử xem kết quả có giống `round` không, tại sao lại khác nhau?