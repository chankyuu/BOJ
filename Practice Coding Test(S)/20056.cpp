#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;

struct fireBall {
	int r = 0;					// 파이어볼 위치(행)
	int c = 0;					// 파이어볼 위치(열)
	int m = 0;					// 질량
	int s = 0;					// 속력
	int d = 0;					// 방향
};

vector<fireBall> board[52][52];
vector<fireBall> fireBalls;

// 파이어볼 이동
void moveFire() {
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board[i][j].clear();

	for (int i = 0; i < fireBalls.size(); i++) {
		fireBall fb = fireBalls[i];
		fb.r += dx[fb.d] * fb.s;
		fb.c += dy[fb.d] * fb.s;

		while (fb.r < 0)  fb.r += N;
		while (fb.r >= N) fb.r -= N;
		while (fb.c < 0) fb.c += N;
		while (fb.c >= N) fb.c -= N;
		
		fireBalls[i].r = fb.r;
		fireBalls[i].c = fb.c;
		board[fb.r][fb.c].push_back(fb);
	}
	// 파이어볼 합치고 삭제
	vector<fireBall> tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j].size() == 1) tmp.push_back(board[i][j][0]);
			if (board[i][j].size() >= 2) {
				vector<bool> t;
				int mass = 0;
				int speed = 0;

				for (int k = 0; k < board[i][j].size(); k++) {
					mass += board[i][j][k].m;
					speed += board[i][j][k].s;

					if(board[i][j][k].d % 2 == 0) t.push_back(true);
					else t.push_back(false);
				}
				bool flag = true;
				for (int k = 1; k < t.size(); k++) {
					if (t[0] == t[k]) flag = true;
					else {
						flag = false;
						break;
					}
				}
				mass /= 5;
				speed /= board[i][j].size();

				if (mass == 0) 	continue;
				
				if (flag) {
					for (int dir = 0; dir < 8; dir += 2) {
						tmp.push_back({ i, j, mass, speed, dir });
					}
				}
				else {
					for (int dir = 1; dir < 8; dir += 2) {
						tmp.push_back({ i, j, mass, speed, dir });
					}
				}
			}
		}
	}
	fireBalls = tmp;
	//cout << fireBalls.size();
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

	while (K--) {
		moveFire();
	}

	for (int i = 0; i < fireBalls.size(); i++) result += fireBalls[i].m;

	cout << result;
	return 0;
}
