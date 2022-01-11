#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, K;
vector<int> tray;
int t_tray[12][12];
int colCnt = 1;
int idx_r = 0;
int idx_c = 0;

// board 복사(b를 a로 복사)
void copyTray(int a[12][12], int b[12][12]) {
	for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) a[i][j] = b[i][j];
}
// 가장 적은 어항에 물고기 넣기
void addFish() {
	int m = 0x7f7f7f7f;
	for (int i = 0; i < tray.size(); i++) m = min(m, tray[i]);
	for (int i = 0; i < tray.size(); i++) {
		if (tray[i] == m) tray[i] += 1;
	}
}
// 어항 돌리기1
void rollTray1() {
	int tmp[12][12];
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) tmp[i][j] = t_tray[i][j];
	}	
	for (int i = 0; i < idx_r; i++) {
		for (int j = 0; j < idx_c; j++) {
			t_tray[j][idx_r - 1 - i] = tmp[i][j];
		}
	}
	swap(idx_r, idx_c);
}
// 물고기 수 조절
void controlFish() {
	int t_tray2[12][12];
	for (int i = idx_c; i < idx_c + tray.size(); i++) t_tray[idx_r - 1][i] = tray[i - idx_c];

	idx_c += tray.size();
	copyTray(t_tray2, t_tray);

	for (int i = 0; i < idx_r; i++) {
		for (int j = 0; j < idx_c; j++) {
			if (t_tray[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= idx_r || ny < 0 || ny >= idx_c) continue;
					if (t_tray[nx][ny] > t_tray[i][j] || t_tray[nx][ny] == 0) continue;

					int d = (t_tray[i][j] - t_tray[nx][ny]) / 5;
					if (d > 0) {
						t_tray2[i][j] -= d;
						t_tray2[nx][ny] += d;
					}
				}
			}
		}
	}
	copyTray(t_tray, t_tray2);
}
// 어항을 일렬로 놓기
void putLine() {
	tray.clear();
	for (int i = 0; i < idx_c; i++) {
		for (int j = idx_r - 1; j >= 0; j--) {
			if (t_tray[j][i] == 0) continue;
			tray.push_back(t_tray[j][i]);
		}
	}
}
// 어항 쌓기
int addTray() {
	int maxF = 0;
	int minF = 0x7f7f7f7f;

	bool isFirst = true;
	int cnt = 0;
	int rowCnt = 1;

	idx_r = 0;
	while (true) {
		idx_c = 0;
		for (int k = 0; k < rowCnt; k++) {
			t_tray[idx_r][idx_c++] = tray[k];
		}
		for(int k = 0; k < rowCnt; k++) tray.erase(tray.begin());
		idx_r++;
		cnt++;
		if (isFirst) {
			isFirst = false;
			continue;
		}
		if (cnt % 2 == 0) rowCnt++;
		if (rowCnt > tray.size()) break;
		// 어항 돌리기1
		rollTray1();
	}
	
	// 물고기 수 조절
	controlFish();

	// 어항을 바닥에 일렬로 놓기
	putLine();

	for (int i = 0; i < 12; i++) fill(t_tray[i], t_tray[i] + 12, 0);

	// 어항 돌리기2
	int rollSize = tray.size() / 2;
	for (int i = 0; i < rollSize; i++) {
		t_tray[0][i] = tray[i];
	}
	for (int i = 0; i < rollSize; i++) tray.erase(tray.begin());

	int newSize = rollSize / 2;
	for (int i = 0; i < newSize; i++) swap(t_tray[0][i], t_tray[0][rollSize - 1 - i]);

	for (int i = 0; i < rollSize; i++) t_tray[1][i] = tray[i];
	for (int i = 0; i < rollSize; i++) tray.erase(tray.begin());
	// 이부분 에러
	for (int i = 0; i < 2; i++) {
		for (int j = newSize; j < rollSize; j++) {
			if (newSize == 1) {
				t_tray[i + newSize + 1][j - newSize] = t_tray[i][j];
				t_tray[i][j] = 0;
			}
			else {
				t_tray[i + 2][j - newSize] = t_tray[i][j];
				t_tray[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < newSize; i++) swap(t_tray[0][i], t_tray[1][i]);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < newSize / 2; j++) swap(t_tray[i][j], t_tray[i][newSize -1 - j]);
	}

	idx_r = 4;
	idx_c = newSize;
	// 물고기 수 조절
	controlFish();

	// 어항을 바닥에 일렬로 놓기
	putLine();
	
	for (auto c : tray) {
		maxF = max(maxF, c);
		minF = min(minF, c);
	}
	return maxF - minF;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dif = 0;
	int count = 0;
	int x;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> x;
		tray.push_back(x);
	}
	while (true) {
		addFish();
		dif = addTray();
		count++;

		if (dif <= K) break;
		for (int i = 0; i < 12; i++) fill(t_tray[i], t_tray[i] + 12, 0);
	}
	cout << count;

	return 0;
}