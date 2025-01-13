#include <iostream>
#include <vector>
#include <random>
using namespace std;

int compareCountMerge = 0;  // Biến đếm số lần so sánh trong Merge Sort
int compareCountQuick = 0;  // Biến đếm số lần so sánh trong Quick Sort

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
        compareCountMerge++;  // Tăng số lần so sánh
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

// Hàm Partition (Quick Sort)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Chọn pivot là phần tử cuối
    int i = low - 1;

    for (int j = low; j < high; j++) {
        compareCountQuick++;  // Tăng số lần so sánh
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Hoán đổi arr[i] và arr[j]
        }
    }

    swap(arr[i + 1], arr[high]);  // Hoán đổi pivot với arr[i+1]
    return i + 1;  // Vị trí của pivot
}

// Hàm Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // Tìm vị trí pivot
        quickSort(arr, low, p - 1);  // Sắp xếp phần bên trái pivot
        quickSort(arr, p + 1, high);  // Sắp xếp phần bên phải pivot
    }
}

int main() {
    vector<int> arr1 = {5, 2, 9, 1, 5, 6};  // Mảng cần sắp xếp

    // Merge Sort
    mergeSort(arr1, 0, arr1.size() - 1);
    cout << "Kết quả Merge Sort: ";
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Số lần so sánh trong Merge Sort: " << compareCountMerge << endl;

    // Đặt lại số lần so sánh cho Quick Sort
    compareCountQuick = 0;

    vector<int> arr2 = {5, 2, 9, 1, 5, 6};  // Mảng mới để thực hiện Quick Sort

    // Quick Sort
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "Kết quả Quick Sort: ";
    for (int x : arr2) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Số lần so sánh trong Quick Sort: " << compareCountQuick << endl;

    return 0;
}
