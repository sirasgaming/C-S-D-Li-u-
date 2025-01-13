function optimized_bubble_sort!(arr)
    n = length(arr)
    for i in 1:(n-1)
        # Đặt flag để kiểm tra xem có xảy ra hoán đổi hay không
        swapped = false
        for j in 1:(n-i)
            if arr[j] > arr[j+1]
                # Hoán đổi hai phần tử
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = true
            end
        end
        # Nếu không có hoán đổi nào, dừng vòng lặp
        if !swapped
            break
        end
    end
    return arr
end

# Test
arr = [5, 1, 4, 2, 8]
optimized_bubble_sort!(arr)
println("Kết quả sau Optimized Bubble Sort: ", arr)
