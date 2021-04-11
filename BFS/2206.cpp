#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int N, M;
string tmp[1002];
bool isused[1002][1002];
int board0[1002][1002];
int boardN[1002][1002];
int dist = 1002 * 1002;
void BFS() {
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	board0[0][0] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board0[nx][ny] >= 1 || isused[nx][ny] == 1) continue;
			board0[nx][ny] = board0[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	Q.push({ N - 1, M - 1 });
	boardN[N - 1][M - 1] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (boardN[nx][ny] >= 1 || isused[nx][ny] == 1) continue;
			boardN[nx][ny] = boardN[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	if (board0[N - 1][M - 1] > 0) dist = board0[N - 1][M - 1];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isused[i][j] == 0) continue;
			int dist0 = 1002 * 1002;
			int distN = 1002 * 1002;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (board0[nx][ny] > 0) dist0 = min(dist0, board0[nx][ny]);
				if (boardN[nx][ny] > 0) distN = min(distN, boardN[nx][ny]);
			}
			dist = min(dist, dist0 + distN + 1);
		}
	}
	if (dist == 1002 * 1002) cout << "-1";
	else cout << dist;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> tmp[i];

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) isused[i][j] = tmp[i][j] - '0';
	for (int i = 0; i < N; i++) {
		fill(board0[i], board0[i] + 1002, 0);
		fill(boardN[i], boardN[i] + 1002, 0);
	}

	BFS();

	return 0;
}
