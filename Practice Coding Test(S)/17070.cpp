#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[3] = { 0, 1, 1};
int dy[3] = { 1, 0, 1 };
int N;
int board[20][20];
int result = 0;

bool check(pair<int, int> f, pair<int, int> s, int d){
	if (f.X < 0 || f.X >= N || f.Y < 0 || f.Y >= N) return false;
	if (s.X < 0 || s.X >= N || s.Y < 0 || s.Y >= N) return false;
	if (board[s.X][s.Y] == 1) return false;
	
	if (d == 2) {
		if (board[s.X][s.Y - 1] == 1) return false;
		if (board[s.X - 1][s.Y] == 1) return false;
	}

	return true;
}
void bt(pair<int, int> f, pair<int, int> s, int d) {
	if (!check(f, s, d)) return;
	if (s.X == N - 1 && s.Y == N - 1) {
		result++;
		return;
	}

	// dir = 0 -> 가로, dir = 1 -> 세로, dir = 2 -> 대각선
	for (int dir = 0; dir < 3; dir++) {
		if (d == 0 && dir == 1) continue;
		if (d == 1 && dir == 0) continue;
		pair<int, int> nf = s;
		pair<int, int> ns = { s.X + dx[dir], s.Y + dy[dir] };
		
		bt(nf, ns, dir);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

	bt({ 0, 0 }, { 0, 1 }, 0);

	cout << result;
	return 0;
}