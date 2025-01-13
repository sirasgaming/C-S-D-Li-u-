#include <iostream>
using namespace std;

int sum_1_to_n(int n) {
    int s = 0;  // 1 assignment operation
    for (int i = 1; i <= n; i++) {  // n loop iterations
        s += i;  // 1 addition and 1 assignment operation per loop iteration
    }
    return s;
}

int main() {
    int n = 5;
    cout << "Tong 1. . n = " << sum_1_to_n(n) << endl;  // Output: 15
    return 0;
}
