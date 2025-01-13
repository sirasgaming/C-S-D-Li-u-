using Random
using Printf
using BenchmarkTools

# Hàm Bubble Sort
function bubble_sort!(arr::Vector{Int})
    n = length(arr)
    for i in 1:n-1
        for j in 1:n-i
            if arr[j] > arr[j+1]
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
        end
    end
end

# Hàm Insertion Sort
function insertion_sort!(arr::Vector{Int})
    n = length(arr)
    for i in 2:n
        key = arr[i]
        j = i - 1
        while j > 0 && arr[j] > key
            arr[j+1] = arr[j]
            j -= 1
        end
        arr[j+1] = key
    end
end

# Hàm Selection Sort
function selection_sort!(arr::Vector{Int})
    n = length(arr)
    for i in 1:n-1
        min_index = i
        for j in i+1:n
            if arr[j] < arr[min_index]
                min_index = j
            end
        end
        arr[i], arr[min_index] = arr[min_index], arr[i]
    end
end

# Hàm tạo mảng ngẫu nhiên
function generate_random_array(size::Int)
    return rand(1:10_000, size)
end

# Hàm đo thời gian thực hiện
function measure_execution_time(sort_function::Function, arr::Vector{Int})
    copy_arr = copy(arr)  # Tạo bản sao của mảng để giữ nguyên mảng gốc
    return @belapsed sort_function!(copy_arr)  # Đo thời gian thực thi
end

# Benchmark
function benchmark_sorting_algorithms()
    sizes = [1000, 5000, 10000]  # Các kích thước mảng cần kiểm tra
    for size in sizes
        println("Array size: $size")
        arr = generate_random_array(size)

        # Bubble Sort
        bubble_time = measure_execution_time(bubble_sort!, arr)
        @printf("Bubble Sort: %.2f ms\n", bubble_time * 1000)

        # Insertion Sort
        insertion_time = measure_execution_time(insertion_sort!, arr)
        @printf("Insertion Sort: %.2f ms\n", insertion_time * 1000)

        # Selection Sort
        selection_time = measure_execution_time(selection_sort!, arr)
        @printf("Selection Sort: %.2f ms\n", selection_time * 1000)

        println("---------------------------------")
    end
end

# Chạy benchmark
benchmark_sorting_algorithms()
