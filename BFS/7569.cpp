#include <bits/stdc++.h>
using namespace std;
int board[102][102][102];
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
struct loc {
	int Z;
	int X;
	int Y;
};
queue<loc> Q;
int n, m, h;
int tmp = 0;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			for (int k = 0; k < 102; k++) board[i][j][k] = -1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) Q.push({ i, j, k });
			}
		}
	}
	while (!Q.empty()) {
		loc cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int nz = cur.Z + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (board[nz][nx][ny] == -1 || board[nz][nx][ny] > 0) continue;
			board[nz][nx][ny] = board[cur.Z][cur.X][cur.Y] + 1;
			Q.push({ nz, nx, ny });
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
				tmp = max(tmp, board[i][j][k]);
			}
		}
	}
	cout << tmp - 1;

	return 0;
}