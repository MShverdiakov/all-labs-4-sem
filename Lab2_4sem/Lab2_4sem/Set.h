#include <iostream>

using namespace std;

class Set {
	int n; // number of elements
	int* base; // array as a base
public:
	Set(int n = 0) { base = new int[n]; }
	~Set() {
		n = 0; delete []base;
	}
	void add(int elem) {
		if (!in(elem)) {
			int* new_base = new int[n + 1]; // adding to an array
			for (int i = 0; i < n; i++)
				new_base[i] = base[i];
			new_base[n] = elem;
			// making set bigger
			n += 1;
			delete[]base;
			base = new_base;
		}
	}
	bool in(int elem) {
		for (int i = 0; i < n; i++)
			if (elem == base[i]) return true;
		return false;
	}
	void set_base(int* arr) {
		delete[] base;
		base = arr;
	}
	friend ostream& operator << (ostream& out, Set& set) {
		for (int i = 0; i < set.n; i++)
			out << set.base[i] << " ";
		out << endl;
		return out;
	}
};