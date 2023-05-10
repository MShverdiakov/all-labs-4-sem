#include "Set.h"
#include <fstream>

Set load_data() {
	ifstream fin("set_int.txt");
	int n; fin >> n;
	Set set(n);
	if ((n < 1) or (n > 10)) { throw "invalid argument (number of elements)"; }
	int elem;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> elem;
		arr[i] = elem;
	}
	set.set_base(arr);
	fin.close();
	return set;
}