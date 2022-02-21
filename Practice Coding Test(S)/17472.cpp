#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int board[12][12];
int num = 0;
int dist[7][7];
vector<pair<int, int>> Dist[7][7];
vector <pair<pair<int, int>, int>> Bridge;
bool check[7][7];
int result = 0x7f7f7f7f;
int tmp = 0;
bool visIsland[7];

// 각 섬마다 번호 붙히기
void bfs() {
	bool vis[12][12];
	for (int i = 0; i < N; i++) fill(vis[i], vis[i] + M, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			if (vis[i][j]) continue;

			vis[i][j] = true;
			num++;
			queue<pair<int, int>> Q;
			Q.push({ i, j });
			board[i][j] = num;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;

					vis[nx][ny] = true;
					board[nx][ny] = num;
					Q.push({ nx, ny });
				}
			}
		}
	}
}
// 각 섬끼리 최단거리 구하기
void checkDist() {
	bool vis[12][12];
	for (int i = 0; i < N; i++) fill(vis[i], vis[i] + M, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			if (vis[i][j] == true) continue;
			int idx = board[i][j];
			vis[i][j] = true;
			queue<pair<int, int>> Q;
			Q.push({ i, j });

			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					vector<pair<int, int>> distIdx;
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					int cnt = 0;

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (vis[nx][ny]) continue;
					if (board[nx][ny] == idx) {
						Q.push({ nx, ny });
						vis[nx][ny] = true;
						continue;
					}

					while (true) {
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
						if (board[nx][ny] != 0) {
							if (cnt <= 1) break;
							int nxtIdx = board[nx][ny];

							if (Dist[idx][nxtIdx].size() == 0) {
								Dist[idx][nxtIdx] = distIdx;
								Dist[nxtIdx][idx] = distIdx;
								break;
							}
							else {
								if (cnt < Dist[idx][nxtIdx].size()) {
									Dist[idx][nxtIdx] = distIdx;
									Dist[nxtIdx][idx] = distIdx;
									break;
								}
								else break;
							}
						}

						cnt++;
						distIdx.push_back({ nx, ny });
						nx += dx[dir];
						ny += dy[dir];
					}
				}
			}
		}
	}
}
// 하나의 섬으로 연결됐는지?
void checkIsland(int cur) {
	if (visIsland[cur]) return;
	visIsland[cur] = true;

	for (int i = 1; i <= num; i++) {
		if (cur == i) continue;
		if (check[cur][i]) {
			checkIsland(i);
		}
	}

}
// 최소거리 찾기
void bt(int cnt, int s, int Sum) {
	if (cnt >= 1) {
		// 하나로 연결됐는지 확인
		fill(visIsland, visIsland + 7, false);
		bool Flag = true;
		checkIsland(1);

		for (int i = 1; i <= num; i++) {
			if (visIsland[i] == false) {
				Flag = false;
				break;
			}
		}

		if (Flag) {
			result = min(result, Sum);
			return;
		}
	}

	for (int i = s; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			if (check[i][j]) continue;
			if (Dist[i][j].size() == 0) continue;
			// 다리 연결
			check[i][j] = true;
			check[j][i] = true;
			bt(cnt + 1, i, Sum + Dist[i][j].size());
			// 다리 해제
			check[i][j] = false;
			check[j][i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 7; i++) fill(check[i], check[i] + 7, false);

	bfs();
	checkDist();
	bt(0, 1, 0);

	if (result == 0x7f7f7f7f) result = -1;
	cout << result;
	return 0;
}