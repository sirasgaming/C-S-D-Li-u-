def insertion_sort(arr):
    print("Mảng ban đầu:", arr)
    for i in range(1, len(arr)):
        # Lấy giá trị phần tử hiện tại (key)
        key = arr[i]
        j = i - 1
        
        # Di chuyển các phần tử lớn hơn key về phía sau
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # Chèn key vào đúng vị trí
        arr[j + 1] = key
        
        # In ra mảng sau mỗi bước chèn
        print(f"Bước {i}: Chèn phần tử {key} vào vị trí đúng -> {arr}")
    
    print("Kết quả sau Insertion Sort:", arr)

# Test
arr = [5, 3, 4, 1, 2]
insertion_sort(arr)
