---
tags: [cpp, brocode, competitive-programming]
source: "Codeforces 339A - Helpful Maths (tự giải, tra std::sort trên StackOverflow)"
date: 2026-10-11
---

# Sắp xếp mảng (`std::sort`)

#cpp/sort #cpp/vector #cpp/co-ban #competitive-programming

> [!note] Khái niệm
> `std::sort` (thư viện `<algorithm>`) sắp xếp các phần tử trong một khoảng `[first, last)` bằng **iterator**. Mặc định là **tăng dần**. Có thể truyền thêm một *comparator* như `std::greater<>()` để đổi thứ tự so sánh.

## Bài toán: Helpful Maths (CF 339A)

Cho chuỗi tổng như `3+2+1`, chỉ chứa số `1`, `2`, `3` và dấu `+`. Sắp xếp các số tăng dần rồi in lại: `1+2+3`.

## Code của mình

```cpp
#include <bits/stdc++.h>
#include <cctype>

int main() {
    std::string calculation;
    std::cin >> calculation;

    std::vector<char> toNumber = {};

    for (int i : calculation) {
        if (isdigit(i)) {          // bỏ dấu '+', giữ chữ số
            toNumber.push_back(i);
        }
    }

    std::sort(toNumber.rbegin(), toNumber.rend(), std::greater<>());

    for (int i = 0; i < toNumber.size() - 1; i++) {
        std::cout << toNumber[i] << "+";
    }
    std::cout << toNumber.back();  // thay cho [-1]
    return 0;
}
```

### Giải thích từng bước

1. `isdigit(i)` lọc ra ==chỉ các chữ số==, tự bỏ qua `'+'`. Mảng `toNumber` chứa các **ký tự** `'1'`, `'2'`, `'3'`.
2. Dòng `std::sort(rbegin, rend, std::greater<>())` là chỗ hay ho nhất, xem bên dưới.
3. Vòng `for` in mỗi phần tử kèm `+`, **trừ phần tử cuối** được in riêng bằng `.back()` để không bị dư dấu `+`.

### Dòng sort này thực chất làm gì?

- `rbegin()`/`rend()` là iterator **đảo ngược** (duyệt từ cuối về đầu).
- `std::greater<>()` bảo sort xếp **giảm dần** trên cái nhìn đảo ngược đó.
- <span style="color:#61afef">Giảm dần khi nhìn ngược = tăng dần khi nhìn xuôi</span>, nên kết quả cuối cùng vẫn là **tăng dần**. Chạy đúng, nhưng vòng vèo 🌀

> [!tip] Cách gọn hơn
> Chỉ cần sort bình thường là đã tăng dần:
> ```cpp
> std::sort(toNumber.begin(), toNumber.end());
> ```
> Muốn giảm dần thì mới dùng `std::sort(v.begin(), v.end(), std::greater<>());`

> [!warning] Cạm bẫy thường gặp
> - <span style="color:#e06c75">C++ không có `v[-1]` như Python.</span> `-1` bị đổi thành số khổng lồ (`size_t`), truy cập ngoài mảng, dính assertion `__n < this->size()`. Dùng `v.back()` hoặc `v[v.size() - 1]`.
> - `v.size()` trả về `size_t` (số không dấu). Mảng rỗng thì `v.size() - 1` tràn thành số cực lớn. Nên ép `(int)v.size() - 1` để an toàn.
> - Input chỉ có **một số** (ví dụ `2`) là case biên. Vòng `for` không chạy, chỉ còn dòng `.back()` nên vẫn đúng ✅

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `std::sort(v.begin(), v.end())` | Sắp xếp tăng dần, cần `<algorithm>` |
| `std::greater<>()` | Comparator để sắp xếp giảm dần |
| `v.back()` | Phần tử cuối, thay cho `v[-1]` của Python |
| `isdigit(c)` | Kiểm tra ký tự có phải chữ số, thuộc `<cctype>` |
| In danh sách có dấu phân cách | In `+` sau mỗi phần tử trừ phần tử cuối (hoặc in `+` trước mỗi phần tử trừ phần tử đầu) |

> [!question] Tự luyện
> 1. Viết lại bài này **không dùng** `rbegin()/rend()`, chỉ dùng `begin()/end()`.
> 2. Thử đếm số lần xuất hiện của `1`, `2`, `3` (counting) thay cho `sort`, rồi in kết quả. Cách nào nhanh hơn khi chuỗi dài?
> 3. Sửa chương trình để in **giảm dần**: `3+2+1`.

Liên quan: [[CPP - Vòng lặp for (For Loops)]] · [[CPP - std::string methods]]
