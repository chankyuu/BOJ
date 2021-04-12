#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int N;
int board[102][102];
bool temp[102][102];
int result = 0;
int Max = 0;

void check(int c) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > c) temp[i][j] = true;
		}
	}
}
void BFS(int height) {
	for (int i = 0; i < 102; i++) 	fill(temp[i], temp[i] + 102, false);
	check(height);

	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j] == false) continue;
			Q.push({ i, j });
			temp[i][j] = false;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (temp[nx][ny] == false) continue;
					temp[nx][ny] = false;
					Q.push({ nx, ny });
				}
			}
			result++;
			if (Max < result) Max = result;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 102; i++) fill(board[i], board[i] + 102, -1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {
		result = 0;
		BFS(i);
	}

	cout << Max;
	return 0;
}
