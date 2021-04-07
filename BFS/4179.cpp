#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
string board[1002];
int arr_J[1002][1002];
int arr_F[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int BFS(queue<pair<int, int>>& J, queue<pair<int, int>>& F) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') {
				J.push({ i, j });
				arr_J[i][j] = 0;
			}
			else if (board[i][j] == 'F') {
				F.push({ i, j });
				arr_F[i][j] = 0;
			}
		}
	}
	// 불 먼저 다 채우기!
	while (!F.empty()) {
		auto cur = F.front(); F.pop();
		//cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '#' || arr_F[nx][ny] >= 0) continue;
			arr_F[nx][ny] = arr_F[cur.X][cur.Y] + 1;
			F.push({ nx,ny });
		}
	}
	// 지훈이 살리기!
	while (!J.empty()) {
		auto cur = J.front(); J.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << arr_J[cur.X][cur.Y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || arr_J[nx][ny] >= 0 || (arr_F[nx][ny] != -1 && arr_F[nx][ny] <= arr_J[cur.X][cur.Y] + 1)) continue;
			arr_J[nx][ny] = arr_J[cur.X][cur.Y] + 1;
			J.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> J;
	queue<pair<int, int>> F;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(arr_J[i], arr_J[i] + m, -1);
		fill(arr_F[i], arr_F[i] + m, -1);
	}
	for (int i = 0; i < n; i++) cin >> board[i];

	BFS(J, F);
	return 0;
}