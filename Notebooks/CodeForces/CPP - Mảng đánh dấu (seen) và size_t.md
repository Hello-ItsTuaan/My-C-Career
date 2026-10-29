---
tags: [cpp, codeforces, brocode]
source: "Codeforces 271A - Beautiful Year (tự giải)"
date: 2026-10-11
---

# Mảng đánh dấu (`seen[]`) và kiểu `size_t`

#cpp/seen-array #cpp/size_t #codeforces

> [!note] Khái niệm
> **Mảng đánh dấu** (marking / frequency array) là một mảng `bool` nhỏ dùng để trả lời câu hỏi *"giá trị này đã xuất hiện chưa?"* chỉ trong ==O(1)==. Với chữ số thì chỉ cần 10 ô (từ 0 đến 9), mỗi ô tương ứng một chữ số.

## Bài toán: Codeforces 271A

Cho một năm `year`, tìm năm **nhỏ nhất lớn hơn** `year` mà các chữ số đều **khác nhau đôi một**.

Ý tưởng: duyệt tăng dần từ `year + 1`, năm nào có các chữ số phân biệt thì in ra rồi dừng. Đáp án luôn nằm rất gần nên vét cạn là đủ nhanh.

## Cách 1: so sánh từng cặp (bản đầu tiên)

```cpp
bool isDistinct(int year) {
    std::vector<int> separateNums = {};

    while (year > 0) {
        separateNums.push_back(year % 10);   // tách từng chữ số
        year /= 10;
    }

    for (size_t i = 0; i < separateNums.size(); i++) {
        for (size_t j = i + 1; j < separateNums.size(); j++) {
            if (separateNums[i] == separateNums[j]) return false;
        }
    }
    return true;
}
```

Đúng, nhưng phải tạo `vector` và dùng **2 vòng for lồng nhau** (độ phức tạp ==O(k²)== với k là số chữ số).

## Cách 2: mảng `seen[]` (bản nâng cấp)

```cpp
bool isDistinct(int year) {
    bool seen[10] = {false};     // seen[d] = chữ số d đã gặp chưa?

    while (year > 0) {
        int d = year % 10;           // lấy chữ số cuối
        if (seen[d]) return false;   // gặp lần 2 => trùng
        seen[d] = true;              // đánh dấu đã gặp
        year /= 10;                  // bỏ chữ số cuối
    }
    return true;
}
```

Chỉ **1 vòng while**, không cần vector, và độ phức tạp giảm còn ==O(k)==.

> [!example] Chạy thử
> | Năm | Các chữ số lấy ra | Kết quả |
> |---|---|---|
> | 1987 | 7, 8, 9, 1 | <span style="color:#98c379">true</span> (không trùng) |
> | 2013 | 3, 1, 0, 2 | <span style="color:#98c379">true</span> |
> | 1000 | 0, 0, ... | <span style="color:#e06c75">false</span> (`seen[0]` đã `true`) |

## Chương trình hoàn chỉnh

```cpp
#include <bits/stdc++.h>

bool isDistinct(int year) {
    bool seen[10] = {false};
    while (year > 0) {
        int d = year % 10;
        if (seen[d]) return false;
        seen[d] = true;
        year /= 10;
    }
    return true;
}

int main() {
    int year = 0;
    std::cin >> year;

    for (int i = year + 1; ; i++) {      // lặp đến khi tìm được
        if (isDistinct(i)) {
            std::cout << i;
            return 0;
        }
    }
}
```

> [!tip] Mẹo
> Pattern "mảng đánh dấu đã thấy" xuất hiện cực nhiều trong CP: kiểm tra trùng lặp, đếm tần suất, đánh dấu đã thăm. Chỉ cần nhớ: ==giá trị nhỏ thì dùng chính nó làm chỉ số mảng==.

## `size_t` là gì?

`size_t` là kiểu số nguyên <span style="color:#61afef">**không dấu**</span> (unsigned), là kiểu mà `.size()` của `vector` và `string` trả về. Vì kích thước thì không thể âm.

```cpp
for (size_t i = 0; i < v.size(); i++) { ... }   // đúng kiểu, không bị warning
for (int i = 0; i < v.size(); i++) { ... }      // chạy được, nhưng compiler cảnh báo signed/unsigned
```

> [!warning] Cạm bẫy: duyệt ngược với `size_t`
> ```cpp
> std::vector<int> v = {};
> for (size_t i = v.size() - 1; i >= 0; i--) { ... }
> ```
> Với số không dấu, `0 - 1` **không ra -1** mà "quay vòng" thành một số cực lớn. Điều kiện `i >= 0` thì <span style="color:#e06c75">luôn đúng</span>, nên vòng lặp chạy vô hạn hoặc crash. Khi duyệt ngược, hãy dùng `int` và ép kiểu: `for (int i = (int)v.size() - 1; i >= 0; i--)`.

## Các điểm nhỏ rút ra từ bài này

- Hàm tên `isDistince` bị sai chính tả, đúng là `isDistinct` (distinct = phân biệt).
- Nhánh `if (year == 0)` là thừa vì đề đảm bảo `year >= 1000`.
- Vòng lặp `i <= INT_MAX` nên viết `for (int i = year + 1; ; i++)` cho trung thực với ý đồ "lặp đến khi tìm thấy".

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `bool seen[10] = {false};` | Khởi tạo cả 10 ô là `false` |
| Kiểm tra rồi mới đánh dấu | `if (seen[d]) return false; seen[d] = true;` |
| Độ phức tạp | Từ O(k²) (so cặp) xuống O(k) (seen[]) |
| `size_t` | Kiểu không dấu, trả về bởi `.size()` |
| Duyệt ngược | Không dùng `size_t` với điều kiện `>= 0` |

> [!question] Tự luyện
> 1. Sửa hàm để kiểm tra một chuỗi `std::string` có toàn ký tự **khác nhau** không (gợi ý: mảng `seen[26]`, dùng `c - 'a'` làm chỉ số).
> 2. Viết hàm đếm **có bao nhiêu chữ số khác nhau** trong một số nguyên (gợi ý: đếm số ô `true` trong `seen`).

Liên quan: [[CPP - Vòng lặp for (for loops)]] · [[CPP - Truyền mảng vào hàm]] · [[CPP - Chuỗi (std::string)]]
