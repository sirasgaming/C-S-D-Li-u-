# Hàm Partition: Đưa pivot về vị trí đúng và sắp xếp các phần tử
def partition(arr, low, high):
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1        # Chỉ số nhỏ hơn pivot

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            # Hoán đổi arr[i] và arr[j]
            arr[i], arr[j] = arr[j], arr[i]

    # Hoán đổi pivot với arr[i+1] để đưa pivot vào vị trí đúng
    arr[i + 1], arr[high] = arr[high], arr[i + 1]

    return i + 1  # Vị trí của pivot

# Hàm Quick Sort
def quickSort(arr, low, high):
    if low < high:
        # Tìm vị trí pivot
        p = partition(arr, low, high)

        # Gọi đệ quy Quick Sort cho hai phần bên trái và bên phải của pivot
        quickSort(arr, low, p - 1)
        quickSort(arr, p + 1, high)

# Hàm chính
if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]

    # Gọi hàm quickSort để sắp xếp
    quickSort(arr, 0, len(arr) - 1)

    # In kết quả sau khi sắp xếp
    print("Kết quả Quick Sort:", arr)
