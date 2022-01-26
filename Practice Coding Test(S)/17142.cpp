#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int board[55][55];
int t_board[55][55];

vector<pair<int, int>> virus;
vector<pair<int, int>> t_virus;
int MIN = 0x7f7f7f7f;

// 몇초 걸렸는지 판단
void checkBoard() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 && t_board[i][j] < 0) 	return;
			if (t_board[i][j] > tmp && board[i][j] != 2) tmp = t_board[i][j];
		}
	}
	MIN = min(MIN, tmp);
}
// 바이러스 퍼트리기
void BFS(vector<pair<int, int>> V) {
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) t_board[i][j] = -1;
	for (int i = 0; i < V.size(); i++) t_board[V[i].X][V[i].Y] = 0;

	while (!V.empty()) {
		auto cur = V.front(); V.erase(V.begin());

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == 1 || t_board[nx][ny] >= 0) continue;

			t_board[nx][ny] = t_board[cur.X][cur.Y] + 1;
			V.push_back({ nx, ny });
		}
	}
	checkBoard();
}
// 최소 값 찾기
void findMin(int cnt, int p) {
	if (cnt == M) {
		BFS(t_virus);
		return;
	}

	for (int i = p; i < virus.size(); i++) {
		board[virus[i].X][virus[i].Y] = 3;
		t_virus.push_back(virus[i]);
		findMin(cnt + 1, i + 1);
		board[virus[i].X][virus[i].Y] = 2;
		t_virus.erase(t_virus.begin() + t_virus.size() - 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i, j });
		}
	}

	findMin(0, 0);

	if (MIN == 0x7f7f7f7f) cout << -1;
	else cout << MIN;
	
	return 0;
}
