#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> g[1002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	queue<int> q;
	bool vis[1002];
	int result = 0;

	fill(vis, vis + 1002, false);
	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		if (g[i].size() != 0) q.push(i);
		vis[i] = true;
		result++;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			
			for (int nxt : g[cur]) {
				if (vis[nxt]) continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}
	}
	cout << result;
	return 0;
}