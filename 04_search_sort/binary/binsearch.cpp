#include <iostream>
using namespace std;

int search(int arr[], int l, int r, int key)
{
	int num1;
	bool bool1 = false;
	while ((l <= r) && (bool1 != true))
	{
		num1 = (l + r) / 2;
		if (arr[num1] == key) bool1 = true;
		if (arr[num1] > key) r = num1 - 1;
		else l = num1 + 1;
	}
	return (num1 - 2);
}

int main()
{
	int cif[10] = { 5, 11, 45, 25, 12, 1, 86, 85, 81, 10 };
	int massize = sizeof(cif) / sizeof(cif[0]);
	cout << "12 is located at position " << search(cif, 0, massize, 12) << " (starting with position 0)\n";
}