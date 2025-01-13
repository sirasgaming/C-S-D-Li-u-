#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    cout << "Mảng ban đầu: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key về phía sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        // Chèn key vào đúng vị trí
        arr[j + 1] = key;

        // In ra mảng sau mỗi bước chèn
        cout << "Bước " << i << ": Chèn phần tử " << key << " vào vị trí đúng -> ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Kết quả sau Insertion Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 3, 4, 1, 2};
    insertionSort(arr);
    return 0;
}
