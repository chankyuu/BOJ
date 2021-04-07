#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{ {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int cnt = 0;
int meter = 0;
void BFS(queue<pair<int, int>>& Q) {
	int tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] != 1) {
				vis[i][j] = 1;
				Q.push({ i,j });
				tmp = 1;
				cnt++;

				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					//cout << '(' << cur.X << ", " << cur.Y << ") -> ";
					for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
						if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
						vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
						tmp++;
						Q.push({ nx,ny });
					}
				}
				if (meter < tmp) meter = tmp;
			}
		}
	}
	cout << cnt << "\n";
	cout << meter << "\n";
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int> > Q;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	BFS(Q);
}