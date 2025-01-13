# Hàm Bubble Sort với đếm số lần hoán đổi
function bubble_sort(arr)
    swap_count = 0
    n = length(arr)
    for i in 1:(n-1)
        for j in 1:(n-i)
            if arr[j] > arr[j+1]
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swap_count += 1
            end
        end
    end
    return swap_count
end

# Hàm Selection Sort với đếm số lần hoán đổi
function selection_sort(arr)
    swap_count = 0
    n = length(arr)
    for i in 1:(n-1)
        min_index = i
        for j in (i+1):n
            if arr[j] < arr[min_index]
                min_index = j
            end
        end
        if min_index != i
            arr[i], arr[min_index] = arr[min_index], arr[i]
            swap_count += 1
        end
    end
    return swap_count
end

# Tạo mảng ngẫu nhiên
n = 10
random_array = rand(1:100, n)
println("Mảng ban đầu: ", random_array)

# Sao chép mảng để thực hiện sắp xếp
bubble_array = copy(random_array)
selection_array = copy(random_array)

# Gọi hàm và lấy số lần hoán đổi
bubble_swaps = bubble_sort(bubble_array)
selection_swaps = selection_sort(selection_array)

# Kết quả Bubble Sort
println("Kết quả sau Bubble Sort: ", bubble_array)
println("Số lần hoán đổi của Bubble Sort: ", bubble_swaps)

# Kết quả Selection Sort
println("Kết quả sau Selection Sort: ", selection_array)
println("Số lần hoán đổi của Selection Sort: ", selection_swaps)

# So sánh kết quả
if bubble_swaps > selection_swaps
    println("Selection Sort ít hoán đổi hơn Bubble Sort.")
elseif bubble_swaps < selection_swaps
    println("Bubble Sort ít hoán đổi hơn Selection Sort.")
else
    println("Số lần hoán đổi của hai thuật toán là như nhau.")
end
