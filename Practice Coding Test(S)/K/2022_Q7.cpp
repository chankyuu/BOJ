#include <string>
#include <vector>

using namespace std;

#define X first
#define Y second

int board[7][7];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int answer = 0;
int n, m;
bool vis[5][5];

int bt(pair<int, int> cur, pair<int, int> nxt) {
	if (vis[cur.X][cur.Y]) return 0;

	int Flag = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 0) continue;
		if (vis[nx][ny]) continue;

		vis[cur.X][cur.Y] = 1;

		int Flag2 = bt(nxt, { nx, ny }) + 1;

		vis[cur.X][cur.Y] = 0;

		if (Flag % 2 == 0 && Flag2 % 2 == 1) Flag = Flag2;
		else if (Flag % 2 == 0 && Flag2 % 2 == 0) Flag = max(Flag, Flag2);
		else if (Flag % 2 == 1 && Flag2 % 2 == 1) Flag = min(Flag, Flag2);
	}
	return Flag;
}
int solution(vector<vector<int>> t_board, vector<int> aloc, vector<int> bloc) {
	n = t_board.size();
	m = t_board[0].size();

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) board[i][j] = t_board[i][j];
	answer = bt({ aloc[0], aloc[1] }, { bloc[0], bloc[1] });

	return answer;
}