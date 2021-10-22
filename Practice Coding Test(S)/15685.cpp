#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

vector<int> inf;
int board[102][102];
int N;
int x, y, d, g;
int cnt = 0;

void solve() {
	for (int i = 0; i < g; i++) {
		int size = inf.size() - 1;
		for (int j = size; j >= 0; j--) {
			x = x + dx[(inf[j] + 1) % 4];
			y = y + dy[(inf[j] + 1) % 4];

			board[x][y] = 1;
			inf.push_back((inf[j] + 1) % 4);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N;

	for (int i = 0; i < 102; i++) fill(board[i], board[i] + 102, 0);
	for (int i = 0; i < N; i++) {
		inf.clear();
		cin >> y >> x >> d >> g;
		
		board[x][y] = 1;
		
		x += dx[d];
		y += dy[d];
		
		board[x][y] = 1;
		inf.push_back(d);

		solve();
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1 && board[i][j+1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1) cnt++;
		}
	}
	cout << cnt;

	return 0;
}