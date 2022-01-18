#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
int board[52][52];

struct fireBall {
	int r = 0;					// 파이어볼 위치(행)
	int c = 0;					// 파이어볼 위치(열)
	int m = 0;					// 질량
	int s = 0;					// 속력
	int d = 0;					// 방향
};

vector<fireBall> fireBalls;

// 파이어볼 이동
void moveFire() {
	for (int i = 0; i < fireBalls.size(); i++) {
		fireBall fb = fireBalls[i];
		for (int j = 1; j <= fb.s; j++) {
			fb.r += dx[fb.d];
			fb.c += dy[fb.d];

			if (fb.r < 0)  fb.r = N - 1;
			if (fb.r >= N) fb.r = 0;
			if (fb.c < 0) fb.c = N - 1;
			if (fb.c >= N) fb.c = 0;
		}
		fireBalls[i].r = fb.r;
		fireBalls[i].c = fb.c;
		board[fb.r][fb.c]++;
	}
	// 파이어볼 합치고 삭제
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] >= 2) {
				vector<bool> t;
				fireBall tmp;

				tmp.r = i;
				tmp.c = j;

				for (int k = 0; k < fireBalls.size(); k++) {
					if (i == fireBalls[k].r && j == fireBalls[k].c) {
						tmp.m += fireBalls[k].m;
						tmp.s += fireBalls[k].s;

						if(fireBalls[k].d % 2 == 0) t.push_back(true);
						else t.push_back(false);

						fireBalls.erase(fireBalls.begin() + k);
						k--;
					}
				}
				bool flag = true;
				for (int k = 1; k < t.size(); k++) {
					if (t[0] == t[k]) flag = true;
					else {
						flag = false;
						break;
					}
				}
				tmp.m /= 5;
				tmp.s /= board[i][j];

				if (tmp.m == 0) {
					board[i][j] = 0; 
					continue;
				}
				if (flag) {
					for (int dir = 0; dir < 8; dir += 2) {
						pair<int, int> cur = { i, j };
						tmp.d = dir;
						cur.X += dx[tmp.d];
						cur.Y += dy[tmp.d];

						if (cur.X < 0)  cur.X = N - 1;
						if (cur.X >= N) cur.X = 0;
						if (cur.Y < 0) cur.Y = N - 1;
						if (cur.Y >= N) cur.Y = 0;

						tmp.r = cur.X;
						tmp.c = cur.Y;
						fireBalls.push_back(tmp);
					}
				}
				else {
					for (int dir = 1; dir < 8; dir += 2) {
						pair<int, int> cur = { i,j };
						tmp.d = dir;
						cur.X += dx[tmp.d];
						cur.Y += dy[tmp.d];

						if (cur.X < 0)  cur.X = N - 1;
						if (cur.X >= N) cur.X = 0;
						if (cur.Y < 0) cur.Y = N - 1;
						if (cur.Y >= N) cur.Y = 0;

						tmp.r = cur.X;
						tmp.c = cur.Y;

						fireBalls.push_back(tmp);
					}
				}
				board[i][j] = 0;
			}
		}
	}
	cout << fireBalls.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;

	cin >> N >> M >> K;

	while (M--) {
		fireBall fb;
		cin >> fb.r >> fb.c >> fb.m >> fb.s >> fb.d;
		fb.r -= 1;
		fb.c -= 1;
		fireBalls.push_back(fb);
	}

	for (int i = 0; i < N; i++) fill(board[i], board[i] + N, 0);

	while (K--) {
		moveFire();
	}

	for (int i = 0; i < fireBalls.size(); i++) result += fireBalls[i].m;

	cout << result;
	return 0;
}