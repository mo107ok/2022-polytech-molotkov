

#include <iostream>
#include<cassert>

using namespace std;


int** getMatrix(int m, int n) {
	int** arr = new int* [m];

	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
	}

	return arr;
}


void fillMatrix(int** matrix, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % 19 - 9;
		}
	}
}


void printMatrix(int** matrix, int m, int n, int widthCharSize) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(widthCharSize);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


void deleteMatrix(int** matrix, int m) {
	for (int i = 0; i < m; i++) {
		delete matrix[i];
	}
	delete[] matrix;
}


void matmul(int** a, int m_a, int n_a, int** b, int m_b, int n_b, int** c) {
	for (int i = 0; i < m_a; i++)
	{
		for (int j = 0; j < n_b; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n_a; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}


int getMatMulValAtIndices(int** a, int** b, int a_i, int b_i, int equalSide) {
	int mulValue = 0;

	for (int i = 0; i < a_i; i++)
	{
		for (int j = 0; j < b_i; j++)
		{
			for (int k = 0; k < equalSide; k++) {
				mulValue += a[i][k] * b[k][j];
			}
		}
	}

	return mulValue;
}


bool mateq(int** a, int m_a, int n_a, int** b, int m_b, int n_b) {
	if (m_a != m_b || n_a != n_b) {
		return false;
	}

	for (int i = 0; i < m_a; i++) {
		for (int j = 0; j < n_a; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}

	return true;
}


bool isMatricesCanBeMultiplied(int n_a, int m_b) {
	return n_a == m_b;
}


int main()
{
	int m_a = 8;
	int n_a = 10;
	int m_b = 10;
	int n_b = 7;

	srand(time(0));

	int** a = getMatrix(m_a, n_a);
	int** b = getMatrix(m_b, n_b);

	fillMatrix(a, m_a, n_a);
	fillMatrix(b, m_b, n_b);

	printMatrix(a, m_a, n_a, 3);

	cout << endl << endl;

	printMatrix(b, m_b, n_b, 3);

	int** c = getMatrix(m_a, n_b);

	if (!isMatricesCanBeMultiplied(n_a, m_b)) {
		cout << endl << "Can't multiply specified matrices" << endl;
		return 0;
	}

	matmul(a, m_a, n_a, b, m_b, n_b, c);

	cout << endl << endl;

	printMatrix(c, m_a, n_b, 5);

	cout << endl << endl;

	mateq(a, m_a, n_a, b, m_b, n_b) ? cout << "Matrices are equal" : cout << "Matrices are not equal" << endl;

	assert(getMatMulValAtIndices(a, b, 1, 1, n_a) == c[0][0]);
}