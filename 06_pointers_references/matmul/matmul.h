#include <iostream>


using namespace std;


int** arr_create(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) arr[i] = new int[cols];

    return arr;
}


void fill_array(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "row: " << i + 1 << endl;

        for (int j = 0; j < cols; j++) cin >> arr[i][j];
    }
    cout << endl;
}


void print_array(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << arr[i][j] << " ";
        cout << endl << endl;
    }
}


void matmul(int** a, int r_a, int c_a, int** b, int r_b, int c_b, int** c) {
    for (int i = 0; i < r_a; i++) {
        for (int j = 0; j < c_b; j++) {
            c[i][j] = 0;
            for (int k = 0; k < r_b; k++) c[i][j] += a[i][k] * b[k][j];
        }
    }
}


void delete_arr(int** a, int m) {
    for (int i = 0; i < m; i++) delete[] a[i];
}