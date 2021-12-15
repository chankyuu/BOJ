#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int a = 1, b = 1, c = 1;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) a *= i;
	for (int i = 1; i <= K; i++) b *= i;
	for (int i = 1; i <= N - K; i++) c *= i;
	
	cout << a / (b * c);

	return 0;
}