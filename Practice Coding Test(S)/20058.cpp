#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[65][65];
int N, Q;
int b_size = 0;

// 시계 방향으로 보드 회전
void turnRight(pair<int, int> cur, int csize) {
	int t_board[65][65];

	for (int i = cur.X; i < cur.X + csize; i++) for (int j = cur.Y; j < cur.Y + csize; j++) t_board[i][j] = board[i][j];

	for (int i = cur.X; i < cur.X + csize; i++) {
		for (int j = cur.Y; j < cur.Y + csize; j++) {
			board[i][j] = t_board[csize - 1 - (j - cur.Y) + cur.X][(i - cur.X) + cur.Y];
		}
	}
}
// 얼음양 조사
void checkIce() {
	int t_board[65][65] = { 0, };
	for (int i = 0; i < b_size; i++) for (int j = 0; j < b_size; j++) t_board[i][j] = board[i][j];

	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (board[i][j] == 0) continue;
			int cnt = 0;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= b_size || ny < 0 || ny >= b_size) continue;
				if (board[nx][ny] > 0) cnt++;
			}
			if (cnt < 3) t_board[i][j] -= 1;
		}
	}
	for (int i = 0; i < b_size; i++) for (int j = 0; j < b_size; j++) board[i][j] = t_board[i][j];
}
// 파이어스톰
void fireStorm(int L) {
	int t_size = pow(2, L);

	for (int i = 0; i < b_size; i += t_size) {
		for (int j = 0; j < b_size; j += t_size) {
			turnRight({ i, j }, t_size);
		}
	}
}
// 남아있음 얼음의 합 구하기
int sumIce() {
	int result = 0;
	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			result += board[i][j];
		}
	}
	return result;
}
// 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수 구하기
int findBlock() {
	int maxCnt = 1;
	bool check[65][65] = { false, };

	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (board[i][j] == 0 || check[i][j]) continue;
			queue<pair<int, int>> Q;
			Q.push({ i, j });
			check[i][j] = true;
			int cnt = 1;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= b_size || ny < 0 || ny >= b_size) continue;
					if (check[nx][ny] || board[nx][ny] == 0) continue;

					check[nx][ny] = true;
					cnt++;
					Q.push({ nx, ny });
				}
			}
			if (cnt > maxCnt) maxCnt = cnt;
		}
	}
	if (maxCnt == 1) return 0;
	return maxCnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;

	b_size = pow(2, N);
	for (int i = 0; i < b_size; i++) {
		for (int j = 0; j < b_size; j++) {
			int x;
			cin >> x;
			board[i][j] = x;
		}
	}
	while (Q--) {
		int L;
		cin >> L;
		fireStorm(L);
		checkIce();
	}
	cout << sumIce() << "\n";
	cout << findBlock();
	return 0;
}