#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct block {
	int size = 0;
	int rainbow = 0;
	pair<int, int> center = { 22, 22 };
	vector<pair<int, int>> route;
};

int N, M;
int board[22][22];
block maxB;
int result = 0;

// 크기가 가장 큰 블록 그룹 찾기
// 검은색 = -1, 무지개 = 0, 나머지 = 1~M, 빈칸 = -2;
bool findBlockSize() {
	vector<pair<int, int >> maxIdx;
	bool isEnd = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0) {
				block tmp;
				bool check[22][22];
				int curN = board[i][j];

				for (int i = 0; i < N; i++) fill(check[i], check[i] + N, false);

				queue<pair<int, int>> Q;
				Q.push({ i, j });
				check[i][j] = true;

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();

					if (board[cur.X][cur.Y] == 0) tmp.rainbow++;
					else {
						if (tmp.center.X > cur.X) tmp.center = { cur.X, cur.Y };
						else if (tmp.center.X == cur.X) {
							if (tmp.center.Y > cur.Y) tmp.center = { cur.X, cur.Y };
						}
					}
					tmp.route.push_back({ cur.X, cur.Y });
					tmp.size++;

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (check[nx][ny]) continue;
						if (board[nx][ny] == -1) continue;
						if (board[nx][ny] != curN && board[nx][ny] != 0) continue;

						check[nx][ny] = true;
						Q.push({ nx, ny });
					}
				}
				if (tmp.size >= 2) {
					isEnd = true;
					if (maxB.size < tmp.size) {
						maxB = tmp;
					}
					else if (maxB.size == tmp.size) {
						if (maxB.rainbow < tmp.rainbow) maxB = tmp;
						else if (maxB.rainbow == tmp.rainbow) {
							if (maxB.center.X < tmp.center.X) maxB = tmp;
							else if (maxB.center.X == tmp.center.X) {
								if (maxB.center.Y < tmp.center.Y) maxB = tmp;
							}
						}
					}
				}
			}
		}
	}
	return isEnd;
}
// 블록 제거
void removeBlock() {
	for (int i = 0; i < maxB.route.size(); i++) {
		board[maxB.route[i].X][maxB.route[i].Y] = -2;
	}
	result += maxB.size * maxB.size;

	maxB.size = 0;
	maxB.rainbow = 0;
	maxB.center = { N, N };
	maxB.route.clear();
}
// 중력 작용
void force() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (board[j][i] <= -1) continue;

			int curX = j;
			while (true) {
				int nx = curX + dx[0];

				if (nx == N) break;
				if (board[nx][i] == -1) break;
				if (board[nx][i] >= 0) break;

				board[nx][i] = board[curX][i];
				board[curX][i] = -2;
				curX = nx;
			}
		}
	}
}
// 반시계 회전
void turnBoard() {
	int t_board[22][22];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) t_board[i][j] = board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = t_board[j][(N - 1) - i];
		}
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
	while (findBlockSize()) {
		removeBlock();
		force();
		turnBoard();
		force();
	}

	cout << result;
	return 0;
}