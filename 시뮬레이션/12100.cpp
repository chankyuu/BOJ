// 게임판을 상하좌우로 기울이기
// 5번 기울이는 각각의 방향을 정하기
#include <bits/stdc++.h>

using namespace std;

int N;
int board[22][22];
int tmp[22][22];
int pre[22];
int maxN = 0;

void resetBoard() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = board[i][j];
}
void comp(int p, int dir) {
	bool canSum[22];

	fill(canSum, canSum + 22, true);

	if (dir == 0) {
		for (int i = N - 2; i >= 0; i--) {
			if (tmp[i][p] == 0) continue;

			int cnt = i + 1;
			bool zero = true;

			while (cnt < N) {
				if (tmp[cnt][p] == 0) {
					cnt++;
					continue;
				}
				if (tmp[cnt][p] == tmp[i][p]) {
					zero = false;
					if (canSum[cnt]) {
						tmp[cnt][p] = tmp[cnt][p] * 2;
						tmp[i][p] = 0;
						canSum[cnt] = false;
						break;
					}
					else {
						if (cnt - 1 != i) {
							tmp[cnt - 1][p] = tmp[i][p];
							tmp[i][p] = 0;
						}
						break;
					}
				}
				else {
					zero = false;
					if (cnt - 1 != i) {
						tmp[cnt - 1][p] = tmp[i][p];
						tmp[i][p] = 0;
					}
					break;
				}
			}
			if (zero) {
				if (cnt - 1 != i) {
					tmp[cnt - 1][p] = tmp[i][p];
					tmp[i][p] = 0;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = N - 2; i >= 0; i--) {
			if (tmp[p][i] == 0) continue;

			int cnt = i + 1;
			bool zero = true;

			while (cnt < N) {
				if (tmp[p][cnt] == 0) {
					cnt++;
					continue;
				}
				if (tmp[p][cnt] == tmp[p][i]) {
					zero = false;
					if (canSum[cnt]) {
						tmp[p][cnt] = tmp[p][cnt] * 2;
						tmp[p][i] = 0;
						canSum[cnt] = false;
						break;
					}
					else {
						if (cnt - 1 != i) {
							tmp[p][cnt - 1] = tmp[p][i];
							tmp[p][i] = 0;
						}
						break;
					}
				}
				else {
					zero = false;
					if (cnt - 1 != i) {
						tmp[p][cnt - 1] = tmp[p][i];
						tmp[p][i] = 0;
					}
					break;
				}
			}
			if (zero) {
				if (cnt - 1 != i) {
					tmp[p][cnt - 1] = tmp[p][i];
					tmp[p][i] = 0;
				}
			}
		}
	}
	else if (dir == 2) {
		for (int i = 1; i < N; i++) {
			if (tmp[i][p] == 0) continue;

			int cnt = i - 1;
			bool zero = true;

			while (cnt >= 0) {
				if (tmp[cnt][p] == 0) {
					cnt--;
					continue;
				}
				if (tmp[cnt][p] == tmp[i][p]) {
					zero = false;
					if (canSum[cnt]) {
						tmp[cnt][p] = tmp[cnt][p] * 2;
						tmp[i][p] = 0;
						canSum[cnt] = false;
						break;
					}
					else {
						if (cnt + 1 != i) {
							tmp[cnt + 1][p] = tmp[i][p];
							tmp[i][p] = 0;
						}
						break;
					}
				}
				else {
					zero = false;
					if (cnt + 1 != i) {
						tmp[cnt + 1][p] = tmp[i][p];
						tmp[i][p] = 0;
					}
					break;
				}
			}
			if (zero) {
				if (cnt + 1 != i) {
					tmp[cnt + 1][p] = tmp[i][p];
					tmp[i][p] = 0;
				}
			}
		}
	}
	else if (dir == 3) {
		for (int i = 1; i < N; i++) {
			if (tmp[p][i] == 0) continue;

			int cnt = i - 1;
			bool zero = true;

			while (cnt >= 0) {
				if (tmp[p][cnt] == 0) {
					cnt--;
					continue;
				}
				if (tmp[p][cnt] == tmp[p][i]) {
					zero = false;
					if (canSum[cnt]) {
						tmp[p][cnt] = tmp[p][cnt] * 2;
						tmp[p][i] = 0;
						canSum[cnt] = false;
						break;
					}
					else {
						if (cnt + 1 != i) {
							tmp[p][cnt + 1] = tmp[p][i];
							tmp[p][i] = 0;
						}
						break;
					}
				}
				else {
					zero = false;
					if (cnt + 1 != i) {
						tmp[p][cnt + 1] = tmp[p][i];
						tmp[p][i] = 0;
					}
					break;
				}
			}
			if (zero) {
				if (cnt + 1 != i) {
					tmp[p][cnt + 1] = tmp[p][i];
					tmp[p][i] = 0;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	int maxN = 0;

	cin >> N;

	for (int i = 0; i < 22; i++) {
		fill(board[i], board[i] + 22, 0);
		fill(tmp[i], tmp[i] + 22, 0);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int src = 0; src < (1 << (2 * 5)); src++) {
		int emp = src;
		resetBoard();

		for (int size = 0; size < 5; size++) {
			bool isTrue = true;
			int dir = emp % 4;
			emp /= 4;

			// board를 통해 비교하고, 모든 칸 다 조사해서 같으면 합치고 다르면 그냥 옮기고,,,,
			for (int i = 0; i < N; i++) comp(i, dir);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxN = max(maxN, tmp[i][j]);
			}
		}
	}
	cout << maxN;
}

//// 게임판을 상하좌우로 기울이는 해법을 O(N)에 해결하는 방법!
//// idx 변수를 유심히 봐봐!
//void tiltid() {
//	int arr[8] = { 0, 2, 0, 2, 8, 8, 0, 16 };
//	int tilted[8] = {};
//	int idx = 0;
//	for (int i = 0; i < 8; i++) {
//		if (arr[i] == 0) continue;
//		if (tilted[idx] == 0)
//			tilted[idx] = arr[i];
//		else if (tilted[idx] == arr[i])
//			tilted[idx++] *= 2;
//		else
//			tilted[++idx] = arr[i];
//	}
//}

//// 내가 해결한 풀이는 상,하,좌,우 모든 방향에 대해 고려하여 작성한 코드이지만
//// 이 문제를 왼쪽으로 기울이는 위의 코드만 가지고도 해결할 수 있다.
//// 방법은 보드 자체를 90, 180, 270도 회전시킨 후 왼쪽으로 돌리는 함수를 이용하면 된다!
//// rotate() 함수가 보드를 돌리는 함수! (스티커 붙이기 문제랑 완전 똑같다)
//// 전체 코드
// http://boj.kr/82284615e5814db489ee482ef77bcaf4
//#include <bits/stdc++.h>
//using namespace std;
//
//int board1[21][21];
//int board2[21][21];
//int n;
//
//void rotate() { // board2를 시계 방향으로 90도 회전하는 함수
//	int tmp[21][21];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			tmp[i][j] = board2[i][j];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			board2[i][j] = tmp[n - 1 - j][i];
//}
//
//void tilt(int dir) {
//	while (dir--) rotate();
//	for (int i = 0; i < n; i++) {
//		int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
//		int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지 가리키는 변수
//		for (int j = 0; j < n; j++) {
//			if (board2[i][j] == 0) continue;
//			if (tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
//				tilted[idx] = board2[i][j];
//			else if (tilted[idx] == board2[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
//				tilted[idx++] *= 2;
//			else // 다른 값을 갖는 블록이 충돌
//				tilted[++idx] = board2[i][j];
//		}
//		for (int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]에 tilted를 덮어씀
//	}
//}
//
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> board1[i][j];
//
//	int mx = 0;
//	for (int tmp = 0; tmp < 1024; tmp++) {
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				board2[i][j] = board1[i][j];
//		int brute = tmp;
//		for (int i = 0; i < 5; i++) {
//			int dir = brute % 4;
//			brute /= 4;
//			tilt(dir);
//		}
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				mx = max(mx, board2[i][j]);
//	}
//	cout << mx;
//}