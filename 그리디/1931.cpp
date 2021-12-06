#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> office[100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> office[i].second >> office[i].first;

	sort(office, office + N);

	int s = 0;
	int e = 0;
	for (int i = 0; i < N; i++) {
		if (office[i].second < e) continue;
		if (office[i].first > s) {
			s = office[i].second;
			e = office[i].first;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}