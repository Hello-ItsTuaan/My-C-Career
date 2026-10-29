---

## tags: [cpp, brocode] source: "BroCode - Namespaces" date: 2026-08-30

# Không gian tên (`namespace`)

#cpp/namespace #cpp/co-ban #brocode

> [!note] Khái niệm `namespace` giải quyết vấn đề **trùng tên** trong dự án lớn. Khi nhiều file/thư viện đều khai báo một biến/hàm tên giống nhau (ví dụ `x`), trình biên dịch sẽ không biết bạn đang nói tới cái nào. Namespace giống như "cái hộp" gom các entity lại — miễn khác hộp thì trùng tên vẫn ok.

## Cú pháp & Ví dụ

```cpp
namespace first {
    int x = 0;
}

namespace second {
    int x = 1;
}
```

Hai biến cùng tên `x` nhưng nằm trong hai "hộp" khác nhau nên không xung đột.

### Cách 1: Toán tử phạm vi `::`

```cpp
int main() {
    int x = 2;
    std::cout << x << std::endl;        // x toàn cục (local trong main)
    std::cout << first::x << std::endl; // x của namespace "first"
    return 0;
}
```

`::` (scope resolution operator) dùng để **chỉ đích danh** biến đó thuộc namespace nào — ==đây là cách an toàn nhất vì không gây nhầm lẫn với biến local hay biến ở namespace khác==.

### Cách 2: `using namespace`

```cpp
int main() {
    using namespace first;
    std::cout << x << std::endl; // hiểu ngầm là first::x
    return 0;
}
```

> [!warning] Cạm bẫy thường gặp `using namespace std;` rất tiện nhưng <span style="color:#e06c75">không an toàn trên project lớn</span> — vì nó "mở toang" cả namespace `std`, dễ gây trùng tên với các thư viện khác hoặc namespace tự định nghĩa của bạn.

### Tip của BroCode: chỉ import cái mình cần

```cpp
int main() {
    using std::cout;   // chỉ lấy cout
    using std::string; // chỉ lấy string

    string name = "Tuan";
    cout << "Hello" << std::endl;
    return 0;
}
```

> [!tip] Mẹo Thay vì `using namespace std;` (import hết), hãy dùng `using std::cout;`, `using std::string;`... để chỉ <span style="color:#98c379">lấy đúng thứ cần dùng</span>. Vừa an toàn hơn, vừa code người khác đọc vào biết ngay bạn đang xài gì từ `std`.

## Tóm tắt nhanh

|Điều cần nhớ|Giải thích|
|---|---|
|`namespace`|Gom các entity (biến, hàm, class...) lại thành một "hộp" tên riêng để tránh trùng tên|
|`::`|Scope resolution operator — chỉ định rõ entity thuộc namespace nào (`first::x`)|
|`using namespace X;`|Import toàn bộ namespace X, tiện nhưng dễ gây xung đột trên project lớn|
|`using std::cout;`|Import chọn lọc — chỉ lấy đúng cái cần, an toàn hơn `using namespace std;`|

> [!question] Tự luyện
> 
> 1. Thử tạo thêm `namespace third { int x = 5; }` rồi in cả 3 giá trị `first::x`, `second::x`, `third::x` trong cùng một `main()`.
> 2. Thử `using namespace first;` và `using namespace second;` cùng lúc rồi in `x` không có `::` — xem trình biên dịch báo lỗi gì (gợi ý: ambiguous).