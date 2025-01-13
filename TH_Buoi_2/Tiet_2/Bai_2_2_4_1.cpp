#include <iostream>
#include <vector>
using namespace std;

// Hàm Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};
    bubbleSort(arr);
    cout << "Ket qua sau Bubble Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
