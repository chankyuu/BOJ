#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[100002];

int n, m;
int dx[2] = { -1,1 };
//int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int BFS(queue<int>& Q) {
	if (n == m) {
		cout << "0";
		return 0;
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		//cout << "(" << cur << ")" << " -> ";
		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx < 0 || nx > 100000) continue;
			if (board[nx] > 0) continue;
			if (board[nx] == -1) {
				cout << board[cur];
				return 0;
			}
			board[nx] = board[cur] + 1;
			Q.push(nx);
		}
		if (cur * 2 < 0 || cur * 2 > 100000) continue;
		if (board[cur * 2] > 0) continue;
		if (board[cur * 2] == -1) {
			cout << board[cur];
			return 0;
		}
		board[cur * 2] = board[cur] + 1;
		Q.push(cur * 2);
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> Q;

	fill(board, board + 100001, 0);
	cin >> n >> m;
	board[n] = 1;								// 수빈이 위치
	board[m] = -1;							// 동생 위치

	Q.push(n);
	BFS(Q);
	return 0;
}