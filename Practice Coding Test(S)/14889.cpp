#include <bits/stdc++.h>

using namespace std;

int N;
int board[22][22];
int Sum = 0;
int result = 0x7f7f7f7f;

vector<int> TeamA;
vector<int> TeamB;

// ÆÀ ¸¸µé±â
void makeTeam(int idx, int cnt) {
	if (cnt == N / 2) {
		int teamA = 0;
		int teamB = 0;

		TeamB.clear();
		for (int i = 1; i <= N; i++) {
			if (find(TeamA.begin(), TeamA.end(), i - 1) == TeamA.end()) {
				TeamB.push_back(i - 1);
			}
		}
		for (int i = 0; i < TeamA.size(); i++) {
			for (int j = 0; j < TeamA.size(); j++) {
				if (i == j) continue;
				teamA += board[TeamA[i]][TeamA[j]];
			}
		}
		for (int i = 0; i < TeamB.size(); i++) {
			for (int j = 0; j < TeamB.size(); j++) {
				if (i == j) continue;
				teamB += board[TeamB[i]][TeamB[j]];
			}
		}
		result = min(result, abs(teamA - teamB));
		return;
	}
	for (int i = idx; i < N; i++) {
		TeamA.push_back(i);
		makeTeam(i + 1, cnt + 1);
		TeamA.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];
	
	makeTeam(0, 0);

	cout << result;
	return 0;
}