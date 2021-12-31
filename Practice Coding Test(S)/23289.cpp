
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int R, C, K;
int W, x, y, t;
int board[22][22];
int sum[22][22];
int check[22][22];
vector<pair<int, int>> heater;
vector<pair<int, int>> place;
vector<pair<pair<int, int>, int>> wall;
bool checkPlace() {
	for (auto p : place) {
		if (sum[p.X][p.Y] < K) return false;
	}
	return true;
}
void setBoard() {
	for (int i = 0; i < R; i++) {
		if (i == 0) {
			for (int j = 0; j < C; j++) if (sum[i][j] > 0) sum[i][j] -= 1;
			continue;
		}
		if (i == R - 1) {
			for (int j = 0; j < C; j++) if (sum[i][j] > 0) sum[i][j] -= 1;
			continue;
		}
		if (sum[i][0] > 0) sum[i][0] -= 1;
		if (sum[i][C - 1] > 0) sum[i][C - 1] -= 1;
	}
}
// 1. 온풍기 바람 나옴

void heat() {
	queue<pair<int, int>> Q;

	for (int s = 0; s < heater.size(); s++) {
		auto c = heater[s];
		for (int i = 0; i < R; i++) fill(check[i], check[i] + C, 0);
		// 1:오른쪽, 2:왼쪽. 3:위쪽, 4:아래쪽
		switch (board[c.X][c.Y]) {
		case 1:
			Q.push({ c.X, c.Y + 1 });
			check[c.X][c.Y + 1] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X + i;
					int ny = cur.Y + 1;
					bool isTrue = false;

					if (nx < 0 || nx >= R || ny >= C) continue;
					if (check[nx][ny] > 0) continue;

					for (int p = 0; p < wall.size(); p++) {
						if (i == 0) {
							if (cur.X == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
						}
						else if (i == -1) {
							if (cur.X == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
							if (nx == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
						}
						else {
							if (nx == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
							if (nx == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
						}
					}
					if (isTrue) continue;

					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		case 2:
			Q.push({ c.X, c.Y - 1 });
			check[c.X][c.Y - 1] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X + i;
					int ny = cur.Y - 1;
					bool isTrue = false;

					if (nx < 0 || nx >= R || ny < 0) continue;
					if (check[nx][ny] > 0) continue;

					for (int p = 0; p < wall.size(); p++) {
						if (i == 0) {
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
						}
						else if (i == -1) {
							if (cur.X == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
						}
						else {
							if (nx == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
						}
					}
					if (isTrue) continue;

					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		case 3:
			Q.push({ c.X - 1, c.Y });
			check[c.X - 1][c.Y] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				
				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X - 1;
					int ny = cur.Y + i;
					bool isTrue = false;

					if (nx < 0 || ny >= C || ny < 0) continue;
					if (check[nx][ny] > 0) continue;

					for (int p = 0; p < wall.size(); p++) {
						if (i == 0) {
							if (cur.X == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
						}
						else if (i == -1) {
							if (cur.X == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
							if (cur.X == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
						}
						else {
							if (cur.X == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
							if (cur.X == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
						}
					}
					if (isTrue) continue;

					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		case 4:
			Q.push({ c.X + 1, c.Y });
			check[c.X + 1][c.Y] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X + 1;
					int ny = cur.Y + i;
					bool isTrue = false;

					if (nx >= R || ny >= C || ny < 0) continue;
					if (check[nx][ny] > 0) continue;

					for (int p = 0; p < wall.size(); p ++) {
						if (i == 0) {
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
						}
						else if(i == -1) {
							if (cur.X == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
						}
						else {
							if (cur.X == wall[p].X.X && cur.Y == wall[p].X.Y && wall[p].Y == 1) {
								isTrue = true;
								break;
							}
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 0) {
								isTrue = true;
								break;
							}
						}
					}
					if (isTrue) continue;

					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		default:
			break;
		}
		for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) sum[i][j] += check[i][j];
	}
}
// 2. 온도 조절
void controlTemp() {
	int tmp[22][22];
	int dif = 0;

	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) tmp[i][j] = sum[i][j];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sum[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					bool isTrue = false;

					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if (sum[i][j] <= sum[nx][ny]) continue;

					dif = (sum[i][j] - sum[nx][ny]) / 4;
					if (dif < 1) continue;

					// 벽이 있는지 확인
					for (int p = 0; p < wall.size(); p++) {
						switch (dir) {
						case 0:
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 0) isTrue = true;
							break;
						case 1:
							if (i == wall[p].X.X && j == wall[p].X.Y && wall[p].Y == 1) isTrue = true;
							break;
						case 2:
							if (i == wall[p].X.X && j == wall[p].X.Y && wall[p].Y == 0) isTrue = true;
							break;
						case 3:
							if (nx == wall[p].X.X && ny == wall[p].X.Y && wall[p].Y == 1) isTrue = true;
							break;
						default:
							break;
						}
						if (isTrue) break;
					}
					if (isTrue) continue;

					tmp[i][j] -= dif;
					tmp[nx][ny] += dif;
				}
			}
		}
	}
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) sum[i][j] = tmp[i][j];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0) {
				if (board[i][j] != 5) heater.push_back({ i, j });
				else place.push_back({ i, j });
			}
		}

	cin >> W;
	while (W--) {
		cin >> x >> y >> t;
		wall.push_back({ { x -1, y -1 }, t});
	}

	while (true) {
		heat();
		controlTemp();
		setBoard();
		cnt++;
		if (checkPlace()) break;
		if (cnt >= 101) break;
	}

	cout << cnt;
	return 0;
}
