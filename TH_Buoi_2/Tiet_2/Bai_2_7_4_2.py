import random
import time

# Hàm Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Hàm Insertion Sort
def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Hàm Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Hàm tạo mảng ngẫu nhiên
def generate_random_array(size):
    return [random.randint(0, 10000) for _ in range(size)]

# Hàm đo thời gian thực hiện
def measure_execution_time(sort_function, arr):
    start_time = time.time()
    sort_function(arr)
    end_time = time.time()
    return (end_time - start_time) * 1000  # Thời gian tính bằng milliseconds

# Chạy benchmark
if __name__ == "__main__":
    sizes = [1000, 5000, 10000]  # Kích thước mảng
    for size in sizes:
        arr = generate_random_array(size)
        print(f"Array size: {size}")

        # Đo thời gian Bubble Sort
        bubble_arr = arr.copy()
        bubble_time = measure_execution_time(bubble_sort, bubble_arr)
        print(f"Bubble Sort: {bubble_time:.2f} ms")

        # Đo thời gian Insertion Sort
        insertion_arr = arr.copy()
        insertion_time = measure_execution_time(insertion_sort, insertion_arr)
        print(f"Insertion Sort: {insertion_time:.2f} ms")

        # Đo thời gian Selection Sort
        selection_arr = arr.copy()
        selection_time = measure_execution_time(selection_sort, selection_arr)
        print(f"Selection Sort: {selection_time:.2f} ms")

        print("---------------------------------")
