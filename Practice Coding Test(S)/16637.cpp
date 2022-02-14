#include <bits/stdc++.h>

using namespace std;

int N;
string board;
vector<char> tmp;
int maxR = -0x7f7f7f7f;

int cal(int a, int b, char op) {
	int result = 0;
	
	if (op == '+') result = a + b;
	else if (op == '*') result = a * b;
	else if (op == '-') result = a - b;
	return result;
}
void bt(int idx, int cur) {
	if (idx > N - 1) {
		maxR = max(maxR, cur);
		return;
	}

	char op;

	if (idx == 0) op = '+';
	else op = board[idx - 1];

	if (idx + 2 < N) {
		int now = cal(board[idx] - '0', board[idx + 2] - '0', board[idx + 1]);
		bt(idx + 4, cal(cur, now, op));
	}
	bt(idx + 2, cal(cur, board[idx] - '0', op));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> board;

	bt(0, 0);

	cout << maxR;
	return 0;
}