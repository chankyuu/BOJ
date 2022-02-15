#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int t_board[1002][1002];
	int n = board.size();
	int m = board[0].size();

	for (int i = 0; i < n; i++) fill(t_board[i], t_board[i] + m, 0);
	for (int i = 0; i < skill.size(); i++) {
		// 적 공격
		int r1 = skill[i][1];
		int c1 = skill[i][2];
		int r2 = skill[i][3];
		int c2 = skill[i][4];
		int d = skill[i][5];

		if (skill[i][0] == 1) {
			t_board[r1][c1] -= d;

			if (r2 >= n - 1 && c2 >= m - 1) continue;

			if (r2 >= n - 1) {
				t_board[r1][c2 + 1] += d;
				continue;
			}
			if (c2 >= m - 1) {
				t_board[r2 + 1][c1] += d;
				continue;
			}
			t_board[r2 + 1][c1] += d;
			t_board[r1][c2 + 1] += d;
			t_board[r2 + 1][c2 + 1] -= d;
		}
		// 회복
		else {
			t_board[r1][c1] += d;

			if (r2 >= n - 1 && c2 >= m - 1) continue;

			if (r2 >= n - 1) {
				t_board[r1][c2 + 1] -= d;
				continue;
			}
			if (c2 >= m - 1) {
				t_board[r2 + 1][c1] -= d;
				continue;
			}
			t_board[r1][c2 + 1] -= d;
			t_board[r2 + 1][c1] -= d;
			t_board[r2 + 1][c2 + 1] += d;
		}
	}

	//누적 합 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			t_board[i][j] += t_board[i][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			t_board[j][i] += t_board[j - 1][i];
		}
	}
	// 답구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] += t_board[i][j];
			if (board[i][j] > 0) answer++;
		}
	}
	return answer;
}