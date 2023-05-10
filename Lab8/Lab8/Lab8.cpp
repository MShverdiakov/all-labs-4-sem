#include <iostream>
#include <vector>
using namespace std;

bool is_same_fract_ration(float num1, float num2, float needed_q) {
	float this_q = num2 / num1;
	if (abs(this_q - needed_q) < 0.0001)
		return true;
	return false;
}

int main()
{
	cout << "How many elements?\n"; 
	int n; cin >> n;

	vector<float> v;
	vector<float>::iterator itv;
	cout << "write your elements\n";
	float in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		v.emplace_back(in);
	}
	
	bool flag = true;
	float q = v.at(1) / v.at(0);
	itv = v.begin() + 1;
	while ((itv != v.end() - 1) && flag) {
		if (!is_same_fract_ration(*itv, *(itv + 1), q)) {
			flag = false;
			cout << "not all have same ration, first wrong pair is " << distance(v.begin(), itv) + 1 << endl;
		}
		itv++;
	}
	if (flag)
		cout << "you list of number makes geometric progression";
}