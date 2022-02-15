#include <bits/stdc++.h>

using namespace std;

int l[20], r[20], val[20];
// 상태 방문했는지
bool vis[1 << 17];
int n;
int ans = 1;

void dfs(int state) {
	if (vis[state]) return;
	vis[state] = true;

	int wolf = 0;
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (state & (1 << i)) {
			num++;
			wolf += val[i];
		}
	}

	if (wolf * 2 >= num) return;
	ans = max(ans, num - wolf);
	// 다음 상태로
	for (int i = 0; i < n; i++) {
		if (!(state & (1 << i))) continue;

		if (l[i] != -1) dfs(state | (1 << l[i]));
		if (r[i] != -1) dfs(state | (1 << r[i]));
	}
}
int solution(vector<int> info, vector<vector<int>> edges) {
	n = info.size();
	fill(l, l + n, -1);
	fill(r, r + n, -1);
	fill(vis, vis + (1 << 17), false);

	for (int i = 0; i < n; i++) val[i] = info[i];
	for (int i = 0; i < edges.size(); i++) {
		if (l[edges[i][0]] == -1) l[edges[i][0]] = edges[i][1];
		else r[edges[i][0]] = edges[i][1];
	}

	dfs(1);
	return ans;
}