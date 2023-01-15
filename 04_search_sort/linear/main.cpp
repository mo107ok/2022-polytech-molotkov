#include <iostream>

const int N = 10;
int A[N] = {-248, -208, -143, 72, 99, 115, 120, 156, 164, 181};
int A2[N] = {1, 2, 2, 2, 5, 6, 7, 8, 9, 10};
int A3[N] = {1, 2, 2, 3, 8, 10, 10, 10, 10, 10};
int A4[N] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};

int linearSearch(const int *a, int n, int x, int *result) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            result[count] = i;
            count++;
        }
    }
    return count;
}

void test(const int *a, int x) {
    std::cout << "x = " << x << std::endl;
    int result[N];
    int count;

    count = linearSearch(a, N, x, result);
    std::cout << "Linear, count: " << count << std::endl;
    std::cout << "Linear, result: ";
    for (int i = 0; i < count; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main() {
    test(A, 120);
    test(A2, 2);
    test(A3, 10);
    test(A4, 99);
    return 0;
}