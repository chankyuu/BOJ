#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, M;
int board[52][52];
vector<pair<int, int>> cloude;

// 물복사버그 마법 + 구름 생성
void magic() {
	vector<pair<int, int>> t_cloude;
	for (int i = 0; i < cloude.size(); i++) t_cloude.push_back(cloude[i]);

	// 대각선 인덱스 -> 1, 3, 5, 7 
	for (int i = 0; i < cloude.size(); i++) {
		int cnt = 0;
		auto cur = cloude[i];
		for (int i = 1; i < 8; i += 2) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny]) cnt++;
		}
		board[cur.X][cur.Y] += cnt;
	}
	cloude.clear();
	// 구름 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] < 2) continue;
			bool Flag = false;

			for (int k = 0; k < t_cloude.size(); k++) {
				if (i == t_cloude[k].X && j == t_cloude[k].Y) {
					Flag = true;
					break;
				}
			}
			if (!Flag) {
				cloude.push_back({ i, j });
				board[i][j] -= 2;
			}
		}
	}
}
// 구름 움직이기
void moveCloude(int d, int s) {
	for (int i = 0; i < cloude.size(); i++) {
		int count = 1;
		while (true) {
			cloude[i].X += dx[d];
			cloude[i].Y += dy[d];

			if (cloude[i].X < 0) cloude[i].X = N - 1;
			if (cloude[i].X >= N) cloude[i].X = 0;
			if (cloude[i].Y < 0) cloude[i].Y = N - 1;
			if (cloude[i].Y >= N) cloude[i].Y = 0;
			
			count++;

			if (count > s) break;
		}
		board[cloude[i].X][cloude[i].Y] += 1;
	}
}
// 물의 합 구하기
int sumWater() {
	int result = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) result += board[i][j];
	return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];
	
	cloude.push_back({ N - 1, 0 });
	cloude.push_back({ N - 1, 1 });
	cloude.push_back({ N - 2, 0 });
	cloude.push_back({ N - 2, 1 });

	while (M--) {
		int x, y;
		cin >> x >> y;
		moveCloude(x - 1, y);
		magic();
	}

	cout << sumWater();
	return 0;
}