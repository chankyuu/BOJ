#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int arr[10];
void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[cur] = i;
			func(cur + 1);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);

	return 0;
}
