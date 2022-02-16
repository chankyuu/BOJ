#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[3] = { 0, -1, 0};
int dy[3] = { -1, 0, 1 };
int N, M, D;
int board[18][18];
int castle[18][18];
int result = 0;
// 적이 있는지 확인
bool check() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (castle[i][j] == 1) return false;
	return true;
}
void attack(vector<int> info) {
	int kill = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) castle[i][j] = board[i][j];

	while (true) {
		if (check()) break;
		int tmp[18][18];		// 적을 이미 죽였는지 확인
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) tmp[i][j] = castle[i][j];
		// 적 공격
		for (int i = 0; i < info.size(); i++) {
			if (info[i]) continue;
			int dist[18][18];			// 거리 측정
			for (int j = 0; j <= N; j++) fill(dist[j], dist[j] + M, 0);

			bool Flag = false;
			queue<pair<int, int>> q;
			q.push({ N, i });
			while (!q.empty()) {
				if (Flag) break;
				auto cur = q.front(); q.pop();

				for (int dir = 0; dir < 3; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx == N) continue;
					if (nx < 0 || ny < 0 || ny >= M) continue;
					if (dist[nx][ny] > 0) continue;

					if (dist[cur.X][cur.Y] + 1 > D) {
						Flag = true;
						break;
					}
					if (castle[nx][ny] == 1) {
						if (tmp[nx][ny] == 1) {
							kill++;
							tmp[nx][ny] = 0;
						}
						Flag = true;
						break;
					}
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}
		}
		// tmp값 castle에 원래대로 복구
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) castle[i][j] = tmp[i][j];

		// 적 이동
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (castle[i][j] == 0) continue;
				if(!(i == N - 1)) castle[i + 1][j] = 1;
				castle[i][j] = 0;
			}
		}
	}
	result = max(result, kill);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> board[i][j];
	
	vector<int> brute(M, 0);
	fill(brute.begin() + 3, brute.end(), 1);
	// 궁수를 배치 가능한 모든 조합 만들기
	do {
		attack(brute);
	} while (next_permutation(brute.begin(), brute.end()));
	
	cout << result;
	return 0;
}