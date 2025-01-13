function insertion_sort(arr)
    println("Mảng ban đầu: ", arr)
    n = length(arr)
    
    for i in 2:n
        key = arr[i]
        j = i - 1
        
        # Di chuyển các phần tử lớn hơn key về phía sau
        while j > 0 && arr[j] > key
            arr[j + 1] = arr[j]
            j -= 1
        end
        
        # Chèn key vào đúng vị trí
        arr[j + 1] = key
        
        # In ra mảng sau mỗi bước chèn
        println("Bước $i: Chèn phần tử $key vào vị trí đúng -> ", arr)
    end
    
    println("Kết quả sau Insertion Sort: ", arr)
end

# Test
arr = [5, 3, 4, 1, 2]
insertion_sort(arr)
