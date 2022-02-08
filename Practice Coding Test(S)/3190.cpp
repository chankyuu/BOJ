#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, K, L;
int board[102][102];
int t_board[102][102];
int result = 0;
int dir = 1;

int t[102];
char c[102];

vector<pair<int, int>> snake;
// 뱀 움직이기
bool moveSnake(int dir, bool check) {
	int nx = snake.back().X + dx[dir];
	int ny = snake.back().Y + dy[dir];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
	if (t_board[nx][ny] == -1) return false;

	snake.push_back({ nx, ny });
	// 사과가 없을 때
	if (board[nx][ny] != 1) {
		t_board[snake.front().X][snake.front().Y] = 0;
		snake.erase(snake.begin());

		// 방향이 바뀌었을 때
		if (check) t_board[snake[snake.size() - 1].X][snake[snake.size() - 1].Y] = -1;
	}

	t_board[nx][ny] = -1;
	return true;
}

// 뱀 회전
void turnSnake(char c) {
	// 왼쪽으로 회전
	if (c == 'L') {
		dir = (dir + 1) % 4;
	}
	// 오른쪽으로 회전
	else if (c == 'D') {
		dir--;
		if (dir < 0) dir = 3;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Flag = 0;
	bool check = false;

	cin >> N >> K;

	for (int i = 0; i < N; i++) fill(board[i], board[i] + N, 0);

	while (K--) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}

	t_board[0][0] = -1;
	snake.push_back({ 0, 0 });

	cin >> L;

	for(int i = 0; i < L; i++){
		cin >> t[i] >> c[i];
	}
	
	while(true){
		if(moveSnake(dir, check)) result++;
		else break;
		
		check = false;

		if (result == t[Flag]) {
			turnSnake(c[Flag]);
			check = true;
			Flag++;
		}
	}
	result++;
	cout << result;
	return 0;
}