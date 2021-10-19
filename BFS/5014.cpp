#include <bits/stdc++.h>
using namespace std;

int board[1000002];
int F, S, G, U, D;
int num = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	queue<int> Q;
	int nx = 0;

	cin >> F >> S >> G >> U >> D;

	fill(board, board + 1000002, -1);

	board[S] = 0;

	Q.push(S);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();

		if (cur == G) {
			cout << board[cur];
			return 0;
		}
		for (int dir = 0; dir < 2; dir++) {
			if (dir == 0) {
				nx = cur + U;
			}
			else if (dir == 1) {
				nx = cur - D;
			}

			if (nx < 1 || nx > F) continue;
			if (board[nx] >= 0) continue;

			board[nx] = board[cur] + 1;
			Q.push(nx);
		}
	}

	cout << "use the stairs";
	return 0;
}