#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int arr[10];
int tmp[10];
void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (cur == 0) {
			arr[cur] = tmp[i];
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
		else {
			if (!isused[i] && arr[cur - 1] < tmp[i]) {
				arr[cur] = tmp[i];
				isused[i] = 1;
				func(cur + 1);
				isused[i] = 0;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> tmp[i];
	sort(tmp, tmp + n);

	func(0);

	return 0;
}
