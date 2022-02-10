#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int board[12][12];
int result = 0;

pair<int, int > R, B;

// 구슬 움직이기
void moveMarble(pair<int, int> r, pair<int, int> b, int cnt, int dir) {
	if (cnt >= 10) return;
	if (result == 1) return;
	
	pair<int, int> nR = r;
	pair<int, int> nB = b;
	bool rFlag = false;
	bool bFlag = false;

	while (true) {
		if (board[nR.X][nR.Y] == -1) break;
		if (board[nR.X][nR.Y] == -2) {
			rFlag = true;
			break;
		}
		nR.X += dx[dir];
		nR.Y += dy[dir];
	}
	nR.X -= dx[dir];
	nR.Y -= dy[dir];

	while (true) {
		if (board[nB.X][nB.Y] == -1) break;
		if (board[nB.X][nB.Y] == -2) {
			bFlag = true;
			break;
		}
		nB.X += dx[dir];
		nB.Y += dy[dir];
	}
	nB.X -= dx[dir];
	nB.Y -= dy[dir];

	if (nR == nB) {
		int rD = abs(r.X - nR.X) + abs(r.Y - nR.Y);
		int bD = abs(b.X - nB.X) + abs(b.Y - nB.Y);

		if (rD > bD) {
			nR.X -= dx[dir];
			nR.Y -= dy[dir];
		}
		else if (rD < bD) {
			nB.X -= dx[dir];
			nB.Y -= dy[dir];
		}
	}

	if (bFlag) return;
	else {
		if (rFlag) {
			result = 1;
			return;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (i == dir) continue;
		if (i == 0 && dir == 2) continue;
		if (i == 1 && dir == 3) continue;
		if (i == 2 && dir == 0) continue;
		if (i == 3 && dir == 1) continue;

		moveMarble(nR, nB, cnt + 1, i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '.') board[i][j] = 0;
			else if (c == '#') board[i][j] = -1;
			else if (c == 'O') board[i][j] = -2;
			else if (c == 'R') {
				board[i][j] = 0;
				R = { i, j };
			}
			else if (c == 'B') {
				board[i][j] = 0;
				B = { i, j };
			}
		}
	}
	//for (int i = 0; i < 4; i++) moveMarble(R, B, 0, i);

	moveMarble(R, B, 0, 3);
	moveMarble(R, B, 1, 0);
	moveMarble(R, B, 2, 1);
	moveMarble(R, B, 3, 0);
	moveMarble(R, B, 4, 3);
	cout << result;
	return 0;
}