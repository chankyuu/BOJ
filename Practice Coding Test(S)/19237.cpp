#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M, K;

struct shark {
	int num;
	int smell;
	int dir;
};

shark board[22][22];
shark t_board[22][22];
int sharkP[405][4][4];

// 방향 바꾸기
int changeDir(int x, int y, int n, int d, int cnt) {
	// 빈칸이 없으면
	if (cnt == 4) {
		for (int i = 0; i < 4; i++) {
			int tmp = sharkP[board[x][y].num][board[x][y].dir][i];
			int nx = x + dx[tmp];
			int ny = y + dy[tmp];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			if (board[nx][ny].num == board[x][y].num) return tmp;
		}
	}

	int dir;
	
	dir = sharkP[n][d][cnt];

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	

	if (nx < 0 || nx >= N || ny < 0 || ny >= N || t_board[nx][ny].smell != 0) {
		return changeDir(x, y, n, d, cnt + 1);
	}
	else	return dir;
}
// 냄새 제거
void removeSmell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].smell > 0 && board[i][j].dir == -1) board[i][j].smell -= 1;
			if (board[i][j].smell == 0) {
				board[i][j].num = 0;
				board[i][j].dir = 0;
			}
		}
	}
}
// 상어 이동
void moveShark() {
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) t_board[i][j] = board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (t_board[i][j].num == 0 || t_board[i][j].dir == -1) continue;
			int dir = board[i][j].dir;

			dir = changeDir(i, j, board[i][j].num, dir, 0);
			
			board[i][j].dir = dir;

			int nx = i + dx[dir];
			int ny = j + dy[dir];

			if (board[nx][ny].num != 0 && board[nx][ny].num != board[i][j].num) {
				if (board[nx][ny].num > board[i][j].num) {
					board[nx][ny].num = board[i][j].num;
					board[nx][ny].smell = K;
					board[nx][ny].dir = board[i][j].dir;
				}
				board[i][j].dir = -1;
				continue;
			}

			board[nx][ny].num = board[i][j].num;
			board[nx][ny].smell = K;
			board[nx][ny].dir = board[i][j].dir;
			board[i][j].dir = -1;
		}
	}
}
// 해답 체크
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].num >= 2 && board[i][j].dir != -1) return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;
	int tmp[22];

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			board[i][j].num = n;
			if (n != 0) board[i][j].smell = K;
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp[i];
		tmp[i] -= 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].num == 0) continue;
			board[i][j].dir = tmp[board[i][j].num - 1];
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int d;
				cin >> d;
				sharkP[i][j][k] = d - 1;
			}
		}
	}

	while (!check()) {
		moveShark();
		removeSmell();
		result++;

		if (result >= 1000) {
			result = -1;
			break;
		}
	}

	cout << result;
	return 0;
}