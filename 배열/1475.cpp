#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int tmp[9] = { 0 };
	string rN;
	int set = 0;

	cin >> rN;

	for (int i = 0; i < rN.length(); i++) {
		if (rN[i] == '9') tmp[6]++;
		else tmp[rN[i] - 48]++;
	}

	for (int i = 0; i < 9; i++) {
		if (i == 6) tmp[i] = ceil(tmp[i] / 2.);
		if (set < tmp[i]) set = tmp[i];
	}

	cout << set;

	return 0;
}