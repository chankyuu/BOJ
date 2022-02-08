#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int N, M;
int board[12][12];
int result = 0x7f7f7f7f;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

pair<int, int> R, B;
// 최소 값 찾기
void back(int Rx, int Ry, int Bx, int By, int cnt, int D) {
	if (cnt > 11) return;
	if (cnt >= result) return;

	bool Rflag = false;
	bool Bflag = false;
	// 순서대로 왼, 오, 위, 아래로 기울이기
	int nxR = Rx + dx[D];
	int nyR = Ry + dy[D];

	while (true) {
		if (board[nxR][nyR] == -1) break;
		if (board[nxR][nyR] == -2) {
			Rflag = true;
			break;
		}
		nxR += dx[D];
		nyR += dy[D];
	}
	nxR -= dx[D];
	nyR -= dy[D];

	int nxB = Bx + dx[D];
	int nyB = By + dy[D];

	while (true) {
		if (board[nxB][nyB] == -1) break;
		if (board[nxB][nyB] == -2) {
			Bflag = true;
			break;
		}
		nxB += dx[D];
		nyB += dy[D];
	}
	nxB -= dx[D];
	nyB -= dy[D];

	if (Bflag) return;
	else {
		if (Rflag) {
			result = min(result, cnt);
			return;
		}
	}

	if (nxR == nxB && nyR == nyB) {
		int rD = abs(Rx - nxR) + abs(Ry - nyR);
		int bD = abs(Bx - nxB) + abs(By - nyB);

		if (rD > bD) {
			nxR -= dx[D];
			nyR -= dy[D];
		}
		else if(rD < bD){
			nxB -= dx[D];
			nyB -= dy[D];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		if (D == dir) continue;
		if (D == 0 && dir == 1) continue;
		if (D == 1 && dir == 0) continue;
		if (D == 2 && dir == 3) continue;
		if (D == 3 && dir == 2) continue;

		back(nxR, nyR, nxB, nyB, cnt + 1, dir);
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
			if (c == '#') board[i][j] = -1;
			else if (c == '.') board[i][j] = 0;
			else if (c == 'B') {
				board[i][j] = 0;
				B = { i, j };
			}
			else if (c == 'R') {
				board[i][j] = 0;
				R = { i, j };
			}
			else if (c == 'O') board[i][j] = -2;
		}
	}
	for(int i = 0; i < 4; i++) back(R.X, R.Y, B.X, B.Y, 1, i);

	if (result == 0x7f7f7f7f) cout << "-1";
	else cout << result;

	return 0;
}