#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int board[52][52];
int result = 0x7f7f7f7f;
struct Case {
	int r, c, s;
};
vector<Case> info;
bool vis[6];

int A() {
	int tmp = 0x7f7f7f7f;
	for (int i = 0; i < N; i++) {
		int tmp2 = 0;
		for (int j = 0; j < M; j++) {
			tmp2 += board[i][j];
		}
		tmp = min(tmp, tmp2);
	}
	return tmp;
}
// 배열 돌리기
void turnA(int idx) {
	int t_board[52][52];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) t_board[i][j] = board[i][j];

	int fx = info[idx].r - info[idx].s;
	int fy = info[idx].c - info[idx].s;

	int lx = info[idx].r + info[idx].s;
	int ly = info[idx].c + info[idx].s;

	while (fx != lx && fy != ly) {
		for (int i = fy; i < ly; i++) board[fx][i + 1] = t_board[fx][i];
		for (int i = ly; i > fy; i--) board[lx][i - 1] = t_board[lx][i];
		for (int i = fx; i < lx; i++) board[i + 1][ly] = t_board[i][ly];
		for (int i = lx; i > fx; i--) board[i - 1][fy] = t_board[i][fy];
		
		fx++; fy++;
		lx--; ly--;
	}
}
// 배열 원래대로
void returnA(int idx) {
	int t_board[52][52];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) t_board[i][j] = board[i][j];

	int fx = info[idx].r - info[idx].s;
	int fy = info[idx].c - info[idx].s;

	int lx = info[idx].r + info[idx].s;
	int ly = info[idx].c + info[idx].s;

	while (fx != lx && fy != ly) {
		for (int i = fy; i < ly; i++) board[lx][i + 1] = t_board[lx][i];
		for (int i = ly; i > fy; i--) board[fx][i - 1] = t_board[fx][i];
		for (int i = fx; i < lx; i++) board[i + 1][fy] = t_board[i][fy];
		for (int i = lx; i > fx; i--) board[i - 1][ly] = t_board[i][ly];

		fx++; fy++;
		lx--; ly--;
	}
}
void bt(int cnt) {
	if (cnt >= K) {
		result = min(result, A());
		return;
	}

	for (int i = 0; i < K; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		// 배열 돌리기
		turnA(i);
		bt(cnt + 1);
		vis[i] = false;
		// 배열 원래대로
		returnA(i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> board[i][j];
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		info.push_back({ r - 1, c - 1, s });
	}
	for (int i = 0; i < 6; i++) vis[i] = false;

	bt(0);
	
	cout << result;
	return 0;
}