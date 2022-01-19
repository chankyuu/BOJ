#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct customer {
	int sx, sy, ex, ey;
	bool end = false;
};
int N, M, fuel;
int board[22][22];			// 0 = 빈칸, 1 = 벽
int dist[22][22];
customer customers[405];
pair<int, int> cur;

// 거리 구하기
void BFS(int x, int y) {
	for (int i = 0; i < N; i++) fill(dist[i], dist[i] + N, -1);
	queue<pair<int, int>> Q;
	
	Q.push({ x, y });
	dist[x][y] = 0;

	while (!Q.empty()) {
		auto c = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = c.X + dx[dir];
			int ny = c.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[c.X][c.Y] + 1;
			Q.push({ nx, ny });
		}
	}
}

// 최단거리 구하기
bool countMinDis() {
	for(int cnt = 0; cnt < M; cnt++){
		int minDist = 0x7f7f7f7f;
		pair<int, int> c = { 0, 0 };
		int idx = 0;
		BFS(cur.X, cur.Y);

		for (int i = 0; i < M; i++) {
			if (customers[i].end) continue;
			if (dist[customers[i].sx][customers[i].sy] < minDist) {
				c = { customers[i].sx, customers[i].sy };
				minDist = dist[customers[i].sx][customers[i].sy];
				idx = i;
			}
			else if (dist[customers[i].sx][customers[i].sy] == minDist) {
				if (c.X > customers[i].sx) {
					c = { customers[i].sx, customers[i].sy };
					minDist = dist[customers[i].sx][customers[i].sy];
					idx = i;
				}
				else if (c.X == customers[i].sx) {
					if (c.Y > customers[i].sy) {
						c = { customers[i].sx, customers[i].sy };
						minDist = dist[customers[i].sx][customers[i].sy];
						idx = i;
					}
				}
			}
		}
		cur.X = c.X;
		cur.Y = c.Y;
		customers[idx].end = true;

		// 못 갈때
		if (dist[c.X][c.Y] == -1) return false;
		fuel -= dist[c.X][c.Y];
		// 연료 부족할때
		if (fuel < 0) return false;

		BFS(cur.X, cur.Y);
		cur.X = customers[idx].ex;
		cur.Y = customers[idx].ey;

		if (dist[customers[idx].ex][customers[idx].ey] == -1) return false;

		fuel -= dist[customers[idx].ex][customers[idx].ey];
		if (fuel < 0) return false;
		fuel += 2 * dist[customers[idx].ex][customers[idx].ey];
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, nx, ny;
	int cnt = 2;
	cin >> N >> M >> fuel;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

	cin >> x >> y;
	
	cur.X = x - 1; cur.Y = y - 1;

	for(int i = 0; i < M; i++) {
		cin >> x >> y >> nx >> ny;
		customers[i] = { x - 1, y - 1, nx - 1, ny - 1, false };
	}

	if (countMinDis()) cout << fuel;
	else  cout << "-1";

	return 0;
}