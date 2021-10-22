#include <bits/stdc++.h>

using namespace std;

int chain[4][8];
int k;
int sum = 0;
int a, b;
bool vis[4];
void solve(int a, int b) {
	if (a < 0 || a > 3 || vis[a]) return;

	vis[a] = true;

	if (a - 1 >= 0) {
		if (chain[a - 1][2] != chain[a][6]) solve(a - 1, b * -1);
	}
	if (a + 1 <= 3) {
		if (chain[a][2] != chain[a + 1][6]) solve(a + 1, b * -1);
	}

	if (b == 1) {
		int tmp = chain[a][7];
		for (int i = 7; i > 0; i--) {
			chain[a][i] = chain[a][i - 1];
		}
		chain[a][0] = tmp;
	}
	else if (b == -1) {
		int tmp = chain[a][0];
		for (int i = 0; i < 7; i++) {
			chain[a][i] = chain[a][(i + 1) % 8];
		}
		chain[a][7] = tmp;
	}

	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	for (int i = 0; i < 4; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			chain[i][j] = tmp[j] - 48;
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> a >> b;

		a -= 1;
		fill(vis, vis + 4, false);
		solve(a, b);
	}

	for (int i = 0; i < 4; i++) {
		if (chain[i][0] == 1) {
			if (i == 0) sum += 1;
			else if (i == 1) sum += 2;
			else if (i == 2) sum += 4;
			else sum += 8;
		}
	}
	cout << sum;
	return 0;
}