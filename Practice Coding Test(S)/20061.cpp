#include <bits/stdc++.h>

using namespace std;

int N;
int board[10][10];
int result = 0;
int r = 0;
// 블록 이동
void moveBlock(int t, int x, int y) {
	int nx = x + 1;
	int ny = y + 1;

	switch (t) {
	case 1:
		while (true) {
			if (nx >= 10 || board[nx][y] != 0) break;
			nx += 1;
		}
		while (true) {
			if (ny >= 10 || board[x][ny] != 0) break;
			ny += 1;
		}
		board[nx - 1][y] = 1;
		board[x][ny - 1] = 1;
		break;
	case 2:
		while (true) {
			if (nx >= 10 || (board[nx][y] != 0 || board[nx][y + 1] != 0)) break;
			nx += 1;
		}
		board[nx - 1][y] = 1;
		board[nx - 1][y + 1] = 1;

		while (true) {
			if (ny + 1 >= 10 || board[x][ny + 1] != 0) break;
			ny += 1;
		}
		board[x][ny - 1] = 1;
		board[x][ny] = 1;
		break;
	case 3:
		while (true) {
			if (nx + 1 >= 10 || board[nx + 1][y] != 0) break;
			nx += 1;
		}
		board[nx - 1][y] = 1;
		board[nx][y] = 1;

		while (true) {
			if (ny >= 10 || (board[x][ny] != 0 || board[x + 1][ny] != 0)) break;
			ny += 1;
		}
		board[x][ny - 1] = 1;
		board[x + 1][ny - 1] = 1;
		break;
	}
}
// 특별한 칸 체크
void checkSpecial() {
	int cnt = 0;
	// 초록색 보드부터
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (board[i][j] > 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt >= 1) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				board[i][j] = board[i - cnt][j];
			}
		}
	}
	for (int i = 4; i <= 5; i++) for (int j = 0; j < 4; j++) board[i][j] = 0;

	cnt = 0;

	// 파란색 보드
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (board[j][i] > 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt >= 1) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				board[j][i] = board[j][i - cnt];
			}
		}
	}

	for (int i = 4; i <= 5; i++) for (int j = 0; j < 4; j++) board[j][i] = 0;
}
// 행, 열 체크
void checkBoard() {
	for (int i = 9; i >= 6; i--) {
		bool check = true;
		for (int j = 0; j <= 3; j++) {
			if (board[i][j] == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			for (int k = i; k >= 4; k--) {
				for(int j = 0; j <= 3; j++) board[k][j] = board[k - 1][j];
			}
			result++;
			i++;
		}
	}
	// 파란색
	for (int i = 9; i >= 6; i--) {
		bool check = true;
		for (int j = 0; j <= 3; j++) {
			if (board[j][i] == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			for (int k = i; k >= 4; k--) {
				for (int j = 0; j <= 3; j++) board[j][k] = board[j][k - 1];
			}
			result++;
			i++;
		}
	}
	checkSpecial();
}
// 남은 칸 계산
void sumBoard() {
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] > 0) r++;
			if (board[j][i] > 0) r++;
		}
	}
	cout << r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 10; i++) fill(board[i], board[i] + 10, 0);
	// t = 1 -> 1x1 / t = 2 -> 1x2 / t = 3 -> 2x1 크기
	while (N--) {
		int x, y, t;
		cin >> t >> x >> y;

		moveBlock(t, x, y);
		checkBoard();
	}

	cout << result << "\n";
	sumBoard();

	return 0;
}