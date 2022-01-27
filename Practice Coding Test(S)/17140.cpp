#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int r, c, k;
int board[102][102];
int N, M;

// ����(a�� b���� �տ� �;��� �� true)
bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.X < b.X) return true;
	else if (a.X == b.X) {
		return a.Y < b.Y;
	}
	else return false;
}
// R����(�� / ���� Ƚ��) ���� ���� Ƚ���� Ŀ���� �� -> ���� Ŀ���� ��
void R() {
	int maxM = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int idx = 1;
		vector<pair<int, int>> T;
		sort(board[i], board[i] + M);

		// {����Ƚ��, ��} ������ T�� �Է�
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			if (board[i][j] == idx) {
				cnt++;
				if (j == M - 1) T.push_back({ cnt, idx });
			}
			else {
				if (cnt != 0) T.push_back({ cnt, idx });
				idx++;
				cnt = 0;
				j--;
			}
		}
		// T�� ����(���� Ƚ���� Ŀ���� ��, ���� Ŀ���� ������)
		sort(T.begin(), T.end(), comp);

		for (int j = 0; j < M; j++) board[i][j] = 0;

		idx = 0;
		for (int j = 0; j < T.size(); j++) {
			board[i][idx++] = T[j].Y;
			board[i][idx++] = T[j].X;

			if (idx > 100) break;
		}
		maxM = max(maxM, idx);
	}
	M = maxM;
}
// C����
void C() {
	int maxN = 0;
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		int idx = 1;
		int t_board[100];
		vector<pair<int, int>> T;
		for (int j = 0; j < N; j++) t_board[j] = board[j][i];

		sort(t_board, t_board + N);

		// {����Ƚ��, ��} ������ T�� �Է�
		for (int j = 0; j < N; j++) {
			if (t_board[j] == 0) continue;
			if (t_board[j] == idx) {
				cnt++;
				if (j == N - 1) T.push_back({ cnt, idx });
			}
			else {
				if (cnt != 0) T.push_back({ cnt, idx });
				idx++;
				cnt = 0;
				j--;
			}
		}
		// T�� ����(���� Ƚ���� Ŀ���� ��, ���� Ŀ���� ������)
		sort(T.begin(), T.end(), comp);

		for (int j = 0; j < M; j++) board[j][i] = 0;

		idx = 0;
		for (int j = 0; j < T.size(); j++) {
			board[idx++][i] = T[j].Y;
			board[idx++][i] = T[j].X;

			if (idx > 100) break;
		}
		maxN = max(maxN, idx);
	}
	N = maxN;
}
// ���� üũ
bool checkEnd() {
	if (board[r-1][c-1] == k) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;

	cin >> r >> c >> k;

	N = M = 3;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> board[i][j];

	while (!checkEnd()) {
		if (N >= M) R();
		else C();

		result++;
		if (result > 100) {
			result = -1;
			break;
		}
	}

	cout << result;
	return 0;
}