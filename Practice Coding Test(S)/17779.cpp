#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
int board[22][22];
int t_board[22][22];
int result = 0x7f7f7f7f;

// 경계 나누기
void divBoard(int x, int y) {
	for (int d1 = 1; d1 <= y; d1++) {
		for (int d2 = 1; d2 < N - y; d2++) {
			if (x + d1 >= N || y - d1 < 0) continue;
			if (x + d2 >= N || y + d2 >= N) continue;
			if (x + d1 + d2 >= N || y - d1 + d2 >= N) continue;
			if (y + d2 - d1 < 0) continue;

			pair<int, int> T[4];

			T[0].X = x; T[0].Y = y;
			T[1].X = x + d1; T[1].Y = y - d1;
			T[2].X = x + d2; T[2].Y = y + d2;
			T[3].X = x + d1 + d2; T[3].Y = y - d1 + d2;

			for (int i = 0; i < N; i++) fill(t_board[i], t_board[i] + N, 5);
			
			int idx = 0;
			for(int i = 0; i < T[1].X; i++){
				if (i >= T[0].X) idx++;
				for (int j = 0; j <= T[0].Y - idx; j++) t_board[i][j] = 1;
			}
			
			idx = 0;
			for (int i = 0; i <= T[2].X; i++) {
				if (i > T[0].X) idx++;
				for (int j = T[0].Y + 1 + idx; j < N; j++) t_board[i][j] = 2;
			}

			idx = 0;
			for (int i = N - 1; i >= T[1].X; i--) {
				if (i < T[3].X) idx++;
				for (int j = 0; j < T[3].Y - idx; j++) t_board[i][j] = 3;
			}

			idx = 0;
			for (int i = N - 1; i > T[2].X; i--) {
				if (i <= T[3].X) idx++;
				for (int j = T[3].Y + idx; j < N; j++) t_board[i][j] = 4;
			}

			int cnt1 = 0;
			int cnt2 = 0;
			int cnt3 = 0;
			int cnt4 = 0;
			int cnt5 = 0;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (t_board[i][j] == 1) cnt1 += board[i][j];
					if (t_board[i][j] == 2) cnt2 += board[i][j];
					if (t_board[i][j] == 3) cnt3 += board[i][j];
					if (t_board[i][j] == 4) cnt4 += board[i][j];
					if (t_board[i][j] == 5) cnt5 += board[i][j];
				}
			}
			int Min = min(cnt1, min(cnt2, min(cnt3, min(cnt4, cnt5))));
			int Max = max(cnt1, max(cnt2, max(cnt3, max(cnt4, cnt5))));

			result = min(result, Max - Min);
			cout << t_board[0][0];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			divBoard(i, j);
		}
	}
	cout << result;

	return 0;
}
