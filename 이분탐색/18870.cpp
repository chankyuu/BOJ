#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> num;
int tmp[1000002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back(n);
		tmp[i] = n;
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(num.begin(), num.end(), tmp[i]) - num.begin() << " ";
	}
	return 0;
}