#include <bits/stdc++.h>

using namespace std;

int N;
// 각 이닝마다 1번~9번타자 결과 저장
int val[52][9];
// 다음 이닝에서의 순서
vector<int> order(8);
// 현재 순서
int cur = 0;
// 점수
int cnt = 0;
// 최종 점수
int result = 0;

// 야구게임
void baseball(int idx) {
	// 주자 상황
	int ground[3];
	fill(ground, ground + 3, 0);

	int out = 0;
	while (true) {
		if (out >= 3) break;

		int attack = val[idx][order[cur]];
		switch (attack) {
		case 0 :
			out++;
			break;
		case 1 :
			for (int i = 2; i >= 0; i--) {
				if (ground[i]) {
					if (i == 2) {
						cnt++;
						ground[i] = 0;
						continue;
					}
					ground[i + 1] = 1;
					ground[i] = 0;
				}
			}
			ground[0] = 1;
			break;
		case 2 :
			for (int i = 2; i >= 0; i--) {
				if (ground[i]) {
					if (i == 2 || i == 1) {
						cnt++;
						ground[i] = 0;
						continue;
					}
					ground[i + 2] = 1;
					ground[i] = 0;
				}
			}
			ground[1] = 1;
			break;
		case 3 :
			for (int i = 2; i >= 0; i--) {
				if (ground[i]) {
					cnt++;
					ground[i] = 0;
				}
			}
			ground[2] = 1;
			break;
		case 4 :
			for (int i = 2; i >= 0; i--) {
				if (ground[i]) {
					cnt++;
					ground[i] = 0;
				}
			}
			cnt++;
			break;
		}
		cur = (cur + 1) % 9;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++) for (int j = 0; j < 9; j++) cin >> val[i][j];

	for (int i = 0; i < 8; i++) order[i] = i + 1;
	// 경기 시작
	do {
		cnt = 0;
		cur = 0;
		order.insert(order.begin() + 3, 0);

		// 이닝 시작
		for (int i = 0; i < N; i++) baseball(i);

		order.erase(order.begin() + 3);
		result = max(result, cnt);
	} while (next_permutation(order.begin(), order.end()));
	
	cout << result;
	return 0;
}