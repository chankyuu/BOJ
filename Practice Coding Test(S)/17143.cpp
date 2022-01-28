#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int R, C, M;
// s �ӷ�, d �̵�����, z ũ��
struct shark {
	int s = 0;
	int d = 0;
	int z = 0;
};
shark board[102][102];

// ���� ��ȯ
int changeDir(int dir) {
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
}
// ��� �̵�
void moveShark() {
	shark t_board[102][102];
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) t_board[i][j] = board[i][j];
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) board[i][j] = { 0, 0, 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (t_board[i][j].z < 1) continue;
			int dir = t_board[i][j].d;
			int speed;
			int round;

			int nx = i;
			int ny = j;

			// �� k ��ŭ �̵�
			if (dir == 1 || dir == 2) {
				round = (R - 1) * 2;
				speed = t_board[i][j].s % round;
			}
			else {
				round = (C - 1) * 2;
				speed = t_board[i][j].s % round;
			}

			while (speed--) {
				nx += dx[dir];
				ny += dy[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
					nx -= dx[dir];
					ny -= dy[dir];

					dir = changeDir(dir);

					nx += dx[dir];
					ny += dy[dir];
				}
			}
			t_board[i][j].d = dir;

			if (board[nx][ny].z > 1) {
				if (t_board[i][j].z > board[nx][ny].z) board[nx][ny] = t_board[i][j];
				else if (t_board[i][j].z == board[nx][ny].z) board[nx][ny].d = dir;
			}
			else 	board[nx][ny] = t_board[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int result = 0;

	cin >> R >> C >> M;

	while (M--) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		board[r - 1][c - 1] = { s, d, z };
	}

	// ���ÿ� �̵�
	for (int i = 0; i < C; i++) {
		// ��� ���
		for (int j = 0; j < R; j++) {
			if (board[j][i].z >= 1) {
				result += board[j][i].z;
				board[j][i] = { 0 , 0, 0 };
				break;
			}
		}
		// ��� �̵�
		moveShark();
	}
	cout << result;

	return 0;
}