#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, K;
int A[12][12];
int board[12][12];
int result = 0;

struct Tree {
	int x;
	int y;
	int num;
};
vector<int> tree[12][12];
vector<Tree> deadTree;
// ��
void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tree[i][j].size() == 0) continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] <= board[i][j]) {
					board[i][j] -= tree[i][j][k];
					tree[i][j][k] += 1;
				}
				else {
					deadTree.push_back({ i, j, tree[i][j][k] });
					tree[i][j].erase(tree[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}
// ����
void summer() {
	for (int i = 0; i < deadTree.size(); i++) {
		board[deadTree[i].x][deadTree[i].y] += deadTree[i].num / 2;
	}
	deadTree.clear();
}
// ����
void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tree[i][j].size() == 0) continue;
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 != 0) continue;
				for (int dir = 0; dir < 8; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					tree[nx][ny].push_back(1);
				}
			}
		}
	}
}
// �ܿ�
void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] += A[i][j];
		}
	}
}
// ���� ���� ���ϱ�
void countTree() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += tree[i][j].size();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) fill(board[i], board[i] + N, 5);

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];


	while (M--) {
		int x, y, num;
		cin >> x >> y >> num;
		tree[x - 1][y - 1].push_back(num);
	}

	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	countTree();
	cout << result;
	return 0;
}