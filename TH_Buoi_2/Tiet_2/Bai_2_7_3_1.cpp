#include <iostream>
#include <vector>
#include <cstdlib> // Để sử dụng rand() và srand()
#include <ctime>   // Để sử dụng time()

using namespace std;

// Hàm Bubble Sort với đếm số lần hoán đổi
int bubbleSort(vector<int> arr) {
    int swap_count = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swap_count;
            }
        }
    }
    return swap_count;
}

// Hàm Selection Sort với đếm số lần hoán đổi
int selectionSort(vector<int> arr) {
    int swap_count = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
            ++swap_count;
        }
    }
    return swap_count;
}

int main() {
    srand(time(0)); // Khởi tạo seed cho số ngẫu nhiên

    // Tạo mảng ngẫu nhiên
    int n = 10;
    vector<int> random_array(n);
    for (int i = 0; i < n; ++i) {
        random_array[i] = rand() % 100 + 1; // Số ngẫu nhiên từ 1 đến 100
    }

    // In mảng ban đầu
    cout << "Mảng ban đầu: ";
    for (int num : random_array) {
        cout << num << " ";
    }
    cout << endl;

    // Sao chép mảng để so sánh
    vector<int> bubble_array = random_array;
    vector<int> selection_array = random_array;

    // Thực hiện Bubble Sort và Selection Sort
    int bubble_swaps = bubbleSort(bubble_array);
    int selection_swaps = selectionSort(selection_array);

    // Kết quả Bubble Sort
    cout << "Kết quả sau Bubble Sort: ";
    for (int num : bubble_array) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Số lần hoán đổi của Bubble Sort: " << bubble_swaps << endl;

    // Kết quả Selection Sort
    cout << "Kết quả sau Selection Sort: ";
    for (int num : selection_array) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Số lần hoán đổi của Selection Sort: " << selection_swaps << endl;

    // So sánh
    if (bubble_swaps > selection_swaps) {
        cout << "Selection Sort ít hoán đổi hơn Bubble Sort." << endl;
    } else if (bubble_swaps < selection_swaps) {
        cout << "Bubble Sort ít hoán đổi hơn Selection Sort." << endl;
    } else {
        cout << "Số lần hoán đổi của hai thuật toán là như nhau." << endl;
    }

    return 0;
}
