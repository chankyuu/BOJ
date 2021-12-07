// 백트래킹으로 접근 ... -> 시간 초과
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, K;
//pair<int, int> m[102];
//bool isUsed[102];
//int tmpW = 0;
//int tmpV = 0;
//int maxV = 0;
//
//void back(int p) {
//	if (tmpW > K) {
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		if (!isUsed[i]) {
//			isUsed[i] = true;
//			tmpW += m[i].first;
//			tmpV += m[i].second;
//			back(p + 1);
//			isUsed[i] = false;
//			tmpW -= m[i].first;
//			tmpV -= m[i].second;
//		}
//	}
//	maxV = max(maxV, tmpV);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) cin >> m[i].first >> m[i].second;
//
//	back(0);
//
//	cout << maxV;
//	return 0;
//}

// DP 풀이법
#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<int, int> m[102];
int D[102][100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) cin >> m[i].first >> m[i].second;

	// D[i][j] = i개의 물품을 채웠을때 무게는 j이고 그에 따른 최대 가치값을 나타냄
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (m[i].first <= j) {
				D[i][j] = max(D[i - 1][j], D[i - 1][j - m[i].first] + m[i].second);
			}
			else D[i][j] = D[i-1][j];
		}
	}
	cout << D[N][K];
	return 0;
}