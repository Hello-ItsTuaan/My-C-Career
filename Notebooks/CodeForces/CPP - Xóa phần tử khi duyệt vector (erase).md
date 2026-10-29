---
tags: [cpp, brocode, competitive-programming]
source: "Codeforces 236A - Boy or Girl (tự giải, tự debug)"
date: 2026-10-11
---

# Xóa phần tử khi đang duyệt (`erase` + loop invariant)

#cpp/vector #cpp/erase #cpp/loop-invariant #competitive-programming

> [!note] Khái niệm
> Khi `erase` một phần tử khỏi `vector`, **các phần tử phía sau dồn sang trái** và `size()` giảm đi 1. Nếu vẫn `j++` như bình thường thì sẽ ==bỏ sót phần tử vừa dồn vào vị trí `j`==.

## Bài toán: Boy or Girl (CF 236A)

Đếm số ký tự **khác nhau** (distinct) trong tên. Số chẵn thì in `CHAT WITH HER!`, số lẻ thì in `IGNORE HIM!`.

## ❌ Code sai ban đầu

```cpp
for (int i = 0; i < eachchar.size(); i++) {
    for (int j = 0; j < eachchar.size(); j++) {
        if (eachchar[i] == eachchar[j]) {
            eachchar.erase(eachchar.begin() + j);
        }
    }
}
```

Có **2 lỗi cùng lúc**:

1. <span style="color:#e06c75">`j` bắt đầu từ 0</span> nên khi `j == i`, phần tử so sánh với **chính nó** (luôn bằng nhau) và tự xóa mình.
2. <span style="color:#e06c75">`j++` sau khi `erase`</span> nên nhảy qua phần tử vừa dồn sang trái.

## ✅ Code đúng

```cpp
// ─── Remove duplicates in place ───
for (int i = 0; i < (int)eachchar.size(); i++) {
    for (int j = i + 1; j < (int)eachchar.size(); ) {  // j = i+1: không so với chính nó
        if (eachchar[i] == eachchar[j]) {
            eachchar.erase(eachchar.begin() + j);      // xóa xong thì KHÔNG j++
        } else {
            j++;
        }
    }
}

if (eachchar.size() % 2 == 0) std::cout << "CHAT WITH HER!";
else                          std::cout << "IGNORE HIM!";
```

> [!important] Quy tắc vàng
> <span style="color:#98c379">Chỉ tăng chỉ số khi KHÔNG xóa.</span> Sau `erase`, phần tử kế tiếp đã tự nằm ở vị trí `j` rồi, cứ để vòng sau kiểm tra nó.

## 🧠 Loop invariant (ý tưởng "big brain")

> [!note] Bất biến vòng lặp
> Ở đầu lượt `i`, mọi ký tự ở vị trí `< i` đều ==đã là duy nhất==, và không còn bản sao nào của chúng phía sau.
>
> Vì mỗi `i'` trước đó đã quét hết phần còn lại và xóa mọi bản sao của chính nó. Do đó **không cần so sánh ngược về phía trước**, chỉ cần `j = i + 1`.

Trace với `aab`:

| Lượt | Hành động | Mảng sau đó |
|---|---|---|
| `i=0` (`a`) | quét phải, thấy `a` thứ 2, xóa | `ab` |
| `i=1` (`b`) | không còn gì phía sau | `ab` |

Kết quả `size() = 2`, chẵn, in `CHAT WITH HER!` ✅

> [!tip] Cách gọn hơn
> Với chuỗi dài hơn (như 10⁵ ký tự) thì O(n²) sẽ TLE. Dùng `std::set<char>` (`set.size()` là số ký tự khác nhau), hoặc `sort` rồi `std::unique`:
> ```cpp
> std::sort(v.begin(), v.end());
> v.erase(std::unique(v.begin(), v.end()), v.end());
> ```

> [!warning] Cạm bẫy thường gặp
> - Chiều chẵn/lẻ rất dễ nhầm: **chẵn là HER**, **lẻ là HIM**.
> - So sánh phần tử với chính nó (`i == j`) luôn đúng, hãy loại trường hợp đó.
> - `size()` trả về `size_t` (không dấu), ép `(int)` khi trừ hoặc so sánh với số âm.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| `erase` dồn phần tử sang trái | Không `j++` ngay sau khi xóa |
| `j = i + 1` | Tránh tự so sánh và tránh làm lại việc thừa |
| Loop invariant | Phần đã duyệt (`< i`) luôn "sạch", không cần kiểm tra lại |
| Độ phức tạp | O(n²), đủ cho n ≤ 100 |
| Cách nhanh hơn | `std::set<char>` hoặc `sort` + `unique` |

> [!question] Tự luyện
> 1. Viết lại bài này bằng `std::set<char>`, chỉ vài dòng thôi.
> 2. Viết lại bằng mảng `bool seen[26]` và `c - 'a'`.
> 3. Tự phát biểu loop invariant của vòng `for` trong bài **Helpful Maths** trước đó. Đúng bài tập luyện tư duy chứng minh vòng lặp 😎

Liên quan: [[CPP - Sắp xếp với std::sort]] · [[CPP - Vòng lặp for (For Loops)]] · [[CPP - std::string methods]]
