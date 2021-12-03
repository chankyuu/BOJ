#include <bits/stdc++.h>

using namespace std;

int N, K;
int coin[12];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) cin >> coin[i];
	for (int i = N - 1; i >= 0; i--) {
		if (K == 0) break;
		cnt += K / coin[i];
		K = K % coin[i];
	}
	cout << cnt;
	return 0;
}