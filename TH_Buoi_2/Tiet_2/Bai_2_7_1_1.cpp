#include <iostream>
#include <vector>

using namespace std;

void optimizedBubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Đặt flag để kiểm tra xem có xảy ra hoán đổi hay không
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi hai phần tử
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có hoán đổi nào, dừng vòng lặp
        if (!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    
    optimizedBubbleSort(arr);

    cout << "Kết quả sau Optimized Bubble Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
