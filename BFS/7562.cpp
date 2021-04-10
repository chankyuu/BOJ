#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int isused[300][300];
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int N;
int L;
int result;
int a, b, c, d;

void BFS() {
	queue<pair<int, int>> Q;
	Q.push({ a, b });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
			if (isused[nx][ny] > 1) continue;
			isused[nx][ny] = isused[cur.X][cur.Y] + 1;
			if (nx == c && ny == d) {
				result = isused[nx][ny] - 1;
				break;
			}

			Q.push({ nx, ny });
		}
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int i = 0; i < 300; i++) fill(isused[i], isused[i] + 300, 0);
		cin >> L;
		cin >> a >> b >> c >> d;
		isused[a][b] = 1;
		BFS();
		if (a == c && b == d) cout << 0 << "\n";
		else cout << result << "\n";
	}

	return 0;
}
