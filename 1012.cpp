#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m, k;
int cnt = 0;
int check = -1;
pair<int, int> rp;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;

	cin >> T;

	while (T--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, 0);
		}
		queue<pair<int, int>> Q;
		for (int i = 0; i < k; i++) {
			cin >> rp.X >> rp.Y;
			board[rp.X][rp.Y] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && !(vis[i][j])) Q.push({ i, j });
				while (!Q.empty()) {
					check = 1;
					auto cur = Q.front(); Q.pop();
					vis[cur.X][cur.Y] = 1;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || vis[nx][ny]) continue;
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
				if (check == 1) cnt++;
				check = -1;
			}
		}
		cout << cnt << "\n";
		cnt = 0;
	}

	return 0;
}