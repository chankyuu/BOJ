#include <bits/stdc++.h>

using namespace std;

int N, M, T;
int board[55][55];
int t_board[55][55];
// 원판 회전(d = 0 -> 시계 방향 / d = 1 -> 반시계)

void turnBoard(int x, int d, int k) {
	for (int i = 0; i < N; i++) {
		if ((i + 1) % x != 0) continue;
		int tmp[55];

		for (int j = 0; j < M; j++) tmp[j] = board[i][j];

		if (d == 0) {
			for (int j = 0; j < M; j++) board[i][j] = tmp[(M - k+ j) % M];
		}
		else {
			for (int j = 0; j < M; j++) board[i][j] = tmp[(j + k) % M];
		}
	}
}
// 인접한 수 지우기(양 옆) 없으면 더해주기
void removeNum() {
	bool Flag = false;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) t_board[i][j] = board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (t_board[i][j] == 0) continue;
			int pre = j - 1;
			int nxt = j + 1;

			int pre2 = i - 1;
			int nxt2 = i + 1;

			int cur = t_board[i][j];

			if (pre < 0) pre = M - 1;
			if (nxt >= M) nxt = 0;

			if (t_board[i][pre] == cur) {
				board[i][pre] = 0;
				board[i][j] = 0;
				Flag = true;
			}
			if (t_board[i][nxt] == cur) {
				board[i][nxt] = 0;
				board[i][j] = 0;
				Flag = true;
			}

			if (i == 0) {
				if (t_board[nxt2][j] == cur) {
					board[nxt2][j] = 0;
					board[i][j] = 0;
					Flag = true;
				}
				continue;
			}

			if (i == N - 1) {
				if (t_board[pre2][j] == cur) {
					board[pre2][j] = 0;
					board[i][j] = 0;
					Flag = true;
				}
				continue;
			}

			if (t_board[nxt2][j] == cur) {
				board[nxt2][j] = 0;
				board[i][j] = 0;
				Flag = true;
			}

			if (t_board[pre2][j] == cur) {
				board[pre2][j] = 0;
				board[i][j] = 0;
				Flag = true;
			}
		}
	}
	if (!Flag) {
		int Sum = 0;
		int d = 0;
		int n = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] > 0) {
					Sum += board[i][j];
					cnt++;
				}
			}
		}
		d = Sum / cnt;
		n = Sum % cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] > 0) {
					if (n == 0) {
						if (board[i][j] > d) board[i][j] -= 1;
						else if (board[i][j] < d) board[i][j] += 1;
					}
					else {
						if (board[i][j] > d) board[i][j] -= 1;
						else if (board[i][j] <= d) board[i][j] += 1;
					}
				}
			}
		}
	}

}
// 남은 수 계산
void sumBoard() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += board[i][j];
		}
	}
	cout << sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;
		turnBoard(x, d, k);
		removeNum();
	}
	sumBoard();
	return 0;
}
