#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int office[10][10];
int temp[10][10];
vector<pair<int, int>> cctvN;

void resetBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = office[i][j];
		}
	}
}
// 0 = 后沫, 6 = 寒, 1~5 CCTV
// 1 -> 茄率 规氢 / 2 -> 剧率 规氢 / 3 -> 流阿 规氢 / 4 -> 技 规氢 / 5 -> 葛电 规氢
void cctv(int dir, int x, int y) {
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M) return;
		if (temp[x][y] == 6) return;
		if (temp[x][y] != 0) continue;

		temp[x][y] = -1;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	int set = 0;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			temp[i][j] = office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5) cctvN.push_back({ i, j });
			if (office[i][j] == 0) set++;
		}
	}

	for (int p = 0; p < (1 << (2 * cctvN.size())); p++) {
		int emp = 0;
		resetBoard();
		int tmp = p;
		for (int i = 0; i < cctvN.size(); i++) {
			int dir = tmp % 4;
			tmp /= 4;

			int x = cctvN[i].X;
			int y = cctvN[i].Y;

			switch (office[x][y]) {
			case 1 :
				cctv(dir, x, y);
				break;
			case 2 :
				cctv(dir, x, y);
				cctv(dir + 2, x, y);
				break;
			case 3 :
				cctv(dir, x, y);
				cctv(dir + 1, x, y);
				break;
			case 4 :
				cctv(dir, x, y);
				cctv(dir + 1, x, y);
				cctv(dir + 2, x, y);
				break;
			case 5 :
				cctv(dir, x, y);
				cctv(dir + 1, x, y);
				cctv(dir + 2, x, y);
				cctv(dir + 3, x, y);
				break;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 0) emp++;
			}
		}
		set = min(set, emp);
	}
	cout << set;

	return 0;
}