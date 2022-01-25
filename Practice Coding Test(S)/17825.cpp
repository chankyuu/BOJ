#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int board[9][22] = { {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, -1},
								{0, 0, 0, 0, 0, 13, 0,  0,  0,  0,  22,   0,   0,  0,   0,  28, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 16, 0,  0,  0,  0,  24,   0,   0,  0,   0,  27, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 19, 0,  0,  0,  0,  25,   0,   0,  0,   0,  26, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 25, 0,  0,  0,  0,  30,   0,   0,  0,   0,  25, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 30, 0,  0,  0,  0,  35,   0,   0,  0,   0,  30, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 35, 0,  0,  0,  0,  40,   0,   0,  0,   0,  35, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 40, 0,  0,  0,  0,  -1,   0,   0,  0,   0,  40, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, -1, 0,  0,  0,  0,   0,    0,   0,  0,   0,  -1, 0 , 0, 0, 0, 0, 0}
};

int N[10];
int maxN = 0;
pair<int, int> horse[4];
vector<int> tmp;

// 보드에 다른 말이 있는지 검사
bool checkHorse(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (x == horse[i].X && y == horse[i].Y) return true;
		if (board[x][y] == 40 && board[horse[i].X][horse[i].Y] == 40) return true;
		if (board[x][y] == 25 && board[horse[i].X][horse[i].Y] == 25) return true;
		if (x != 0 && horse[i].X != 0 && board[x][y] == 30 && board[horse[i].X][horse[i].Y] == 30) return true;
		if (board[x][y] == 35 && board[horse[i].X][horse[i].Y] == 35) return true;
	}
	return false;
}
// 말 움직이기
void moveHorse(int cnt, int r) {
	if (cnt == 10) {
		maxN = max(maxN, r);
		
		/*if (r >= 214) {
			cout << "***************" << "\n";
			cout << "N = " << r << "\n";
			cout << "***************" << "\n";
			for (int i = 0; i < tmp.size(); i++)	cout << tmp[i] << " ";
			cout << "\n";
		}*/
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (horse[i].X == -1 && horse[i].Y == -1) continue;
		int dir = N[cnt];
		auto cur = horse[i];
		int nx = cur.X;
		int ny = cur.Y;
		bool Flag = false;

		if (cur.X != 0 || board[cur.X][cur.Y] == 10 || board[cur.X][cur.Y] == 30) {
			nx = cur.X + dir;
			if (nx > 7) Flag = true;
		}
		else if (board[cur.X][cur.Y] == 20) {
			nx = cur.X + dir;
			if (nx > 6) Flag = true;
		}
		else {
			ny = cur.Y + dir;
			if (ny > 21) Flag = true;
		}
		
		if (checkHorse(nx, ny)) continue;

		if (Flag) horse[i] = { -1, -1 };
		else {
			horse[i] = { nx, ny };
			r += board[nx][ny];
		}
		//tmp.push_back(i);
		
		/*if (tmp.size() >= 3) {
			if (tmp[0] == 0 && tmp[1] == 1 && tmp[2] == 1)
				cout << "zz";
		}*/
		moveHorse(cnt + 1, r);

		horse[i] = { cur.X, cur.Y };
		if (!Flag) r -= board[nx][ny];
		/*tmp.erase(tmp.begin() + tmp.size() - 1);*/
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) cin >> N[i];
	for (int i = 0; i < 4; i++) horse[i] = { 0, 0 };
	moveHorse(0, 0);
	cout << maxN;
	return 0;
}
