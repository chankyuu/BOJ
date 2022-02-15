#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[1030][1030];
int dp[1030][1030];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

	// dp[i][j] = 가로 누적합
	for(int i = 0; i < N; i++) dp[i][0] = board[i][0];

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = dp[i][j - 1] + board[i][j];
		}
	}

	while (M--) {
		int result = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int i = x1 - 1; i < x2; i++) {
			if (y2 == 0) {
				result += dp[i][0];
				continue;
			}
			result += (dp[i][y2 - 1] - dp[i][y1 - 2]);
		}
		cout << result << "\n";
	}
	return 0;
}