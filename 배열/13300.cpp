#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int g[6][2] = { 0 };
	int tmp[2];
	int N;
	int K;
	int S;
	int Y;
	int sum = 0;

	cin >> N;
	cin >> K;
	// 0여학생, 1남학생
	while (N--) {
		cin >> S;
		cin >> Y;

		g[Y - 1][S]++;
	}


	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			sum += ceil(double(g[i][j]) / K);
		}
	}

	cout << sum;

	return 0;
}