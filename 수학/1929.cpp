#include <bits/stdc++.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> M >> N;

	vector<bool> state(N + 1, true);
	state[1] = false;
	for (int i = 2; i*i <= N; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			state[j] = false;
		}
	}

	for (int i = M; i <= N; i++) if(state[i]) cout << i << "\n";

	return 0;
}