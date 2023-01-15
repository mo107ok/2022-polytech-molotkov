#include <iostream>

const int N = 10;
int A[N] = {-248, -208, -143, 72, 99, 115, 120, 156, 164, 181};
int A2[N] = {1, 2, 2, 2, 5, 6, 7, 8, 9, 10};
int A3[N] = {1, 2, 2, 3, 8, 10, 10, 10, 10, 10};
int A4[N] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};

int binarySearch(const int *a, int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main() {
    std::cout << "x = " << 120 << "\nBinary: " << binarySearch(A, N, 120) << "\n\n";
    std::cout << "x = " << 2 << "\nBinary: " << binarySearch(A2, N, 2) << "\n\n";
    std::cout << "x = " << 10 << "\nBinary: " << binarySearch(A3, N, 10) << "\n\n";
    std::cout << "x = " << 99 << "\nBinary: " << binarySearch(A4, N, 99) << "\n\n";
    return 0;
}