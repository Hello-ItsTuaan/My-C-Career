---
tags: [cpp, codeforces, thuat-toan]
source: "Codeforces 136A - Presents"
date: 2026-10-25
---

# Hoán vị nghịch đảo (Inverse Permutation) - bài `Presents`

#cpp/hoan-vi #cpp/codeforces #cpp/vector

> [!note] Đề bài nói gì?
> Có **n** bạn, bạn `i` tặng quà cho bạn `p[i]`. Mỗi người nhận đúng 1 món quà nên `p` là một ==hoán vị của 1..n==. Yêu cầu: với mỗi bạn `i`, in ra **ai đã tặng quà cho bạn `i`**.

## Hiểu Input / Output

```
Input:
4
2 3 4 1

Output:
4 1 2 3
```

- Dòng 1 (`4`): có 4 người bạn.
- Dòng 2 (`2 3 4 1`): ==vị trí của số = người tặng, giá trị của số = người nhận==.
  - Bạn 1 tặng bạn 2, bạn 2 tặng bạn 3, bạn 3 tặng bạn 4, bạn 4 tặng bạn 1.
- Output hỏi ngược lại: bạn 1 nhận từ ai (bạn 4), bạn 2 nhận từ ai (bạn 1), ... → `4 1 2 3`.

> [!tip] Mẹo nhớ
> Input nói <span style="color:#61afef">"mình tặng cho ai"</span>, output hỏi <span style="color:#98c379">"mình nhận từ ai"</span>. Chỉ là **đổi góc nhìn**, số liệu vẫn y nguyên.

## Cách của mình (tự nghĩ ra, không dùng Google/AI)

Ý tưởng: muốn biết ai tặng cho bạn `v`, thì **tìm xem số `v` nằm ở vị trí nào** trong dãy `p`. Vị trí đó chính là người tặng.

```cpp
#include <bits/stdc++.h>

int main() {
    int soBan;
    std::cin >> soBan;

    std::vector<int> banDuocTang = {};
    std::vector<int> banDuocTangLonDan = {};

    for (int i = 0; i < soBan; i++) {
        int temp;
        std::cin >> temp;
        banDuocTang.push_back(temp);
    }

    banDuocTangLonDan = banDuocTang;
    std::sort(banDuocTangLonDan.begin(), banDuocTangLonDan.end());

    for (int i = 0; i < banDuocTang.size(); i++) {
        int index = 0;
        for (int j = 0; j < banDuocTang.size(); j++) {
            index++;
            if (banDuocTang[j] == banDuocTangLonDan[i]) {
                std::cout << index << " ";
            }
        }
    }

    return 0;
}
```

Giải thích nhanh:

1. Đọc `p` vào `banDuocTang`.
2. Copy sang `banDuocTangLonDan` rồi `sort` → luôn ra `1 2 3 ... n`.
3. Với mỗi giá trị `v` (từ 1 đến n), duyệt `banDuocTang` tìm `v`, ==in ra vị trí (đánh số từ 1)==.

> [!example] Chạy tay ví dụ 1
> `p = 2 3 4 1`, sort ra `1 2 3 4`.
> - Giá trị 1 nằm ở vị trí 4 → in `4`
> - Giá trị 2 nằm ở vị trí 1 → in `1`
> - Giá trị 3 nằm ở vị trí 2 → in `2`
> - Giá trị 4 nằm ở vị trí 3 → in `3`
>
> Kết quả `4 1 2 3` ✅

> [!warning] Cạm bẫy thường gặp
> - Đề đánh số bạn từ **1**, còn vector đánh index từ **0** → dễ lệch 1. Biến `index` ở trên chính là `j + 1`.
> - <span style="color:#d19a66">`i < banDuocTang.size()`</span> so sánh `int` với `size_t`, compiler có thể nhắc nhẹ (xem [[CPP - Mảng đánh dấu (seen) và size_t]]).
> - Trường hợp `p[i] = i` (tự tặng cho mình) không cần xử lý riêng, code vẫn đúng.

## Nhận xét về cách làm

| Điểm | Nhận xét |
|---|---|
| Độ phức tạp | O(n²) vì 2 vòng for lồng nhau. Với n ≤ 100 chỉ ~10.000 phép tính, dư sức qua 2 giây |
| Đoạn `sort` | Hơi thừa: vì `p` là hoán vị của 1..n, sort xong luôn là `1..n`. Chỉ cần một biến chạy từ 1 đến n |
| Biến `index` | Hợp lý, nhưng bằng `j + 1` nên có thể bỏ |
| Kết luận | ==Đúng, qua ví dụ==. Chỉ cần gọn hơn |

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Dạng bài | Hoán vị nghịch đảo: đảo chiều mũi tên "i tặng p[i]" |
| Đọc input | Vị trí = người tặng, giá trị = người nhận |
| Cách tìm kiếm (của mình) | Tìm giá trị `v` nằm ở vị trí nào, O(n²) |
| Hướng tối ưu | Vừa đọc vừa ghi sổ ngược, O(n) (tự nghĩ thử bên dưới) |
| Cảm nhận | Mất ~1 tiếng khi mới quay lại luyện thuật toán là **bình thường** |

> [!question] Tự luyện
> 1. Thử viết lại bài này **không dùng `sort` và không dùng mảng thứ hai**, chỉ dùng một biến chạy từ 1 đến n.
> 2. Thử nghĩ cách đạt O(n): khi vừa đọc "bạn `i` tặng bạn `p`", ta có thể ghi lại điều gì ngay lúc đó để khỏi phải tìm kiếm sau?
> 3. Tự điền ví dụ 3 (`2` / `1 2`) bằng tay rồi đối chiếu với đáp án.

> [!quote] Ghi chú cá nhân
> Từ "I am uncomfortable" (không hiểu gì) đến tự giải được bằng cách mình thật sự hiểu. Cảm giác này quý hơn việc bài được AC. Mục tiêu tiếp theo: [[CPP - Bài Beautiful Matrix (CF 263A)]].
