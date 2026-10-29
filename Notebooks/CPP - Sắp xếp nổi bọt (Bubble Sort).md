---
tags: [cpp, brocode]
source: "BroCode - Bubble Sort (tự viết hàm sort)"
date: 2026-10-14
---

# Sắp xếp nổi bọt (`Bubble Sort`)

#cpp/sort #cpp/mang #brocode

> [!note] Khái niệm
> **Bubble Sort** là thuật toán sắp xếp đơn giản nhất: lặp đi lặp lại việc <span style="color:#61afef">so sánh 2 phần tử đứng cạnh nhau</span>, nếu chúng sai thứ tự thì **đổi chỗ (swap)**. Sau mỗi lượt duyệt, phần tử lớn nhất "nổi" dần về cuối mảng như bọt khí nổi lên mặt nước — nên mới có tên *nổi bọt*.

## Cú pháp & Ví dụ

```cpp
#include <bits/stdc++.h>

void sort(int array[], int size);

int main() {
    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size);

    for (int element : array) {
        std::cout << element << " ";
    }

    return 0;
}

void sort(int array[], int size) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
```

### Đọc code theo 3 tầng

1. **Vòng ngoài `i`** — quyết định *số lượt duyệt*. Mỗi lượt đưa được ít nhất 1 phần tử lớn nhất về đúng chỗ ở cuối. Có `size` phần tử thì cần tối đa `size - 1` lượt.
2. **Vòng trong `j`** — đi từ đầu đến cuối mảng, mỗi bước nhìn cặp `(array[j], array[j+1])`.
3. **Khối `if`** — nếu cặp đó <span style="color:#e06c75">đang đứng sai thứ tự</span> (trái > phải) thì hoán đổi bằng biến tạm `temp`.

> [!important] Swap phải có biến tạm
> `array[j] = array[j+1]; array[j+1] = array[j];` là **sai** — dòng đầu đã ghi đè mất giá trị cũ của `array[j]`. Phải cất vào `temp` trước: ==temp = a → a = b → b = temp==.

### Chạy tay 2 lượt đầu (mảng gốc `10 1 9 2 8 3 7 4 6 5`)

| Lượt | Điều xảy ra | Mảng sau lượt |
|---|---|---|
| `i = 0` | `10` bị đẩy swap liên tục từ đầu đến cuối (so với 1, 9, 2, 8, 3, 7, 4, 6, 5 đều lớn hơn) | `1 9 2 8 3 7 4 6 5 `**`10`** |
| `i = 1` | `9` làm tương tự, nổi đến sát `10` | `1 2 8 3 7 4 6 5 `**`9 10`** |
| ... | cứ thế, mỗi lượt chốt thêm 1 phần tử ở cuối | ... |
| xong | không còn cặp nào sai thứ tự | `1 2 3 4 5 6 7 8 9 10` |

> [!tip] Tối ưu nhỏ: `size - 1 - i`
> Sau `i` lượt thì `i` phần tử cuối đã đúng chỗ rồi, vòng trong không cần đụng vào nữa:
> ```cpp
> for (int j = 0; j < size - 1 - i; j++) {
> ```
> Code gốc của BroCode vẫn đúng, chỉ là so sánh thừa. Đây là cách ==giảm khoảng một nửa số phép so sánh==.

> [!tip] Vì sao `j < size - 1` mà không phải `j < size`?
> Vì trong thân vòng lặp có `array[j+1]`. Nếu `j` chạy đến `size - 1` thì `j+1 = size` → <span style="color:#e06c75">đọc ra ngoài mảng (out of bounds)</span>.

> [!warning] Cạm bẫy thường gặp
> - Hàm tự đặt tên `sort` dễ trùng với `std::sort` nếu sau này thêm `using namespace std;`. Nên đặt `bubbleSort` cho an toàn.
> - `sizeof(array)/sizeof(array[0])` **chỉ đúng trong `main()`** (nơi mảng còn nguyên là mảng). Vào trong hàm, `int array[]` thực chất chỉ là con trỏ, nên mới phải truyền `size` vào như tham số.
> - Mảng được truyền vào hàm là <span style="color:#d19a66">truyền theo địa chỉ</span>, nên hàm `sort` sửa trực tiếp mảng của `main` — không cần `return`.

## Liên hệ với bài loại phần tử trùng lặp

Cả hai bài đều là **vòng lặp lồng nhau trên mảng**, nhưng làm việc khác nhau:

| | Loại phần tử trùng | Bubble Sort |
|---|---|---|
| Vòng trong so sánh | 1 phần tử với *mọi* phần tử còn lại | 2 phần tử *liền kề* |
| Hành động | xoá / đánh dấu phần tử trùng | swap nếu sai thứ tự |
| Độ phức tạp | O(n²) | O(n²) |

Nếu thấy rối, hãy tự hỏi: **"vòng trong đang so sánh cái gì với cái gì?"** — hiểu được câu này là hiểu được thuật toán.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Ý tưởng | so sánh cặp liền kề, sai thứ tự thì swap |
| Sau mỗi lượt | phần tử lớn nhất còn lại nổi về cuối |
| Số lượt ngoài | `size - 1` |
| Swap | luôn cần biến `temp` (hoặc `std::swap`) |
| Độ phức tạp | O(n²), chậm với mảng lớn, hợp để học tư duy |
| Thực tế | dùng `std::sort` cho nhanh (O(n log n)) |

> [!question] Tự luyện
> 1. Sửa code để sắp xếp **giảm dần** (chỉ đổi đúng 1 ký tự trong điều kiện `if`).
> 2. Thêm `size - 1 - i` vào vòng trong, rồi thêm 1 biến đếm `comparisons` để so sánh số lần so sánh trước và sau khi tối ưu.
> 3. Thử in mảng sau **mỗi lượt `i`** để tự thấy hiện tượng "nổi bọt".

Xem thêm: [[CPP - Truyền mảng vào hàm]] · [[CPP - Vòng lặp for]] · [[CPP - Mảng đánh dấu (seen) và size_t]]
