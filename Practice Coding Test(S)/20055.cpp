#include <iostream>
#include <vector>

using namespace std;

int N, K;
int protect[202];
bool robot[202];

// ��Ʈ ȸ��
void moveBelt() {
	int b_end = protect[2 * N - 1];

	for (int i = 2 * N - 2; i >= 0; i--) {
		// ������ �ű��(��Ʈ)
		protect[i + 1] = protect[i];

		// �κ��� �Ȱ��� �ű��
		if (robot[i]) {
			robot[i + 1] = true;
			robot[i] = false;
		}
	}
	protect[0] = b_end;
	if (robot[N - 1]) robot[N - 1] = false;
}
// �κ� �̵�
void moveRobot() {
	for (int i = 2 * N - 2; i >= 0; i--) {
		if (!robot[i] || robot[i + 1] || !protect[i + 1] >= 1) continue;
		robot[i + 1] = true;
		robot[i] = false;
		protect[i + 1] -= 1;
	}
	if (robot[N - 1]) robot[N - 1] = false;
}
// �κ� �ø���
void addRobot() {
	if (protect[0] >= 1 && !robot[0]) {
		protect[0] -= 1;
		robot[0] = true;
	}
}
// ���� üũ
bool checkEnd() {
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (protect[i] == 0) cnt++;
	}
	if (cnt >= K) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int step = 0;

	cin >> N >> K;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> protect[i * N + j];
		}
	}

	while (!checkEnd()) {
		step++;
		moveBelt();
		moveRobot();
		addRobot();
	}

	cout << step;
	return 0;
}