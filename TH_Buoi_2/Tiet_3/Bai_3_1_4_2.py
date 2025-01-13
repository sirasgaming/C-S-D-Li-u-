# Hàm trộn hai mảng con đã được sắp xếp
def merge(arr, left, mid, right):
    n1 = mid - left + 1  # Kích thước mảng con trái
    n2 = right - mid     # Kích thước mảng con phải

    # Tạo các mảng tạm thời
    L = arr[left:mid+1]
    R = arr[mid+1:right+1]

    # Trộn hai mảng L và R vào arr[left..right]
    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Sao chép phần còn lại của L, nếu có
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Sao chép phần còn lại của R, nếu có
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

# Hàm Merge Sort
def mergeSort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2  # Tìm điểm giữa để chia đôi

        # Sắp xếp đệ quy từng nửa
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        # Trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right)

# Hàm chính
if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]

    # Gọi hàm mergeSort để sắp xếp
    mergeSort(arr, 0, len(arr) - 1)

    # In kết quả sau khi sắp xếp
    print("Kết quả Merge Sort:", arr)
