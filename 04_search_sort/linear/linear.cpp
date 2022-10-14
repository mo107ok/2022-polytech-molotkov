#include <iostream>
using namespace std;

int search(int arr[], int n, int x, int result[])
{
    int b;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            b = i;
        }
    }
    return b;
}


int main()
{
    int cif[10] = { 5, 11, 45, 25, 12, 1, 86, 85, 81, 10 };
    int massize = sizeof(cif) / sizeof(cif[0]);
    int result[massize];
    for (int i = 0; i < massize; ++i)
    {
        result[i] = 0;
    }
    cout << "12 is located at " << search(cif, massize, 12, result) << endl << " (if starting with 0)" << '\n';
}