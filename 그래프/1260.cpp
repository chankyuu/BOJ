#include <bits/stdc++.h>

using namespace std;

int N, M, V;
vector<int> g[1002];
bool vis[1002];

void dfs(int cur) {
	vis[cur] = true;
	cout << cur << " ";
	for (int nxt : g[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}
void bfs() {
	queue<int> q;

	q.push(V);
	vis[V] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		cout << cur << " ";

		sort(g[cur].begin(), g[cur].end());

		for (int nxt : g[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(g[i].begin(), g[i].end());
	}
	fill(vis, vis + 1002, false);
	dfs(V);
	cout << "\n";
	fill(vis, vis + 1002, false);
	bfs();

	return 0;
}