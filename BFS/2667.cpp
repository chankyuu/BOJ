#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
string tmp[25];
int apart[25][25];
int result[25];
int cnt = 0;
int meter = 1;

void BFS() {
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (apart[i][j] == 1) {
				cnt++;
				Q.push({ i, j });

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (apart[nx][ny] == 0 || apart[nx][ny] > 1) continue;
						apart[cur.X][cur.Y] = 0;
						apart[nx][ny] = ++meter;
						Q.push({ nx, ny });
					}
				}
				result[cnt - 1] = meter;
				meter = 1;
			}
		}
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 25; i++) fill(apart[i], apart[i] + 25, -1);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> tmp[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) apart[i][j] = tmp[i][j] - '0';

	BFS();
	sort(result, result + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) cout << result[i] << "\n";

	return 0;
}
