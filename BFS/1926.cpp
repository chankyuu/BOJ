#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[502][502] =
{ {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
bool vis[502][502]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�

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
					for (int dir = 0; dir < 4; dir++) { // �����¿� ĭ�� ���캼 ���̴�.
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ���� ���� ��� �Ѿ
						if (vis[nx][ny] || board[nx][ny] != 1) continue; // �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���
						vis[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
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