#include <bits/stdc++.h>

using namespace std;

int D[1002][1002];
int mod = 10007;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;

	for (int i = 0; i <= N; i++) fill(D[i], D[i] + N, 1);
	// D[i][j] = iCj
	for (int i = 1; i <= N; i++) D[i][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j]) % 10007;
		}
	}
	cout << D[N][K];

	return 0;
}