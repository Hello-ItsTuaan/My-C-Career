# Nhập số lượng số cần kiểm tra
n = int(input("Nhập n: "))

# Vòng lặp chạy từ 1 đến n (tránh chia cho 0)
for i in range(1, n + 1):
    x = int(input(f"Nhập số thứ {i}: "))
    
    # Kiểm tra nếu x chia hết cho i
    if x % i == 0:
        print(f"-> {x} chia hết cho {i}")
