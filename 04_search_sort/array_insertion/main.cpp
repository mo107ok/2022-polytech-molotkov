#include <iostream>
#include <cstring>
#include <cassert>

int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int *insert(int x, int p, int arr[], int n) {
    for (int i = n; i > p; i--) arr[i] = arr[i - 1];

    arr[p] = x;
    return arr;
}

int search_position(int x, int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] >= x)
            return i;
    }
    return n;
}

int* insert_sorted(int arr[], int n, int x) {
    int p = search_position(x, arr, n);
    return insert(x, p, arr, n);
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "First array: " << std::endl;
    int a0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int expected_r0[11] = {0, 1, 2, 3, 100, 4, 5, 6, 7, 8, 9};
    print(a0, 10);
    int* r0 = insert(100, 4, a0, 10);
    for (int i = 0; i < 11; ++i) assert(r0[i] == expected_r0[i]);
    print(a0, 11);
    std::cout << std::endl;

    std::cout << "Second array: " << std::endl;
    int a1[4] = {1, 3, 5, 6};
    print(a1, 4);
    assert(search_position(5, a1, 4) == 2);
    std::cout << "Position of 5: " << search_position(5, a1, 4) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Third array: " << std::endl;
    int a2[4] = {1, 3, 5, 6};
    print(a2, 4);
    assert(search_position(7, a2, 4) == 4);
    std::cout << "Position of 7: " << search_position(7, a2, 4) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Fourth array: " << std::endl;
    int a3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int expected_r3[11] = {0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    print(a3, 10);
    int* r3 = insert_sorted(a3, 10, 5);
    for (int i = 0; i < 11; ++i) assert(r3[i] == expected_r3[i]);
    print(a3, 11);
    return 0;
}