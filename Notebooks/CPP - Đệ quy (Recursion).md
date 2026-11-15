---
tags: [cpp, brocode]
source: "BroCode - Recursion"
date: 2026-11-14
---

# Đệ quy (`recursion`)

#cpp/recursion #cpp/ham #brocode

> [!note] Khái niệm
> **Đệ quy** là kỹ thuật lập trình trong đó ==một hàm tự gọi lại chính nó== từ bên trong thân hàm. Ý tưởng: lấy một bài toán phức tạp, **chẻ nhỏ** thành một bước lặp đi lặp lại đơn giản, rồi để hàm tự lặp bước đó cho tới khi gặp điều kiện dừng.
> So với cách viết vòng lặp (*iterative*), đệ quy (*recursive*) thường cho code ngắn và "sạch" hơn.

## Cú pháp & Ví dụ

### 1. Giai thừa: lặp vs đệ quy

```cpp
long long factorial(int num) {
  // ── Cách 1: vòng lặp (iterative) ──
  // int result = 1;
  // for (int i = 1; i <= num; i++) {
  //   result = result * i;
  // }

  // ── Cách 2: đệ quy (recursive) ──
  if (num > 1) {
    return num * factorial(num - 1);   // gọi lại chính nó với bài toán nhỏ hơn
  } else {
    return 1;                          // điều kiện dừng (base case)
  }
}
```

Một hàm đệ quy **luôn** cần 2 phần:

- **Base case** (điều kiện dừng): `else { return 1; }` — chỗ để hàm *thôi* không gọi lại nữa.
- **Recursive case**: `num * factorial(num - 1)` — gọi lại chính nó, nhưng với đầu vào ==tiến gần hơn tới base case==.

> [!example] Hàm chạy như thế nào? `factorial(4)`
> ```
> factorial(4) = 4 * factorial(3)
>                    3 * factorial(2)
>                        2 * factorial(1)
>                            1            ← base case, bắt đầu "trả ngược" về
>                        2 * 1 = 2
>                    3 * 2 = 6
>                4 * 6 = 24
> ```
> Mỗi lần gọi là một "tầng" mới chồng lên **stack**; tới base case thì các tầng lần lượt trả giá trị về từ trên xuống.

### 2. Đi bộ: `walk(steps)`

```cpp
void walk(int steps) {
  // for (int i = 0; i < steps; i++) {
  //   std::cout << "You just take a step! \n";
  // }

  if (steps > 0) {
    std::cout << "You take a step!\n";
    walk(steps - 1);   // giảm steps mỗi lần → cuối cùng chạm 0 thì dừng
  }
}
```

Hàm `void` cũng đệ quy được — ở đây base case là *"không làm gì cả"* khi `steps <= 0` (nhánh `if` không chạy).

> [!warning] Cạm bẫy: quên `- 1` ⇒ Stack Overflow
> Nếu viết `walk(steps);` mà ==không có `-1`==, `steps` không bao giờ giảm → hàm gọi chính nó mãi mãi. Mỗi lần gọi ăn thêm một ít bộ nhớ stack, tới lúc hết chỗ thì chương trình **crash**: đó chính là <span style="color:#e06c75">Stack Overflow</span> 😄 (trùng tên với cái web quen thuộc luôn).
> Quy tắc: *mỗi lần gọi đệ quy phải đưa đầu vào gần base case hơn, và base case phải có thật.*

> [!tip] Mẹo
> Trước khi viết đệ quy, tự hỏi 2 câu: **(1)** Khi nào thì dừng? **(2)** Mỗi bước, bài toán nhỏ đi như thế nào?
> Nếu trả lời được cả hai thì viết hàm gần như xong rồi.

## Ưu & nhược điểm

| | Đệ quy | Vòng lặp |
|---|---|---|
| Độ dài code | <span style="color:#98c379">ngắn, gọn, dễ đọc hơn</span> (với bài có cấu trúc đệ quy) | dài hơn một chút |
| Bộ nhớ | <span style="color:#e06c75">tốn hơn</span> (mỗi lần gọi thêm 1 tầng stack) | tiết kiệm |
| Tốc độ | <span style="color:#e06c75">chậm hơn</span> (chi phí gọi hàm) | nhanh hơn |
| Hợp với | sắp xếp, tìm kiếm (VD: merge sort, quick sort, binary search), cây, DFS | các việc lặp đơn giản |

> [!important] Lưu ý khi thi giải
> Trong competitive programming, đệ quy quá sâu (cỡ vài trăm nghìn tầng) dễ làm tràn stack. Biết **khi nào** nên đổi sang vòng lặp cũng là một kỹ năng.

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Đệ quy là gì | Hàm tự gọi chính nó, chia bài toán lớn thành bước nhỏ lặp lại |
| Base case | Điều kiện dừng, bắt buộc phải có |
| Recursive case | Gọi lại chính nó với đầu vào nhỏ hơn / gần base case hơn |
| `factorial` | `n * factorial(n-1)`, dừng khi `n <= 1` trả về `1` |
| Thiếu base case / quên `-1` | Gọi vô hạn → Stack Overflow |
| Đánh đổi | Code gọn hơn nhưng tốn bộ nhớ hơn và chậm hơn vòng lặp |

> [!question] Tự luyện
> 1. Trong `main()` chưa hề gọi `walk(...)` 😏 — thêm `walk(3);` rồi chạy thử. Sau đó cố tình xoá `- 1` để tận mắt xem Stack Overflow (nhớ lưu file trước nhé!).
> 2. Viết hàm đệ quy `long long sum(int n)` trả về `1 + 2 + ... + n`, rồi thử viết thêm `int fib(int n)` (dãy Fibonacci) và so sánh với cách dùng vòng lặp.

Liên quan: [[CPP - Hàm & Tham số]] · [[CPP - Bộ nhớ động (Dynamic Memory)]] · [[CPP - Con trỏ (Pointers)]]
