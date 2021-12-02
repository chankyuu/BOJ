#include <bits/stdc++.h>

using namespace std;

int N;
int D[1000002];
int inf[1000002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	D[1] = 0;
	inf[1] = 0;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		inf[i] = i - 1;
		if (i % 2 == 0 && D[i] > D[i / 2] + 1) {
			D[i] = D[i / 2] + 1;
			inf[i] = i / 2;
		}
		if (i % 3 == 0 && D[i] > D[i / 3] + 1) {
			D[i] = D[i / 3] + 1;
			inf[i] = i / 3;
		}
	}

	cout << D[N] << "\n";

	int cur = N;
	while (true) {
		cout << cur << " ";
		if (cur == 1) break;
		cur = inf[cur];
	}
	return 0;
}