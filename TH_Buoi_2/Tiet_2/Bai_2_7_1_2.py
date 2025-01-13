def optimized_bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        # Đặt flag để kiểm tra xem có xảy ra hoán đổi hay không
        swapped = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                # Hoán đổi hai phần tử
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # Nếu không có hoán đổi nào, dừng vòng lặp
        if not swapped:
            break
    return arr

# Test
arr = [5, 1, 4, 2, 8]
optimized_bubble_sort(arr)
print("Kết quả sau Optimized Bubble Sort:", arr)
