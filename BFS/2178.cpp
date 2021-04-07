#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[502][502];// 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
//bool vis[502][502]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�

int dist = 0;
int result = 0;
int check = 0;
void BFS(queue<pair<int, int>>& Q) {
	//vis[0][0] = 1;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		//cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1 || board[cur.X][cur.Y] < board[nx][ny]) continue;
			board[nx][ny] = board[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
			dist = board[nx][ny];
			if (nx == n - 1 && ny == m - 1) {
				result = dist;
				check = 1;
				break;
			}
		}
		board[cur.X][cur.Y] = -1;
		if (check == 1) break;
	}
	cout << result;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	string a;

	fill(&board[0][0], &board[501][502], -1);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) if (a[j] == '1') board[i][j] = a[j] - '0';
	}

	BFS(Q);

	return 0;
}