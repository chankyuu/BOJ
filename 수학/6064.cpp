#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int T, M, N, x, y;
int loop = 0;

int cal(int M, int N, int x, int y) {
	loop = lcm(M, N);

	for (int i = x; i <= loop; i += M) {
		if (i % N == y) {
			return i;
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;

		cout << cal(M, N, x, y);
	}
	return 0;
}