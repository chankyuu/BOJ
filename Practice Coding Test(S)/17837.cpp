#include <bits/stdc++.h>

using namespace std;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int N, K;
int board[12][12];
struct horse {
	int num;
	int dir;
};
vector<horse> horses[12][12];
int result = 1;

// ���� ��ȯ
int changeDir(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	if (d == 4) return 3;
}
// �� �̵�
bool moveHorse() {
	for (int idx = 0; idx < K; idx++) {
		bool Flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < horses[i][j].size(); k++) {
					if (horses[i][j][k].num != idx) continue;
					int dir = horses[i][j][k].dir;
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					// ��� �Ǵ� �Ķ��� �˻�
					if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2) {
						dir = changeDir(dir);
						nx = i + dx[dir];
						ny = j + dy[dir];
						horses[i][j][k].dir = dir;
					}
					// �Ķ����� ��
					if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2) {
						Flag = true;
						continue;
					}
					// ����϶�
					if (board[nx][ny] == 0) {
						for (int p = k; p < horses[i][j].size(); p++) horses[nx][ny].push_back(horses[i][j][p]);
						for (int p = k; p < horses[i][j].size(); p++) {
							horses[i][j].erase(horses[i][j].begin() + p);
							p--;
						}
					}
					// �������϶�
					else if (board[nx][ny] == 1) {
						for (int p = horses[i][j].size() - 1; p >= k; p--) horses[nx][ny].push_back(horses[i][j][p]);
						for (int p = k; p < horses[i][j].size(); p++) {
							horses[i][j].erase(horses[i][j].begin() + p);
							p--;
						}
					}
					if (horses[nx][ny].size() >= 4) return true;
					Flag = true;
				}
				if (Flag) break;
			}
			if (Flag) break;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;

	// 0 = ��� / 1 = ������ / 2 = �Ķ���
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

	for(int i = 0; i < K; i++){
		int x, y, d;
		cin >> x >> y >> d;
		horses[x-1][y-1].push_back({ i, d });
	}
	
	while (!moveHorse()) {
		result++;
		if (result > 1000) {
			result = -1;
			break;
		}
	}

	cout << result;
	return 0;
}
