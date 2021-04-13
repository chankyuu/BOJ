#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll func1(ll a, ll b, ll m) {
	if (b == 1) return a % m;
	ll val = 1;
	val = func1(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0) return val;
	else return val * a % m;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;

	cin >> a >> b >> c;
	cout << func1(a, b, c);
	return 0;
}
