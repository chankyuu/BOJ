#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;
int board[52][52];
int b1 = 0;
int b2 = 0;
int b3 = 0;

// 얼음 파편 던지기(d = 방향, s = 거리)
void snowBall(int d, int s) {
	int t = 1;
	pair<int, int> cur = { N / 2, N / 2 };
	while (true) {
		int nx = cur.X + dx[d] * t;
		int ny = cur.Y + dy[d] * t;

		board[nx][ny] = 0;
		t++;
		if (t > s) break;
	}
}
// 구슬 움직이기
void moveMarble(pair<int, int> cur, int count, int dis, int n, int d) {
	bool isEnd = false;
	int s = dis;
	int dir = d;
	
	for (int i = n; i < 2; i++) {
		for (int j = count; j < s; j++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			board[cur.X][cur.Y] = board[nx][ny];

			cur.X = nx;
			cur.Y = ny;
			if (nx == 0 && ny == 0) {
				board[nx][ny] = 0;
				return;
			}
		}
		count = 0;
		switch (dir) {
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
	}
	s++;
	
	//	moveMarble({ cur.X, cur.Y }, j + 1, s, i, dir)
	// 구슬은 인덱스 0, 2, 1, 3 순으로 움직임
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				board[cur.X][cur.Y] = board[nx][ny];

				cur.X = nx;
				cur.Y = ny;

				if (nx == 0 && ny == 0) {
					board[nx][ny] = 0;
					isEnd = true;
					break;
				}
			}
			if (isEnd) break;

			switch (dir) {
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
		s++;

		if (isEnd) break;
	}
}
// 구슬 체크
void checkMarble() {
	pair<int, int> cur = { N / 2, N / 2 };
	bool isEnd = false;
	int s = 1;
	int dir = 2;
	// 인덱스 체크는 2, 1, 3, 0 순으로
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				cur.X += dx[dir];
				cur.Y += dy[dir];
				
				if (cur.X == 0 && cur.Y == 0) {
					isEnd = true;
					break;
				}
				if (board[cur.X][cur.Y] != 0) continue;

				while (board[cur.X][cur.Y] == 0) {
					int board_t[52][52];
					bool flag = false;
					for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board_t[i][j] = board[i][j];

					moveMarble({ cur.X, cur.Y }, j + 1, s, i, dir);

					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							if (board[i][j] != board_t[i][j]) {
								flag = true;
								break;
							}
						}
						if (flag) break;
					}
					if (!flag) break;
				}
			}
			if (isEnd) break;

			switch (dir) {
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
		s++;
		if (isEnd) break;
	}
}
// 구슬 폭발
bool explosionMarble() {
	pair<int, int> cur = { N / 2, N / 2 };
	bool isEnd = false;
	int s = 1;
	int dir = 2;
	int cnt = 0;
	bool flag = true;
	vector<pair<int, int>> sameR;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx == 0 && ny == 0) {
					isEnd = true;
					break;
				}
				if (board[nx][ny] == 0) {
					cur.X = nx;
					cur.Y = ny;
					continue;
				}
				if (board[nx][ny] == board[cur.X][cur.Y]) {
					cnt++;
					sameR.push_back({ cur.X, cur.Y });
				}
				else {
					if (cnt >= 3) {
						for (auto t : sameR) {
							board[t.X][t.Y] = 0;
						}
						if (board[cur.X][cur.Y] == 1) b1 += (cnt + 1);
						else if (board[cur.X][cur.Y] == 2) b2 += (cnt + 1);
						else b3 += (cnt + 1);

						board[cur.X][cur.Y] = 0;
						flag = false;
					}
					cnt = 0;
					sameR.clear();
				}
				cur.X = nx;
				cur.Y = ny;
			}
			if (isEnd) break;

			switch (dir) {
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
		s++;

		if (isEnd) break;
	}
	return flag;
}
// 마지막 보드 변하기
void changeBoard() {
	pair<int, int> cur = { N / 2 , N / 2 };
	bool isEnd = false;
	int s = 1;
	int dir = 2;
	int cnt = 1;
	queue<pair<int, int>> sameR;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (board[cur.X][cur.Y] == 0) {
					isEnd = true;
					break;
				}
				if (board[nx][ny] == board[cur.X][cur.Y]) {
					cnt++;
				}
				else {
					if (board[cur.X][cur.Y] == -1) {
						cur.X = nx;
						cur.Y = ny;
						continue;
					}
					sameR.push({ cnt, board[cur.X][cur.Y] });
					cnt = 1;
				}
				cur.X = nx;
				cur.Y = ny;
			}
			if (isEnd) break;

			switch (dir) {
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
		s++;

		if (isEnd) break;
	}
	for (int i = 0; i < 52; i++) fill(board[i], board[i] + 52, 0);
	board[N / 2][N / 2] = -1;

	isEnd = false;
	s = 1;
	dir = 2;
	cur.X = N / 2;
	cur.Y = N / 2;
	int tmp = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (cur.X == 0 && cur.Y == 0) {
					isEnd = true;
					break;
				}
				if (board[cur.X][cur.Y] == -1) {
					cur.X = nx;
					cur.Y = ny;
					continue;
				}
				tmp++;
				if (tmp > 1) {
					tmp = 0;
					cur.X = nx;
					cur.Y = ny;
					continue;
				}
				if (sameR.size() == 0) {
					isEnd = true;
					break;
				}
				board[cur.X][cur.Y] = sameR.front().X;
				board[nx][ny] = sameR.front().Y;
				sameR.pop();
				
				cur.X = nx;
				cur.Y = ny;
			}
			if (isEnd) break;

			switch (dir) {
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
		s++;

		if (isEnd) break;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			board[i][j] = x;
		}
	}
	board[N / 2][N / 2] = -1;

	while (M--) {
		int d, s;
		int stop = false;
		cin >> d >> s;

		snowBall(d - 1, s);
		while (!stop) {
			checkMarble();
			stop = explosionMarble();
		}
		changeBoard();

		cout << board[N / 2][N / 2];
	}

	cout << 1 * b1 + 2 * b2 + 3 * b3;
	return 0;
}