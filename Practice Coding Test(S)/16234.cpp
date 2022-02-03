#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, L, R;
int board[52][52];
vector<bool> tmp[52][52];
int result = 0;

// 인구 이동
bool open() {
	bool Flag = false;

	// 국경선 열기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				int nd = (dir + 2) % 4;

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (tmp[i][j][dir] == true && tmp[nx][ny][nd] == true) continue;

				if (abs(board[i][j] - board[nx][ny]) >= L && abs(board[i][j] - board[nx][ny]) <= R) {
					tmp[i][j][dir] = true;
					tmp[nx][ny][(dir + 2) % 4] = true;
					Flag = true;
				}
			}
		}
	}
	return Flag;
}
void movePeople(){
	// 연합
	queue<pair<int, int>> Q;
	bool visit[52][52];

	for (int i = 0; i < N; i++) fill(visit[i], visit[i] + N, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) continue;
			vector<pair<int, int>> V;
			int P = board[i][j];
			int C = 1;

			Q.push({ i, j });
			visit[i][j] = true;
			V.push_back({ i, j });

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					int nd = (dir + 2) % 4;

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visit[nx][ny]) continue;
					if (tmp[cur.X][cur.Y][dir] == false && tmp[nx][ny][nd] == false) continue;
					
					P += board[nx][ny];
					C++;
					V.push_back({ nx, ny });
					visit[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
			for (int a = 0; a < V.size(); a++) board[V[a].X][V[a].Y] = P / C;
		}
	}
	// 연합 해체
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int dir = 0; dir < 4; dir++) tmp[i][j][dir] = false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < 4; k++) tmp[i][j].push_back(false);

	while (open()) {
		movePeople();
		result++;
		if (result >= 2000) break;
	}
	cout << result;
	return 0;
}