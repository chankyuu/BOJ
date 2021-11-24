#include <bits/stdc++.h>

using namespace std;

int N;
int D[1000002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();
	int idx = 2;

	cin >> N;
	D[1] = 0;

	while (true) {
		if (idx == N + 1)  break;

		int m1 = 0x7f7f7f7f;
		int m2 = 0x7f7f7f7f;
		int m3 = 0x7f7f7f7f;

		if (idx % 3 == 0) {
			m1 = D[idx / 3] + 1;
		}
		if (idx % 2 == 0) {
			m2 = D[idx / 2] + 1;
		}
		m3 = D[idx - 1] + 1;

		D[idx] = min(min(m1, m2), m3);
		idx++;
	}
	cout << D[N] << " ";
	return 0;
}