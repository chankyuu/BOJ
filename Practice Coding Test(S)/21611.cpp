#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int td[4] = { 2, 1, 3, 0 };

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
void moveMarble() {
	queue<int> q;
	pair<int, int> cur = { N / 2, N / 2 };
	bool isEnd = false;
	int s = 1;
	int dir = 0;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[td[dir]];
				int ny = cur.Y + dy[td[dir]];
				if (board[nx][ny] && board[nx][ny] != -1) q.push(board[nx][ny]);
			
				cur.X = nx;
				cur.Y = ny;
				if (nx == 0 && ny == 0) {
					isEnd = true;
					break;
				}
			}
			dir = (dir + 1) % 4;
			if (isEnd) break;
		}
		s++;
		if (isEnd) break;
	}

	for(int i = 0; i < N; i++) fill(board[i], board[i] + N, 0);
	board[N / 2][N / 2] = -1;
	if (q.empty()) return;
	cur.X = N / 2, cur.Y = N / 2;
	dir = 0;
	s = 1;
	isEnd = false;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[td[dir]];
				int ny = cur.Y + dy[td[dir]];
				board[nx][ny] = q.front();
				q.pop();
				if (q.empty()) return;

				cur.X = nx;
				cur.Y = ny;

				if (nx == 0 && ny == 0) {
					isEnd = true;
					break;
				}
			}
			dir = (dir + 1) % 4;
			if (isEnd) break;
		}
		s++;
		if (isEnd) break;
	}
}
// 구슬 폭발
bool explosionMarble() {
	pair<int, int> cur = { N / 2, N / 2 };
	queue<pair<int, int>> q;
	bool isEnd = false;
	int s = 1;
	int dir = 0;
	int cnt = 0;
	bool flag = true;
	vector<pair<int, int>> sameR;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[td[dir]];
				int ny = cur.Y + dy[td[dir]];

				if (board[nx][ny] == board[cur.X][cur.Y]) q.push({ nx, ny });
				else {
					if (q.size() >= 4) {
						while (!q.empty()) {
							auto k = q.front();
							q.pop();
							
							if (board[k.X][k.Y] == 1) b1 += (cnt + 1);
							else if (board[k.X][k.Y] == 2) b2 += (cnt + 1);
							else if (board[k.X][k.Y] == 3) b3 += (cnt + 1);
							board[k.X][k.Y] = 0;
						}
						flag = false;
					}
					else {
						while (!q.empty()) q.pop();
					}
					q.push({ nx, ny });
				}
				if (nx == 0 && ny == 0) {
					isEnd = true;
					break;
				}
				cur.X = nx;
				cur.Y = ny;
			}
			if (isEnd) break;
			dir = (dir + 1) % 4;
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
	int dir = 0;
	int cnt = 1;
	queue<pair<int, int>> sameR;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[td[dir]];
				int ny = cur.Y + dy[td[dir]];

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
			dir = (dir + 1) % 4;
		}
		s++;

		if (isEnd) break;
	}
	for (int i = 0; i < N; i++) fill(board[i], board[i] + N, 0);
	board[N / 2][N / 2] = -1;

	if (sameR.empty()) {
		return;
	}

	isEnd = false;
	s = 1;
	dir = 0;
	cur.X = N / 2;
	cur.Y = N / 2;
	int tmp = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < s; j++) {
				int nx = cur.X + dx[td[dir]];
				int ny = cur.Y + dy[td[dir]];

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
				if (sameR.empty()) {
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
			dir = (dir + 1) % 4;
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
		cin >> d >> s;

		snowBall(d - 1, s);
		do {
			moveMarble();
		} while (!explosionMarble());

		changeBoard();
	}
	board[N / 2][N / 2] = -1;
	cout << (1 * b1) + (2 * b2) + (3 * b3);
	return 0;
}
