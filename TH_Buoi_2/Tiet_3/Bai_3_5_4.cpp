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

// Hàm Insertion Sort
void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm Hybrid Quick Sort (Quick Sort kết hợp Insertion Sort)
void hybridQuickSort(vector<int>& arr, int low, int high, int threshold) {
    if (low < high) {
        if (high - low + 1 <= threshold) {
            // Sử dụng Insertion Sort khi kích thước mảng con nhỏ
            insertionSort(arr, low, high);
        } else {
            int p = partition(arr, low, high);  // Tìm vị trí pivot
            hybridQuickSort(arr, low, p - 1, threshold);  // Sắp xếp phần bên trái pivot
            hybridQuickSort(arr, p + 1, high, threshold);  // Sắp xếp phần bên phải pivot
        }
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
    vector<int> sizes = {5000, 10000, 20000};

    // Ngưỡng kích thước mảng khi chuyển sang sử dụng Insertion Sort
    int threshold = 10;

    for (int size : sizes) {
        // Tạo mảng ngẫu nhiên
        vector<int> arrQuick = generateRandomArray(size);
        vector<int> arrHybridQuick = arrQuick;  // Sao chép mảng cho Hybrid Quick Sort

        // Đo thời gian thực thi Quick Sort không tối ưu hóa
        auto start = chrono::high_resolution_clock::now();
        quickSort(arrQuick, 0, arrQuick.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> quickSortTime = end - start;
        
        // Đo thời gian thực thi Hybrid Quick Sort
        start = chrono::high_resolution_clock::now();
        hybridQuickSort(arrHybridQuick, 0, arrHybridQuick.size() - 1, threshold);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> hybridQuickSortTime = end - start;

        // In kết quả
        cout << "Kích thước mảng: " << size << endl;
        cout << "Thời gian thực thi Quick Sort: " << quickSortTime.count() << " giây" << endl;
        cout << "Thời gian thực thi Hybrid Quick Sort: " << hybridQuickSortTime.count() << " giây" << endl;
        cout << "-------------------------------------------" << endl;
    }

    return 0;
}
