#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define X first
#define Y second 
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;
int board[22][22];
bool tmp[22][22];
int dice[6] = { 1, 3, 2, 4, 5, 6 };

// dir = 0 (남쪽), dir = 1 (동쪽), dir = 2 (북쪽), dir = 3 (서쪽)
int dir = 1;
// 현재 위치
pair<int, int> m = { 0, 0 };
// 총점
int sum = 0;
// 2. 닿은 면과 같은 점수 부분의 면적 구하기(BFS)
int BFS(pair<int, int> c) {
	int cnt = 0;
	int pre = board[c.X][c.Y];
	queue<pair<int, int>> Q;
	Q.push({ c.X, c.Y });
	tmp[c.X][c.Y] = true;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			// 범위 밖일 때
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// 이미 방문했으면 패스
			if (tmp[nx][ny] == true) continue;
			// 현재 수와 다음 수가 같지 않을 때
			if (board[nx][ny] != board[cur.X][cur.Y]) continue;

			tmp[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}
	return pre * cnt;
}
// 1. 주사위 굴리기
void rollDice() {
	int nx = m.X + dx[dir];
	int ny = m.Y + dy[dir];

	if (nx < 0) 	dir = 0;
	if (nx >= N) dir = 2;
	if (ny < 0) dir = 1;
	if (ny >= M) dir = 3;


	int tmp[4];

	m.X += dx[dir];
	m.Y += dy[dir];

	switch (dir) {
	case 0:
		tmp[0] = dice[0];
		tmp[1] = dice[4];
		tmp[2] = dice[5];
		tmp[3] = dice[2];

		dice[4] = tmp[0];
		dice[5] = tmp[1];
		dice[2] = tmp[2];
		dice[0] = tmp[3];
		break;
	case 1:
		tmp[0] = dice[0];
		tmp[1] = dice[1]; 
		tmp[2] = dice[5];
		tmp[3] = dice[3];

		dice[1] = tmp[0];
		dice[5] = tmp[1];
		dice[3] = tmp[2];
		dice[0] = tmp[3];
		break;
	case 2: 
		tmp[0] = dice[0];
		tmp[1] = dice[2];
		tmp[2] = dice[5];
		tmp[3] = dice[4];
	
		dice[2] = tmp[0];
		dice[5] = tmp[1];
		dice[4] = tmp[2];
		dice[0] = tmp[3];
		break;
	case 3 :
		tmp[0] = dice[0];
		tmp[1] = dice[3];
		tmp[2] = dice[5];
		tmp[3] = dice[1];
	
		dice[3] = tmp[0];
		dice[5] = tmp[1];
		dice[1] = tmp[2];
		dice[0] = tmp[3];
		break;
	default :
		break;
	}
	sum += BFS({ m.X, m.Y });

	if (dice[5] > board[m.X][m.Y]) {
		dir -= 1;
		if (dir < 0) dir = 3;
	}
	else if (dice[5] < board[m.X][m.Y]) {
		dir = (dir + 1) % 4;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> board[i][j];

	while (K--) {
		for (int i = 0; i < N; i++) fill(tmp[i], tmp[i] + M, false);
		rollDice();
	}
	cout << sum;
	return 0;
}