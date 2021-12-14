#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++) {
		// 소수가 아니라면
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int tmp;
	int cnt = 0;
	
	cin >> N;

	for (int k = 0; k < N; k++) {
		cin >> tmp;
		if (isPrime(tmp)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}