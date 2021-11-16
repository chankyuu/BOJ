// �������� �����¿�� ����̱�
// 5�� ����̴� ������ ������ ���ϱ�
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

			// board�� ���� ���ϰ�, ��� ĭ �� �����ؼ� ������ ��ġ�� �ٸ��� �׳� �ű��,,,,
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

//// �������� �����¿�� ����̴� �ع��� O(N)�� �ذ��ϴ� ���!
//// idx ������ ������ ����!
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

//// ���� �ذ��� Ǯ�̴� ��,��,��,�� ��� ���⿡ ���� ����Ͽ� �ۼ��� �ڵ�������
//// �� ������ �������� ����̴� ���� �ڵ常 ������ �ذ��� �� �ִ�.
//// ����� ���� ��ü�� 90, 180, 270�� ȸ����Ų �� �������� ������ �Լ��� �̿��ϸ� �ȴ�!
//// rotate() �Լ��� ���带 ������ �Լ�! (��ƼĿ ���̱� ������ ���� �Ȱ���)
//// ��ü �ڵ�
// http://boj.kr/82284615e5814db489ee482ef77bcaf4
//#include <bits/stdc++.h>
//using namespace std;
//
//int board1[21][21];
//int board2[21][21];
//int n;
//
//void rotate() { // board2�� �ð� �������� 90�� ȸ���ϴ� �Լ�
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
//		int tilted[21] = {}; // board2[i]�� �������� ����� ����� ������ ����
//		int idx = 0; // tilted �迭���� ��� �����ؾ� �ϴ��� ����Ű�� ����
//		for (int j = 0; j < n; j++) {
//			if (board2[i][j] == 0) continue;
//			if (tilted[idx] == 0) // ������ ��ġ�� ������� ���
//				tilted[idx] = board2[i][j];
//			else if (tilted[idx] == board2[i][j]) // ���� ���� ���� ����� �浹�� ���
//				tilted[idx++] *= 2;
//			else // �ٸ� ���� ���� ����� �浹
//				tilted[++idx] = board2[i][j];
//		}
//		for (int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]�� tilted�� ���
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