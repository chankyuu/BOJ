#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int tmp = 1 << (n - 1);
	if (r < tmp && c < tmp) {
		return func(n - 1, r, c);
	}
	else if (r < tmp && c >= tmp) {
		return tmp * tmp + func(n - 1, r, c - tmp);
	}
	else if (r >= tmp && c < tmp) {
		return 2 * tmp * tmp + func(n - 1, r - tmp, c);
	}
	else if (r >= tmp && c >= tmp) {
		return 3 * tmp * tmp + func(n - 1, r - tmp, c - tmp);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout << func(a, b, c);
	return 0;
}
