---
tags: [cpp, brocode]
source: "BroCode - Nested Loops"
date: 2026-09-20
---

# Vòng lặp lồng nhau (Nested Loops)

#cpp/vong-lap #cpp/dieu-khien #brocode

> [!note] Khái niệm
> Nested loop là đặt 1 vòng lặp bên trong 1 vòng lặp khác. Vòng ngoài chạy 1 lần thì vòng trong chạy HẾT toàn bộ số lần của nó rồi mới quay lại vòng ngoài chạy tiếp lần kế. Thường dùng để xử lý dữ liệu 2 chiều — ví dụ in hình, ma trận, bảng.

## Cú pháp & Ví dụ

```cpp
int row, columns;
char symbol;

std::cin >> row;
std::cin >> columns;
std::cin >> symbol;

int currentCol = columns;

for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= currentCol; j++) {
        std::cout << symbol;
    }
    std::cout << "\n";
    currentCol -= 1;
}
```

Vòng ngoài (`i`) chạy theo số hàng, vòng trong (`j`) chạy theo `currentCol` để in ký tự trên 1 hàng. Điểm hay ở bài này: `currentCol -= 1` nằm ==ngoài vòng lặp trong nhưng vẫn trong vòng lặp ngoài==, nên mỗi hàng mới số cột lại giảm đi 1 → kết quả không phải hình chữ nhật đều mà là hình tam giác thu nhỏ dần.

Comment gốc của m ghi chú "phải tăng j, không phải trừ columns" — đúng là lỗi hay gặp: nếu lỡ tay viết `columns -= 1` bên trong vòng `j`, biến `columns` gốc sẽ bị <span style="color:#e06c75">mất giá trị ban đầu ngay từ hàng đầu tiên</span>, làm hỏng logic của các hàng sau.

> [!warning] Cạm bẫy thường gặp
> Đặt sai vị trí biến đếm/biến thay đổi: để nhầm trong vòng lặp trong khi lẽ ra phải ở vòng ngoài (hoặc ngược lại) sẽ làm sai hoàn toàn kết quả. Luôn tự hỏi: "biến này cần đổi mỗi lần lặp TRONG hay chỉ mỗi lần lặp NGOÀI?"

## Tóm tắt nhanh

| Điều cần nhớ | Giải thích |
|---|---|
| Thứ tự chạy | Vòng trong chạy hết trước, vòng ngoài mới sang lần tiếp |
| Dùng khi nào | Dữ liệu 2 chiều: hình, bảng, ma trận |
| Vị trí biến đổi | Đặt đúng chỗ (trong/ngoài) quyết định kết quả đúng/sai |

> [!question] Tự luyện
> 1. Sửa code để in hình chữ nhật đều (không thu nhỏ dần) — gợi ý: bỏ dòng `currentCol -= 1`.
> 2. Viết nested loop in bảng cửu chương (1x1 đến 9x9).
