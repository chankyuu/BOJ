#include <bits/stdc++.h>

using namespace std;

int board[42][42];
int N, M, K;
int R, C;
int sticker[12][12];
bool isCan = true;
void turn_s () {
	int tmp[12][12];
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp[j][R - (i + 1)] = sticker[i][j];
		}
	}
	
	for (int i = 0; i < 12; i++) fill(sticker[i], sticker[i] + 12, 0);
	swap(R, C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sticker[i][j] = tmp[i][j];
		}
	}
}
bool check(int x, int y) {
	if (R > N || C > M) return false;
	if (x + (R - 1) >= N || y + (C - 1) >= M) {
		return false;
	}

	int tX = 0;
	int tY = 0;

	for (int i = x; i < x + R; i++) {
		for (int j = y; j < y + C; j++) {
			if (board[i][j] == 1 && sticker[tX][tY] == 1) {
				return false;
			}
			tY = (tY + 1) % C;
		}
		tX = (tX + 1) % R;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int sum = 0;
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) fill(board[i], board[i] + M, 0);

	for (int cnt = 0; cnt < K; cnt++) {
		int x = 0;
		int y = 0;
		int c = 0;

		cin >> R >> C;

		for (int i = 0; i < R; i++) fill(sticker[i], sticker[i] + C, 0);

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> sticker[i][j];
			}
		}
		while(true){
			isCan = check(x, y);

			if (isCan) {
				int tX = 0;
				int tY = 0;
				for (int i = x; i < x + R; i++) {
					for (int j = y; j < y + C; j++) {
						if (sticker[tX][tY] == 1) board[i][j] = 1;
						tY = (tY + 1) % C;
					}
					tX = (tX + 1) % R;
				}
				break;
			}

			y++;
			if (y == M) {
				x++;

				if (x == N) {
					x = 0;
					turn_s();
					c++;
				}
				y = 0;
			}

			if (c == 4) break;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) sum++;
		}
	}
	cout << sum;
	return 0;
}