//// 백트래킹을 이용한 방법
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define X first
//#define Y second
//
//int N;
//int maxC;
//int minD = 0x7f7f7f7f;
//int chickCnt = 0;
//int board[52][52];
//int tmp[52][52];
//
//vector<pair<int, int>> V;
//vector<pair<int, int>> H;
//bool isUsed[15];
//
//int cntDist(pair<int, int> m) {
//	int tmp = 0x7f7f7f7f;
//
//	for (int i = 0; i < V.size(); i++) {
//		if(isUsed[i]) tmp = min(tmp, (abs(m.first - V[i].first) + abs(m.second - V[i].second)));
//	}
//	return tmp;
//}
//
//void back(int k, int c) {
//	if (k == maxC + 1) {
//		int m = 0;
//		for (auto cur : H) {
//			m += cntDist({ cur.X, cur.Y });
//		}
//		minD = min(minD, m);
//		return;
//	}
//	for (int i = c; i < chickCnt; i++) {
//		if (!isUsed[i]) {
//			isUsed[i] = true;
//			back(k + 1, i);
//			isUsed[i] = false;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie();
//
//	cin >> N >> maxC;
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++) {
//			cin >> board[i][j];
//			if (board[i][j] == 2) {
//				chickCnt++;
//				V.push_back({ i, j });
//			}
//			if (board[i][j] == 1) {
//				H.push_back({ i, j });
//			}
//		}
//	
//	if (chickCnt <= maxC) {
//		minD = 0;
//		for (int i = 0; i < V.size(); i++) isUsed[i] = true;
//		for (auto cur : H) {
//			minD += cntDist({ cur.X, cur.Y });
//		}
//	}
//	else {
//		back(1, 0);
//	}
//	cout << minD;
//
//	return 0;
//}

// next_permutation을 이용한 방법
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int N;
int maxC;
int minD = 0x7f7f7f7f;
int board[52][52];

vector<pair<int, int>> V;
vector<pair<int, int>> H;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N >> maxC;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) V.push_back({ i, j });
			if (board[i][j] == 1) H.push_back({ i, j });
		}
	
	vector<int> brute(V.size(), 1);
	fill(brute.begin(), brute.begin() + V.size() - maxC, 0);
	do {
		int dist = 0;
		for (auto cur : H) {
			int tmp = 0x7f7f7f7f;
			for (int i = 0; i < V.size(); i++) {
				if (brute[i] == 0) continue;
				tmp = min(tmp, abs(V[i].X - cur.X) + abs(V[i].Y - cur.Y));
			}
			dist += tmp;
		}
		minD = min(minD, dist);
	} while (next_permutation(brute.begin, brute.end));

	cout << minD;

	return 0;
}