#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[1002][1002];// 1이 파란 칸, 0이 빨간 칸에 대응
//bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int dist = 0;
int check = 2;
void BFS(queue<pair<int, int>>& Q) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) Q.push({ i, j });
			else if (board[i][j] == 0) check = 0;
		}
	}
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		//cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1 || board[cur.X][cur.Y] <= board[nx][ny]) continue;
			board[nx][ny] = board[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
			dist = board[nx][ny];
		}
		board[cur.X][cur.Y] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				check = 1;
				break;
			}
		}
	}
	if (check == 1) cout << "-1";
	else if (check == 2) cout << "0";
	else cout << dist - 1;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	BFS(Q);

	return 0;
}