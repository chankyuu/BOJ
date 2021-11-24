#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int D[12];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> T;
	D[0] = 0;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 0; i < T; i++) {
		cin >> N;

		for (int j = 4; j <= N; j++) {
			D[j] = D[j - 1] + D[j - 2] + D[j - 3];
		}

		cout << D[N] << "\n";
	}
	return 0;
}