#include <bits/stdc++.h>

using namespace std;

int N;
int person[12];
bool T[12][12];
bool vis[12];
int result = 0x7f7f7f7f;

bool checkConnect(vector<int> c, bool f){
	bool visit[12];
	queue<int> Q;
	Q.push(c[0]);

	fill(visit, visit + N, false);
	visit[c[0]] = true;
	int cnt = 1;

	while (!Q.empty()){
		int cur = Q.front();	Q.pop();

		for (int i = 0; i < N; i++){
			if (visit[i]) continue;

			if (T[cur][i] && vis[i] == f){
				visit[i] = true;
				cnt++;        
				Q.push(i);
			}
		}
	}
	if (c.size() == cnt) return true;
	return false;
}
bool check() {
	vector<int> a, b;

	for (int i = 0; i < N; i++) {
		if (vis[i]) a.push_back(i);
		else b.push_back(i);
	}

	if (a.size() == 0 || b.size() == 0) return false;
	// a ����, b ���� ��� �� ����Ǿ� �ִ��� Ȯ��
	if (!checkConnect(a, true)) return false;
	if (!checkConnect(b, false)) return false;
	return true;
}
void dfs(int cur, int cnt) {
	if (cnt >= 1) {
		// �������� üũ
		if (check()) {
			int a = 0;
			int b = 0;
			for (int i = 0; i < N; i++) {
				if (vis[i]) a += person[i];
				else b += person[i];
			}
			result = min(result, abs(a - b));
		}
	}
	for (int i = cur; i < N; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		// ��� ����
		dfs(i, cnt + 1);
		vis[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> person[i];
	
	fill(vis, vis + N, false);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;
			T[i][tmp - 1] = true;
			T[tmp - 1][i] = true;
		}
	}
	dfs(0, 0);

	if (result == 0x7f7f7f7f) result = -1;
	cout << result;
	return 0;
}