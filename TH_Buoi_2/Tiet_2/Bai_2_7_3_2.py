import random

# Bubble Sort với đếm số lần hoán đổi
def bubble_sort(arr):
    swap_count = 0
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swap_count += 1
    return swap_count

# Selection Sort với đếm số lần hoán đổi
def selection_sort(arr):
    swap_count = 0
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]
            swap_count += 1
    return swap_count

# Tạo mảng ngẫu nhiên
n = 10
random_array = [random.randint(1, 100) for _ in range(n)]
print("Mảng ban đầu:", random_array)

# So sánh số lần hoán đổi
bubble_array = random_array[:]  # Sao chép mảng
selection_array = random_array[:]

bubble_swaps = bubble_sort(bubble_array)
selection_swaps = selection_sort(selection_array)

print("Kết quả sau Bubble Sort:", bubble_array)
print("Số lần hoán đổi của Bubble Sort:", bubble_swaps)

print("Kết quả sau Selection Sort:", selection_array)
print("Số lần hoán đổi của Selection Sort:", selection_swaps)

# Phân tích kết quả
if bubble_swaps > selection_swaps:
    print("Selection Sort ít hoán đổi hơn Bubble Sort.")
elif bubble_swaps < selection_swaps:
    print("Bubble Sort ít hoán đổi hơn Selection Sort.")
else:
    print("Số lần hoán đổi của hai thuật toán là như nhau.")
