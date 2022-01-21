#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int result = 0;
struct fish {
	int num;
	int dir;
};

fish board[4][4];
bool isAlive[17];
pair<int, int> sharkP;
int sharkD;

// 물고기 움직이기
void moveFish() {
	for (int idx = 1; idx <= 16; idx++) {
		bool Flag = false;
		if (!isAlive[idx]) continue;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j].num != idx) continue;

				for (int dir = 0; dir < 8; dir++) {
					int nx = i + dx[board[i][j].dir];
					int ny = j + dy[board[i][j].dir];

					if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || board[nx][ny].num == -1) {
						board[i][j].dir = (board[i][j].dir + 1) % 8;
						continue;
					}
					swap(board[i][j], board[nx][ny]);
					Flag = true;
					break;
				}
				if (Flag) break;
			}
			if (Flag) break;
		}
	}
}
// 최적 해 찾기
void findMax(int r) {
	result = max(result, r);

	moveFish();

	fish t_board[4][4];
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) t_board[i][j] = board[i][j];

	for (int i = 1; i <= 3; i++) {
		int nx = sharkP.X + dx[sharkD] * i;
		int ny = sharkP.Y + dy[sharkD] * i;
		int cx = sharkP.X;
		int cy = sharkP.Y;
		int cd = sharkD;
		int tNum;

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) return;
		if (board[nx][ny].num == 0) continue;

		tNum = board[nx][ny].num;
		
		sharkP = { nx, ny };
		sharkD = board[nx][ny].dir;
		isAlive[tNum] = false;
		r += tNum;
		board[nx][ny].num = -1;
		board[cx][cy].num = 0;

		findMax(r);
		
		for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) board[j][k] = t_board[j][k];

		sharkP = { cx, cy };
		sharkD = cd;
		isAlive[tNum] = true;
		r -= tNum;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fish tmp;
			cin >> tmp.num >> tmp.dir;
			tmp.dir -= 1;
			board[i][j] = tmp;
		}
	}
	fill(isAlive, isAlive + 17, true);
	// 초기 상태(0,0)에 상어가 진입
	result = board[0][0].num;
	sharkP = { 0, 0 };
	sharkD = board[0][0].dir;
	isAlive[board[0][0].num] = false;
	board[0][0].num = -1;

	findMax(result);

	cout << result;
	return 0;
}