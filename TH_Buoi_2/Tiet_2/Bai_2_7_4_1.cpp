#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Hàm Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Hàm Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Hàm tạo mảng ngẫu nhiên
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Giá trị ngẫu nhiên từ 0 đến 9999
    }
    return arr;
}

// Hàm đo thời gian thực hiện
template <typename Func>
double measureExecutionTime(Func sortFunction, vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

int main() {
    srand(time(0));
    vector<int> sizes = {1000, 5000, 10000};
    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);
        cout << "Array size: " << size << endl;

        double bubbleTime = measureExecutionTime(bubbleSort, arr);
        cout << "Bubble Sort: " << bubbleTime << " ms" << endl;

        double insertionTime = measureExecutionTime(insertionSort, arr);
        cout << "Insertion Sort: " << insertionTime << " ms" << endl;

        double selectionTime = measureExecutionTime(selectionSort, arr);
        cout << "Selection Sort: " << selectionTime << " ms" << endl;

        cout << "---------------------------------" << endl;
    }
    return 0;
}
