#include <bits/stdc++.h>

using namespace std;

int N, M, H;
bool board[32][12];
int result = 0x7f7f7f7f;

// 사다리 타기
bool sadari() {
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (board[j][cur]) cur += 1;
			else if (board[j][cur - 1]) cur -= 1;
		}
		if (cur != i) return false;
	}
	return true;
}
// 사다리 조작
void control(int idx, int cnt) {
	if (cnt > 3) {
		return;
	}

	if (sadari()) {
		result = min(result, cnt);
		return;
	}

	for (int i = idx; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if (board[j][i]) continue;
			if (board[j][i - 1]) continue;
			if (board[j][i + 1]) continue;

			board[j][i] = true;
			control(i, cnt + 1);
			board[j][i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;

	for (int i = 0; i < 32; i++) for (int j = 0; j < 12; j++) board[i][j] = false;

	while (M--) {
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
	}

	control(1, 0);

	if (result == 0x7f7f7f7f) cout << "-1";
	else cout << result;
	return 0;
}