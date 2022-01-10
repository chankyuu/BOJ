#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[4][4];
int M, S;
int x, y, d;

struct fishS {
	int x;
	int y;
	int dir;
};
vector<fishS> fish[4][4];
vector<fishS> tFish[4][4];

// 인덱스 0, 2, 4, 6 (서, 북, 동, 남)
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void copyFish(vector<fishS> f[4][4], vector<fishS> s[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			f[i][j] = s[i][j];
		}
	}
}
void makeFish() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < tFish[i][j].size(); k++) {
				fish[i][j].push_back(tFish[i][j][k]);
			}
		}
	}
}
void checkSmell() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] <= -2) board[i][j] -= 1;
			if (board[i][j] <= -5) board[i][j] = 0;
		}
	}
}
// board[x][y] == -1 -> 상어 있는 칸 / board[x][y] == -2 -> 물고기 냄새가 있는 칸
bool checkMove(int px, int py) {
	if (px < 0 || px >= 4 || py < 0 || py >= 4 || board[px][py] <= -2 || (px == x - 1 && py == y - 1)) {
		return false;
	}
	return true;
}
// 1. 물고기 이동
void moveFish() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		tFish[i][j].clear();
		tFish[i][j] = fish[i][j];
	}
	vector<fishS> tempFish[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < fish[i][j].size(); k++) {
				for (int cnt = 0; cnt < 8; cnt++) {
					int curD = fish[i][j][k].dir;

					if (!checkMove(i + dx[curD], j + dy[curD])) {
						fish[i][j][k].dir -= 1;
						if (fish[i][j][k].dir < 0) fish[i][j][k].dir = 7;
						if (cnt == 7) tempFish[i][j].push_back({ i, j, fish[i][j][k].dir });
						continue;
					}
					tempFish[i + dx[curD]][j + dy[curD]].push_back({ i + dx[curD], j + dy[curD], curD });

					break;
				}
			}
		}
	}
	copyFish(fish, tempFish);
}

// 2. 상어 이동 및 복제
void moveShark() {
	int maxCnt = 0;
	vector<int> mRoot = { 9, 9, 9 };
	for (int tmp = 0; tmp < 64; tmp++) {
		vector<fishS> tFish2[4][4];
		copyFish(tFish2, fish);

		int brute = tmp;
		int cnt = 0;
		bool isEnd = false;
		queue<pair<int, int>> shark;
		shark.push({ x - 1, y - 1 });
		vector<int> tRoot;
		// 상 0(2), 좌 1(0), 하 2(6), 우 3(4)
		// 상어의 루트 결정(64가지의 경우 모두 체크)
		for (int i = 0; i < 3; i++) {
			auto curS = shark.front(); shark.pop();
			int dir = brute % 4;
			brute /= 4;

			switch (dir) {
			case 0:
				curS.X += dx[2];
				curS.Y += dy[2];
				break;
			case 1:
				curS.X += dx[0];
				curS.Y += dy[0];
				break;
			case 2:
				curS.X += dx[6];
				curS.Y += dy[6];
				break;
			case 3:
				curS.X += dx[4];
				curS.Y += dy[4];
				break;
			}

			if (curS.X < 0 || curS.X >= 4 || curS.Y < 0 || curS.Y >= 4) {
				isEnd = true;
				break;
			}

			if (tFish2[curS.X][curS.Y].size() > 0) {
				cnt += tFish2[curS.X][curS.Y].size();
				tFish2[curS.X][curS.Y].clear();
			}

			tRoot.push_back(dir);
			shark.push({ curS.X, curS.Y });
		}
		if (isEnd) continue;

		if (cnt == maxCnt) {
			for (int i = 0; i < 3; i++) {
				if (tRoot[i] < mRoot[i]) {
					mRoot = tRoot;
					maxCnt = cnt;
					break;
				}
				else if (tRoot[i] > mRoot[i]) break;
			}
		}
		else if (cnt > maxCnt) {
			mRoot = tRoot;
			maxCnt = cnt;
		}
	}
	// 상어가 결정된 루트에 따라 진짜 움직임
	int nx = x - 1;
	int ny = y - 1;
	for (auto c : mRoot) {
		switch (c) {
		case 0:
			nx += dx[2];
			ny += dy[2];
			break;
		case 1:
			nx += dx[0];
			ny += dy[0];
			break;
		case 2:
			nx += dx[6];
			ny += dy[6];
			break;
		case 3:
			nx += dx[4];
			ny += dy[4];
			break;
		}

		if (fish[nx][ny].size() > 0) {
			fish[nx][ny].clear();
			board[nx][ny] = -2;
		}
	}
	x = nx + 1;
	y = ny + 1;
	checkSmell();
	makeFish();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> S;

	while (M--) {
		cin >> x >> y >> d;
		fishS f = { x - 1, y - 1, d - 1 };
		fish[x - 1][y - 1].push_back(f);
	}
	cin >> x >> y;

	while (S--) {
		moveFish();
		moveShark();
	}

	int result = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) result += fish[i][j].size();

	cout << result;
	return 0;
}
