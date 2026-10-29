---
tags: [cpp, brocode]
source: "BroCode - Vòng lặp for (áp dụng qua Codeforces 282A, 158A)"
date: 2026-09-14
---

# Vòng Lặp `for` — Áp Dụng Qua Bài Tập Thực Tế

#cpp/loop #cpp/co-ban #brocode

> [!note] Khái niệm
> `for` dùng khi biết trước **số lần cần lặp lại** một khối lệnh — ví dụ
> đọc `n` dòng input, hoặc duyệt qua từng phần tử trong mảng/vector.
> Cú pháp: `for (khởi_tạo; điều_kiện; bước_nhảy) { ... }`. Ba phần chạy
> theo thứ tự: khởi tạo (1 lần duy nhất) → kiểm tra điều kiện → chạy
> thân loop → chạy bước nhảy → quay lại kiểm tra điều kiện, lặp lại tới
> khi điều kiện `false`.

## Cú pháp & Ví dụ — bài Bit++ (282A)

```cpp
#include <iostream>
#include <string>

int main() {
    int result = 0;
    int loop;
    std::string input;

    std::cin >> loop;

    for (int i = 0; i < loop; i++) {
        std::cin >> input; // đọc input MỚI ở mỗi vòng lặp
        if (input == "X++" || input == "++X") {
            result += 1;
        } else if (input == "X--" || input == "--X") {
            result -= 1;
        }
    }

    std::cout << result;
    return 0;
}
```

`i` chỉ là **biến đếm số lần lặp**, không mang ý nghĩa gì khác ngoài việc
kiểm soát vòng lặp chạy đúng `loop` lần — ==tuyệt đối không dùng `i` để
đại diện cho giá trị dữ liệu thật (điểm số, index cần tra)== nếu không
sẽ bị lẫn lộn giữa "vị trí" và "giá trị", lỗi rất hay gặp khi mới học.

Kết hợp với **vector** (dùng để lưu nhiều giá trị cùng loại) khi biết
trước số lượng phần tử — bài 158A (Next Round):

```cpp
std::vector<int> arr_numbers(n); // tạo sẵn n phần tử, khởi tạo = 0
for (int i = 0; i < n; i++) {
    std::cin >> arr_numbers[i]; // đọc thẳng vào từng vị trí i
}
```

> [!tip] Mẹo
> Khi số lượng phần tử `n` đã biết trước (đọc được từ input), khai báo
> <span style="color:#61afef">`std::vector<int> arr(n)`</span> ngay từ
> đầu rồi gán bằng `arr[i]` trong loop — gọn hơn `push_back()` nhiều.

> [!warning] Cạm bẫy thường gặp khi mới học loop
> 1. **Quên đọc input mới trong loop** — khai báo biến (`std::string
>    input;`) ở ngoài xong quên đặt `std::cin >> input;` bên trong thân
>    `for`, dẫn tới biến giữ giá trị cũ (hoặc rỗng) suốt cả vòng lặp.
> 2. **Lẫn lộn index `i` với giá trị dữ liệu** — ví dụ so sánh
>    `if (i < miniumRequirement)` trong khi đáng lẽ phải so
>    `arr_numbers[i] >= miniumRequirement`. `i` là **vị trí**, còn giá
>    trị thật nằm trong `arr_numbers[i]`.
> 3. **Off-by-one khi tra "hạng thứ k"** — mảng bắt đầu từ index 0, nên
>    hạng thứ `k` nằm ở `arr[k - 1]`, không phải `arr[k]`.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `for (init; cond; step)` | init chạy 1 lần, cond check mỗi vòng, step chạy sau mỗi vòng |
| `i` trong loop | chỉ là biến đếm, không phải giá trị dữ liệu |
| `std::vector<int> arr(n)` | tạo sẵn n phần tử = 0, gán bằng `arr[i]` |
| Hạng thứ `k` | nằm ở index `k - 1` (do mảng bắt đầu từ 0) |
| Đọc input trong loop | luôn đặt `std::cin >> ...` bên trong thân `for` nếu cần giá trị mới mỗi vòng |

> [!question] Tự luyện
> 1. Viết lại bài Next Round (158A) nhưng thử dùng `while` loop thay vì
>    `for` — kết quả logic phải giống hệt.
> 2. Cho một vector số nguyên, viết loop đếm xem có bao nhiêu phần tử
>    là số chẵn (dùng `% 2 == 0`), tự tạo input để test.
