#include <iostream>
#include <fstream>

using namespace std;

template <typename T> void delete_2d_arr(T** arr, int n, int m) {
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
}

template <typename Type> Type** load_data(int& x, int& y) {
	ifstream fin("matrix_complex.txt");
	int& n = x, & m = y; fin >> n >> m;
	if ((n < 1) or (n > 10)) { throw "invalid argument (number of rows)"; }
	if ((m < 2) or (m > 10)) { throw "invalid argument (number of columns)";	}
	Type** arr = new Type * [m];
	for (int i = 0; i < m; i++)
		arr[i] = new Type[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fin >> arr[i][j];
	fin.close();
	return arr;
}

template <typename T>
T** min_matr(T** a, int n, int m) {
	for (int j = 0; j < n; j++) {
		int l = m / 2;
		int r = m;
		T minr = a[j][l];
		int minr_id = l;
		for (int i = l; i < r; i++) {
			if (abs(minr) > abs(a[j][i])) {
				minr = a[j][i];
				minr_id = i;
			}
		}

		l = 0;
		r = m / 2;
		T minl = a[j][l];
		int minl_id = l;
		for (int i = l; i < r; i++) {
			if (abs(minl) > abs(a[j][i])) {
				minl = a[j][i];
				minl_id = i;
			}
		}

		T temp = a[j][minr_id];
		a[j][minr_id] = a[j][minl_id];
		a[j][minl_id] = temp;
	}
	return a;
}

template <typename T> bool isMultiple(T* arr, int m, T x) {
	bool flag = false;
	for (int j = 0; j < m; j++)
		if (arr[j] % x == 0) {
			flag = true; break; // вообще тупо как-то использовать досрочный выход когда можно while
		}
	return flag;
}