#include <bits/stdc++.h>

using namespace std;

int N = 10;
int board[12][12];
int rest[5] = { 5, 5, 5, 5, 5 };
int result = 0x7f7f7f7f;

// 붙힐 수 있나 검사
bool check(int s, int a, int b) {
	if (a + s > 10 || b + s > 10) return false;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (!board[a + i][b + j]) return false;
		}
	}
	return true;
}
// 색종이 붙히기
void Add(int s, int a, int b) {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			board[a + i][b + j] = 0;
		}
	}
}
// 색종이 떼기
void Minus(int s, int a, int b) {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			board[a + i][b + j] = 1;
		}
	}
}
// dfs
void dfs(int x, int y, int cnt) {
	if (cnt >= result) return;

	while (board[x][y] == 0) {
		y++;
		if (y >= 10) {
			x++;
			y = 0;
			if (x >= 10) {
				// 남은거 없으면 결과값 갱신
				result = min(result, cnt);
				return;
			}
		}
	}
	for (int s = 5; s >= 1; s--) {
		if (rest[s - 1] < 1) continue;

		if (check(s, x, y)) {
			rest[s - 1]--;
			Add(s, x, y);

			dfs(x, y, cnt + 1);

			rest[s - 1]++;
			Minus(s, x, y);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> board[i][j];
	
	dfs(0, 0, 0);

	if (result == 0x7f7f7f7f) result = -1;
	cout << result;
	return 0;
}