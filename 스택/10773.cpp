#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<int> rst;
	int N;
	int a;
	int result = 0;

	cin >> N;
	while (N--) {
		cin >> a;

		if (a == 0) {
			rst.pop();
		}
		else {
			rst.push(a);
		}
	}
	int size = rst.size();
	for (int i = 0; i < size; i++) {
		result += rst.top();
		rst.pop();
	}
	cout << result;

	return 0;
}