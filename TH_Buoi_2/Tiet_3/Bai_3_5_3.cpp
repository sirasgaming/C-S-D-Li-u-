#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>  // std::swap
using namespace std;

// Hàm Partition (Quick Sort)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Chọn pivot là phần tử cuối
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Hoán đổi arr[i] và arr[j]
        }
    }

    swap(arr[i + 1], arr[high]);  // Hoán đổi pivot với arr[i+1]
    return i + 1;  // Vị trí của pivot
}

// Hàm Quick Sort (Không tối ưu hóa)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // Tìm vị trí pivot
        quickSort(arr, low, p - 1);  // Sắp xếp phần bên trái pivot
        quickSort(arr, p + 1, high);  // Sắp xếp phần bên phải pivot
    }
}

// Hàm Partition (Randomized Quick Sort)
int randomizedPartition(vector<int>& arr, int low, int high) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    int pivotIndex = dis(gen);  // Chọn một pivot ngẫu nhiên trong khoảng [low, high]
    
    swap(arr[pivotIndex], arr[high]);  // Đưa pivot ngẫu nhiên về cuối mảng
    return partition(arr, low, high);  // Sử dụng Partition với pivot đã được chọn ngẫu nhiên
}

// Hàm Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = randomizedPartition(arr, low, high);  // Tìm vị trí pivot ngẫu nhiên
        randomizedQuickSort(arr, low, p - 1);  // Sắp xếp phần bên trái pivot
        randomizedQuickSort(arr, p + 1, high);  // Sắp xếp phần bên phải pivot
    }
}

// Hàm tạo mảng ngẫu nhiên
vector<int> generateRandomArray(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);  // Sinh số ngẫu nhiên từ 1 đến 100000

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

int main() {
    // Kích thước mảng lớn để kiểm tra hiệu suất
    vector<int> sizes = {5000, 100000, 500000};

    for (int size : sizes) {
        // Tạo mảng ngẫu nhiên
        vector<int> arrQuick = generateRandomArray(size);
        vector<int> arrRandomizedQuick = arrQuick;  // Sao chép mảng cho Randomized Quick Sort

        // Đo thời gian thực thi Quick Sort không tối ưu hóa
        auto start = chrono::high_resolution_clock::now();
        quickSort(arrQuick, 0, arrQuick.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> quickSortTime = end - start;
        
        // Đo thời gian thực thi Randomized Quick Sort
        start = chrono::high_resolution_clock::now();
        randomizedQuickSort(arrRandomizedQuick, 0, arrRandomizedQuick.size() - 1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> randomizedQuickSortTime = end - start;

        // In kết quả
        cout << "Kích thước mảng: " << size << endl;
        cout << "Thời gian Quick Sort: " << quickSortTime.count() << " giây" << endl;
        cout << "Thời gian Randomized Quick Sort: " << randomizedQuickSortTime.count() << " giây" << endl;
        cout << "-------------------------------------------" << endl;
    }

    return 0;
}
