#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;
int board[102][102];
int result[102];
int cnt = 0;
int meter = 0;
void BFS() {
	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				cnt++;
				Q.push({ i, j });

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] == -1 || board[nx][ny] > 0) continue;
						board[nx][ny] = ++meter;
						Q.push({ nx, ny });
					}
				}
				if (meter == 0) result[cnt - 1] = meter + 1;
				else result[cnt - 1] = meter;
				meter = 0;
			}
		}
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 102; i++) fill(board[i], board[i] + 102, 0);
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				board[j][k] = -1;
			}
		}
	}

	BFS();
	sort(result, result + cnt);
	cout << cnt << "\n";

	for (int i = 0; i < cnt; i++) cout << result[i] << " ";
	return 0;
}
