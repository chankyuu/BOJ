#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

string board[1002];
int vis[1002][1002];
int sang[1002][1002];

int T, n, m;

void BFS() {
	queue<pair<int, int>> Q1;		// 불
	queue<pair<int, int>> Q2;		// 상근이

	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + m, -1);
		fill(sang[i], sang[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '*') {
				Q1.push({ i, j });
				vis[i][j] = 0;
			}
			if (board[i][j] == '@') {
				Q2.push({ i, j });
				sang[i][j] = 0;
			}
		}
	}

	while (!Q1.empty()) {
		auto cur = Q1.front(); Q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '#' || vis[nx][ny] >= 0) continue;

			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			Q1.push({ nx, ny });
		}
	}

	while (!Q2.empty()) {
		auto cur = Q2.front(); Q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << sang[cur.X][cur.Y] + 1 << "\n";
				return;
			}

			if (board[nx][ny] == '#' || sang[nx][ny] >= 0) continue;
			if (vis[nx][ny] != -1 && sang[cur.X][cur.Y] + 1 >= vis[nx][ny]) continue;

			sang[nx][ny] = sang[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> m >> n;
		fill(board, board + n, '#');

		for (int j = 0; j < n; j++) {
			cin >> board[j];
		}

		BFS();
	}
	return 0;
}