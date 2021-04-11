#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int N;
int color[102][102];
bool isused[102][102];
int result = 0;
void BFS1() {
	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isused[i][j]) {
				isused[i][j] = 1;
				result++;
				Q.push({ i, j });

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (isused[nx][ny]) continue;
						if (color[nx][ny] == color[cur.X][cur.Y]) {
							isused[nx][ny] = 1;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
	}
}
void BFS2() {
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isused[i][j]) {
				isused[i][j] = 1;
				result++;
				Q.push({ i, j });

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (isused[nx][ny]) continue;
						if ((color[nx][ny] == color[cur.X][cur.Y]) || (color[nx][ny] == 1 && color[cur.X][cur.Y] == 2) || (color[nx][ny] == 2 && color[cur.X][cur.Y] == 1)) {
							isused[nx][ny] = 1;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char a;

	for (int i = 0; i < N; i++) fill(color[i], color[i] + 102, 0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a == 'R') color[i][j] = 1;
			else if (a == 'G') color[i][j] = 2;
			else color[i][j] = 3;
		}
	}
	BFS1();
	cout << result << " ";

	result = 0;
	for (int i = 0; i < N; i++) fill(isused[i], isused[i] + 102, 0);

	BFS2();
	cout << result;
	return 0;
}
