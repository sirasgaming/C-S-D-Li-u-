#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>  // std::swap
using namespace std;

// Hàm trộn hai mảng con đã được sắp xếp (Merge Sort)
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Kích thước mảng con trái
    int n2 = right - mid;     // Kích thước mảng con phải

    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu vào mảng tạm L và R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Trộn hai mảng L và R vào arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép phần còn lại của L, nếu có
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Sao chép phần còn lại của R, nếu có
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Hàm Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Tìm điểm giữa để chia đôi
        mergeSort(arr, left, mid);  // Sắp xếp đệ quy nửa trái
        mergeSort(arr, mid + 1, right);  // Sắp xếp đệ quy nửa phải
        merge(arr, left, mid, right);  // Trộn hai nửa đã sắp xếp
    }
}

// Hàm Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);  // Hoán đổi các phần tử
            }
        }
    }
}

// Hàm tạo mảng ngẫu nhiên
vector<int> generateRandomArray(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);  // Sinh số ngẫu nhiên từ 1 đến 10000

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

int main() {
    // Kích thước mảng
    vector<int> sizes = {5000, 10000, 20000};

    for (int size : sizes) {
        // Tạo mảng ngẫu nhiên
        vector<int> arrMerge = generateRandomArray(size);
        vector<int> arrBubble = arrMerge;  // Sao chép mảng cho Bubble Sort

        // Đo thời gian thực thi Merge Sort
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arrMerge, 0, arrMerge.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> mergeSortTime = end - start;
        
        // Đo thời gian thực thi Bubble Sort
        start = chrono::high_resolution_clock::now();
        bubbleSort(arrBubble);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> bubbleSortTime = end - start;

        // In kết quả
        cout << "Kích thước mảng: " << size << endl;
        cout << "Thời gian thực thi Merge Sort: " << mergeSortTime.count() << " giây" << endl;
        cout << "Thời gian thực thi Bubble Sort: " << bubbleSortTime.count() << " giây" << endl;
        cout << "-------------------------------------------" << endl;
    }

    return 0;
}
