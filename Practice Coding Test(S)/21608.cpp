#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;
int board[22][22];
vector<vector<int>> n;

struct comp {
	int fab = 0;			// 좋아하는 학생 수
	int temp = 0;			// 빈칸의 수
	int r = 0x7f7f7f7f;				// 행의 번호
	int c = 0x7f7f7f7f;				// 열의 번호
};
// 비교함수
bool cmp(vector<int> a, vector<int> b) {
	return a.front() < b.front();
}
// 자리 정하기
void setSeat(int k) {
	comp maxC;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) continue;
			comp c;
			c.r = i;
			c.c = j;
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

				if (board[nx][ny] == 0) c.temp++;
				for (int i = 1; i <= 4; i++) {
					if (board[nx][ny] == n[k][i]) c.fab++;
				}
			}
			if (c.fab > maxC.fab) maxC = c;
			else if (c.fab == maxC.fab) {
				if (c.temp > maxC.temp) maxC = c;
				else if (c.temp == maxC.temp) {
					if (c.r < maxC.r) maxC = c;
					else if (c.r == maxC.r) {
						if (c.c < maxC.c) maxC = c;
					}
				}
			}
			
		}
	}
	board[maxC.r][maxC.c] = n[k][0];
}
// 만족도 조사
void search() {
	int result = 0;

	sort(n.begin(), n.end(), cmp);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cur = board[i][j] - 1;
			int cnt = 0;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				
				for (int tmp = 1; tmp <= 4; tmp++) {
					if (board[nx][ny] == n[cur][tmp]) cnt++;
				}
			}
			switch (cnt) {
			case 0 :
				break;
			case 1 :
				result += 1;
				break;
			case 2 :
				result += 10;
				break;
			case 3 :
				result += 100;
				break;
			case 4: 
				result += 1000;
				break;
			default :
				break;
			}
		}
	}
	cout << result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 0; i < N * N; i++){
		vector<int> t;

		for (int k = 0; k < 5; k++) {
			int x;
			cin >> x;
			t.push_back(x);
		}

		n.push_back(t);

		setSeat(i);
	}
	search();

	return 0;
}