#include <iostream>

#include "Header.h"
#include "Complex.h"

using namespace std;

double abs(Complex<float> x) { return x.module(); }

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	
	Complex<float>** arr;
	try { arr = load_data<Complex<float>>(n, m); }
	catch (const char* msg) { cout << msg; return 2; }

	cout << "before" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	arr = min_matr<Complex<float>>(arr, n, m);

	cout << "after" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	delete_2d_arr(arr, n, m);
}