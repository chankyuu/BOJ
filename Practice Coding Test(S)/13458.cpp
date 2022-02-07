#include <bits/stdc++.h>

using namespace std;

int N;
int A, B, C;
int board[1000002];
int result = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> board[i];

	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		result++;
		board[i] -= B;
		if (board[i] < 0) continue;
		result += board[i] / C;
		board[i] %= C;
		if (board[i] != 0 && board[i] / C == 0) result++;
	}

	cout << result;
	return 0;
}