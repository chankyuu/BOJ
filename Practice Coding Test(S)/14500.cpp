#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int board[502][502];
bool visited[502][502];
pair<int, int> cur;
int result = 0;
// 테트로미노 찾기
void solve(int cnt, int r) {
	if (cnt == 4) {
		result = max(result, r);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		pair<int, int> pre = cur;

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny]) continue;

		visited[nx][ny] = true;
		r += board[nx][ny];
		cur = { nx, ny };

		solve(cnt + 1, r);

		visited[nx][ny] = false;
		r -= board[nx][ny];
		cur = pre;
	}
}
// 가운데 모양만 처리
void except() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cnt = 0;
			int tmp = board[i][j];
			// 가운데 모양이 4번 반복
			for (int k = 0; k < 12; k++) {
				int dir = k % 4;
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				cnt++;
				tmp += board[nx][ny];

				if (cnt == 3) {
					result = max(result, tmp);
					cnt = 0;
					tmp = board[i][j];
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cur = { i, j };
			visited[i][j] = true;
			solve(0, 0);
			visited[i][j] = false;
		}
	}
	except();

	cout << result;
	return 0;
}