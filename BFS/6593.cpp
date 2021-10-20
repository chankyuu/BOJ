#include <bits/stdc++.h>
using namespace std;


string board[32];
int vis[32][32][32];
int L, R, C;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct loc {
	int z;
	int x;
	int y;
};

void BFS(queue<loc>& Q) {
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
			if (vis[nz][nx][ny] == -1 || vis[nz][nx][ny] >= 1) continue;
			
			if (vis[nz][nx][ny] == -2) {
				cout << "Escaped in " << vis[cur.z][cur.x][cur.y] << " minute(s)." << "\n";
				return;
			}

			vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
			Q.push({ nz, nx, ny });
		}
	}
	cout << "Trapped!" << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	while (true) {
		queue<loc> Q;

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		// 변수 초기화
		fill(board, board + 32, '#');

		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				fill(vis[i][j], vis[i][j] + 32, -1);
			}
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string tmp;
				cin >> tmp;
				
				board[j] = tmp;
			}
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (board[j][k] == '.') vis[i][j][k] = 0;
					else if (board[j][k] == 'S') {
						vis[i][j][k] = 1;
						Q.push({ i, j, k });
					}
					else if (board[j][k] == 'E') vis[i][j][k] = -2;
				}
			}
		}
		BFS(Q);
	}
	return 0;
}