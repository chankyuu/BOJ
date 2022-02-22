#include <bits/stdc++.h>

using namespace std;

int T;
int m, c, a;
int var[100002];					// 정수를 담는 변수
int cur = 0;							// 현재 포인터 위치
int curChar = 0;					// 현재 읽어야할 문자 위치
char board[5000];
char Input[5000];
int Left[5000];
int Right[5000];

void checkLoop() {
	int cnt = 0;
	int minPtr, maxPtr;

	for (int idx = 0; idx < c; idx++) {
		if (cnt == 50000000) {
			minPtr = maxPtr = idx;
		}
		if (cnt > 50000000) {
			minPtr = min(minPtr, idx);
			maxPtr = max(maxPtr, idx);
		}
		if (cnt >= 100000000) {
			cout << "Loops " << minPtr - 1 << " " << maxPtr << "\n";
			return;
		}
		switch (board[idx]) {
		case '-':
			var[cur]--;
			if (var[cur] < 0) var[cur] = 255;
			break;
		case '+':
			var[cur] = (var[cur] + 1) % 256;
			break;
		case '<':
			cur--;
			if (cur < 0) cur = m - 1;
			break;
		case '>':
			cur++;
			if (cur >= m) cur = 0;
			break;
		case '[':
			if (var[cur] == 0) idx = Left[idx];
			break;
		case ']':
			if (var[cur] != 0) idx = Right[idx];
			break;
		case '.':
			//cout << var[cur];
			break;
		case ',':
			if (curChar >= a) var[cur] = 255;
			else var[cur] = Input[curChar];
			if (curChar < a) curChar++;
			break;
		}
		cnt++;
	}
	cout << "Terminates" << "\n";
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> m >> c >> a;

		cur = 0;
		curChar = 0;
		fill(var, var + m, 0);
		fill(board, board + c, 0);
		fill(Input, Input + a, 0);
		fill(Left, Left + c, 0);
		fill(Right, Right + c, 0);

		stack<int> s;
		for (int i = 0; i < c; i++) {
			cin >> board[i];
			if (board[i] == '[') s.push(i);
			else if (board[i] == ']') {
				Right[i] = s.top();
				Left[s.top()] = i;
				s.pop();
			}
		}
		for (int i = 0; i < a; i++) cin >> Input[i];

		checkLoop();
	}

	return 0;
}