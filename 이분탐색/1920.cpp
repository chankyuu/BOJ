#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[100002];
int tmp;
int check() {
	int s = 0;
	int e = N - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (num[mid] > tmp) {
			e = mid - 1;
		}
		else if (num[mid] < tmp) {
			s = mid + 1;
		}
		else return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];

	sort(num, num + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << check() << "\n";
	}
	return 0;
}