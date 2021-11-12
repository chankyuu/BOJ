#include <bits/stdc++.h>

using namespace std;
int N;
long long num[100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	cin >> N;
	int max_cnt = 0;
	int cnt = 0;
	long long max_num;

	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		num[i] = a;
	}

	sort(num, num + N);

	cnt++;
	for (int i = 0; i < N - 1; i++) {
		if (num[i + 1] == num[i]) cnt++;
		else {
			if (cnt > max_cnt) {
				max_cnt = cnt;
				max_num = num[i];
			}
			cnt = 1;
		}
	}
	if (cnt > max_cnt) max_num = num[N - 1];
	cout << max_num;

	return 0;
}