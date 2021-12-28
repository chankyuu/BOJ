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
int wall[22][22];
int check[22][22];
vector<pair<int, int>> heater;
vector<pair<int, int>> place;
bool checkPlace() {
	for (auto p: place) {
		if (sum[p.X][p.Y] < K) return false;
	}
	return true;
}
// 1. 온풍기 바람 나옴
void heat() {
	queue<pair<int, int>> Q;

	for (int i = 0; i < R; i++) fill(check[i], check[i] + C, 0);

	for (int s = 0; s < heater.size(); s++) {
		auto c = heater[s];

		// 1:오른쪽, 2:왼쪽. 3:위쪽, 4:아래쪽
		switch (board[c.X][c.Y]) {
		case 1 :
			Q.push({ c.X, c.Y + 1 });
			check[c.X][c.Y + 1] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X + i;
					int ny = cur.Y + 1;

					if (nx < 0 || nx >= R || ny >= C) continue;
					if (check[nx][ny] > 0) continue;

					if (i == 0) {
						if (wall[cur.X][cur.Y] && wall[cur.X][ny]) continue;
					}
					else {
						if (wall[cur.X][cur.Y] && wall[nx][cur.Y]) continue;
						if (wall[nx][cur.Y] && wall[nx][ny]) continue;
					}
					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		case 2 :
			Q.push({ c.X, c.Y - 1 });
			check[c.X][c.Y - 1] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X + i;
					int ny = cur.Y - 1;

					if (nx < 0 || nx >= R || ny < 0) continue;
					if (check[nx][ny] > 0) continue;

					if (i == 0) {
						if (wall[cur.X][cur.Y] && wall[cur.X][ny]) continue;
					}
					else {
						if (wall[cur.X][cur.Y] && wall[nx][cur.Y]) continue;
						if (wall[nx][cur.Y] && wall[nx][ny]) continue;
					}
					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		case 3 :
			Q.push({ c.X - 1, c.Y});
			check[c.X - 1][c.Y] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X - 1;
					int ny = cur.Y + i;

					if (nx < 0 || ny >= C || ny < 0) continue;
					if (check[nx][ny] > 0) continue;

					if (i == 0) {
						if (wall[cur.X][cur.Y] && wall[nx][cur.Y]) continue;
					}
					else {
						if (wall[cur.X][cur.Y] && wall[cur.X][ny]) continue;
						if (wall[cur.X][ny] && wall[nx][ny]) continue;
					}
					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		case 4 :
			Q.push({ c.X - 1, c.Y });
			check[c.X + 1][c.Y] = 5;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (check[cur.X][cur.Y] <= 1) continue;

				for (int i = -1; i < 2; i++) {
					int nx = cur.X + 1;
					int ny = cur.Y + i;

					if (nx >= R || ny >= C || ny < 0) continue;
					if (check[nx][ny] > 0) continue;

					if (i == 0) {
						if (wall[cur.X][cur.Y] && wall[nx][cur.Y]) continue;
					}
					else {
						if (wall[cur.X][cur.Y] && wall[cur.X][ny]) continue;
						if (wall[cur.X][ny] && wall[nx][ny]) continue;
					}
					check[nx][ny] = check[cur.X][cur.Y] - 1;
					Q.push({ nx, ny });
				}
			}
			break;
		default :
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

					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if (wall[i][j] && wall[nx][ny]) continue;

					if (sum[i][j] > sum[nx][ny]) {
						dif = (sum[i][j] - sum[nx][ny]) / 4;
						tmp[i][j] -= dif;
						tmp[i][j] += dif;
					}
					else {
						dif = (sum[nx][ny] - sum[i][j]) / 4;
						tmp[i][j] += dif;
						tmp[i][j] -= dif;
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) sum[i][j] += tmp[i][j];
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
				if(board[i][j] != 5) heater.push_back({ i, j });
				else place.push_back({ i, j });
			}
		}

	cin >> W;
	while (W--) {
		cin >> x >> y >> t;
		if (t == 0) {
			wall[x][y] = 1;
			wall[x - 1][y] = 1;
		}
		else {
			wall[x][y] = 1;
			wall[x][y + 1] = 1;
		}
	}

	while (true) {
		heat();
		controlTemp();
		cnt++;
		if (checkPlace) break;
	}

	cout << cnt;
	return 0;
}