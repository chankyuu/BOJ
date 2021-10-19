//#include <bits/stdc++.h>
//using namespace std;
//
//#define X first
//#define Y second
//
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//int board[102][102];
//int copy_board[102][102];
//int N;
//
//void BFS() {
//	queue<pair<int, int>> Q;
//	int idx = 2;
//	int min_dist = 999;
//	bool isNext = false;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (board[i][j] == 1) {
//				Q.push({ i, j });
//				board[i][j] = idx;
//				isNext = true;
//			}
//			while (!Q.empty()) {
//				auto cur = Q.front(); Q.pop();
//
//				for (int dir = 0; dir < 4; dir++) {
//					int nx = cur.X + dx[dir];
//					int ny = cur.Y + dy[dir];
//
//					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//					if (board[nx][ny] == 0 || board[nx][ny] == idx) continue;
//
//					board[nx][ny] = idx;
//					Q.push({ nx, ny });
//				}
//			}
//			if (isNext) {
//				idx++;
//				isNext = false;
//			}
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			bool isSide = false;
//			int idx = 0;
//
//			for (int k = 0; k < N; k++) {
//				fill(copy_board[k], copy_board[k] + N, 0);
//			}
//
//			if (board[i][j] == 0) {
//				for (int dir = 0; dir < 4; dir++) {
//					int nx = i + dx[dir];
//					int ny = j + dy[dir];
//
//					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//					if (board[nx][ny] > 1) {
//						isSide = true;
//						idx = board[nx][ny];
//						Q.push({ i, j });
//						copy_board[i][j] = 1;
//						break;
//					}
//				}
//			}
//
//			if (isSide) {
//				while (!Q.empty()) {
//					auto cur = Q.front(); Q.pop();
//
//					for (int dir = 0; dir < 4; dir++) {
//						int nx = cur.X + dx[dir];
//						int ny = cur.Y + dy[dir];
//
//						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//						if (copy_board[nx][ny] > 0) continue;
//						if (board[nx][ny] > 1) {
//							if (board[nx][ny] != idx) {
//								min_dist = min(min_dist, copy_board[cur.X][cur.Y]);
//							}
//							continue;
//						}
//
//						copy_board[nx][ny] = copy_board[cur.X][cur.Y] + 1;
//						Q.push({ nx, ny });
//					}
//				}
//			}
//		}
//	}
//	cout << min_dist;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie();
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> board[i][j];
//		}
//	}
//
//	BFS();
//	return 0;
//}