#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;
int board[22][22];
int SIZE = 2;
int cnt = 0;
int result = 0;
queue<pair<int, int>> Q;

// 아기 상어 이동거리 측정
bool moveShark() {
	int t_board[22][22];
	int r = Q.front().X;
	int c = Q.front().Y;
	for (int i = 0; i < N; i++) fill(t_board[i], t_board[i] + N, -1);
	t_board[r][c] = 0;
	int mR = 22;
	int mC = 22;
	int mT = 22;
	int Flag = false;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (t_board[nx][ny] >= 0 || board[nx][ny] > SIZE) continue;

			if (board[nx][ny] != 0 && board[nx][ny] < SIZE && t_board[cur.X][cur.Y] + 1 <= mT) {
				if (mR > nx) {
					mR = nx;
					mC = ny;
				}
				else if (mR == nx) {
					if (mC > ny) {
						mR = nx;
						mC = ny;
					}
				}
				mT = t_board[cur.X][cur.Y] + 1;
				Flag = true;
			}

			t_board[nx][ny] = t_board[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	if (Flag) {
		//cout << t_board[0][0];
		board[mR][mC] = 0;
		cnt++;
		if (cnt == SIZE) {
			SIZE++;
			cnt = 0;
		}
		Q.push({ mR, mC });
		result += mT;
	}
	return Flag;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				Q.push({ i, j });
				board[i][j] = 0;
			}
		}
	}

	while (moveShark()) {
	}

	cout << result;
	return 0;
}